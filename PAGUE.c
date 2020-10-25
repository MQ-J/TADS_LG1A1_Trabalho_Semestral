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
cartoes c;

/*FUN��ES*/
void confirma_pagto_a(void)
{
	printf("Pagamento concu�do? [s=sim] [n=n�o]\n");
	fflush(stdin);
	scanf("%c", &op);
	switch (op)
	{
		case's': case'S':                                                      /*caso o pagamento seja conclu�do*/
		pagto.codigo = conta_quant_pagamento();                            /*chama o programa de contagem autonum�rica*/
		strcpy(pagto.forma, "dinheiro");
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);      /*s� ap�s a confirmma��o do pagamento os arquivos s�o enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		pagto.valor = 1;
		PEDIDOS = fopen("ULTIMOPEDIDO.DAT", "w");
		fwrite(&pagto, sizeof(pagto), 1, PEDIDOS);
		fclose(PEDIDOS);
		system ("LEVE");
		break;

		default:                                                         /* pagamento N�O conclu�do */
		system ("VENDAS");
		break;
	}
}

void confirma_pagto_b(void)
{
	printf("Pagamento concu�do? [s=sim] [n=n�o]\n");
	fflush(stdin);
	scanf("%c", &op);
	switch (op)
	{
		case's': case'S':                                                        /*caso o pagamento seja conclu�do*/
		pagto.codigo = conta_quant_pagamento();                             /*chama o programa de contagem autonum�rica*/
		c.codigo = pagto.codigo;
		strcpy(pagto.forma, "cartao");
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);        /*s� ap�s a confirmma��o do pagamento os arquivos s�o enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		pagto.valor = 2;
		PEDIDOS = fopen("ULTIMOPEDIDO.DAT", "w");
		fwrite(&pagto, sizeof(pagto), 1, PEDIDOS);
		fclose(PEDIDOS);
		cadastracartao(c);
		system ("LEVE");
		break;

		default:                                                          /* pagamento N�O conclu�do */
		system ("VENDAS");
		break;
	}
}

void confirma_pagto_c(void)
{
	printf("Pagamento concu�do? [s=sim] [n=n�o]\n");
	fflush(stdin);
	scanf("%c", &op);
	switch (op)
	{
		case's': case'S':                                                     /*caso o pagamento seja conclu�do*/
		pagto.codigo = conta_quant_pagamento();                            /*chama o programa de contagem autonum�rica*/
		strcpy(pagto.forma, "cheque");
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);      /*s� ap�s a confirmma��o do pagamento os arquivos s�o enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		pagto.valor = 3;
		PEDIDOS = fopen("ULTIMOPEDIDO.DAT", "w");
		fwrite(&pagto, sizeof(pagto), 1, PEDIDOS);
		fclose(PEDIDOS);
		system ("LEVE");
		break;

		default:                                                        /* pagamento N�O conclu�do */
		system ("VENDAS");
		break;
	}
}

void mascara_cartao(void)
{
	int i;
	printf("Digite o n�mero do cart�o: ");
	for(i=0; i<16; i++)
	{
		fflush(stdin);	c.numbcartao[i] = getche();
	}
	for(i=4; i<12; i++)
	{
		c.numbcartao[i] = '*';
	}
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
	
	PEDIDOS = fopen ("ULTIMOPEDIDO.DAT", "r");
	if (PEDIDOS == NULL)
	{
		system("cls");
		printf("\n\n\tOPA, nenhum pedido registrado, realize um pedido e tente novamente.");
		printf("\n\n\tPressione qualquer tecla para voltar ao menu\n");
		fflush(stdin); getch();
		system ("VENDAS");
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
		mascara_cartao();
		confirma_pagto_b();
		break;
		
		case 'c': case 'C':
		confirma_pagto_c();
		break;
	}
	return (0);
}
