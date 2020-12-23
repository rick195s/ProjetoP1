
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"

int gerarCodigoUnico(tipoUnidadeCurricular uniCurriulares[], int numUCs)
{

    int codigo, unico,i;

    /*Caso exista uma UC com o codigo igual ao gerado o programa irá
    continuar a gerar até não haver códigos de UCs iguais  */

    do
    {
        unico = 1;
        codigo = (rand() %(9999-1000+1))+1000;

        for(i=0;i<numUCs;i++)
        {
            if(uniCurriulares[i].codigo == codigo)
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


int inserirUc(tipoUnidadeCurricular uniCurriculares[], int numUCs)
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
        para a esse campo não ser alterado com dados aleatórios que estejam na memória*/

        uniCurriculares[up_numUCs].codigo = gerarCodigoUnico(uniCurriculares, up_numUCs);
        up_numUCs++;
        system("@cls||clear");

    }

    escreverFiheiroBinarioUC(uniCurriculares, up_numUCs);



    return up_numUCs;
}
