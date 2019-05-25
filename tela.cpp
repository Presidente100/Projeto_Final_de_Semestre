/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2� Semestre Ci�ncia da Computa��o
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/


/* Bibliotecas */
#include <stdio.h>

#include "tela.h"
#include "carro.h"
#include "gotoxy.h"
#include "caracteres.h"


/* Constantes */
# define POSICAO_PLACAR_DIGITO_1 0
# define POSICAO_PLACAR_DIGITO_2 5
# define POSICAO_PLACAR_DIGITO_3 10

const unsigned char CARRO[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS] ={
																			{221, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 222},
																			{223, 223, 223, 223, 219, 219, 219, 219, 219, 219, 219, 223, 223, 223, 223},
																			{177, 177, 177, ' ', ' ', ' ', 219, 219, 219, ' ', ' ', ' ', 177, 177, 177},
																			{177, 177, 177, 220, 219, 219, 219, 219, 219, 219, 219, 220, 177, 177, 177},
																			{177, 177, 177, 223, 219, 219, 219, 219, 219, 219, 219, 223, 177, 177, 177},
																			{177, 177, 177, ' ', 223, 223, 223, 223, 223, 223, 223, ' ', 177, 177, 177}
																		};

/* Estruturas */

struct struct_Carro
{
	//int pos_top_left_linha; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo do Carro
	//int pos_top_left_coluna; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo do Carro
	
	int posicao_atual_carro;
	unsigned char carro[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS];
} carro;
	
struct struct_Placar
{
	//int pos_top_left_linha; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo do Placar
	//int pos_top_left_coluna; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo do Placar
	
	unsigned char placar[TAMANHO_PLACAR_LINHAS][TAMANHO_PLACAR_COLUNAS];
} placar;

struct struct_Tela
{
	int pos_top_left_linha; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo da Tela
	int pos_top_left_coluna; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo da Tela
		
	unsigned char tela_atual;
	unsigned char proxima_tela;
	unsigned char tela[NUMERO_DE_TELAS][TAMANHO_TELA_LINHAS][TAMANHO_TELA_COLUNAS];
} tela;


/* Fun��es Privadas */


/* GERAIS */
void Realiza_Inicializacao_das_Estruturas()
{
	Cria_Carro();
	Cria_Placar();
	Alterar_Placar(0);
	//Cria_Pistas();
	Inicializa_Telas();
	
}



/* CARRO */
void Cria_Carro()
{
	int linha = 0;
	int coluna = 0;
	
	char auxiliar[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS] ={
																	{221, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 222},
																	{223, 223, 223, 223, 219, 219, 219, 219, 219, 219, 219, 223, 223, 223, 223},
																	{177, 177, 177, ' ', ' ', ' ', 219, 219, 219, ' ', ' ', ' ', 177, 177, 177},
																	{177, 177, 177, 220, 219, 219, 219, 219, 219, 219, 219, 220, 177, 177, 177},
																	{177, 177, 177, 223, 219, 219, 219, 219, 219, 219, 219, 223, 177, 177, 177},
																	{177, 177, 177, ' ', 223, 223, 223, 223, 223, 223, 223, ' ', 177, 177, 177}
																};

	
	/* Carrega o Carro para dentro da Matriz carro */
	for(linha = 0; linha < TAMANHO_CARRO_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_CARRO_COLUNAS; coluna++)
		{
			carro.carro[linha][coluna] = auxiliar[linha][coluna];
		}
	}
}



void Move_Carro(int movimentar_carro)
{
	carro.posicao_atual_carro += movimentar_carro;
}



void Inserir_Carro_na_Tela()
{
	int linha = 0;
	int coluna = 0;
	
	//int pos_top_left_linha = TAMANHO_TELA_LINHAS - ESPESSURA_BORDA_TELA - TAMANHO_CARRO_LINHAS;
	//int pos_top_left_coluna = (TAMANHO_TELA_COLUNAS / 2) - (TAMANHO_CARRO_COLUNAS / 2);
	
		
	for(linha = 0; linha < TAMANHO_CARRO_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_CARRO_COLUNAS; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + POSICAO_CARRO_LINHA][coluna + POSICAO_CARRO_COLUNA + carro.posicao_atual_carro] = carro.carro[linha][coluna];
		}
	}	
}



/* PLACAR */
void Cria_Placar()
{
	int linha = 0;
	int coluna = 0;
	
	char auxiliar[TAMANHO_PLACAR_LINHAS][TAMANHO_PLACAR_COLUNAS] =	{
																		{201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188}
																	};

	
	/* Define a Posi��o na Tela onde o Placar deve come�ar a ser desenhado */
	//placar.pos_top_left_linha = ESPESSURA_BORDA_TELA + 1;
	//placar.pos_top_left_coluna = ESPESSURA_BORDA_TELA + 1;
	
	/* Carrega o Placar para dentro da Matriz placar */
	for(linha = 0; linha < TAMANHO_PLACAR_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PLACAR_COLUNAS; coluna++)
		{
			placar.placar[linha][coluna] = auxiliar[linha][coluna];
		}
	}
}



void Alterar_Placar(int pontuacao)
{
	int linha = 0;
	int coluna = 0;
	int digito = 0;
	int numero[3] = {0, 0, 0};
	
	/* Valida��o da Pontua��o */
	if((pontuacao < 0) || (pontuacao > 999))
	{
		pontuacao = 0;
	}
	else
	{
		/* Separa os D�gitos da Pontua��o */
		numero[0] = pontuacao / 100;
		numero[1] = (pontuacao - (numero[0] * 100)) / 10;
		numero[2] = (pontuacao - (numero[0] * 100) - (numero[1] * 10));
	}
	
		
	/* Insere a Pontua��o */
	for(digito = 0; digito < 3; digito++)
	{
		for(linha = ESPESSURA_BORDA_PLACAR; linha < (TAMANHO_PLACAR_LINHAS - ESPESSURA_BORDA_PLACAR); linha++)
		{
			
			for(coluna = ESPESSURA_BORDA_PLACAR; coluna < (TAMANHO_CARACTER_COLUNAS + ESPESSURA_BORDA_PLACAR); coluna++)
			{
				switch(digito)
				{
					case 0:
						placar.placar[linha][coluna + POSICAO_PLACAR_DIGITO_1] = Montar_Caractere(numero[0], (linha - ESPESSURA_BORDA_PLACAR), (coluna - ESPESSURA_BORDA_PLACAR));
					break;
					
					case 1:
						placar.placar[linha][coluna + POSICAO_PLACAR_DIGITO_2] = Montar_Caractere(numero[1], (linha - ESPESSURA_BORDA_PLACAR), (coluna - ESPESSURA_BORDA_PLACAR));
					break;
					
					case 2:
						placar.placar[linha][coluna + POSICAO_PLACAR_DIGITO_3] = Montar_Caractere(numero[2], (linha - ESPESSURA_BORDA_PLACAR), (coluna - ESPESSURA_BORDA_PLACAR));
					break;
				}
			}
		}
	}
}



void Inserir_Placar_na_Tela()
{
	int linha = 0;
	int coluna = 0;
	
		
	for(linha = 0; linha < TAMANHO_PLACAR_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PLACAR_COLUNAS; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + POSICAO_PLACAR_LINHA][coluna + POSICAO_PLACAR_COLUNA] = placar.placar[linha][coluna];
		}
	}	
}



void Exibe_Placar()
{
	int linha = 0;
	int coluna = 0;
		
	
	for(linha = 0; linha < TAMANHO_PLACAR_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PLACAR_COLUNAS; coluna++)
		{
			printf("%c", placar.placar[linha][coluna]);
		}
		
		printf("\n");
	}	
}



/* TELA */
void Inicializa_Telas()
{
	int indice = 0;
	
	/* Inicializa Vari�veis */
	tela.pos_top_left_linha = 0; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo da Tela
	tela.pos_top_left_coluna = 0; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo da Tela
		
	tela.tela_atual = 0;
	tela.proxima_tela = 1;
	
	for(indice = 0; indice < NUMERO_DE_TELAS; indice++)
	{
		Limpa_Tela(indice);
	}	
}



void Limpa_Tela(unsigned char indice_tela)
{
	int linha = 0;
	int coluna = 0;
		
	
	/* Preenche a Tela com o caracter Espa�o (Deixa a Tela "Em Branco") */
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
			tela.tela[indice_tela][linha][coluna] = 32; // Caractere Espa�o
		}
	}
	
	/* Coloca as Bordas Horizontais (Superior e Inferior) */
	for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
	{			
		tela.tela[indice_tela][0][coluna] = 205;
		tela.tela[indice_tela][TAMANHO_TELA_LINHAS - 1][coluna] = 205;
	}
	
	/* Coloca as Bordas Verticais (Esquerda e Direita) */
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{			
		tela.tela[indice_tela][linha][0] = 186;
		tela.tela[indice_tela][linha][TAMANHO_TELA_COLUNAS - 1] = 186;
	}
	
	/* Coloca as Bordas nos V�rtices */
	tela.tela[indice_tela][0][0] = 201;
	tela.tela[indice_tela][0][TAMANHO_TELA_COLUNAS - 1] = 187;
	tela.tela[indice_tela][TAMANHO_TELA_LINHAS - 1][0] = 200;
	tela.tela[indice_tela][TAMANHO_TELA_LINHAS - 1][TAMANHO_TELA_COLUNAS - 1] = 188;
	
}



void Exibe_Tela()
{
	int linha = 0;
	int coluna = 0;
		
	
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
			if(tela.tela[TELA_AUXILIAR][linha][coluna] != 0)
			{
				gotoxy(linha, coluna);
				printf("%c", tela.tela[TELA_AUXILIAR][linha][coluna]);
			}
		}
	}
}



void Atualizar_Tela()
{
	int linha = 0;
	int coluna = 0;
	
	Limpa_Tela(tela.proxima_tela);
	//Inserir_Pista_na_Tela();
	Inserir_Placar_na_Tela();
	Inserir_Carro_na_Tela();
	Comparar_Tela_Atual_com_Proxima_Tela();
	Exibe_Tela();
	
	/* Atualiza �ndices */
	tela.tela_atual		= (~tela.tela_atual) & 0x01;
	tela.proxima_tela	= (~tela.proxima_tela) & 0x01;
	
}



void Comparar_Tela_Atual_com_Proxima_Tela()
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{				
			if	(tela.tela[tela.tela_atual][linha][coluna] != tela.tela[tela.proxima_tela][linha][coluna])
			{
				tela.tela[TELA_AUXILIAR][linha][coluna] = tela.tela[tela.proxima_tela][linha][coluna];
			}
			else
			{
				tela.tela[TELA_AUXILIAR][linha][coluna] = 0;
			}
		}
	}
	
}




/*
void Montar_Proxima_Tela()
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
		}
	}
	
}
*/










