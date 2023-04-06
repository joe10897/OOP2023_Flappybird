#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	//loading background
	background.LoadBitmapByString({"C:/OOP2023_flappybird/OOP2023_Flappybird/Resources/background.bmp"});
	background.SetTopLeft(20, 20);

	//loading game title
	title.LoadBitmapByString({ "C:/OOP2023_flappybird/OOP2023_Flappybird/Resources/Title.bmp"}, RGB(255, 255, 255));
	title.SetTopLeft(50, 50);

	//loading play button
	clickedPlayButton.LoadBitmapByString({"C:/OOP2023_flappybird/OOP2023_Flappybird/Resources/PlayButton.bmp"}, RGB(255, 255, 255));
	clickedPlayButton.SetTopLeft(420, 280);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
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
	clickedPlayButton.ShowBitmap();
}
