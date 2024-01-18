#include <stdio.h>
#include <math.h>

#define f(x) x - ((exp(x)+cos(x)-3*x*x)/(exp(x)-sin(x)-6*x))

void seperator(const char symbol, int count)
{
    printf("\n");
    for(int i=0;i<count;i++)
    {
        printf("%c", symbol);
    }
    printf("\n");
}

float getFloatInput(const char* title)
{
    float temp = 0;
    printf("%s", title);
    scanf("%f", &temp);
    return temp;
}

int getIntInput(const char* title)
{
    int temp;
    printf("%s", title);
    scanf("%d", &temp);
    return temp;
}

void print_table_title()
{
    seperator('-', 100);
    printf("Iterations\t x0\t\t x1\t\tf(x1)-x1\n");
    seperator('-', 100);
}

int main() {
    int step = 1, N;
    float x0, x1, f1, err;
    x0 = getFloatInput("Enter the initial guess (x0) : ");
    err = getFloatInput("Enter the error tolerance (e) : ");
    N = getIntInput("Enter the maximum number of iteration (N) : ");

    print_table_title();

    do {
        x1 = f(x0);
        f1 = f(x1) - x1;
        printf("%d\t\t% .7lf\t% .7lf\t% .7lf\n", step, x0, x1, f1);
        x0 = x1;
        step++;
    } while (fabs(f1) > err);

    seperator('_',100);
    printf("The approximated root is: %0.8lf\n", x1);

    return 0;
}