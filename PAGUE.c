/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados.h"

/*VARIÁVEIS*/
char lc_all;
char op_pagament, op;
int conta_digito;
int numb;

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
		printf("Pagamento concuído? [s=im] [n=não]\n");
		fflush(stdin);	scanf("%c", &op);
		switch (op)
		{
			case's': case'S':                                              /*pagamento concluído*/
			pagto.codigo = contagem(pagto.codigo);
			strcpy(pagto.forma, "dinheiro");
			pagto.valor = pedi.custototal;
			PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
			fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);
			fclose(PAGAMENTOS);
			system ("LEVE");
			break;
			
			case'n': case'N':                                            /* pagamento NÃO concluído */
			system ("MENU");
			break;
		}
		break;
		
		
		case 'c': case 'C':
		printf("Pagamento concuído? [s=im] [n=não]\n");
		fflush(stdin);	scanf("%c", &op);
		switch (op)
		{
			case's': case'S':                                              /*pagamento concluído*/
			/*contagem auto numerica do numero do pedido*/
			pagto.codigo++;
			strcpy(pagto.forma, "cheque");
			pagto.valor = pedi.custototal;
			PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
			fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);
			fclose(PAGAMENTOS);
			system ("LEVE");
			break;
			
			case'n': case'N':                                            /* pagamento NÃO concluído */
			system ("MENU");
			break;
		}
		break;
		
		case 'b': case 'B':
		conta_digito = 0;
		printf("Digite o número do cartão: ");
		fflush(stdin);
		do
		{
			numb = getch();
			printf("*");
			conta_digito++;
		}
		while (conta_digito <= 15);
		printf("Pagamento concuído? [s=im] [n=não]\n");
		fflush(stdin);	scanf("%c", &op);
		switch (op)
		{
			case's': case'S':                                              /*pagamento concluído*/
			/*contagem auto numerica do numero do pedido*/
			pagto.codigo++;
			strcpy(pagto.forma, "cartao");
			pagto.valor = pedi.custototal;
			PAGAMENTOS = fopen("PAGAMENTOS.DAT", "a");
			fwrite(&pagto, sizeof(pagto), 1, PAGAMENTOS);
			fclose(PAGAMENTOS);
			system ("LEVE");
			break;
			
			case'n': case'N':                                            /* pagamento NÃO concluído */
			system ("MENU");
			break;
		}
		break;
	}
}
