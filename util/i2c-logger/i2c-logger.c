#include <pigpio.h>
#include <iostream>
using namespace std;

int main(void)
{
	bsc_xfer_t xfer;
	gpioInitialise();
	xfer.control = (0x48<<16) | 0x305; // Set I2C slave Address to 0x48
	int status = bscXfer(&xfer);

	if (status >= 0) {
		xfer.rxCnt = 0;
		while (1) {
			if (xfer.rxCnt > 0) {
				cout << xfer.rxBuf;
			}

			status = bscXfer(&xfer);
		}
	}

	return 1;
}
