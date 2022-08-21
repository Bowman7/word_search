#include<SFML/Graphics.hpp>
class word
{
public:
	word();
	void run();
private:
	void processEvents();
	void update();
	void render();
private:
	sf::RenderWindow mWindow;
	sf::Texture mTexture;
	sf::Sprite mSprite;
   
};
word::word()
	:mWindow(sf::VideoMode(1000,1000),"cruel world ")
{
	
}
void word::run()
{
	sf::Clock clock;
	sf::Time timeSince=sf::Time::Zero;
	while(mWindow.isOpen())
	{
		processEvents();
		timeSince+=clock.restart();
		while(timeSince>sf::seconds(1.f/60.f))
		{
			timeSince-=sf::seconds(1.f/60.f);
			processEvents();
			update();
		}
		render();
	}
	
}
void word::processEvents()
{
	sf::Event event;
	while(mWindow.pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::Closed:
			mWindow.close();break;
		}
	}
}
void word::update()
{
	
}
void word::render()
{
	mWindow.clear();
	mWindow.display();
}
int main()
{
	word world;
	world.run();
	return 0;
}
