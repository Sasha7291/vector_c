# VECTOR 1.0.0

  Данная библиотека реализует структуру vector для всех стандартных типов языка C - аналог версии стандарта C++11 <vector>. 

  ## Подключение
  Для включения создания vector необходимого типа vector.h должен быть включен в файл проекта следующим образом:
  ```
  #define <TYPENAME>_VECTOR
  #include "vector.h" 
  ```

  Структура будет иметь имя vector_<typename>, методы создания и удаления init_vector_<typename>() и destruct_vector_<typename>().
  Если необходимо включить vector для нескольких типов:
  ```
  #define <TYPENAME_1>_VECTOR
  #include "vector.h"
  #define <TYPENAME_2>_VECTOR
  #include "vector.h"

  ...

  ```
  
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
