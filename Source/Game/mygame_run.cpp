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
	//鍵盤觸法
	
	if (cnt >= 5)  //Pipe 自動移動
	{
		cnt = 0;
		pipe_down[shot].SetTopLeft(pipe_down[shot].GetLeft() - 5, pipe_down[shot].GetTop());
		pipe_down[shot].ShowBitmap();

		pipe_top[shot].SetTopLeft(pipe_top[shot].GetLeft() - 5, pipe_top[shot].GetTop());
		pipe_top[shot].ShowBitmap();
		shot++;

		pipe_down[shot].SetTopLeft(pipe_down[shot].GetLeft() - 10, pipe_down[shot].GetTop());
		pipe_down[shot].ShowBitmap();

		pipe_top[shot].SetTopLeft(pipe_top[shot].GetLeft() - 10, pipe_top[shot].GetTop());
		pipe_top[shot].ShowBitmap();
		shot++;

		if (shot > 1000)
		{
			shot = 0;
		}
	}
	cnt++;
	

	//for (int i = 10; i == 300; i += 10)
	//{
	//	if (10 < pipe_down.GetTop()) {
	//		pipe_down.SetTopLeft(pipe_down.GetLeft(), pipe_down.GetTop() + 10);
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
	bird.LoadBitmapByString({ "Resources/bird.bmp" }, RGB(255, 255, 255));
	bird.SetTopLeft(500, 300);

	//loading pipe_down
	cnt = 5;
	shot = 0;


	int Random_Down[5] = { 300, 350, 400, 450, 500 };
	int number_Down = rand() % (500-300+1)+300;
	for (int i = 0; i < 1000; i++)
	{
		pipe_down[i].LoadBitmapByString({ "Resources/pipe_down.bmp" }, RGB(255, 255, 255));
		pipe_down[i].SetTopLeft(1000, 400);

		pipe_top[i].LoadBitmapByString({ "Resources/pipe_top.bmp" }, RGB(255, 255, 255));
		pipe_top[i].SetTopLeft(1000, -200);
		//pipe_down.SetAnimation(1000, true);
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

	//show title
	//title.ShowBitmap();

	//clickedPlayButton.ShowBitmap();
	bird.ShowBitmap();

	//show pipe_down
	for (int i = 0; i < 1000; i++)
	{
		if (pipe_down[i].IsBitmapLoaded() == true)
		{
			pipe_down[i].SetTopLeft(pipe_down[i].GetLeft() -5, pipe_down[i].GetTop());
			pipe_down[i].ShowBitmap();

			pipe_top[i].SetTopLeft(pipe_top[i].GetLeft() - 5, pipe_top[i].GetTop());
			pipe_top[i].ShowBitmap();
			//character.ShowBitmap();
			//pipe_down.ShowBitmap();
		}
	}
}

void CGameStateRun::show_text(){
	CDC *pDC = CDDraw::GetBackCDC();
	CTextDraw::Print(pDC, 300, 600, "Some text here.");
}
