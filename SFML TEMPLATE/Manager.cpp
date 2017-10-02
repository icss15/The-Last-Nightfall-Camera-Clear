#include "Manager.h"



Manager::Manager()
{
	janela = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TOE: The Last Nightfall");
	p1.m_texture.loadFromFile("BG_Menu_1280x720.png");
	p1.m_sprite.setTexture(p1.m_texture);

	p1.m_BallTexture.loadFromFile("Escolha_Menu.png");
	p1.m_Ball.setTexture(p1.m_BallTexture);
	p1.m_Ball.setPosition(395, 270);

	GO.m_GameOverScreen.loadFromFile("GameOver.png");
	GO.m_GameOver.setTexture(GO.m_GameOverScreen);
	GO.m_GameOver.setPosition(225, 100);

	j.m_JogoScreen.loadFromFile("Jogo.png");
	j.m_Jogo.setTexture(j.m_JogoScreen);
	j.m_Jogo.setPosition(225, 50);

	j.m_playerTexture.loadFromFile("Player.png");
	j.m_player.setTexture(j.m_playerTexture);
	j.m_player.setPosition(225, 50);


	j.m_ayoTexture.loadFromFile("Ayo.jpg");
	j.m_ayo.setTexture(j.m_ayoTexture);
	j.m_ayo.setPosition(225, 50);

	i.m_inimigoTexture.loadFromFile("inimigo.png");
	i.m_inimigo.setTexture(i.m_inimigoTexture);
	i.m_inimigo.setPosition(500, 50);

	j.m_LeftTexture.loadFromFile("Left.jpg");
	j.m_Left.setTexture(j.m_LeftTexture);
	j.m_Left.setPosition(1000, 50);

	j.m_RightTexture.loadFromFile("Right.jpg");
	j.m_Right.setTexture(j.m_RightTexture);
	j.m_Right.setPosition(500, 50);

	a.m_arrowTexture.loadFromFile("Arrow.png");
	a.m_arrow.setTexture(a.m_arrowTexture);

	j.m_vidaTexture.loadFromFile("Heart.jpg");
	j.m_vida1.setTexture(j.m_vidaTexture);
	j.m_vida1.setPosition(1, -100);


	j.m_vida2Texture.loadFromFile("Heart.jpg");
	j.m_vida2.setTexture(j.m_vida2Texture);
	j.m_vida2.setPosition(50, -100);


	j.m_vida3Texture.loadFromFile("Heart.jpg");
	j.m_vida3.setTexture(j.m_vida3Texture);
	j.m_vida3.setPosition(100, -100);



}


Manager::~Manager()
{
	delete janela;
}

void Manager::Programa()
{
	while (Quit == false)
	{
		Inputs();
		Update();
		Render();
	}
}

void Manager::Inputs()
{
	while (janela->pollEvent(eventos))
	{
		posicaoMouse = sf::Mouse::getPosition(*janela);
		j.posicaoPlayer = j.m_player.getPosition();
		switch (eventos.type)
		{
		case sf::Event::Closed:
			Quit = true;
			break;
		case sf::Event::KeyPressed:
			InputTeclado();
			break;
		case sf::Event::MouseButtonPressed:
			MouseClicado();
			break;
		case sf::Event::MouseMoved:
			MouseMovido();
			break;
		}
	}
}

void Manager::Update()
{
	switch (EstadoTela)
	{
	case MENU:
		UpdateMenu();
		break;
		
	case JOGO:
		UpdateJogo();
		break;

	case GAMEOVER:
		UpdateGameOver();
		break;
	}
}

void Manager::Render()
{
	janela->clear();
	switch (EstadoTela)
	{
	case MENU:
		RenderMenu();
		break;

	case JOGO:
		RenderJogo();
		break;

	case GAMEOVER:
		RenderGameOver();
		break;
	case QUIT: 
		Quit = true;
		break;
	}
	janela->display();
}

void Manager::UpdateMenu()
{

	

}

void Manager::UpdateJogo()
{
	if (j.m_inimigo.getGlobalBounds().intersects(j.m_player.getGlobalBounds())) // Floor
	{
		j.m_player.setPosition(j.m_inimigo.getPosition().x - j.m_player.getPosition().x, j.m_inimigo.getPosition().y - j.m_player.getPosition().y);
		vida == vida - 1;

	}

	sf::View view(sf::FloatRect(500, 500, 600, 500));
	view.setCenter(j.m_player.getPosition().x, j.m_player.getPosition().y);
	view.setViewport(sf::FloatRect(0.01f, 0.01f, 0.99f, 0.99f));
	janela->setView(view);

	i.destino = (sf::Vector2f)j.posicaoPlayer;
	i.direcaoInimigo = (sf::Vector2f)j.m_player.getPosition() - i.m_inimigo.getPosition();
	sf::Vector2f aux = i.direcaoInimigo*i.velocidade;
	i.m_inimigo.move(aux);

	if (a.atirando = true) {
		sf::Vector2f aux = a.direcaoflecha*a.velocidade;
		a.m_arrow.move(aux);
		a.atirando = false;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (EstadoTela == JOGO) {

			a.destino = (sf::Vector2f)posicaoMouse;
			a.atirando = true;
			a.m_arrow.setPosition(j.m_player.getPosition());
			a.direcaoflecha = (sf::Vector2f)posicaoMouse - j.m_player.getPosition();
		}
	}

	if (j.m_inimigo.getGlobalBounds().intersects(j.m_player.getGlobalBounds())) // Floor
	{
		j.m_player.setPosition(j.m_inimigo.getPosition().x - j.m_player.getPosition().x, j.m_inimigo.getPosition().y - j.m_player.getPosition().y);

	
}

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
	j.m_player.move(0, -0.1);
	j.m_vida1.move(0, -0.1);
	j.m_vida2.move(0, -0.1);
	j.m_vida3.move(0, -0.1);

}

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
{
	j.m_player.move(0, 0.1);
	j.m_vida1.move(0, 0.1);
	j.m_vida2.move(0, 0.1);
	j.m_vida3.move(0, 0.1);

}

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
	j.m_player.move(-0.1, 0);
	j.m_vida1.move(-0.1, 0);
	j.m_vida2.move(-0.1, 0);
	j.m_vida3.move(-0.1, 0);
}

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
	j.m_player.move(0.1, 0);
	j.m_vida1.move(0.1, 0);
	j.m_vida2.move(0.1, 0);
	j.m_vida3.move(0.1, 0);
}
if (vida == 2) {
	j.m_vida2Texture.loadFromFile("Broken.jpg");
	j.m_vida2.setTexture(j.m_vida2Texture);
}
if (vida == 1) {
	j.m_vida3Texture.loadFromFile("Broken.jpg");
	j.m_vida3.setTexture(j.m_vida3Texture);
}
if (vida <= 0) {
	EstadoTela == GAMEOVER;
}


	j.m_ayo.setPosition(sf::Mouse::getPosition().x , sf::Mouse::getPosition().y );

	if (j.m_player.getPosition().x <= 0) {//Left
		j.m_player.setPosition(0.f, j.m_player.getPosition().y);
		if (j.m_player.getPosition().x >= SCREEN_WIDTH - j.m_player.getGlobalBounds().width) //Right
			j.m_player.setPosition(SCREEN_WIDTH - j.m_player.getGlobalBounds().width, j.m_player.getPosition().y);
		if (j.m_player.getPosition().y <= 0) //Top
			j.m_player.setPosition(j.m_player.getPosition().x, 0.f);
		if (j.m_player.getPosition().y >= SCREEN_HEIGHT - j.m_player.getGlobalBounds().height) //Bottom
			j.m_player.setPosition(j.m_player.getPosition().x, SCREEN_HEIGHT - j.m_player.getGlobalBounds().height);
	}
	if (i.m_inimigo.getPosition().x <= 0) {//Left
		i.m_inimigo.setPosition(0.f, i.m_inimigo.getPosition().y);
		if (i.m_inimigo.getPosition().x >= SCREEN_WIDTH - i.m_inimigo.getGlobalBounds().width) //Right
			i.m_inimigo.setPosition(SCREEN_WIDTH - i.m_inimigo.getGlobalBounds().width, i.m_inimigo.getPosition().y);
		if (i.m_inimigo.getPosition().y <= 0) //Top
			i.m_inimigo.setPosition(i.m_inimigo.getPosition().x, 0.f);
		if (i.m_inimigo.getPosition().y >= SCREEN_HEIGHT - i.m_inimigo.getGlobalBounds().height) //Bottom
			i.m_inimigo.setPosition(i.m_inimigo.getPosition().x, SCREEN_HEIGHT - i.m_inimigo.getGlobalBounds().height);
	}
}


void Manager::UpdateGameOver()
{
}

void Manager::RenderMenu()
{
	janela->draw(p1.m_sprite);

	texto1.setFillColor(sf::Color::White);
	
	janela->draw(p1.m_Ball);
}

void Manager::RenderJogo()
{
	janela->draw(j.m_Jogo);

	janela->draw(j.m_player);

	janela->draw(j.m_ayo);

	janela->draw(i.m_inimigo);


	janela->draw(a.m_arrow);
}

void Manager::RenderGameOver()
{
	janela->draw(GO.m_GameOver);
}

void Manager::InputTeclado() {
	P_Menu = &Menu_Op;
	switch (eventos.key.code) {
		case sf::Keyboard::Up:
			switch (Menu_Op) {
			case 0:
				break;
			case 1:
				*P_Menu = 0;
				p1.m_Ball.setPosition(395, 270);
				OpcaoMenu = 1;
				//EstadoTela = JOGO;
				break;
			case 2:
				*P_Menu = 1;
				p1.m_Ball.setPosition(395, 360);
				OpcaoMenu = 2;
				//EstadoTela = OPÇÕES;

				break;
			case 3:
				*P_Menu = 2;
				p1.m_Ball.setPosition(395, 450);
				OpcaoMenu = 3;
				//EstadoTela = GAME OVER;
				break;
			}
			break;

		case sf::Keyboard::Down:
			switch (Menu_Op) {
			case 0:
				*P_Menu = 1;
				p1.m_Ball.setPosition(395, 360);
				OpcaoMenu = 2;
				//EstadoTela = OPÇÕES;
				break;
			case 1:
				*P_Menu = 2;
				p1.m_Ball.setPosition(395, 450);
				OpcaoMenu = 3;
				//EstadoTela = GAME OVER;
				break;
			case 2:
				*P_Menu = 3;
				p1.m_Ball.setPosition(395, 530);
				OpcaoMenu = 4;
				//EstadoTela = SAIR;
				break;
			}
			break;

	case sf::Keyboard::Escape:
		Quit = true;
		break;

	case sf::Keyboard::Return:
		if (OpcaoMenu == JOGO)
			EstadoTela = JOGO;
		else if (OpcaoMenu == GAMEOVER)
			EstadoTela = GAMEOVER;
		else if (OpcaoMenu == QUIT)
			EstadoTela = QUIT;
		break;
	}
}


void Manager::MouseClicado()
{
	switch (eventos.mouseButton.button)
	{
	case sf::Mouse::Left: //Mouse Botao Esquerdo Pressionado


		break;

	case sf::Mouse::Right: //Mouse Botao Direito Pressionado
		break;
	}
}

void Manager::MouseMovido() {
	
}
