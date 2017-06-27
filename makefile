CFLAG = -Wall -Werror -o
BIN_DIR = bin
BUILD_DIR = build/src
SRC_DIR = src
CC = gcc
DIRGUARD=@mkdir -p $(@D)

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET = $(BIN_DIR)/main

BUILD_DIR_TEST = build/test
SRC_DIR_TEST = test
SRC_TEST = $(wildcard $(SRC_DIR_TEST)/*.c)
OBJ_TEST = $(SRC_TEST:$(SRC_DIR_TEST)/%.c=$(BUILD_DIR_TEST)/%.o)
TARGET_TEST = $(BIN_DIR)/function-test

$(TARGET): $(OBJ)
	@$(DIRGUARD)
	@$(CC) $(CFLAG) $@ $(OBJ)

$(OBJ): $(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	@$(DIRGUARD)
	@$(CC) -c $(CFLAG) $@ $<

.PHONY: clean

clean: 
	@rm -f $(BUILD_DIR)/*.o $(TARGET)
	@rm -f $(BUILD_DIR_TEST)/*.o $(TARGET_TEST)

$(TARGET_TEST): $(OBJ_TEST) $(OBJ)
	@$(DIRGUARD)
	@$(CC) $(CFLAG) $@ $(OBJ_TEST) $(BUILD_DIR)/function.o

$(OBJ_TEST): $(BUILD_DIR_TEST)/%.o : $(SRC_DIR_TEST)/%.c
	@$(DIRGUARD)
	@$(CC) -I $(SRC_DIR) -I thirdparty -c $< $(CFLAG) $@

.PHONY: testing
testing: $(TARGET_TEST)
	$(TARGET_TEST)



