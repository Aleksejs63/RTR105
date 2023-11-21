/* fclose example */
#include <stdio.h>
int main()
{
  FILE *pFile;
  pFile = fopen("fclose.txt", "wt");

  if (pFile != NULL)

  {
    fprintf(pFile, "Mans teksts\n");
    fclose(pFile);

    if (fclose != 0)
    {
      printf("Fails aizvērts veiksmīgi\n");
    } // aizdomīgi jo pie fclose veismīgas izpildes jāatgriež 0
    else
    {
      printf("Kļūda faila aiztaisīšanā\n");
    }
  }

  else
  {
    printf("Kļūda faila rakstīšanā!\n");
  }

  return 0;
}
