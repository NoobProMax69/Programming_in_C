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
    // Set PORTD as output for statuses (bits 0-3) and conditions (bits 4-7)
    DDRD = 0xFF; // Set all 8 bits of PORTD as output

    while (1) {
        // First test case
        uint8_t stat = 0B01101101;
        display_statuses_and_results(stat);
        _delay_ms(12000); // Delay 12 seconds

        // Second test case
        stat = 0B01010111;
        display_statuses_and_results(stat);
        _delay_ms(12000); // Delay 12 seconds

        // Third test case
        stat = 0B00000000;
        display_statuses_and_results(stat);
        _delay_ms(12000); // Delay 12 seconds
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

    // Display statuses on LEDs connected to bits 0–3
    PORTD = (stat & 0x0F); // Copy bits 0-3 directly to LEDs 0-3

    // Clear condition LEDs (bits 4–7)
    PORTD &= 0x0F;

    // Evaluate conditions and map them to LEDs 4–7
    // Condition 0: Everything in the car is working normally
    if ((stat & 0x0F) == 0) {
        PORTD |= (1 << 4); // Turn on LED 4
    }

    // Condition 1: Engine is too hot
    if (engine_temp == 1) {
        PORTD |= (1 << 5); // Turn on LED 5
    }

    // Condition 2: Engine oil is too low AND engine is too hot
    if (oil_level == 1 && engine_temp == 1) {
        PORTD |= (1 << 6); // Turn on LED 6
    }

    // Condition 3: Brake fluid is too low OR brake pads are bad
    if (brake_fluid == 1 || brake_pad == 1) {
        PORTD |= (1 << 7); // Turn on LED 7
    }
}
