#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

#include <stdlib.h>
#include <string.h>

#define state_using_vector(T) \
struct _vector_##T\
{\
  T *elem;  \
  int size; \
  int maxSize; \
}; \
void initVector_##T (struct _vector_##T *v)\
{\
    v->size = 0;\
    v->maxSize = 0;\
    v->elem = NULL;\
}\
void pushBack_##T(struct _vector_##T *v, T *e)\
{\
    if (!v->maxSize)\
    {\
        v->elem = (T*)malloc(sizeof(T));\
        if (!v->elem)\
        {\
            printf("申请空间失败\n");\
            exit(1);\
        }\
        v->maxSize = 1;\
    }\
\
    if (v->size >= v->maxSize)\
    {\
        v->elem = (T*)realloc(v->elem, v->size * 2 * sizeof(T));\
        if (!v->elem)\
        {\
            printf("申请空间失败\n");\
            exit(1);\
        }\
        v->maxSize = v->size * 2;\
    }\
\
    v->elem[v->size] = *e;\
    ++v->size;\
}\
void pop_##T(struct _vector_##T *v, T *e)\
{\
    *e = v->elem[0];\
    v->elem = v->elem + 1;\
    --(v->size);\
    --(v->maxSize);\
}\
void remove_##T(struct _vector_##T *v)\
{\
    free(v->elem);\
    v->size = v->maxSize = 0;\
    free(v);\
}\
int getSize_##T(struct _vector_##T *v)\
{\
    return v->size;\
}\
int getMaxSize_##T(struct _vector_##T *v)\
{\
    return v->maxSize;\
}\
\
typedef _vector_##T vector_##T


#endif
