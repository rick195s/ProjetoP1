#ifndef FUNCOES_UC_H_INCLUDED
#define FUNCOES_UC_H_INCLUDED

#include "constantes.h"

int gerarCodigoUnico(tipoUnidadeCurricular uniCurriculares[], int numUCs);
tipoUnidadeCurricular lerDadosUC();
int inserirUCs(tipoUnidadeCurricular uniCurriculares[], int numUCs);
void alterarUC(tipoUnidadeCurricular uniCurriculares[], int numUCs);
int prourarUC(tipoUnidadeCurricular uniCurriculares[], int numUCs);
void listarUC(tipoUnidadeCurricular uniCurricular, int detalhes);

#endif // FUNCOES_UC_H_INCLUDED
