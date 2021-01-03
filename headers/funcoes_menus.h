#ifndef FUNCOES_MENUS_H_INCLUDED
#define FUNCOES_MENUS_H_INCLUDED

#include "constantes.h"

char menuPrincipal();
void menuUC(tipoUnidadeCurricular uniCurriculares[], int *numUCs);
tipoAulaOnline *menuAulas(tipoAulaOnline aulasOnline[],int *numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs);


#endif // FUNCOES_MENUS_H_INCLUDED
