#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stiva.h"
#include "coada.h"
#include "lista.h"
#include "paranteza.h"
void AfiParanteza(void *a,FILE *out){

	TParanteza *p = (TParanteza *)a;
	fprintf(out,"%c",p->tip);
}
int comparId(void *a, void *b){

	int x = ((TParanteza *)a)->id;
	int y = ((TParanteza *)b)->id;
	return x - y;
}
int main(int argc, char *argv[]){
		
	int N,nrSt,nrQ;
	FILE *input = fopen(argv[1],"rt");
	if (!input){
		printf("nu se deschide fisier intrare\n");
		return -1;
	}
	FILE *output = fopen(argv[2],"wt");
	if (!output){
		printf("nu se deschide fisier iesire\n");
		return -1;
	}
	fscanf(input,"%d %d %d",&N,&nrSt,&nrQ);
	VectorSt st = (VectorSt)malloc(nrSt*sizeof(ASt));
	VectorQ q = (VectorQ)malloc(nrQ*sizeof(ACoada));
	int i;
	for (i = 0; i < nrSt; i++){
		st[i] = InitSt(sizeof(TParanteza));
	}
	for (i = 0; i < nrQ; i++){
		q[i] = InitQ(sizeof(TParanteza));
	}
	for (i = 0; i < N; i++){

		char op[10];
		fscanf(input,"%s",op);
		if (!strcmp("push",op)){
			int indexSt;
			TParanteza *p = (TParanteza *)malloc(sizeof(TParanteza));
			fscanf(input,"%d %d  %c\n",&indexSt,&(p->id),&(p->tip));
			push(st[indexSt],p);
			free(p);

		}else if (!strcmp(op,"pop")){

			int indexSt;
			fscanf(input,"%d",&indexSt);
			void *ae = malloc(st[indexSt]->dime);
			pop(st[indexSt],ae);
			free(ae);

		}else if (!strcmp(op,"sorts")){

			int indexSt;
			fscanf(input,"%d",&indexSt);
			sorts(st[indexSt],comparId);			
		}else if (!strcmp("prints",op)){
			prints(st,nrSt,AfiParanteza,output);
		}else if (!strcmp(op,"corrects")){
			int indexSt;
			fscanf(input,"%d",&indexSt);
			fprintf(output,"%d\n",corrects(st[indexSt]));
		}else if (!strcmp(op,"intrq")){

			int indexQ;
			TParanteza *p = (TParanteza *)malloc(sizeof(TParanteza));
			fscanf(input,"%d %d %c\n",&indexQ,&(p->id),&(p->tip));
			intrq(q[indexQ],p);
			free(p);
		}else if (!strcmp(op,"extrq")){

			int indexQ;
			fscanf(input,"%d",&indexQ);
			void *ae = malloc(q[indexQ]->dime);
			extrq(q[indexQ],ae);
			free(ae);
		}else if (!strcmp(op,"sortq")){
			
			int indexQ;
			fscanf(input,"%d",&indexQ);
			sortq(q[indexQ],comparId);
		}else if (!strcmp(op,"printq")){
			printq(q,nrQ,AfiParanteza,output);
		}else if (!strcmp(op,"correctq")){
			int indexQ;
			fscanf(input,"%d",&indexQ);
			fprintf(output,"%d\n",correctq(q[indexQ]));
		}


	}	
	for (i = 0; i < nrSt; i++)
		DistrSt(&st[i]);
	for (i = 0; i < nrQ; i++)
		DistrQ(&q[i]);
	free(st);
	free(q);
	fclose(input);
	fclose(output);

	return 0;
}
