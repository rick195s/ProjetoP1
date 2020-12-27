#ifndef FUNCOES_UC_H_INCLUDED
#define FUNCOES_UC_H_INCLUDED

#include "constantes.h"

int gerarCodigoUnico(tipoUnidadeCurricular uniCurriculares[], int numUCs);
void lerUCTipoAulas(tipoAulas tipoAulas[]);
tipoUnidadeCurricular lerDadosUC();
int inserirUCs(tipoUnidadeCurricular uniCurriculares[], int numUCs);
void alterarUC(tipoUnidadeCurricular uniCurriculares[], int numUCs);
int procurarUC(tipoUnidadeCurricular *uniCurricular, int codigoUC, int devolverUC);
void listarUC(tipoUnidadeCurricular uniCurricular, int detalhes);
void obterUC(tipoUnidadeCurricular *uniCurricular, int posicao);

#endif // FUNCOES_UC_H_INCLUDED
