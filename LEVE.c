/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados.h"

/*VARIÁVEIS*/
char entrega;

/*CORPO DO PROGRAMA*/
int main()
{
	system("color b0");
	system("cls");
	setlocale (LC_ALL, "");
	printf("========= LEVE ==========\n\n");
	printf ("Pedido entregue? [s=sim]\n");
	fflush (stdin);
	scanf ("%c", &entrega);
	if (entrega == 's')
	{
	remove ("TICKET.TXT");
	system ("VENDAS");
	}
}
