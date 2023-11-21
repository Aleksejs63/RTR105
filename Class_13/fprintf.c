/* fprintf example */
#include <stdio.h>
#include <string.h>

int main()
{
   FILE *pFile;
   int n;
   char name[100];

   pFile = fopen("fprintf.txt", "w");

   // uzdevums pēc lietotāja izvēles atvērt failu papildināšanai vai pārrakstīšanai

   if (pFile != NULL)
   {
      for (n = 0; n < 3; n++)
      {
         puts("Lūdzu ievadiet vārdu: ");
         // gets (name);

         fgets(name, 20, stdin);
         name[strcspn(name, "\n")] = 0;

         fprintf(pFile, "Name %d [%-10.10s]\n", n + 1, name);
      }
      fclose(pFile);
   }

   else
   {
      printf("Kļūda faila attaisīšanā!\n");
   }
   return 0;
}
