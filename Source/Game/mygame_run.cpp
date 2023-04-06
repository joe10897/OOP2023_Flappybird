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
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
	//button stage
	playBtnClicked = finishLoaded = onHelp = helpBtnClicked = onAbout = onHowToPlay = onCheatPage = false;
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	//鍵盤觸法
	if (SpaceKey == true)
	{
		if (clickedPlayButton.GetLeft() < 1000)
		{
			clickedPlayButton.SetTopLeft(clickedPlayButton.GetLeft() + 10, clickedPlayButton.GetTop());
		}
	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	//loading background
	background.LoadBitmapByString({ "C:/OOP2023_flappybird/OOP2023_Flappybird/Resources/background.bmp" });
	title.LoadBitmapByString({ "C:/OOP2023_flappybird/OOP2023_Flappybird/Resources/Title.bmp" }, RGB(255, 255, 255));
	clickedPlayButton.LoadBitmapByString({ "C:/OOP2023_flappybird/OOP2023_Flappybird/Resources/PlayButton.bmp" }, RGB(255, 255, 255));
	bird.LoadBitmapByString({ "C:/OOP2023_flappybird/OOP2023_Flappybird/Resources/bird.bmp" }, RGB(255, 255, 255));
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_LEFT)
	{
		LeftKey = true;
	}
	if (nChar == VK_RIGHT)
	{
		RightKey = true;
	}
	if (nChar == VK_UP)
	{
		UpKey = true;
	}
	if (nChar == VK_DOWN)
	{
		DownKey = true;
	}
	if (nChar == 0x20)
	{
		SpaceKey = true;
	}
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_LEFT)
	{
		LeftKey = false;
	}
	if (nChar == VK_RIGHT)
	{
		RightKey = false;
	}
	if (nChar == VK_UP)
	{
		UpKey = false;
	}
	if (nChar == VK_DOWN)
	{
		DownKey = false;
	}
	if (nChar == 0x20)
	{
		SpaceKey = false;
	}
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	//play button
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	//show background
	background.ShowBitmap();
	background.SetTopLeft(0, 0);

	bird.ShowBitmap();
	bird.SetTopLeft(420, 280);
	//title.ShowBitmap();
	//title.SetTopLeft(50, 50);

	//clickedPlayButton.ShowBitmap();
	//clickedPlayButton.SetTopLeft(420, 280);
}

void CGameStateRun::show_text(){
	CDC *pDC = CDDraw::GetBackCDC();
	//CFont* fp;
	//CTextDraw::ChangeFontLog(pDC, fp, 21, "�L�n������", RGB(0, 0, 0), 800);
	CTextDraw::Print(pDC, 237, 128, "HIIIIIIIIIIIII");
}
