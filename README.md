# vectors — библиотека для работы с 2D‑векторами на C

## Описание

`vectors` — это небольшая, простая и понятная библиотека на C для работы с двумерными векторами.  
Она не тянет за собой никаких зависимостей (кроме стандартной библиотеки C) и может использоваться как в учебных проектах, так и в небольших графических/игровых движках.

Библиотека построена вокруг двух основных сущностей:

- `struct Vector` — вектор в 2D‑пространстве  
- `struct Basis2D` — базис (пара единичных векторов), позволяющий выполнять линейные преобразования

---

## Возможности

- **Инициализация вектора**
  - `void VInit(struct Vector* v, BASIS i, BASIS j);`
- **Модуль (длина) вектора**
  - `MODUL VModul(struct Vector v);`
- **Сумма и разность векторов**
  - `void VSumm(struct Vector* out, struct Vector v1, struct Vector v2);`
  - `void VDiff(struct Vector* out, struct Vector v1, struct Vector v2);`
- **Умножение и деление на скаляр**
  - `MODUL VMul(struct Vector* v, double scalar);`
  - `MODUL VDiv(struct Vector* v, double scalar);`
- **Скалярное произведение**
  - `SCALAR VDot(struct Vector v1, struct Vector v2);`
- **Нормализация**
  - `MODUL VNormal(struct Vector* out, struct Vector v);`
- **Проверка на нулевой вектор**
  - `VIZ VIsZero(struct Vector v);`
- **Угол между векторами**
  - `ANGLE VAngle(struct Vector v1, struct Vector v2, int format);`  
    `format`: `RAD` (радианы) или `GRA` (градусы)
- **Расстояние между концами двух векторов**
  - `RADIUS VRadiusDot(struct Vector v1, struct Vector v2);`
- **Работа с базисом и линейными преобразованиями**
  - `void VBasisInit(struct Basis2D* b);` — единичный базис  
  - `void VNevBasis(struct Basis2D* b, BASIS ix, BASIS iy, BASIS jx, BASIS jy);` - задаёт координаты концов базисных векторов
  - `void VTransformer(struct Vector* v, struct Basis2D b);` - преобразует вектор по заданному базису
- **Отладочная информация**
  - `const char* VInf(struct Vector v);`

---

Сборка и подключение
Скопируйте файлы vectors.c и vectors.h в свой проект.

Подключите заголовок:

c
#include "vectors.h"
Добавьте vectors.c в список исходников при сборке.
