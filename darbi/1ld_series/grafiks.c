#include <stdio.h>
#include <math.h>





double my_cos(double x)
{

    double a, sum;
    int k = 0;
    
    a = pow(-1, k) * pow(x, k) / (1.);
    sum = a;
    //printf("%.2f \t %8.2f \t %8.2f \n", x, a, sum);
    // printf("a0 = %8.2f sum0 = %8.2f \n", a, sum);

    while (k < 500)
    {
        k++;
        a = a * (-1) * x /   ((2 * k) * (2 * k - 1));
        sum = sum + a;
        if (k == 499)
        {
            printf("a499 = %.2f sum499 = %.2f \n", a, sum);
        }
        if (k == 500)
        {
            printf("a500 = %.2f sum500 = %.2f \n", a, sum);
        }
        
    }

    return sum;
}

void main()
{
    double x, y, yy;
    printf("Kosinuss no kvadratsaknes no x aprekinasana\n");
    printf("Ievadiet argumentu x: ");
    scanf("%lf", &x);
    printf("\n");
    
    y = cos(sqrt(x));
    yy = my_cos(x);
    
    
    printf("\nStandarta cos(sqrt(x)):         y = cos(sqrt(%.2f))     = %.20f\n", x, y);

    
    printf("Izmantojot summas cos(sqrt(x)): y = my_cos(sqrt(%.2f))  = %.20f\n\n", x, yy);
    
    
    
    

    printf("                 500\n");
    printf("                ____\n");
    printf("                \\              k   k\n");
    printf("                 \\         (-1) * x\n");
    printf("cos(sqrt(%.2f)) = >    __________________\n", x);
    printf("                 /\n");
    printf("                /___         (2*k)!\n");
    printf("                 k=0\n");
    printf(" \n\n");

    printf("                           (-1) * x\n");
    printf(" rekurences reizinatajs: _______________\n\n");
    printf("                         (2*k) * (2*k-1)\n");

}


