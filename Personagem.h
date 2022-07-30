#pragma once
#include "Item.h"

enum JoystickGenerico { BOTAO_JOYSTICK_Y, BOTAO_JOYSTICK_B, BOTAO_JOYSTICK_A, BOTAO_JOYSTICK_X, BOTAO_JOYSTICK_LB, BOTAO_JOYSTICK_RB, BOTAO_JOYSTICK_LT, BOTAO_JOYSTICK_RT, BOTAO_JOYSTICK_BACK, BOTAO_JOYSTICK_START };

class Personagem
{
	public:
		Personagem();
		~Personagem();
		void inicializar(int nPersonagem);
		void atualizar();
		void desenhar();
		bool testarColisao(Item item);

		int getPontuacao() { return pontuacao; }

	protected:
		Sprite sprite;
		float x, y, velocidade;
		int nPersonagem, pontuacao;
};

