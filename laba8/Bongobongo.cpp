#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main() {

	sf::Texture cowboy_img;
	sf::RenderWindow window(sf::VideoMode(336, 188), "cowboy");

	cowboy_img.loadFromFile("source/cowboy.jpg");

	sf::Sprite cowboy_fond;
	cowboy_fond.setTexture(cowboy_img);
	
	sf::Texture circle_bobs;
	circle_bobs.loadFromFile("source/cowboy.jpg");
	sf::CircleShape shape(30.f);
	shape.setPosition(10, 10);
	shape.setTexture(&circle_bobs);

	sf::Music music;
	music.openFromFile("source/song.ogg");
	music.play();
	music.setVolume(100);

	sf::Font font;
	font.loadFromFile("source/Antarctic.otf");
	sf::Text text("TExt epta", font, 20);
	text.setPosition(150, 150);
	text.setColor(sf::Color::Black);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(cowboy_fond);
		window.draw(shape);
		window.draw(text);
		window.display();

	}

	return 0;





}