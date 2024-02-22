// Implementation of lagrange method

#include<stdio.h>

typedef struct Point
{
    double x, y;
}Point;

void get_points(Point *target, int count)
{
    printf("\nEnter the data points:\n");
    for(int i=0;i<=count;i++)
    {
        printf("(x%d, y%d) : ", i, i);
        scanf("%lf %lf", &target[i].x, &target[i].y);
    }
}

int main()
{
    int pointCount;
    float sum = 0, x;
    printf("Enter the number of points (n) : ");
    scanf("%d", &pointCount);

    Point points[pointCount];

    get_points(points, pointCount);

    printf("Enter the value of x : ");
    scanf("%f", &x);

    for(int i=0;i<=pointCount;i++)
    {
        float prod = 1.0;
        for(int j=0;j<=pointCount;j++)
        {
            if(i != j)
            {
                prod *= (x-points[j].x) / (points[i].x - points[j].x);
            }
        }
        sum += prod * points[i].y;
    }

    printf("\nThe approx value of f(%.4f) is : %f", x, sum);
    return 0;
}