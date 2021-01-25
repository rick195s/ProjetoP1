#ifndef FUNCOES_ESTATISTICAS_H_INCLUDED
#define FUNCOES_ESTATISTICAS_H_INCLUDED

/*
FUNCAO QUE DEVOLVE A MEDIA DAS PRESENCAS EM CADA AULA ONLINE
*/
float mediaDePresencasAula(tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAula[], int numAcessos);

/*
FUNCAO QUE VAI LISTAR AS UC COM MENOS AULAS ONLINE
*/
void listarUCMenosAulasOnline(tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas);

/*
FUNCAO QUE VAI DEVOLVER A PERCENTAGEM DE UC COM AULAS GRAVADAS
*/
int percentagemUCsAulasGravadas(tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas);

/*
FUNCAO QUE VAI DEVOLVER PARA "vetorCarateres" QUAL O TIPO DE AULAS COM MAIS ACESSOS AS GRAVACOES
*/
void tipoAulaGravacoes(tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAulas[], int numAcessos, char vetorCaracteres[MAX_STRING]);

#endif // FUNCOES_ESTATISTICAS_H_INCLUDED
