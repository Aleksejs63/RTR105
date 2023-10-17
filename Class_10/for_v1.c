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





 for(i++, gadijuma_skaitlis = rand(); gadijuma_skaitlis % 10; gadijuma_skaitlis = rand(), i++)
)
{
 printf("%d. skaitlis\n", i);
 printf("Gadījuma skaitlis - %d\n", gadijuma_skaitlis);
 printf("Šis skaitlis nedalās ar 10 bez atlikuma.\n"); 
}

 printf("Ģenerēšanas beigas\n");
 printf("Beidzot skaitlis %d.  iterācijā %d dalās ar 10 bez atlikuma.\n", i, gadijuma_skaitlis);



 return 0;
}
