#pragma once
#pragma once

#include <cmath>
#include "mygame.h"
#include "config.h"
#include "../Library/gameutil.h"
#include "../Library/audio.h"
#include "../Library/gameutil.h"

using namespace game_framework;

class Object {
public:
	int getWidth();
	int getHeight();
	int getX();
	int getY();

	bool collision(const Object& obj) const;

	virtual void init();
	virtual void update();
	virtual void destroy();
	virtual void render();

	Object();
	virtual ~Object();

protected:
	float x, y;
	float velX, velY;
	float aX, aY;
	int width, height;
	int rotDegree;
	float scaleFactorX;
	float scaleFactorY;
	float objectTimer;

	CMovingBitmap* bitmap;

	int ID;

};