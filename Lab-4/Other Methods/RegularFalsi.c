#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (exp(cos(x)) - sin(x))

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
    seperator('_',130);
    printf("Iteration\tx0\t\tf(x0)\t\tx1\t\tf(x1)\t\tx2\t\tf(x2)");
    seperator('_',130);
}

void print_table_content(int step, float x0, float fx0, float x1, float fx1, float x2, float fx2)
{
    printf("%d\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.5f\t\t%.4f\n", step, x0, fx0, x1, fx1, x2, fx2);
}

int main()
{
    float x0, err, x1, x2, f0, f1, f2;
    int N, step = 1;

    Input:
    x0 = getFloatInput("\nEnter the value of lower initial guess : ");
    x1 = getFloatInput("\nEnter the valie of higher inital guess : ");
    err = getFloatInput("\nEnter the value of predefined error : ");

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
        x2 = x0 - ((x1-x0)*f0)/(f1-f0);
        f2 = f(x2);

        print_table_content(step, x0, f0, x1, f1, x2, f2);

        if(f0*f2<0.0)
        {
            x1 = x2;
            f1 = f2;
        }
        else if(f0*f1<0.0)
        {
            x0 = x2;
            f0 = f2;
        }

        step += 1;
        if(step>N)
        {
            printf("The solution doesnt converge");
            exit(1);
        }

    }while((fabsf(f2)>err));

    seperator('_',100);
    printf("\nThe approximate solution is : %0.8f", x2);
}