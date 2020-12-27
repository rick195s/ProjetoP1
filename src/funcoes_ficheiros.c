#include <stdio.h>
#include <string.h>


#include "../headers/funcoes_ficheiros.h"



void escreverFiheiroBinarioAulasOnline(tipoAulaOnline aulasOnline[], int numAulas)
{


    FILE *ficheiro;

    int erro,numEscrito;

    ficheiro = fopen("ficheiros/AulasOnline.dat", "wb");

    if(ficheiro == NULL)
    {
        printf("\n\nOcorreu um erro ao abrir o ficheiro das aulas online");
    }
    else
    {
        //Escreve o n�mero de aulas online existentes at� ao momento no ficheiro
        fwrite(&numAulas, sizeof(int), 1, ficheiro);

        //Escreve todas as aulas online existentes at� ao momento no ficheiro
        numEscrito=fwrite(aulasOnline, sizeof(tipoAulaOnline), numAulas, ficheiro);
        printf("\n\t\t\tElementos salvos: %d\n", numEscrito);


        erro = fclose(ficheiro);

        if(erro != 0)
        {

            printf("\n\nOcorreu um erro ao fechar o ficheiro %d", erro);
        }
    }

}


void lerFiheiroBinarioUC(tipoUnidadeCurricular uniCurriculares[], int *numUCs){


    FILE *ficheiro;

    int erro,numLido;


    ficheiro = fopen("ficheiros/UnidadesCurriculares.dat", "rb");

    if(ficheiro == NULL)
    {
        printf("\n\nOcorreu um erro ao abrir o ficheiro das unidades curriculares");
    }
    else
    {
        //Le o n�mero de UCs existentes at� ao momento no ficheiro
        fread(numUCs, sizeof(int), 1, ficheiro);
        //Le todas as UCs existentes at� ao momento no ficheiro
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
        printf("\n\nOcorreu um erro ao abrir o ficheiro das unidades curriculares");
    }
    else
    {
        //Escreve o n�mero de UCs existentes at� ao momento no ficheiro
        fwrite(&numUCs, sizeof(int), 1, ficheiro);

        //Escreve todas as UCs existentes at� ao momento no ficheiro
        numEscrito=fwrite(uniCurriculares, sizeof(tipoUnidadeCurricular), numUCs, ficheiro);
        printf("\n\t\t\tElementos salvos: %d\n", numEscrito);


        erro = fclose(ficheiro);

        if(erro != 0)
        {

            printf("\n\nOcorreu um erro ao fechar o ficheiro %d", erro);
        }
    }

}
