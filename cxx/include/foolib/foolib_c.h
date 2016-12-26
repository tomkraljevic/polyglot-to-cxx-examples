#ifndef FOOLIB_C_H
#define FOOLIB_C_H 1

#ifdef __cplusplus
extern "C" {
#endif

typedef int foolib_result_t;
#define FOOLIB_RESULT_SUCCESS 0
#define FOOLIB_RESULT_ERROR 1

typedef void* foolib_object_t;

foolib_object_t foolib_new();

foolib_result_t foolib_delete(foolib_object_t object);

foolib_result_t foolib_operation(foolib_object_t object);

#ifdef __cplusplus
}
#endif

#endif
