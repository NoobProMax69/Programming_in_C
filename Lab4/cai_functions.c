#include <stdio.h>
#include <stdlib.h>
#include "cai_functions.h"

const char *correct_responses[] = {
    "Very good!", "Excellent!", "Nice work!", "Well done!", "Great!", "Keep up the good work!"
};

const char *incorrect_responses[] = {
    "No. Please try again.", "Wrong. Try again.", "Don't give up!", "No. Keep trying.", "Sorry, it is not right."
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
        else
            printf("Please enter a valid number.\n");
    }
}

void generate_question(char mode, int *num1, int *num2, int *correct_answer, char *operator) {
    if (mode == 'a') {  // Addition
        *num1 = rand() % 100;
        *num2 = rand() % (100 - *num1);  // Ensure sum <= 100
        *correct_answer = *num1 + *num2;
        *operator = '+';
    } else if (mode == 's') {  // Subtraction
        *num1 = rand() % 100;
        *num2 = rand() % (*num1 + 1);  // Ensure num2 <= num1 for non-negative result
        *correct_answer = *num1 - *num2;
        *operator = '-';
    } else if (mode == 'm') {  // Mixed
        if (rand() % 2 == 0) {  // Randomly select addition or subtraction
            *num1 = rand() % 100;
            *num2 = rand() % (100 - *num1);  // Addition case
            *correct_answer = *num1 + *num2;
            *operator = '+';
        } else {
            *num1 = rand() % 100;
            *num2 = rand() % (*num1 + 1);  // Subtraction case
            *correct_answer = *num1 - *num2;
            *operator = '-';
        }
    }
}



void practice(char mode) {
    printf("Now, you will be given 10 questions to solve:\n");
    int correct_count = 0;

    for (int i = 1; i <= 10; i++) {
        int num1, num2, correct_answer;
        char operator;
        generate_question(mode, &num1, &num2, &correct_answer, &operator);

        int user_answer;
        while (1) {
            printf("%d. %d %c %d = ", i, num1, operator, num2);
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
    int questions[15][4];  // Stores question number, num1, num2, and user_answer
    char operators[15];    // Stores the operator for each question

    for (int i = 0; i < 15; i++) {
        int num1, num2, correct_answer;
        char operator;
        generate_question(mode, &num1, &num2, &correct_answer, &operator);

        operators[i] = operator; // Store the operator for this question

        int user_answer;
        printf("%d. %d %c %d = ", i + 1, num1, operator, num2);
        scanf("%d", &user_answer);

        // Store the question details
        questions[i][0] = i + 1;
        questions[i][1] = num1;
        questions[i][2] = num2;
        questions[i][3] = user_answer;

        if (user_answer == correct_answer) {
            correct_count++;
        }
    }

    print_test_results(correct_count, 15, questions, operators);
}



void print_test_results(int correct_count, int total_questions, int questions[][4], char operators[]) {
    printf("\nTest completed.\n");
    printf("Your score: %d/%d (%.2f%%)\n", correct_count, total_questions, (correct_count / (float)total_questions) * 100);

    printf("\n%-5s %-10s %-10s %-15s %-15s\n", "Q#", "Number 1", "Number 2", "Correct Answer", "Your Answer");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < total_questions; i++) {
        int num1 = questions[i][1];
        int num2 = questions[i][2];
        int user_answer = questions[i][3];
        int correct_answer;

        // Determine the correct answer based on the operator
        if (operators[i] == '+') {
            correct_answer = num1 + num2;
        } else if (operators[i] == '-') {
            correct_answer = num1 - num2;
        }

        printf("%-5d %-10d %-10d %-15d %-15d\n",
               questions[i][0], num1, num2, correct_answer, user_answer);
    }
}

