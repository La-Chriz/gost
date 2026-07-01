CC ?= gcc
CFLAGS ?= -Wall -Wextra -std=c99
CPPFLAGS += -I./src -DGOST_IMPLEMENTATION

TARGET := gost
SRCS := src/main.c

all: $(TARGET)

$(TARGET): $(SRCS) src/gost.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(TARGET)
