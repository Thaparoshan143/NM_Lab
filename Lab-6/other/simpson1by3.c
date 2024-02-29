// Implementation of lagrange method with function form

#include<stdio.h>
#include<math.h>

#define f(x) (2.0/(1+x*x)) // function for which integral is to be taken
#define n 10 // size of step in between the given interval

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


void get_points(Point *target, Point inter, float h)
{
    int ind = 0;

    for(float start = inter.x; start <= inter.y; start += h)
    {
        target[ind].x = start;
        target[ind].y = f(start);
        ind++;
    }
}

int main()
{
    float integ = 0, h;
    Point inter, points[n];
    printf("Enter the interval values (a, b) : ");
    scanf("%lf %lf", &inter.x, &inter.y);
    
    get_points(points, inter, (inter.y-inter.x)/n);

    h = (points[1].x - points[0].x);

    for(int i=0;i<=n;i++)
    {
        if(i == 0 || i == n)
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