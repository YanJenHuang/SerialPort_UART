#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

// Open UART_RX location
int handle_ (open("/dev/cu.usbserial", O_RDWR | O_NOCTTY));

// Read Byte
unsigned char readByte()
{
	unsigned char bytes[1];
	while( read(handle_, bytes, sizeof(bytes))==-1);
	return bytes[0];
}

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
	while(true){
		char byte = readByte();
		printf("%c\n", byte);
	}
	return 0;
}