#include "libUnicornio.h"
#pragma once

enum TipoItem {tAsteroide1, tAsteroide2, tCometa, tEstrela5, tEstrela10};

class Item
{
public:
	Item();
	~Item();
	void inicializar();
	void resetar();
	void atualizar();
	void desenhar();
	Sprite getSprite() { return sprite; }
	float getX() { return x; }
	float getY() { return y; }
	TipoItem getTipo() { return tipo; }
	void testarColisao(bool colisao);

protected:
	Sprite sprite;
	float x, y, velocidade;
	TipoItem tipo;
	Som som;
};

