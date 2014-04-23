all:
	gcc -o main -Wall main.c command.c uart.c -lpthread

clean:
	rm main
