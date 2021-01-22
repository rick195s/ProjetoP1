#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headers/funcoes_uc.h"
#include "../headers/funcoes_ficheiros.h"
#include "../headers/funcoes_auxiliares.h"
#include "../headers/funcoes_aulas.h"
#include "../headers/funcoes_acessos.h"



void ordenarVetorUC(tipoUnidadeCurricular uniCurriculares[], int numUCs, int quantidadeAcessosUC[])
{

    int i,j,posmenor, auxQuantidades;

    tipoUnidadeCurricular aux;

    for(i=0; i<numUCs-1; i++) /* Percorre vetor */
    {
        posmenor=i;
        for (j=i+1; j<numUCs; j++)
        {
            if (quantidadeAcessosUC[j] > quantidadeAcessosUC[posmenor])  /* > para decrescente */
            {
                posmenor = j;
            }
        }
        if (posmenor!=i)  /* se existir elemento inferior */
        {
            auxQuantidades=quantidadeAcessosUC[posmenor];
            quantidadeAcessosUC[posmenor]=quantidadeAcessosUC[i];
            quantidadeAcessosUC[i]=auxQuantidades;
            aux=uniCurriculares[posmenor]; /* troca elemento corrente com o menor */
            uniCurriculares[posmenor]=uniCurriculares[i];
            uniCurriculares[i]=aux;
        }
    }

}


void rankingUC(tipoUnidadeCurricular uniCurriculares[], int numUCs, tipoAulaOnline aulasOnline[], int numAulas, tipoAcessoAula acessosAula[], int numAcessos)
{
    /*
    O algoritmo adiciona a quantidade de acessos duma aula da unidade curricular
    na mesma posicao do vetor "uniCurriculres" no vetor "acessos"

    Ou seja:
        se existir uma aula que pertença a uma uc a quantidade de acessos a essa
        aula irá ser armazenada no vetor "acessos" na mesma posicao que a uc esta
        no vetor uniCurriculares. Quantidade de acessos de uniCurriculares[x]=acessos[x]
    */

    int i,j,*quantidadeAcessosUC=NULL;

    quantidadeAcessosUC=calloc(numUCs, sizeof(int));

    if(quantidadeAcessosUC == NULL)
    {
        mostrarMensagem("Ocorreu um erro ao reservar memoria",0);
    }
    else
    {

        for(i=0; i<numUCs; i++)
        {
            for(j=0; j<numAulas; j++)
            {
                if(uniCurriculares[i].codigo == aulasOnline[j].codigoUC)
                {
                    quantidadeAcessosUC[i]+=quantidadeAcessosAula(aulasOnline[j], acessosAula, numAcessos, 1);

                }
            }
        }

        ordenarVetorUC(uniCurriculares, numUCs, quantidadeAcessosUC);

        for(i=0; i<numUCs; i++)
        {
            listarUC(uniCurriculares[i],aulasOnline,numAulas);
        }

        free(quantidadeAcessosUC);
    }


}

void listarUC(tipoUnidadeCurricular uniCurricular, tipoAulaOnline aulasOnline[], int numAulas)
{

    /*
    Caso a função receba por parametro a variável "detalhes" com o valor 1
    a função irá mostrar mais detalhes relativos à unidade curricular
    */

    int i;


    printf("\n\n---------------------------  Codigo da UC: %d ---------------------------", uniCurricular.codigo);
    printf("\n\n\tDesignacao: %s", uniCurricular.designacao);

    if(uniCurricular.tipoUC == 0)
    {
        printf("\t\t\tTipo: obrigatoria");

    }
    else if(uniCurricular.tipoUC == 1)
    {
        printf("\t\t\tTipo: opcional");

    }
    if(uniCurricular.regime == 0)
    {
        printf("\n\n\tRegime: diurno");

    }
    else if(uniCurricular.regime == 1)
    {
        printf("\n\n\tRegime: pos-laboral");

    }

    printf("\t\t\t\tSemestre: %d", uniCurricular.semestre);
    printf("\n\n\tTipo de Aulas:");
    for(i=0; i<TIPOS_AULA; i++)
    {
        if(uniCurricular.aulasOnline[i].quantidade != 0)
        {

            printf("\n\n\t\t%s:",  uniCurricular.aulasOnline[i].designacao);
            printf("\n\t\t\tAulas previstas: %d aula(s)",  uniCurricular.aulasOnline[i].quantidade);
            printf("\t\tAulas agendadas: %d aula(s)",  quantidadeAulasTipo(uniCurricular,i,aulasOnline,numAulas,1));
            printf("\n\t\t\tAulas realizadas: %d aula(s)",  quantidadeAulasTipo(uniCurricular,i,aulasOnline,numAulas,0));
            printf("\t\tDuracao: %d minuto(s)",  uniCurricular.aulasOnline[i].duracao );

        }

    }

    for(i=0; i<numAulas; i++)
    {
        if(aulasOnline[i].codigoUC == uniCurricular.codigo && aulasOnline[i].estado == 0)
        {
            if(aulasOnline[i].tipoAula == 0)
            {
                printf("\n\n\tTipo da Aula -> T");

            }
            else if(aulasOnline[i].tipoAula == 1)
            {
                printf("\n\n\tTipo da Aula -> TP");

            }
            else
            {
                printf("\n\n\tTipo da Aula -> PL");
            }
            printf("\t\t\tData -> %d/%d/%d", aulasOnline[i].data.dia,aulasOnline[i].data.mes,aulasOnline[i].data.ano);
            printf("\t\t\tHora de Inicio -> %.2f", aulasOnline[i].horaInicio);
        }
    }

}

int procurarUC(int codigoUC, tipoUnidadeCurricular uniCurriculares[], int numUCs)
{

    /*
    Esta função devolve a posição onde se encontra a unidade curricular com o codigo recebido
    pelo argumento "codigoUC" ou -1 caso não encontre
    */


    int i,posicao=-1;


    for(i=0; i<numUCs; i++)
    {

        if(uniCurriculares[i].codigo == codigoUC)
        {
            posicao = i;
            i=numUCs;
        }

    }


    return posicao;

}

void alterarUC(tipoUnidadeCurricular uniCurriculares[], int numUCs)
{
    int posicao,codigo;

    system("@cls||clear");
    codigo=lerInteiro("\n\nInsira o codigo da UC que pretende alterar",1000,9999);
    /*
    Ao chamar a função "procurarUC" é possível guardar a UC que foi encontra
    no primeiro argumento dessa mesma função mas neste caso como não é
    pretendida essa alteração é enviada uma variavél qualquer do tipoUnidadeCurricular
    para a função, sendo que ela não vai ser alterada.
    */
    posicao=procurarUC(codigo, uniCurriculares, numUCs);
    if(posicao != -1)
    {
        //Mostra a unidade curricular que foi encontrada

        /*
        Guarda o código da unidade curricular numa variavel local para depois
        de a mesma ser alterada continuar com o mesmo código
        */
        codigo=uniCurriculares[posicao].codigo;
        uniCurriculares[posicao]=lerDadosUC();
        uniCurriculares[posicao].codigo=codigo;

    }
    else
    {
        mostrarMensagem("Nao existe nenhuma unidade curricular com o codigo igual ao que introduziu",0);
    }


}

int gerarCodigoUnico(tipoUnidadeCurricular uniCurriculares[], int numUCs)
{

    srand(time(NULL));
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

void lerUCTipoAulas(tipoAulas tipoAulas[])
{


    int j;
    /*
    Nesta parte do código é copiado para o campo do vetor "designacao" os caracteres
    que representam os tipos de aula existentes
    */

    strcpy(tipoAulas[0].designacao, "T");
    strcpy(tipoAulas[1].designacao, "TP");
    strcpy(tipoAulas[2].designacao, "PL");


    for(j=0; j<TIPOS_AULA; j++)
    {

        /*Se o utilizador indicar que não existem aulas, ou seja inserir 0, para um tipo de aula
        a duracao da mesma terá um valor aleatório */
        printf("\n\nIndique a quantidade de aulas de %s da UC", tipoAulas[j].designacao );
        tipoAulas[j].quantidade = lerInteiro("",0,MAX_AULAS_POR_TIPO);

        if(tipoAulas[j].quantidade > 0)
        {

            printf("\n\nIndique a duracao das aulas de %s da UC em minutos", tipoAulas[j].designacao );
            tipoAulas[j].duracao = lerInteiro("",1,MAX_DURACAO_AULA_DIURNO);
        }

    }

}

tipoUnidadeCurricular lerDadosUC()
{

    tipoUnidadeCurricular uniCurricular;


    lerString("\n\nInsira a designacao da UC: ", uniCurricular.designacao, MAX_STRING);
    uniCurricular.tipoUC = lerInteiro("\n\nIndique o tipo de UC\n\n0 - Opcional\n\n1 - Obrigatoria\n\n ",0,1);
    uniCurricular.semestre = lerInteiro("\n\nIndique o semestre a que esta UC pertence ",1,6);
    uniCurricular.regime = lerInteiro("\n\nIndique o requime da UC\n\n0 - diurno\n\n1 - pos-laboral\n\n ",0,1);
    lerUCTipoAulas(uniCurricular.aulasOnline);


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



    return up_numUCs;
}
