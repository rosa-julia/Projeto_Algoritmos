#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int i=0, j=1, opc, qtdSessao, qtdPessoa, somaM = 0, somaF = 0, idade, crianca=0, adolescente=0, adulto=0, idoso=0, tipoIngresso, somaMeia=0, somaInteira=0;
	int maiorIdadeFem = 0, maiorIdadeMasc = 0;
	char nomeFilme[50], sexo[1], formaCompra[50][100];
    int presencial=0, online=0;
	
	
    menu:                                                      // Marca��o de retorno do menu inicial;
    printf("Bem vindo ao Cinema! Escolha a op��o desejada:\n\n"); // Imprime o menu inicial;
    printf("1. Iniciar an�lise\n2. Sair\n\nOp��o: ");             // Imprime o menu inicial;
    scanf("%d", &opc);                                            // Recebe a op��o desejada no menu inicial;

    if (opc == 2) // Valida��o das op��es do menu inicial (1);
    {
        printf("\nFinalizando...\n");
        exit(0); // Finalizando o programa;
    }
    else if (opc != 1) // Valida��o das op��es do menu inicial (2);
    {
        system("cls");
        printf("#AVISO: Digite uma op��o v�lida!\n\n");
        goto menu; // Retornando ao menu para digitar a op��o desejada novamente;
    }

    system("cls"); // Limpando o terminal;

    printf("Digite a quantidade de sess�es: ");
    scanf("%d", &qtdSessao); // Recebe a quantidade de sess�es dos filmes;

    system("cls"); // Limpando o terminal;
    
    if (qtdSessao != 2) // Valida��o da quantidade de sess�es;
    {
        do
        {
            printf("#AVISO: �nica quantidade aceita: 2.\nDigite novamente!");
            printf("Digite a quantidade de sess�es: ");
            fflush(stdin); // Limpando o buffer do teclado;
            scanf("%d", &qtdSessao);
            system("cls");
        } while (qtdSessao != 2);
    }

	printf("Nome do filme: ");
        fflush(stdin);                  // Limpando o buffer do teclado;
        fgets(nomeFilme, 50, stdin); // Utilizando a fun��o fgets para receber o nome dos filmes;

        system("cls");

        printf("### SESS�O %d ###\n\n", j);
        printf("Digite a quantidade de pessoas que assistiram ao filme (M�n. 10): ");
        fflush(stdin); // Limpando o buffer do teclado;
        scanf("%d", &qtdPessoa);
        system("cls");

        if (qtdPessoa < 10) // Valida��o da quantidade de pessoas;
        {
            do
            {
                printf("### SESS�O %d ###\n\n", j + 1);
                printf("#AVISO: A quantidade m�nima aceita � 10.\nDigite novamente!");
                printf("Digite a quantidade de pessoas que assistiram ao filme (M�n. 10): ");
                fflush(stdin); // Limpando o buffer do teclado;
                scanf("%d", &qtdPessoa);

                system("cls");

            } while (qtdPessoa < 10);
        }

        for (i = 0; i < qtdPessoa; i++)
        {
            printf("### SESS�O %d ###\n(%d� pessoa)\n\n", j + 1, i + 1);
            printf("Sexo:\n\n-[M]asculino\n-[F]eminino\n\nOp��o: ");
            fflush(stdin); // Limpando o buffer do teclado;
            scanf("%s", &sexo);

            if (strcmp(sexo, "M") != 0 && strcmp(sexo, "F") != 0)
            {
                do
                {
                    printf("### SESS�O %d ###\n(%d� pessoa)\n\n", j + 1, i + 1);
                    printf("#AVISO: Sexo inv�lido.\nDigite novamente!");
                    printf("Sexo:\n\n-[M]asculino\n-[F]eminino\n\nOp��o: ");
                    fflush(stdin); // Limpando o buffer do teclado;
                    scanf("%s", &sexo);

                    system("cls");

                } while (strcmp(sexo, "M") != 0 && strcmp(sexo, "F") != 0);
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

            printf("### SESS�O %d ###\n(%d� pessoa)\n\n", j + 1, i + 1);
            printf("Idade (M�n. 3 | M�x. 100): ");
            fflush(stdin); // Limpando o buffer do teclado;
            scanf("%d", &idade);

            if (idade < 3 || idade > 100)
            {
                do
                {
                    printf("### SESS�O %d ###\n(%d� pessoa)\n\n", j + 1, i + 1);
                    printf("#AVISO: Idade inv�lida.\nDigite novamente!");
                    printf("Idade (M�n. 3 | M�x. 100): ");
                    fflush(stdin); // Limpando o buffer do teclado;
                    scanf("%d", &idade);

                    system("cls"); // Limpando o terminal;

                } while (idade < 3 || idade > 100);
            }
			
			if(idade <= 13){
				crianca++;
			}
			
			if(idade > 13 && idade <= 17){
				adolescente++;
			}
			
			if(idade > 18 && idade <= 64){
				adulto++;
			}
			
			if(idade > 64 && idade <= 100){
				idoso++;
			}
			
			if (strcmp(sexo, "M") == 0 && idade >=18)
            {
                maiorIdadeFem += 1;
            }

            else if (strcmp(sexo, "F") == 0 && idade >=18)
            {
                maiorIdadeMasc += 1;
            }
			
            system("cls"); // Limpando o terminal;

        telaIngresso:
            printf("### SESS�O %d ###\n(%d� pessoa)\n\n", j + 1, i + 1);
            printf("Tipo de ingresso:\n\n-1. Inteira (R$ 50,00)\n-2. Meia (R$ 25,00)\n\nOp��o: ");
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
                printf("#AVISO: Digite uma op��o v�lida!\n");
                goto telaIngresso; // Retorna � marca��o de tela do tipo de ingresso
            }
             //Pergunta a forma de compra ao usu�rio 
			 system("cls");  
            printf("Forma de compra:\n\n1. Presencialmemte\n2 .Online\nDigite a op��o desejada: ");
            scanf("%s", &formaCompra[j]);
        
             //Faz o somat�rio
            if(strcmp(formaCompra[j], "Presencialmente")==0){
            	presencial = presencial+1;
			}else if(strcmp(formaCompra[j], "Online")==0){
				online = online+1;
			}
			//Valida��o da forma de compra 
			
			if(strcmp(formaCompra[j], "Presencialmente")!=0 && strcmp(formaCompra[j], "Online")!=0){
				do{
					system("cls");
					printf("Op��o inv�lida.\nForma de compra:\n\n1. Presencialmente\n2. Online\nDigite a op��o desejada: ");
					scanf("%s", &formaCompra[j]);
				}while(strcmp(formaCompra[j], "Presencialmente")!=0 && strcmp(formaCompra[j], "Online")!=0);
			}
			

            system("cls"); // Limpando o terminal
        }
	
	printf("Sess�o: %d\n", i);
	printf("Nome do filme: %s\n", nomeFilme);
	printf("Espectadores:\n-Masculinos: %d\n-Femininos: %d\n", somaM, somaF);
	printf("Quantidade de pessoas por classifica��o:\n-Crian�as: %d\n-Adolescentes: %d\n-Adultos: %d\n-Idosos: %d\n", crianca, adolescente, adulto, idoso);
	printf("Pessoas maiores de idade:\n-Femininos: %d\n-Masculinos: %d\n", maiorIdadeFem, maiorIdadeMasc);
	printf("Valor total arrecadado:\n-Meia-entrada: R$ %d\n-Inteira: R$ %d\n", somaMeia, somaInteira);
    printf("\nN�mero de pessoas que compraram o ingresso de forma presencial: %d", presencial);
    printf("\nN�mero de pessoas que compraram o ingresso On-line: %d", online);
	
	if(somaMeia > somaInteira){
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
