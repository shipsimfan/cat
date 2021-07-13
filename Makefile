SRC_DIR := ./src
SYSROOT_DIR := ../../sysroot
SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')
TARGET := ./cat.app

CC := clang
CC_FLAGS := --target=x86_64-los --sysroot=$(SYSROOT_DIR) -Wall -g

all: $(TARGET)

clean:
	@rm -f $(TARGET)
	
$(TARGET): $(SRC_FILES)
	@echo "    $(CYAN)Compiling$(RESET) $@ . . ."
	@$(CC) $(CC_FLAGS) -o $@ $^
