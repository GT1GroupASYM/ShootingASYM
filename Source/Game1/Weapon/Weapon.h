/////////////////////////////////////////////////////
// Name : Weapon
//
// Author : 山田 聖弥
//
// Day : 2017/7/25
/////////////////////////////////////////////////////
#pragma once

class Character;

/////////////////////////////////////////////////////
// Name : Bullet
//
// Over View : 弾の基底クラス
/////////////////////////////////////////////////////
class Weapon
{
protected:

	enum WEAPONID
	{
		NONE,
		MACHINEGUN,
		TWINS
	};

	//武器レベル
	int level_;

	//武器レベルの上限
	 static const int maxLevel_ = 3;

	 //攻撃力のテーブル
	 int powerTable_[maxLevel_] =
	 {
		 20,25,50
	 };


	 //攻撃力
	 int power_;

	//コンストラクタ
	Weapon(int power);
public:

	//デストラクタ
	~Weapon();

	//初期化処理
	virtual void Initialize();
	
	//更新処理
	virtual void Update(Character& character);
	
	//描画処理
	virtual void Render();

	//レベルが上がる
	virtual void LevelUp();

	//攻撃力の取得
	int Power();

	//武器IDの取得
	virtual WEAPONID ID() { return NONE; }
};