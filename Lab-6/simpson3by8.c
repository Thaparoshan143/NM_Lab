// Implementation of 3/8 simpson rule

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
        else if(i%3 == 0)
        {
            integ += 2 * points[i].y;
        }
        else
        {
            integ += 3 * points[i].y;
        }
    }

    integ = 3 * h * integ/8;

    printf("\nThe approx integral is : %f", integ);
    return 0;
}