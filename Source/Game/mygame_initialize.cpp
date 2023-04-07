#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "config.h"

using namespace game_framework;
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0, "Start flying...");	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	//Sleep(1000);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
	//Load background image
	//background.LoadBitmapByString({"C:/OOP2023_flappybird/OOP2023_Flappybird/Bitmaps/InitBackground.bmp"});
	//background.SetTopLeft(0, 0);
	background.LoadBitmapByString({ "Resources/background.bmp" });
	title.LoadBitmapByString({ "Resources/Title.bmp" }, RGB(255, 255, 255));
	clickedPlayButton.LoadBitmapByString({ "Resources/PlayButton.bmp" }, RGB(255, 255, 255));
	settingButton.LoadBitmapByString({ "Resources/setting.bmp" }, RGB(255, 255, 255));

}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnMove()							// 移動遊戲元素
{
	//鍵盤觸法
	if (SpaceKey == true)
	{
		GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
	}
}

void CGameStateInit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

	if (nChar == 0x20)
	{
		SpaceKey = true;
	}

}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

	if (nChar == 0x20)
	{
		SpaceKey = false;
	}

}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{	
	if (nFlags = true) {
		GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
	}
}

void CGameStateInit::OnShow()
{
	//show background
	background.ShowBitmap();
	background.SetTopLeft(0, 0);

	title.ShowBitmap();
	title.SetTopLeft(370, 70);

	clickedPlayButton.ShowBitmap();
	clickedPlayButton.SetTopLeft(400, 240);

	settingButton.ShowBitmap();
	settingButton.SetTopLeft(850, 10);
}

void CGameStateInit::load_background()
{
	background.LoadBitmapByString({ "Resources/background.bmp" });
	background.SetTopLeft(0, 0);
}
