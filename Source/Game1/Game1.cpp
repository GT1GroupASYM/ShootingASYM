/////////////////////////////////////////////////////
// Name : Game1
//
// Author : 山田 聖弥
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#include "Game1.h"
#include "Scene\Scene\Scene.h"
#include "Scene\PlayScene\PlayScene.h"
#include "../GameBase/Sprite/SpriteManager/SpriteManager.h"
#include "../GameBase/ImputManager/InputManager.h"
#include "CollisionManager\CollisionManager.h"

/////////////////////////////////////////////////////
// Name : Game1
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Game1::Game1()
{
	scene_.reset(new PlayScene);
}

/////////////////////////////////////////////////////
// Name : ~Game1
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Game1::~Game1()
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
void Game1::Initialize()
{
	GameMain::Initialize();

	scene_->Initialize();
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : 更新処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void Game1::Update()
{
	GameMain::Update();

	//シーン切り替え
	auto next = scene_->Input();
	if (next)
	{
		scene_ = next;
		scene_->Initialize();
	}

	//シーンの更新
	scene_->Update();

	CollisionManager::GetInstance()->Update();
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
void Game1::Render()
{
	GameMain::Render();

	auto spriteBatch = SpriteManager::GetInstance()->SpriteBatch();
	auto commonState = SpriteManager::GetInstance()->CommonState();
	spriteBatch->Begin(DirectX::SpriteSortMode_Deferred,commonState->NonPremultiplied(),commonState->PointClamp());

	scene_->Render();

	spriteBatch->End();
}
