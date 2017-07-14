/////////////////////////////////////////////////////
// Name : PlayerNormalState
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../PlayerState.h"

/////////////////////////////////////////////////////
// Name : PlayerNormalState
//
// Over View : 通常状態
/////////////////////////////////////////////////////
class PlayerNormalState:public PlayerState
{
public:
	//コンストラクタ
	PlayerNormalState();

	//デストラクタ
	~PlayerNormalState();

	//状態の切り替え
	std::shared_ptr<PlayerState> Input(Player& player) override;
	
	//更新処理
	void Update(Player& player) override;
};