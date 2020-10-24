/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*ESTRUTURA DE PRODUTOS*/
typedef struct
{
	int codigo;
	char nome[22+1];
	float custo;
} produtos;

/*ESTRUTURA DE PAGAMENTOS*/
typedef struct
{
	int codigo;
	char forma[8+1];
	float valor;
} pagamentos;

/*ESTRUTURA DE CARTÕES*/
typedef struct
{
	int codigo;
	int numbcartao;
} cartoes;

/*VARIÁVEIS DAS ESTRUTURAS*/
	produtos prod;
	pagamentos pagto;
	cartoes card;

/*ENDEREÇO DE MEMÓRIA DOS ARQUIVOS .DAT*/
	FILE * PRODUTOS;
	FILE * PAGAMENTOS;                       /*os endereços tem o mesmo nome das respectivas estruturas para facilitar o entendimento*/
	FILE * CARTOES;
