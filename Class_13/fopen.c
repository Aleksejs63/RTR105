#include <stdio.h>

int main()
{
    FILE *pFile;

    pFile = fopen("fails.txt", "w"); // izveido failu rakstīšanai
    if (pFile != NULL)               // pārbauda vai attaisīšana izdevās
    {
        fputs("Ieraksts izdevās\n", pFile); // ievieto tekstu failā
        fclose(pFile);                      // aiztaisa failu
    }
    return 0;
}
