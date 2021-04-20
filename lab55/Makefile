BUILD_DIR = build

# ----------------------------------------------------------------------------------------------------------------------

all: clean executor.o main.o
	g++ -pthread $(BUILD_DIR)/main.o $(BUILD_DIR)/support.o -o ${BUILD_DIR}/program

main.o: build
	g++ -c -Wall --std=c++2a main.cpp -o $(BUILD_DIR)/main.o

executor.o: build
	g++ -c -Wall --std=c++2a support.cpp -o $(BUILD_DIR)/support.o

# ----------------------------------------------------------------------------------------------------------------------

tests: clean_tests all
	./run_tests.sh

clean_tests:
	rm -f output.txt

# ----------------------------------------------------------------------------------------------------------------------

build:
	mkdir -p "$(BUILD_DIR)"

clean:
	rm -rf $(BUILD_DIR)