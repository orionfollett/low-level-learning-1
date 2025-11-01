
CC=gcc
CFLAGS=(
    -Wall
    -Wextra
    -Werror
    -Wshadow
    -Wconversion
    -Wcast-align
    -Wstrict-prototypes
    -Wmissing-prototypes
    -Wfloat-equal
    -Wundef
    -fsanitize=address
    -fsanitize=undefined
    -g
    -std=c89
    -O2
)

SRC_DIR=src
BUILD_DIR=build
TEST_DIR=tests

TARGET=$BUILD_DIR/app

SRC=(src/*.c tests/*.c)

test(){
    echo "\n🧪 Building and running tests...\n"
    mkdir -p $BUILD_DIR
    $CC $CFLAGS $SRC -o $TARGET
    ./build/app
}

fmt(){
    clang-format --style Chromium -i $SRC_DIR/*.c $SRC_DIR/*.h $TEST_DIR/*.c 2>/dev/null || true
}

clean(){
    rm -rf build/
    mkdir -p build
}