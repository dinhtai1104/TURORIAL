#include "SFML/Graphics.hpp"
#include <iostream>
#include "Animation.h"
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Ground.h"
#include "Pipe.h"
using namespace std;
using namespace sf;


enum STATE {ATTACK, DEFENSE, BEAMSATTACK};

int main() {

	/*
		Animation: loat cac anh.
	
	*/
	RenderWindow window(VideoMode(500, 500), "Hello World");
	window.setFramerateLimit(60);

	Entity* player = new Player();
	Entity* ground = new Ground();
	Entity* pipe = new Pipe(Vector2f(50, 400), Vector2f(700, 0), 100, 3);
	Entity* pipe2 = new Pipe(Vector2f(50, 400), Vector2f(300, 0), 100, 3);

	while (window.isOpen()) {
		
		// Nhận sự kiện
		Event evt;

		while (window.pollEvent(evt)) {
			switch (evt.type)
			{
			case Event::Closed:
				window.close();
				break;
			
			case Event::MouseButtonReleased:
				cout << "Mouse Released\n";
				break;
			case Event::KeyReleased:
				//velocity.x = 0;
				break;
			default:
				break;
			}
		}

		
		player->isCollision(ground);
		pipe->isCollision(player);
		pipe2->isCollision(player);
		player->Update();
		pipe->Update();
		pipe2->Update();
		// Xóa màn hình
		window.clear();


		// Vẽ
		pipe->Draw(window);
		pipe2->Draw(window);
		player->Draw(window);
		ground->Draw(window);
		window.display();


	}


	return 0;
}