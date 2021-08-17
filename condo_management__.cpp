#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

struct condomino {
  char name [45];
  char cpf[20];
  int apt;
  float debito;
}c[150];
int n,i,j=0,a=0,sum=0,g,qtd = 0, dev = 0, quites = 0; 

void read();
void add_condomino();
void pesquisa();
void atualizar();
void exibir_devedores();
void exibir_quites();
void remover();
void write();


main(){
	read();
	char another = 's';
	int opt;
	printf("\t\t|------------------------------------------------|\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|       -----------------------------            |\n");
	printf("\t\t|       CONDOMANAGEMENT EDFICIO P2               |\n");
	printf("\t\t|       -----------------------------            |\n");
	printf("\t\t|                SEJA BEM VINDO                  |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|            creators: Ygor Trocoli              |\n");
	printf("\t\t|                      Joao lucas                |\n");
	printf("\t\t|                      Guilherme Wanderley       |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|------------------------------------------------|\n\n\n");
	system("pause");
	system("cls");
		
do{
	printf("Escolhe sua opcao: \n\n\n\n");
  printf("1 - Inserir um novo condomino\n");
  printf("2 - Consultar condomino\n");
  printf("3 - Atualizar debito\n");
  printf("4 - Exibir os condominos devedores\n");
  printf("5 - Exibir os condominos quites\n");
  printf("6 - Remover condomino\n");
  printf("0 - Sair\n");
	scanf("%d" , &opt);
  fflush(stdin);
  
  switch(opt){
  	case 1:
  		system("cls");
  		add_condomino();
  		system("cls");
  		printf("Cadastro contluido com sucesso...");
  		sleep(2);
  		system("cls");
  		fflush(stdin);
  		break;
  		
  		
  		
  	case 2:
		system("cls");
		pesquisa();
		system("cls");
		fflush(stdin);
		break;
		
		
		
  	case 3:{
  		system("cls");
		atualizar();
		fflush(stdin);
		
}
		system("cls");
		break;
	
	case 4:
		system("cls");
		exibir_devedores();
		fflush(stdin);	
		system("cls");
		break;
		
	case 5:
		system("cls");
		exibir_quites();
		fflush(stdin);	
		system("cls");
		break;
	
	case 6:
		system("cls");
		remover();
		fflush(stdin);
		system("cls");
		break;
		
	case 0:
		write();
		return 0;
}
}
while(opt != 0);
}

void add_condomino(){
	printf("\n\n");
    printf("Existem %d condominos cadastrados\n\n",qtd);//how many inputs
    printf("Quantos condominos você deseja cadastrar?=\n");
    scanf("%d",&n);
    sum=n+qtd;

    for(i=qtd,j=0; i<sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Entre o nome do morador = ");
        gets(c[i].name);
        fflush(stdin);
        printf("\n\nDigite o CPF do morador = ");
        gets(c[i].cpf);
        fflush(stdin);
        printf("\n\nQual  o apartamento do Condomino a ser cadastrado? = ");
        scanf("%d",&c[i].apt);
        fflush(stdin);
        printf("\n\nQual o debito atual do morador? = ");
        scanf("%f",&c[i].debito);
        fflush(stdin);
        printf("\n\n");
        if(c[i].debito == 0){
        	quites++;
		}
		else{
			dev++;
		}
		system("cls");
        j++;
        a++;
        qtd++;
    }
}



void pesquisa(){
    char cpf_cons[20];
    int x = 1;
    char another ='s';
    while(another == 's'){
    system("cls");
    printf("Digite o CPF a ser consultado =  ");
    
    fflush(stdin);
    gets(cpf_cons);
    system("cls");
    for(g = 0; g < sum ; g++){
    	if(strcmp(cpf_cons,c[g].cpf) == 0){
    		printf("Nome = %s" , c[g].name);
    		printf("\n\nCPF = %s" , c[g].cpf);
    		printf("\n\nApto = %d" , c[g].apt);
    		printf("\n\nDebito = R$ %2.2f" , c[g].debito);
    		x = 0;
		}
		}
		if(x == 1){
			printf("\nCPF invalido!\n");

		
		
		}
		printf("\n\nDeseja fazer nova consulta?(s/n)");
		fflush(stdin);
		scanf("%c" , &another);
	}
}


void atualizar(){   
	 char cpf_cons[20];
    int x = 1;
    char another = 's';
    while(another == 's'){

    printf("Digite o CPF do condomino a ser atualizado =  ");
    fflush(stdin);
    gets(cpf_cons);
    for(g = 0; g < qtd ; g++){
    	if(strcmp(cpf_cons,c[g].cpf) == 0){
    		printf("\n\n%s tem um debito de : R$: %2.2f " , c[g].name , c[g].debito);
    		printf("\n\nDigite o novo debito: ");
    		scanf("%f" , &c[g].debito);
    		x = 0;
		}
		}
		if(x == 1){
			printf("\nCPF invalido!\n");
}
	fflush(stdin);
	printf("Deseja fazer nova alteracao?(s/n)\n\n");
	scanf("%c" , &another);
}
}


void exibir_devedores(){
	int i;
	printf("Lista de condominos devedores: \n\n\n");
	for(i = 0; i < qtd ; i++){
		if(c[i].debito != 0){
			printf("Nome = %s\n\ncpf = %s\n\napto = %d\n\nValor a pagar = R$ %2.2f\n\n" , c[i].name , c[i].cpf , c[i].apt , c[i].debito);
			printf("\n**********************************************************\n\n");
		}
	}
	system("pause");
}



void exibir_quites(){
	int i;
	printf("Lista de condominos quites: \n\n\n");	
	for(i = 0; i < qtd ; i++){
		if(c[i].debito == 0){
			printf("Nome = %s\n\ncpf = %s\n\napto = %d\n\nO condomino esta em dia!\n" , c[i].name , c[i].cpf , c[i].apt);
			printf("\n**********************************************************\n\n");
		}
	}
	system("pause");
	
}

	void read()
{
    FILE *fp = fopen("condominio.txt","r");
    if(fp == NULL)
    {
        fp = fopen("condominio.txt","w");
        fclose(fp);
        printf("Reinicie o programa...\n\n\n");
    }

    qtd = fread(c, sizeof(struct condomino),150, fp);
    fclose(fp);
}

void write()
{
    FILE *fp = fopen("condominio.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(c, sizeof(struct condomino),qtd, fp);

    fclose(fp);
}

void remover(){
	char cpf_cons[20];
    int x = 1,index;
    char another ='s';
    while(another == 's'){
    system("cls");
    printf("Digite o CPF do mroador a ser deletado =  ");
    
    fflush(stdin);
   	gets(cpf_cons);
    system("cls");
    for(g = 0; g < sum ; g++){
    	if(strcmp(cpf_cons,c[g].cpf) == 0){
    		while(g < sum){
    			strcpy(c[g].name, c[g+1].name);
    			strcpy(c[g].cpf , c[g+1].cpf);
    			c[g].apt = c[g+1].apt;
    			c[g].debito = c[g+1].debito;
    			x = 0;
    			g++;
			}
			qtd--;
			printf("Concluido!\n");
			fflush(stdin);
		}
		}
		if(x == 1){
			printf("\nCPF invalido!\n");

		
		
		}
		printf("\n\nDeseja remover outro condomino??(s/n)");
		fflush(stdin);
		scanf("%c" , &another);
	}
	
}
















