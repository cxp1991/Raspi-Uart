#include "uart.h"
#include "command.h"

int main (int argc, char *argv[])
{
	int uart0_filestream = -1;

	uart0_filestream = open_uart ("/dev/ttyAMA0", 9600);
	
	if (uart0_filestream == -1)
	{
		printf("Error - Unable to open UART\n");
	}

	//----- Uart Transmit -----
	if (uart0_filestream != -1)
	{
		printf ("Start send command!\n");
		control_servo (uart0_filestream, 1, -30);
		printf ("Finish send command!\n");
	}

	close(uart0_filestream);
}
