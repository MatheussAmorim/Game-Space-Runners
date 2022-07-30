#include "Personagem.h"



Personagem::Personagem()
{
}


Personagem::~Personagem()
{
}

void Personagem::inicializar(int nPersonagem)
{
	this->nPersonagem = nPersonagem;
	if (!gRecursos.carregouSpriteSheet("nave"))
	{
		gRecursos.carregarSpriteSheet("nave", "Assets/imagens/nave.png", 1, 4);
	}
	if (!gRecursos.carregouSpriteSheet("nave2"))
	{
		gRecursos.carregarSpriteSheet("nave2", "Assets/imagens/nave2.png", 1, 4);
	}
	if (!gRecursos.carregouSpriteSheet("nave3"))
	{
		gRecursos.carregarSpriteSheet("nave3", "Assets/imagens/nave3.png", 1, 5);
	}
	if (!gRecursos.carregouSpriteSheet("nave4"))
	{
		gRecursos.carregarSpriteSheet("nave4", "Assets/imagens/nave4.png", 1, 4);
	}

	sprite.setSpriteSheet("nave");
	if (nPersonagem == 2)
	{
		sprite.setSpriteSheet("nave2");
		sprite.setEscala(1.2, 1.2);
	}
	if (nPersonagem == 3)
	{
		sprite.setSpriteSheet("nave3");
		sprite.setEscala(1.2, 1.2);
	}
	if (nPersonagem == 4)
	{
		sprite.setSpriteSheet("nave4");
		sprite.setEscala(1.2, 1.2);
	}
	sprite.setEscala(2, 2);
	x = 300 * nPersonagem - 128;
	y = 600;
	
	velocidade = 3;
	pontuacao = 0;
}

void Personagem::atualizar()
{
	sprite.avancarAnimacao();
	sprite.setVelocidadeAnimacao(3);

	if (pontuacao <= 0) {

		pontuacao = 0;
	}
	// Jogador 1
	if ((gTeclado.segurando[TECLA_D] || gJoysticks.player1.x > 0) && nPersonagem == 1)
	{
		if (x < gJanela.getLargura() - sprite.getLargura()/2)
		{
			x += velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_A] || gJoysticks.player1.x < 0) && nPersonagem == 1)
	{
		if (x > sprite.getLargura()/2) 
		{
			x -= velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_W] || gJoysticks.player1.y < 0) && nPersonagem == 1)
	{
		if (y > sprite.getAltura() / 2)
		{
			y -= velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_S] || gJoysticks.player1.y > 0) && nPersonagem == 1)
	{
		if (y < gJanela.getAltura() - sprite.getAltura() / 2)
		{
			y += velocidade;
		}
	}
	//Jogador 2
	if ((gTeclado.segurando[TECLA_L] || gJoysticks.player2.x > 0) && nPersonagem == 2)
	{
		if (x < gJanela.getLargura() - sprite.getLargura() / 2)
		{
			x += velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_J] || gJoysticks.player2.x < 0) && nPersonagem == 2)
	{
		if (x > sprite.getLargura() / 2)
		{
			x -= velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_I] || gJoysticks.player2.y < 0) && nPersonagem == 2)
	{
		if (y > sprite.getAltura() / 2)
		{
			y -= velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_K] || gJoysticks.player2.y > 0) && nPersonagem == 2)
	{
		if (y < gJanela.getAltura() - sprite.getAltura() / 2)
		{
			y += velocidade;
		}
	}
	//Jogador 3
	if ((gTeclado.segurando[TECLA_DIR] || gJoysticks.player3.x > 0) && nPersonagem == 3)
	{
		if (x < gJanela.getLargura() - sprite.getLargura() / 2)
		{
			x += velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_ESQ] || gJoysticks.player3.x < 0) && nPersonagem == 3)
	{
		if (x > sprite.getLargura() / 2)
		{
			x -= velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_CIMA] || gJoysticks.player3.y < 0) && nPersonagem == 3)
	{
		if (y > sprite.getAltura() / 2)
		{
			y -= velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_BAIXO] || gJoysticks.player3.y > 0) && nPersonagem == 3)
	{
		if (y < gJanela.getAltura() - sprite.getAltura() / 2)
		{
			y += velocidade;
		}
	}
	//Jogador 4
	if ((gTeclado.segurando[TECLA_KP_6] || gJoysticks.player4.x > 0) && nPersonagem == 4)
	{
		if (x < gJanela.getLargura() - sprite.getLargura() / 2)
		{
			x += velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_KP_4] || gJoysticks.player4.x < 0) && nPersonagem == 4)
	{
		if (x > sprite.getLargura() / 2)
		{
			x -= velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_KP_8] || gJoysticks.player4.y < 0) && nPersonagem == 4)
	{
		if (y > sprite.getAltura() / 2)
		{
			y -= velocidade;
		}
	}
	if ((gTeclado.segurando[TECLA_KP_5] || gJoysticks.player4.y > 0) && nPersonagem == 4)
	{
		if (y < gJanela.getAltura() - sprite.getAltura() / 2)
		{
			y += velocidade;
		}
	}
}

void Personagem::desenhar()
{
	sprite.desenhar(x,y);
}

bool Personagem::testarColisao(Item item)
{
	bool colisao;

	colisao = uniTestarColisao(sprite, x, y, 0, item.getSprite(), item.getX(), item.getY(), 0);
	if(colisao)
	{
		switch (item.getTipo())
		{
			case tEstrela5: 
				pontuacao += 10;
				break;
			case tEstrela10:
				pontuacao += 5;
				break;
			case tCometa:
				pontuacao -= 5;
				break;
			case tAsteroide1:
				pontuacao -= 5;
				break;
			case tAsteroide2:
				pontuacao -= 5;
				break;
		}
	}

	return colisao;
}
