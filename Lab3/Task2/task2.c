#include <stdio.h>

int main(){

    double x;
    printf("Enter value for x: ");
    scanf("%lf", &x);

    double sum = 1.0;
    double term = 1.0;
    int n;

    printf("Term\tSum\n");

    while (term >= 0.0000001){
        printf("%d\t%.7f\n", n+1, sum);
        n++;
        term = term * (x / n);
        sum += term;
    }
    
    return 0;
}