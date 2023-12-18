#include <stdio.h>
#include <math.h>






int main()
{
    float a, b, integral1 = 0., integral2, eps, h;
   
    int n = 2, k;

    printf("Cien. lietotaj ludzu ievadiet a vertibu: ");
    scanf("%f", &a);

    printf("Cien. lietotaj ludzu ievadiet b vertibu: ");
    scanf("%f", &b);

    printf("Cien. lietotaj ludzu ievadiet precizitates vertibu: ");
    scanf("%f", &eps);

    // integral2 = (b - a) * (cos(sqrt(a)) + cos(sqrt(b))) / n;
    integral2 = (b - a) * cos(sqrt((a + b) / n));   //vieglaks pierakts, tas pats rezultats
    
    while (fabs(integral2 - integral1) > eps)
    {
        n *= 2;
        h = (b - a) / n;

        integral1 = integral2;
        integral2 = 0.;

        for (k = 0; k < n; k++)
        {
            integral2 += h * cos(sqrt(a + (k + 0.5) * h));
        }
        
        printf("Rectangle method integ1 = %.5f \t integ2 = %.5f \n", integral1, integral2);

    }

    printf("Integrala vertiba taisnsturu metodei: %.5f \n\n", integral2);
    ///////trapecu metode  KAPEC LENAKA ??
    
    n = 2;
    integral2 = (b - a) * ( cos(sqrt(a)) + cos(sqrt(b)) ) / n;
    integral1 = 0.;
    
    while (fabs(integral2 - integral1) > eps)
    {
        n *= 2;            // cik kopa bus attalumi h
        h = (b - a) / n;    // attalums starp trapeces malam
        
        integral1 = integral2;
        integral2 = 0.;

        for (k = 1; k < n; k++)
        {
            integral2 += (cos(sqrt(a + (k - 1) * h)) + cos(sqrt(a + (k * h)))) * (h / 2);
        }
        
        printf("Trapezoidal method integ1 = %.5f \t integ2 = %.5f \n", integral1, integral2);
    }
    printf("Integrala vertiba trapecu metodei: %.5f \n\n", integral2);

    ///////Simpsona metode  
        
    n = 2;
    integral2 = (b - a) * ( cos(sqrt(a)) + 4 *cos(sqrt( (a + b) / n)) + cos(sqrt(b)) ) / (n * 3);
    integral1 = 0.;
    
    
    while (fabs(integral2 - integral1) > eps)
    {
        n *= 2;            // cik kopa bus attalumi h
        h = (b - a) / n;    // attalums starp trapeces malam
        
        integral1 = integral2;
        integral2 = 0.;

        for (k = 1; k < n; k++)
        {
            integral2 += (h / 3.0) * ( cos(sqrt(a + (k - 1) * h)) + 4 * cos(sqrt(  a + ( ((k - 1) + 0.5) * h )))  + cos(sqrt(a + (k * h))) ) ;
        }
        
        printf("Simpsons method integ1 = %.5f \t integ2 = %.5f \n", integral1, integral2);
    }
    printf("Integrala vertiba simpsona metodei: %.5f \n", integral2);






    

    return 0;
}

