#pragma once
#include "Entity.h"
#include <iostream>
using namespace std;
class Pipe : public Entity
{
private:
	RectangleShape pipe1, pipe2;
	float distance;
	Vector2f size;
	float speed;
	float x; // position

public:
	Pipe(Vector2f size, Vector2f position, float distance, float speed) {
		name = "Pipe";
		pipe1.setSize(size);
		pipe2.setSize(size);

		pipe1.setOrigin(size * 0.5f);
		pipe2.setOrigin(size * 0.5f);

		pipe1.setPosition(position);

		pipe2.setPosition(position + Vector2f(0, size.y / 2 + distance + size.y / 2));
		this->distance = distance;
		this->size = size;
		this->speed = speed;
		velocity.x = -speed;
	}


	void Update() {
		Move(velocity);
	}

	void Move(Vector2f velocity) {

		pipe1.move(velocity);
		pipe2.move(velocity);


		OutOfScreen();
	}

	void OutOfScreen() {
		if (pipe1.getPosition().x < 0) {
			SetPosition(700);
		}
	}

	void SetPosition(float x) {
		int offset = rand() % 200 - 100;
		Vector2f position(x, pipe1.getPosition().y + offset);

		/*
		Random -50 50
		*/
		pipe1.setPosition(position);
		pipe2.setPosition(position + Vector2f(0, size.y / 2 + distance + size.y / 2));
		cout << pipe2.getPosition().y << "\n";
	}

	void Draw(RenderWindow& rd) {
		rd.draw(pipe1);
		rd.draw(pipe2);
	}


	bool isCollision(Entity* other) {
		if (other->getBody().getGlobalBounds().intersects(pipe1.getGlobalBounds()) ||
			other->getBody().getGlobalBounds().intersects(pipe2.getGlobalBounds())) {
			cout << "Game Over\n";
			return true;
		}
		return false;
	}
};

