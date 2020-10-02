/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/*VARIÁVEIS*/
char lc_all;
char op;

/*CORPO DO PROGRAMA*/
int main()
{
	system("color 0b");
	system("cls");
	setlocale (lc_all, "");
	printf("                      wmwmwmwmwmwmwmw\n");
	printf("                           MENU\n");
	printf("                      wmwmwmwmwmwmwmw\n\n");
	printf("==========\n");
	printf(" 1.pedido\n");
	printf(" 2.pague\n");
	printf(" 3.leve\n");
	printf(" S.sair\n");
	printf("==========\n ");
	
	fflush (stdin);
	op = getche ();	/*captura a opção escolhida*/
	
	/*chama o respectivo programa filho*/
	switch (op)
	{
	case '1': system ("PEDIDO"); break;
	case '2': system("PAGUE"); break;
	case '3': system("LEVE"); break;
	case 'S': case 's': exit(0); break;
	}
	return 0;
}
