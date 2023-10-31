/* fscanf example */
#include <stdio.h>

int main ()
{
  char str [80];
  float f;
  FILE * pFile;

  pFile = fopen ("myfile.txt","w+");

  // uzdevums* - nolasīt datus no faila ar jauktiem (teksts un skaitļi) datiem

  fprintf (pFile, "%f %s", 3.1416, "PI");
  printf("ftell result before rewind: %ld\n", ftell(pFile));

  rewind (pFile);
  printf("ftell result after rewind: %ld\n", ftell(pFile));


  fscanf (pFile, "%f", &f);
  fscanf (pFile, "%s", str);
  fclose (pFile);
  printf ("I have read: %f and %s \n",f,str);
  return 0;
}
