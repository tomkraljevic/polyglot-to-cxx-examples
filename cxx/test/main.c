#include "foolib/foolib_c.h"
#include <stdio.h>

int
main(int argc, char **argv) {
    foolib_result_t rv;
    foolib_object_t o = foolib_new();
    if (o == NULL) {
        printf("Handle object allocation error\n");
        return 1;
    }

    rv = foolib_operation(o);
    if (rv != FOOLIB_RESULT_SUCCESS) {
        printf("Handle operation error\n");
        return 1;
    }

    rv = foolib_delete(o);
    if (rv != FOOLIB_RESULT_SUCCESS) {
        printf("Handle object deletion error\n");
        return 1;
    }

    printf("Passed\n");
    return 0;
}
