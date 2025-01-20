#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registro() //fun��o respons�vel pelo cadastro dos usu�rios
{
	//in�cio das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das vari�veis/string 
	
	printf("digite o CPF a ser cadastrado: "); //coleta de informa��es dos usu�rios
	scanf("%s", cpf);//%s refe-se a string
	
	strcpy(arquivo, cpf);//copia os valores das strings
	
	FILE *file;//cria��o do arquivo
	file = fopen(arquivo, "w");//cria��o do arquivo e "w" sendo write(escrever)
	fprintf(file, cpf);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//definindo linguagen
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser pesquisado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("arquivo inexistente!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio pesquisado: \n\t");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("digite o cpf a ser deletado: ");
   	scanf("%s", cpf);
    
    remove(cpf);
    	
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("o usuario n�o foi encontrado!\n");
    	system("pause");
	}
}

int main()
{
    int opcao=0;//definindo variaveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
     
   	    system("cls");

		setlocale(LC_ALL, "Portuguese");//definindo linguagen

		printf("\n\nregistro de funcion�rios\n\n");//inicio do menu
		printf("\t1 -registrar\n");
		printf("\t2 -consultar\n");
		printf("\t3 -deletar\n");//fim do menu
	
		scanf("%d", &opcao);//armazenamento da escolha do usuario
	
		system("cls");//respons�vel por limpar a tela
	
		switch(opcao)//inicio da sele��o
		{
			case 1:
			registro();//chamada de fun��es
			break;
				
			case 2:
			consulta();
			break;
		
			case 3:
			   deletar();
			break;
			
			default:
			printf("op��o n�o dispon�vel!\n");
			system("pause");
			break;
			
		}//fim da sele��o
	}
}
