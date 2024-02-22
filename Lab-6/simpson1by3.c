// Implementation of 1/3 simpson rule

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
        else if(i%2 == 0)
        {
            integ += 2 * points[i].y;
        }
        else
        {
            integ += 4 * points[i].y;
        }
    }

    integ = h * integ/3;

    printf("\nThe approx integral is : %f", integ);
    return 0;
}