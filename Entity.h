#pragma once

#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

//float deltaTime = 1;

class Entity {
protected:
	Vector2<float> size;
	float mass;
	string name;
	Vector2<float> velocity;
	float gravity = 9.8f;

	RectangleShape body;

	bool isGround = false;


	void ApplyGravity() {
		velocity.y += gravity * 1 / 20;
	}
public:
	Entity() {
		body.setFillColor(Color(0, 0, 0, 0));
		body.setOutlineColor(Color::Red);
		body.setOutlineThickness(4);
		name = "Default";
		mass = 0;
		velocity.x = velocity.y = 0;

	}
	virtual void Update() {
		if (!isGround)
			ApplyGravity();
		else velocity.y = 0;
	}

	virtual void Draw(RenderWindow& rd) {
		rd.draw(body);
	}

	void resize(Vector2f size) {
		body.setSize(size);
	}

	void setPosition(Vector2f position) {
		body.setPosition(position);
	}

	virtual bool isCollision(Entity* other) {
		/*
			Collision AABB - Tu tim hieu
		*/
		if (other->name == "Pipe") {
			return false;
		}
		if (this->body.getGlobalBounds().intersects(other->body.getGlobalBounds())) {
			isGround = true;
			return true;
		}

		isGround = false;
		return false;
	}

	RectangleShape getBody() { return body; }

};