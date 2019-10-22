all: encode channel decode

encode: encode.c
	gcc -Wall -o encode encode.c support.c
channel: channel.c
	gcc -Wall -o channel channel.c -lm
decode: decode.c
	gcc -Wall -o decode decode.c support.c
