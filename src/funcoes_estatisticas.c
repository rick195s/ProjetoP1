#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"
#include "../headers/funcoes_menus.h"
#include "../headers/funcoes_acessos.h"
#include "../headers/funcoes_estatisticas.h"


void listarUCMenosAulasOnline(tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas){

    int i,j, quantasListar,quantidadeAulasRealizadas[50]={0};

    quantasListar=lerInteiro("\n\nIntroduza quantas UCs pretende listar", 1,numUCs-1);

    for(i=0;i<numUCs;i++){
        for(j=0;j<TIPOS_AULA;j++){
            quantidadeAulasRealizadas[i]+=quantidadeAulasTipo(uniCurriculares[i],j,aulasOnline,numAulas,0);
        }
    }

    ordenarVetorUC(uniCurriculares,numUCs,quantidadeAulasRealizadas);

    /*
    Como a funcao ordenarVetorUC ordena de forma decrescente e temos de
    mostrar as UCs com menos aulas, é necessario percorrer o vetor começando
    pelo fim.

    O i é igualado à ultima posicao do vetor, ou seja numUCs-1, depois ao longo
    do ciclo for é retirado 1 à variavel i até ao i ter um valor igual ou
    inferior ao número de ucs -1 - a qauntidade de ucs que o utilizador pretende
    listar
    */
    for(i=numUCs-1;i>(numUCs-1)-quantasListar;i--){
        listarUC(uniCurriculares[i],aulasOnline,numAulas);

    }


}

float mediaDePresencasAula(tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAula[], int numAcessos)
{
    /*
    Esta funcao vai devolver a media de presencas em todas as aulas online
    */

    float media;
    int i,numPresencas=0;

    for(i=0;i<numAulas;i++){
        numPresencas+=quantidadeAcessosAula(aulasOnline[i], acessosAula, numAcessos, 0);
    }

    media=(float)numPresencas/numAulas;


    return media;
}
