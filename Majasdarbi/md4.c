#include<stdio.h>

int main()
{
    int i;
    long long int faktorials;
    printf("Izvelaties datu tipu: \n char - 1, int - 2, long long - 3\n");

    scanf("%d", &i);

    switch (i)
    {
        case 1:     //char
        
            char skaitlis1;
        
            printf("ievadiet jusu skaitli: \n");
            scanf("%d", &skaitlis1);
                            
            faktorials = skaitlis1;
            
            while (skaitlis1!=2)
            {
                skaitlis1--;
                faktorials *= skaitlis1;
                
            }
            if (faktorials>0)
            {printf("Jusu skaitla faktorials ir: %d \n", faktorials);}
            else 
            {printf("you stupid \n");}
            
            
            
        
        
            break;

        case 2:     //int
        
            int skaitlis2;

            printf("ievadiet jusu skaitli: \n");
            scanf("%d", &skaitlis2);

            faktorials = skaitlis2;
            while (skaitlis2!=2)
            {
                skaitlis2--;
                faktorials *= skaitlis2;
                    
            }
            if (faktorials>0)
            {printf("Jusu skaitla faktorials ir: %d \n", faktorials);}
            else 
            {printf("you stupid \n");}

            break;

        case 3:     //long long
        
            long long int skaitlis3;
            printf("ievadiet jusu skaitli: \n");
            scanf("%lld", &skaitlis3);
            
        
            faktorials = skaitlis3;
            while (skaitlis3!=2 && faktorials>0)
            {
                skaitlis3--;
                faktorials *= skaitlis3;
                
                
            }
            if (faktorials>0)
            {printf("Jusu skaitla faktorials ir: %lld \n", faktorials);}
            else 
            {printf("you stupid \n");}

            break;

        default:
        printf("Ludzu ievadiet pareizu vertibu!");
    }

    return 0;
}

