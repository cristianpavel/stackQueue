#include "lista.h"
#include "stiva.h"
#ifndef _FUNCTII_
#define _FUNCTII_
typedef int (*TFCmp)(void *,void *);
typedef void (*TFAfi)(void *,FILE *);
#endif
#ifndef _COADA_
#define _COADA_
typedef struct{
	size_t dime;
	TLG prim,ultim;
}TCoada,*ACoada,**VectorQ;
ACoada InitQ(size_t);
int intrq(ACoada,void *);
int extrq(ACoada,void *);
void MutaQ(ACoada,ACoada);
void sortq(ACoada,TFCmp);
void printq(VectorQ,size_t,TFAfi,FILE *);
void DistrQ(ACoada *);
#endif
