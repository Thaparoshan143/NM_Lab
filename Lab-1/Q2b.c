#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (x*log(x)-1.2)
#define df(x) (log(x)+1)

void seperator()
{
    printf("\n________________________________________________________________________________________________________\n");
}

float getFloatInput(const char* title)
{
    float temp=0;
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
    printf("\nNewton's Raphsons Method\n");
    seperator();
    printf("Iteration\t\tx0\t\tf(x0)\t\t\tx1\t\t\tf(x1)");
    seperator();
}

void print_table_content(int i, float x0, float fx0, float x1, float fx1)
{
    printf("%d\t\t%f\t\t%f\t\t%f\t\t%f\n", i, x0, fx0, x1, fx1);
}

int main()
{
    float x0, err, x1, f0, df0, f1;
    int N, step = 1;

    float eval = exp(1);

    x0 = getFloatInput("Enter the value of initial guess x0 : ");
    err = getFloatInput("Enter the maximum error tolerance : ");

    N = getIntInput("Enter the maximum number of iteration : ");

    print_table_title();

    do
    {
        f0 = f(x0);
        df0 = df(x0);

        if(df0==0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }

        x1 = (x0 - (f0/df0));

        print_table_content(step, x0, f(x0), x1, f(x1));
        step += 1;
        if(step>N)
        {
            printf("The solution doesnt converge");
            exit(1);
        }

        f1 = f(x1);
        x0 = x1;

    }while((fabsf(f1)>err));

    seperator();
    printf("\nThe approximate solution is : %0.8f", x1);
}