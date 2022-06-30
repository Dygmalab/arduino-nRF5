//#include "Kaleidoscope.h"

//#include "hw/bsp/board_mcu.h"
/*#include "tusb.h"
#include "usb_descriptors.h"
#include "class/hid/hid_device.h"*/

//#include "nrfx_usbd.h"

#include "Adafruit_TinyUSB.h"

#define LED1 13
#define LED2 14
#define LED3 15
#define LED4 16

#define BTN1 11
#define BTN2 12
#define BTN3 24
#define BTN4 25

// Report ID
enum
{
  RID_KEYBOARD = 1,
  RID_MOUSE,
  RID_CONSUMER_CONTROL, // Media, volume etc ..
};

// HID report descriptor using TinyUSB's template
uint8_t const desc_hid_report[] =
{
  TUD_HID_REPORT_DESC_KEYBOARD( HID_REPORT_ID(RID_KEYBOARD) ),
  TUD_HID_REPORT_DESC_MOUSE   ( HID_REPORT_ID(RID_MOUSE) ),
  TUD_HID_REPORT_DESC_CONSUMER( HID_REPORT_ID(RID_CONSUMER_CONTROL) )
};

// USB HID object
Adafruit_USBD_HID usb_hid(desc_hid_report, sizeof(desc_hid_report), HID_ITF_PROTOCOL_NONE, 2, false);

void setup() 
{
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);
	digitalWrite(LED1, HIGH);
	digitalWrite(LED2, HIGH);
	digitalWrite(LED3, HIGH);
	digitalWrite(LED4, HIGH);
	
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
	
	// usb_hid.setPollInterval(2);
	// usb_hid.setReportDescriptor();
	// usb_hid.setStringDescriptor("TinyUSB HID Composite");
	
	usb_hid.begin();
	digitalWrite(LED1, LOW);  // USB inited.

	TinyUSB_Device_Init(0);  // initialize tinyusb stack.
	//tusb_init(); // initialize tinyusb stack
	
	// wait until device mounted
	while (!TinyUSBDevice.mounted()) delay(1);
	digitalWrite(LED2, LOW);  // USB mounted.
}

void loop() 
{
	TinyUSB_Device_Task();  // USB device task.
	//tud_task();

	//if (TinyUSBDevice.mounted()) digitalWrite(LED2, LOW);  // USB mounted.
}
