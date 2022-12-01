#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	// Variaveis
	int i=0, j=1, opc, qtdSessao, qtdPessoa, somaM = 0, somaF = 0, idade, crianca=0, adolescente=0, adulto=0, idoso=0, tipoIngresso, somaMeia=0, somaInteira=0;
	int maiorIdadeFem = 0, maiorIdadeMasc = 0;
	char nomeFilme[50], sexo[1], formaCompra[50][100];
    int presencial=0, online=0;
	
	
    menu:                                                      // Marcação de retorno do menu inicial;
    printf("Bem vindo ao Cinema! Escolha a opção desejada:\n\n"); // Imprime o menu inicial;
    printf("1. Iniciar análise\n2. Sair\n\nOpção: ");             // Imprime o menu inicial;
    scanf("%d", &opc);                                            // Recebe a opção desejada no menu inicial;

    if (opc == 2) // Validação das opções do menu inicial (1);
    {
        printf("\nFinalizando...\n");
        exit(0); // Finalizando o programa;
    }
    else if (opc != 1) // Validação das opções do menu inicial (2);
    {
        system("cls");
        printf("#AVISO: Digite uma opção válida!\n\n");
        goto menu; // Retornando ao menu para digitar a opção desejada novamente;
    }

    system("cls"); // Limpando o terminal;

    printf("Digite a quantidade de sessões: ");
    scanf("%d", &qtdSessao); // Recebe a quantidade de sessões dos filmes;

    system("cls"); // Limpando o terminal;
    
    if (qtdSessao != 2) // Validação da quantidade de sessões;
    {
        do
        {
            printf("#AVISO: Única quantidade aceita: 2.\nDigite novamente!");
            printf("Digite a quantidade de sessões: ");
            fflush(stdin); // Limpando o buffer do teclado;
            scanf("%d", &qtdSessao);
            system("cls");
        } while (qtdSessao != 2);
    }

	printf("Nome do filme: ");
        fflush(stdin);                  // Limpando o buffer do teclado;
        fgets(nomeFilme, 50, stdin); // Utilizando a função fgets para receber o nome dos filmes;

        system("cls");

        printf("### SESSÃO %d ###\n\n", j);
        printf("Digite a quantidade de pessoas que assistiram ao filme (Mín. 10): ");
        fflush(stdin); // Limpando o buffer do teclado;
        scanf("%d", &qtdPessoa);
        system("cls");

        if (qtdPessoa < 10) // Validação da quantidade de pessoas;
        {
            do
            {
                printf("### SESSÃO %d ###\n\n", j + 1);
                printf("#AVISO: A quantidade mínima aceita é 10.\nDigite novamente!");
                printf("Digite a quantidade de pessoas que assistiram ao filme (Mín. 10): ");
                fflush(stdin); // Limpando o buffer do teclado;
                scanf("%d", &qtdPessoa);

                system("cls");

            } while (qtdPessoa < 10); // Quantidade de pessoas na sessão
        }

        for (i = 0; i < qtdPessoa; i++) // For das sessões 
        {
            printf("### SESSÃO %d ###\n(%dº pessoa)\n\n", j + 1, i + 1);
            printf("Sexo:\n\n-[M]asculino\n-[F]eminino\n\nOpção: ");
            fflush(stdin); // Limpando o buffer do teclado;
            scanf("%s", &sexo); // Seleção de opcões

            if (strcmp(sexo, "M") != 0 && strcmp(sexo, "F") != 0) // Validação dos sexos usando apenas 'M' ou 'F' com string, se for adciona ao contador
            {
                do
                {
                    printf("### SESSÃO %d ###\n(%dº pessoa)\n\n", j + 1, i + 1);
                    printf("#AVISO: Sexo inválido.\nDigite novamente!");
                    printf("Sexo:\n\n-[M]asculino\n-[F]eminino\n\nOpção: ");
                    fflush(stdin); // Limpando o buffer do teclado;
                    scanf("%s", &sexo);

                    system("cls");

                } while (strcmp(sexo, "M") != 0 && strcmp(sexo, "F") != 0); // Complemento da Validação se não for nenhuma opção
            }

            if (strcmp(sexo, "M") == 0)
            {
                somaM += 1;
            }

            else if (strcmp(sexo, "F") == 0)
            {
                somaF += 1;
            }

            system("cls"); // Limpando o terminal

            printf("### SESSÃO %d ###\n(%dº pessoa)\n\n", j + 1, i + 1);
            printf("Idade (Mín. 3 | Máx. 100): ");
            fflush(stdin); // Limpando o buffer do teclado;
            scanf("%d", &idade);

            if (idade < 3 || idade > 100)
            {
                do
                {
                    printf("### SESSÃO %d ###\n(%dº pessoa)\n\n", j + 1, i + 1);
                    printf("#AVISO: Idade inválida.\nDigite novamente!");
                    printf("Idade (Mín. 3 | Máx. 100): ");
                    fflush(stdin); // Limpando o buffer do teclado;
                    scanf("%d", &idade);

                    system("cls"); // Limpando o terminal;

                } while (idade < 3 || idade > 100); // Idade Limitada de 3 a 100 anos 
            }
			
			if(idade <= 13){ // Idade de 3 a 13 anos ela adiciona ao contador 1  se for criança
				crianca++;
			}
			
			if(idade > 13 && idade <= 17){ // Idade de 13 a 17 anos ela adiciona ao contador 1  se for adolecente
				adolescente++;
			}
			
			if(idade > 18 && idade <= 64){ // Idade de 18 a 64 anos ela adiciona ao contador 1  se for adulto
				adulto++;
			}
			
			if(idade > 64 && idade <= 100){ // Idade de 64 a 100 anos ela adiciona ao contador 1  se for idoso
				idoso++;
			}
			
			if (strcmp(sexo, "M") == 0 && idade >=18) // Se o sexo da pessoa for maior que 18 adiciona ao contador 1 fazendo ela ser maio de idade no caso Masculino
            {
                maiorIdadeFem += 1;
            }

            else if (strcmp(sexo, "F") == 0 && idade >=18) // Se o sexo da pessoa for maior que 18 adiciona ao contador 1 fazendo ela ser maio de idade no caso Feminino
            {
                maiorIdadeMasc += 1;
            }
			
            system("cls"); // Limpando o terminal;

        telaIngresso:
            printf("### SESSÃO %d ###\n(%dº pessoa)\n\n", j + 1, i + 1);
            printf("Tipo de ingresso:\n\n-1. Inteira (R$ 50,00)\n-2. Meia (R$ 25,00)\n\nOpção: ");
            fflush(stdin);              // Limpando o buffer do teclado;
            scanf("%d", &tipoIngresso); // Recebe o valor do tipo de ingresso
			
            if (tipoIngresso == 1) // Caso o ingresso seja tipo 1 (Inteira)
            {
            	somaInteira +=25; // Adicionando valor na entrada inteira;
            }
            else if (tipoIngresso == 2) // Caso o ingresso seja tipo 2 (Meia)
            {
            	somaMeia += 50; // Adicionando valor na entrada meia;
            }
            else
            {
                system("cls"); // Limpando o terminal
                printf("#AVISO: Digite uma opção válida!\n");
                goto telaIngresso; // Retorna à marcação de tela do tipo de ingresso
            }
             //Pergunta a forma de compra ao usuário 
			 system("cls");  
            printf("Forma de compra:\n\n1. Presencialmemte\n2 .Online\nDigite a opção desejada: ");
            scanf("%s", &formaCompra[j]); // Forma de compra 
        
             //Faz o somatório
            if(strcmp(formaCompra[j], "Presencialmente")==0){ // Somatorio da compra presencial assim adicionando 1 ao contador
            	presencial = presencial+1;
			}else if(strcmp(formaCompra[j], "Online")==0){ // Somatorio da compra online assim adicionando 1 ao contador
				online = online+1;
			}
			//Validação da forma de compra 
			
			if(strcmp(formaCompra[j], "Presencialmente")!=0 && strcmp(formaCompra[j], "Online")!=0){
				do{
					system("cls");
					printf("Opção inválida.\nForma de compra:\n\n1. Presencialmente\n2. Online\nDigite a opção desejada: "); // Opção de compra
					scanf("%s", &formaCompra[j]);
				}while(strcmp(formaCompra[j], "Presencialmente")!=0 && strcmp(formaCompra[j], "Online")!=0); // Validação de opção possiveis 
			}
			

            system("cls"); // Limpando o terminal
        }
	
	printf("Sessão: %d\n", i);
	printf("Nome do filme: %s\n", nomeFilme); // Imprime o Nome do filme na tela do usuario 
	printf("Espectadores:\n-Masculinos: %d\n-Femininos: %d\n", somaM, somaF);
	printf("Quantidade de pessoas por classificação:\n-Crianças: %d\n-Adolescentes: %d\n-Adultos: %d\n-Idosos: %d\n", crianca, adolescente, adulto, idoso); // Imprime a classificação por idade das pessoas
	printf("Pessoas maiores de idade:\n-Femininos: %d\n-Masculinos: %d\n", maiorIdadeFem, maiorIdadeMasc); // Imprime as pessoas maiores de idade
	printf("Valor total arrecadado:\n-Meia-entrada: R$ %d\n-Inteira: R$ %d\n", somaMeia, somaInteira); // Imprime o total arrecadado dos inigressos
    printf("\nNúmero de pessoas que compraram o ingresso de forma presencial: %d", presencial); // Imprime se a pessoa comprou o ingresso de forma presencial
    printf("\nNúmero de pessoas que compraram o ingresso On-line: %d", online); // Imprime se a pessoa comprou o ingresso de forma online
	
	if(somaMeia > somaInteira){  //caso a quantidade me venda de ingressod de meia seja maior que a da interia aparecera uma mensagem caso ao contrio apresentara outro texto .
		printf("\nForam vendidas mais meia-entradas do que inteiras.\n");
	}
	else{
		printf("\nForam vendidas mais inteiras do que meias.\n");
	}
	
	printf("Digite qualquer tecla para continuar: ");
	scanf("%d", NULL);
	

	goto menu;
	
	return 0;
}
/* Conceitos utilizados do livro "Código Limpo": Utilizamos nomes que revelam seu propósito e nomes pronunciáveis em nossas variáveis - 
Capítulo 2 de Nomes Significativos. Para manter a organização do código, fizemos uso da Continuidade Vertical - Capítulo 5 de Formatação.*/
