/*BIBLIOTECAS*/
#include <stdio.h>
#include <stdlib.h> /*usar system()*/
#include <conio.h> /*usar getch()*/
#include <locale.h> /*usar acentua��o*/
#include <string.h> /*para o gets() funcionar*/

/*ESTRUTURA DE DADOS*/
typedef struct
{
	int codigo;
	char nome[20+1];
	float custo;
}
produtos;

/*VARI�VEIS*/
produtos	busca_produtos;
char op;

/*SALVA DADOS NA ESTRUTURA*/
int main()
{
	setlocale(LC_ALL, "");
	system("color b0");
	do
	{
	system("cls");
	busca_produtos.codigo = busca_produtos.codigo + 1;
	printf("Insira o nome do produto: ");
	fflush(stdin);
	gets(busca_produtos.nome); 
	printf("Insira o pre�o do produto: ");
	fflush(stdin);
	scanf("%f", &busca_produtos.custo);
	printf("<><><><><><><><><><><><><><>\n");
	printf("     CONFIRMANDO DADOS      \n\n");
	printf("c�digo: %i \n", busca_produtos.codigo);
	printf("Nome: %s \n", busca_produtos.nome);
	printf("pre�o: %.2f \n", busca_produtos.custo);
	printf("\n\nCadastrar mais produtos? [s=sim][n=n�o]");
	fflush(stdin);
	op = getche();
	}
	while (op != 'n');
	getch();
	return (0);
}

/*
PROXIMAS ETAPAS - (minha parte: menu e cobran�as)

1- ter a op��o de editar os dados da estrutura na parte "confirmando dados"
2- salvar os dados da estrutura em arquivo .dat
3- ler esse arquivo .dat para fazer alguma coisa
4- arrumar o "lc_all" em todos os progrmas do projeto
*/
