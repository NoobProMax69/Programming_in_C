/** @file lab2.c
*
* @brief lab2 on car statuses
* Author :
*/

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000

void display_statuses_and_results(uint8_t stat);

int main(void) {
    DDRD = 0xFF; // Set all PORTD pins as outputs

    while (1) {
        // Test case 1
        uint8_t stat = 0B01101101;
        display_statuses_and_results(stat);
        _delay_ms(12000);

        // Test case 2
        stat = 0B01010111;
        display_statuses_and_results(stat);
        _delay_ms(12000);

        // Test case 3
        stat = 0B00000000;
        display_statuses_and_results(stat);
        _delay_ms(12000);
    }
}

/*!
* @brief Display car statuses and condition results using LEDs
* @param[in] stat The 8-bit variable storing the statuses
* @return nothing
*/
void display_statuses_and_results(uint8_t stat) {
    // Extract the individual statuses from the stat variable
    uint8_t brake_pad = stat & 0x01;         // Bit 0
    uint8_t brake_fluid = (stat & 0x02) >> 1; // Bit 1
    uint8_t engine_temp = (stat & 0x04) >> 2; // Bit 2
    uint8_t oil_level = (stat & 0x08) >> 3;   // Bit 3

    // Display statuses on LEDs 0–3
    PORTD = (stat & 0x0F); // Directly assign lower 4 bits to LEDs 0–3

    // Evaluate and set condition LEDs (4–7) individually
    if ((stat & 0x0F) == 0) {
        PORTD |= (1 << 4); // All systems normal -> LED 4 ON
    } else {
        PORTD &= ~(1 << 4); // All systems not normal -> LED 4 OFF
    }

    if (engine_temp == 1) {
        PORTD |= (1 << 5); // Engine too hot -> LED 5 ON
    } else {
        PORTD &= ~(1 << 5); // Engine normal -> LED 5 OFF
    }

    if (oil_level == 1 && engine_temp == 1) {
        PORTD |= (1 << 6); // Oil low and engine too hot -> LED 6 ON
    } else {
        PORTD &= ~(1 << 6); // Condition not met -> LED 6 OFF
    }

    if (brake_fluid == 1 || brake_pad == 1) {
        PORTD |= (1 << 7); // Brake fluid low or pads bad -> LED 7 ON
    } else {
        PORTD &= ~(1 << 7); // Condition not met -> LED 7 OFF
    }
}
