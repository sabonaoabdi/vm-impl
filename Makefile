SRC_FILES = driver.cc
CC_FLAGS = -Wall -Wextra -std=c++20 -fsanitize=address,undefined

all:
	clang++ ${CC_FLAGS} ${SRC_FILES} -o ./bin/driver