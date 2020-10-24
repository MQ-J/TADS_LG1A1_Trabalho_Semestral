/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/*VARIÁVEIS*/
char op, op2;

/*CORPO DO PROGRAMA*/
int main()
{
	system("color 0b");
	system("cls");
	setlocale (LC_ALL, "");
	printf("\t|--------------------|\n");
	printf("\t|                    |\n");
	printf("\t|   MENU DE VENDAS   |\n");
	printf("\t|                    |\n");                                                     /*cabeçalho do menu*/
	printf("\t|--------------------|\n\n");
	printf("\t1 - Cadastrar o pedido\n");
	printf("\t2 - Fazer o pagamento\n");
	printf("\t3 - Realizar a entrega\n");
	printf("\ts -     Sair      \n\n\t");
	
	fflush (stdin);
	op = getche();
	switch (op)
	{                                                                              	/*chama o respectivo programa filho*/
	case '1': system ("PEDIDO"); break;
	case '2': system("PAGUE"); break;
	case '3': system("LEVE"); break;
	case 'S': case 's': exit(0); break;
	
	default: printf("\n\t|          Opcão inválida! Digite:          |\n\t|[a = voltar] [qualquer outra tecla = sair] |\n");
	op2 = getche();
	if (op2 == 'a')                                                                            /*opção inválida*/
	main();
	}
	return (0);
}
