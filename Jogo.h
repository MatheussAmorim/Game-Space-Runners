#pragma once
#include "Personagem.h"
#include "Item.h"

enum StatusJogo {
	stMenu, stJogo, stSelecao, stPontuacao,
	stInstrucoes, stCreditos, stPause, stSair
};

class Jogo
{
	public:
		Jogo();
		~Jogo();

		void inicializar();
		void finalizar();
		void executar();
		void resetar();
	
	protected:
		StatusJogo tela;
		Sprite fundo, fundoPause, menu, libLogo, uniLogo, gameLogo, estrela, painel;
		Personagem personagem[4];
		float fx1, fx2, fy1, fy2;
		Texto texto;
		Item item[15];
		bool colisao;
		int nPersonagens;
		BotaoSprite bPlay, bCreditos, bInstrucoes, bSair, bVoltar, bContinuar, bJogadores1, bJogadores2, bJogadores3, bJogadores4;
		Uint64 tempoInicial, tempoPauseInicial;
		int tempo, tempoMaximo, totalVidas;

		void telaMenu();
		void telaJogo();
		void telaSelecao();
		void telaPontuacao();
		void telaInstrucoes();
		void telaCreditos();
		void telaPause();
};

