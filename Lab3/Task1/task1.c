#include <stdio.h>

float calculate_score(float s1, float s2, float s3, float s4, float s5, float difficulty) {
    
    float max_score = 0, min_score = 10, sum = 0;

    
    if (s2 > max_score) max_score = s2;
    if (s3 > max_score) max_score = s3;
    if (s4 > max_score) max_score = s4;
    if (s5 > max_score) max_score = s5;

    if (s2 < min_score) min_score = s2;
    if (s3 < min_score) min_score = s3;
    if (s4 < min_score) min_score = s4;     
    if (s5 < min_score) min_score = s5;

    sum = s1 + s2 + s3 + s4 + s5;

    sum -= (max_score + min_score);

    float final_score = sum * difficulty;

    return final_score;
}

int main() {
    // Input scores and difficulty
    float s1, s2, s3, s4, s5, difficulty;

    printf("Enter the scores from 5 judges:\n\n");

    printf("Enter score fro judge 1: ");
    scanf("%f", &s1);

    printf("Enter score fro judge 2: ");
    scanf("%f", &s2);

    printf("Enter score fro judge 3: ");
    scanf("%f", &s3);

    printf("Enter score fro judge 4: ");
    scanf("%f", &s4);

    printf("Enter score fro judge 5: ");
    scanf("%f", &s5);
    

    printf("\nEnter the degree of difficulty: ");
    scanf("%f", &difficulty);

    float final_score = calculate_score(s1, s2, s3, s4, s5, difficulty);
    printf("\nThe diver's final score is: %.2f\n", final_score);

    return 0;
}
