# A simple Makefile
# Kedir Birhan G00902260
# CS 262, Lab Section 202
# project 2
# The compiler: gcc for C programs, g++ for C++ programs, etc
CC = gcc 
CFLAGS=-g
TARGET = project2_kbirhan_202
all: $(TARGET)

$(TARGET): $(TARGET).c

	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c supporterFunction.c

clean:
	rm $(TARGET)
