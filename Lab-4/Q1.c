#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (x*x*x - 2*x -5)

void seperator()
{
    printf("\n________________________________________________________________________________________________________\n");
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
    printf("\nSecant Method\n");
    seperator();
    printf("Iteration\t\tx0\t\t\tx1\t\t\tx2\t\t\tf(x2)");
    seperator();
}

void print_table_content(int i, float x0, float x1, float x2, float fx2)
{
    printf("%d\t\t\t%f\t\t%f\t\t%f\t\t%f\n", i, x0, x1, x2, fx2);
}

int main()
{
    float x0, err, x1, x2, f0, f1, f2;
    int N, step = 1;

    x0 = getFloatInput("Enter the value of initial guess x0 : ");
    x1 = getFloatInput("Enter the value of initial guess x1 : ");

    err = getFloatInput("Enter the maximum error tolerance : ");

    N = getIntInput("Enter the maximum number of iteration : ");

    f0 = f(x0);
    f1 = f(x1);

    if(x0 == x1 || f0 == f1)
    {
        printf("Mathematical Error!");
        exit(0);
    }

    print_table_title();
    do
    {
        x2 = x1 - ((x1-x0)*f1)/(f1-f0);
        f2 = f(x2);

        print_table_content(step, x0, x1, x2, f2);
        step += 1;
        if(step>N)
        {
            printf("The solution doesnt converge");
            exit(1);
        }

        x0 = x1; f0 = f1;
        x1 = x2; f1 = f2;

    }while((fabsf(f2)>err));

    seperator();
    printf("\nThe approximate solution is : %0.8f", x2);
}