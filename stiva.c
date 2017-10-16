#include "stiva.h"
#include "lista.h"
ASt InitSt(size_t dime){
	ASt s = (ASt)malloc(sizeof(TStiva));
	if (!s){
		printf("eroare la alocare stiva");
		return NULL;
	}
	s->dime = dime;
	s->varf = NULL;
	return s;
}
int push(ASt s,void *ae){

	TLG aux = (TLG)malloc(sizeof(TCelulaG));
	if (!aux){
		printf("eroare la adaugare element in stiva");
		return 0;
	}
	aux->info = malloc(s->dime);
	memcpy(aux->info,ae,s->dime);
	aux->urm = s->varf;
	s->varf = aux;
	return 1;
}
int pop(ASt s,void *ae){
	if (s->varf == NULL)
		return 0;

	TLG aux = s->varf;
	s->varf = s->varf->urm;
	memcpy(ae,aux->info,s->dime);
	free(aux->info);
	free(aux);
	return 1;	

}
void MutaSt(ASt ad,ASt as){

	while(as->varf != NULL){

		void *ae = malloc(ad->dime);
		pop(as,ae);
		push(ad,ae);
		free(ae);
	}


}
void sorts(ASt s,TFCmp f){

	ASt sAux = InitSt(s->dime);
	while (s->varf != NULL){
		void *ae = malloc(s->dime);
		pop(s,ae);
		if (sAux->varf == NULL){
			push(sAux,ae);
			
		}else{
		
			if (f(sAux->varf->info,ae) > 0){
				push(sAux,ae);
			}else{

				while (sAux->varf != NULL && 
						f(sAux->varf->info,ae) < 0){
					void *el = malloc(s->dime);
					pop(sAux,el);
					push(s,el);
					free(el);		
				}
				push(sAux,ae);
			}
		}
		free(ae);

	}
	MutaSt(s,sAux);
	free(sAux);

}
void prints(VectorSt a,size_t n,TFAfi f,FILE *out){


	int i;
	for (i = 0; i < n; i++){

		
		ASt sAux = InitSt(a[i]->dime);
		MutaSt(sAux,a[i]);
		fprintf(out,"\"");
		while (sAux->varf != NULL){

			void *ae = malloc(sAux->dime);
			pop(sAux,ae);
			f(ae,out);
			push(a[i],ae);
			free(ae);

		}
		fprintf(out,"\"");
		fprintf(out,"\n");
		free(sAux);
	}
	
}
void DistrSt(ASt *s){

	while((*s)->varf != NULL){

		void *ae = malloc((*s)->dime);
		pop(*s,ae);
		free(ae);
	}

	free(*s);
	*s = NULL;
}

