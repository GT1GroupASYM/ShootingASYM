/////////////////////////////////////////////////////
// Name : MachineGun
//
// Author : 山田 聖弥
//
// Day : 2017/7/25
/////////////////////////////////////////////////////
#include "../../../../pch.h"
#include "MachineGun.h"
#include "../../../GameBase/ImputManager/InputManager.h"
#include "../../BulletManager/BulletManager.h"
#include "../../Bullet/Bullet.h"
#include "../../Bullet/PlayerBullet/PlayerBullet.h"
#include "../../Character/Character.h"

using namespace Math;

Weapon::WEAPONID MachineGun::id_ = MachineGun::MACHINEGUN;

/////////////////////////////////////////////////////
// Name : BulletFire
//
// Over View : 球を撃つ
//
// Argument : マウス、キャラクターへの参照
//
// Return : 無し
/////////////////////////////////////////////////////
void MachineGun::BulletFire(DirectX::Mouse * mouse, Character & character)
{
	auto x = mouse->GetState().x;
	auto y = mouse->GetState().y;
	auto pos = character.Pos();
	auto vel = Vector2((float)x, (float)y) - pos;
	auto power = powerTable_[level_];

	for (auto i = 0; i < level_ + 1; i++)
	{
		Fire(pos, vel, 1, i);

		if (i == 0) continue;

		Fire(pos, vel, -1, i);
	}
}

/////////////////////////////////////////////////////
// Name : Fire
//
// Over View : 球を撃つ(実際に呼び出すのはBulletFireの中)
//
// Argument : 座標、速度、広がる角度の向き、何発目か
//
// Return : 無し
/////////////////////////////////////////////////////
void MachineGun::Fire(Vector2 pos,Vector2 vel, int dir,int bulletCount)
{
	auto angle = atan2f(vel.y, vel.x);
	angle += (bulletCount * 5) * 3.14f / 180 * dir;
	Matrix rot = Matrix::CreateRotationZ(angle);
	vel = Vector2::TransformNormal(Vector2(1.0f, 0.0f), rot);

	//弾の生成
	std::shared_ptr<Bullet> bullet;
	bullet.reset(new PlayerBullet);
	bullet->Initialize(pos, vel, power_);
	BulletManager::GetInstance()->Add(bullet);
}

/////////////////////////////////////////////////////
// Name : MachineGun
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
MachineGun::MachineGun()
	:Weapon(20),waitTime_(0.1f)
	, currentTime_(0.0f)
{
}

/////////////////////////////////////////////////////
// Name : ~MachineGun
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
MachineGun::~MachineGun()
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
void MachineGun::Initialize()
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
void MachineGun::Update(Character& character)
{
	if (currentTime_ < waitTime_)
	{
		currentTime_ += 1.0f / 60;
		return;
	}

	if (InputManager::GetInstance()->KeyInputDown(DirectX::Keyboard::T))
		LevelUp();
	if (InputManager::GetInstance()->KeyInputDown(DirectX::Keyboard::R))
		level_--;

	auto mouse = InputManager::GetInstance()->Mouse();
	if (mouse->GetState().leftButton)
	{
		//球を撃つ
		BulletFire(mouse, character);

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
void MachineGun::Render()
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
Weapon::WEAPONID MachineGun::ID()
{
	return id_;
}
