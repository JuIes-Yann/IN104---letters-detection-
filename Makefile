CC=gcc
CFLAGS=-I

lettermake: letter_recognition.c
	$(CC) -o letter_recognition.out letter_recognition.c  -lm
	./letter_recognition.out
