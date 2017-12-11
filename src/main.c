#include "system.h"
#include "gpio.h"

inline void blink_handler(unsigned int curr, unsigned int prev) {
	curr = ticks / 250;
	if (curr != prev)
		(curr % 2) ?
			gpio_writePin(LED_PORT, LED3_PIN, 1) :
			gpio_writePin(LED_PORT, LED3_PIN, 0);
	prev = curr;
}

int main(void) {

	unsigned int curr = 0, prev = 0;

	/* Initialize LED */
	gpio_setClock(LED_PORT, true);
	gpio_setMode(LED_PORT, LED3_PIN, OUTPUT);
	gpio_setSpeed(LED_PORT, LED3_PIN, LOW_SPEED);
	gpio_writePin(LED_PORT, LED3_PIN, 0);

	while (1) {
		blink_handler(curr, prev);
	}
}
