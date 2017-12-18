#include <SFML/Graphics.hpp>
#include<cstdio>

using namespace sf;

using namespace Style;


int main()
{
	// VideoMode according to screen resolution
	VideoMode vm(1920,1080);

	// Creating a window with name Timber, opens in full screen
	RenderWindow window(vm, "Timber", Fullscreen);

	//***********************Background Sprite*******************

	// TEXTURE
	Texture bg;
	bg.loadFromFile("graphics/background.png");

	// SPRITE
	Sprite bgSprite;
	bgSprite.setTexture(bg);
	bgSprite.setPosition(0,0);

	//***********************************************************


	//*********************Tree Sprite***************************

	// TEXTURE
	Texture tree;
	tree.loadFromFile("graphics/tree.png");

	// SPRITE
	Sprite treeSprite;
	treeSprite.setTexture(tree);
	treeSprite.setPosition(810,0);

	//***********************************************************


	//********************Bee Sprite*****************************

	// TEXTURE
	Texture bee;
	bee.loadFromFile("graphics/bee.png");

	// SPRITE
	Sprite beeSprite;
	beeSprite.setTexture(bee);
	beeSprite.setPosition(0,800);

	// Boolean for flying bee
	bool beeFlying = false;

	// Speed of bee
	float beeSpeed = 0.0f;

	//**********************************************************


	//********************Cloud Sprite**************************

	// TEXTURE
	Texture cloud;
	cloud.loadFromFile("graphics/cloud.png");

	// SPRITES

	// CLOUD1
	Sprite cloud1;
	cloud1.setTexture(cloud);
	cloud1.setPosition(10,10);

	// CLOUD2
	Sprite cloud2;
	cloud2.setTexture(cloud);
	cloud2.setPosition(250,100);

	// CLOUD3
	Sprite cloud3;
	cloud3.setTexture(cloud);
	cloud3.setPosition(600,150);

	// Boolean for cloud moving
	bool cloud1Moving = false;
	bool cloud2Moving = false;
	bool cloud3Moving = false;

	// Speed of clouds
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	//**********************************************************

	//************************CLOCK*****************************

	Clock clock;

	while(window.isOpen())
	{
		if(Keyboard :: isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		Time t = clock.restart();

		// BEE FLYING
		if(!beeFlying)
		{
			srand((int)Time(0) *10);
			// Speed between 200 to 399
			beeSpeed = (rand() % 200) +200;
		}

		window.draw(bgSprite);
		window.draw(cloud1);
		window.draw(cloud2);
		window.draw(cloud3);
		window.draw(treeSprite);
		window.draw(beeSprite);

		window.display();
	}

	return 0;

}
