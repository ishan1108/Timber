#include <SFML/Graphics.hpp>

using namespace sf;

using namespace Style;


int main()
{
	VideoMode vm(1920,1080);

	RenderWindow window(vm, "Timber", Fullscreen);

	Texture bg;
	bg.loadFromFile("graphics/background.png");

	Sprite bgSprite;
	bgSprite.setTexture(bg);

	bgSprite.setPosition(0,0);

	while(window.isOpen())
	{
		if(Keyboard :: isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.draw(bgSprite);

		window.display();
	}

	return 0;

}
