#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/funcoes_acessos.h"
#include "../headers/constantes.h"
#include "../headers/funcoes_auxiliares.h"
#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_ficheiros.h"

int quantidadeAcessosAula(tipoAulaOnline aulaOnline, tipoAcessoAula acessosAulas[], int numAcessos, int acesso)
{
    /*
    Esta funcao tem a responsabilidade de devolver a quantidade de acessos do tipo "acesso"
    existentes
    */

    int i, quantidadeAcessos=0;


    for(i=0; i<numAcessos; i++)
    {

        if(strcmp(acessosAulas[i].designacaoAula, aulaOnline.designacao) == 0 && acessosAulas[i].tipoAcesso == acesso)
        {
            quantidadeAcessos++;
        }
    }

    return quantidadeAcessos;
}

void listarAcessosAulas(tipoAcessoAula acessoAula)
{


    printf("\n\nNumero do estudante: %d", acessoAula.numeroEstudante);
    printf("\n\nDesignacao da aula: %s", acessoAula.designacaoAula);
    if(acessoAula.tipoAcesso == 0)
    {
        printf("\n\nTipo de acesso: Online");

    }
    else
    {
        printf("\n\nTipo de acesso: Offline");

    }
}

tipoAcessoAula acrescentarDadosAcesso( tipoAulaOnline aulaOnline)
{

    tipoAcessoAula acessoAula;

    acessoAula.numeroEstudante = lerInteiro("\n\nInsira o seu numero de estudante: ", 1000, 9999);
    strcpy(acessoAula.designacaoAula, aulaOnline.designacao);

    if(aulaOnline.estado == 1)
    {
        acessoAula.tipoAcesso = 0;
    }
    else
    {
        acessoAula.tipoAcesso = 1;
    }
    adicionarLogTextoAcessoAulas(acessoAula);

    return acessoAula;
}

tipoAcessoAula *acessoAulaEstudante(tipoAcessoAula acessosAulas[], int *numAcessos, tipoAulaOnline aulasOnline[], int numAulas)
{

    char designacao[MAX_STRING];
    int posicaoAula;
    tipoAcessoAula *aux;

    aux=acessosAulas;
    system("@cls||clear");
    lerString("\n\nInsira a designacao da aula a que pretender aceder: ",designacao,MAX_STRING);

    posicaoAula=procurarDesignacaoAula(aulasOnline,numAulas,designacao);

    if(posicaoAula == -1 || aulasOnline[posicaoAula].estado == 0 || (aulasOnline[posicaoAula].estado == 2 && aulasOnline[posicaoAula].gravada == 0 ))
    {
        if(posicaoAula == -1)
        {
            mostrarMensagem("Nao existe nenhuma aula com a desginacao que introduziu",0);
        }
        else if(aulasOnline[posicaoAula].estado == 0)
        {
            mostrarMensagem("A aula que pretende assistir ainda nao comecou",0);
        }
        else
        {
            mostrarMensagem("Nao pode aceder a aula porque ja terminou e nao foi gravada",0);
        }

    }
    else
    {

        acessosAulas=realloc(acessosAulas, (*numAcessos+1)*sizeof(tipoAcessoAula));

        if(acessosAulas == NULL)
        {
            acessosAulas=aux;
            mostrarMensagem("Ococrreu um erro para reservar memoria ao adicionar acesso a aula",0);
        }
        else
        {

            acessosAulas[*numAcessos] = acrescentarDadosAcesso(aulasOnline[posicaoAula]);
            (*numAcessos)++;
        }
    }

    return acessosAulas;

}
