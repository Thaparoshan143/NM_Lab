// Curve Fitting of second degree parabola : ax^2 + bx + c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ARRAY_SIZE 20

typedef struct Point
{
    double x, y;
}Point;

void print_label(const char *label)
{
    printf("\n%s\n", label);
}

void seperator(const char symbol, int count)
{
    printf("\n");
    for(int i=0;i<count;i++)
    {
        printf("%c", symbol);
    }
    printf("\n");
}

int get_int_input(const char *label)
{
    int temp;
    printf("%s", label);
    scanf("%d", &temp);
    return temp;
}
void get_points_input(Point *target, int n)
{
    print_label("Enter points value : ");
    for (int i = 1; i <= n; i++) 
    {
        printf("(x, y) : ");
        scanf("%lf %lf", &(target[i].x), &(target[i].y));
    }
}

void display_points(Point *point, int n)
{
    print_label("Entered points value are as :");
    seperator('-',50);
    printf("x\t\ty");
    seperator('-',50);
    for (int i = 1; i <= n; i++) 
    {
        printf("%f\t%f\n", point[i].x, point[i].y);
    }
    seperator('-',50);
}

int main() 
{
    int n, i, j, k;
    Point point[ARRAY_SIZE];
    float sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0, sumx3 = 0, sumx2y = 0, sumx4 = 0;
    float c[ARRAY_SIZE], a[ARRAY_SIZE][ARRAY_SIZE], sum, ratio;
    int m = 3; 

    print_label("Fitting the parabola y = ax^2 + bx + c using the method of least squares");
    n = get_int_input("Enter number of data points (n) : ");

    get_points_input(point, n);
    display_points(point, n);

    for (i = 1; i <= n; i++) 
    {
        sumx += point[i].x;
        sumy += point[i].y;
        sumxy += point[i].x * point[i].y;
        sumx2 += pow(point[i].x, 2);
        sumx2y += pow(point[i].x, 2) * point[i].y;
        sumx3 += pow(point[i].x, 3);
        sumx4 += pow(point[i].x, 4);
    }

    // Creating the augmented matrix
    a[3][1] = a[2][2] = a[1][3] = sumx2;
    a[3][2] = a[2][3] = sumx;
    a[3][3] = n;
    a[3][4] = sumy;
    a[2][1] = a[1][2] = sumx3;
    a[2][4] = sumxy;
    a[1][1] = sumx4;
    a[1][4] = sumx2y;

    print_label("The augmented matrix is as :");
    printf("%f\t%f\t%f\t:\t%f\n", sumx4, sumx3, sumx2, sumx2y);
    printf("%f\t%f\t%f\t:\t%f\n", sumx3, sumx2, sumx, sumxy);
    printf("%f\t%f\t%f\t:\t%f\n", sumx2, sumx, (float)n, sumy);

    // Solving for a, b, c using Gauss Elimination Method
    // Condition for Gauss Elimination
    for (i = 1; i <= m - 1; i++) 
    {
        if (a[i][i] == 0.0) 
        {
            printf("\nMathematical Error! We cannot apply Gauss Elimination Method.\n");
            exit(0);
        }
    }

    // Forward Elimination
    for (j = 1; j <= m; j++) 
    {
        for (i = 1; i <= m; i++) 
        {
            if (i > j) 
            {
                ratio = a[i][j] / a[j][j];
                for (k = 1; k <= m + 1; k++) 
                {
                    a[i][k] = a[i][k] - ratio * a[j][k];
                }
            }
        }
    }

    // Backward Substitution
    if (a[m][m] == 0 && a[m][m + 1] != 0) 
    {
        printf("\nThe system is inconsistent and it has no solution.\n");
        exit(0);
    }
    if (a[m][m] == 0 && a[m][m + 1] == 0) 
    {
        printf("\nThe system is consistent and it has infinite solutions.\n");
        exit(0);
    }

    c[m] = a[m][m + 1] / a[m][m];

    for (i = m - 1; i >= 1; i--) 
    {
        sum = 0;
        for (j = i + 1; j <= m; j++) 
        {
            sum += a[i][j] * c[j];
            c[i] = (a[i][m + 1] - sum) / a[i][i];
        }
    }

    print_label("The system is consistent & has unique solutions.\nThe approx. value of constants are :");
    printf("a = %f, b = %f, c = %f", c[1], c[2], c[3]);
    printf("\nThe fitted parabola equation is \ny = (%fx^2) + (%fx) + (%f)\n", c[1], c[2], c[3]);

    return 0;
}
