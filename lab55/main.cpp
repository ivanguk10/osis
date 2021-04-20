#include <iostream>
#include <filesystem>
#include <fstream>
#include <pthread.h>
#include <vector>
#include "support.h"

std::string output_path;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t address_lock = PTHREAD_MUTEX_INITIALIZER;

void *calculate_and_write(void *arg) {
    std::ifstream f;
    std::string input_path = std::string(*((std::string *) arg));
    pthread_mutex_unlock(&address_lock);
    f.open(input_path);
    std::string data((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    f.close();

    auto result = input_path + ": " + string_result(data);
    std::ofstream output_file;

    pthread_mutex_lock(&lock);

    output_file.open(output_path , std::ios::app | std::ios::out);
    output_file << result << std::endl;
    pthread_mutex_unlock(&lock);

    return nullptr;
}

int main(int argc, char **argv) {
    std::string dir(argv[1]);
    output_path = std::string(argv[2]);

    std::vector<pthread_t> pids;

    for (const auto &entry : std::filesystem::directory_iterator(dir)) {
        pthread_t pid;
        pthread_mutex_lock(&address_lock);
        auto input_path = entry.path().string();
        pthread_create(&pid, nullptr, calculate_and_write, (void *) &input_path);
        pids.push_back(pid);
    }

    void *result;

    for (auto pid : pids) {
        pthread_join(pid, &result);
    }

    return 0;
}

