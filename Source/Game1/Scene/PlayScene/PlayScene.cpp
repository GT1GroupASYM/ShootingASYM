/////////////////////////////////////////////////////
// Name : PlayScene
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "PlayScene.h"
#include "../../Character/Player/Player.h"
#include "../../BulletManager/BulletManager.h"
#include "../../Item/LevelUpItem/LevelUpItem.h"
#include "../../Item/MachineGunItem/MachineGunItem.h"
#include "../../Item/TwinsItem/TwinsItem.h"
#include "../../ItemManager/ItemManager.h"

/////////////////////////////////////////////////////
// Name : PlayScene
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
PlayScene::PlayScene()
	:Scene()
{
	RECT rect{ 0,0,32,32 };
	player_.reset(new Player(L"Resources\\Images\\Ball.png",rect));
}

/////////////////////////////////////////////////////
// Name : ~PlayScene
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
PlayScene::~PlayScene()
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
void PlayScene::Initialize()
{
	player_->Initialize();

	ItemManager::GetInstance()->Initialize();
	BulletManager::GetInstance()->Initialize();

	std::shared_ptr<Item> item;
	item.reset(new LevelUpItem);
	item->Pos(Math::Vector2(100, 100));
	ItemManager::GetInstance()->Add(item);

	item.reset(new MachineGunItem);
	item->Pos(Math::Vector2(200, 100));
	ItemManager::GetInstance()->Add(item);

	item.reset(new TwinsItem);
	item->Pos(Math::Vector2(200, 200));
	ItemManager::GetInstance()->Add(item);
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
std::shared_ptr<Scene> PlayScene::Input()
{
	std::shared_ptr<Scene> next = nullptr;

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
void PlayScene::Update()
{
	player_->Update();


	ItemManager::GetInstance()->Update();
	BulletManager::GetInstance()->Update();
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
void PlayScene::Render()
{
	player_->Render();

	ItemManager::GetInstance()->Render();
	BulletManager::GetInstance()->Render();
}
