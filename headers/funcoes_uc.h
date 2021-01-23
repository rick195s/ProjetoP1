#ifndef FUNCOES_UC_H_INCLUDED
#define FUNCOES_UC_H_INCLUDED

#include "constantes.h"

void ordenarVetorUC(tipoUnidadeCurricular uniCurriculares[], int numUCs, int quantidadeAcessosUC[]);
void rankingUC(tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAula[], int numAcessos);
void listarUC(tipoUnidadeCurricular uniCurricular,tipoAulaOnline aulasOnline[], int numAulas);
int procurarUC(int codigoUC, tipoUnidadeCurricular uniCurriculares[], int numUCs);
void alterarUC(tipoUnidadeCurricular uniCurriculares[], int numUCs);
int gerarCodigoUnico(tipoUnidadeCurricular uniCurriculares[], int numUCs);
void lerUCTipoAulas(tipoAulas tipoAulas[]);
tipoUnidadeCurricular lerDadosUC();
int inserirUCs(tipoUnidadeCurricular uniCurriculares[], int numUCs);


#endif // FUNCOES_UC_H_INCLUDED
