#define _CRT_SECURE_NO_WARNINGS

#include "vectors.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

MODUL VModul (struct Vector v) {
	double summ = (v.i * v.i) + (v.j * v.j);
	if (summ != 0)	return sqrt(summ);
	else			return 0;
}

void VInit (struct Vector* v, BASIS i, BASIS j) {
	v->i		= i;
	v->j		= j;
	v->modul	= VModul(*v);
}

void VBasisInit(struct Basis2D* b) {
	b->ixy[VX] = 1;
	b->ixy[VY] = 0;
	b->jxy[VX] = 0;
	b->jxy[VY] = 1;
}

void VCopi(struct Vector* vin, struct Vector vcopi) {
	vin->i		= vcopi.i;
	vin->j		= vcopi.j;
	vin->modul	= vcopi.modul;
}

void VNevBasis(struct Basis2D* b, BASIS ix, BASIS iy, BASIS jx, BASIS jy) {
	b->ixy[VX] = ix;
	b->ixy[VY] = iy;

	b->jxy[VX] = jx;
	b->jxy[VY] = jy;
}

void VTransformer(struct Vector* v, struct Basis2D b) {
	BASIS old_i = v->i;
	BASIS old_j = v->j;

	v->i = old_i * b.ixy[VX] + old_j * b.jxy[VX];
	v->j = old_i * b.ixy[VY] + old_j * b.jxy[VY];

	v->modul = VModul(*v);
}

const char* VInf(struct Vector v) {
	static char buf[128] = { 0 };
	sprintf(buf, "i: %0.4f; j: %0.4f; modul: %0.4f.\n", v.i, v.j, v.modul);
	return buf;
}

void VSumm(struct Vector* VSumm, struct Vector v1, struct Vector v2) {
	VSumm->i			= v1.i + v2.i;
	VSumm->j			= v1.j + v2.j;
	VSumm->modul		= VModul(*VSumm);
}

void VDiff(struct Vector* VDiff, struct Vector v1, struct Vector v2) {
	VDiff->i			= v1.i - v2.i;
	VDiff->j			= v1.j - v2.j;
	VDiff->modul		= VModul(*VDiff);
}

MODUL VMul(struct Vector* v, double scalar) {
	v->i			*= scalar;
	v->j			*= scalar;
	return v->modul = VModul(*v);
}

MODUL VDiv(struct Vector* v, double scalar) {
	if (scalar != 0) {
		v->i			/= scalar;
		v->j			/= scalar;
		return v->modul = VModul(*v);
	}
	else return 0;
}

SCALAR VDot(struct Vector v1, struct Vector v2) {
	return v1.i * v2.i + v1.j * v2.j;
}

MODUL VNormal(struct Vector* NormalVector, struct Vector v) {
	if (v.modul == 0) {
		NormalVector->i = 0;
		NormalVector->j = 0;
	}
	else {
		NormalVector->i = v.i / v.modul;
		NormalVector->j = v.j / v.modul;
	}
	NormalVector->modul = VModul(*NormalVector);
	return NormalVector->modul;

}

VIZ VIsZero(struct Vector v) {
	if (v.i == 0 && v.j == 0) return NULL_VECTOR;
	else return NOT_NULL_VECTOR;
}

ANGLE VAngle(struct Vector v1, struct Vector v2, int format){
	ANGLE angle = acos(((v1.i * v2.i) / (v1.modul * v2.modul)) + ((v1.j * v2.j) / (v1.modul * v2.modul)));
	switch (format){
	case RAD:	return  angle;				break;
	case GRA:	return (180 * angle) / PI;  break;
	default:	return 0;					break;
	}
}

RADIUS VRadiusDot(struct Vector v1, struct Vector v2) {
	struct Vector result;
	result.i = v2.i - v1.i;
	result.j = v2.j - v1.j;
	return result.modul = VModul(result);
}

void VReturnBasis(BASIS* i, BASIS* j, struct Vector v) {
	*i = v.i;
	*j = v.j;
}

