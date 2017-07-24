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