BUILD_DIR = build
TEST_DIR = tests


all: build
	g++ main.cpp algorithm.cpp -o ${BUILD_DIR}/program -Wall

test: clean_tests all
	./test.sh


clean_tests:
	rm -f ${TEST_DIR}/output[0123456789]*.txt

build:
	mkdir build

clean: clean_tests
	rm -rf build

