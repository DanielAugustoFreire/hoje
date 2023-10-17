#include <stdio.h>
#include <time.h>

typedef struct{
	int hora_pediu;
	int min_pediu;
	int hora_chegou;
	int min_chegou;
}Horario;

typedef struct{
	char rua[50];
	int num;
	char cidade[50];
}Endereco;

typedef struct{
	int num_p;
	char nome[50];
	Horario h;
	Endereco e;
}Cliente;

void cadastrar(Cliente *c)
{
	FILE *fp;
	fp = fopen("pedidos.bin", "ab");
	
	printf("Entre com o Numero do Pedido:");
	scanf("%d", &c->num_p);
	getchar();
	printf("Entre com o Nome do Cliente:");
	fgets(c->nome, 50, stdin);
	printf("Entre com a Cidade:");
	fgets(c->e.cidade, 50, stdin);	
	printf("Entre com a Rua:");
	fgets(c->e.rua, 50, stdin);
	printf("Entre com o Numero:");
	scanf("%d", &c->e.num);	
	getchar();
	
	strtok(c->nome, "\n");
	strtok(c->e.cidade, "\n");
	strtok(c->e.rua, "\n");

	
	time_t rawtime;
	struct tm *timeinfo;
	
	time(&rawtime);
    timeinfo = localtime(&rawtime);
	
	c->h.hora_pediu = timeinfo->tm_hour;
    c->h.min_pediu = timeinfo->tm_min;
    fprintf(fp,"%d,%s,%s,%s,%d,%02d:%02d",c->num_p,c->nome,c->e.cidade,c->e.rua,c->e.num,c->h.hora_pediu,c->h.min_pediu);
    
    fclose(fp);
}

void listar()
{
	FILE *fp;
	fp = fopen("pedidos.bin", "rb");
	char linha[256];
	
	if(fp == NULL){
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }
    

	fgets(linha, sizeof(linha), fp);
    printf("\n%s\n\n", linha);
	
	
	fclose(fp);	
}


int main()
{
	Cliente c;
	int i= 1000;
	
	while(i!=3)
	{
		printf("Escolha uma opcao:\n[1] - Cadastrar um pedido\n[2] - Listar Pedidos\n[3] - Sair");
		scanf("%d", &i);
		if(i == 1)
			cadastrar(&c);
		else if(i == 2 )
			listar(c);
	}
}