/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados.h"

/*VARI�VEIS*/
char lc_all;
int entrega;

/*CORPO DO PROGRAMA*/
int main()
{
	system("color b0");
	system("cls");
	setlocale (lc_all, "");
	printf("========= LEVE ==========\n\n");
	printf ("Pedido entregue? [s=sim]\n");
	fflush (stdin);
	scanf ("%c", &entrega);
	if (entrega == 's')
	{
	remove ("lista_pedido.txt");
	system ("MENU");
	}
}
