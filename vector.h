/*!
    @mainpage VECTOR 1.0.0
    \brief Заголовочный файл, который необходимо включать в проект для вызова структуры vector и её методов.
    \author Sasha729
    \version 1.0.0
    \date 10.05.2024

    Данная библиотека реализует структуру vector для всех стандартных типов языка C - аналог версии стандарта C++11 <vector>. 
    Для включения создания vector необходимого типа
    vector.h должен быть включен в файл проекта следующим образом:
    \code
    #define <TYPENAME>_VECTOR
    #include "vector.h"
    \endcode 

    Структура будет иметь имя vector_<typename>, методы создания и удаления init_vector_<typename>() и destruct_vector_<typename>().

    Если необходимо включить vector для нескольких типов:
    \code
    #define <TYPENAME_1>_VECTOR
    #include "vector.h"
    #define <TYPENAME_2>_VECTOR
    #include "vector.h"

    ...

    \endcode

    Доступные типы данных и соответсвующие им макросы и псевдонимы типов (<TYPENAME>_VECTOR и <typename>, соответсвенно):
    1. char, CHAR_VECTOR, char
    2. unsigned char, UNSIGNED_CHAR_VECTOR, uchar
    3. signed char, SIGNED_CHAR_VECTOR, char
    4. short, SHORT_VECTOR, short
    5. unsigned short, UNSIGNED_SHORT_VECTOR, ushort
    6. int, INT_VECTOR, int
    7. unsigned int, UNSIGNED_INT_VECTOR, uint
    8. long int, LONG_INT_VECTOR, long
    9. unsigned int, UNSIGNED_LONG_INT_VECTOR, ulong
    10. long long int, LONG_LONG_INT_VECTOR, longlong
    11. unsigned long long int, UNSIGNED_LONG_LONG_INT_VECTOR, ulonglong
    12. float, FLOAT_VECTOR, float
    13. double, DOUBLE_VECTOR, double
    14. long double, LONG_DOUBLE_VECTOR, ldouble

    Можно добавлять собственные типы данных, однако стоит учитывать, что vector не очищает память внутри объектов, которые в находятся, он удаляет лишь сами объекты,
    поэтому требуется использовать дополнительную очитку либо, если у объекта имеется деструктор вида void destruct_object(<typename>**), можно вызвать функцию
    destruct_vector_with_object_<typename>() и передать в неё деструктор объекта. Также для использования метода print необходимо его также модифицировать и добавить
    в отдельную ветвь условной компиляции.
*/

/*!
    \file
    \brief Заголовочный файл, который необходимо включать в проект для вызова структуры vector и её методов.
    \author Sasha729
    \version 1.0.0
    \date 10.05.2024

    Данный файл подключается для использования структуры vector и её методов в проекте.
    Можно добавлять собственные типы данных, однако стоит учитывать, что vector не очищает память внутри объектов, которые в находятся, он удаляет лишь сами объекты,
    поэтому требуется использовать дополнительную очитку либо, если у объекта имеется деструктор вида void destruct_object(<typename>**), можно вызвать функцию
    destruct_vector_with_object_<typename>() и передать в неё деструктор объекта. Также для использования метода print необходимо его также модифицировать и добавить
    в отдельную ветвь условной компиляции.
*/

#ifdef CHAR_VECTOR
#define T char
#include "vector_template.h"
#undef T
#undef CHAR_VECTOR
#endif

#ifdef UNSIGNED_CHAR_VECTOR
typedef unsigned char uchar;
#define T uchar
#include "vector_template.h"
#undef T
#undef UNSIGNED_CHAR_VECTOR
#endif

#ifdef SIGNED_CHAR_VECTOR
#define T char
#include "vector_template.h"
#undef T
#undef SIGNED_CHAR_VECTOR
#endif

#ifdef SHORT_VECTOR
#define T short
#include "vector_template.h"
#undef T
#undef SHORT_VECTOR
#endif

#ifdef UNSIGNED_SHORT_VECTOR
typedef unsigned short ushort;
#define T ushort
#include "vector_template.h"
#undef T
#undef UNSIGNED_SHORT_VECTOR
#endif

#ifdef INT_VECTOR
#define T int
#include "vector_template.h"
#undef T
#undef INT_VECTOR
#endif

#ifdef UNSIGNED_INT_VECTOR
typedef unsigned int uint;
#define T uint
#include "vector_template.h"
#undef T
#undef UNSIGNED_INT_VECTOR
#endif

#ifdef LONG_INT_VECTOR
#define T long
#include "vector_template.h"
#undef T
#undef LONG_INT_VECTOR
#endif

#ifdef UNSIGNED_LONG_INT_VECTOR
typedef unsigned long ulong;
#define T ulong
#include "vector_template.h"
#undef T
#undef UNSIGNED_LONG_INT_VECTOR
#endif

#ifdef LONG_LONG_INT_VECTOR
typedef long long longlong;
#define T longlong
#include "vector_template.h"
#undef T
#undef LONG_LONG_INT_VECTOR
#endif

#ifdef UNSIGNED_LONG_LONG_INT_VECTOR
typedef unsigned long long ulonglong;
#define T ulonglong
#include "vector_template.h"
#undef T
#undef UNSIGNED_LONG_LONG_INT_VECTOR
#endif

#ifdef FLOAT_VECTOR
#define T float
#include "vector_template.h"
#undef T
#undef FLOAT_VECTOR
#endif

#ifdef DOUBLE_VECTOR
#define T double
#include "vector_template.h"
#undef T
#undef DOUBLE_VECTOR
#endif

#ifdef LONG_DOUBLE_VECTOR
typedef long double ldouble
#define T ldouble
#include "vector_template.h"
#undef T
#undef LONG_DOUBLE_VECTOR
#endif