// Implementation of trapezoidal rule

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
    float integ = 0, h;
    printf("Enter the number of points (n) : ");
    scanf("%d", &pointCount);

    Point points[pointCount];

    get_points(points, pointCount);

    h = (points[1].x - points[0].x);

    for(int i=0;i<=pointCount;i++)
    {
        if(i == 0 || i == pointCount)
        {
            integ += points[i].y;
        }
        else
        {
            integ += 2 * points[i].y;
        }
    }

    integ = h * integ/2;

    printf("\nThe approx integral is : %f", integ);
    return 0;
}