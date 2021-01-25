#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include "constantes.h"

/*
FUNCAO PARA PROCURAR UMA AULA ONLINE PELA SUA DESGINACAO
*/

int procurarDesignacaoAula(tipoAulaOnline aulasOnline[], int numAulas, char designacao[MAX_STRING]);

/*
FUNCOES RELACIONADAS COM A LISTAGEM DE AULAS ONLINE
*/
void listarAulaOnline(tipoAulaOnline aulaOnline,tipoAcessoAula acessosAula[], int numAcessos);
void listarInformacoesUCdaAula(tipoAulaOnline aulasOnline[], int numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAcessoAula acessosAula[], int numAcessos);

int quantidadeAulasTipo(tipoUnidadeCurricular uniCurricular, int tipoAula, tipoAulaOnline aulasOnline[], int numAulas, int op);

/*
FUNOCES PARA LER E VERIFICAR DADOS DAS AULAS ONLINE
*/

int verificarHorarioAula(tipoAulaOnline aulasOnline[], int numAulas, tipoAulaOnline aulaOnline);
float lerHoraAula(float inicio, float fim);
float formatarHoraComDuracaoAula(int duracao, float hora, int sinal);
void lerHorarioCompletoAula(tipoUnidadeCurricular uniCurricular, tipoAulaOnline *aulaOnline, tipoAulaOnline aulasOnline[], int numAulas);
tipoAulaOnline lerDadosAulaOnline(tipoUnidadeCurricular uniCurricular, tipoAulaOnline aulasOnline[], int numAulas);

/*
FUNCOES PARA A ALTERACAO DE ALGUM CAMPO DO VETOR DAS AULAS OU ALTERAR O VETOR DAS AULAS
*/
tipoAulaOnline *agendarAulaOnline(tipoAulaOnline aulasOnline[],int *numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs);
tipoAulaOnline *editarAulaOnline(tipoAulaOnline aulasOnline[],int *numAulas,tipoUnidadeCurricular uniCurriculares[],int numUCs);
void listarEstudantesPresentes(tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAulas[], int numAcessos);
void gravarAulaOnline(tipoAulaOnline *aulaOnline,int *numAulasGravadas);
void terminarAulaOnline(tipoAulaOnline *aulaOnline,int *numAulasTerminadas);
void iniciarAulaOnline(tipoAulaOnline *aulaOnline);
void administradorAulaOnline(tipoAulaOnline aulasOnline[], int numAulas, int *numAulasTerminadas,int *numAulasGravadas);

/*
FUNCAO PARA ORDENAR O VETOR DAS AULAS REALIZADAS DA MAIS ANTIGA PARA A MAIS NOVA
*/
void ordenarAulaAntigas(tipoAulaOnline aulasOnline[], int numAulas);

#endif // FUNCOES_AULAS_H_INCLUDED
