#include "foolib/foolib_c.h"
#include <stdio.h>

int
main(int argc, char **argv) {
    foolib_result_t rv;
    foolib_object_t o;

    rv = foolib_g_init();
    if (rv != FOOLIB_RESULT_SUCCESS) {
        printf("Init error\n");
        return 1;
    }

    o = foolib_new();
    if (o == FOOLIB_OBJECT_ALLOC_FAILED) {
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

    rv = foolib_g_destroy();
    if (rv != FOOLIB_RESULT_SUCCESS) {
        printf("Destroy error\n");
        return 1;
    }

    printf("Passed\n");
    return 0;
}
