// Gauss Jordan Method for Solving the solution

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAT_SIZE 20

int get_int_input(const char *label)
{
    int temp;
    printf("%s", label);
    scanf("%d", &temp);
    return temp;
}

float get_float_input(const char *label)
{
    float temp;
    printf("%s", label);
    scanf("%f", &temp);
    return temp;
}

void print_label(const char *label)
{
    printf("\n%s\n", label);
}

int main()
{
    int n, i, j, k;
    float a[MAT_SIZE][MAT_SIZE], x[MAT_SIZE], ratio, sum;

    print_label("Gauss Jordan Method");
    n = get_int_input("Enter the size of Coefficient matrix A (n) : ");
    print_label("Enter the elements a[i][j] of the agumented matriz [A:C] corresponding to the matrix : ");

    // Taking the input from user in the matrix
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            printf("a[%d][%d] = ", i, j);
            a[i][j] = get_float_input("");
        }
    }

    // Condition of Gauss Jordan
    for(i=1;i<=n-1;i++)
    {
        if(a[i][i]==0)
        {
            print_label("Mathematical Error! We cannot apply Gauss Jordan method");
            print_label("Interchange rows");
            exit(0);
        }
    }

    // Applying the Gauss Jordan
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(i != j)
            {
                ratio = a[i][j]/a[j][j];
                for(k=1;k<=n+1;k++)
                {
                    a[i][k] = a[i][k] - ratio * a[j][k];
                }
            }
        }
    }

    if(a[n][n] == 0 && a[n][n+1] != 0)
    {
        print_label("The system is inconsistent and has no solution");
        exit(0);
    }

    else if(a[n][n] == 0 && a[n][n+1] == 0)
    {
        printf("The system is consistent and has infinite solution");
        exit(0);
    }

    x[n] = a[n][n+1]/a[n][n];

    for(i=n-1;i>=1;i--)
    {
        sum = 0;
        for(j=i+1;j<=n;j++)
        {
            sum += a[i][j] * x[j];
        }

        x[i] = (a[i][n+1] - sum)/a[i][i];
    }

    print_label("The system is consistent and has unique solution");
    print_label("The approximate solution is given as :");

    for(i=1;i<=n;i++)
    {
        printf("\t x[%d] = %0.6f", i, x[i]);
    }

    return 0;
}