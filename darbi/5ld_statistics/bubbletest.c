#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
 

    int len = 256;
    int offset = 0;
    unsigned char teksts[len];

    printf("Ievadiet tekstu: ");
    fgets(teksts, len, stdin);

    int skaits = strlen(teksts) - 1;
   
    


    for (int i = 0; i < skaits; i++) //skaits 7 
    {
        if (teksts[i] == 32)        //kad i = 2 ieiet
        {
            int a = i;
            teksts[a] = teksts[a + 1];  // aizvieto space ar next char
            while (a < skaits)     // now gonna go from 2 to 6 (last char)
            {
                        
                teksts[a+1] = teksts[a+2];
                a++;
            }
            
        }
        
    }

  
    printf("Jusu tekts ->  ");
    puts(teksts);
}