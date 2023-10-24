#include "foo_v2.h"
#include <stdio.h>
#include <string.h>


void foo(int *id, char *name)
{
    fprintf(stdout,"id atrašanās vieta atmiņā: %p\n", id);
    fprintf(stdout,"id vērtība: %d\n", *id);

    fprintf(stdout,"name atrašanās vieta atmiņā: %p\n", name);
    fprintf(stdout,"name vērtība: %s\n", name);



    fprintf(stderr, "foo(%d, \"%s\");\n", *id, name);

    *id = 50;
}
