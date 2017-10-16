#include "stiva.h"
#include "coada.h"
int corrects(void *as){
	ASt s = (ASt)as;
        int lungMax = 0;
        ASt sAux = InitSt(s->dime);
        ASt sP = InitSt(sizeof(TInSecv));
        int nrCont = 0;
        while (s->varf != NULL){
                void *ae = malloc(s->dime);
                pop(s,ae);
                push(sAux,ae);
                char *p = malloc(sizeof(1));
                *p = ((TParanteza *)ae)->tip;
                free(ae);
                if (*p == '(' || *p == '[' ||
                        *p == '{'){

                        if (sP->varf == NULL){

                               nrCont = 0;

                        }else{

                                if (*p == '(' && (((TInSecv *)sP->varf->info)->tip) != ')'){

                                        nrCont = 0;
                                        DistrSt(&sP);
                                        sP = InitSt(sizeof(TInSecv));

                                }else if (*p == '('){

                                        TInSecv *t = malloc(sizeof(TInSecv));
                                        pop(sP,t);
                                        free(t);
                                        nrCont = nrCont + 2;

                                }else if (*p == '[' && (((TInSecv *)sP->varf->info)->tip) != ']'){
                                        nrCont = 0;
                                        DistrSt(&sP);
                                        sP = InitSt(sizeof(TInSecv));

                                }else if (*p == '['){
                                        TInSecv *t = malloc(sizeof(TInSecv));
                                        pop(sP,t);
                                        free(t);
                                        nrCont = nrCont + 2;
                                }else if (*p == '{' &&  (((TInSecv *)sP->varf->info)->tip) != '}'){
                                        nrCont = 0;
                                        DistrSt(&sP);
                                        sP = InitSt(sizeof(TInSecv));
                                }else if (*p == '{'){
                                        TInSecv *t = malloc(sizeof(TInSecv));
                                        pop(sP,t);
                                        free(t);
                                        nrCont = nrCont + 2;
                                }
                        }


                }else{
                        TInSecv *aux = malloc(sizeof(TInSecv));
                        aux->tip = *p;
                        aux->nrDisc = nrCont;
                        push(sP,aux);
                        free(aux);
                }
		free(p);
                int deScazut = 0;
                if (sP->varf != NULL)
                        deScazut = ((TInSecv *)sP->varf->info)->nrDisc;
                if (nrCont - deScazut > lungMax)
                        lungMax = nrCont - deScazut;

        }


        DistrSt(&sP);
        MutaSt(s,sAux);
        DistrSt(&sAux);
        return lungMax;


}
int correctq(void *aq){


	ACoada q = (ACoada)aq;
	int lungMax = 0;
	ACoada qAux = InitQ(q->dime);
	ASt sP = InitSt(sizeof(TInSecv));
	int nrCont = 0;
	while (q->prim != NULL){
	
		void *ae = malloc(q->dime);
		extrq(q,ae);
		intrq(qAux,ae);
                char *p = malloc(sizeof(1));
                *p = ((TParanteza *)ae)->tip;
                free(ae);
                if (*p == ')' || *p == ']' ||
                        *p == '}'){

                        if (sP->varf == NULL){

                               nrCont = 0;

                        }else{

                                if (*p == ')' && (((TInSecv *)sP->varf->info)->tip) != '('){

                                        nrCont = 0;
                                        DistrSt(&sP);
                                        sP = InitSt(sizeof(TInSecv));

                                }else if (*p == ')'){

                                        TInSecv *t = malloc(sizeof(TInSecv));
                                        pop(sP,t);
                                        free(t);
                                        nrCont = nrCont + 2;

                                }else if (*p == ']' && (((TInSecv *)sP->varf->info)->tip) != '['){
                                        nrCont = 0;
                                        DistrSt(&sP);
                                        sP = InitSt(sizeof(TInSecv));

                                }else if (*p == ']'){
                                        TInSecv *t = malloc(sizeof(TInSecv));
                                        pop(sP,t);
                                        free(t);
                                        nrCont = nrCont + 2;
                                }else if (*p == '}' &&  (((TInSecv *)sP->varf->info)->tip) != '{'){
                                        nrCont = 0;
                                        DistrSt(&sP);
                                        sP = InitSt(sizeof(TInSecv));
                                }else if (*p == '}'){
                                        TInSecv *t = malloc(sizeof(TInSecv));
                                        pop(sP,t);
                                        free(t);
                                        nrCont = nrCont + 2;
                                }
                        }



                }else{
                        TInSecv *aux = malloc(sizeof(TInSecv));
                        aux->tip = *p;
                        aux->nrDisc = nrCont;
                        push(sP,aux);
                        free(aux);
                }
		free(p);
                int deScazut = 0;
                if (sP->varf != NULL)
                        deScazut = ((TInSecv *)sP->varf->info)->nrDisc;
                if (nrCont - deScazut > lungMax)
                        lungMax = nrCont - deScazut;

        }


        DistrSt(&sP);
        MutaQ(q,qAux);
        DistrQ(&qAux);
        return lungMax;

		
}

