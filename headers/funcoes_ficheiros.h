#ifndef FUNCOES_FICHEIROS_H_INCLUDED
#define FUNCOES_FICHEIROS_H_INCLUDED

#include "constantes.h"

tipoAcessoAula *lerFicheiroBinarioAcessoAulas(tipoAcessoAula acessosAulas[], int *numAcessos);
void escreverLogBinarioAcessosAulas(tipoAcessoAula acessosAulas[], int numAcessos);
void adicionarLogTextoAcessoAulas(tipoAcessoAula acessoAula);
tipoAulaOnline *lerFiheiroBinarioAulasOnline(tipoAulaOnline aulasOnline[], int *numAulas, int *numAulasTerminadas, int *numAulasGravadas);
void escreverFiheiroBinarioAulasOnline(tipoAulaOnline aulasOnline[], int numAulas);
void lerFiheiroBinarioUC(tipoUnidadeCurricular uniCurriculares[], int *numUCs);
void escreverFiheiroBinarioUC(tipoUnidadeCurricular uniCurriculares[], int numUCs);

#endif // FUNCOES_FICHEIROS_H_INCLUDED
