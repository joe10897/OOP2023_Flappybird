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
		// �Ϥ��I��
		CMovingBitmap background;
		
		// ���a�Ϥ�
		CMovingBitmap ground;
		bool IsAnimation;

		// ���a�Ϥ������e��
		float groundMaxLandWidth;
		float groundStartXaxis;

	}
};