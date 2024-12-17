#include <stdio.h>
#include "cai_functions.h"

int main() {
    char name[50];
    int choice;

    get_user_name(name);

    while (1) {
        printf("\nYou can choose:\n");
        printf("1. Do a practice\n");
        printf("2. Complete a test\n");
        printf("3. Quit the program\n");
        choice = get_choice(3);

        if (choice == 1) {
            printf("\nNow, you can choose to do practices on:\n");
            printf("1. Additions\n");
            printf("2. Subtractions\n");
            printf("3. Additions and Subtractions\n");
            int practice_mode = get_choice(3);
            if (practice_mode == 1)
                practice('a'); // Addition practice
            else if (practice_mode == 2)
                practice('s'); // Subtraction practice
            else
                practice('m'); // Mixed practice
        }
        else if (choice == 2) {  // Test mode
            printf("\nNow, you can choose to do a test on:\n");
            printf("1. Additions\n");
            printf("2. Subtractions\n");
            printf("3. Additions and Subtractions\n");
            int test_mode = get_choice(3);
            if (test_mode == 1)
                test('a'); // Addition test
            else if (test_mode == 2)
                test('s'); // Subtraction test
            else
                test('m'); // Mixed test
        }
        else if (choice == 3) {  // Quit program
            printf("Thank you for using the program! Goodbye.\n");
            break;
        }
    }

    return 0;
}