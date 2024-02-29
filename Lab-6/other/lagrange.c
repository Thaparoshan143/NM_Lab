// Implementation of lagrange method with function form

#include<stdio.h>
#include<math.h>

typedef struct Point
{
    double x, y;
}Point;


void print_point(Point *p, int count)
{
    for(int i=0;i<count;i++)
    {
        printf("%lf, %lf\n", p[i].x, p[i].y);
    }
}

void get_points(Point *target, int count)
{
    printf("\nEnter the data points:\n");
    for(int i=0;i<count;i++)
    {
        printf("(x%d, y%d) : ", i+1, i+1);
        scanf("%lf %lf", &target[i].x, &target[i].y);
    }
}

int main()
{
    float sum = 0, x, h;
    int pointCount;
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