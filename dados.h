/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
/*---------------------------------------*/

/*ESTRUTURA DE PRODUTOS*/
typedef struct
{
	int codigo;
	char nome[22+1];
	float custo;
} produtos;

/*ESTRUTURA DE PEDIDOS*/
typedef struct
{
	produtos produtopedido;
	int quant;
	float custo;
} pedidos;

/*ESTRUTURA DE PAGAMENTOS*/
typedef struct
{
	int codigo;
	char forma[8+1];
	float valor;
} pagamentos;

/*ESTRUTURA DE CARTÕES*/
typedef struct
{
	int codigo;
	char numbcartao[16];
} cartoes;

/*---------------------------------------*/

/*VARIÁVEIS DAS ESTRUTURAS*/
	pedidos pedi;
	produtos prod;
	pagamentos pagto;
	cartoes card;
/*---------------------------------------*/

/*ENDEREÇO DE MEMÓRIA DOS ARQUIVOS .DAT*/
	FILE * PRODUTOS;
	FILE * PAGAMENTOS;                                      /*os endereços tem o mesmo nome das respectivas estruturas para facilitar o entendimento*/
	FILE * CARTOES;
	FILE * PEDIDOS;
	FILE * TICKET;

/*---------------------------------------*/
/*FUNÇÃO DE ERRO*/
void  falha (void)
{
	system ("cls");
	printf ("ALGO DEU ERRADO, ABORTAR MISSÃO!");
	getch();
	exit(0);
}

/*FUNÇÃO DE CONTAGEM AUTONUMÉRICA DE PRODUTOS*/
int conta_quant_produtos()
{
	PRODUTOS = fopen("PRODUTOS.DAT", "r");
	if (fopen == NULL)
		prod.codigo = 1;	
	else
	{
		if (fseek(PRODUTOS, 0, SEEK_END))
			prod.codigo =1;
		else
		{
			prod.codigo = (ftell(PRODUTOS) / sizeof(prod))+1;                                  /*contagem autonumérica que ignora o erro do fseek*/
		}
	}
	fclose(PRODUTOS);
	return(prod.codigo);
}

/*FUNÇÃO DE CONTAGEM AUTONUMÉRICA DE PAGAMENTOS*/
int conta_quant_pagamento()
{
	PAGAMENTOS = fopen("PAGAMENTOS.DAT", "r");
	if (fopen == NULL)
		prod.codigo = 1;	
	else
	{
		if (fseek(PAGAMENTOS, 0, SEEK_END))
			prod.codigo =1;
		else
		{
			pagto.codigo = (ftell(PAGAMENTOS) / sizeof(pagto))+1;                              /*contagem autonumérica que ignora o erro do fseek*/
		}
	}
	fclose(PAGAMENTOS);
	return(pagto.codigo);
}

/*FUNÇÃO DE CADASTRO DE CARTÓES*/
void cadastracartao(cartoes C)
{
	CARTOES = fopen("CARTOES.DAT", "a");
	if (fopen == NULL)
	{
		falha();
	}
	else
	{
    	fwrite (&C, sizeof(C), 1, CARTOES);
    	if (ferror(CARTOES))
    	{
			falha();
		}
	}	
	fclose(CARTOES);
	
}

/*FUNÇÃO DE PEDIDO*/
void PesquisarPedido (produtos * Ped)
{
	produtos lerpedido; 
	PRODUTOS = fopen ("PRODUTOS.DAT", "r");	
	if (PRODUTOS == NULL)
	{
	   	falha();
	}
	else
    {    
   		while (!feof(PRODUTOS))
   		{ 
			fread (&lerpedido, sizeof(lerpedido), 1, PRODUTOS);
        		if (ferror(PRODUTOS))
        		{
					falha();
				}
	        	if (!feof(PRODUTOS))
	           		if (Ped->codigo == lerpedido.codigo)
	           	{
	            	*Ped = lerpedido;
	            	break;
	           	}
	   }
	fclose(PRODUTOS);
   }
}
/*FUNÇÃO PARA REGISTRAR PEDIDOS*/
void RegistrarPedido (pagamentos criarpedido, char controle)
{
	if (controle == '1')
		PEDIDOS = fopen ("ULTIMOPGTO.DAT", "w");
	else
		falha();
	if (PEDIDOS == NULL)
		falha();
	fwrite (&criarpedido, sizeof (criarpedido), 1, PEDIDOS);
	if (ferror (PEDIDOS))
		falha();

	fclose (PEDIDOS);
}
/*FUNÇÃO PARA CRIAR TICKET DO ULTIMO PEDIDO*/
void ticket (int numeropedido, int quant, pedidos dadospedido, float total, char controle)
{
	setlocale(LC_ALL,"");
	if (quant==1)
        TICKET = fopen ("TICKET.TXT", "w");
    else
		TICKET = fopen ("TICKET.TXT", "a");
    
	if (TICKET == NULL)
    {
		printf ("\nErro ao gerar o Ticket");
    	getch();
	}
	else
	{
		if (quant==1)
        {
			fprintf (TICKET, "===============================================\n");
			fprintf (TICKET, "=================== TICKET ====================\n");
			fprintf (TICKET, "===============================================\n");
			fprintf (TICKET, "\tNúmero do pedido: %i\n", numeropedido);
			fprintf (TICKET, "===============================================\n");
	   		fprintf (TICKET, "Cód - Produto   - Unidade - Quant - Valor Total\n");
	   		fprintf (TICKET, "===============================================\n");
    	}
		if (controle == '1')
        {
			fprintf (TICKET, "===============================================\n");
			fprintf (TICKET, "\t\tTOTAL R$ %5.2f\n", total);
			fprintf (TICKET, "===============================================\n");
		}
		else
			fprintf (TICKET, "\n%2i - %-10s -  %.2f - %3i - %5.2f\n", dadospedido.produtopedido.codigo, dadospedido.produtopedido.nome, dadospedido.produtopedido.custo, dadospedido.quant, dadospedido.custo);
	}
	fclose (TICKET);
}

