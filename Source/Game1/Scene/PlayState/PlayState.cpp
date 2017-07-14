/////////////////////////////////////////////////////
// Name : PlayState
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "../../../../pch.h"
#include "PlayState.h"

/////////////////////////////////////////////////////
// Name : PlayState
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
PlayState::PlayState()
	:SceneState()
{
}

/////////////////////////////////////////////////////
// Name : ~PlayState
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
PlayState::~PlayState()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void PlayState::Initialize()
{
}

/////////////////////////////////////////////////////
// Name : input
//
// Over View : シーン切り替え
//
// Argument : 無し
//
// Return : 次のシーン
/////////////////////////////////////////////////////
std::shared_ptr<SceneState> PlayState::Input()
{
	std::shared_ptr<SceneState> next = nullptr;

	return next;
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : 描画処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void PlayState::Update()
{
}

/////////////////////////////////////////////////////
// Name : Render
//
// Over View : 描画処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void PlayState::Render()
{
}
