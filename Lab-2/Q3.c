#include<stdio.h>
#include<math.h>

#define f(x) (x*log10(x)-1.2)

void seperator(const char symbol, int count)
{
    printf("\n");
    for(int i=0;i<count;i++)
    {
        printf("%c", symbol);
    }
    printf("\n");
}

int getIntInput(const char *label)
{
    int temp;
    printf("%s", label);
    scanf("%d", &temp);
    return temp;
}

float getFloatInput(const char *label)
{
    float temp;
    printf("%s", label);
    scanf("%f", &temp);
    return temp;
}

void print_table_title()
{
    seperator('_',100);
    printf("Iteration\t\tx0\t\tx1\t\t\tx2\t\t\tf(x2)");
    seperator('_',100);
}

void print_table_content(int step, float x0, float x1, float x2, float fx2)
{
    printf("%d\t\t%f\t\t%f\t\t%f\t\t%f\n", step, x0, x1, x2, fx2);
}

int main()
{
    double x0, x1, x2, f0, f1, f2, err;
    int step = 1;

    Input:
    x0 = getFloatInput("\nEnter the value of lower initial guess : ");
    x1 = getFloatInput("\nEnter the valie of higher initla guess : ");
    err = getFloatInput("\nEnter the value of predefined error : ");

    f0 = f(x0);
    f1 = f(x1);

    if(f0*f1>0.0)
    {
        printf("\nThe initial guess is wrong again! please assign value again!");
        goto Input;
    }

    print_table_title();

    do{
        x2 = (x1+x0)/2.0;
        f2 = f(x2);

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
        print_table_content(step, x0, x1, x2, f2);
        step++;

    }while(fabs(f2)>err);

    seperator('_',100);
    printf("\nThe approximate real root is %0.8f", x2);

    return 0;
}