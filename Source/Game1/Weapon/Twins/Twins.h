/////////////////////////////////////////////////////
// Name : Twins
//
// Author : 山田 聖弥
//
// Day : 2017/7/25
/////////////////////////////////////////////////////
#pragma once

#include <Mouse.h>

#include "../Weapon.h"

namespace Math = DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : Twins
//
// Over View : 前後撃ちクラス
/////////////////////////////////////////////////////
class Twins:public Weapon
{
private:
	//弾の打つ速さ
	float waitTime_;

	//経過時間
	float currentTime_;

	//攻撃の向き
	int dir_;

	//球の大きさの上昇値
	const float bulletIncreaseValue_ = 0.25f;

	//球を打つ
	void BulletFire(DirectX::Mouse* mouse,Character& caracter);

public:
	//コンストラクタ
	Twins();

	//デストラクタ
	~Twins();

	//初期化処理
	void Initialize() override;

	//更新処理
	void Update(Character& character) override;

	//描画処理
	void Render() override;
};

