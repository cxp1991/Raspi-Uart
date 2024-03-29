#include <stdio.h>
#include <unistd.h>			
#include <fcntl.h>			
#include <termios.h>		
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
 #include <pthread.h>

int open_uart (const char *device, const int baud);
int tx_uart (int fd, const char *tx_buffer);
int rx_uart (int fd, char *rx_buffer, int num_byte_receive_expected);
