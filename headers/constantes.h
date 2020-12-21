#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#define MAX_UC 40
#define TIPOS_AULA 3
#define MAX_STRING 50
#define MAX_ESTUDANTES 100
#define MAX_MENU_OPCOES 15
#define MAX_STRING_FRASE 100

/*
typedef struct{

    char op[1];
    char opFrase[MAX_STRING_FRASE];



}tipoMenu;*/

typedef struct{

    int codigoAula;
    int numeroAluno;

}tipoAcessoGravacoes;

typedef struct
{

    int dia;
    int mes;
    int ano;

} tipoData;

typedef struct
{

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
    int horaInicio;
    int horaFim;
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
    tipoAulas tipoAulaOnline[TIPOS_AULA];

} tipoUnidadeCurricular;

typedef struct
{
    char nome[MAX_STRING];
    int numero;

} tipoEstudante;

#endif // CONSTANTES_H_INCLUDED
