# A simple Makefile
# Kedir Birhan G00902260
# CS 262, Lab Section 202
# project 1
# The compiler: gcc for C programs, g++ for C++ programs, etc
CC = gcc 
CFLAGS=-g -Wall
TARGET = project1_kbirhan_202
all: $(TARGET)

$(TARGET): $(TARGET).c

	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm $(TARGET)
