/////////////////////////////////////////////////////
// Name : Twins
//
// Author : 山田 聖弥
//
// Day : 2017/7/25
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>

#include "../../../../pch.h"
#include "Twins.h"
#include "../../../GameBase/ImputManager/InputManager.h"
#include "../../Bullet/Bullet.h"
#include "../../Bullet/PlayerBullet/PlayerBullet.h"
#include "../../BulletManager/BulletManager.h"
#include "../../Character/Character.h"

using namespace DirectX::SimpleMath;

Weapon::WEAPONID Twins::id_ = Twins::TWINS;

/////////////////////////////////////////////////////
// Name : BulletFire
//
// Over View : 球を撃つ
//
// Argument : マウス、キャラクターへの参照
//
// Return : 無し
/////////////////////////////////////////////////////
void Twins::BulletFire(DirectX::Mouse * mouse,Character& character)
{
	auto x = (float)mouse->GetState().x;
	auto y = (float)mouse->GetState().y;
	auto pos = character.Pos();
	auto vel = Vector2(x, y) - pos;

	//弾の生成
	std::shared_ptr<Bullet> bullet;
	bullet.reset(new PlayerBullet);
	auto power = powerTable_[level_];
	bullet->Initialize(pos, vel * dir_, power);
	bullet->Scale(1 + (level_ - 1) * bulletIncreaseValue_);
	BulletManager::GetInstance()->Add(bullet);

	//攻撃の向きの変更
	dir_ *= -1;
}


/////////////////////////////////////////////////////
// Name : Twins
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Twins::Twins()
	:Weapon(20),waitTime_(0.3f)
	,currentTime_(0.0f),dir_(1)
{
}

/////////////////////////////////////////////////////
// Name : ~Twins
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Twins::~Twins()
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
void Twins::Initialize()
{
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : 更新処理
//
// Argument : キャラクターへの参照
//
// Return : 無し
/////////////////////////////////////////////////////
void Twins::Update(Character & character)
{
	if (currentTime_ < waitTime_)
	{
		currentTime_ += 1.0f / 60;
		return;
	}

	auto mouse = InputManager::GetInstance()->Mouse();
	if (mouse->GetState().leftButton)
	{
		//球を撃つ
		BulletFire(mouse,character);

		//マシンガンの待機時間の初期化
		currentTime_ = 0.0f;
	}
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
void Twins::Render()
{
}

/////////////////////////////////////////////////////
// Name : ID
//
// Over View : 武器IDの取得
//
// Argument : 無し
//
// Return : 武器ID
/////////////////////////////////////////////////////
Weapon::WEAPONID Twins::ID()
{
	return id_;
}
