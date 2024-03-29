#include "uart.h"
#include "command.h"

void receive_uart_thread(int *pfd);

int main (int argc, char *argv[])
{
	pthread_t rx_thread;
	int *pfd;
	int uart0_filestream = -1;

	uart0_filestream = open_uart ("/dev/ttyAMA0", 9600);
	
	if (uart0_filestream == -1)
	{
		printf("Error - Unable to open UART\n");
	}

	//----- Uart receive -----
	if (uart0_filestream != -1)
	{
		pfd = (int*)malloc(sizeof(int));
		*pfd = uart0_filestream;
		pthread_create( &rx_thread, NULL, &receive_uart_thread, pfd);
	}

	//----- Uart Transmit -----
	if (uart0_filestream != -1)
	{
		printf ("Start send command!\n");
		//control_servo (uart0_filestream, 1, atoi(argv[1]));
		get_temperature (uart0_filestream);
		printf ("Finish send command!\n");
	}

	while(1);

	free(pfd);
	close(uart0_filestream);
}

void receive_uart_thread(int *pfd)
{
	char *rx_buffer;
	rx_buffer = (char*)malloc(sizeof(char)*256);
	
	while (1)
	{
		rx_uart (*pfd, rx_buffer, 6);
		fflush (stdout) ;
	}
}

