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


typedef struct{

    int numeroEstudante;
    int tipoAcesso;
    char designacaoAula[MAX_STRING];

}tipoAcessoAula;

typedef struct{

    int codigoAula;
    int numeroAluno;

}tipoAcessoGravacoes;

typedef struct{

    int hora;
    int minutos;

}tipoHora;

typedef struct
{

    int dia;
    int mes;
    int ano;

} tipoData;

typedef struct
{
    char designacao[MAX_STRING];
    int quantidade;
    int duracao;

} tipoAulas;

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

typedef struct
{

    int codigo;
    char designacao[MAX_STRING];
    int tipoUC;
    int semestre;
    int regime;
    tipoAulas aulasOnline[TIPOS_AULA];

} tipoUnidadeCurricular;

typedef struct
{
    char nome[MAX_STRING];
    int numero;

} tipoEstudante;

#endif // CONSTANTES_H_INCLUDED
