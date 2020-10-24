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
	printf("Pagamento concu�do? [s=im] [n=n�o]\n");
	fflush(stdin);	scanf("%c", &op);
	switch (op)
	{
		case's': case'S':                                                      /*caso o pagamento seja conclu�do*/
		pagto.codigo = conta_quant_pagamento();                            /*chama o programa de contagem autonum�rica*/
		strcpy(pagto.forma, "dinheiro");
		pagto.valor = pedi.custototal;
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);      /*s� ap�s a confirmma��o do pagamento os arquivos s�o enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		system ("LEVE");
		break;

		case'n': case'N':                                                         /* pagamento N�O conclu�do */
		system ("MENU");
		break;
	}
}

void confirma_pagto_b(void)
{
	printf("Pagamento concu�do? [s=im] [n=n�o]\n");
	fflush(stdin);	scanf("%c", &op);
	switch (op)
	{
		case's': case'S':                                                        /*caso o pagamento seja conclu�do*/
		pagto.codigo = conta_quant_pagamento();                             /*chama o programa de contagem autonum�rica*/
		strcpy(pagto.forma, "cartao");
		pagto.valor = pedi.custototal;
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);        /*s� ap�s a confirmma��o do pagamento os arquivos s�o enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		
		CARTOES = fopen("CARTOES.DAT", "r");
		fwrite(&card, sizeof(card), 1, CARTOES);            /*os arquivos s� s�o enviados para o CARTOES.DAT quando o pagamento � aprovado*/
		fclose(CARTOES);
	
		system ("LEVE");
		break;

		case'n': case'N':                                                          /* pagamento N�O conclu�do */
		system ("MENU");
		break;
	}
}

void confirma_pagto_c(void)
{
	printf("Pagamento concu�do? [s=im] [n=n�o]\n");
	fflush(stdin);	scanf("%c", &op);
	switch (op)
	{
		case's': case'S':                                                     /*caso o pagamento seja conclu�do*/
		pagto.codigo = conta_quant_pagamento();                            /*chama o programa de contagem autonum�rica*/
		strcpy(pagto.forma, "cheque");
		pagto.valor = pedi.custototal;
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);      /*s� ap�s a confirmma��o do pagamento os arquivos s�o enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		system ("LEVE");
		break;

		case'n': case'N':                                                        /* pagamento N�O conclu�do */
		system ("MENU");
		break;
	}
}

void confirma_cartao(void)
{
	int i;
	card.codigo = conta_quant_cartao();
	printf("Digite o n�mero do cart�o: ");
	for(i=0; i<=16; i++)
	{
		fflush(stdin);	card.numbcartao[i] = getche();
		printf("*");
	}
	for(i = 4; i <=11; i++)
	card.numbcartao[i] = '*';
}

/*CORPO DO PROGRAMA*/
int main()
{
	system("color b0");
	system("cls");
	setlocale (lc_all, "");
	float precototal;
	printf("========= PAGUE ==========\n\n");
	
	PEDIDOS = fopen ("PEDIDOS.DAT", "r");
	while (!feof(PEDIDOS))
	fread(&pedi, sizeof(pedi), 1, PEDIDOS);
	fclose(PEDIDOS);
	precototal = pedi.custototal;                              /*busca o valor total da compra no arquivo PEDIDOS.DAT para mostrar na tela*/
	printf("Pre�o total: R$ %.2f", precototal); 
	
	printf("\n\nQual a forma de pagamento?");
	printf("\n\n a = dinheiro\n b = cart�o de d�bito/cr�dito\n c = cheque\n\n");
	fflush(stdin);	scanf("%c", &op_pagament);
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
