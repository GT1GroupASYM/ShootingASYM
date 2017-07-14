/////////////////////////////////////////////////////
// Name : PlayerState
//
// Author : 山田 聖弥
//
// Day : 2017/7/12
/////////////////////////////////////////////////////
#pragma once

#include <memory>

class Player;

/////////////////////////////////////////////////////
// Name : PlayerState
//
// Over View : プレイヤーの状態管理の基底クラス
/////////////////////////////////////////////////////
class PlayerState
{
private:

	//コンストラクタ
	PlayerState() {}
public:
	//デストラクタ
	virtual ~PlayerState() {}

	//状態の変更
	virtual std::shared_ptr<PlayerState> Input(Player& player);
	
	//更新処理
	virtual void Update(Player& player);
};