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

/*ESTRUTURA DE CARTÕES*/
typedef struct
{
	int codigo;
	int numbcartao[16];
} cartoes;

/*---------------------------------------*/

/*VARIÁVEIS DAS ESTRUTURAS*/
	produtos prod;
	pagamentos pagto;
	cartoes card;
	pedidos pedi;
/*---------------------------------------*/

/*ENDEREÇO DE MEMÓRIA DOS ARQUIVOS .DAT*/
	FILE * PRODUTOS;
	FILE * PAGAMENTOS;                                      /*os endereços tem o mesmo nome das respectivas estruturas para facilitar o entendimento*/
	FILE * CARTOES;
	FILE * PEDIDOS;
/*---------------------------------------*/

/*FUNÇÃO DE CONTAGEM AUTONUMÉRICA DE PRODUTOS*/
int conta_quant_produtos()
{
	PRODUTOS = fopen("PRODUTOS.DAT", "r");
	if (fopen == NULL)
		prod.codigo = 1;	
	else
	{
		if (fseek(PRODUTOS, 0, SEEK_END))
			prod.codigo =1;
		else
		{
			prod.codigo = (ftell(PRODUTOS) / sizeof(prod))+1;                                  /*contagem autonumérica que ignora o erro do fseek*/
		}
	}
	fclose(PRODUTOS);
	return(prod.codigo);
}

/*FUNÇÃO DE CONTAGEM AUTONUMÉRICA DE PAGAMENTOS*/
int conta_quant_pagamento()
{
	PAGAMENTOS = fopen("PAGAMENTOS.DAT", "r");
	if (fopen == NULL)
		prod.codigo = 1;	
	else
	{
		if (fseek(PAGAMENTOS, 0, SEEK_END))
			prod.codigo =1;
		else
		{
			pagto.codigo = (ftell(PAGAMENTOS) / sizeof(pagto))+1;                              /*contagem autonumérica que ignora o erro do fseek*/
		}
	}
	fclose(PAGAMENTOS);
	return(pagto.codigo);
}

/*FUNÇÃO DE CONTAGEM AUTONUMÉRICA DE CARTÓES*/
int conta_quant_cartao()
{
	CARTOES = fopen("CARTOES.DAT", "r");
	if (fopen == NULL)
	{
		CARTOES = fopen("CARTOES.DAT", "w");
		card.codigo = 1;
	}
	else
	{
		if (fseek(CARTOES, 0, SEEK_END))
			card.codigo =1;
		else
		{
			card.codigo = (ftell(CARTOES) / sizeof(card))+1;                              /*contagem autonumérica que ignora o erro do fseek*/
		}
	}
	fclose(CARTOES);
	return(card.codigo);
}
