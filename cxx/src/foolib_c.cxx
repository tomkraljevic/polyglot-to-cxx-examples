#include "foolib/foolib.h"
#include "foolib/foolib_c.h"
#include <cassert>
#include <cstdio>
#include <map>

int foolib_g_verbosity = 0;

typedef std::map<foolib_object_t, foolib::Animal*> FoolibGlobalMap;
FoolibGlobalMap *foolib_g_map = NULL;
volatile foolib_object_t foolib_g_next_idx = 5000;

foolib_result_t foolib_g_init() {
    // TODO:  make this atomic if needed.  Not needed for python because of GIL.

    if (foolib_g_map != NULL) {
        return FOOLIB_RESULT_ERROR_BAD_STATE;
    }

    foolib_g_map = new FoolibGlobalMap;
    if (foolib_g_map == NULL) {
        return FOOLIB_RESULT_ERROR_ALLOC_FAILED;
    }

    return FOOLIB_RESULT_SUCCESS;
}

foolib_result_t foolib_g_destroy() {
    // TODO:  make this atomic if needed.  Not needed for python because of GIL.

    if (foolib_g_map != NULL) {
        delete foolib_g_map;
    }

    return FOOLIB_RESULT_SUCCESS;
}

foolib_object_t foolib_new()
{
    // TODO:  make this atomic if needed.  Not needed for python because of GIL.

    foolib::Animal *a = new foolib::Dog();
    if (a == NULL) {
        return FOOLIB_OBJECT_ALLOC_FAILED;
    }

    foolib_object_t object;
    {
        object = foolib_g_next_idx;
        foolib_g_next_idx++;
        (*foolib_g_map)[object] = a;
    }

    if (foolib_g_verbosity > 0) {
        printf("%d = foolib_new\n", object);
    }

    return object;
}

foolib_result_t foolib_delete(foolib_object_t object)
{
    // TODO:  make this atomic if needed.  Not needed for python because of GIL.

    foolib_result_t rv;
    FoolibGlobalMap::iterator it;
    it = foolib_g_map->find(object);
    if (it == foolib_g_map->end()) {
        rv = FOOLIB_RESULT_ERROR_NOT_FOUND;
        if (foolib_g_verbosity > 0) {
            printf("%d = foolib_delete(%d)\n", rv, object);
        }
        goto done;
    }

    {
        foolib::Animal *a = (*foolib_g_map)[object];
        foolib_g_map->erase(it);
        delete a;
        rv = FOOLIB_RESULT_SUCCESS;
    }

done:
    if (foolib_g_verbosity > 0) {
        printf("%d = foolib_delete(%d)\n", rv, object);
    }

    return rv;
}

foolib_result_t foolib_operation(foolib_object_t object)
{
    // TODO:  make this atomic if needed.  Not needed for python because of GIL.

    foolib_result_t rv;
    FoolibGlobalMap::iterator it;
    it = foolib_g_map->find(object);
    if (it == foolib_g_map->end()) {
        rv = FOOLIB_RESULT_ERROR_NOT_FOUND;
        goto done;
    }

    {
        foolib::Animal *a = (*foolib_g_map)[object];
        a->operation();
        rv = FOOLIB_RESULT_SUCCESS;
    }

done:
    if (foolib_g_verbosity > 0) {
        printf("%d = foolib_operation(%d)\n", rv, object);
    }

    return rv;
}
