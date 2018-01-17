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

	//**********************************************************

	//***********************Game Paused************************

	bool paused = true;

	//**********************************************************

	//******************while window is open********************

	while(window.isOpen())
	{
		//*****************Escape Key**************************
		if(Keyboard :: isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//*****************************************************


		//**************Enter Key******************************

		if(Keyboard :: isKeyPressed(Keyboard :: Return))
		{
			paused = false;
		}

		if(!paused)
		{
			Time t = clock.restart();

			//********************BEE******************************
			// BEE FLYING
			if(!beeFlying)
			{
				// Speed
				srand((int)time(0) *10);
				// Speed between 200 to 399
				beeSpeed = (rand() % 200) +200;

				// Height
				srand((int) time(0) * 10);
				// Height between 500 to 999
				float height = (rand() %500) + 500;
				beeSprite.setPosition(2000, height);

				beeFlying = true;

			}

			else
			{
				beeSprite.setPosition(beeSprite.getPosition().x -
									 (beeSpeed * t.asSeconds()),
									  beeSprite.getPosition().y);

				if(beeSprite.getPosition().x < -100)
				{
					beeFlying = false;
				}
			}

			//****************************************************


			//*********************CLOUD1*************************

			if(!cloud1Moving)
					{
						// Speed
						srand((int)time(0) *10);
						// Speed between 0 to 199
						cloud1Speed = (rand() % 150);

						// Height
						srand((int) time(0) * 10);
						// Height between 0 to 149
						float cloudHeight = (rand() % 150);
						cloud1.setPosition(-200, cloudHeight);

						cloud1Moving = true;

					}
			else
			{
				cloud1.setPosition(cloud1.getPosition().x +
									 (cloud1Speed * t.asSeconds()),
									 cloud1.getPosition().y);

				if(cloud1.getPosition().x > 2000)
				{
					cloud1Moving = false;
				}
			}

			//****************************************************

			//*********************Cloud2*************************

			if(!cloud2Moving)
					{
						// Speed
						srand((int)time(0) * 10);
						// Speed between 0 to 149
						cloud2Speed = (rand() % 100);

						// Height
						srand((int) time(0) * 10);
						// Height between 0 to 149
						float cloudHeight = (rand() % 150) - 100;
						cloud2.setPosition(-700, cloudHeight);

						cloud2Moving = true;

					}
			else
			{
				cloud2.setPosition(cloud2.getPosition().x +
									 (cloud2Speed * t.asSeconds()),
									 cloud2.getPosition().y);

				if(cloud2.getPosition().x > 2000)
				{
					cloud2Moving = false;
				}
			}

			//****************************************************


			//*********************Cloud3*************************

			if(!cloud3Moving)
					{
						// Speed
						srand((int)time(0) * 10);
						// Speed between 0 to 209
						cloud3Speed = (rand() % 100);

						// Height
						srand((int) time(0) * 20);
						// Height between 0 to 149
						float cloudHeight = (rand() % 350) -150;
						cloud3.setPosition(-1100, cloudHeight);

						cloud3Moving = true;

					}
			else
			{
				cloud3.setPosition(cloud3.getPosition().x +
									 (cloud3Speed * t.asSeconds()),
									 cloud3.getPosition().y);

				if(cloud3.getPosition().x > 2000)
				{
					cloud3Moving = false;
				}
			}

			//********************************************************

		}

		//**********************End (!paused)************************

		window.draw(bgSprite);
		window.draw(cloud1);
		window.draw(cloud2);
		window.draw(cloud3);
		window.draw(treeSprite);
		window.draw(beeSprite);

		window.display();

	}

	//************************************************************

	return 0;

}
