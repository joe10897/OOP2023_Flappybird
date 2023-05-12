#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "birdobj.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
namespace game_framework
{
	void Bird::Bird_main()
	{
		birdd.LoadBitmapByString({ "Resources/bird.bmp" }, RGB(255, 255, 255));
	}
	//void OnMove() 
	//{


	//}
	void Bird::OnShow()
	{
		birdd.ShowBitmap();
		birdd.SetTopLeft(600, 300);
	}
}
