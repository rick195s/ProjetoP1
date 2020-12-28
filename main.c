#include <stdio.h>
#include <stdlib.h>

#include "headers/funcoes_menus.h"
#include "headers/constantes.h"
#include "headers/funcoes_ficheiros.h"

int main()
{

    tipoUnidadeCurricular uniCurriculares[MAX_UC] = {0};
    tipoAulaOnline aulasOnline[MAX_AULAS] = {0};
    int numUCs = 0, numAulas = 0;
    lerFiheiroBinarioUC(uniCurriculares, &numUCs);
    lerFiheiroBinarioAulasOnline(aulasOnline, &numAulas);
    char op;


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
            system("@cls||clear");
            menuAulas(aulasOnline, &numAulas);
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

    return 0;
}
