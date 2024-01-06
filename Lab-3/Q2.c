#include<stdio.h>
#include<math.h>

#define POINTS_SIZE 15

typedef struct Point {
    double x, y;
}Point;

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

Point getPointInput()
{
    Point temp;
    printf("x : ");
    scanf("%lf", &temp.x);
    printf("y : ");
    scanf("%lf", &temp.y);
    seperator('-',15);
    return temp;
}

void getPointsInput(Point *target, int count)
{
    printf("\nEnter the value of respective points :\n");
    for(int i=1;i<=count;i++)
    {
        target[i] = getPointInput();
    }
}

void displayPoints(Point *target, int count)
{
    seperator('_',50);
    printf("x\t\t\ty");
    seperator('_',50);
    for(int i=1;i<=count;i++)
    {
        printf("%f\t\t%f\n", target[i].x, target[i].y);
    }
    seperator('_',50);
}

int main()
{
    int n, i;
    double sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0, a = 0, b = 0;

    Point point[POINTS_SIZE];
    printf("Fitting the straight line y = a + bx using the method of least square\n");
    n = getIntInput("\nEnter the number of data points (n) : ");

    getPointsInput(point, n);
    displayPoints(point, n);

    for(int i=1;i<=n;i++)
    {
        sumx += point[i].x;
        sumy += point[i].y;
        sumx2 += (point[i].x * point[i].x);
        sumxy += (point[i].x * point[i].y);
    }

    b = ((n * sumxy - sumx * sumy)/(n * sumx2 - sumx * sumx));
    a = (sumy - b * sumx)/n;

    printf("\nThe value is as a = %0.9f and b = %0.9f", a, b);

    printf("\nThe Fitted regression line is  y = %0.9f + %0.9fx", a, b);

    return 0;
}