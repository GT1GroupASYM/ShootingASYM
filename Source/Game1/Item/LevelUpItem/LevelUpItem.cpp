/////////////////////////////////////////////////////
// Name : LevelUpItem
//
// Author : 山田 聖弥
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#include "LevelUpItem.h"
#include "../../../GameBase/Sprite/Sprite.h"
#include "../../Character/Player/Player.h"
#include "../../CollisionManager/CollisionManager.h"

/////////////////////////////////////////////////////
// Name : LevelUpItem
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
LevelUpItem::LevelUpItem()
	:Item()
{
	sprite_.reset(new Sprite(L"Resources\\Images\\LevelUpItem.png", RECT{ 0,0,32,32 }));
	sprite_->Origine(Math::Vector2(16, 16));
}

/////////////////////////////////////////////////////
// Name : ~LevelUpItem
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
LevelUpItem::~LevelUpItem()
{
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
bool LevelUpItem::Update()
{
	if (hit_)
		return false;

	CollisionManager::GetInstance()->Entry(this);

	return true;
}

/////////////////////////////////////////////////////
// Name : Used
//
// Over View : アイテムを使用する
//
// Argument : プレイヤーへの参照
//
// Return : 無し
/////////////////////////////////////////////////////
void LevelUpItem::Used(Player & player)
{
	player.LevelUp();
}
