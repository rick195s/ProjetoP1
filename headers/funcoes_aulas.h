#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include "constantes.h"

int quantidadeAulasTipo(tipoUnidadeCurricular uniCurricular,int tipoAula);
tipoData lerData();
tipoAulaOnline lerDadosAulaOnline();
int agendarAulaOnline(tipoAulaOnline aulasOnline[], int numAulas);


#endif // FUNCOES_AULAS_H_INCLUDED
