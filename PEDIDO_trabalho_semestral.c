/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/*VARIÁVEIS*/
char lc_all;
char op;
int quant_sandu;
int quant_coca;
int quant_pao;
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
	printf(" a. Sanduíche de presunto \n");
	printf(" s. Coca-cola de café     \n");       /* Produtos a venda */
	printf(" d. Pão de queijo         \n");
	printf(" f. Cancelar compra       \n");
	printf(" j. Voltar ao menu        \n\n");
	
	fflush (stdin);
	op = getche();/* captura a opção escolida*/
	
	if (op == 'a') /* SANDUÍCHE */
	{
	printf ("\n\nQuantos?\n");
	scanf ("%u", &quant_sandu);
	arq = fopen ("lista_pedido.txt", "a"); /* criando arquivo com lista de pedido */
	fprintf(arq,"\nSanduíches de presunto: %u", quant_sandu);
	fclose(arq);
	printf ("\n\nMais alguma coisa? [s=sim] [n=não]\n");
	fflush (stdin);
	op2 = getche ();
		if (op2 == 's') /* Volta ao menu de opções */
		goto inicio;
		if (op2 =='n') /* Volta ao programa MENU_MQ */
		goto retorno_menu; 
	}
	if (op == 's') /* COCA */
	{
	printf ("\n\nQuantos?\n");
	scanf ("%u", &quant_coca);
	arq = fopen ("lista_pedido.txt", "a"); /* criando arquivo com lista de pedidos */
	fprintf(arq,"\nCocas: %u", quant_coca);
	fclose(arq);
	printf ("\n\nMais alguma coisa? [s=sim] [n=não]\n");
	fflush (stdin);
	op2 = getche ();
		if (op2 == 's') /* Volta ao menu de opções */
		goto inicio;
		if (op2 =='n') /* Volta ao programa MENU_MQ */
		goto retorno_menu; 
	}
	if (op == 'd') /* PÃO DE QUEIJO */
	{
	printf ("\n\nQuantos?\n");
	scanf ("%u", &quant_pao);
	arq = fopen ("lista_pedido.txt", "a"); /* criando arquivo com lista de pedidos */
	fprintf(arq,"\nPães de queijo: %u", quant_pao);
	fclose(arq);
	printf ("\n\nMais alguma coisa? [s=sim] [n=não]\n");
	fflush (stdin);
	op2 = getche ();
		if (op2 == 's') /* Volta ao menu de opções */
		goto inicio;
		if (op2 =='n') /* Volta ao programa MENU_MQ */
		goto retorno_menu; 
	}
	if (op == 'f') /* CANCELA PEDIDO */
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
	if (op == 'j') /* VOLTA AO PROGRAMA MENU */
	retorno_menu:
	system ("MENU_MQ");
	return 0;
}
