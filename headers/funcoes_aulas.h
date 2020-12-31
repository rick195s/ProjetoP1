#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include "constantes.h"

void listarAulasOnline(tipoAulaOnline aulaOnline);
int quantidadeAulasTipo(tipoUnidadeCurricular uniCurricular, int tipoAula, tipoAulaOnline aulasOnline[], int numAulas);
tipoData lerData();
tipoAulaOnline lerDadosAulaOnline(tipoUnidadeCurricular uniCurricular, tipoAulaOnline aulasOnline[], int numAulas);
int agendarAulaOnline(tipoAulaOnline aulasOnline[], int numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs);


#endif // FUNCOES_AULAS_H_INCLUDED
