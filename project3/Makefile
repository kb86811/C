# A simple Makefile
# Kedir Birhan G00902260
# CS 262, Lab Section 202
# lab11
# The compiler: gcc for C programs, g++ for C++ programs, etc
CC = gcc 
CFLAGS = -Wall -g -O0 
TARGET = project3_kbirhan_202
OBJ  = test

all: $(TARGET)

$(TARGET): $(TARGET).c item.c

	$(CC) $(CFLAGS) -o $(TARGET)  $(TARGET).c item.c

clean:
	rm $(TARGET)
