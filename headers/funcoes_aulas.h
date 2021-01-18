#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include "constantes.h"
void gravarAulaOnline(tipoAulaOnline *aulaOnline);
void terminarAulaOnline(tipoAulaOnline *aulaOnline);
void iniciarAulaOnline(tipoAulaOnline *aulaOnline);
void administradorAulaOnline(tipoAulaOnline aulasOnline[], int numAulas);
tipoAulaOnline *editarAulaOnline(tipoAulaOnline aulasOnline[],int *numAulas,tipoUnidadeCurricular uniCurriculares[],int numUCs);
int procurarDesignacaoAula(tipoAulaOnline aulasOnline[], int numAulas, char designacao[MAX_STRING]);
void lerHorarioCompletoAula(tipoUnidadeCurricular uniCurricular, tipoAulaOnline *aulaOnline, tipoAulaOnline aulasOnline[], int numAulas);
int verificarHorarioAula(tipoAulaOnline aulasOnline[], int numAulas, tipoAulaOnline aulaOnline);
float formatarHoraComDuracaoAula(int duracao, float hora, int sinal);
float lerHoraAula(float inicio, float fim);
void listarInformacoesUCdaAula(tipoAulaOnline aulasOnline[], int numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAcessoAula acessosAula[], int numAcessos);
void listarAulaOnline(tipoAulaOnline aulaOnline,tipoAcessoAula acessosAula[], int numAcessos);
int quantidadeAulasTipo(tipoUnidadeCurricular uniCurricular, int tipoAula, tipoAulaOnline aulasOnline[], int numAulas, int op);
tipoAulaOnline lerDadosAulaOnline(tipoUnidadeCurricular uniCurricular, tipoAulaOnline aulasOnline[], int numAulas);
tipoAulaOnline *agendarAulaOnline(tipoAulaOnline aulasOnline[],int *numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs);


#endif // FUNCOES_AULAS_H_INCLUDED
