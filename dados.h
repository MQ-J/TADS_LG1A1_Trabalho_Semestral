/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*---------------------------------------*/

/*ESTRUTURA DE PRODUTOS*/
typedef struct
{
	int codigo;
	char nome[22+1];
	float custo;
} produtos;

/*ESTRUTURA DE PEDIDOS*/
typedef struct
{
	int codigo;
	char nome[22+1];
	float custo;
	int quant;
	float custoitem;
	float custototal;
} pedidos;

/*ESTRUTURA DE PAGAMENTOS*/
typedef struct
{
	int codigo;
	char forma[8+1];
	float valor;
} pagamentos;

/*ESTRUTURA DE CART�ES*/
typedef struct
{
	int codigo;
	int numbcartao;
} cartoes;
/*---------------------------------------*/

/*VARI�VEIS DAS ESTRUTURAS*/
	produtos prod;
	pagamentos pagto;
	cartoes card;
	pedidos pedi;
/*---------------------------------------*/

/*ENDERE�O DE MEM�RIA DOS ARQUIVOS .DAT*/
	FILE * PRODUTOS;
	FILE * PAGAMENTOS;                       /*os endere�os tem o mesmo nome das respectivas estruturas para facilitar o entendimento*/
	FILE * CARTOES;
	FILE * PEDIDOS;
/*---------------------------------------*/

/*FUN��O DE CONTAGEM AUTONUM�RICA*/
int contagem(int valor)
{
	valor++;
	return(valor);
}

