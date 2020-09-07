/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/*VARIÁVEIS*/
char lc_all;
char op;
int quant_sandu, valor_sandu;
int quant_coca, valor_coca;
int quant_pao, valor_pao;
int valor_total;
FILE * arq;
char op2;


/*MENU DE OPÇÕES*/
int main()
{
	inicio:
	system("color b0");
	system("cls");
	setlocale (lc_all, "");
	printf("========= PEDIDO ==========\n\n");
	printf("         opções:         \n");
	printf(" a. Sanduíche de presunto...R$ 8,00 \n");
	printf(" s. Coca-cola de café.......R$ 5,00\n");       /* Produtos a venda */
	printf(" d. Pão de queijo...........R$ 3,00\n\n");
	printf(" f. Cancelar compra       \n");
	printf(" j. Voltar ao menu        \n\n");
	
	fflush (stdin);
	op = getche();/* captura a opção escolida*/
	
	if (op == 'a')                                                                            /* SANDUÍCHE */
	{
	printf ("\n\nQuantos?\n");
	scanf ("%i", &quant_sandu);
	valor_sandu = quant_sandu * 8;
	arq = fopen ("lista_pedido.txt", "a"); /* criando arquivo com lista de pedido */
	fprintf(arq,"\nSanduíches de presunto (%i)...R$ %i,00", quant_sandu, valor_sandu);
	fclose(arq);
	printf ("\n\nMais alguma coisa? [s=sim] [n=não]\n");
	fflush (stdin);
	op2 = getche ();
		if (op2 == 's') /* Volta ao menu de opções */
		goto inicio;
		if (op2 =='n') /* Volta ao programa MENU_MQ */
		{
			arq = fopen ("lista_pedido.txt", "a");
			valor_total = valor_sandu + valor_coca + valor_pao;  /* calcula preço total*/
			fprintf(arq, "\n\nR$ %i", valor_total);
			fclose(arq);
			goto retorno_menu;
		} 
	}
	if (op == 's')                                                                               /* COCA */
	{
	printf ("\n\nQuantos?\n");
	scanf ("%i", &quant_coca);
	valor_coca = quant_coca * 5;
	arq = fopen ("lista_pedido.txt", "a"); /* criando arquivo com lista de pedidos */
	fprintf(arq,"\nCocas (%i)....................R$ %i,00", quant_coca, valor_coca);
	fclose(arq);
	printf ("\n\nMais alguma coisa? [s=sim] [n=não]\n");
	fflush (stdin);
	op2 = getche ();
		if (op2 == 's') /* Volta ao menu de opções */
		goto inicio;
		if (op2 =='n') /* Volta ao programa MENU_MQ */
		{
			arq = fopen ("lista_pedido.txt", "a");
			valor_total = valor_sandu + valor_coca + valor_pao;  /* calcula preço total*/
			fprintf(arq, "\n\nR$ %i", valor_total);
			fclose(arq);
			goto retorno_menu;
		}
	}
	if (op == 'd')                                                                          /* PÃO DE QUEIJO */
	{
	printf ("\n\nQuantos?\n");
	scanf ("%i", &quant_pao);
	valor_pao = quant_pao * 3;
	arq = fopen ("lista_pedido.txt", "a"); /* criando arquivo com lista de pedidos */
	fprintf(arq,"\nPães de queijo (%i)...........R$ %i,00", quant_pao, valor_pao);
	fclose(arq);
	printf ("\n\nMais alguma coisa? [s=sim] [n=não]\n");
	fflush (stdin);
	op2 = getche ();
		if (op2 == 's') /* Volta ao menu de opções */
		goto inicio;
		if (op2 =='n') /* Volta ao programa MENU_MQ */
		{
			arq = fopen ("lista_pedido.txt", "a");
			valor_total = valor_sandu + valor_coca + valor_pao;  /* calcula preço total*/
			fprintf(arq, "\n\nR$ %i", valor_total);
			fclose(arq);
			goto retorno_menu;
		} 
	}
	if (op == 'f')                                                                          /* CANCELA PEDIDO */
	{
	remove ("lista_pedido.txt");
	printf ("\n\nMais alguma coisa? [s=sim] [n=não]\n");
	fflush (stdin);
	op2 = getche ();
		if (op2 == 's') /* Volta ao menu de opções */
		goto inicio;
		if (op2 =='n') /* Volta ao programa MENU_MQ */
		goto retorno_menu;
	}
	if (op == 'j')                                                                       /* VOLTA AO PROGRAMA MENU */
	retorno_menu:
	system ("MENU");
	return 0;
}
