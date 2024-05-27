/*!
    \file
    \brief Заголовочный файл, который содержит объявление структуры vector и шаблонную реализацию его методов.
    \author Sasha729
    \version 1.0.1
    \date 27.05.2024

    Заголовочный файл, который содержит объявление структуры vector и шаблонную реализацию его методов.
    Можно добавлять собственные типы данных, однако стоит учитывать, что vector не очищает память внутри объектов, которые в находятся, он удаляет лишь сами объекты,
    поэтому требуется использовать дополнительную очитку памяти.
*/
#ifdef T

#include "template.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TEMPLATE(__vector_private, T)
{
    T *__data;
    unsigned int __size;
    unsigned int __allocated_size;
} TEMPLATE(vector_private, T);

typedef struct TEMPLATE(__vector, T) TEMPLATE(vector, T);
struct TEMPLATE(__vector, T)
{
    TEMPLATE(vector_private, T) __private;

    T (*at)(const TEMPLATE(vector, T) *const *const, const unsigned int);               ///< возвращает значение по индексу
    T (*back)(const TEMPLATE(vector, T) *const *const);                                 ///< возвращает последний элемент
    T *(*begin)(const TEMPLATE(vector, T) *const *const);                               ///< возвращает указатель на первый элемент
    unsigned int (*capacity)(const TEMPLATE(vector, T) *const *const);                  ///< возвращает доступную выделенную память для заполнения вектора
    void (*clear)(TEMPLATE(vector, T) **const);                                         ///< очищает вектор
    T *(*data)(const TEMPLATE(vector, T) *const *const);                                ///< возвращает значение по индексу
    void (*emplace)(TEMPLATE(vector, T) *const *const, const unsigned int, const T);    ///< вставляет значение по индексу
    int (*empty)(const TEMPLATE(vector, T) *const *const);                              ///< проверяет, не пустой ли вектор
    T *(*end)(const TEMPLATE(vector, T) *const *const);                                 ///< возвращает указатель на последний элемент
    void (*erase)(TEMPLATE(vector, T) *const *const, const unsigned int);               ///< удаляет элемент по индексу
    int (*find_first_of)(const TEMPLATE(vector, T) *const *const, const T);             ///< возвращает индекс первого вхождения элемента
    int (*find_last_of)(const TEMPLATE(vector, T) *const *const, const T);              ///< возвращает индекс последнего вхождения элемента
    T (*front)(const TEMPLATE(vector, T) *const *const);                                ///< возвращает первый элемент
    void (*insert)(TEMPLATE(vector, T) *const *const, const unsigned int, const T);     ///< вставляет элемент перед индексом
    void (*pop_back)(TEMPLATE(vector, T) *const *const);                                ///< удаляет элемент из конца
    void (*pop_front)(TEMPLATE(vector, T) *const *const);                               ///< удаляет элемент из начала
    void (*print)(const TEMPLATE(vector, T) *const *const);                             ///< выводит вектор в стандартный поток вывода
    void (*push_back)(TEMPLATE(vector, T) *const *const, const T);                      ///< добавляет элемент в конец
    void (*push_front)(TEMPLATE(vector, T) *const *const, const T);                     ///< добавляет элемент в начало
    void (*reserve)(TEMPLATE(vector, T) *const *const, const unsigned int);             ///< выделяет дополнительную память
    void (*resize)(TEMPLATE(vector, T) *const *const, const unsigned int);              ///< изменяет размер вектора
    unsigned int (*size)(const TEMPLATE(vector, T) *const *const);                      ///< возвращает количество элементов в векторе
};

static T TEMPLATE(at, T)(const TEMPLATE(vector, T) *const *const self, const unsigned int index);
static T TEMPLATE(back, T)(const TEMPLATE(vector, T) *const *const self);
static T *TEMPLATE(begin, T)(const TEMPLATE(vector, T) *const *const self);
static unsigned int TEMPLATE(capacity, T)(const TEMPLATE(vector, T) *const *const self);
static void TEMPLATE(clear, T)(TEMPLATE(vector, T) **const self);
static T *TEMPLATE(data, T)(const TEMPLATE(vector, T) *const *const self);
static void TEMPLATE(emplace, T)(TEMPLATE(vector, T) *const *const self, const unsigned int index, const T value);
static int TEMPLATE(empty, T)(const TEMPLATE(vector, T) *const *const self);
static T *TEMPLATE(end, T)(const TEMPLATE(vector, T) *const *const self);
static void TEMPLATE(erase, T)(TEMPLATE(vector, T) *const *const self, const unsigned int index);
static int TEMPLATE(find_first_of, T)(const TEMPLATE(vector, T) *const *const self, const T value);
static int TEMPLATE(find_last_of, T)(const TEMPLATE(vector, T) *const *const self, const T value);
static T TEMPLATE(front, T)(const TEMPLATE(vector, T) *const *const self);
static void TEMPLATE(insert, T)(TEMPLATE(vector, T) *const *const self, const unsigned int before, const T value);
static void TEMPLATE(pop_back, T)(TEMPLATE(vector, T) *const *const self);
static void TEMPLATE(pop_front, T)(TEMPLATE(vector, T) *const *const self);
static void TEMPLATE(print, T)(const TEMPLATE(vector, T) *const *const self);
static void TEMPLATE(push_back, T)(TEMPLATE(vector, T) *const *const self, const T value);
static void TEMPLATE(push_front, T)(TEMPLATE(vector, T) *const *const self, const T value);
static void TEMPLATE(reserve, T)(TEMPLATE(vector, T) *const *const self, const unsigned int res_size);
static void TEMPLATE(resize, T)(TEMPLATE(vector, T) *const *const self, const unsigned int size);
static unsigned int TEMPLATE(size, T)(const TEMPLATE(vector, T) *const *const self);

void TEMPLATE(destruct_vector, T)(TEMPLATE(vector, T) **self)
{
    if ((*self)->__private.__allocated_size > 0)
        free((*self)->__private.__data);
    free(*self);

    *self = NULL;
}

TEMPLATE(vector, T) *TEMPLATE(init_vector, T)(const unsigned int init_size, const T init_value)
{
    TEMPLATE(vector, T) *new_vector = (TEMPLATE(vector, T)*)malloc(sizeof(TEMPLATE(vector, T)));
    assert(new_vector != NULL && "ERROR :: VECTOR :: Memory couldn't be allocated");

    new_vector->__private.__data = (T*)calloc(init_size, sizeof(T));
    assert(new_vector->__private.__data != NULL && "ERROR :: VECTOR :: Memory couldn't be allocated");

    new_vector->__private.__size = init_size;
    new_vector->__private.__allocated_size = init_size;
    for (unsigned int i = 0; i < init_size; ++i)
        new_vector->__private.__data[i] = init_value;

    new_vector->at = TEMPLATE(at, T);
    new_vector->back = TEMPLATE(back, T);
    new_vector->begin = TEMPLATE(begin, T);
    new_vector->capacity = TEMPLATE(capacity, T);
    new_vector->clear = TEMPLATE(clear, T);
    new_vector->data = TEMPLATE(data, T);
    new_vector->emplace = TEMPLATE(emplace, T);
    new_vector->empty = TEMPLATE(empty, T);
    new_vector->end = TEMPLATE(end, T);
    new_vector->erase = TEMPLATE(erase, T);
    new_vector->front = TEMPLATE(front, T);
    new_vector->insert = TEMPLATE(insert, T);
    new_vector->find_first_of = TEMPLATE(find_first_of, T);
    new_vector->find_last_of = TEMPLATE(find_last_of, T);
    new_vector->pop_back = TEMPLATE(pop_back, T);
    new_vector->pop_front = TEMPLATE(pop_front, T);
    new_vector->print = TEMPLATE(print, T);
    new_vector->push_back = TEMPLATE(push_back, T);
    new_vector->push_front = TEMPLATE(push_front, T);
    new_vector->reserve = TEMPLATE(reserve, T);
    new_vector->resize = TEMPLATE(resize, T);
    new_vector->size = TEMPLATE(size, T);

    return new_vector;
}

static T TEMPLATE(at, T)(const TEMPLATE(vector, T) *const *const self, const unsigned int index)
{
    assert(index < (*self)->__private.__size && "ERROR :: TEMPLATE(vector, T) :: Index out of range");

    return (*self)->__private.__data[index];
}

static T TEMPLATE(back, T)(const TEMPLATE(vector, T) *const *const self)
{
    return (*self)->__private.__data[(*self)->__private.__size - 1];
}

static T *TEMPLATE(begin, T)(const TEMPLATE(vector, T) *const *const self)
{
    return (*self)->__private.__data;
}

static unsigned int TEMPLATE(capacity, T)(const TEMPLATE(vector, T) *const *const self)
{
    return (*self)->__private.__allocated_size;
}

static void TEMPLATE(clear, T)(TEMPLATE(vector, T) **const self)
{
    free((*self)->__private.__data);
    (*self)->__private.__size = 0;
    (*self)->__private.__allocated_size = 0;
}

static T *TEMPLATE(data, T)(const TEMPLATE(vector, T) *const *const self)
{
    return (*self)->__private.__data;
}

static void TEMPLATE(emplace, T)(TEMPLATE(vector, T) *const *const self, const unsigned int index, const T value)
{
    assert(index < (*self)->__private.__size && "ERROR :: TEMPLATE(vector, T) :: Index out of range");

    (*self)->__private.__data[index] = value;
}

static int TEMPLATE(empty, T)(const TEMPLATE(vector, T) *const *const self)
{
    return (*self)->__private.__size == 0;
}

static T *TEMPLATE(end, T)(const TEMPLATE(vector, T) *const *const self)
{
    return (*self)->__private.__data + (*self)->__private.__size - 1;
}

static void TEMPLATE(erase, T)(TEMPLATE(vector, T) *const *const self, const unsigned int index)
{
    assert(index < (*self)->__private.__size && "ERROR :: TEMPLATE(vector, T) :: Index out of range");

    if (index == 0)
    {
        TEMPLATE(pop_front, T)(self);
        return;
    }
    else if (index == (*self)->__private.__size)
    {
        TEMPLATE(pop_back, T)(self);
        return;
    }

    memmove((*self)->__private.__data + index, (*self)->__private.__data + index + 1, ((*self)->__private.__size - index) * sizeof(T));
    --(*self)->__private.__size;
}

int TEMPLATE(find_first_of, T)(const TEMPLATE(vector, T) *const *const self, const T value)
{
    unsigned int i;
    for (i = 0; i < (*self)->size(self); ++i)
        if ((*self)->at(self, i) == value)
            return i;

    return -1;
}

int TEMPLATE(find_last_of, T)(const TEMPLATE(vector, T) *const *const self, const T value)
{
    unsigned int i;
    for (i = (*self)->size(self) - 1; i >= 0; --i)
        if ((*self)->at(self, i) == value)
            return i;

    return -1;
}

static T TEMPLATE(front, T)(const TEMPLATE(vector, T) *const *const self)
{
    return (*self)->__private.__data[0];
}

static void TEMPLATE(insert, T)(TEMPLATE(vector, T) *const *const self, const unsigned int before, const T value)
{
    assert(before < (*self)->__private.__size && "ERROR :: TEMPLATE(vector, T) :: Index out of range");

    if (before == 0)
    {
        TEMPLATE(push_front, T)(self, value);
        return;
    }
    else if (before == (*self)->__private.__size)
    {
        TEMPLATE(push_front, T)(self, value);
        return;
    }

    if ((*self)->__private.__size == (*self)->__private.__allocated_size)
    {
        (*self)->__private.__data =  (T*)realloc((*self)->__private.__data, ((*self)->__private.__size + 1) * sizeof(T));
        assert((*self)->__private.__data !=  NULL && "ERROR :: TEMPLATE(vector, T) :: Memory couldn't be allocated");
        ++(*self)->__private.__allocated_size;
    }

    memmove((*self)->__private.__data + before + 1, (*self)->__private.__data + before, ((*self)->__private.__size - before) * sizeof(T));

    (*self)->__private.__data[before] = value;
    ++(*self)->__private.__size;
}

static void TEMPLATE(pop_back, T)(TEMPLATE(vector, T) *const *const self)
{
    --(*self)->__private.__size;
}

static void TEMPLATE(pop_front, T)(TEMPLATE(vector, T) *const *const self)
{
    memmove((*self)->__private.__data, (*self)->__private.__data + 1, ((*self)->__private.__size - 1) * sizeof(T));
    --(*self)->__private.__size;
}

static void TEMPLATE(print, T)(const TEMPLATE(vector, T) *const *const self)
{
    printf("vector { ");
    if ((*self)->__private.__size > 0)
    {
        for (unsigned int i = 0; i < (*self)->__private.__size - 1; ++i)
#ifdef CHAR_VECTOR
            printf("%hhd, ", TEMPLATE(at, T)(self, i));
        printf("%hhd }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef UNSIGNED_CHAR_VECTOR
            printf("%hhu, ", TEMPLATE(at, T)(self, i));
        printf("%hhu }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef SHORT_VECTOR
            printf("%hd, ", TEMPLATE(at, T)(self, i));
        printf("%hd }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef UNSIGNED_SHORT_VECTOR
            printf("%hu, ", TEMPLATE(at, T)(self, i));
        printf("%hu }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef INT_VECTOR
            printf("%d, ", TEMPLATE(at, T)(self, i));
        printf("%d }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef UNSIGNED_INT_VECTOR
            printf("%u, ", TEMPLATE(at, T)(self, i));
        printf("%u }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef LONG_INT_VECTOR
            printf("%ld, ", TEMPLATE(at, T)(self, i));
        printf("%ld }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef UNSIGNED_LONG_INT_VECTOR
            printf("%lu, ", TEMPLATE(at, T)(self, i));
        printf("%lu }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef LONG_LONG_INT_VECTOR
            printf("%lld, ", TEMPLATE(at, T)(self, i));
        printf("%lld }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef UNSIGNED_LONG_LONG_INT_VECTOR
            printf("%llu, ", TEMPLATE(at, T)(self, i));
        printf("%llu }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef FLOAT_VECTOR
            printf("%f, ", TEMPLATE(at, T)(self, i));
        printf("%f }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef DOUBLE_VECTOR
            printf("%f, ", TEMPLATE(at, T)(self, i));
        printf("%f }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
#ifdef LONG_DOUBLE_VECTOR
            printf("%Lf, ", TEMPLATE(at, T)(self, i));
        printf("%Lf }\n", TEMPLATE(at, T)(self, (*self)->__private.__size - 1));
#endif
    }
    else
    {
        printf("}\n");
    }

    printf("size: %d\n", (*self)->__private.__size);
    printf("allocated_size: %d\n", (*self)->__private.__allocated_size);
}

static void TEMPLATE(push_back, T)(TEMPLATE(vector, T) *const *const self, const T value)
{
    if ((*self)->__private.__size == (*self)->__private.__allocated_size)
    {
        (*self)->__private.__data =  (T*)realloc((*self)->__private.__data, ((*self)->__private.__allocated_size + 1) * sizeof(T));
        assert((*self)->__private.__data != NULL && "ERROR :: TEMPLATE(vector, T) :: Memory couldn't be allocated");
        ++(*self)->__private.__allocated_size;
    }

    (*self)->__private.__data[(*self)->__private.__size] = value;
    ++(*self)->__private.__size;
}

static void TEMPLATE(push_front, T)(TEMPLATE(vector, T) *const *const self, const T value)
{
    if ((*self)->__private.__size == (*self)->__private.__allocated_size)
    {
        (*self)->__private.__data =  (T*)realloc((*self)->__private.__data, ((*self)->__private.__allocated_size + 1) * sizeof(T));
        assert((*self)->__private.__data != NULL && "ERROR :: TEMPLATE(vector, T) :: Memory couldn't be allocated");
        ++(*self)->__private.__allocated_size;
    }

    memmove((*self)->__private.__data + 1, (*self)->__private.__data, (*self)->__private.__size * sizeof(T));

    (*self)->__private.__data[0] = value;
    ++(*self)->__private.__size;
}

static void TEMPLATE(reserve, T)(TEMPLATE(vector, T) *const *const self, const unsigned int res_size)
{
    (*self)->__private.__data =  (T*)realloc((*self)->__private.__data, ((*self)->__private.__allocated_size + res_size) * sizeof(T));
    (*self)->__private.__allocated_size += res_size;

    assert((*self)->__private.__data != NULL && "ERROR :: TEMPLATE(vector, T) :: Memory couldn't be allocated");
}

static void TEMPLATE(resize, T)(TEMPLATE(vector, T) *const *const self, const unsigned int size)
{
    (*self)->__private.__data = (T*)realloc((*self)->__private.__data, size * sizeof(T));
    (*self)->__private.__allocated_size = size;
    if ((*self)->__private.__size > (*self)->__private.__allocated_size)
        (*self)->__private.__size = (*self)->__private.__allocated_size;

    assert((*self)->__private.__data != NULL && "ERROR :: TEMPLATE(vector, T) :: Memory couldn't be allocated");
}

static unsigned int TEMPLATE(size, T)(const TEMPLATE(vector, T) *const *const self)
{
    return (*self)->__private.__size;
}

#endif // T //
