#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paranteza.h"
#ifndef _FUNCTII_
#define _FUNCTII_
typedef int (*TFCmp)(void *,void*);
typedef void (*TFAfi)(void *,FILE *);
#endif
#ifndef _STIVA_
#define _STIVA_
typedef struct{
	size_t dime;
	TLG varf;	
}TStiva,*ASt,**VectorSt;
ASt InitSt(size_t);
int push(ASt,void *);
int pop(ASt,void *);
void MutaSt(ASt,ASt);
void sorts(ASt,TFCmp);
void prints(VectorSt,size_t,TFAfi,FILE *);
void DistrSt(ASt *);
#endif
