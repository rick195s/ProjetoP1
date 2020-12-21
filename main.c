#include <stdio.h>
#include <stdlib.h>

#include "headers/funcoes_menus.h"

int main()
{

    char op;


    do
    {
        op=menuPrincipal();

        switch(op)
        {
        case 'U':
            system("@cls||clear");
            menuUC();
            break;
        case 'A':

            break;
        case 'E':
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
