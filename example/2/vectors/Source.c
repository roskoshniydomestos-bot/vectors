#include <stdio.h>
#include "vectors.h"

int main() {
    /*создаём векторы и базис*/
    struct Vector a, b, sum, diff, norm;
    struct Basis2D basis;

    /*инициализируем (указиваем координаты их концов)*/
    VInit(&a, 3, 4);
    VInit(&b, -2, 5);

    /*выводим информацию о векторах*/
    printf("a = %s", VInf(a));
    printf("b = %s", VInf(b));

    /*находим векторную сумму и результирующий вектор*/
    VSumm(&sum, a, b);
    printf("a + b = %s", VInf(sum));

    /*находим результирующий вектор разности двух векторов*/
    VDiff(&diff, a, b);
    printf("a - b = %s", VInf(diff));

    /*скалярное произведение векторов*/
    printf("Dot = %f\n", VDot(a, b));

    /*нормализация вектора*/
    VNormal(&norm, a);
    printf("Normalized a = %s", VInf(norm));

    /*угол между двумя векторами в радианах*/
    printf("Angle(a, b) = %f rad\n", VAngle(a, b, RAD));

    /*приводим базисные векторы в нормальный вид: i[1;0], j[0;1]*/
    VBasisInit(&basis);

    /*преобразуем вектор согласно новому базису*/
    VTransformer(&a, basis);
    printf("a in default basis = %s", VInf(a));

    return 0;
}
