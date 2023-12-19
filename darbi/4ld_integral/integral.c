#include <stdio.h>
#include <math.h>

float coskv(float x)
{
    return cos(sqrt(x));
}




int main()
{
    float a, b, integral1 = 0., integral2, eps, h;
   
    int n = 2, k, m = 1;

    printf("Cien. lietotaj ludzu ievadiet a vertibu: ");
    scanf("%f", &a);

    printf("Cien. lietotaj ludzu ievadiet b vertibu: ");
    scanf("%f", &b);

    printf("Cien. lietotaj ludzu ievadiet precizitates vertibu: ");
    scanf("%f", &eps);

    // integral2 = (b - a) * (cos(sqrt(a)) + cos(sqrt(b))) / n;
    integral2 = (b - a) * ( coskv(a) + coskv(b) ) / n;   //vieglaks pierakts, tas pats rezultats
    
    while (fabs(integral2 - integral1) > eps)
    {
        n *= 2;
        h = (b - a) / n;

        integral1 = integral2;
        integral2 = 0.;

        for (k = 0; k < n; k++)
        {
            integral2 += h * coskv(a + (k + 0.5) * h);
        }
        
        // printf("Rectangle method integ1 = %.5f \t integ2 = %.5f \n", integral1, integral2);

    }

    printf("Integrala vertiba taisnsturu metodei: %.5f \n\n", integral2);



    ///////trapecu metode  
    
    n = 2;
    integral2 = (b - a) * ( coskv(a) + coskv(b) ) / n;
    integral1 = 0.;
    
    while (fabs(integral2 - integral1) > eps)
    {
        n *= 2;            // cik kopa bus attalumi h
        h = (b - a) / n;    // attalums starp trapeces malam
        
        integral1 = integral2;
        integral2 = 0.;

        for (k = 1; k < n; k++)
        {
            integral2 += (coskv(a + (k - 1) * h) + coskv(a + (k * h))) * (h / 2);
        }
        
        // printf("Trapezoidal method integ1 = %.5f \t integ2 = %.5f \n", integral1, integral2);
    }
    
    printf("Integrala vertiba trapecu metodei: %.5f \n\n", integral2);



    ///////Simpsona metode   NEIET
        
    // n = 2;
    // integral2 = (b - a) * ( coskv(a) + coskv(b) ) / n;
    // integral1 = 0.;
    // printf("Simpsona integralsis\n");

    
    
    // while (fabs(integral2 - integral1) > eps)
    // {
    //     n *= 2;            // cik kopa bus attalumi h
    //     h = (b - a) / n;    // attalums starp trapeces malam
    //     integral1 = integral2;
    //     integral2 = 0.;
        
    //     for (k = 0; k < n; k++)
    //     {

    //         integral2 += ((h) / 3.) * ( coskv(a + (k * h)) + ( (4.) * coskv(a + (k + 0.5) * h)) + coskv(a + ((k + 1) * h)) );

           
    //     }
        
    //     printf("Simpsons method integ1 = %.5f \t integ2 = %.5f \n", integral1, integral2);
    // }

    n = 0;
    

    integral2 = (b - a) * ( coskv(a) + coskv(b) ) / 2.;
    integral1 = 0.;
    printf("Simpsona integralsis\n");

    
    
    while (fabs(integral2 - integral1) > eps)
    {
        m *= 2;
        n = 2 * m;            // cik kopa bus attalumi h
        h = (b - a) / n;    // attalums starp trapeces malam
        integral1 = integral2;
        integral2 = 0.;
        
        for (k = 1; k <= m-1; k++)
        {

            integral2 += (2.) * ( (2.) * coskv(a + ((2 * k) - 1) * h) + coskv(a + (2 * k * h)) );

            integral2 += coskv(a) + ((4.) * coskv(b-h)) + coskv(b);

            integral2 *= (h / 3.);

           
        }
        
        printf("Simpsons method integ1 = %.5f \t integ2 = %.5f \n", integral1, integral2);
    }
    printf("Integrala vertiba simpsona metodei: %.5f \n", integral2);






    

    return 0;
}

