#include "Item.h"



Item::Item()
{
}


Item::~Item()
{
}

void Item::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("asteroide1"))
	{
		gRecursos.carregarSpriteSheet("asteroide1", "assets/imagens/Asteroide_1.png");
	}
	if (!gRecursos.carregouSpriteSheet("asteroide3"))
	{
		gRecursos.carregarSpriteSheet("asteroide3", "assets/imagens/Asteroide_3.png");
	}
	if (!gRecursos.carregouSpriteSheet("cometa"))
	{
		gRecursos.carregarSpriteSheet("cometa", "assets/imagens/cometa.png", 1,3);
	}
	if (!gRecursos.carregouSpriteSheet("estrela5"))
	{
		gRecursos.carregarSpriteSheet("estrela5", "assets/imagens/estrela.png", 1,3);
	}
	if (!gRecursos.carregouSpriteSheet("estrela10"))
	{
		gRecursos.carregarSpriteSheet("estrela10", "assets/imagens/estrela2.png", 1,3);
	}

	/*
	if (!gRecursos.carregouAudio("moeda"))
	{
		gRecursos.carregarAudio("moeda", "assets/sons/coin.mp3");
	}
	if (!gRecursos.carregouAudio("diamante"))
	{
		gRecursos.carregarAudio("diamante", "assets/sons/coin.mp3");
	}
	*/
	
	
	resetar();


}

void Item::resetar()
{
	tipo = (TipoItem)(rand() % 5); //qtdItens é o número de itens no enum
	//tipo = tMoeda;

	switch (tipo)
	{
	case tAsteroide1: sprite.setSpriteSheet("asteroide1");
		sprite.setEscala(2, 2);
		break;
	case tAsteroide2: sprite.setSpriteSheet("asteroide3");
		sprite.setEscala(2, 2);
		break;
	case tCometa: sprite.setSpriteSheet("cometa");
		sprite.setEscala(2, 2);
		break;
	case tEstrela5: sprite.setSpriteSheet("estrela5");
		sprite.setEscala(2, 2);
		break;
	case tEstrela10: sprite.setSpriteSheet("estrela10");
		sprite.setEscala(2, 2);
		break;
	}
	x = rand() % 900 + sprite.getAltura();
	y = -(rand() % 500) -sprite.getAltura();
	velocidade = 1;
}

void Item::atualizar()
{
	switch (tipo)
	{
	case tCometa:
		velocidade = 2;
		break;
	}
	y += velocidade;
	if (y > gJanela.getAltura() + sprite.getAltura())
	{
		resetar();
	}
	sprite.avancarAnimacao();
}

void Item::desenhar()
{
	sprite.desenhar(x, y);
}

void Item::testarColisao(bool colisao)
{
	if (colisao)
	{
		resetar();
	}
}
