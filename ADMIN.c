/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/*ESTRUTURAS DE DADOS*/
typedef struct
{
	int codigo;
	char nome[22+1];
	float custo;
} registro;

/*VARIÁVEIS GERAIS*/
registro reg;
FILE * produtos;

/*CADASTRAR PROUTOS*/
void cadastro(void)
{
	system("color 0b");
	setlocale(LC_ALL,"");                                                                            /*variáveis locais e outras definições*/
	char op;
	
	produtos = fopen("PRODUTOS.DAT", "w"); if (fopen == NULL) reg.codigo = 1;
	fseek(produtos, 0, SEEK_END);
	reg.codigo = ftell(produtos) / sizeof(reg);                                                   /*contagem autonumérica do código do produto*/
	if (reg.codigo == 0) reg.codigo = 1;
	fclose(produtos);
	
	printf("\n\n\tInsira o nome do produto: "); fflush(stdin); gets(reg.nome);
	printf("\tInsira o valor do produto: "); fflush(stdin); scanf("%f", &reg.custo);                /*definindo nome e valor do produto*/
	produtos = fopen("PRODUTOS.DAT", "a"); if (fopen == NULL) produtos = fopen("PRODUTOS.DAT", "w");
	fwrite(&reg, sizeof(reg), 1, produtos);
	fclose(produtos);
	
	printf("\n\tCadastrar novo produto? [s = sim] [qualquer outra tecla = não]\n\t");
	fflush(stdin); op = getche(); switch(op)                                                        /*pergunta se quer cadastrar outro produto*/
	{
		case's': case'S': cadastro(); break;
		default: main();
	}
}

/*VERIFICAR PRODUTOS*/
void verifica(void)
{
	system("color 0b");                                                                    /*variáveis locais e outras definições*/
	setlocale(LC_ALL,"");
	char op;
	
	produtos = fopen("PRODUTOS.DAT", "r");
	if (fopen == NULL)
	{
		printf("\n\tERRO! Crie um produto ou verifique os existentes");                           /*tenta abrir o arquivo .dat*/
		getch();
		exit(0);
	}
	
	printf("\n\n\tcodigo       nome do produto          valor");
	while( !feof(produtos))
	{
		fread(&reg, sizeof(reg), 1, produtos);                   /*salva os dados do arquivo .dat na estrutura ao invés de buscar diretamente por segurança*/
		if ( !feof(produtos) )                                                              /*    e aproveita o loop para mostrar   */
		printf("\n\t%i            %-22s   %.2f", reg.codigo, reg.nome, reg.custo);          /*    os produtos existentes na tela    */ 
	}
	fclose(produtos);
	
	printf("\n\tPressione qualquer tecla para voltar ao menu\n\t");
	fflush(stdin); getch();
	main();
}

/*FUNÇÃO MAIN*/
int main()
{
	system("cls");
	system("color 0b");
	setlocale(LC_ALL,"");                                    /*variáveis locais e outras definições*/
	int op;
	
	printf("\t|--------------------|\n");
	printf("\t|                    |\n");
	printf("\t|   MENU PRINCIPAL   |\n");
	printf("\t|                    |\n");
	printf("\t|--------------------|\n\n");                            /*menu de opções*/
	printf("\t1 - Cadastrar produtos\n");
	printf("\t2 - Verificar produtos\n");
	printf("\t3 - Vender produtos   \n");
	printf("\ts - Sair              \n\n\t");
	
	fflush(stdin); op = getche(); switch(op)
	{
		case'1': cadastro(); break;
		case'2': verifica(); break;                      /*captura a opção e chama a respectiva função*/
		case'3': system("MENU"); break;
		case's': case 'S': exit(0); break;
		default: printf("Opção inválida"); fflush(stdin); getch(); 
		main();
	}
	return(0);
}
