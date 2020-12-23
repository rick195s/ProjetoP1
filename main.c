#include <stdio.h>
#include <stdlib.h>

#include "headers/funcoes_menus.h"
#include "headers/constantes.h"

int main()
{

    tipoUnidadeCurricular uniCurriculares[MAX_UC] = {0};
    int numUCs = 0;

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
