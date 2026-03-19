# vectors — a lightweight 2D vector math library for C

## Description

`vectors` is a small, simple, and easy‑to‑use C library for working with 2D vectors.  
It has no external dependencies (other than the C standard library) and can be used in educational projects, small graphics engines, or game prototypes.

The library is built around two core structures:

- `struct Vector` — a vector in 2D space  
- `struct Basis2D` — a basis (a pair of unit vectors) used for linear transformations

---

## Features

- **Vector initialization**
  - `void VInit(struct Vector* v, BASIS i, BASIS j);`
- **Vector magnitude**
  - `MODUL VModul(struct Vector v);`
- **Vector addition and subtraction**
  - `void VSumm(struct Vector* out, struct Vector v1, struct Vector v2);`
  - `void VDiff(struct Vector* out, struct Vector v1, struct Vector v2);`
- **Scalar multiplication and division**
  - `MODUL VMul(struct Vector* v, double scalar);`
  - `MODUL VDiv(struct Vector* v, double scalar);`
- **Dot product**
  - `SCALAR VDot(struct Vector v1, struct Vector v2);`
- **Normalization**
  - `MODUL VNormal(struct Vector* out, struct Vector v);`
- **Zero‑vector check**
  - `VIZ VIsZero(struct Vector v);`
- **Angle between vectors**
  - `ANGLE VAngle(struct Vector v1, struct Vector v2, int format);`  
    `format`: `RAD` (radians) or `GRA` (degrees)
- **Distance between vector endpoints**
  - `RADIUS VRadiusDot(struct Vector v1, struct Vector v2);`
- **Basis operations and linear transformations**
  - `void VBasisInit(struct Basis2D* b);` — initializes an identity basis  
  - `void VNevBasis(struct Basis2D* b, BASIS ix, BASIS iy, BASIS jx, BASIS jy);` — sets basis vector coordinates  
  - `void VTransformer(struct Vector* v, struct Basis2D b);` — transforms a vector using the given basis
- **Debug information**
  - `const char* VInf(struct Vector v);`

---

## Build and integration

1. Copy `vectors.c` and `vectors.h` into your project.
2. Include the header:

   c
   #include "vectors.h"
