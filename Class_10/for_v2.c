#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10


int main(void)
{
 int i = 0;
 int gadijuma_skaitlis, gadijuma_skaitlu_generatora_grauds;

 gadijuma_skaitlu_generatora_grauds = time(NULL);
 printf("Gadījuma skaitļu ģeneratora grauds - %d\n", gadijuma_skaitlu_generatora_grauds);
 srand(gadijuma_skaitlu_generatora_grauds);


 i = i + 1; //darbības (operācijas) netiek pildītas vienlaicīgi
            //šeit ir divas operācijas( saskaitīšana + un piešķiršana =)
            //saskaitīšanai ir prioritāte - tā tiks izpildīta pirmā
	    //i++; inkrements (skaitļa pieaugums par vienu vienību)
	    //++i;
	    //i += 1;


 gadijuma_skaitlis = rand();


 for(;gadijuma_skaitlis % 10;)
{
 printf("%d. skaitlis\n", i);
 printf("Gadījuma skaitlis - %d\n", gadijuma_skaitlis);
 printf("Šis skaitlis nedalās ar 10 bez atlikuma.\n");

 gadijuma_skaitlis = rand(); //bez sis rindinas dabusim bezgaligu ciklu
 i++;
}

 printf("Ģenerēšanas beigas\n");
 printf("Beidzot skaitlis %d.  iterācijā %d dalās ar 10 bez atlikuma.\n", i, gadijuma_skaitlis);



 return 0;
}
