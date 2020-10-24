/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados.h"

/*VARIÁVEIS*/
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
	setlocale (LC_ALL, "");
	printf("================= PEDIDO ==================\n");
	printf("           Produtos disponíveis:             ");
	printf("\n-------------------------------------------");
	printf("\ncodigo  |    nome do produto       | valor ");                                    /*cabeçalho do menu*/
	printf("\n-------------------------------------------");
	PRODUTOS = fopen("PRODUTOS.DAT", "r");
	while( !feof(PRODUTOS))
	{
		fread(&prod, sizeof(prod), 1, PRODUTOS);                                          /*busca a lista de produtos em PRODUTOS.DAT*/
		if ( !feof(PRODUTOS) )
		printf("\n%-2i      |    %-22s| %-5.2f", prod.codigo, prod.nome, prod.custo);
	}
	printf("\n-------------------------------------------");
	printf("\n        | f. Cancelar compra       |");
	printf("\n        | j. Voltar ao menu        |");
	printf("\n-------------------------------------------");
	fclose(PRODUTOS);
	
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
