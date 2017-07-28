/////////////////////////////////////////////////////
// Name : Player
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "../../../../pch.h"
#include "Player.h"
#include "PlayerState\PlayerState.h"
#include "PlayerState\PlayerNormalState\PlayerNormalState.h"
#include "../../Weapon/MachineGun/MachineGun.h"
#include "../../Weapon/Twins/Twins.h"
#include "../../CollisionManager/CollisionManager.h"
#include "../../Bullet/Bullet.h"
#include "../../Item/Item.h"
#include "../../../GameBase/Utility/UtilityFunction/UtilityFunction.h"

/////////////////////////////////////////////////////
// Name : Player
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Player::Player(wchar_t* texturePass,RECT rect)
	:Character(texturePass,rect)
{
	state_.reset(new PlayerNormalState);
	weapon_.reset(new MachineGun);
}

/////////////////////////////////////////////////////
// Name : ~Player
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Player::~Player()
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
void Player::Initialize()
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
void Player::Update()
{
	auto next = state_->Input(*this);
	if (next)
	{
		state_ = next;
	}

	state_->Update(*this);

	Character::Update();

	CollisionManager::GetInstance()->Entry(this);
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
void Player::Render()
{
	Character::Render();
}

/////////////////////////////////////////////////////
// Name : Hit
//
// Over View : 当たった時の処理
//
// Argument : Bulletのポインタ
//
// Return : 無し
/////////////////////////////////////////////////////
void Player::Hit(Bullet * bullet)
{
	auto power = bullet->Power();

	hp_ -= power;

	hp_ = Clamp(hp_, 0, maxHp_);
}

/////////////////////////////////////////////////////
// Name : Hit
//
// Over View : 当たった時の処理
//
// Argument : Itemのポインタ
//
// Return : 無し
/////////////////////////////////////////////////////
void Player::Hit(Item * item)
{
	item->Used(*this);
}

/////////////////////////////////////////////////////
// Name : LevelUp
//
// Over View : 武器レベルの上昇
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void Player::LevelUp()
{
	weapon_->LevelUp();
}

/////////////////////////////////////////////////////
// Name : ChangeWeapon
//
// Over View : 武器の変更
//
// Argument : 新しい武器
//
// Return : 無し
/////////////////////////////////////////////////////
void Player::ChangeWeapon(std::shared_ptr<Weapon> newWeapon)
{
	if (weapon_->ID() == newWeapon->ID()) return;

	weapon_ = newWeapon;
}