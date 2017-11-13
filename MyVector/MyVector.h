#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

#include <stdlib.h>
#include <string.h>

#define state_using_vector(T)                                               \
struct _vector_##T                                                          \
{                                                                           \
  T *elem;                                                                  \
  int size;                                                                 \
  int capacity;                                                             \
};                                                                          \
void initVector_##T (struct _vector_##T *v)                                 \
{                                                                           \
    v->size = 0;                                                            \
    v->capacity = 0;                                                        \
    v->elem = NULL;                                                         \
}                                                                           \
void pushBack_##T(struct _vector_##T *v, T *e)                              \
{                                                                           \
    if (!v->capacity)                                                       \
    {                                                                       \
        v->elem = (T*)malloc(sizeof(T));                                    \
        if (!v->elem)                                                       \
        {                                                                   \
            printf("申请空间失败\n");                                        \
            exit(1);                                                        \
        }                                                                   \
        v->capacity = 1;                                                    \
    }                                                                       \
                                                                            \
    if (v->size >= v->capacity)                                             \
    {                                                                       \
        v->elem = (T*)realloc(v->elem, v->size * 2 * sizeof(T));            \
        if (!v->elem)                                                       \
        {                                                                   \
            printf("申请空间失败\n");                                        \
            exit(1);                                                        \
        }                                                                   \
        v->capacity = v->size * 2;                                          \
    }                                                                       \
                                                                            \
    v->elem[v->size] = *e;                                                  \
    ++v->size;                                                              \
}                                                                           \
void pop_##T(struct _vector_##T *v, T *e)                                   \
{                                                                           \
    *e = v->elem[0];                                                        \
    --(v->size);                                                            \
    T *tmp = (T*)malloc((v->capacity)*sizeof(T));                           \
    memcpy(tmp, v->elem+1, (v->size)*sizeof(T));                            \
    free(&(v->elem[0]));                                                    \
    v->elem = tmp;                                                          \
}                                                                           \
void remove_##T(struct _vector_##T *v)                                      \
{                                                                           \
    free(v->elem);                                                          \
    v->elem = NULL;                                                         \
    v->size = v->capacity = 0;                                              \
}                                                                           \
int getSize_##T(struct _vector_##T *v)                                      \
{                                                                           \
    return v->size;                                                         \
}                                                                           \
int getCapacity_##T(struct _vector_##T *v)                                  \
{                                                                           \
    return v->capacity;                                                     \
}                                                                           \
                                                                            \
typedef struct _vector_##T vector_##T


#endif
