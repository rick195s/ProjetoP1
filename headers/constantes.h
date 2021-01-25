#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#define MAX_UC 40
#define TIPOS_AULA 3
#define MAX_STRING 50
#define MAX_ESTUDANTES 100
#define MAX_MENU_OPCOES 15
#define MAX_STRING_FRASE 100
#define MAX_DURACAO_AULA_DIURNO 600
#define MAX_DURACAO_AULA_POS_LABORAL 240
#define MAX_AULAS_POR_TIPO 150

/*
ESTRUTUA DOS ACESSOS A UMA AULA
*/
typedef struct{

    int numeroEstudante;
    int tipoAcesso;
    char designacaoAula[MAX_STRING];

}tipoAcessoAula;

/*
ESTRUTURA DA DATA
*/
typedef struct
{

    int dia;
    int mes;
    int ano;

} tipoData;

/*
ESTRUTURA DE UM TIPO DE AULAS
*/
typedef struct
{
    char designacao[MAX_STRING];
    int quantidade;
    int duracao;

} tipoAulas;


/*
ESTRUTURA DAS AULAS ONLINE
*/
typedef struct
{

    int codigoUC;
    char designacao[MAX_STRING];
    int tipoAula;
    char nomeDocente[MAX_STRING];
    tipoData data;
    float horaInicio;
    float horaFim;
    int estado;
    int gravada;


} tipoAulaOnline;


/*
ESTRUTURA DAS UNIDADES CURRICULARES
*/
typedef struct
{

    int codigo;
    char designacao[MAX_STRING];
    int tipoUC;
    int semestre;
    int regime;
    tipoAulas aulasOnline[TIPOS_AULA];

} tipoUnidadeCurricular;


#endif // CONSTANTES_H_INCLUDED
