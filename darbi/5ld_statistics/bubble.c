#include <stdio.h>
#include <string.h>


int main()
{

 

    int len = 256;
    unsigned char teksts[len];
    
    printf("Cien. lietotaj ludzu ievadiet tekstu (izmantojot tikai anglu alfabeta burtus): ");
    fgets(teksts, len, stdin);

    int spacecount = 0;
    
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

    ////////////////////moda

    unsigned char chars[len];
    unsigned char freq[len];
    int max_moda = 0;
    int modu_count = 1;
    a = 0;
    chars[a] = fixtext[1];
    freq[a] = 0;
    ///////katru individualu burtu pievieno sarakstaa
    for (int i = 2; i < strlen(fixtext); i++)
    {
        if (fixtext[i] != chars[a])
        {
            
            a++;
            chars[a] = fixtext[i];
            freq[a] = 0;
        }
        

    }
    
    ///////biezuma saraksta piepilisana
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
    
    ////////modas meklesana biezuma masiivaa

   

    unsigned char moda_index[strlen(fixtext)];

    for (int j = 0; j < a+1; j++)
    {
        if (freq[j] > max_moda)
        {
            max_moda = freq[j];     
            moda_index[0] = j;
        }
        
    }

    for (int i = 0; i < a+1; i++)
    {
        if (freq[i] == max_moda && moda_index[0] != i)
        {
            moda_index[modu_count] = i;
            modu_count++;
        }
        
    }


    if (modu_count == 1)
    {
        printf("Moda ir: %c , %d (%d reizes) \n", chars[moda_index[0]], chars[moda_index[0]],  max_moda);
    }
    else
    {
        for (int i = 0; i < modu_count; i++)
        {
            printf("Modas ir: %c , %d (%d reizes); \n", chars[moda_index[i]], chars[moda_index[i]],  max_moda);
        }
    }
    
    printf("Modu skaits: %d", modu_count);
    
    ////////izvade gnuplot

    FILE * pFile;
    
    pFile = fopen ("sort.dat", "w");
    fprintf(pFile, "burts\tfrekvence\n");

    for (int j = 0; j < a+1; j++)
    {
        fprintf(pFile, "%c\t\t\t%d\n", chars[j], freq[j]);
    }


    fclose (pFile);




    return 0;


}

