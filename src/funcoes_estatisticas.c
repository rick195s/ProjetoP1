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



float mediaDePresencasAula(tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAula[], int numAcessos)
{
    /*
    Esta funcao vai devolver a media de presencas em todas as aulas online
    */

    float media;
    int i,numPresencas=0;

    for(i=0; i<numAulas; i++)
    {
        numPresencas+=quantidadeAcessosAula(aulasOnline[i], acessosAula, numAcessos, 0);
    }

    media=(float)numPresencas/numAulas;


    return media;
}

void listarUCMenosAulasOnline(tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas)
{

    int i,j, quantasListar,*quantidadeAulasRealizadas=NULL;

    quantidadeAulasRealizadas=calloc(numUCs,sizeof(int));

    if(quantidadeAulasRealizadas == NULL)
    {
        mostrarMensagem("Ocorreu um erro ao reservar memoria",0);
    }
    else
    {

        quantasListar=lerInteiro("\n\nIntroduza quantas UCs pretende listar", 1,numUCs-1);

        for(i=0; i<numUCs; i++)
        {
            for(j=0; j<TIPOS_AULA; j++)
            {
                quantidadeAulasRealizadas[i]+=quantidadeAulasTipo(uniCurriculares[i],j,aulasOnline,numAulas,0);
            }
        }

        ordenarVetorUC(uniCurriculares,numUCs,quantidadeAulasRealizadas);

        free(quantidadeAulasRealizadas);
        /*
        Como a funcao ordenarVetorUC ordena de forma decrescente e temos de
        mostrar as UCs com menos aulas, é necessario percorrer o vetor começando
        pelo fim.

        O i é igualado à ultima posicao do vetor, ou seja numUCs-1, depois ao longo
        do ciclo for é retirado 1 à variavel i até ao i ter um valor igual ou
        inferior ao número de ucs -1 - a qauntidade de ucs que o utilizador pretende
        listar
        */
        for(i=numUCs-1; i>(numUCs-1)-quantasListar; i--)
        {
            listarUC(uniCurriculares[i],aulasOnline,numAulas);

        }

    }


}

int percentagemUCsAulasGravadas(tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas)
{

    int i,j,numUCsGravacoes=0,percentagem;

    /*
    Neste algoritmo o vetor das aulsa online e das ucs são percorridos
    e se houver alguma uc com pelo menos uma aula gravada então a variavel
    numUCsGravacoes é incrementada.
    */

    for(i=0; i<numUCs; i++)
    {

        for(j=0;j<numAulas;j++){
            if(aulasOnline[j].codigoUC == uniCurriculares[i].codigo && aulasOnline[j].gravada == 1){
                numUCsGravacoes++;
                j=numAulas;             //Se for encontrada alguma aula gravada que pertença à uc então
            }                           //este ciclo for é interrompido

        }

    }

    percentagem = ((float)numUCsGravacoes/numUCs)*100;

    return percentagem;
}

void tipoAulaGravacoes(tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAulas[], int numAcessos, char vetorCaracteres[MAX_STRING]){

    int i,j,t=0,tp=0,pl=0;


    for(i=0;i<numAcessos;i++){
        for(j=0;j<numAulas;j++){

            if(strcmp(acessosAulas[i].designacaoAula,aulasOnline[j].designacao) == 0 && acessosAulas[i].tipoAcesso == 1){
                if(aulasOnline[j].tipoAula == 0){
                    t++;
                }else if(aulasOnline[j].tipoAula == 1){
                    tp++;
                }else{
                    pl++;
                }
            }
        }
    }

    if(t >= tp && t >= pl){
        strcpy(vetorCaracteres, "T");
    }else if(tp >= t && tp >= pl){
        strcpy(vetorCaracteres, "TP");
    }else{
        strcpy(vetorCaracteres, "PL");
    }



}
