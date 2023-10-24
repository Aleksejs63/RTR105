#include "foo.h"
#include <stdio.h>
//https://riptutorial.com/c/example/3250/calling-a-function-from-another-c-file



int main(void)
{
    int id_main = 42;
    printf("id_main vērtība pirms foo funkcijas izpildes: %d\n", id_main);

    char *name_main = "mans teksts";
    printf("name_main atrašanas vieta atmiņā (izdruka no main): %p\n", name_main);
    printf("name_main vērtība pirms foo funkcijas izpildes: %s\n\n", name_main);


    //foo(&id_main, name_main);
    foo(id_main, name_main);
    printf("\nid_main vērtība pēc foo funkcijas izpildes: %d\n", id_main);
    printf("name_main vērtība pēc foo funkcijas izpildes: %s\n", name_main);



    foo(42, "bar");
    return 0;
}
