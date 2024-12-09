// cai_functions.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cai_functions.h"

const char *correct_responses[] = {
    "Very good!", "Excellent!", "Nice work!", "Well done!", "Great!", "Keep up the good work!"
};

const char *incorrect_responses[] = {
    "No. Please try again.", "Wrong. Try once again.", "Don’t give up!", "No. Keep trying.", "Sorry, it is not right."
};

void get_user_name(char name[]) {
    printf("Enter your name:  ");
    scanf("%s", name);
    printf("Welcome, %s!\n", name);
}

int get_choice(int num_choices) {
    int choice;
    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= num_choices)
            return choice;
        else {
            printf("Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear input buffer
        }
    }
}

void generate_question(char mode, int *num1, int *num2, int *correct_answer) {
    if (mode == 'a') {  // Addition
        *num1 = rand() % 100;
        *num2 = rand() % (100 - *num1); // Ensure sum <= 99
        *correct_answer = *num1 + *num2;
    }
    else if (mode == 's') {  // Subtraction
        *num1 = rand() % 100;
        *num2 = rand() % (*num1 + 1); // Ensure result is non-negative
        *correct_answer = *num1 - *num2;
    }
    else if (mode == 'm') {  // Mixed
        if (rand() % 2 == 0) {  // Randomly choose addition or subtraction
            *num1 = rand() % 100;
            *num2 = rand() % (100 - *num1); // Ensure sum <= 99
            *correct_answer = *num1 + *num2;
        } else {
            *num1 = rand() % 100;
            *num2 = rand() % (*num1 + 1); // Ensure result is non-negative
            *correct_answer = *num1 - *num2;
        }
    }
}


void practice(char mode) {
    printf("Now, you will be given 10 questions to solve:\n");
    int correct_count = 0;
    for (int i = 1; i <= 10; i++) {
        int num1, num2, correct_answer;
        generate_question(mode, &num1, &num2, &correct_answer);
        int user_answer;

        while (1) {
            printf("%d. %d %c %d = ", i, num1, (mode == 'a') ? '+' : (mode == 's') ? '-' : '+', num2);
            scanf("%d", &user_answer);
            if (user_answer == correct_answer) {
                printf("%s\n", correct_responses[rand() % 6]);
                correct_count++;
                break;
            } else {
                printf("%s\n", incorrect_responses[rand() % 5]);
            }
        }
    }
    printf("Practice completed. You answered %d/10 questions correctly.\n", correct_count);
}

void test(char mode) {
    printf("Now, you will be given 15 questions to solve:\n");
    int correct_count = 0;
    int questions[15][4];  // Stores question number, num1, num2, user_answer

    for (int i = 0; i < 15; i++) {
        int num1, num2, correct_answer;
        generate_question(mode, &num1, &num2, &correct_answer);
        int user_answer;
        printf("%d. %d %c %d = ", i + 1, num1, (mode == 'a') ? '+' : (mode == 's') ? '-' : '+', num2);
        scanf("%d", &user_answer);
        questions[i][0] = i + 1;
        questions[i][1] = num1;
        questions[i][2] = num2;
        questions[i][3] = user_answer;

        if (user_answer == correct_answer) {
            correct_count++;
        }
    }

    // Display test results
    print_test_results(correct_count, 15, questions);
}

void print_test_results(int correct_count, int total_questions, int questions[][4]) {
    printf("\nTest completed.\n");
    printf("Your score: %d/%d (%.2f%%)\n", correct_count, total_questions, (correct_count / (float)total_questions) * 100);
    for (int i = 0; i < total_questions; i++) {
        printf("Q%d: %d %c %d = Correct: %d, Your answer: %d\n",
            questions[i][0], questions[i][1],
            (questions[i][2] >= questions[i][1]) ? '-' : '+',
            questions[i][2],
            (questions[i][2] >= questions[i][1]) ? questions[i][1] - questions[i][2] : questions[i][1] + questions[i][2],
            questions[i][3]);
    }
}
