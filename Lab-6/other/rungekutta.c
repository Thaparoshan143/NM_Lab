#include <stdio.h>
#include <math.h>

#define f(x, y) (x + pow(y, 2))

typedef struct Point
{
    float x, y;
}Point;

int main() 
{
   int n;
   Point inter, point;
   float xn, h, k, k1, k2, k3, k4;
   printf("Enter the value of (x0, y0) : ");
   scanf("%f%f", &inter.x, &inter.y);
   printf("Enter the value of xn: ");
   scanf("%f", &xn);
   printf("Enter the value of each step size (h) : ");
   scanf("%f", &h);
   
   point.y = inter.y;
   point.x = inter.x;

   printf("\nRange Kutta method of fourth order:\n");
   while (point.x != xn) {
      k1 = h * (f(point.x, point.y));
      k2 = h * (f(point.x + h / 2, point.y + k1 / 2));
      k3 = h * (f(point.x + h / 2, point.y + k2 / 2));
      k4 = h * (f(point.x + h, point.y + k3));
      k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
      point.y += k;
      point.x += h;

      printf("\ny(%f) = %f", point.x, point.y);
   }

   printf("\n\nThe approximate solution of the differential equation is: y(%.4f) = %f", point.x, point.y);
   return 0;
}
