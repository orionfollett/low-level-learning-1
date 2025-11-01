
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Wshadow -Wconversion -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wfloat-equal -Wundef -fsanitize=address -fsanitize=undefined -g -std=c89 -O2

SRC_DIR := src
BUILD_DIR := build
TEST_DIR := tests

TARGET := $(BUILD_DIR)/app


build: $(TARGET)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) 

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

fmt:
	clang-format --style Chromium -i $(SRC_DIR)/*.c $(SRC_DIR)/*.h $(TEST_DIR)/*.c $(TEST_DIR)/*.h 2>/dev/null || true

clean:
	rm -rf $(BUILD_DIR)

run: clean build
	@echo "\n🚀 Running...\n"
	./$(TARGET)
	
test:
	@echo "\n🧪 Building and running tests...\n"
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(TEST_SRCS) $(wildcard $(TEST_DIR)/*.c) -o $(BUILD_DIR)/tests
	@echo "\n🏃 Running tests...\n"
	@$(BUILD_DIR)/tests || true
	

.PHONY: all build test format clean run