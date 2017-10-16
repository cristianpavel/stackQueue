#ifndef _LISTA_GENERICA_
#define _LISTA_GENERICA_
typedef struct celula{

	void *info;
	struct celula *urm;
}TCelulaG,*TLG,**ALG;
#endif
