#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/funcoes_acessos.h"
#include "../headers/constantes.h"
#include "../headers/funcoes_auxiliares.h"
#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_ficheiros.h"

void listarAcessosAulas(tipoAcessoAula acessoAula){

    system("@cls||clear");
    printf("\n\nNumero do estudante: %d", acessoAula.numeroEstudante);
    printf("\n\nDesginacao da aula: %s", acessoAula.designacaoAula);
    if(acessoAula.tipoAcesso == 0){
        printf("\n\nTipo de acesso: Online");

    }else{
        printf("\n\nTipo de acesso: Offline");

    }
}

tipoAcessoAula acrescentarDadosAcesso(tipoAcessoAula acessosAulas[], tipoAulaOnline aulaOnline){

    tipoAcessoAula acessoAula;

    acessoAula.numeroEstudante = lerInteiro("\n\nInsira o seu numero de estudante: " , 1000, 9999);
    strcpy(acessoAula.designacaoAula, aulaOnline.designacao);

    if(aulaOnline.estado == 1){
        acessoAula.tipoAcesso = 0;
    }else{
        acessoAula.tipoAcesso = 1;
    }
    adicionarLogTextoAcessoAulas(acessoAula);

    return acessoAula;
}

tipoAcessoAula *acessoAulaEstudante(tipoAcessoAula acessosAulas[], int *numAcessos, tipoAulaOnline aulasOnline[], int numAulas){

    char designacao[MAX_STRING];
    int posicaoAula;
    tipoAcessoAula *aux;

    aux=acessosAulas;
    system("@cls||clear");
    lerString("\n\nInsira a designacao da aula a que pretender aceder: ",designacao,MAX_STRING);

    posicaoAula=procurarDesignacaoAula(aulasOnline,numAulas,designacao);

    if(posicaoAula == -1 || aulasOnline[posicaoAula].estado == 0){
        if(posicaoAula == -1){
            system("@cls||clear");
            printf("\n\nNao existe nenhuma aula com a desginacao que introduziu");
        }else{
            system("@cls||clear");
            printf("\n\nA aula que pretende assistir ainda nao comecou");
        }
    }else{

        acessosAulas=realloc(acessosAulas, (*numAcessos+1)*sizeof(tipoAcessoAula));

        if(acessosAulas == NULL){
            acessosAulas=aux;
            system("@cls||clear");
            printf("\n\nOcocrreu um erro para reservar memoria ao adicionar acesso a aula");
        }else{

            acessosAulas[*numAcessos] = acrescentarDadosAcesso(acessosAulas, aulasOnline[posicaoAula]);
            (*numAcessos)++;
        }
    }

    return acessosAulas;

}
