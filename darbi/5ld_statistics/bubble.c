#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h> 

int main()
{
    //min max tikai burtiem saskana ar ascii (punktus atstarpes nenemam)
    //liec lietotajam lietot anglu burtus
    //burti var but gan lielie gan mazie
    //vid ir visu ascii summa un jadala ar skaitu (jaizmanto pareizo datu tipu, jo var but dalskaitlis, janoapalo un char uj jaizvelas kurs simbols atbilst?)
    //mediana - indekss videjais 
    //modas meklesana - paradas vairak par vienu reizi, visbiezakais paradisanas skaits, modas var but vairakas.
    //alternativs modas meklesanas panemiens. pirmais elements, ejam gat rindu un skaitam cik reizes tas paradas. Dara ar katru simbolu un iestata par modu to kas uzvareeja
    //sakartotais secibai, sak ar pirmo elementu, iegaume poziciju skaitu. Cik reizes(pozicijas) nemainijas un iestata ka modu




    //noformesana

    // a b c
    //97 98 99
    //5  2  1  -ciik reizes paradas
    //  med  max  -kas tā par vērtību, ja tā ir kautkāda

    // gnuplotaa histogramma    

    int len = 256;
    unsigned char teksts[len];
    
    printf("Ievadiet tekstu: ");
    fgets(teksts, len, stdin);

    
   
    int spacecount = 0;
    
    ////spacecheck WIP
  
    // for (int i = 0; i < skaits; i++) 
    // {
       
        
        
        
    //     if (teksts[i] == 32)        
    //     {
    //         int a = i;
    //         teksts[a] = teksts[a + 1];  
    //         while (a < skaits)    
    //         {
                        
    //             teksts[a+1] = teksts[a+2];
    //             a++;
    //         }
            
    //     }
        
        // if (teksts[i + 1] == 32)        
        // {
        //     int a = i + 1;
        //     teksts[a + 1] = teksts[a + 2];  
        //     while (a < skaits)    
        //     {
                        
        //         teksts[a+2] = teksts[a+3];
        //         a++;
        //     }
            
        // }
        
    
    
 
   

   
    /// allowed char check

    for (int i = 0; i < strlen(teksts) - 1; i++)
    
    {

        if (teksts[i] != 32)
        {
            if (teksts[i] < 65 || teksts[i] > 122)
            {
                printf("Ievadei der tikai anglu burti.");
                return 1;
            }

            else if (teksts[i] < 97 && teksts[i] > 90)
            {
                printf("Ievadei der tikai anglu burti.");
                return 1;
            }
        }

        else
        {
            spacecount++;
        }
        

    }

    ///////////Sorting
   
    unsigned char bigger = 0;
   

    for (int i = 0; i < strlen(teksts); i++)
    {
        for (int j = 0; j < strlen(teksts)- 1 - i; j++)
        {
            if (teksts[j] > teksts[j+1])
            {
                bigger = teksts[j];
                teksts[j] = teksts[j+1];
                teksts[j+1] = bigger;
            }
            
            
        }
    }
    
        
    

    printf("Sakartots teksts ar atstarpem: %s \n", teksts);

    ///////Atstarpju dzesana
   
    unsigned char fixtext[strlen(teksts) - spacecount];
    int a = 0;

    for (int i = 0; i < strlen(teksts) ; i++)
    {
        
        if (teksts[i] != 32)
        {
           
            fixtext[a] = teksts[i];
            a++;
            
        }
        fixtext[a+1] = '\0';
    }
    

    
    printf("Sakartots teksts: %s \n", fixtext);

    ////////min

    int min = fixtext[1];
    int max = fixtext[strlen(fixtext) - 1];
    printf("Minimala vertiba: %c \n", min);

    ////////max

    printf("Maksimala vertiba: %c \n", max);

    ///////vid

    int sum = 0;
    for (int i = 1; i < strlen(fixtext); i++)
    {
        sum += fixtext[i];
    }
    
    int vid = sum / (strlen(fixtext)-1);
    printf("Videja vertiba: %c (%d) \n", vid, vid);

    ///////med

    int amount = strlen(fixtext) - 1;

    int med = (amount/2) + 1;

    if (amount % 2 != 0)    //////nepara
    {
        printf("Nepara mediana: %c \n", fixtext[med]);
    }
    else                    /////para
    {
        printf("Para mediana: %c un %c \n", fixtext[med-1], fixtext[med]);
    }

    ///////moda
    unsigned char chars[len];
    unsigned char freq[len];
    int max_moda = 0;
    a = 0;
    chars[a] = fixtext[1];
    
    
    for (int i = 2; i < strlen(fixtext); i++)
    {
        if (fixtext[i] != chars[a])
        {
            
            a++;
            chars[a] = fixtext[i];
            freq[a] = 0;
        }
        

    }
    
  
    for (int j = 0; j < a+1; j++)
    {
        for (int i = 0; i < strlen(fixtext); i++)
        {
            if (chars[j] == fixtext[i])
            {
                freq[j]++;
            }
            
        }
       
       
    
    }
    
    
    max_moda = freq[0];
    int moda_index = 0;
    for (int j = 1; j < a+1; j++)
    {
        if (freq[j] > max_moda)
        {
            max_moda = freq[j];
            moda_index = j;
        }
        
    }
    
    printf("Moda ir: %c (%d reizes)", chars[moda_index], max_moda);

    return 0;


}

