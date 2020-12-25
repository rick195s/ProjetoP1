
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"


void listarUC(tipoUnidadeCurricular uniCurricular,int detalhes)
{

    /*
    Caso a função receba por parametro a variável "detalhes" com o valor 1
    a função irá mostrar mais detalhes relativos à unidade curricular
    */

    int i;


    if(detalhes == 1){


    }

    printf("\n\nDados da UC:");
    printf("\n\n\tCodigo: %d", uniCurricular.codigo);
    printf("\n\tDesignacao: %s", uniCurricular.designacao);
    if(uniCurricular.tipoUC == 0){
        printf("\n\tTipo: obrigatoria");

    }else if(uniCurricular.tipoUC == 1){
        printf("\n\tTipo: opcional");

    }
    if(uniCurricular.regime == 0){
        printf("\n\tRegime: diurno");

    }else if(uniCurricular.regime == 1){
        printf("\n\tRegime: pos-laboral");

    }

    printf("\n\tSemestre: %d", uniCurricular.semestre);
    printf("\n\tTipo de Aulas:");
    for(i=0; i<TIPOS_AULA; i++)
    {
        if(uniCurricular.aulasOnline[i].quantidade != 0)
        {

            printf("\n\t\t%s:",  uniCurricular.aulasOnline[i].designacao);
            printf("\n\t\t\tQuantidade: %d aula(s)",  uniCurricular.aulasOnline[i].quantidade );
            printf("\n\t\t\tDuracao: %d minuto(s)",  uniCurricular.aulasOnline[i].duracao );
        }

    }


}

int prourarUC(tipoUnidadeCurricular uniCurriculares[], int numUCs)
{

    /*
    Devolve a posição onde se encontra a unidade curricular
    com o codigo inserido pelo utilizador ou -1 caso não encontre
    */

    int codigoUC,i,posicao=-1;

    system("@cls||clear");
    codigoUC=lerInteiro("\n\nInsira o codigo da UC que pretende alterar",1000,9999);

    for(i=0; i<numUCs; i++)
    {

        if(uniCurriculares[i].codigo == codigoUC)
        {
            posicao = i;

        }

    }

    return posicao;

}

void alterarUC(tipoUnidadeCurricular uniCurriculares[], int numUCs)
{
    int posicao,codigo;

    posicao=prourarUC(uniCurriculares, numUCs);
    if(posicao != -1)
    {

        listarUC(uniCurriculares[posicao],0);
        codigo=uniCurriculares[posicao].codigo;
        uniCurriculares[posicao]=lerDadosUC();
        uniCurriculares[posicao].codigo=codigo;
        escreverFiheiroBinarioUC(uniCurriculares, numUCs);
    }
    else
    {
        printf("\n\nNao existe nenhuma unidade curricular com o codigo que introduziu");

    }


}


int gerarCodigoUnico(tipoUnidadeCurricular uniCurriculares[], int numUCs)
{

    int codigo, unico,i;

    /*Caso exista uma UC com o codigo igual ao gerado o programa irá
    continuar a gerar até não haver códigos de UCs iguais
    */

    do
    {
        unico = 1;
        //Gera um Codigo entre 1000 e 9999
        codigo = (rand() %(9999-1000+1))+1000;

        for(i=0; i<numUCs; i++)
        {
            if(uniCurriculares[i].codigo == codigo)
            {
                unico = 0;
            }
        }
    }
    while(unico != 1);

    return codigo;
}

tipoUnidadeCurricular lerDadosUC()
{

    tipoUnidadeCurricular uniCurricular;
    int j;

    lerString("\n\nInsira a designacao da UC: ", uniCurricular.designacao, MAX_STRING);
    uniCurricular.tipoUC = lerInteiro("\n\nIndique o tipo de UC\n\n0- Opcional\n\n1- Obrigatoria\n\n ",0,1);
    uniCurricular.semestre = lerInteiro("\n\nIndique o semestre a que esta UC pertence ",1,6);
    uniCurricular.regime = lerInteiro("\n\nIndique o requime da UC\n\n0- diurno\n\n1- pos-laboral\n\n ",0,1);

    /*Nesta parte do código é copiado para o campo do vetor "designacao" os caracteres
    que representam os tipos de aula existentes*/

    strcpy(uniCurricular.aulasOnline[0].designacao, "T");
    strcpy(uniCurricular.aulasOnline[1].designacao, "TP");
    strcpy(uniCurricular.aulasOnline[2].designacao, "PL");


    for(j=0; j<TIPOS_AULA; j++)
    {

        /*Se o utilizador indicar que não existem aulas, ou seja inserir 0, para um tipo de aula
        a duracao da mesma terá um valor aleatório */
        printf("\n\nIndique a quantidade de aulas de %s da UC", uniCurricular.aulasOnline[j].designacao );
        uniCurricular.aulasOnline[j].quantidade = lerInteiro("",0,200);

        if(uniCurricular.aulasOnline[j].quantidade > 0)
        {

            printf("\n\nIndique a duracao das aulas de %s da UC em minutos", uniCurricular.aulasOnline[j].designacao );
            uniCurricular.aulasOnline[j].duracao = lerInteiro("",0,200);
        }

    }

    return uniCurricular;
}


int inserirUCs(tipoUnidadeCurricular uniCurriculares[], int numUCs)
{

    int up_numUCs, quantidadeUCs,i;

    up_numUCs = numUCs;

    system("@cls||clear");

    quantidadeUCs=lerInteiro("\n\nIndique quantas unidades curiulares pretende inserir", 1, MAX_UC-numUCs);


    for(i=0; i<quantidadeUCs; i++)
    {
        printf("\n\nUC numero %d", i+1 );
        uniCurriculares[up_numUCs] = lerDadosUC();

        /*O ccdigo da UC só é gerada após a introdução dos dados pelo utilizador
        para esse campo não ser alterado com dados aleatórios que estejam na memória*/

        uniCurriculares[up_numUCs].codigo = gerarCodigoUnico(uniCurriculares, up_numUCs);
        up_numUCs++;
        system("@cls||clear");

    }

    escreverFiheiroBinarioUC(uniCurriculares, up_numUCs);



    return up_numUCs;
}
