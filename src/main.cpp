#include<SFML/Graphics.hpp>
#include"rand.h"
class word
{
public:
	word(int[],int);
	~word();
	void start();
private:
	int sourceRandAr[9];
	int sourceRandRange;
	void processEvents();
	void update();
	void render();
	void assignPos(int [],sf::Sprite [],int,sf::Sprite []);
	
private:
	sf::RenderWindow mWindow;
	sf::Texture mTexture;
	sf::Sprite mSprite[9];
	sf::Sprite trueSprite[9];
   
};
word::word(int psourceRandAr[],int psourceRandRange)
	:mWindow(sf::VideoMode(900,900),"cruel world "),mTexture(),mSprite()
{
	mTexture.loadFromFile("/home/batu/repos/word_search/src/word.png");
	sourceRandRange=psourceRandRange;
	std::cout<<"sourceranfAr:"<<std::endl;
	for(int i=0;i<sourceRandRange;i++)
	{
		sourceRandAr[i]=psourceRandAr[i];
		std::cout<<sourceRandAr[i]<<std::endl;
	}
	for(int k=0;k<9;k++)
	{
		mSprite[k].setTexture(mTexture);
	}
	assignPos(sourceRandAr,mSprite,9,trueSprite);
	
}
void word::start()
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
        for(int i=0;i<9;i++)
	{
		mWindow.draw(trueSprite[i]);
	}
	mWindow.display();
	
}
void word::assignPos(int ar[],sf::Sprite sp[],int range,sf::Sprite trueSprite[])
{
	float posx,posy;
	posx=0.f;posy=0.f;
	int count =0;
	while(count<=range)
	{
		if(posx==900.f)
		{
			posx=0;
			posy+=300.f;
		}
		if(ar[count]==0)
		{
			sf::IntRect r2(0.f,0.f,300,300);
			sp[0].setTextureRect(r2);
			sp[0].setPosition(posx,posy);
			trueSprite[count]=sp[0];
			posx+=300.f;
		}
		if(ar[count]==1)
		{
			sf::IntRect r3(300.f,0.f,300,300);
			sp[1].setTextureRect(r3);
			sp[1].setPosition(posx,posy);
			trueSprite[count]=sp[1];
			posx+=300.f;
		}
		if(ar[count]==2)
		{
			sf::IntRect r4(600.f,0.f,300,300);
			sp[2].setTextureRect(r4);
			sp[2].setPosition(posx,posy);
			trueSprite[count]=sp[2];
			posx+=300.f;
		}
		if(ar[count]==3)
		{
			sf::IntRect r5(0.f,300.f,300,300);
			sp[3].setTextureRect(r5);
			sp[3].setPosition(posx,posy);
			trueSprite[count]=sp[3];
			posx+=300.f;
		}
		if(ar[count]==4)
		{
			sf::IntRect r6(300.f,300.f,300,300);
			sp[4].setTextureRect(r6);
			sp[4].setPosition(posx,posy);
			trueSprite[count]=sp[4];
			posx+=300.f;
		}
		if(ar[count]==5)
		{
			sf::IntRect r7(600.f,300.f,300,300);
			sp[5].setTextureRect(r7);
			sp[5].setPosition(posx,posy);
			trueSprite[count]=sp[5];
			posx+=300.f;
		}
		if(ar[count]==6)
		{
			sf::IntRect r8(0.f,600.f,300,300);
			sp[6].setTextureRect(r8);
			sp[6].setPosition(posx,posy);
			trueSprite[count]=sp[6];
			posx+=300.f;
		}
		if(ar[count]==7)
		{
			sf::IntRect r9(300.f,600.f,300,300);
			sp[7].setTextureRect(r9);
			sp[7].setPosition(posx,posy);
			trueSprite[count]=sp[7];
			posx+=300.f;
		}
		if(ar[count]==8)
		{
			sf::IntRect r10(600.f,600.f,300,300);
			sp[8].setTextureRect(r10);
			sp[8].setPosition(posx,posy);
			trueSprite[count]=sp[8];
			posx+=300.f;
		}
		count++;
	}
}
word::~word()
{
	std::cout<<"destructor"<<std::endl;
}
int main()
{
	int realAr[9];
	int refAr[9];
	run(refAr,9);
	switchAr(realAr,refAr);
	std::cout<<"asdf";
	word world(realAr,9);
	world.start();
	return 0;
}
