#ifndef FUNCOES_MENUS_H_INCLUDED
#define FUNCOES_MENUS_H_INCLUDED

#include "constantes.h"

char menuEstatisticas(tipoUnidadeCurricular uniCurriculres[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAulas[], int numAcessos);
char menuAdministradorAula();
char menuAulas();
char menuUC();
char menuPrincipal(int numUCs, int numAcessos, int numAulas,int numAulasTerminadas,int numAulasGravadas);



#endif // FUNCOES_MENUS_H_INCLUDED
