/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados.h"

/*CADASTRAR PROUTOS*/
void cadastro(void)
{
	system("color 0b");
	setlocale(LC_ALL,"");                                                                            /*vari�veis locais e outras defini��es*/
	char op;
	
	PRODUTOS = fopen("PRODUTOS.DAT", "r");
	if (fopen == NULL)
		prod.codigo = 1;	
	else
	{
		if (fseek(PRODUTOS, 0, SEEK_END))
			prod.codigo =1;
		else
		{
			prod.codigo = (ftell(PRODUTOS) / sizeof(prod))+1;                                  /*contagem autonum�rica que ignora o erro do fseek*/
		}
	}
	fclose(PRODUTOS);

	printf("\n\n\tInsira o nome do produto: "); fflush(stdin); gets(prod.nome);
	printf("\tInsira o valor do produto: "); fflush(stdin); scanf("%f", &prod.custo);                 /*definindo nome e valor do produto*/
	PRODUTOS = fopen("PRODUTOS.DAT", "a"); if (fopen == NULL) PRODUTOS = fopen("PRODUTOS.DAT", "w");
	fwrite(&prod, sizeof(prod), 1, PRODUTOS);
	fclose(PRODUTOS);
	
	printf("\n\tCadastrar novo produto? [s = sim] [qualquer outra tecla = n�o]\n\t");
	fflush(stdin); op = getche();                                                                    /*pergunta se quer cadastrar outro produto*/
	switch(op)
	{
		case's': case'S': cadastro(); break;
		default: main();
	}
}

/*VERIFICAR PRODUTOS*/
void verifica(void)
{
	system("color 0b");                                                                    /*vari�veis locais e outras defini��es*/
	setlocale(LC_ALL,"");
	char op;
	
	PRODUTOS = fopen("PRODUTOS.DAT", "r");
	if (PRODUTOS == NULL)
	{
		printf("\n\n\tERRO! Crie um produto ou verifique os existentes");                          /*tenta abrir o arquivo .dat*/
		getch();
		main();
	}
	
	printf("\n\n\t-------------------------------------------");
	printf("\n\tcodigo  |    nome do produto       | valor ");
	printf("\n\t-------------------------------------------");
	while( !feof(PRODUTOS))
	{
		fread(&prod, sizeof(prod), 1, PRODUTOS);                   /*salva os dados do arquivo .dat na estrutura ao inv�s de buscar diretamente por seguran�a*/
		if ( !feof(PRODUTOS) )                                                              /*    e aproveita o loop para mostrar   */
		printf("\n\t%-2i      |    %-22s| %-5.2f", prod.codigo, prod.nome, prod.custo);     /*    os produtos existentes na tela    */ 
	}
	printf("\n\t-------------------------------------------");
	fclose(PRODUTOS);
	
	printf("\n\tPressione qualquer tecla para voltar ao menu\n\t");
	fflush(stdin); getch();
	main();
}

/*FUN��O MAIN*/
int main()
{
	system("cls");
	system("color 0b");
	setlocale(LC_ALL,"");                                    /*vari�veis locais e outras defini��es*/
	int op;
	
	printf("\t|--------------------|\n");
	printf("\t|                    |\n");
	printf("\t|   MENU PRINCIPAL   |\n");
	printf("\t|                    |\n");
	printf("\t|--------------------|\n\n");                            /*menu de op��es*/
	printf("\t1 - Cadastrar produtos\n");
	printf("\t2 - Verificar produtos\n");
	printf("\t3 - Vender produtos   \n");
	printf("\ts - Sair              \n\n\t");
	
	fflush(stdin); op = getche(); switch(op)
	{
		case'1': cadastro(); break;
		case'2': verifica(); break;                      /*captura a op��o e chama a respectiva fun��o*/
		case'3': system("MENU"); break;
		case's': case 'S': exit(0); break;
		default: printf("\n\n\tOp��o inv�lida"); printf("\n\tPressione qualquer tecla para voltar ao menu\n\t");
		fflush(stdin); getch();
		main();
	}
	return(0);
}
