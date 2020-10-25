/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados.h"

/*VARIÁVEIS*/
char entrega;

/*FUNÇÃO LEVE*/
void formadepagamento ()
{
    PAGAMENTOS = fopen ("ULTIMOPEDIDO.DAT", "r");
	fread(&pagto, sizeof(pagto), 1, PAGAMENTOS);
	if (pagto.valor == 1)
	{
		system("color 02");
		printf("PEDIDO nº%i PAGO COM DINHEIRO\n\n", pagto.codigo); 
	}
	if (pagto.valor == 2)
	{
		system("color 0d");
		printf("PEDIDO nº%i PAGO COM CARTÃO\n\n", pagto.codigo); 
	}
	if (pagto.valor == 3)
	{
		system("color 01");
		printf("PEDIDO nº%i PAGO COM CHEQUE\n\n", pagto.codigo); 
	}
	fclose (PAGAMENTOS);
}


/*CORPO DO PROGRAMA*/
int main()
{
	system("color 0b");
	system("cls");
	setlocale (LC_ALL, "");
	printf("============= LEVE ==============\n\n");
	PAGAMENTOS = fopen ("ULTIMOPEDIDO.DAT", "r");
	if (PAGAMENTOS == NULL)
			{
				system ("cls");
				printf("\n\n\tERRO! Nenhum pedido realizado");                          /*tenta abrir o arquivo .dat*/
				getch();
				system ("VENDAS");
				return (0);
			}
	fclose (PAGAMENTOS);
	formadepagamento();
	printf ("Pedido entregue? [s = sim] [n = não]\n");
	fflush (stdin);
	scanf ("%c", &entrega);
	if (entrega == 's' || entrega == 'S')
	{
		remove ("ULTIMOPEDIDO.DAT");
		remove ("TICKET.TXT");
	}
	
	system ("ADMIN");
	return (0);
}
