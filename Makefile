#SHELL     = /bin/sh
#BUILD_DIR = ` pwd `
BUILD_DIR = $(shell pwd)
SRC_DIR   = $(BUILD_DIR)/src
INC_DIR   = $(BUILD_DIR)/inc
OBJ_DIR   = $(BUILD_DIR)/obj
CC        = g++
RM        = rm -rf

all:
	@echo "--------"
	@echo "----Make all in BUILD_DIR = $(BUILD_DIR)"
	@echo "--------"
	mkdir -p $(OBJ_DIR) 
	$(CC) $(SRC_DIR)/*.cpp -o $(OBJ_DIR)/battle.out
	@echo "--------"
	@echo "----Building was successfully finished-----"
	@echo "--------"

clean:
	$(RM) $(OBJ_DIR)/* 
