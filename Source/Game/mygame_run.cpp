#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "config.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
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
	//PIPE **

	if (DownKey == true)  //向上
	{
		if (bird.GetTop() < 400)
		{
			bird.SetTopLeft(bird.GetLeft(),bird.GetTop() + 4);
		}
	}
	if (UpKey == true)  //向下
	{
		if (10 < bird.GetTop())
		{
			bird.SetTopLeft(bird.GetLeft(), bird.GetTop() - 4);
		}
	}

	//loading pipe_down
	//pipe_down.ToggleAnimation();
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
	bird.LoadBitmapByString({ "Resources/balloon.bmp" }, RGB(0, 0, 0));
	bird.SetTopLeft(500, 300);

	//loading pipe
	for (int i = 0; i < 1000; i++) { //Y軸平移
		pipe_top[i].LoadBitmapByString({ "Resources/pipe_top.bmp" }, RGB(255, 255, 255));
		pipe_down[i].LoadBitmapByString({ "Resources/pipe_down.bmp" }, RGB(255, 255, 255));
		pipe_top[i].SetTopLeft(900, -150);
		pipe_down[i].SetTopLeft(1000, 300);
	}
	 //loading ground
	ground.LoadBitmapByString({ "Resources/ground.bmp" }, RGB(255, 255, 255));
	ground.ShowBitmap();
	//_imgStartX += 1;
	//if (_imgStartX >= 40)
		//_imgStartX = 0.0;

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

	//show title
	//title.ShowBitmap();

	//clickedPlayButton.ShowBitmap();
	bird.ShowBitmap();

	//show pipe_down
	for (int i = 0; i < 1000; i++) { //Y軸平移
		pipe_down[i].ShowBitmap();
		pipe_top[i].ShowBitmap();
		pipe_down[i].SetTopLeft(pipe_down[i].GetLeft() - 20, pipe_down[i].GetTop());
		pipe_top[i].SetTopLeft(pipe_top[i].GetLeft() - 20, pipe_top[i].GetTop());
		
	}

	ground.ShowBitmap();
	ground.SetTopLeft(0, 500);

}

void CGameStateRun::show_text(){
	CDC *pDC = CDDraw::GetBackCDC();
	CTextDraw::Print(pDC, 300, 600, "Some text here.");
}
