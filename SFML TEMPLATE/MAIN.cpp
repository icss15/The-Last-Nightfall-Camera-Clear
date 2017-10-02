#include <iostream>
#include <SFML\Main.hpp>
#include "Manager.h"

int main() {
	sf::Music Menu_Musica; if (!Menu_Musica.openFromFile("Musicas/Musica_Menu.ogg")) return -1; // error music.play();
	Menu_Musica.setLoop(true);
	Menu_Musica.play();
	Menu_Musica.setVolume(50);

	sf::Music Menu_Vento; if (!Menu_Vento.openFromFile("Musicas/Som_Vento_Menu.wav")) return -1; // error music.play();
	Menu_Vento.setLoop(true);
	Menu_Vento.play();
	Menu_Vento.setVolume(25);

	sf::Music Menu_Fundo; if (!Menu_Fundo.openFromFile("Musicas/Som_Fundo_Menu.wav")) return -1; // error music.play();
	Menu_Fundo.setLoop(true);
	Menu_Fundo.play();
	Menu_Fundo.setVolume(50);

	Manager *manager = new Manager();
	manager->Programa();
	delete manager;
	return 0;
}