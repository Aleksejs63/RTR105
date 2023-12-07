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
    fprintf(pFile, "\tx          cos(sqrt(x))  cos'(sqrt(x)) cos''(sqrt(x)) \n");


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
    /////////////////// atvasinajums1 masivs
    for (k = 0; k < i+1; k++)
    {
        der1[k] = (func[k+1] - func[k]) / delta_x;
        if (k == i) {der1[i] = 0;}
    }
    //////////////////// atvadinajums2 masivs
    for (k = 0; k < i+1; k++)
    {
        der2[k] = (der1[k+1] - der1[k]) / delta_x;
        if (k == i) {der2[i] = 0;}
        if (k == i-1) {der2[i-1] = 0;}
    }

        
    for (int valdis = 0; valdis < i + 1; valdis++)
    {
         fprintf(pFile, "%13.4f\t%10.3e\t%10.3e\t%10.4f\n", x[valdis], func[valdis], der1[valdis], der2[valdis]);       ///// funkciai jabut masiva!!
    }
    
   








/////////// izpetit malloc//////////////

    free (x);
    free (func);
    free (der1);
    free (der2);

    fclose (pFile);
    

    return 0;
}

