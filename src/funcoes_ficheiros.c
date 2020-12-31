#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/funcoes_ficheiros.h"

void lerFiheiroBinarioAulasOnline(tipoAulaOnline aulasOnline[], int *numAulas)
{


    FILE *ficheiro;

    int erro,numLido;

    *numAulas=0;

    ficheiro = fopen("ficheiros/AulasOnline.dat","rb");

    if(ficheiro == NULL)
    {
        printf("\n\nOcorreu um erro ao ler o ficheiro das aulas online");
    }
    else
    {
        //Le o número de UCs existentes até ao momento no ficheiro

        fread(numAulas, sizeof(int), 1, ficheiro);
        //Le todas as UCs existentes até ao momento no ficheiro
        if(*numAulas == 0){
             aulasOnline = realloc(aulasOnline, 1*sizeof(tipoAulaOnline));
        }else{
             aulasOnline = realloc(aulasOnline, (*numAulas)*sizeof(tipoAulaOnline));
        }

        if(aulasOnline == NULL)
        {
            printf("\n\nNao foi possivel reservar memoria para as aulas online ao ler ficheiro das aulas");
        }
        else
        {
            numLido=fread(aulasOnline, sizeof(tipoAulaOnline), *numAulas, ficheiro);
            printf("\n\t\t\tElementos lidos: %d\n", numLido);

            erro = fclose(ficheiro);

            if(erro != 0)
            {

                printf("\n\nOcorreu um erro ao fechar o ficheiro %d", erro);
            }
        }

    }



}


void escreverFiheiroBinarioAulasOnline(tipoAulaOnline aulasOnline[], int numAulas)
{


    FILE *ficheiro;

    int erro,numEscrito;

    ficheiro = fopen("ficheiros/AulasOnline.dat", "wb");

    if(ficheiro == NULL)
    {
        printf("\n\nOcorreu um erro ao escrever no ficheiro das aulas online");
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
        printf("\n\nOcorreu um erro ao ler o ficheiro das unidades curriculares");
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
        printf("\n\nOcorreu um erro ao escrever no ficheiro das unidades curriculares");
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
