#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int dia, mes, ano;
}nascimento;

typedef struct{
	char nome[256];
	char telefone[13];
	char email[256];
	char sangue[4];
	nascimento n;
}contato;



int menu(void)
{
	int op;
	
	printf("Entre com a opcao:\n[1] - Cadastrar Contato\n[2] - Listar Contatos\n[3] - Consultar Aniversariantes por Mes\n[4] - Sair");
	scanf("%d", &op);
	if(op > 0 && op < 5)
	{	
		return op;	
	}
	else 
	{
		return 0;
	}
}

void cadastrar()
{
	FILE *fp;
	int i;
	contato c;
	fp = fopen("agenda.dat", "ab");
	
		printf("Entre com o nome do Contato:");
		fgets(c.nome, 256, stdin);
		strtok(c.nome, "\n");
		
		for (i = 0; c.nome[i] != '\0'; i++) 
		{
	        if (c.nome[i] == ' ') {
	            c.nome[i] = '-';
	        }
    	}	
		
		printf("Entre com a data de nascimento no formato dd/mm/aaaa:");
		scanf("%d/%d/%d", &c.n.dia, &c.n.mes, &c.n.ano);
		fflush(stdin);
		printf("Entre com o telefone:");
		fgets(c.telefone, 13, stdin);
		strtok(c.telefone, "\n");
		printf("Entre com o email");
		fgets(c.email, 256, stdin);
		strtok(c.email, "\n");
		printf("Entre com o tipo sanguineo");
		fgets(c.sangue, 4, stdin);
		strtok(c.sangue, "\n");
		
		
		fprintf(fp,"%s  %02d %02d %04d  %s  %s  %s\n", c.nome, c.n.dia, c.n.mes, c.n.ano, c.telefone, c.email, c.sangue);
		
	fclose(fp);
}

void listar()
{
	int dia, mes, ano;
	char nome[256], email[256], telefone[13], sangue[4];
	
	FILE *fp;
	fp = fopen("agenda.dat", "rb");
	
	if(fp == NULL)
		printf("ERRO AO LER");
	
		while(fscanf(fp,"%255s %d  %d  %d %12s %255s %3s", nome, &dia, &mes, &ano, telefone, email, sangue) == 7)
		{
			printf("\n%s  %02d/%02d/%04d  %s  %s  %s\n\n", nome, dia, mes, ano, telefone, email, sangue);
		}
		
	fclose(fp);
}

void aniversario()
{
	int dia, mes, ano;
	char nome[256], email[256], telefone[13], sangue[4];
	int mes_entrada;
	
	FILE *fp;
	fp = fopen("agenda.dat", "rb");
	
	if(fp == NULL)
		printf("ERRO AO LER");
	
		printf("Entre com o mes:");
		scanf("%d", &mes_entrada);
		
		while(fscanf(fp,"%255s %d  %d  %d %12s %255s %3s", nome, &dia, &mes, &ano, telefone, email, sangue) == 7)
		{
			if(mes_entrada == mes)
				printf("\n%s  %02d/%02d/%04d  %s  %s  %s\n\n", nome, dia, mes, ano, telefone, email, sangue);
		}
		
	fclose(fp);
}

int main()
{
	int iterador=0;
	contato c;
	
	do{
		iterador = menu();
		fflush(stdin);
		if(iterador == 0)
		{
			printf("Entrada Invalida!!\n\n");	
		}
		else if(iterador == 1)
		{
			cadastrar();
		}
		else if(iterador == 2)
		{
			listar();
		}
		else
		{
			aniversario();	
		}
	}while(iterador != 4);
	
	
	
	
}
