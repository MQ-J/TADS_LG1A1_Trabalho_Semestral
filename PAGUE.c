/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/*VARI�VEIS*/
char lc_all;
char pagament, op;
int op_card, conta_digito;
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
	
	printf("\n\nQual a forma de pagamento?");
	printf("\n\n a = dinheiro\n b = cart�o de d�bito/cr�dito\n c = cheque\n\n");
	fflush(stdin);
	scanf ("%c", &pagament);
	switch (pagament)
	{
		case 'a': case 'A': case 'c': case 'C':
		printf("Pagamento concu�do?\n");
		fflush(stdin);
		scanf ("%c", &op);
		if (op == 's')                                         /*pagamento conclu�do*/
		system ("LEVE");
		if (op =='n')                                       /* pagamento N�O conclu�do */
		{
			remove ("lista_pedido.txt");
			system ("MENU");
		}
		break;
		
		case 'b': case 'B':
		conta_digito = 0;
		printf("Digite o n�mero do cart�o: ");
		fflush(stdin);
		do
		{
			op_card = getch();
			printf("*");
			conta_digito++;
		}
		while (conta_digito <= 15);
		printf("\nPagamento concu�do?\n");
		fflush(stdin);
		scanf ("%c", &op);
		if (op == 's')                                         /*pagamento conclu�do*/
		system ("LEVE");
		if (op =='n')                                       /* pagamento N�O conclu�do */
		{
			remove ("lista_pedido.txt");
			system ("MENU");
		}
		break;
	}
}
