/////////////////////////////////////////////////////
// Name : CollisionManager
//
// Author : 山田 聖弥
//
// Day : 2017/7/25
/////////////////////////////////////////////////////
#pragma once

#include <vector>
#include "../../GameBase/Utility/Singleton/Singleton.h"

class Player;
class Enemy;
class Bullet;

/////////////////////////////////////////////////////
// Name : CollisionManager
//
// Over View : 当たり判定管理クラス
/////////////////////////////////////////////////////
class CollisionManager:public Singleton<CollisionManager>
{
private:


	friend Singleton<CollisionManager>;

	//コンストラクタ
	CollisionManager();
public:

	//デストラクタ
	~CollisionManager();

	//更新処理
	void Update();
};

