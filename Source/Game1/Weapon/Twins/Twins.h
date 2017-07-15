/////////////////////////////////////////////////////
// Name : Twins
//
// Author : 山田 聖弥
//
// Day : 2017/7/16
/////////////////////////////////////////////////////
#pragma once

#include "../Weapon.h"

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

