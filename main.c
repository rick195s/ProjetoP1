#include <stdio.h>
#include <stdlib.h>

#include "headers/funcoes_menus.h"
#include "headers/constantes.h"
#include "headers/funcoes_ficheiros.h"

int main()
{

    tipoUnidadeCurricular uniCurriculares[MAX_UC] = {0};
    int numUCs = 0, numAulas = 0;
    char op;
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
                menuUC(uniCurriculares, &numUCs);
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
                    aulasOnline=menuAulas(aulasOnline, &numAulas, uniCurriculares, numUCs);
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

        free(aulasOnline);
    }



    return 0;
}
