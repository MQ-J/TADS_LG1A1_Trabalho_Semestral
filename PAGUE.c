/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "dados.h"

/*VARI�VEIS*/
char lc_all;
char op_pagament, op;
int conta_digito;
int numb;

/*FUN��ES*/
void confirma_pagto_a(void)
{
	printf("Pagamento concu�do? [s=sim] [n=n�o]\n");
	fflush(stdin);
	op = getch();
	switch (op)
	{
		case's': case'S':                                                      /*caso o pagamento seja conclu�do*/
		pagto.codigo = conta_quant_pagamento();                            /*chama o programa de contagem autonum�rica*/
		strcpy(pagto.forma, "dinheiro");
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);      /*s� ap�s a confirmma��o do pagamento os arquivos s�o enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		remove("ULTIMOPGTO.DAT");
		system ("LEVE");
		break;

		default:                                                         /* pagamento N�O conclu�do */
		system ("MENU");
		break;
	}
}

void confirma_pagto_b(void)
{
	printf("Pagamento concu�do? [s=sim] [n=n�o]\n");
	fflush(stdin);
	op = getch();
	switch (op)
	{
		case's': case'S':                                                        /*caso o pagamento seja conclu�do*/
		pagto.codigo = conta_quant_pagamento();                             /*chama o programa de contagem autonum�rica*/
		strcpy(pagto.forma, "cartao");
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);        /*s� ap�s a confirmma��o do pagamento os arquivos s�o enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		
		CARTOES = fopen("CARTOES.DAT", "a");
		fwrite(&card, sizeof(card), 1, CARTOES);            /*os arquivos s� s�o enviados para o CARTOES.DAT quando o pagamento � aprovado*/
		fclose(CARTOES);
		remove("ULTIMOPGTO.DAT");
		system ("LEVE");
		break;

		default:                                                          /* pagamento N�O conclu�do */
		system ("MENU");
		break;
	}
}

void confirma_pagto_c(void)
{
	printf("Pagamento concu�do? [s=sim] [n=n�o]\n");
	fflush(stdin);
	op = getch();
	switch (op)
	{
		case's': case'S':                                                     /*caso o pagamento seja conclu�do*/
		pagto.codigo = conta_quant_pagamento();                            /*chama o programa de contagem autonum�rica*/
		strcpy(pagto.forma, "cheque");
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);      /*s� ap�s a confirmma��o do pagamento os arquivos s�o enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		remove("ULTIMOPGTO.DAT");
		system ("LEVE");
		break;

		default:                                                        /* pagamento N�O conclu�do */
		system ("MENU");
		break;
	}
}

void confirma_cartao(void)
{
	int i;
	cartoes c;
	printf("Digite o n�mero do cart�o: ");
	for(i=0; i<16; i++)
	{
		fflush(stdin);	c.numbcartao[i] = getche();
	}
	for(i=4; i<12; i++)
	{
		c.numbcartao[i] = '*';
	}
	c.codigo = pagto.codigo;
	cadastracartao(c);
	printf("\n");
}

/*CORPO DO PROGRAMA*/
int main()
{
	system("color 0b");
	system("cls");
	setlocale (lc_all, "");
	float precototal;
	printf("========= PAGUE ==========\n\n");
	
	PEDIDOS = fopen ("ULTIMOPGTO.DAT", "r");
	if (PEDIDOS == NULL)
	{
		printf("OPA, nenhum pedido registrado, realize um pedido e tente novamente.");
		printf("\n\n\nPressione qualquer tecla para voltar ao menu\n");
		fflush(stdin); getch();
		system ("MENU");
	}
	while (!feof(PEDIDOS))
	fread(&pagto, sizeof(pagto), 1, PEDIDOS);
	fclose(PEDIDOS);
	precototal = pagto.valor;                              /*busca o valor total da compra no arquivo PEDIDOS.DAT para mostrar na tela*/
	printf("Pre�o total: R$ %.2f", precototal); 
	
	printf("\n\nQual a forma de pagamento?");
	printf("\n\n a = dinheiro\n b = cart�o de d�bito/cr�dito\n c = cheque\n\n");
	fflush(stdin);
	op_pagament = getch();
	switch (op_pagament)
	{
		case 'a': case 'A':
		confirma_pagto_a();
		break;
		
		case 'b': case 'B':
		confirma_cartao();
		confirma_pagto_b();
		break;
		
		case 'c': case 'C':
		confirma_pagto_c();
		break;
	}
	return (0);
}
