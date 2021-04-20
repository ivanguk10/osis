#include <sstream>
#include "support.h"


std::string string_result(std::string &data) {
    std::string temp;
    std::istringstream input(data);
    input >> temp;
    int type = std::stoi(temp);

    input >> temp;
    double first_operand = std::stod(temp);
        
    input >> temp;
    double second_operand = std::stod(temp);
    return std::to_string(calculate(type, first_operand, second_operand));
}

double calculate(int type, double first_operand, double second_operand) {
    switch (type) {
        case 1:
            return first_operand + second_operand;
        case 2:
            return first_operand * second_operand;
        case 3:
            return first_operand * first_operand + second_operand * second_operand;
    }
    return EXIT_FAILURE;
}
