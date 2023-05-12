#pragma once
#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "config.h"

// Pipe between gap
const float PIPE_BETWEEN_GAP = 110.0f;

// Pipe between distance 
const float PIPE_BETWEEN_DISTANCE = 180.0f;

// Pipe min height
const float PIPE_MIN_HEIGHT = 50.0f;

namespace game_framework {
	class Pipe {
		Pipe( background);
		~Pipe();

	public:
		void randomGen(float x);
		void update(float dt);
		void OnDraw();
		void setX(float x);
		float getX();
		float getPipeWidth();

	private:
		float pipeX;
		float gapY;

	};
}