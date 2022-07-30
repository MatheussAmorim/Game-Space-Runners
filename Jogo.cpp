#include "Jogo.h"
#include <ctime>
Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1280, 720, true);
	srand(time(0));
	tempoMaximo = 60;

	if (!gRecursos.carregouSpriteSheet("fundo"))
	{
		gRecursos.carregarSpriteSheet("fundo", "Assets/imagens/fundo.png");
	}
	fundo.setSpriteSheet("fundo");

	if (!gRecursos.carregouSpriteSheet("menu"))
	{
		gRecursos.carregarSpriteSheet("menu", "Assets/imagens/menu.png");
	}
	menu.setSpriteSheet("menu");

	if (!gRecursos.carregouSpriteSheet("painel"))
	{
		gRecursos.carregarSpriteSheet("painel", "Assets/imagens/painel.png",1,2);
	}
	painel.setSpriteSheet("painel");

	if (!gRecursos.carregouSpriteSheet("libLogo"))
	{
		gRecursos.carregarSpriteSheet("libLogo", "Assets/imagens/lib.png");
	}
	libLogo.setSpriteSheet("libLogo");
	libLogo.setEscala(4, 4);

	if (!gRecursos.carregouSpriteSheet("uniLogo"))
	{
		gRecursos.carregarSpriteSheet("uniLogo", "Assets/imagens/uni.png");
	}
	uniLogo.setSpriteSheet("uniLogo");
	uniLogo.setEscala(0.3, 0.3);

	if (!gRecursos.carregouSpriteSheet("gameLogo"))
	{
		gRecursos.carregarSpriteSheet("gameLogo", "Assets/imagens/gamelogo.png");
	}
	gameLogo.setSpriteSheet("gameLogo");

	if (!gRecursos.carregouSpriteSheet("fundoPause"))
	{
		gRecursos.carregarSpriteSheet("fundoPause", "Assets/imagens/fundoPause.png");
	}
	fundoPause.setSpriteSheet("fundoPause");

	if (!gRecursos.carregouSpriteSheet("bPlay"))
	{
		gRecursos.carregarSpriteSheet("bPlay", "Assets/imagens/bPlay.png", 3);
	}
	bPlay.setSpriteSheet("bPlay");
	bPlay.setPos(615, 430);

	// bVoltar, bContinuar
	if (!gRecursos.carregouSpriteSheet("bCreditos"))
	{
		gRecursos.carregarSpriteSheet("bCreditos", "Assets/imagens/bCreditos.png", 3);
	}
	bCreditos.setSpriteSheet("bCreditos");
	bCreditos.setPos(615, 530);

	if (!gRecursos.carregouSpriteSheet("bInstrucoes"))
	{
		gRecursos.carregarSpriteSheet("bInstrucoes", "Assets/imagens/bInstrucoes.png", 3);
	}
	bInstrucoes.setSpriteSheet("bInstrucoes");
	bInstrucoes.setPos(615, 480);

	if (!gRecursos.carregouSpriteSheet("bSair"))
	{
		gRecursos.carregarSpriteSheet("bSair", "Assets/imagens/bSair.png", 3);
	}
	bSair.setSpriteSheet("bSair");
	bSair.setPos(615, 580);

	if (!gRecursos.carregouSpriteSheet("bVoltar"))
	{
		gRecursos.carregarSpriteSheet("bVoltar", "Assets/imagens/bVoltar.png", 3);
	}
	bVoltar.setSpriteSheet("bVoltar");
	bVoltar.setPos(615, 580);

	if (!gRecursos.carregouSpriteSheet("bContinuar"))
	{
		gRecursos.carregarSpriteSheet("bContinuar", "Assets/imagens/bContinuar.png", 3);
	}
	bContinuar.setSpriteSheet("bContinuar");
	bContinuar.setPos(615, 530);

	//botões qtd jogadores
	if (!gRecursos.carregouSpriteSheet("bJogadores1"))
	{
		gRecursos.carregarSpriteSheet("bJogadores1", "Assets/imagens/1.png", 3);
	}
	bJogadores1.setSpriteSheet("bJogadores1");
	bJogadores1.setPos(500, 460);

	if (!gRecursos.carregouSpriteSheet("bJogadores2"))
	{
		gRecursos.carregarSpriteSheet("bJogadores2", "Assets/imagens/2.png", 3);
	}
	bJogadores2.setSpriteSheet("bJogadores2");
	bJogadores2.setPos(570, 460);

	if (!gRecursos.carregouSpriteSheet("bJogadores3"))
	{
		gRecursos.carregarSpriteSheet("bJogadores3", "Assets/imagens/3.png", 3);
	}
	bJogadores3.setSpriteSheet("bJogadores3");
	bJogadores3.setPos(640, 460);

	if (!gRecursos.carregouSpriteSheet("bJogadores4"))
	{
		gRecursos.carregarSpriteSheet("bJogadores4", "Assets/imagens/4.png", 3);
	}
	bJogadores4.setSpriteSheet("bJogadores4");
	bJogadores4.setPos(710, 460);

	if (!gRecursos.carregouMusica("sound"))
	{
		gRecursos.carregarMusica("sound", "Assets/sons/sound.mp3");
	}
	fx1 = gJanela.getLargura() / 2;
	fy1 = 0;
	fx2 = gJanela.getLargura() / 2;
	fy2 = gJanela.getAltura();

	nPersonagens = 4;

	for (int p = 0; p < nPersonagens; p++)
	{
		personagem[p].inicializar(p + 1);
	}

	for (int i = 0; i < 15; i++)
	{
		item[i].inicializar();
	}

	if (!gRecursos.carregouFonte("fonteRoboto"))
	{
		gRecursos.carregarFonte("fonteRoboto", "assets/fontes/Westminster.ttf", 45);
	}
	texto.setFonte("fonteRoboto");

	texto.setString("Teste de texto");
	texto.setCor(255, 255, 255);
	tela = stMenu;
}

void Jogo::finalizar()
{
	//gRecursos.descarregarSpriteSheet("fundo");
	//gRecursos.descarregarTodosSpriteSheets();
	gRecursos.descarregarTudo();

	uniFinalizar();
}

void Jogo::executar()
{
	gMusica.tocar("sound", true);
	gMusica.setVolumeGlobal(50);

	while (tela != stSair && !gEventos.sair)
	{
		uniIniciarFrame();

		switch (tela)
		{
		case stMenu: telaMenu();
			break;

		case stPause:
		case stJogo: telaJogo();
			break;
		case stSelecao: telaSelecao();
			break;
		case stPontuacao: telaPontuacao();
			break;
		case stInstrucoes: telaInstrucoes();
			break;
		case stCreditos: telaCreditos();
			break;
		case stSair:
			break;
		}

		uniTerminarFrame();
	}
}

void Jogo::resetar()
{
	tempoMaximo = 60;

	fx1 = gJanela.getLargura() / 2;
	fy1 = 0;
	fx2 = gJanela.getLargura() / 2;
	fy2 = gJanela.getAltura();

	nPersonagens = 4;

	for (int p = 0; p < nPersonagens; p++)
	{
		personagem[p].inicializar(p + 1);
	}

	for (int i = 0; i < 15; i++)
	{
		item[i].inicializar();
	}

	if (!gRecursos.carregouFonte("fonteRoboto"))
	{
		gRecursos.carregarFonte("fonteRoboto", "assets/fontes/Westminster.ttf", 45);
	}
	texto.setFonte("fonteRoboto");

	texto.setString("Teste de texto");
	texto.setCor(255, 255, 255);


	tela = stMenu;
}

void Jogo::telaJogo()
{
	fundo.desenhar(fx1, fy1);
	fundo.desenhar(fx2, fy2);

	if (gTeclado.pressionou[TECLA_ESC])
	{
		tela = stPause;
		gMouse.mostrarCursor();
	}

	for (int i = 0; i < 15; i++)
	{
		item[i].desenhar();
	}

	for (int p = 0; p < nPersonagens; p++)
	{
		personagem[p].desenhar();
		texto.setString("Jogador " + to_string(p + 1) + "\nPontuação: " + to_string(personagem[p].getPontuacao()));
		texto.desenhar(320 * (p + 1) - 160, 70);
	}

	if (tela == stJogo)
	{
		
		gMouse.esconderCursor();

		tempo = gTempo.getTempoAteTickAtual(tempoInicial);
		texto.setString("Tempo restante: " + to_string(tempoMaximo - tempo));
		texto.desenhar(gJanela.getLargura() / 2, 150);

		
		if (gTeclado.pressionou[TECLA_P])
		{
			gMusica.pausar();
		}

		if (gTeclado.pressionou[TECLA_C])
		{
			gMusica.continuar();
		}

		if (fy2 < fundo.getAltura() + fundo.getAltura() / 2)
		{
			fy2++;
		}
		else
		{
			fy2 = -fundo.getAltura() / 2;
		}

		if (fy1 < fundo.getAltura() + fundo.getAltura() / 2)
		{
			fy1++;
		}
		else
		{
			fy1 = -fundo.getAltura() / 2;
		}

		for (int i = 0; i < 15; i++)
		{
			item[i].atualizar();

			for (int p = 0; p < nPersonagens; p++)
			{
				item[i].testarColisao(personagem[p].testarColisao(item[i]));
			}

		}

		for (int p = 0; p < nPersonagens; p++)
		{
			personagem[p].atualizar();
		}

		if (tempoMaximo - tempo <= 0)
		{
			tela = stPontuacao;
		}
			
	}
	else // Tela de pause
	{
		fundoPause.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		
		bContinuar.atualizar();
		bContinuar.desenhar();
		if (bContinuar.estaClicado())
		{
			tela = stJogo;
			gMouse.esconderCursor();
		}

		bSair.atualizar();
		bSair.desenhar();
		if (bSair.estaClicado())
		{
			resetar();
		}
	}
}

void Jogo::telaMenu()
{
	menu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	painel.desenhar(110, 550);
	painel.avancarAnimacao();
	painel.setVelocidadeAnimacao(0.8);

	gameLogo.desenhar(gJanela.getLargura() / 2, 200);

	bPlay.atualizar();
	bPlay.desenhar();
	if (bPlay.estaClicado())
	{
		tela = stSelecao;

	}

	bInstrucoes.atualizar();
	bInstrucoes.desenhar();
	if (bInstrucoes.estaClicado())
	{
		tela = stInstrucoes;
	}

	bCreditos.atualizar();
	bCreditos.desenhar();
	if (bCreditos.estaClicado())
	{
		tela = stCreditos;
	}

	bSair.atualizar();
	bSair.desenhar();
	if (bSair.estaClicado())
	{
		tela = stSair;
	}

}

void Jogo::telaSelecao()
{

	texto.setString("Jogadores:");
	texto.desenhar(600, 400);

	bJogadores1.atualizar();
	bJogadores1.desenhar();
	if (bJogadores1.estaClicado()) {

		nPersonagens = 1;
		tela = stJogo;
		tempoInicial = gTempo.getTicks();

	}

	bJogadores2.atualizar();
	bJogadores2.desenhar();
	if (bJogadores2.estaClicado()) {

		nPersonagens = 2;
		tela = stJogo;
		tempoInicial = gTempo.getTicks();

	}

	bJogadores3.atualizar();
	bJogadores3.desenhar();
	if (bJogadores3.estaClicado()) {

		nPersonagens = 3;
		tela = stJogo;
		tempoInicial = gTempo.getTicks();

	}

	bJogadores4.atualizar();
	bJogadores4.desenhar();
	if (bJogadores4.estaClicado()) {

		nPersonagens = 4;
		tela = stJogo;
		tempoInicial = gTempo.getTicks();

	}



}

void Jogo::telaPontuacao()
{
	gMouse.mostrarCursor();

	texto.setString("Pontuações:");
	texto.desenhar(600, 300);
	if (nPersonagens == 1)
	{
		texto.setString("Jogador 1 - " + to_string(personagem[0].getPontuacao()));
		texto.desenhar(600, 350);

	}
	if (nPersonagens == 2)
	{
		texto.setString("Jogador 1 - " + to_string(personagem[0].getPontuacao()));
		texto.desenhar(600, 350);
		texto.setString("Jogador 2 - " + to_string(personagem[1].getPontuacao()));
		texto.desenhar(600, 400);
		
	}
	if (nPersonagens == 3)
	{
		texto.setString("Jogador 1 - " + to_string(personagem[0].getPontuacao()));
		texto.desenhar(600, 350);
		texto.setString("Jogador 2 - " + to_string(personagem[1].getPontuacao()));
		texto.desenhar(600, 400);
		texto.setString("Jogador 3 - " + to_string(personagem[2].getPontuacao()));
		texto.desenhar(600, 450);
	}
	if (nPersonagens == 4)
	{
		texto.setString("Jogador 1 - " + to_string(personagem[0].getPontuacao()));
		texto.desenhar(600, 350);
		texto.setString("Jogador 2 - " + to_string(personagem[1].getPontuacao()));
		texto.desenhar(600, 400);
		texto.setString("Jogador 3 - " + to_string(personagem[2].getPontuacao()));
		texto.desenhar(600, 450);
		texto.setString("Jogador 4 - " + to_string(personagem[3].getPontuacao()));
		texto.desenhar(600, 500);
	}

	bVoltar.atualizar();
	bVoltar.desenhar();
	if (bVoltar.estaClicado())
	{
		resetar();
	}
}

void Jogo::telaInstrucoes()
{
	texto.setString("Colete o máximo de estrelas que conseguir antes do tempo acabar");
	texto.desenhar(650, 150);

	texto.setString("Cuidado para não bater e perder seus pontos");
	texto.desenhar(650, 200);

	texto.setString("Controles:");
	texto.desenhar(600, 300);

	texto.setString("Jogador 1: WASD / Joystick 1");
	texto.desenhar(600, 350);
	texto.setString("Jogador 2: IJKL / Joystick 2");
	texto.desenhar(600, 400);
	texto.setString("Jogador 3: SETAS / Joystick 3");
	texto.desenhar(600, 450);
	texto.setString("Jogador 4: NUM-8456  / Joystick 4");
	texto.desenhar(600, 500);

	bVoltar.atualizar();
	bVoltar.desenhar();
	if (bVoltar.estaClicado())
	{
		tela = stMenu;
	}
}

void Jogo::telaCreditos()
{
	texto.setString("Programado por Matheus Amorim");
	texto.desenhar(650, 180);
	texto.setString("Arte por Natália Evangelista");
	texto.desenhar(650, 260);
	texto.setString("Música: Porter Robinson - Sad Machine (littlelamp100 remix)");
	texto.desenhar(650, 340);
	texto.setString("Orientado pelo Prof. Fernando Pinho Marson");
	texto.desenhar(650, 420);
	texto.setString("Desenvolvido para a atividade de Algoritmos e Programação em C++");
	texto.desenhar(650, 500);

	libLogo.desenhar(300, 580);
	uniLogo.desenhar(980, 580);

	bVoltar.atualizar();
	bVoltar.desenhar();
	if (bVoltar.estaClicado())
	{
		tela = stMenu;
	}
}

void Jogo::telaPause()
{
	
}
