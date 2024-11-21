/** @file lab2.c
*
* @brief lab2 on car statuses
* Author :
*/

#include <avr/io.h>
#include <util/delay.h>

// Set CPU clock to 16MHz
#define F_CPU 16000000

// Function prototype
void display_statuses_and_results(uint8_t stat);

int main(void) {
    // Set PORTD as output (all 8 bits: 0-3 for statuses, 4-7 for conditions)
    DDRD = 0xFF;

    while (1) {
        // First test case
        uint8_t stat = 0B01101101;
        display_statuses_and_results(stat);
        _delay_ms(12000); // Delay 2 minutes

        // Second test case
        stat = 0B01010111;
        display_statuses_and_results(stat);
        _delay_ms(12000); // Delay 2 minutes

        // Third test case
        stat = 0B00000000;
        display_statuses_and_results(stat);
        _delay_ms(12000); // Delay 2 minutes
    }
}

/*!
* @brief Display car statuses and condition results using LEDs
* @param[in] stat The 8-bit variable storing the statuses
* @return nothing
*/
void display_statuses_and_results(uint8_t stat) {
    uint8_t brake_pad = stat & 0x01;       // Bit 0
    uint8_t brake_fluid = (stat & 0x02) >> 1; // Bit 1
    uint8_t engine_temp = (stat & 0x04) >> 2; // Bit 2
    uint8_t oil_level = (stat & 0x08) >> 3;   // Bit 3

    // Clear the outputs (turn off all LEDs)
    PORTD = 0x00;

    // Evaluate conditions and map them to LEDs
    // Condition 0: Everything in the car is working normally
    if (stat == 0) {
        PORTD |= (1 << 0); // Turn on LED 0
    }

    // Condition 1: Engine is too hot
    if (engine_temp == 1) {
        PORTD |= (1 << 1); // Turn on LED 1
    }

    // Condition 2: Engine oil is too low AND engine is too hot
    if (oil_level == 1 && engine_temp == 1) {
        PORTD |= (1 << 2); // Turn on LED 2
    }

    // Condition 3: Brake fluid is too low OR brake pads are bad
    if (brake_fluid == 1 || brake_pad == 1) {
        PORTD |= (1 << 3); // Turn on LED 3
    }
}

