#undef __STRICT_ANSI__
#include <stdio.h>
#include <math.h>

void main()
{

    FILE * pFile;
    float a, b, delta_x;
    
    

    printf("Cien. lietotaj ievadiet ludzu a vertibu: ");
    scanf("%f", &a);

    printf("Ievadiet b vertibu: ");
    scanf("%f", &b);

    printf("Ievadiet precizitati (delta_x): ");
    scanf("%f", &delta_x);

    pFile = fopen ("derivative.dat", "w");
    fprintf(pFile, "\tx \n");

    int i = ((b-a) / delta_x);
   
    
    // float * x;
    // x = (float*) malloc (i * sizeof(float)); // i * elementuskaits  japieskaita vieninieks//
    // float * der
//     float der1[i];
//     float der2[i];
    float x[i];
    x[0] = a;
  
        // while(x<b)
        // {

        //     fprintf(pFile, "%10.2f\t%10.2f\t%10.2f\n", x, cos(sqrt(x)), (cos(sqrt(x+delta_x))-cos(sqrt(x)))/delta_x);
               
        //     x += delta_x;  

        // }



   
    for (int k = 1; k < i+1; k++)
    {
        
        
        x[k] =  x[k-1] + delta_x;  
        
        
        
    }
        
    for (int valdis = 0; valdis < i + 1; valdis++)
    {
         fprintf(pFile, "%10.2f\t%10.2f\n", x[valdis], cos(sqrt(x[valdis])));       ///// funkciai jabut masiva!!
    }
    
   








/////////// izpetit malloc//////////////


    fclose (pFile);
    


}

