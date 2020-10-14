#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
using namespace std;
using namespace sf;
class Animation
{
public:
	Animation() {}
	Animation(int countImage, string fileName, float deltaTime) {
		for (int i = 1; i <= countImage; i++) {
			Texture tmpImg;
			tmpImg.loadFromFile(fileName + to_string(i) + ".png");
			listTexture.push_back(tmpImg);
		}
		this->deltaTime = deltaTime;
	}
	void Update() {
		currentFrame += deltaTime;
		if (currentFrame > listTexture.size() - 1) {
			currentFrame = 0;
		}
	}

	void setTexture(Sprite& s) {
		s.setTexture(listTexture[currentFrame]);
		s.setTextureRect(IntRect(0, 0, listTexture[currentFrame].getSize().x, listTexture[currentFrame].getSize().y));
		s.setOrigin((Vector2<float>)listTexture[currentFrame].getSize() * 0.5f);
	}

private:
	vector<Texture> listTexture;
	float deltaTime;
	float currentFrame = 0;
};

