#ifndef FUNCOES_UC_H_INCLUDED
#define FUNCOES_UC_H_INCLUDED

#include "constantes.h"

/*
FUNCOES PARA A ORDENACAO E LISTAGEM DO RANKING DAS UCS
*/
void ordenarVetorUC(tipoUnidadeCurricular uniCurriculares[], int numUCs, int quantidadeAcessosUC[]);
void rankingUC(tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAula[], int numAcessos);

/*
FUNCAO PARA LISTAR UMA UC
*/
void listarUC(tipoUnidadeCurricular uniCurricular,tipoAulaOnline aulasOnline[], int numAulas);

/*
FUNCAO PARA PROCURAR UMA UC ATRAVES DO SEU CODIGO UNICO
*/
int procurarUC(int codigoUC, tipoUnidadeCurricular uniCurriculares[], int numUCs);

/*
FUNCOES PARA ADICIONAR DADOS AS ELEMENTOS DAS ESTRUTURAS
*/
int gerarCodigoUnico(tipoUnidadeCurricular uniCurriculares[], int numUCs);
void lerUCTipoAulas(tipoAulas tipoAulas[]);
tipoUnidadeCurricular lerDadosUC();

/*
FUNCOES QUE IRAM ALTERAR O VETOR DAS UC
*/
void alterarUC(tipoUnidadeCurricular uniCurriculares[], int numUCs);
int inserirUCs(tipoUnidadeCurricular uniCurriculares[], int numUCs);


#endif // FUNCOES_UC_H_INCLUDED
