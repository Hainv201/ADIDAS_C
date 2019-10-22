CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm
SHAREDFILES = support.c
TARGET = encode channel decode

all: $(TARGET)

encode: encode.c
	$(CC) $(CFLAGS) -o encode encode.c $(SHAREDFILES)
channel: channel.c
	$(CC) $(CFLAGS) -o channel channel.c $(LDFLAGS)
decode: decode.c
	$(CC) $(CFLAGS) -o decode decode.c $(SHAREDFILES)