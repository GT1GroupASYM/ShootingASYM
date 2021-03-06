/////////////////////////////////////////////////////
// Name : Player
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../Character.h"

class PlayerState;
class Weapon;
class PlayerNormalState;
class Bullet;
class Item;

/////////////////////////////////////////////////////
// Name : Player
//
// Over View : プレイヤークラス
/////////////////////////////////////////////////////
class Player :public Character
{
private:
	std::shared_ptr<PlayerState> state_;
	std::shared_ptr<Weapon> weapon_;

	friend PlayerNormalState;

public:
	//コンストラクタ
	Player(wchar_t* texturePass,RECT rect);

	//デストラクタ
	~Player();

	//初期化処理
	void Initialize() override;

	//更新処理
	void Update() override;

	//描画処理
	void Render() override;

	//当たった時の処理
	void Hit(Bullet* bullet);
	void Hit(Item* item);

	//武器レベルの上昇
	void LevelUp();

	//武器の変更
	void ChangeWeapon(std::shared_ptr<Weapon> newWeapon);
};

