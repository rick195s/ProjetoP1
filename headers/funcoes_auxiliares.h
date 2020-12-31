#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#include "../headers/constantes.h"

float formatarHoraComDuracaoAula(int duracao, float hora, int sinal);
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void limpaBufferStdin(void);


#endif // FUNCOES_AUXILIARES_H_INCLUDED
