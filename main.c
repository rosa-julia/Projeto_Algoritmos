// PROJETO FINAL: ALGORITMOS E PROGRAMAÇÃO
// INTEGRANTES:
// 1. João Pedro Araujo Sarinho Fonseca - UC22200347 - ADS
// 2. Júlia Cerqueira Brito Rosa - UC22200243 - ADS
// 3. Lucas Soares Garcia - UC22200062 - ADS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Setando os caracteres para português;

    int i = 0, j = 0, opc, qtdSessao, qtdPessoa, idade[10], tipoIngresso, somaM = 0, somaF = 0; // Declarando as variáveis iniciais;
    int crianca = 0, adolescente = 0, adulto = 0, idoso = 0, sobeMasculino = 0, sobeFeminino = 0;

menu:                                                             // Marcação de retorno do menu inicial;
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

    // Definindo os vetores com o tamanho de acordo com o número de sessões;
    int totalInteira[qtdSessao], totalMeia[qtdSessao], sexoM[qtdSessao], sexoF[qtdSessao], sessao[qtdSessao];
    char nomeFilme[qtdSessao][50];
    char sexo[qtdSessao][1];

    system("cls"); // Limpando o terminal

    for (j = 0; j < qtdSessao; j++) //##### INICIANDO A ENTRADADA DE DADOS #####
    {
        printf("Nome do filme: ");
        fflush(stdin);                  // Limpando o buffer do teclado;
        fgets(nomeFilme[j], 50, stdin); // Utilizando a função fgets para receber o nome dos filmes;

        system("cls");

        printf("### SESSÃO %d ###\n\n", j + 1);
        printf("Digite a quantidade de pessoas que assistiram ao filme (Mín. 10): ");
        fflush(stdin); // Limpando o buffer do teclado;
        scanf("%d", &qtdPessoa);
        system("cls");

        if (qtdPessoa < 2) // Validação da quantidade de pessoas;
        {
            do
            {
                printf("### SESSÃO %d ###\n\n", j + 1);
                printf("#AVISO: A quantidade mínima aceita é 10.\nDigite novamente!");
                printf("Digite a quantidade de pessoas que assistiram ao filme (Mín. 10): ");
                fflush(stdin); // Limpando o buffer do teclado;
                scanf("%d", &qtdPessoa);

                system("cls");

            } while (qtdPessoa < 2);
        }

        for (i = 0; i < qtdPessoa; i++)
        {
            printf("### SESSÃO %d ###\n(%dº pessoa)\n\n", j + 1, i + 1);
            printf("Sexo:\n\n-[M]asculino\n-[F]eminino\n\nOpção: ");
            fflush(stdin); // Limpando o buffer do teclado;
            scanf("%c", &sexo);

            if (strcmp(sexo, "M") != 0 && strcmp(sexo, "F") != 0)
            {
                do
                {
                    printf("### SESSÃO %d ###\n(%dº pessoa)\n\n", j + 1, i + 1);
                    printf("#AVISO: Sexo inválido.\nDigite novamente!");
                    printf("Sexo:\n\n-[M]asculino\n-[F]eminino\n\nOpção: ");
                    fflush(stdin); // Limpando o buffer do teclado;
                    scanf("%c", &sexo);

                    system("cls");

                } while (strcmp(sexo, "M") != 0 && strcmp(sexo, "F") != 0);
            }

            if (strcmp(sexo, "M") == 0)
            {
                somaM += 1;
                sexoM[j] = somaM;
            }

            else if (strcmp(sexo, "F") == 0)
            {
                somaF += 1;
                sexoF[j] = somaF;
            }

            system("cls"); // Limpando o terminal

            printf("### SESSÃO %d ###\n(%dº pessoa)\n\n", j + 1, i + 1);
            printf("Idade (Mín. 3 | Máx. 100): ");
            fflush(stdin); // Limpando o buffer do teclado;
            scanf("%d", &idade[i]);

            if (idade[i] < 3 || idade[i] > 100)
            {
                do
                {
                    printf("### SESSÃO %d ###\n(%dº pessoa)\n\n", j + 1, i + 1);
                    printf("#AVISO: Idade inválida.\nDigite novamente!");
                    printf("Idade (Mín. 3 | Máx. 100): ");
                    fflush(stdin); // Limpando o buffer do teclado;
                    scanf("%d", &idade[i]);

                    system("cls"); // Limpando o terminal;

                } while (idade[i] < 3 || idade[i] > 100);
            }
            if (idade[j] > 18 && strcmp(sexoF[j], "[F]eminino") == 0)  
			{
		  		sobeFeminino++;
			}
	      	else if (idade[j] > 18 && strcmp(sexoM[j], "[M]asculino") == 0)
				{
		  		sobeMasculino++;
				}

	      		if (idade[j] >= 3 && idade[j] <= 13)
				{
		 			crianca++;
				}
				else if (idade[j] >= 14 && idade[j] <= 17)
				{
		  			adolescente++;
				}
	      		else if (idade[j] >= 18 && idade[j] <= 64)
				{
		 			adulto++;
				}
	     		 else if (idade[j] >= 65 && idade[j] <= 100)
				{
		 			idoso++;
				}
                system("cls"); // Limpando o terminal;
                

        telaIngresso:
            printf("### SESSÃO %d ###\n(%dº pessoa)\n\n", j + 1, i + 1);
            printf("Tipo de ingresso:\n\n-1. Inteira (R$ 50,00)\n-2. Meia (R$ 25,00)\n\nOpção: ");
            fflush(stdin);              // Limpando o buffer do teclado;
            scanf("%d", &tipoIngresso); // Recebe o valor do tipo de ingresso

            if (tipoIngresso == 1) // Caso o ingresso seja tipo 1 (Inteira)
            {
                totalInteira[j] = 25; // Adicionando valor na entrada inteira;
            }
            else if (tipoIngresso == 2) // Caso o ingresso seja tipo 2 (Meia)
            {
                totalMeia[j] = 50; // Adicionando valor na entrada meia;
            }
            else
            {
                system("cls"); // Limpando o terminal
                printf("#AVISO: Digite uma opção válida!\n");
                goto telaIngresso; // Retorna à marcação de tela do tipo de ingresso
            }

            system("cls"); // Limpando o terminal
        }
        somaM = 0; // Zerando o valor do contador da quantidade de pessoas do sexo masculino
        somaF = 0; // Zerando o valor do contador da quantidade de pessoas do sexo feminino
    }

    for (j = 0; j < qtdSessao; j++)
    {                                                 //##### INICIANDO A SAÍDA DE DADOS #####
        printf("\n\n### SESSÃO %d ###\n\n", j + 1);   // Imprimindo a sessão correspondente
        printf("-Nome do filme: %s\n", nomeFilme[j]); // Imprimindo nome do filme
        printf("-Feminino: %d\n  -Masculino: %d\n", sexoF[j], sexoM[j]);
    } // Imprimindo a quantidade total de pessoas Masculinas e Femininas que estavam presentes na sessão.

    return 0;
}
