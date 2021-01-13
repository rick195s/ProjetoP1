#ifndef FUNCOES_ACESSOS_H_INCLUDED
#define FUNCOES_ACESSOS_H_INCLUDED
#include "constantes.h"

void listarAcessosAulas(tipoAcessoAula acessoAula);
tipoAcessoAula acrescentarDadosAcesso(tipoAcessoAula acessosAulas[], tipoAulaOnline aulaOnline);
tipoAcessoAula *acessoAulaEstudante(tipoAcessoAula acessosAulas[], int *numAcessos, tipoAulaOnline aulasOnline[], int numAulas);


#endif // FUNCOES_ACESSOS_H_INCLUDED
