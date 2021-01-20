#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"

tipoAcessoAula *lerFicheiroBinarioAcessoAulas(tipoAcessoAula acessosAulas[], int *numAcessos){

    FILE *ficheiro;

    int erro,numLido;
    tipoAcessoAula *aux;


    ficheiro = fopen("ficheiros/AcessosAulas.dat","rb");

    if(ficheiro == NULL )
    {
        mostrarMensagem("Ocorreu um erro ao ler o ficheiro dos acessoas as aulas",0);

    }
    else
    {
        //Le o número de acessos a aulas existentes até ao momento no ficheiro
        fread(&(*numAcessos), sizeof(int), 1, ficheiro);
        aux = acessosAulas;
        acessosAulas = realloc(acessosAulas, (*numAcessos)*sizeof(tipoAcessoAula));


        if(acessosAulas == NULL)
        {
            mostrarMensagem("Nao foi possivel reservar memoria para as aulas online ao ler ficheiro das aulas",0);
            acessosAulas = aux;
        }
        else
        {
            //Le todos os acessos as aulas
            numLido=fread(acessosAulas, sizeof(tipoAcessoAula), *numAcessos, ficheiro);
            printf("\n\t\t\tElementos lidos: %d\n", numLido);

            erro = fclose(ficheiro);

            if(erro != 0)
            {
                printf("\n\nOcorreu um erro ao fechar o ficheiro %d", erro);
            }
        }

    }


    return acessosAulas;
}

void escreverLogBinarioAcessosAulas(tipoAcessoAula acessosAulas[], int numAcessos){

    FILE *ficheiro;

    int erro;

    ficheiro = fopen("ficheiros/AcessosAulas.dat", "wb");

    if(ficheiro == NULL)
    {
        mostrarMensagem("Ocorreu um erro ao escrever no ficheiro dos acessoas as aulas",0);
    }
    else
    {
        //Escreve o número de UCs existentes até ao momento no ficheiro
        fwrite(&numAcessos, sizeof(int), 1, ficheiro);
        //Acrescenta o acesso à aula online no ficheiro binario
        fwrite(acessosAulas, sizeof(tipoAcessoAula), numAcessos, ficheiro);

        erro = fclose(ficheiro);

        if(erro != 0)
        {

            printf("\n\nOcorreu um erro ao fechar o ficheiro %d", erro);
        }
    }

}

void adicionarLogTextoAcessoAulas(tipoAcessoAula acessoAula){

    FILE *ficheiro;

    int erro;

    ficheiro = fopen("ficheiros/AcessosAulas.log", "a");

    if(ficheiro == NULL)
    {
        mostrarMensagem("Ocorreu um erro ao escrever no log dos acessos as aulas",0);
    }
    else
    {
        //Acrecenta o acesso à aula online no ficheiro de texto
        fprintf(ficheiro, "%s - ", acessoAula.designacaoAula);
        fprintf(ficheiro, "%d - ", acessoAula.numeroEstudante);
        if(acessoAula.tipoAcesso == 0){
            fprintf(ficheiro, "Online\n");
        }else{
            fprintf(ficheiro, "Offline\n");

        }

        erro = fclose(ficheiro);

        if(erro != 0)
        {

            printf("\n\nOcorreu um erro ao fechar o ficheiro %d", erro);
        }
    }
}




tipoAulaOnline *lerFiheiroBinarioAulasOnline(tipoAulaOnline aulasOnline[], int *numAulas, int *numAulasTerminadas, int *numAulasGravadas)
{


    FILE *ficheiro;

    int erro,numLido, i;
    tipoAulaOnline *aux;




    ficheiro = fopen("ficheiros/AulasOnline.dat","rb");

    if(ficheiro == NULL)
    {
        mostrarMensagem("Ocorreu um erro ao ler o ficheiro das aulas online",0);

    }
    else
    {
        //Le o número de UCs existentes até ao momento no ficheiro

        fread(&(*numAulas), sizeof(int), 1, ficheiro);
        aux = aulasOnline;
        aulasOnline = realloc(aulasOnline, (*numAulas)*sizeof(tipoAulaOnline));


        if(aulasOnline == NULL)
        {
            mostrarMensagem("Nao foi possivel reservar memoria para as aulas online ao ler ficheiro das aulas",0);
            aulasOnline = aux;
        }
        else
        {
            //Le todas as UCs existentes até ao momento no ficheiro
            numLido=fread(aulasOnline, sizeof(tipoAulaOnline), *numAulas, ficheiro);
            printf("\n\t\t\tElementos lidos: %d\n", numLido);

            for(i=0;i<*numAulas;i++){
                if(aulasOnline[i].estado == 2){
                    (*numAulasTerminadas)++;
                }
                if(aulasOnline[i].gravada == 1){
                    (*numAulasGravadas)++;
                }
            }
            erro = fclose(ficheiro);

            if(erro != 0)
            {

                printf("\n\nOcorreu um erro ao fechar o ficheiro %d", erro);
            }
        }

    }


    return aulasOnline;
}


void escreverFiheiroBinarioAulasOnline(tipoAulaOnline aulasOnline[], int numAulas)
{


    FILE *ficheiro;

    int erro,numEscrito;

    ficheiro = fopen("ficheiros/AulasOnline.dat", "wb");

    if(ficheiro == NULL)
    {
        mostrarMensagem("Ocorreu um erro ao escrever no ficheiro das aulas online",0);
    }
    else
    {
        //Escreve o número de aulas online existentes até ao momento no ficheiro

        fwrite(&numAulas, sizeof(int), 1, ficheiro);

        //Escreve todas as aulas online existentes até ao momento no ficheiro
        numEscrito=fwrite(aulasOnline, sizeof(tipoAulaOnline), numAulas, ficheiro);
        printf("\n\t\t\tElementos salvos: %d\n", numEscrito);


        erro = fclose(ficheiro);

        if(erro != 0)
        {

            printf("\n\nOcorreu um erro ao fechar o ficheiro %d", erro);
        }
    }

}


void lerFiheiroBinarioUC(tipoUnidadeCurricular uniCurriculares[], int *numUCs)
{


    FILE *ficheiro;

    int erro,numLido;


    ficheiro = fopen("ficheiros/UnidadesCurriculares.dat", "rb");

    if(ficheiro == NULL)
    {
        mostrarMensagem("Ocorreu um erro ao ler o ficheiro das unidades curriculares",0);
    }
    else
    {
        //Le o número de UCs existentes até ao momento no ficheiro
        fread(numUCs, sizeof(int), 1, ficheiro);
        //Le todas as UCs existentes até ao momento no ficheiro
        numLido=fread(uniCurriculares, sizeof(tipoUnidadeCurricular), *numUCs, ficheiro);
        printf("\n\t\t\tElementos lidos: %d\n", numLido);


        erro = fclose(ficheiro);

        if(erro != 0)
        {

            printf("\n\nOcorreu um erro ao fechar o ficheiro %d", erro);
        }
    }



}

void escreverFiheiroBinarioUC(tipoUnidadeCurricular uniCurriculares[], int numUCs)
{


    FILE *ficheiro;

    int erro,numEscrito;

    ficheiro = fopen("ficheiros/UnidadesCurriculares.dat", "wb");

    if(ficheiro == NULL)
    {
        mostrarMensagem("Ocorreu um erro ao escrever no ficheiro das unidades curriculares",0);
    }
    else
    {
        //Escreve o número de UCs existentes até ao momento no ficheiro
        fwrite(&numUCs, sizeof(int), 1, ficheiro);

        //Escreve todas as UCs existentes até ao momento no ficheiro
        numEscrito=fwrite(uniCurriculares, sizeof(tipoUnidadeCurricular), numUCs, ficheiro);
        printf("\n\t\t\tElementos salvos: %d\n", numEscrito);


        erro = fclose(ficheiro);

        if(erro != 0)
        {

            printf("\n\nOcorreu um erro ao fechar o ficheiro %d", erro);
        }
    }

}
