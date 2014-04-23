#include "uart.h"
#include "command.h"

void receive_uart_thread(int *pfd)
{
	char *rx_buffer;
	rx_buffer = (char*)malloc(sizeof(char)*256);
	
	while (1)
	{
		tcflush (*pfd, TCIOFLUSH) ;
		rx_uart (*pfd, rx_buffer, 9);
		fflush (stdout) ;
	}
}

int main(int argc, char *argv[])
{
	int uart0_filestream = -1;
	pthread_t rx_thread;

	uart0_filestream = open_uart ("/dev/ttyAMA0", 9600);
	
	if (uart0_filestream == -1)
	{
		printf("Error - Unable to open UART\n");
	}
	
	//----- Uart receive -----
	/*if (uart0_filestream != -1)
	{
		int *pfd;
		pfd = (int*)malloc(sizeof(int));
		*pfd = uart0_filestream;
		pthread_create( &rx_thread, NULL, &receive_uart_thread, pfd);
	}*/

	//----- Uart Transmit -----
	if (uart0_filestream != -1)
	{
	//	tx_uart (uart0_filestream, argv[1]);
		control_servo (uart0_filestream, 1, 30);
	}

	
	
	while(1);
	close(uart0_filestream);

}
