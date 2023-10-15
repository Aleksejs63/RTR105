#include <stdio.h>


int main()
{

    char v, i;

    printf("Ievadiet skaitli no 0 lidz 9 : ");
    scanf("%c", &v);

    for(i = 7; i >= 0; i--)     //parbida lietotaja ievaditas char binaro vertibu 7 bitus pa labi (sakuma tiek salidzinats skaitla MSB)
    {
    printf("%d", (v >> i) & 1); // tiek izprintets char vertibas salidzinajums ar 1
                                // ja char bita vertiba ir 1 tad tiek izprintets 1 ja ir 0 tad printe 0
                                // atkarto lidz tiek salidzinatas visas char vertibas     

    }


    return 0;
}

