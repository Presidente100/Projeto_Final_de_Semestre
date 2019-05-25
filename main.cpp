/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2� Semestre Ci�ncia da Computa��o
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/



/* Inclus�o das Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* Biblioteca com Fun��es para Strings */
#include <conio.h> /* Biblioteca da fun��o getch */
#include <locale.h>	/* Biblioteca para Acentua��o */
#include <time.h>/* Biblioteca para Data e Hora */


#include "tela.h"
#include "carro.h"
#include "gotoxy.h"
#include "milisegundos.h"
#include "caracteres.h"


/* Constantes */
#define SAIR 5
#define NUM_CADASTROS 3
#define TAMANHO_NOME 100

#define ASCII_1 176
#define ASCII_2 177
#define ASCII_3 178

#define ASCII_11 219
#define ASCII_12 220
#define ASCII_13 221
#define ASCII_14 222
#define ASCII_15 223
#define ASCII_16 254







const unsigned char CARRO[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS] ={
																			{221, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 222},
																			{223, 223, 223, 223, 219, 219, 219, 219, 219, 219, 219, 223, 223, 223, 223},
																			{177, 177, 177, ' ', ' ', ' ', 219, 219, 219, ' ', ' ', ' ', 177, 177, 177},
																			{177, 177, 177, 220, 219, 219, 219, 219, 219, 219, 219, 220, 177, 177, 177},
																			{177, 177, 177, 223, 219, 219, 219, 219, 219, 219, 219, 223, 177, 177, 177},
																			{177, 177, 177, ' ', 223, 223, 223, 223, 223, 223, 223, ' ', 177, 177, 177}
																		};


/* Estruturas */



/* Declara��o de Fun��es */
int VerificaTeclasDeMovimentacao(char tecla);



/* Fun��o Main */
int main(void)
{
	int movimentar_carro = 0;
	int opcao = 0;
	int indice = 0;	
	
	int linha = 0;
	int coluna = 0;
	
	
	int sentido = 0;
	int auxiliar = 0;	
	int posicao_carro = 0;
	
	unsigned char tela_atual = 0;
	
	
	clock_t tempo_inicio;
	unsigned int milisegundos = 0;
	
	
	/* Permite o uso de Acentua��o */
	setlocale(LC_ALL, "ALL");
		
		
	
		
		
	/* Exibe Carro */
	/*
	for(linha = 0; linha < TAMANHO_CARRO_LINHAS; linha++)
	{
		printf("\n");
		for(coluna = 0; coluna < TAMANHO_CARRO_COLUNAS; coluna++)
		{
			printf("%c", CARRO[linha][coluna]);
		}
	}
	*/
	
	
	
	/*
	printf("\n\n\n");
	Exibir_Numero(0);printf("\n");
	Exibir_Numero(1);printf("\n");
	Exibir_Numero(2);printf("\n");
	Exibir_Numero(3);printf("\n");
	Exibir_Numero(4);printf("\n");
	Exibir_Numero(5);printf("\n");
	Exibir_Numero(6);printf("\n");
	Exibir_Numero(7);printf("\n");
	Exibir_Numero(8);printf("\n");
	Exibir_Numero(9);printf("\n");
	*/
	
	//printf("\n");
	//Cria_Placar();
	//Alterar_Placar(789);
	//Exibe_Placar();
	
	/* Pista */
	/*
	printf("\n%c%c", 177, 219);
	printf("\n%c%c", 219, 177);
	printf("\n%c%c", 177, 219);
	printf("\n%c%c", 219, 177);
	printf("\n%c%c", 177, 219);
	printf("\n%c%c", 219, 177);
	printf("\n%c%c", 177, 219);
	printf("\n%c%c", 219, 177);
	printf("\n%c%c", 177, 219);
	printf("\n%c%c", 219, 177);
	
	getch();
	*/
	
	
	Realiza_Inicializacao_das_Estruturas();
	Exibe_Tela(); // Exibe as Bordas da Tela
	Atualizar_Tela();
	
	
	tempo_inicio = Inicia_Cronometro();
	while(1)
	{		
		milisegundos = Tempo_Cronometro(tempo_inicio);
		
		
		if(milisegundos > 10)
		{
			if(kbhit())
			{
				movimentar_carro = VerificaTeclasDeMovimentacao(getch());
				
				if(movimentar_carro)
				{
					Move_Carro(movimentar_carro);
					Atualizar_Tela();
					movimentar_carro = 0;
				}
			}
			
			
			
			
			
			tempo_inicio = Inicia_Cronometro();
		}
	}
	
	/*
	do
	{
		system("cls");
		
		printf("\n\t\t Agenda Eletr�nica\n");
		
		printf("\n [1] - Cadastrar");
		printf("\n [2] - Pesquisar");
		printf("\n [3] - Listar");
		printf("\n [4] - Classificar");
		printf("\n [5] - Sair");
		printf("\n ");		
		printf("\n Digite a sua Op��o: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				Cadastrar(agenda);
			break;
			
			case 2:
				Pesquisar(agenda);
			break;
			
			case 3:
				Listar(agenda);
			break;
			
			case 4:
				Classificar(agenda);
			break;
			
			case 5:
				system("cls");
				printf("\n\n Programa Finalizado !");
				printf("\n\n\n");
			break;
			
			default:
				system("cls");
				printf("\n\n Op��o Inv�lida !!!");
				getch();
			break;
		}
		
	} while(opcao != SAIR);
	*/
	
}




int VerificaTeclasDeMovimentacao(char tecla)
{
	if	(
			(tecla == 'a') ||
			(tecla == 'A') ||
			(tecla == 75) 
		)
	{
		return MOVER_CARRO_PARA_ESQUERDA;
	}
	
	if	(
			(tecla == 'd') ||
			(tecla == 'D') ||
			(tecla == 77) 
		)
	{
		return MOVER_CARRO_PARA_DIREITA;
	}
	
	return 0;
}














