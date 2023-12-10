#undef __STRICT_ANSI__
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{

    FILE * pFile;
    float a, b, delta_x;
    int k;

    printf("Cien. lietotaj ievadiet ludzu a vertibu: ");
    scanf("%f", &a);

    printf("Ievadiet b vertibu: ");
    scanf("%f", &b);

    printf("Ievadiet precizitati (delta_x): ");
    scanf("%f", &delta_x);

    pFile = fopen ("derivative.dat", "w");
    fprintf(pFile, "x       cos(sqrt(x))    analytical'  forward difference' analytical''  forward difference'' \n");


    int i = ((b-a) / delta_x);
   
    
    
    float * x;
    x = (float*) malloc ((i * sizeof(float)) + 1); 
    if (x==NULL) exit (1);

    float * func;
    func = (float*) malloc ((i * sizeof(float)) + 1); 
    if (func==NULL) exit (1);

    float * der1;
    der1 = (float*) malloc ((i * sizeof(float)) + 1); 
    if (der1==NULL) exit (1);

    float * der2;
    der2 = (float*) malloc ((i * sizeof(float)) + 1); 
    if (der2==NULL) exit (1);

    float * der_analytical1;
    der_analytical1 = (float*) malloc ((i * sizeof(float)) + 1); 
    if (der_analytical1==NULL) exit (1);

    float * der_analytical2;
    der_analytical2 = (float*) malloc ((i * sizeof(float)) + 1); 
    if (der_analytical2==NULL) exit (1);


   
    ///////////////// x masivs
    x[0] = a;
    for (k = 1; k < i+1; k++)
    {
        x[k] =  x[k-1] + delta_x;

    }

    ///////////////// funkciju masivs
    for (k = 0; k < i+1; k++)
    {
    
        func[k] =  cos(sqrt(x[k]));


    }

    /////////////////// forward difference' masivs
    for (k = 0; k < i+1; k++)
    {
        der1[k] = (func[k+1] - func[k]) / delta_x;
        if (k == i) {der1[i] = 0;}
    }

    //////////////////// forward difference'' masivs
    for (k = 0; k < i+1; k++)
    {
        der2[k] = (der1[k+1] - der1[k]) / delta_x;
        if (k == i) {der2[i] = 0;}
        if (k == i-1) {der2[i-1] = 0;}
    }

    //////////////////// analytical' masivs
    for (k = 0; k < i+1; k++)
    {

        der_analytical1[k] = ( (-1) * sin(sqrt(x[k])) ) / ( 2 * sqrt(x[k]) );

    }

    //////////////////// analytical'' masivs
    for (k = 0; k < i+1; k++)
    {

        der_analytical2[k] = ( sin(sqrt(x[k])) - sqrt(x[k]) * cos(sqrt(x[k])) ) / ( 4 * x[k] * sqrt(x[k]) );

    }



    for (k = 0; k < i+1; k++)
    {

        fprintf(pFile, "%.1f\t\t%10.5f\t\t%10.5f\t\t%10.5f\t\t%10.5f\t\t%10.5f\n", x[k], func[k], der_analytical1[k], der1[k], der_analytical2[k], der2[k]);

    }
    
   
    free (x);
    free (func);
    free (der1);
    free (der2);
    free (der_analytical1);
    free (der_analytical2);

    fclose (pFile);
    

    return 0;
}

