/////////////////////////////////////////////////////
// Name : MachineGun
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "../../../../pch.h"
#include "MachineGun.h"
#include "../../../GameBase/ImputManager/InputManager.h"
#include "../../BulletManager/BulletManager.h"
#include "../../Bullet/Bullet.h"
#include "../../Character/Character.h"

using namespace DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : CalcPower
//
// Over View : レベルから攻撃力を算出
//
// Argument : 無し
//
// Return : 攻撃力
/////////////////////////////////////////////////////
int MachineGun::CalcPower()
{
	auto power = 0;

	//20 -> 25 -> 50
	for (auto i = 0; i < 5; i++)
	{
		auto num = 100 % (5 - (level_ - 1) - i);
		if (num == 0)
		{
			power = 100 / (5 - (level_ - 1) - i);
			break;
		}
	}

	return power;
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

	auto mouse = InputManager::GetInstance()->Mouse();
	if (mouse->GetState().leftButton)
	{
		auto x = mouse->GetState().x;
		auto y = mouse->GetState().y;
		auto pos = character.Pos();
		auto vel = Vector2(x, y) - pos;
		auto power = CalcPower();

		for (auto i = 0; i < level_; i++)
		{
			//弾の生成
			std::shared_ptr<Bullet> bullet;
			bullet.reset(new Bullet);
			bullet->Initialize(pos, vel, power_);
			BulletManager::GetInstance()->Add(bullet);

			if (i == 0) continue;
		}
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