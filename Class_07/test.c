#include <stdio.h>

int main()
{

  int i;
  char str [80];

  printf("Lūdzu ievadiet savu vārdu: ");
  scanf("%79s" ,str);
  printf("Lūdzu ievadiet savu vecumu: ");
  scanf("%d", &i);
  printf("Jūs esat %s un jums ir %d gadi \n", str, i);
  printf("Jūsu vecums hex sistēmā ir: %#x \n", i);

  return 0;

}


