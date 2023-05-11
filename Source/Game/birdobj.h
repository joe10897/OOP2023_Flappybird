#pragma once
//#ifndef BIRD_H
//#define BIRD_H
#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <memory>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "config.h"

namespace game_framework
{
	class Bird
	{
	public:
		void Bird_main();
		void OnShow();
		//void OnKeyDown(UINT, UINT, UINT);
		//void OnKeyUp(UINT, UINT, UINT);
		//void OnLButtonDown(UINT nFlags, CPoint point); 
		//void OnLButtonUp(UINT nFlags, CPoint point);	
		//void OnMouseMove(UINT nFlags, CPoint point);	
		//void OnRButtonDown(UINT nFlags, CPoint point);  
		//void OnRButtonUp(UINT nFlags, CPoint point);
	private:
		//void OnMove();
		CMovingBitmap birdd;
		bool onClick;
	};
}
//#endif