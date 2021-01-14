#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#include "../headers/constantes.h"

void mostrarMensagem(char mensagem[MAX_STRING], int tipo);
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
tipoData lerData(void);
void limpaBufferStdin(void);



#endif // FUNCOES_AUXILIARES_H_INCLUDED
