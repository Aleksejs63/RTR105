#include <stdio.h>
#include <math.h>

float coskv(float x)
{
    return cos(sqrt(x));
}

int main()
{
    float a, b, integral1 = 0., integral2, eps, h;
   
    int n, k, m = 1;
    // int n = 2, k, m = 1; prev edition

    printf("Cien. lietotaj ludzu ievadiet a vertibu: ");
    scanf("%f", &a);

    printf("Cien. lietotaj ludzu ievadiet b vertibu: ");
    scanf("%f", &b);

    printf("Cien. lietotaj ludzu ievadiet precizitates vertibu: ");
    scanf("%f", &eps);

    printf("\n");


    ////////taisnsturu metode
    
    integral2 = (b - a) * ( coskv(a) + coskv(b) ) / 2.;   
    
    while (fabs(integral2 - integral1) > eps)
    {
        m *= 2;
        n = 2 * m;            
        h = (b - a) / n;  
        integral1 = integral2;
        integral2 = 0.;

        for (k = 0; k < n; k++)
        {
            integral2 += h * coskv(a + (k + 0.5) * h);
        }
        
    }

    printf("Integrala vertiba taisnsturu metodei: %.5f \n", integral2);


    ///////trapecu metode  
    
    integral2 = (b - a) * ( coskv(a) + coskv(b) ) / 2.;
    integral1 = 0.;
    
    while (fabs(integral2 - integral1) > eps)
    {
        m *= 2;
        n = 2 * m;            
        h = (b - a) / n;  
        integral1 = integral2;
        integral2 = 0.;

        for (k = 1; k < n; k++)
        {
            integral2 += (coskv(a + (k - 1) * h) + coskv(a + (k * h))) * (h / 2);
        }
        
    }
    
    printf("Integrala vertiba trapecu metodei: %.5f \n", integral2);


    //////simpsona metode

    integral2 = (b - a) * ( coskv(a) + coskv(b) ) / 2.;
   
    while (fabs(integral2 - integral1) > eps)
    {
        m *= 2;
        n = 2 * m;            
        h = (b - a) / n;   
        integral1 = integral2;
        integral2 = 0.;
        
        for (k = 1; k <= m-1; k++)
        
            integral2 = integral2 + (2.) * ( 2. * coskv(a + (2 * k - 1) * h) + coskv(a + 2 * k * h) );
            integral2 = integral2 + coskv(a) + coskv(b) + 4. * coskv(b-h);
            integral2 *= (h / 3.);  
           
           
    }
        
    printf("Integrala vertiba simpsona metodei: %.5f \n", integral2);
    
    return 0;
}

