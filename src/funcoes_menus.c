
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "../headers/funcoes_menus.h"
#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_auxiliares.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/constantes.h"
#include "../headers/funcoes_estatisticas.h"


char menuEstatisticas(tipoUnidadeCurricular uniCurriculres[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAulas[], int numAcessos)
{

    char op, tipoDeAula[MAX_STRING];
    float mediaPesencas;
    int percentagemUCsGravadas;

    mediaPesencas=mediaDePresencasAula(aulasOnline, numAulas, acessosAulas, numAcessos);
    percentagemUCsGravadas=percentagemUCsAulasGravadas(uniCurriculres, numUCs, aulasOnline, numAulas);
    tipoAulaGravacoes(aulasOnline,numAulas,acessosAulas,numAcessos,tipoDeAula);

    printf("\n--------------------------- Estatisticas ---------------------------");

    printf("\n\nTipo de Aulas com mais acessos as gravacoes: %s",tipoDeAula);
    printf("\n\nMedia de presencas por cada aula realizada: %.2f",mediaPesencas);
    printf("\n\nPercentagem de UCs com aulas gravadas: %d%%",percentagemUCsGravadas);
    printf("\n\nQ - Mostrar UCs com menor quantidade de aulas online realizadas");
    printf("\n\nR - Mostrar aulas online realizadas ha mais tempo");
    printf("\n\nV - Voltar atras\n\nOpcao--> ");

    scanf("%c", &op);
    op=toupper(op);
    limpaBufferStdin();


    return op;
}


char menuAdministradorAula()
{

    char op;


    printf("\n--------------------------- Administrador da Aula Online ---------------------------");



    printf("\n\nI - Iniciar Aula Online");
    printf("\n\nT - Terminar Aula Online");
    printf("\n\nG - Gravar Aula Online");
    printf("\n\nV - Voltar atras\n\nOpcao--> ");

    scanf("%c", &op);
    op=toupper(op);
    limpaBufferStdin();


    return op;

}

char menuAulas()
{

    char op;


    printf("\n--------------------------- Menu das Aulas Online ---------------------------");



    printf("\n\nA - Agendar Aula Online");
    printf("\n\nE - Editar agendamento ou eliminar Aula Online");
    printf("\n\nI - Entrar na Aula Online como administrador");
    printf("\n\nQ - Listar Aula Online com informacao da UC");
    printf("\n\nH - Listar Alunos presentas na Aula Online");
    printf("\n\nL - Listar Todas as Aulas Online");
    printf("\n\nV - Voltar atras\n\nOpcao--> ");

    scanf("%c", &op);
    op=toupper(op);
    limpaBufferStdin();


    return op;

}

char menuUC()
{

    char op;


    printf("\n--------------------------- Menu Unidade Curriular ---------------------------");



    printf("\n\nI - Inserir UCs");
    printf("\n\nA - Alterar UC");
    printf("\n\nL - Listar UC");
    printf("\n\nR - Ranking de UCs");
    printf("\n\nV - Voltar atras\n\nOpcao--> ");

    scanf("%c", &op);
    op=toupper(op);
    limpaBufferStdin();


    return op;

}

char menuPrincipal(int numUCs, int numAcessos, int numAulas,int numAulasTerminadas,int numAulasGravadas)
{
    char op;

    printf("\n* Numero de UCs: %d *\t\t\t* Numero de Acessos a aulas: %d\n", numUCs, numAcessos);
    printf("\n* Numero de aulas agendadas: %d *\t* Numero de aulas realizadas: %d \n", numAulas,numAulasTerminadas);
    printf("\n* Numero de aulas gravadas: %d *",numAulasGravadas);
    printf("\n\n--------------------------- Menu Principal ---------------------------");
    printf("\n\nU - Inserir, Alterar ou Listar informacoes de UCs");
    printf("\n\nA - Agendar, Alterar, Listar aulas online ou Registar estado de aulas");
    printf("\n\nE - Entrar numa aula");
    printf("\n\nL - Mostrar Estatisticas");
    printf("\n\nF - Fim\n\nOpcao--> ");

    scanf("%c", &op);
    op=toupper(op);
    limpaBufferStdin();


    return op;

}

