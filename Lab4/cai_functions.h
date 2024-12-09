
#ifndef CAI_FUNCTIONS_H
#define CAI_FUNCTIONS_H

void get_user_name(char name[]);
int get_choice(int num_choices);
void generate_question(char mode, int *num1, int *num2, int *correct_answer);
void practice(char mode);
void test(char mode);
void print_test_results(int correct_count, int total_questions, int questions[][4]);

#endif //CAI_FUNCTIONS_H
