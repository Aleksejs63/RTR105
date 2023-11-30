#include <stdio.h>

int main()
{

    char v;

    printf("Cien. lietotaj ievadiet pozītivu naturalu skaitli (līdz 255): ");
    scanf("%hhd", &v);

    printf("Jūsu skaitlis binārajā formā: ");

    printf("%hhd", (v >> 7) & 1);
    printf("%hhd", (v >> 6) & 1);
    printf("%hhd", (v >> 5) & 1);
    printf("%hhd", (v >> 4) & 1);
    printf("%hhd", (v >> 3) & 1);
    printf("%hhd", (v >> 2) & 1);
    printf("%hhd", (v >> 1) & 1);
    printf("%hhd", (v >> 0) & 1);

    printf("\n");
    return 0;
}
