#ifndef FUNCOES_FICHEIROS_H_INCLUDED
#define FUNCOES_FICHEIROS_H_INCLUDED

#include "constantes.h"

/*
FUNCOES PARA A LEITURA DE DADOS DOS RESPETIVOS FICHEIROS
*/
tipoAcessoAula *lerFicheiroBinarioAcessoAulas(tipoAcessoAula acessosAulas[], int *numAcessos);
tipoAulaOnline *lerFiheiroBinarioAulasOnline(tipoAulaOnline aulasOnline[], int *numAulas, int *numAulasTerminadas, int *numAulasGravadas);
void lerFiheiroBinarioUC(tipoUnidadeCurricular uniCurriculares[], int *numUCs);

/*
FUNCOES PARA A ESCRITA DE DADOS NOS RESPETIVOS FICHEIROS
*/
void escreverLogBinarioAcessosAulas(tipoAcessoAula acessosAulas[], int numAcessos);
void escreverFiheiroBinarioAulasOnline(tipoAulaOnline aulasOnline[], int numAulas);
void escreverFiheiroBinarioUC(tipoUnidadeCurricular uniCurriculares[], int numUCs);

/*
FUNCAO PARA ADICIONAR AO FICHEIRO LOG OS RESPETIVOS DADOS
*/
void adicionarLogTextoAcessoAulas(tipoAcessoAula acessoAula);

#endif // FUNCOES_FICHEIROS_H_INCLUDED
