#pragma once
#include "Entity.h"
class Ground : public Entity
{
private:
	RectangleShape ground;

public:

	Ground() {
		ground.setSize(Vector2f(1000, 100));
		ground.setOrigin(ground.getSize() * 0.5f);
		ground.setPosition(Vector2f(0, 500));

		this->body.setPosition(ground.getPosition());
		
		this->resize(ground.getSize());

		this->body.setOrigin(ground.getSize() * 0.5f);
	}

	void Update() {

	}

	void Draw(RenderWindow& rd) {
		Entity::Draw(rd);
		rd.draw(ground);
	}

};

