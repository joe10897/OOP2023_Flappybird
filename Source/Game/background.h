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

namespace game_framework{

	class BackGround {
	public:
		BackGround();
		~BackGround();
		void update(float dt);
		void draw(float x, float y);

	private:
		// 圖片背景
		CMovingBitmap background;
		
		// 陸地圖片
		CMovingBitmap ground;
		bool IsAnimation;

		// 陸地圖片水平寬度
		float groundMaxLandWidth;
		float groundStartXaxis;

	}
};