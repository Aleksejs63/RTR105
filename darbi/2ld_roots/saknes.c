#include <stdio.h>
#include <math.h>

float modified_func(float x, float c)
{
    return cos(sqrt(x)) - c;
}

int main()
{

    float a, b, c, x, delta_x, func_a, func_b;
    int k = 0;

    

    printf("Cien. lietotaj ievadiet ludzu a vertibu: ");
    scanf("%f", &a);

    printf("Cien. lietotaj ievadiet ludzu b vertibu: ");
    scanf("%f", &b);

    printf("Cien. lietotaj ievadiet ludzu c vertibu: ");
    scanf("%f", &c);

    printf("Cien. lietotaj ievadiet ludzu delta_x vertibu: ");
    scanf("%f", &delta_x);

    func_a = cos(sqrt(a));
    func_b = cos(sqrt(b));
 
    if (func_a * func_b > 0)
    {
        printf("Intervala [%.2f;%.2f] funkcijai cos(sqrt(x)) ", a, b);
        printf("saknu nav vai taja ir para saknu skaits\n");
        return 1;
    }
    
    printf("cos(sqrt(%.3f)) = %.3f\t", a, func_a);
    printf("cos(sqrt(%.3f)) = %.3f\n\n", b, func_b);

    while ((b-a) > delta_x)
    {
        k++;
        x = (a+b) / 2;

        if (func_a * modified_func(x, c) > 0)
        {
            a = x;
        }
        else
        {
            b = x;
        }

        printf("%2d. iteracija: cos(sqrt(%.3f)) = %.3f\t", k, a, cos(sqrt(a)));
        printf("cos(sqrt(%.3f)) = %.3f\t", x, modified_func(x, c));
        printf("cos(sqrt(%.3f)) = %.3f\n", b, cos(sqrt(b)));

    }
    
    printf("\nSakne atrodas pie x = %.3f , jo cos(sqrt(x)) ir %.3f\n", x, modified_func(x, c));

    return 0;
}
