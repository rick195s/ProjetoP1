#ifndef FUNCOES_ACESSOS_H_INCLUDED
#define FUNCOES_ACESSOS_H_INCLUDED
#include "constantes.h"

/*
FUNCAO QUE DEVOLVE A QUANTIDADE DE ACESSOS DO TIPO "acesso" A UMA AULA ONLINE
*/

int quantidadeAcessosAula(tipoAulaOnline aulaOnline, tipoAcessoAula acessosAulas[], int numAcessos, int acesso);

/*
FUNCAO QUE LISTA UMA AULA ONLINE INDIVIDUALMENTE
*/
void listarAcessosAulas(tipoAcessoAula acessoAula);

/*
FUNCOES QUE ALTERAM O VETOR DOS ACESSOS AS AULAS
*/
tipoAcessoAula acrescentarDadosAcesso(tipoAulaOnline aulaOnline);
tipoAcessoAula *acessoAulaEstudante(tipoAcessoAula acessosAulas[], int *numAcessos, tipoAulaOnline aulasOnline[], int numAulas);


#endif // FUNCOES_ACESSOS_H_INCLUDED
