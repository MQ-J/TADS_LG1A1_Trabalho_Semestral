/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/*VARI�VEIS*/
char lc_all;
int pagament;

/*CORPO DO PROGRAMA*/
int main()
{
	system("color b0");
	system("cls");
	setlocale (lc_all, "");
	printf("========= PAGUE ==========\n\n");
	printf("O Pagamento foi realizado? [s=sim] [n=n�o]\n");
	fflush (stdin);
	scanf ("%c", &pagament);
	if (pagament =='s') /* pagamento conclu�do*/
	system ("LEVE_MQ");
	if (pagament =='n') /* pagamento N�O conclu�do */
	{
	remove ("lista_pedido.txt");
	system ("MENU_MQ");
	}
}
