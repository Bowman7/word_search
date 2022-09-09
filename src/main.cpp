#include<SFML/Graphics.hpp>
#include"rand.h"
#include<vector>
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
	sf::Texture selTexture;
	sf::Sprite mSprite[9];
	sf::Sprite trueSprite[9];
	sf::Sprite selectSprite[9];
	sf::Sprite refSelSprite[3];
private:
	float mouseX,mouseY;
   
};
word::word(int psourceRandAr[],int psourceRandRange)
	:mWindow(sf::VideoMode(900,900),"cruel world "),mTexture(),mSprite()
{
	mTexture.loadFromFile("/home/batu/repos/word_search/src/word.png");
	selTexture.loadFromFile("/home/batu/repos/word_search/src/wordselect.png");
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
		selectSprite[k].setTexture(selTexture);
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
		case sf::Event::MouseMoved:
			//	int mousex,mousey;
			mouseX=sf::Mouse::getPosition(mWindow).x;
			mouseY=sf::Mouse::getPosition(mWindow).y;
			std::cout<<"x pos:"<<mouseX<<"ypos:"<<mouseY<<std::endl;
			
		}
	}
}
void word::update()
{
	int refValcount=0;
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		while(refValcount!=3)
		{
			if(mouseX<300 && mouseY<300)
			{
				sf::IntRect s1(0.f,0.f,300,300);
				selectSprite[0].setTextureRect(s1);
				selectSprite[0].setPosition(0.f,0.f);
				refSelSprite[refValcount]=selectSprite[0];
				refValcount++;
			}
			if(mouseX>300 && mouseX<600 && mouseY<300)
			{
				sf::IntRect s2(300.f,0.f,300,300);
				selectSprite[1].setTextureRect(s2);
				selectSprite[1].setPosition(300.f,0.f);
				refSelSprite[refValcount]=selectSprite[1];
				refValcount++;
			}
			if(mouseX>600 && mouseX<900 && mouseY<300)
			{
				sf::IntRect s3(600.f,0.f,300,300);
				selectSprite[2].setTextureRect(s3);
				selectSprite[2].setPosition(600.f,0.f);
				refSelSprite[refValcount]=selectSprite[2];
				refValcount++;
			}
			if(mouseX<300 && mouseY>300 && mouseY<600)
			{
				sf::IntRect s4(0.f,300.f,300,300);
				selectSprite[3].setTextureRect(s4);
				selectSprite[3].setPosition(0.f,300.f);
				refSelSprite[refValcount]=selectSprite[3];
				refValcount++;
			}
			if(mouseX>300 && mouseX<600 && mouseY>300 && mouseY<600)
			{
				sf::IntRect s5(300.f,300.f,300,300);
				selectSprite[4].setTextureRect(s5);
				selectSprite[4].setPosition(300.f,300.f);
				refSelSprite[refValcount]=selectSprite[4];
				refValcount++;
			}
			if(mouseX>600 && mouseX<900 && mouseY>300 && mouseY<600)
			{
				sf::IntRect s6(600.f,300.f,300,300);
				selectSprite[5].setTextureRect(s6);
				selectSprite[5].setPosition(600.f,300.f);
				refSelSprite[refValcount]=selectSprite[5];
				refValcount++;
			}
			if(mouseX<300 && mouseY>600 && mouseY<900)
			{
				sf::IntRect s7(0.f,600.f,300,300);
				selectSprite[6].setTextureRect(s7);
				selectSprite[6].setPosition(0.f,600.f);
				refSelSprite[refValcount]=selectSprite[6];
				refValcount++;
			}
			if(mouseX>300 && mouseX<600 && mouseY>600 && mouseY<900)
			{
				sf::IntRect s8(300.f,600.f,300,300);
				selectSprite[7].setTextureRect(s8);
				selectSprite[7].setPosition(300.f,600.f);
				refSelSprite[refValcount]=selectSprite[7];
				refValcount++;
			}
			if(mouseX>600 && mouseX<900 && mouseY>600 && mouseY<900)
			{
				sf::IntRect s9(600.f,600.f,300,300);
				selectSprite[8].setTextureRect(s9);
				selectSprite[8].setPosition(600.f,600.f);
				refSelSprite[refValcount]=selectSprite[8];
				refValcount++;
			}
			

		}
	}
	
	
}
void word::render()
{
        mWindow.clear();
        for(int i=0;i<9;i++)
	{
		mWindow.draw(trueSprite[i]);
	}
	mWindow.draw(refSelSprite[0]);
	mWindow.draw(refSelSprite[1]);
	mWindow.draw(refSelSprite[2]);
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
