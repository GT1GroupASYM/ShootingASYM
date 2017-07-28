/////////////////////////////////////////////////////
// Name : MachineGunItem
//
// Author : 山田 聖弥
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#include "MachineGunItem.h"
#include "../../../GameBase/Sprite/Sprite.h"
#include "../../Weapon/MachineGun/MachineGun.h"
#include "../../Character/Player/Player.h"
#include "../../CollisionManager/CollisionManager.h"

/////////////////////////////////////////////////////
// Name : MachineGunItem
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
MachineGunItem::MachineGunItem()
	:Item()
{
	sprite_.reset(new Sprite(L"Resources\\Images\\MachineGunItem.png", RECT{ 0,0,32,32 }));
	sprite_->Origine(Math::Vector2(16, 16));
}

/////////////////////////////////////////////////////
// Name : ~MachineGunItem
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
MachineGunItem::~MachineGunItem()
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
bool MachineGunItem::Update()
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
void MachineGunItem::Used(Player & player)
{
	std::shared_ptr<MachineGun> machineGun;
	machineGun.reset(new MachineGun);
	player.ChangeWeapon(machineGun);
}