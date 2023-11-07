#include <stdio.h>
#include <math.h>
double my_cos(double x)
{

 double a, sum;
 int k = 0;


 a = pow(-1, k) * pow(x, k) / (1.);
 sum = a;
 printf("%.2f \t %8.2f \t %8.2f \n", x, a, sum);

 while(k < 50)
 {
  k++;
  a = a * (-1) * x / ((2*k)*(2*k-1));
  sum = sum + a;
  printf("%.2f \t %8.2f \t %8.2f \n", x, a, sum);
 }

 return sum;
}
void main()
{
 double x = 2.05, y, yy;
 y = cos(sqrt(x));
 yy = my_cos(x);

 printf("std cos - y = cos(sqrt(%.2f))\t = %.20f\n", x, y);
 printf("usr cos - y = my_cos(sqrt(%.2f))\t = %.20f\n", x, yy);



}


