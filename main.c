#include <stdio.h>
#include <stdlib.h>

#include "headers/funcoes_menus.h"
#include "headers/constantes.h"
#include "headers/funcoes_ficheiros.h"
#include "headers/funcoes_aulas.h"
#include "headers/funcoes_uc.h"
#include "headers/funcoes_acessos.h"
#include "headers/funcoes_auxiliares.h"

int main()
{
    int numUCs = 0, numAulas = 0,numAcessos = 0,numAulasTerminadas = 0,numAulasGravadas = 0, i;
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
                                mostrarMensagem("Nao existem aulas para apresentar",0);
                            }
                            else
                            {
                                listarInformacoesUCdaAula(aulasOnline,numAulas,uniCurriculares,numUCs,acessosAulas, numAcessos);
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
            case 'D':
                system("@cls||clear");
                for(i=0; i<numAcessos; i++)
                {
                    listarAcessosAulas(acessosAulas[i]);
                }
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
        free(aulasOnline);
    }



    return 0;
}
