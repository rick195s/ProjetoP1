#include <stdio.h>
#include <stdlib.h>

#include "headers/funcoes_menus.h"
#include "headers/constantes.h"
#include "headers/funcoes_ficheiros.h"
#include "headers/funcoes_aulas.h"
#include "headers/funcoes_uc.h"
#include "headers/funcoes_acessos.h"
#include "headers/funcoes_auxiliares.h"
#include "headers/funcoes_estatisticas.h"

int main()
{
    int i, numUCs = 0, numAulas = 0,numAcessos = 0,numAulasTerminadas = 0,numAulasGravadas = 0, numAulasRealizadas=0, quantasListar;
    char op,opSubMenus;
    tipoUnidadeCurricular uniCurriculares[MAX_UC] = {0};
    tipoAulaOnline *aulasOnline;
    tipoAcessoAula *acessosAulas;

    acessosAulas = NULL;
    aulasOnline = NULL;
    acessosAulas = realloc(acessosAulas,numAcessos*sizeof(tipoAcessoAula));
    aulasOnline = realloc(aulasOnline,numAulas*sizeof(tipoAulaOnline));


    if(aulasOnline == NULL || acessosAulas == NULL)
    {
        mostrarMensagem("Ocorreu um erro ao reservar memoria",0);
    }
    else
    {
        lerFiheiroBinarioUC(uniCurriculares, &numUCs);
        aulasOnline=lerFiheiroBinarioAulasOnline(aulasOnline, &numAulas, &numAulasTerminadas, &numAulasGravadas);
        acessosAulas=lerFicheiroBinarioAcessoAulas(acessosAulas, &numAcessos);

        do
        {
            op=menuPrincipal(numUCs, numAcessos,numAulas,numAulasTerminadas,numAulasGravadas);


            switch(op)
            {
            case 'U':
                system("@cls||clear");
                do
                {
                    opSubMenus=menuUC();
                    switch(opSubMenus)
                    {

                    case 'I':

                        if(numUCs<MAX_UC)
                        {
                            numUCs=inserirUCs( uniCurriculares, numUCs);
                        }
                        else
                        {
                            mostrarMensagem("O numero maximo de UCs foi alcancado",0);
                        }

                        break;
                    case 'A':
                        if(numUCs == 0)
                        {
                            mostrarMensagem("Nao existem unidades curriculares",0);

                        }
                        else
                        {
                            system("@cls||clear");
                            alterarUC(uniCurriculares, numUCs);
                        }
                        break;
                    case 'L':
                        if(numUCs == 0)
                        {
                            mostrarMensagem("Nao existem unidades curriculares",0);

                        }
                        else
                        {
                            system("@cls||clear");
                            for(i=0; i<numUCs; i++)
                            {
                                listarUC(uniCurriculares[i], aulasOnline, numAulas);

                            }
                        }
                        break;
                    case 'R':
                        rankingUC(uniCurriculares,numUCs,aulasOnline,numAulas, acessosAulas, numAcessos);
                        break;
                    case 'V':
                        break;
                    default:
                        mostrarMensagem("Opcao invalida",0);
                    }
                }
                while(opSubMenus!='V');

                break;
            case 'A':
                if(numUCs == 0)
                {
                    mostrarMensagem("Para conseguir entrar no menu de aulas online primeiro e necessario criar unidades curriculares",0);
                }
                else
                {
                    system("@cls||clear");

                    do
                    {
                        opSubMenus = menuAulas();
                        switch(opSubMenus)
                        {
                        case 'A':
                            system("@cls||clear");

                            aulasOnline=agendarAulaOnline(aulasOnline, &numAulas, uniCurriculares, numUCs);

                            break;
                        case 'E':
                            if(numAulas == 0)
                            {
                                mostrarMensagem("Nao existem aulas para editar",0);

                            }
                            else
                            {
                                system("@cls||clear");
                                aulasOnline=editarAulaOnline(aulasOnline, &numAulas, uniCurriculares, numUCs);
                            }


                            break;
                        case 'I':
                            if(numAulas == 0)
                            {
                                mostrarMensagem("Nao existem aulas para apresentar",0);
                            }
                            else
                            {
                                administradorAulaOnline(aulasOnline, numAulas, &numAulasTerminadas, &numAulasGravadas);
                            }
                            break;
                        case 'Q':
                            if(numAulas == 0)
                            {
                                mostrarMensagem("Nao existem aulas",0);
                            }
                            else
                            {
                                listarInformacoesUCdaAula(aulasOnline,numAulas,uniCurriculares,numUCs,acessosAulas, numAcessos);
                            }
                            break;
                        case 'H':
                            if(numAulas == 0)
                            {
                                mostrarMensagem("Nao existem aulas",0);
                            }
                            else
                            {
                                listarEstudantesPresentes(aulasOnline,numAulas,acessosAulas, numAcessos);
                            }
                            break;

                        case 'L':
                            if(numAulas == 0)
                            {
                                mostrarMensagem("Nao existem aulas para apresentar",0);
                            }
                            else
                            {
                                for(i=0; i<numAulas; i++)
                                {
                                    listarAulaOnline(aulasOnline[i], acessosAulas, numAcessos);

                                }
                            }
                            break;
                        case 'V':
                            break;
                        default:
                            mostrarMensagem("Opcao invalida",0);
                        }
                    }
                    while(opSubMenus!='V');


                }


                break;
            case 'E':
                system("@cls||clear");
                acessosAulas=acessoAulaEstudante(acessosAulas, &numAcessos, aulasOnline, numAulas);
                break;

            case 'L':
                /*
                Menu das estatisticas selecionado
                */
                do
                {
                    opSubMenus = menuEstatisticas(uniCurriculares,numUCs, aulasOnline, numAulas, acessosAulas, numAcessos);
                    switch(opSubMenus)
                    {
                    case 'Q':
                        if(numUCs-1 > 0)
                        {
                            listarUCMenosAulasOnline(uniCurriculares,numUCs, aulasOnline, numAulas);
                        }
                        else
                        {
                            mostrarMensagem("E necessario que haja mais que uma unidade curricular para selecionar esta opcao",0);
                        }
                        break;
                    case 'R':
                        /*
                        Este ciclo irá calcular o numero total de aulas que foram realizadas
                        */
                        numAulasRealizadas=0;

                        for(i=0; i<numAulas; i++)
                        {
                            if(aulasOnline[i].estado == 2)
                            {
                                numAulasRealizadas++;
                            }
                        }
                        if(numAulasRealizadas > 0)
                        {
                            quantasListar=lerInteiro("\n\nInsira quantas aulas realizadas ha mais tempo quer listar", 1, numAulasRealizadas);
                            ordenarAulaAntigas(aulasOnline, numAulas);

                            for(i=0; i<quantasListar; i++)
                            {
                                listarAulaOnline(aulasOnline[i], acessosAulas,numAcessos);
                            }

                        }
                        else
                        {
                            mostrarMensagem("Nao existem aulas realizadas",0);
                        }
                        break;
                    case 'V':
                        break;
                    default:
                        mostrarMensagem("Opcao invalida",0);

                    }


                }
                while(opSubMenus!='V');


                break;
            case 'F':
                break;
            default:
                mostrarMensagem("Opcao invalida",0);
            }
        }
        while(op!='F');

        escreverLogBinarioAcessosAulas(acessosAulas, numAcessos);
        escreverFiheiroBinarioUC(uniCurriculares, numUCs);
        escreverFiheiroBinarioAulasOnline(aulasOnline, numAulas);
        free(acessosAulas);
        free(aulasOnline);
    }



    return 0;
}
