/////////////////////////////////////////////////////
// Name : MachineGun
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include <Mouse.h>

#include "../Weapon.h"


/////////////////////////////////////////////////////
// Name : MachineGun
//
// Over View : マシンガンクラス
/////////////////////////////////////////////////////
class MachineGun :public Weapon
{
private:
	//弾の打つ速さ
	float waitTime_;

	//経過時間
	float currentTime_;

	//レベルから攻撃力を算出
	int CalcPower();

	//球を撃つ
	void BulletFire(DirectX::Mouse* mouse, Character& character);
	
	//球を打つ
	void Fire(Math::Vector2 pos,Math::Vector2 vel, int dir,int bulletCount);

public:
	//コンストラクタ
	MachineGun();

	//デストラクタ
	~MachineGun();

	//初期化処理
	void Initialize() override;
	
	//更新処理
	void Update(Character& character) override;
	
	//描画処理
	void Render() override;
};

