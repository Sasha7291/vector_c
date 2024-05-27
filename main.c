#define INT_VECTOR
#include "vector.h"
#define FLOAT_VECTOR
#include "vector.h"
#define LONG_LONG_INT_VECTOR
#include "vector.h"

int main()
{
    vector_longlong *vec_longlong = init_vector_longlong(5, -12412342141341234);
    vector_int *vec_int = init_vector_int(5, 1);
    vector_float *vec_float = init_vector_float(5, 2.6);

    vec_longlong->print((const vector_longlong *const *const)&vec_longlong);
    vec_int->print((const vector_int *const *const)&vec_int);
    vec_float->print((const vector_float *const *const)&vec_float);

    vec_float->insert((vector_float *const *const)&vec_float, 4, 3.2);

    printf("%d\n", vec_float->find_first_of((const vector_float *const *const)&vec_float, 3.2));

    destruct_vector_longlong(&vec_longlong);
    destruct_vector_int(&vec_int);
    destruct_vector_float(&vec_float);

    return 0;
}
