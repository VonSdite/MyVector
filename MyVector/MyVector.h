#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

#include <stdlib.h>
#include <string.h>

#define state_using_vector(T)                                                               \
struct _vector_##T                                                                          \
{                                                                                           \
    T *elem;                                                                                \
    int _size;                                                                              \
    int _capacity;                                                                          \
    int _tail;                                                                              \
    int _head;                                                                              \
    int _empty;                                                                             \
};                                                                                          \
void initVector_##T (struct _vector_##T *v)                                                 \
{                                                                                           \
    v->_size = v->_capacity = v->_tail = v->_head = 0;                                      \
    v->_empty = 1;                                                                          \
    v->elem = NULL;                                                                         \
}                                                                                           \
void pushBack_##T(struct _vector_##T *v, T *e)                                              \
{                                                                                           \
    if (!v->_capacity)                                                                      \
    {                                                                                       \
        v->elem = (T*)malloc(sizeof(T));                                                    \
        if (!v->elem)                                                                       \
        {                                                                                   \
            printf("申请空间失败n");                                                         \
            exit(1);                                                                        \
        }                                                                                   \
        v->_capacity = 1;                                                                   \
    }                                                                                       \
                                                                                            \
    if(v->_empty)                                                                           \
    {                                                                                       \
        v->_empty = 0;                                                                      \
    }                                                                                       \
    else if (v->_tail == v->_head)                                                          \
    {                                                                                       \
        v->elem = (T*)realloc(v->elem, v->_capacity * 2 * sizeof(T));                       \
        if (!v->elem)                                                                       \
        {                                                                                   \
            printf("申请空间失败n");                                                         \
            exit(1);                                                                        \
        }                                                                                   \
        if (v->_tail) memcpy(v->elem + v->_capacity, v->elem, v->_tail * sizeof(T));        \
        v->_tail += v->_capacity;                                                           \
        v->_capacity = v->_capacity * 2;                                                    \
    }                                                                                       \
                                                                                            \
    v->elem[v->_tail] = *e;                                                                 \
    v->_tail = (v->_tail + 1) % v->_capacity;                                               \
    ++v->_size;                                                                             \
}                                                                                           \
void popFront_##T(struct _vector_##T *v, T *e)                                              \
{                                                                                           \
    if (v->_empty)                                                                          \
    {                                                                                       \
        printf("vector为空，不能pop\n");                                                     \
        return ;                                                                            \
    }                                                                                       \
    *e = v->elem[v->_head];                                                                 \
    v->_head = (v->_head + 1) % v->_capacity;                                               \
    --(v->_size);                                                                           \
    if(!v->_size) v->_empty = 1;                                                            \
}                                                                                           \
T getValueByIndex_##T(struct _vector_##T *v, int index)                                     \
{                                                                                           \
    if (index < 0 || index >= v->_size)                                                     \
    {                                                                                       \
        printf("索引越界\n");                                                                \
        exit(1);                                                                            \
    }                                                                                       \
                                                                                            \
    return v->elem[v->_head+index];                                                         \
}                                                                                           \
                                                                                            \
void remove_##T(struct _vector_##T *v)                                                      \
{                                                                                           \
    free(v->elem);                                                                          \
    v->elem = NULL;                                                                         \
    v->_size = v->_capacity = v->_tail = v->_head = 0;                                      \
    v->_empty = 1;                                                                          \
}                                                                                           \
int getSize_##T(struct _vector_##T *v)                                                      \
{                                                                                           \
    return v->_size;                                                                        \
}                                                                                           \
int getCapacity_##T(struct _vector_##T *v)                                                  \
{                                                                                           \
    return v->_capacity;                                                                    \
}                                                                                           \
                                                                                            \
typedef struct _vector_##T vector_##T##_


#endif
