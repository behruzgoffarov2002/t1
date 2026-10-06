# MR DOPPIX CREATED BY BEHRUZ GOFFAROV CONDATCT TEL:70 024 94 14, TELEGRAM: @BEHRUZGOFFAROV
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99
TARGET = alkene_1974

all: $(TARGET)

$(TARGET): alkene_1974.c
	$(CC) $(CFLAGS) alkene_1974.c -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all clean
