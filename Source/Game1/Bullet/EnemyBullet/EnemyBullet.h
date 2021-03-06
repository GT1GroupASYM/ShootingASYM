/////////////////////////////////////////////////////
// Name : EnemyBullet
//
// Author : 山田 聖弥
//
// Day : 2017/7/26
/////////////////////////////////////////////////////
#pragma once

#include "../Bullet.h"

/////////////////////////////////////////////////////
// Name : EnemyBullet
//
// Over View : CollisionManagerに敵の球として登録するためのクラス
/////////////////////////////////////////////////////
class EnemyBullet:public Bullet
{
public:
	//コンストラクタ
	EnemyBullet();

	//デストラクタ
	virtual ~EnemyBullet();

	//更新処理
	virtual bool Update() override;
};

