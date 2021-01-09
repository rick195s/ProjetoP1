#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include "constantes.h"

tipoAulaOnline *editarAulaOnline(tipoAulaOnline aulasOnline[],int *numAulas,tipoUnidadeCurricular uniCurriculares[],int numUCs);
float formatarHoraComDuracaoAula(int duracao, float hora, int sinal);
int verificarHorarioAula(tipoAulaOnline aulasOnline[], int numAulas, tipoAulaOnline aulaOnline);
int procurarDesignacaoAula(tipoAulaOnline aulasOnline[], int numAulas, char designacao[MAX_STRING]);
float lerHoraAula(float inicio, float fim);
void lerHorarioCompletoAula(tipoUnidadeCurricular uniCurricular, tipoAulaOnline *aulaOnline, tipoAulaOnline aulasOnline[], int numAulas);
void listarAulasOnline(tipoAulaOnline aulaOnline);
int verificarQuantidadeAulasTipo(tipoUnidadeCurricular uniCurricular, int tipoAula, tipoAulaOnline aulasOnline[], int numAulas, int todosTipo);
tipoAulaOnline lerDadosAulaOnline(tipoUnidadeCurricular uniCurricular, tipoAulaOnline aulasOnline[], int numAulas);
tipoAulaOnline *agendarAulaOnline(tipoAulaOnline aulasOnline[],int *numAulas, tipoUnidadeCurricular uniCurriculares[], int numUCs);


#endif // FUNCOES_AULAS_H_INCLUDED
