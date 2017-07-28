/////////////////////////////////////////////////////
// Name : TwinsItem
//
// Author : 山田 聖弥
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#include "TwinsItem.h"
#include "../../../GameBase/Sprite/Sprite.h"
#include "../../Weapon/Twins/Twins.h"
#include "../../Character/Player/Player.h"
#include "../../CollisionManager/CollisionManager.h"

/////////////////////////////////////////////////////
// Name : TwinsItem
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
TwinsItem::TwinsItem()
	:Item()
{
	sprite_.reset(new Sprite(L"Resources\\Images\\TwinsItem.png", RECT{ 0,0,32,32 }));
	sprite_->Origine(Math::Vector2(16, 16));
}

/////////////////////////////////////////////////////
// Name : ~MachineGunItem
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
TwinsItem::~TwinsItem()
{
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : 更新処理
//
// Argument : 無し
//
// Return : 何かに当たったらfalse
/////////////////////////////////////////////////////
bool TwinsItem::Update()
{
	if (hit_)
		return false;

	CollisionManager::GetInstance()->Entry(this);

	return true;
}

/////////////////////////////////////////////////////
// Name : Used
//
// Over View : アイテムを使う
//
// Argument : プレイヤーへの参照
//
// Return : 無し
/////////////////////////////////////////////////////
void TwinsItem::Used(Player & player)
{
	std::shared_ptr<Twins> twins;
	twins.reset(new Twins);
	player.ChangeWeapon(twins);
}