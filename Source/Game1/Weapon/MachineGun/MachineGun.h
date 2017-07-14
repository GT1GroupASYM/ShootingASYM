/////////////////////////////////////////////////////
// Name : MachineGun
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../Weapon.h"

/////////////////////////////////////////////////////
// Name : MachineGun
//
// Over View : マシンガンクラス
/////////////////////////////////////////////////////
class MachineGun :public Weapon
{
private:
	float waitTime_;

	float currentTime_;

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

