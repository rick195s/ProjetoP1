#ifndef FUNCOES_ESTATISTICAS_H_INCLUDED
#define FUNCOES_ESTATISTICAS_H_INCLUDED

float mediaDePresencasAula(tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAula[], int numAcessos);
void listarUCMenosAulasOnline(tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas);
int percentagemUCsAulasGravadas(tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas);
void tipoAulaGravacoes(tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAulas[], int numAcessos, char vetorCaracteres[MAX_STRING]);

#endif // FUNCOES_ESTATISTICAS_H_INCLUDED
