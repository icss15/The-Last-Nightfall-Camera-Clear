#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280

#define MENU 0
#define JOGO 1
#define OPÇÕES 2
#define GAMEOVER 3
#define QUIT 4

struct Menu
{
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Sprite m_Ball;
	sf::Texture m_BallTexture;
};
struct GameOver {

	sf::Sprite m_GameOver;
	sf::Texture m_GameOverScreen;

};
struct Jogo {

	sf::Sprite m_Jogo;
	sf::Texture m_JogoScreen;
	sf::Sprite m_player;
	sf::Texture m_playerTexture;
	sf::Sprite m_ayo;
	sf::Texture m_ayoTexture;
	sf::Sprite m_inimigo;
	sf::Texture m_inimigoTexture;
	sf::Sprite m_Left;
	sf::Texture m_LeftTexture;
	sf::Sprite m_Right;
	sf::Texture m_RightTexture;
	sf::Vector2f posicaoPlayer;
	sf::Sprite m_vida1;
	sf::Sprite m_vida2;
	sf::Sprite m_vida3;
	sf::Texture m_vidaTexture;
	sf::Texture m_vida2Texture;
	sf::Texture m_vida3Texture;

	
};
struct arrow
{
	sf::Sprite m_arrow;
	sf::Texture m_arrowTexture;
	sf::Vector2f direcaoflecha, destino;
	bool atirando = false;
	float velocidade = .005f;

}; struct inimigo
{
	sf::Sprite m_inimigo;
	sf::Texture m_inimigoTexture;
	sf::Vector2f direcaoInimigo, destino;
	float velocidade = .0005f;
	float posicaoInimigo;
};


class Manager
{
private: //AQUI VOCÊ CRIA AS VARIÁVEIS
	sf::RenderWindow *janela = nullptr;
	sf::Vector2i posicaoMouse;
	sf::Event eventos;
	sf::Font fonte;
	sf::Text texto1;
	sf::Vector2i localPosition;
	sf::Vector2f aimDir;

	short vida = 3;


	Menu p1;
	GameOver GO;
	Jogo j;
	arrow a;
	inimigo i;

	short EstadoTela = MENU, OpcaoMenu = 1;
	bool Quit = false;
	int Menu_Op;
	int *P_Menu;
	float mousex, mousey;
	int directions;
public:
	Manager();
	~Manager();

	void Programa();

	void Inputs();
	void Update();
	void Render();

	void UpdateMenu();
	void UpdateJogo();
	void UpdateGameOver();

	void RenderMenu();
	void RenderJogo();
	void RenderGameOver();

	void InputTeclado();
	void MouseClicado();
	void MouseMovido();


};

