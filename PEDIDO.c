/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados.h"


/*VARIÁVEIS*/
pedidos op;
FILE * arq;
int quantidadepedidos = 0;
float total = 0;
char sair;
pagamentos registropagamentos;

/*MENU DE OPÇÕES*/
int main()
{
	setlocale (LC_ALL, "");
	system("color 0b");
	system("cls");
	registropagamentos.codigo = conta_quant_pagamento("PAGAMENTOS.DAT")+1;
	do
	{
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
		fclose(PRODUTOS);
		
		printf("\nDigite o código do produto desejado: ");
		fflush(stdin);
		scanf("%i", &op.produtopedido.codigo); /* captura a opção escolida*/
		quantidadepedidos++;
		PesquisarPedido (&op.produtopedido);
		do
		{
			printf ("\nQuantos %s você deseja? ", op.produtopedido.nome);
				fflush(stdin);
				scanf("%i", &op.quant);
				if (op.quant < 1)    
		    	{
					printf ("\nQuantidade inválida!");
		        	getch();
		    	}
		}
		while (op.quant < 1);
		
		op.custo = op.quant * op.produtopedido.custo;
		total = total + op.custo;
		ticket (registropagamentos.codigo, quantidadepedidos, op, total, '0');
		printf ("\nO total do pedido até o momento é de: R$ %6.2f", total);
		printf ("\n\nDeseja pedir mais alguma coisa? [S = sim] ou [N = não]");
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
