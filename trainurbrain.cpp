#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>
#include <sstream>

using namespace sf;

RenderWindow window(VideoMode(720,480),"TrainYourBrain");

void zastavka()
{
    
	Clock clock;  
	std::string FILE;
	while (window.isOpen()){
    	Event event;
    	
    	while (window.pollEvent(event)){
    		if (event.type == Event::Closed)
    		    window.close();
    		if ((event.type == Event::KeyPressed) or (event.type == sf::Event::MouseButtonPressed))
    		    return;
		}
		
	    int time = int(clock.getElapsedTime().asMilliseconds());
	    
	    if (time<500)
	    FILE="10.png";
		else if (time<1000)
		FILE="11.png";
		else if(time<1500)
		FILE="22.png";
        else if((time>1500)&& ((time/500)%2 == 0))
		FILE="333.png";
    	else if ((time>1500) && ((time/500)%2 == 1)) 
		FILE = "33.png";
		Texture tzastavka;
    	tzastavka.loadFromFile(FILE);
    	Sprite szastavka;
    	szastavka.setTexture(tzastavka);
    	szastavka.setPosition(0,0);
    	window.clear();
		window.draw(szastavka);
		window.display();
        }
	}
void kakigrat()
{	
Event event;
	while (window.isOpen()){
		while (window.pollEvent(event)){
    		if (event.type == Event::Closed)
    		    window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {return;}
			Texture tKak;
   			tKak.loadFromFile("kakigrat.png");   
   			Sprite sKak;
			sKak.setTexture(tKak);
   			sKak.setPosition(0,0);
   			window.clear();
			window.draw(sKak);
			window.display();
		}
	}
}
void plane()
{
  	Event event;
	Clock clock;
  	int score,a=0,lives=3,times=0,b=0;
  	std::string file;
	
  	bool ris=false;
  	srand(time(0));
  	a = rand() % 8 + 1;
  while (window.isOpen()&&(lives>0)&&(times<61))
  {
    Event event;
    while (window.pollEvent(event)) {
    	if (event.type == Event::Closed) { window.close(); }
       	times=int(clock.getElapsedTime().asSeconds());
      	if (!ris && Event::KeyReleased){
      		a = rand() % 8 + 1;
      		while (a==b)
			  a = rand() % 8 + 1;
        	if (a == 1) {
          	file = "bluel.png";
          	ris = true;
        	} else if (a == 2) {
          	file = "blueup.png";
          	ris = true;
        	} else if (a == 3) {
          	file = "bluer.png";
          	ris = true;
        	} else if (a == 4) {
          	file = "blued.png";
          	ris = true;
        	} else if (a == 5) {
          	file = "redl.png";
          	ris = true;
        	} else if (a == 6) {
          	file = "redup.png";
          	ris = true;
        	} else if (a == 7) {
          	file = "redr.png";
          	ris = true;
        	} else if (a == 8) {
          	file = "redd.png";
          	ris = true;
        	}
        	Texture texture;
        	texture.loadFromFile(file);
        	Sprite sprite;
        	sprite.setTexture(texture);
        	sprite.setPosition(0, 0);
        	window.clear();
        	window.draw(sprite);
        	window.display();
      }
      	if (ris && event.type == Event::KeyPressed) {   		
        	if (((a == 1) || (a == 5)) && (Keyboard::isKeyPressed(Keyboard::Left))){
          		score++;
          		ris = false;
          		b=a;
        	}
			else if ((a == 1) || (a == 5) && ((Keyboard::isKeyPressed(Keyboard::Right)) ||(Keyboard::isKeyPressed(Keyboard::Up)) ||(Keyboard::isKeyPressed(Keyboard::Down)))) {
          		lives--;
          		ris = false;
          		b=a;
        	}

        	if (((a == 2) || (a == 6)) && (Keyboard::isKeyPressed(Keyboard::Up))) {
          		score++;
          		ris = false;
          		b=a;
        	} 
			else if (((a == 2) || (a == 6)) && ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Left)) ||(Keyboard::isKeyPressed(Keyboard::Down)))) {
          		lives--;
          		ris = false;
          		b=a;
        	}

        	if (((a == 3) || (a == 7)) && (Keyboard::isKeyPressed(Keyboard::Right))) {
          		score++;
          		ris = false;
          		b=a;
        	} 
			else if (((a == 3) || (a == 7)) && ((Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::Up)) ||(Keyboard::isKeyPressed(Keyboard::Down)))) {
          		lives--;
          		ris = false;
          		b=a;
        	}

        	if (((a == 4) || (a == 8)) && (Keyboard::isKeyPressed(Keyboard::Down))) {
          		score++;
          		ris = false;
          		b=a;
        	} 
			else if (((a == 4) || (a == 8)) &&((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Up)) ||(Keyboard::isKeyPressed(Keyboard::Left)))) {
          		lives--;
          		ris = false;
          		b=a;
       		}    
      	}
      	    Text text;
  			Font font;
  			std::ostringstream pscore;
  			pscore << score;
  			font.loadFromFile("font.ttf");
  			text.setFont(font);
  			text.setString("Your score is: " + pscore.str());
  			text.setCharacterSize(48);
  			text.setColor(Color::Blue);
 			text.setPosition(110,110);
    }
  }
  	while (window.isOpen()){
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed) { window.close(); }
  			Text text;
  			Font font;
  			std::ostringstream pscore;
  			pscore << score;
  			font.loadFromFile("font.ttf");
  			text.setFont(font);
  			text.setString("Your score is: " + pscore.str());
  			text.setCharacterSize(48);
  			text.setColor(Color::Blue);
 			text.setPosition(200,260);
  			Texture tzastavka;
    		tzastavka.loadFromFile("gameover.png");
    		Sprite szastavka;
    		szastavka.setTexture(tzastavka);
    		szastavka.setPosition(0,0);
			window.draw(szastavka);
			window.draw(text);
			window.display();
  			if (Keyboard::isKeyPressed(Keyboard::Return))
  				return;
  		}
	}
}
void menu()
{
	while (window.isOpen()){
	Event event;
	while (window.pollEvent(event)){
	if (event.type == Event::Closed)
   	window.close();
	Texture menutexture;
    menutexture.loadFromFile("menu.png");   
    Sprite menusprite;
    menusprite.setTexture(menutexture);
    menusprite.setPosition(0,0);
    window.draw(menusprite);
	window.display();
	if ((sf::Mouse::getPosition(window).x>=217 && sf::Mouse::getPosition(window).x<=503) && (sf::Mouse::getPosition(window).y>=298 && sf::Mouse::getPosition(window).y<=351))
	{
		CircleShape square(15,4);
		square.setFillColor(Color(128,0,128));
		square.setPosition(190,302);
		window.draw(menusprite);
		window.draw(square);
		window.display();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    	{
			plane();
		}
	}
	if ((sf::Mouse::getPosition(window).x>=217 && sf::Mouse::getPosition(window).x<=503) && (sf::Mouse::getPosition(window).y>=436 && sf::Mouse::getPosition(window).y<=480))
	{
		CircleShape square(15,4);
		square.setFillColor(Color(128,0,128));
		square.setPosition(190,440);
		window.draw(menusprite);
		window.draw(square);
		window.display();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			kakigrat();
	}
	}
	}
}
int main(){
	window.setFramerateLimit(120);
	zastavka();
	menu();

	while (window.isOpen()){
    	Event event;
    	while (window.pollEvent(event)){
    		if (event.type == Event::Closed)
    		window.close();
    	}
	}
	return 0;
}



