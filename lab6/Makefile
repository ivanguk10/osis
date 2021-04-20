BUILD_DIR = build

# ----------------------------------------------------------------------------------------------------------------------

server: build
	gcc server.c -o ${BUILD_DIR}/server
	./${BUILD_DIR}/server

client: build
	gcc client.c -o ${BUILD_DIR}/client
	./${BUILD_DIR}/client

# ----------------------------------------------------------------------------------------------------------------------

build:
	mkdir -p "$(BUILD_DIR)"

clean:
	rm -rf $(BUILD_DIR)