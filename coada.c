#include "coada.h"
#include "lista.h"
ACoada InitQ(size_t dime){

	ACoada q = (ACoada)malloc(sizeof(TCoada));
	if (!q){
		printf("eroare la alocare coada\n");
		return NULL;
	}
	q->dime = dime;
	q->prim = NULL;
	q->ultim = NULL;
	return q;

}
int intrq(ACoada q,void *ae){


	TLG aux = (TLG)malloc(sizeof(TCelulaG));
	if (!aux){

		printf("eroare la alocare celula coada\n");
		return 0;
	}
	aux->info = malloc(q->dime);
	memcpy(aux->info,ae,q->dime);
	aux->urm = NULL;
	if (q->ultim == NULL){
		q->ultim = aux;
		q->prim = q->ultim;
		return 1;
	}
	q->ultim->urm = aux;
	q->ultim = aux;
	return 1;

}
int extrq(ACoada q,void *ae){


	if (q->prim == NULL)
		return 0;
	TLG aux = q->prim;
	q->prim = q->prim->urm;
	memcpy(ae,aux->info,q->dime);
	free(aux->info);
	free(aux);
	if (q->prim == NULL)
		q->ultim = NULL;
	return 1;
}
void MutaQ(ACoada ad,ACoada as){

	while (as->prim != NULL){
		void *ae = malloc(as->dime);
		extrq(as,ae);
		intrq(ad,ae);
		free(ae);
	}

}
void sortq(ACoada q,TFCmp f){


	ACoada qSortat = InitQ(q->dime);
	while (q->prim != NULL){

		void *minim = malloc(q->dime);
		memcpy(minim,q->prim,q->dime);
		ACoada qAux = InitQ(q->dime);
		while (q->prim != NULL){
		
			void *ae = malloc(q->dime);
			extrq(q,ae);
			if (f(minim,ae) > 0)
				memcpy(minim,ae,q->dime);
			intrq(qAux,ae);
			free(ae);

		}
		while (qAux->prim != NULL){

			void *ae = malloc(q->dime);
			extrq(qAux,ae);
			if (f(minim,ae) == 0)
				intrq(qSortat,ae);
			else
				intrq(q,ae);
			free(ae);

		}
		free(minim);
		free(qAux);

	}
	
	MutaQ(q,qSortat);
	free(qSortat);
}
void printq(VectorQ a,size_t n,TFAfi f,FILE *out){


	int i;
	for (i = 0; i  < n; i++){


		ACoada qAux = InitQ(a[i]->dime);
		MutaQ(qAux,a[i]);
		fprintf(out,"\"");
		while (qAux->prim != NULL){

			void *ae = malloc(qAux->dime);
			extrq(qAux,ae);
			f(ae,out);
			intrq(a[i],ae);
			free(ae);
		}
		
		fprintf(out,"\"\n");
		free(qAux);
	}


}
void DistrQ(ACoada *q){

	while ((*q)->prim != NULL){

		void *ae = malloc((*q)->dime);
		extrq(*q,ae);
		free(ae);

	}
	free(*q);
	*q = NULL;



}
