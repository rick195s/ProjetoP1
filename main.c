#include <stdio.h>
#include <stdlib.h>

#include "headers/funcoes_menus.h"
#include "headers/constantes.h"
#include "headers/funcoes_ficheiros.h"
#include "headers/funcoes_aulas.h"
#include "headers/funcoes_uc.h"

int main()
{

    tipoUnidadeCurricular uniCurriculares[MAX_UC] = {0};
    int numUCs = 0, numAulas = 0,i;
    char op,opSubMenus;
    tipoAulaOnline *aulasOnline;

    aulasOnline = NULL;
    aulasOnline = realloc(aulasOnline,numAulas*sizeof(tipoAulaOnline));


    if(aulasOnline == NULL)
    {

        printf("\n\nNao foi possivel reservar memoria para as aulas online");

    }
    else
    {
        lerFiheiroBinarioUC(uniCurriculares, &numUCs);
        aulasOnline=lerFiheiroBinarioAulasOnline(aulasOnline,&numAulas);
        do
        {
            op=menuPrincipal();


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
                            system("@cls||clear");
                            printf("\n\n\n\t\tO numero maximo de UCs foi alcancado\n\n\n");
                        }

                        break;
                    case 'A':
                        if(numUCs == 0)
                        {
                            system("@cls||clear");
                            printf("\n\n\n\t\tNao existem unidades curriculares\n\n\n");

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
                            system("@cls||clear");
                            printf("\n\n\n\t\tNao existem unidades curriculares\n\n\n");

                        }
                        else
                        {
                            system("@cls||clear");
                            for(i=0; i<numUCs; i++)
                            {
                                listarUC(uniCurriculares[i],1);
                            }


                        }
                        break;
                    case 'V':
                        break;
                    default:
                        system("@cls||clear");
                        printf("\n\n\n\t\tOpcao invalida\n\n\n");
                    }
                }
                while(opSubMenus!='V');

                break;
            case 'A':
                if(numUCs == 0)
                {
                    system("@cls||clear");
                    printf("\n\n\tPara conseguir entrar no menu de aulas online primeiro e necessario criar unidades curriculares\n\n");
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
                            if(numAulas == 0){
                                system("@cls||clear");
                                printf("\n\nNao existem aulas");
                            }else{
                                system("@cls||clear");
                                aulasOnline=editarAulaOnline(aulasOnline, &numAulas, uniCurriculares, numUCs);
                            }


                            break;
                        case 'I':
                            if(numAulas == 0)
                            {
                                system("@cls||clear");
                                printf("\n\n\tNao existem aulas para apresentar\n\n");
                            }
                            else
                            {
                                administradorAulaOnline(aulasOnline, numAulas);
                            }
                            break;

                        case 'L':
                            if(numAulas == 0)
                            {
                                system("@cls||clear");
                                printf("\n\n\tNao existem aulas para apresentar\n\n");
                            }
                            else
                            {
                                for(i=0; i<numAulas; i++)
                                {

                                    listarAulasOnline(aulasOnline[i]);

                                }
                            }
                            break;
                        case 'V':
                            break;
                        default:
                            system("@cls||clear");
                            printf("\n\n\n\t\tOpcao invalida\n\n\n");
                        }
                    }
                    while(opSubMenus!='V');


                }


                break;
            case 'E':
                system("@cls||clear");

                break;
            case 'F':
                break;
            default:
                system("@cls||clear");
                printf("\n\n\n\t\tOpcao invalida\n\n\n");
            }
        }
        while(op!='F');
        escreverFiheiroBinarioUC(uniCurriculares, numUCs);
        escreverFiheiroBinarioAulasOnline(aulasOnline, numAulas);
        free(aulasOnline);
    }



    return 0;
}
