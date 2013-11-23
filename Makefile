SOURCE_DIR=src
CC=g++
OPTIONS=-std=c++11 -shared
LIB=-lrocksdb -lpthread -lrt -lsnappy -lgflags -lz -lbz2 -lphpcpp
INC=-I./$(SOURCE_DIR)/include
INPUT=$(SOURCE_DIR)/rocksdb_php.cpp
OUTPUT_DIR=bin
OUTPUT_FILE=rocksdb_php.so

all:
	mkdir -p $(OUTPUT_DIR)
	$(CC) $(OPTIONS) $(INPUT) $(LIB) $(INC) -o $(OUTPUT_DIR)/$(OUTPUT_FILE)
