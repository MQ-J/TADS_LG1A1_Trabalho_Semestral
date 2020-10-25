/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados.h"


/*VARI�VEIS*/
pedidos op;
FILE * arq;
int quantidadepedidos = 0;
float total = 0;
char sair;
pagamentos registropagamentos;

/*MENU DE OP��ES*/
int main()
{
	setlocale (LC_ALL, "");
	system("color 0b");
	system("cls");
	registropagamentos.codigo = conta_quant_pagamento("PAGAMENTOS.DAT")+1;
	do
	{
		printf("================= PEDIDO ==================\n");
		printf("           Produtos dispon�veis:             ");
		printf("\n-------------------------------------------");
		printf("\ncodigo  |    nome do produto       | valor ");                                    /*cabe�alho do menu*/
		printf("\n-------------------------------------------");
		PRODUTOS = fopen("PRODUTOS.DAT", "r");
		while( !feof(PRODUTOS))
		{
			fread(&prod, sizeof(prod), 1, PRODUTOS);                                          /*busca a lista de produtos em PRODUTOS.DAT*/
			if ( !feof(PRODUTOS) )
			printf("\n%-2i      |    %-22s| %-5.2f", prod.codigo, prod.nome, prod.custo);
		}
		printf("\n-------------------------------------------");
		fclose(PRODUTOS);
		
		printf("\nDigite o c�digo do produto desejado: ");
		fflush(stdin);
		scanf("%i", &op.produtopedido.codigo); /* captura a op��o escolida*/
		quantidadepedidos++;
		PesquisarPedido (&op.produtopedido);
		do
		{
			printf ("\nQuantos %s voc� deseja? ", op.produtopedido.nome);
				fflush(stdin);
				scanf("%i", &op.quant);
				if (op.quant < 1)    
		    	{
					printf ("\nQuantidade inv�lida!");
		        	getch();
		    	}
		}
		while (op.quant < 1);
		
		op.custo = op.quant * op.produtopedido.custo;
		total = total + op.custo;
		ticket (registropagamentos.codigo, quantidadepedidos, op, total, '0');
		printf ("\nO total do pedido at� o momento � de: R$ %6.2f", total);
		printf ("\n\nDeseja pedir mais alguma coisa? [S = sim] ou [N = n�o]");
		fflush (stdin);
		sair = getch();
    }
    while ( sair == 'S' || sair == 's');
    ticket (registropagamentos.codigo, ++quantidadepedidos, op, total, '1');
    system ("cls");
	system ("NOTEPAD TICKET.TXT");
	registropagamentos.valor = total;
	RegistrarPedido (registropagamentos, '1');
	system ("MENU");
	return 0;
}
