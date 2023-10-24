#include <stdio.h>


int main()
{

    char v, i;

    printf("Ievadiet skaitli no 0 lidz 9 : ");
    scanf("%s", &v);

    for(i = 3; i >= 0; i--)
    {
    	printf("%d", (v >> i) & 1);

    }

    printf("\n");
    return 0;
}

