#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

// Open UART_TX location
int handle_ (open("/dev/ttyO1", O_RDWR | O_NOCTTY));

// Initialize UART
void init()
{
    struct termios options;
    tcgetattr(handle_, &options);

    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);

    options.c_cflag |= B115200;
    options.c_cflag |= CS8;
    options.c_iflag |= IGNPAR;

    tcsetattr(handle_, TCSANOW, &options);
}

int main(){
	init();
	char byte[1];
	while(true){
		scanf("%c", byte);
		write(handle_, byte, sizeof(byte));
	}
	return 0;
}
