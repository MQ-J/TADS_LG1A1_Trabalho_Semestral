/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/*VARI�VEIS*/
char lc_all;
int pagament;
int tam;
FILE * arq;
int preco_total;

/*CORPO DO PROGRAMA*/
int main()
{
	system("color b0");
	system("cls");
	setlocale (lc_all, "");
	printf("========= PAGUE ==========\n\n");
	
	arq = fopen ("lista_pedido.txt", "r");
	tam= -2;
	fseek(arq, tam, SEEK_END);                         /* busca o valor total da compra no recibo */
	while (!feof(arq))
	fscanf(arq, "%i", &preco_total);
	fclose(arq);
	
	printf("Pre�o total: R$ %i", preco_total); 
	printf("\n\nO Pagamento foi realizado? [s=sim] [n=n�o]\n");
	fflush (stdin);
	scanf ("%c", &pagament);
	if (pagament =='s')                                         /* pagamento conclu�do*/
	system ("LEVE");
	if (pagament =='n')                                       /* pagamento N�O conclu�do */
	{
	remove ("lista_pedido.txt");
	system ("MENU");
	}
}
