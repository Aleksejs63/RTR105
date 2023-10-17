#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10


int main(void)
{
 int gadijuma_skaitlis, gadijuma_skaitlu_generatora_grauds;
  
 gadijuma_skaitlu_generatora_grauds = time(NULL);
 printf("Gadījuma skaitļu ģeneratora grauds - %d\n", gadijuma_skaitlu_generatora_grauds);

 srand(gadijuma_skaitlu_generatora_grauds);
 gadijuma_skaitlis = rand();
 printf("Gadījuma skaitlis - %d\n", gadijuma_skaitlis);

 // False - ir tikai skaitliskā nulle
 // True - ir visi pārējie (ja kaut vienā bitā ir 1)

 if(gadijuma_skaitlis % 10 == 0) //101 % 10 -> 1 ... 1 == 0 -> 0 
 				 //100 % 10 -> 0 ... 0 == 0 -> 1
 {
 printf("Šis skaitlis dalās ar 10 bez atlikuma.\n");
 } 
 
 if(gadijuma_skaitlis % 10) //tiek parbaudits vai sis skaitlis dalas ar 10 bez atlikuma
			    //101 % 10 -> 1
			    //100 % 10 -> 0 funkcija tiek izlaista
 {
 printf("Šis skaitlis nedalās ar 10 bez atlikuma.\n");
 }
 
 else
 {
 printf("Šis skaitllis dalās ar 10 bez atlikuma\n");
 }




 return 0;
}
