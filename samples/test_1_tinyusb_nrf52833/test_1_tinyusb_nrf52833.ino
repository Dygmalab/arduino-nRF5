//#include "Kaleidoscope.h"

//#include "hw/bsp/board_mcu.h"
#include "tusb.h"
//#include "usb_descriptors.h"
//#include "class/hid/hid_device.h"

//#include "nrfx_usbd.h"

#define LED1 13
#define LED2 14
#define LED3 15
#define LED4 16

#define BTN1 11
#define BTN2 12
#define BTN3 24
#define BTN4 25

void setup() 
{
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);
	digitalWrite(LED1, LOW);
	digitalWrite(LED2, LOW);
	digitalWrite(LED3, LOW);
	digitalWrite(LED4, LOW);
	
	pinMode(BTN1, INPUT_PULLUP);
	pinMode(BTN2, INPUT_PULLUP);
	pinMode(BTN3, INPUT_PULLUP);
	pinMode(BTN4, INPUT_PULLUP);

	for (uint8_t i = 0; i < 3; i++)
	{
		digitalWrite(LED1, LOW);
		digitalWrite(LED2, LOW);
		digitalWrite(LED3, LOW);
		digitalWrite(LED4, LOW);
		delay(200);
		digitalWrite(LED1, HIGH);
		digitalWrite(LED2, HIGH);
		digitalWrite(LED3, HIGH);
		digitalWrite(LED4, HIGH);
		delay(200);
	}

	//board_init();
	tusb_init(); // initialize tinyusb stack
	digitalWrite(LED1, LOW);
}

void loop() 
{
	tud_task(); // device task
	digitalWrite(LED2, LOW);
}
