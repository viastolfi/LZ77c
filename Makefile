BUILD = build
SRC = src

CS = \
	$(SRC)/main.c \

OBJ = \
	$(BUILD)/main.o \

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all clean

all: $(BUILD)/lz77c

$(BUILD)/lz77c : $(OBJ)
	$(CC) -o $@ $^

$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

