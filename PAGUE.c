/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "dados.h"

/*VARIÁVEIS*/
char lc_all;
char op_pagament, op;
int conta_digito;
int numb;

/*FUNÇÕES*/
void confirma_pagto_a(void)
{
	printf("Pagamento concuído? [s=im] [n=não]\n");
	fflush(stdin);	scanf("%c", &op);
	switch (op)
	{
		case's': case'S':                                                      /*caso o pagamento seja concluído*/
		pagto.codigo = conta_quant_pagamento();                            /*chama o programa de contagem autonumérica*/
		strcpy(pagto.forma, "dinheiro");
		pagto.valor = pedi.custototal;
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);      /*só após a confirmmação do pagamento os arquivos são enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		system ("LEVE");
		break;

		case'n': case'N':                                                         /* pagamento NÃO concluído */
		system ("MENU");
		break;
	}
}

void confirma_pagto_b(void)
{
	printf("Pagamento concuído? [s=im] [n=não]\n");
	fflush(stdin);	scanf("%c", &op);
	switch (op)
	{
		case's': case'S':                                                        /*caso o pagamento seja concluído*/
		pagto.codigo = conta_quant_pagamento();                             /*chama o programa de contagem autonumérica*/
		strcpy(pagto.forma, "cartao");
		pagto.valor = pedi.custototal;
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);        /*só após a confirmmação do pagamento os arquivos são enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		
		CARTOES = fopen("CARTOES.DAT", "r");
		fwrite(&card, sizeof(card), 1, CARTOES);            /*os arquivos só são enviados para o CARTOES.DAT quando o pagamento é aprovado*/
		fclose(CARTOES);
	
		system ("LEVE");
		break;

		case'n': case'N':                                                          /* pagamento NÃO concluído */
		system ("MENU");
		break;
	}
}

void confirma_pagto_c(void)
{
	printf("Pagamento concuído? [s=im] [n=não]\n");
	fflush(stdin);	scanf("%c", &op);
	switch (op)
	{
		case's': case'S':                                                     /*caso o pagamento seja concluído*/
		pagto.codigo = conta_quant_pagamento();                            /*chama o programa de contagem autonumérica*/
		strcpy(pagto.forma, "cheque");
		pagto.valor = pedi.custototal;
		PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
		fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);      /*só após a confirmmação do pagamento os arquivos são enviados para PAGAMENTOS.DAT*/
		fclose(PAGAMENTOS);
		system ("LEVE");
		break;

		case'n': case'N':                                                        /* pagamento NÃO concluído */
		system ("MENU");
		break;
	}
}

void confirma_cartao(void)
{
	int i;
	card.codigo = conta_quant_cartao();
	printf("Digite o número do cartão: ");
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
	printf("Preço total: R$ %.2f", precototal); 
	
	printf("\n\nQual a forma de pagamento?");
	printf("\n\n a = dinheiro\n b = cartão de débito/crédito\n c = cheque\n\n");
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
