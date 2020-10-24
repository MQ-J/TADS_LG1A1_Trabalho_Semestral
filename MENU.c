/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/*VARIÁVEIS*/
char lc_all;
char op, op2;

/*CORPO DO PROGRAMA*/
int main()
{
	system("color 0b");
	system("cls");
	setlocale (lc_all, "");
	printf("                      mwmwmwmwmwmwmw\n");
	printf("                      MENU DE VENDAS\n");
	printf("                      mwmwmwmwmwmwmw\n\n");
	printf("==========\n");
	printf(" 1. pedido\n");
	printf(" 2. pague \n");
	printf(" 3. leve  \n");
	printf(" S. sair  \n");
	printf("==========\n");
	
	
	fflush (stdin);
	op = getche();
	
	/*chama o respectivo programa filho*/
	switch (op)
	{
	case '1': system ("PEDIDO"); break;
	case '2': system("PAGUE"); break;
	case '3': system("LEVE"); break;
	case 'S': case 's': exit(0); break;
	
	/*opção inválida*/
	default: printf("\n\t|          Opcão inválida! Digite:          |\n\t|[a = voltar] [qualquer outra tecla = sair] |\n");
	op2 = getche();
	if (op2 == 'a')
	main();
	}
	return (0);
}
