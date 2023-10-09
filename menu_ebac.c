#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca para carregamento de string

int registro(){  //Fun��o responsavel por cadastrar os usu�rios nos sistema
	
	//inicio da cria��o das string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das vari�veis
		
	printf("Digite seu CPF para realizar o cadastro:\n "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //guardando a informa��o do usu�rio na string ("%s", string)
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string 
	
	FILE *file; //Respodemsavel por criar o arquivo 
	file = fopen(arquivo, "w"); // criar o arquivo "w"
	fprintf(file,cpf); // salva o valor da variavel no arquivo
	fclose(file);	// fecha o arquivo 	
	
	file = fopen(arquivo, "a"); //atualiza o arquivo, podendo manipular
	fprintf(file,","); // salvar o valor da string no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //coletando informa��o do usu�rio
	scanf("%s",nome), //guardando a informa��o do usu�rio na string 
	
	file = fopen(arquivo,"a"); // comando para abrir o arquivo para atualizar valores ("a")
	fprintf(file,nome); //salva o valor da string no arquivo 
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o seu sobrenome para ser cadastrado: \n"); // usado para coletar informa��es do usu�rio
	scanf("%s", sobrenome); //usado para salvar informa��es coletadas na string
	
	file = fopen(arquivo,"a"); // usado para abrir banco de dados e atualizar ("a")
	fprintf(file,sobrenome); //serve para salvar o valor da string no arquivo 
	fclose(file);//fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo para ser cadastrado \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("Usu�rio cadastrado com sucesso! \n");
	system("pause"); //usado para pausar o programa
}
int consulta(){ //Fun��o responsavel por consultar os dados dos usu�rios 
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	//inicio da cria��o das string
	char cpf[40];
	char conteudo[200];
	//final das string
	
	printf("Digite o cpf a ser consultado: "); //responsavel por coletar as iforma��es do usu�rio 
	scanf("%s",cpf); //salva as informa��es coletadas na string 
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf,"r"); //usado para abrir e  consultar o que tiver dentro da variavel cpf
	
	if(file == NULL){ 
		printf("N�o foi possivel localizar o cpf. \n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL){    // while = enquanto 
		printf("Essas s�o as informa��es do usu�rio \n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}
int deletar(){
	
	char cpf[40];
	
	printf("Digite o cpf do usu�rio que deseja ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==  NULL){
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
}
int main(){
	int opcao=0; //Definindo vari�vel inteira
	int x=0;
	
	for(x=1;x=1;){
		
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
		printf("XXXX Cart�rio da EBAC XXXX\n\n"); //TItulo do programa 
		printf("Selecione a op��o desejada no menu:\n\n"); //Menu 
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("Op��o:");
	
		scanf("%d", &opcao); //usado para guardar o que o usu�rio digitou 
	
		system("cls"); // usado para limpar a tela tudo que ja foi escrito 
		
		
		switch(opcao){ //inicio da sele��o do menu
			case 1:
			registro(); // chamado de fun��es registro
			break;
			
			case 2:
			consulta(); //chamado de fun��es de comsulta
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Voc� escolheu uma op��o invalida! \n");
			system("pause");
			break;
		}
	
		
		

	


	}
}


