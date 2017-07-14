/////////////////////////////////////////////////////
// Name : Enemy
//
// Author : 安藤 祥大
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../Character.h"

/////////////////////////////////////////////////////
// Name : Enemy
//
// Over View : エネミークラス
/////////////////////////////////////////////////////
class Enemy : public Character
{
public:
	//コンストラクタ
	Enemy(wchar_t* texturePass);

	//デストラクタ
	~Enemy();

	//初期化処理
	void Initialize() override;

	//更新処理
	void Update() override;

	//描画処理
	void Render() override;

};