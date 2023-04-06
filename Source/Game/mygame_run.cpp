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
	
	if (cnt >= 5)  //Pipe 自動移動
	{
		cnt = 0;
		pipe[shot].SetTopLeft(pipe[shot].GetLeft() - 5, pipe[shot].GetTop());
		pipe[shot].ShowBitmap();
		shot++;
		pipe[shot].SetTopLeft(pipe[shot].GetLeft() - 10, pipe[shot].GetTop());
		pipe[shot].ShowBitmap();
		shot++;
		if (shot > 1000)
		{
			shot = 0;
		}
	}
	

	//for (int i = 10; i == 300; i += 10)
	//{
	//	if (10 < pipe.GetTop()) {
	//		pipe.SetTopLeft(pipe.GetLeft(), pipe.GetTop() + 10);
	//	}
	//}

	if (DownKey == true)  //向上
	{
		if (bird.GetTop() < 400)
		{
			bird.SetTopLeft(bird.GetLeft(),bird.GetTop() +4);
		}
	}
	if (UpKey == true)  //向下
	{
		if (10 < bird.GetTop())
		{
			bird.SetTopLeft(bird.GetLeft(), bird.GetTop() -4);
		}
	}

	//loading pipe
	//pipe.ToggleAnimation();
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	//loading background
	background.LoadBitmapByString({"Resources/background.bmp"});
	background.SetTopLeft(0, 0);

	//loading game title
	title.LoadBitmapByString({ "Resources/Title.bmp"}, RGB(255, 255, 255));
	title.SetTopLeft(50, 50);

	//loading play button
	clickedPlayButton.LoadBitmapByString({"Resources/PlayButton.bmp"}, RGB(255, 255, 255));
	clickedPlayButton.SetTopLeft(420, 280);

	//loading bird
	bird.LoadBitmapByString({ "Resources/bird.bmp" }, RGB(255, 255, 255));
	bird.SetTopLeft(500, 300);

	//loading pipe
	cnt = 5;
	shot = 0;
	for (int i = 0; i < 1000; i++)
	{
		pipe[i].LoadBitmapByString({ "Resources/pipe.bmp" }, RGB(255, 255, 255));
		pipe[i].SetTopLeft(900, 300);
		//pipe.SetAnimation(1000, true);
	}
	
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
	title.ShowBitmap();

	//clickedPlayButton.ShowBitmap();
	bird.ShowBitmap();

	//show pipe
	for (int i = 0; i < 1000; i++)
	{
		if (pipe[i].IsBitmapLoaded() == true)
		{
			pipe[i].SetTopLeft(pipe[i].GetLeft() -5, pipe[i].GetTop());
			pipe[i].ShowBitmap();
			//character.ShowBitmap();
			//pipe.ShowBitmap();
		}
	}
}

void CGameStateRun::show_text(){
	CDC *pDC = CDDraw::GetBackCDC();
	CTextDraw::Print(pDC, 300, 600, "Some text here.");
}
