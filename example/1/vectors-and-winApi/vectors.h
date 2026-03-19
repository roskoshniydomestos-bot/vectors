#pragma once

#define PI					3.14159265												//число пи

#define NORMAL_VECTOR		1														//модуль нориального вектора
#define NULL_VECTOR			0														//модуль нулевого вектора
#define NOT_NULL_VECTOR		-1														//флаг не нулевого вектора
#define NUM_DIMENSIONS		2														//число измерений вектороного промтранства
#define VX					0														//х нулевого базиса
#define VY					1														//у нолевого базиса

#define RAD					11														//радианы
#define GRA					12														//градусы

typedef double	BASIS;																//тип для базисов
typedef double	MODUL;																//тип для модуля вектора
typedef double	SCALAR;																//тип для скалярного произведениия векторов
typedef int		VIZ;																//тип для проверки на нулевой вектор
typedef double	ANGLE;																//угловой тип
typedef double	RADIUS;																//тип для растояния

struct Vector {																		//струксурв параметров вектора
	MODUL	modul;																	//модуль вектора
	BASIS	i;																		//базис i вектора
	BASIS	j;																		//базис j вектора
};

struct Basis2D{																		//структура единичных базисов
	BASIS	ixy[NUM_DIMENSIONS];													//единичный базис i
	BASIS	jxy[NUM_DIMENSIONS];													//единичный базис j
};

MODUL		VModul	(struct Vector v);												//модуль вектора
void		VInit	(struct Vector* v, BASIS i, BASIS j);							//инициализация вектора
void		VBasisInit(struct Basis2D* b);											//инициализация базиса
void		VCopi	(struct Vector* vin, struct Vector vcopi);						//копирование вектора
void		VNevBasis(struct Basis2D* b, BASIS ix, BASIS iy, BASIS jx, BASIS jy);	//задание новых единичных базисов вектора
void		VTransformer(struct Vector* v, struct Basis2D b);						//преобразование вектора по единичным базисам
const char* VInf	(struct Vector v);												//возврфщает строку информацией о векторе
void		VSumm	(struct Vector* VSumm, struct Vector v1, struct Vector v2);		//сумма двух векторов
void		VDiff	(struct Vector* VDiff, struct Vector v1, struct Vector v2);		//разница двух векторов
MODUL		VMul	(struct Vector* v, double scalar);								//умножение вектора на скаляр
MODUL		VDiv	(struct Vector* v, double scalar);								//деление вектора на скаляр
SCALAR		VDot	(struct Vector v1, struct Vector v2);							//скалярное произведение вектороов
MODUL		VNormal	(struct Vector* NormalVector, struct Vector v);					//нормализация вектора
VIZ			VIsZero	(struct Vector v);												//проверка на нулевой вектор
RADIUS		VRadiusDot(struct Vector v1, struct Vector v2);							//растояние между концами двух векторов
void		VReturnBasis(BASIS* i, BASIS* j, struct Vector v);						//возвращает базисы вектора