#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca para carregamento de string

int registro(){  //Função responsavel por cadastrar os usuários nos sistema
	
	//inicio da criação das string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das variáveis
		
	printf("Digite seu CPF para realizar o cadastro:\n "); //coletando informação do usuário
	scanf("%s", cpf); //guardando a informação do usuário na string ("%s", string)
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string 
	
	FILE *file; //Respodemsavel por criar o arquivo 
	file = fopen(arquivo, "w"); // criar o arquivo "w"
	fprintf(file,cpf); // salva o valor da variavel no arquivo
	fclose(file);	// fecha o arquivo 	
	
	file = fopen(arquivo, "a"); //atualiza o arquivo, podendo manipular
	fprintf(file,","); // salvar o valor da string no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //coletando informação do usuário
	scanf("%s",nome), //guardando a informação do usuário na string 
	
	file = fopen(arquivo,"a"); // comando para abrir o arquivo para atualizar valores ("a")
	fprintf(file,nome); //salva o valor da string no arquivo 
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o seu sobrenome para ser cadastrado: \n"); // usado para coletar informações do usuário
	scanf("%s", sobrenome); //usado para salvar informações coletadas na string
	
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
	
	printf("Usuário cadastrado com sucesso! \n");
	system("pause"); //usado para pausar o programa
}
int consulta(){ //Função responsavel por consultar os dados dos usuários 
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	//inicio da criação das string
	char cpf[40];
	char conteudo[200];
	//final das string
	
	printf("Digite o cpf a ser consultado: "); //responsavel por coletar as iformações do usuário 
	scanf("%s",cpf); //salva as informações coletadas na string 
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf,"r"); //usado para abrir e  consultar o que tiver dentro da variavel cpf
	
	if(file == NULL){ 
		printf("Não foi possivel localizar o cpf. \n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL){    // while = enquanto 
		printf("Essas são as informações do usuário \n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}
int deletar(){
	
	char cpf[40];
	
	printf("Digite o cpf do usuário que deseja ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==  NULL){
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	
}
int main(){
	int opcao=0; //Definindo variável inteira
	int x=0;
	
	for(x=1;x=1;){
		
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
		printf("XXXX Cartório da EBAC XXXX\n\n"); //TItulo do programa 
		printf("Selecione a opção desejada no menu:\n\n"); //Menu 
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("Opção:");
	
		scanf("%d", &opcao); //usado para guardar o que o usuário digitou 
	
		system("cls"); // usado para limpar a tela tudo que ja foi escrito 
		
		
		switch(opcao){ //inicio da seleção do menu
			case 1:
			registro(); // chamado de funções registro
			break;
			
			case 2:
			consulta(); //chamado de funções de comsulta
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Você escolheu uma opção invalida! \n");
			system("pause");
			break;
		}
	
		
		

	


	}
}


