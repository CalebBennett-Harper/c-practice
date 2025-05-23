CC = clang
CFLAGS = -Wall -Wextra -Werror -std=c99

TARGET = expenseTracker
SOURCE = expenseTracker.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

.PHONY: clean 