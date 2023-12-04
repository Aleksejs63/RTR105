#include <stdio.h>

int main()
{

  int sk1, sk2, sk3, seciba;

  printf("Izvelaties secibu. 1 - dilstosa, 2 - augosa: \n");
  scanf("%d", &seciba);

  if (seciba != 1 && seciba != 2)
  {
      printf("Ludzu ievadiet atbilstosu skaitli!");
      return 1;
  }



  printf("Cien. lietotaj ludzu ievadiet pirmo skaitli: ");
  scanf("%d", &sk1);
 
  printf("Cien. lietotaj ludzu ievadiet otro skaitli: ");
  scanf("%d", &sk2);

  printf("Cien. lietotaj ludzu ievadiet treso skaitli: ");
  scanf("%d", &sk3);

  
  if (seciba == 1)      ///dilstosa
  {
    
    if (sk1 > sk2)
    {
      if (sk1 > sk3)
      {
        if (sk2 > sk3)
        {
          printf("Jusu skaitli dilstosa seciba: %d %d %d \n", sk1, sk2, sk3);
        }
        else
        {
          printf("Jusu skaitli dilstosa seciba: %d %d %d \n", sk1, sk3, sk2);
        }
      }
 
    }

    else
    {
      if (sk2 > sk3)
      {
        if (sk1 > sk3)
        {
          printf("Jusu skaitli dilstosa seciba: %d %d %d \n", sk2, sk1, sk3);
        }
        else
        {
          printf("Jusu skaitli dilstosa seciba: %d %d %d \n", sk2, sk3, sk1);
        }
      }
    
    }

    if (sk3 > sk1)
    {
      if (sk3 > sk2)
      {
        if (sk2 > sk1)
        {
          printf("Jusu skaitli dilstosa seciba: %d %d %d \n", sk3, sk2, sk1);
        }
        else
        {
          printf("Jusu skaitli dilstosa seciba: %d %d %d \n", sk3, sk1, sk2);
        }
      }
    
    }


  }

  else if (seciba == 2) ///augosa
  {

    if (sk1 > sk2)
      {
        if (sk1 > sk3)
        {
          if (sk2 > sk3)
          {
            printf("Jusu skaitli augosa seciba: %d %d %d \n", sk3, sk2, sk1);
          }
          else
          {
            printf("Jusu skaitli augosa seciba: %d %d %d \n", sk2, sk3, sk1);
          }
        }
  
      }

    else
    {
      if (sk2 > sk3)
      {
        if (sk1 > sk3)
        {
          printf("Jusu skaitli augosa seciba: %d %d %d \n", sk3, sk1, sk2);
        }
        else
        {
          printf("Jusu skaitli augosa seciba: %d %d %d \n", sk1, sk3, sk2);
        }
      }
    
    }

    if (sk3 > sk1)
    {
      if (sk3 > sk2)
      {
        if (sk2 > sk1)
        {
          printf("Jusu skaitli augosa seciba: %d %d %d \n", sk1, sk2, sk3);
        }
        else
        {
          printf("Jusu skaitli augosa seciba: %d %d %d \n", sk2, sk1, sk3);
        }
      }
      
    }

  }
  
 

  return 0;
}