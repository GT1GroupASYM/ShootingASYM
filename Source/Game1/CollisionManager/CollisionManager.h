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
class PlayerBullet;
class EnemyBullet;
class Item;

/////////////////////////////////////////////////////
// Name : CollisionManager
//
// Over View : 当たり判定管理クラス
/////////////////////////////////////////////////////
class CollisionManager:public Singleton<CollisionManager>
{
private:
	std::vector<Player*> playerList_;
	std::vector<Enemy*> enemyList_;
	std::vector<PlayerBullet*> playerBulletList_;
	std::vector<EnemyBullet*> enemyBulletList_;
	std::vector<Item*> itemList_;

	friend Singleton<CollisionManager>;

	//コンストラクタ
	CollisionManager();
public:

	//デストラクタ
	~CollisionManager();

	//更新処理
	void Update();

	//登録をリセットする
	void Clear();

	//当たり判定に登録
	void Entry(Player* player);
	void Entry(Enemy* enemy);
	void Entry(Item* item);
	void Entry(PlayerBullet* bullet);
	void Entry(EnemyBullet* bullet);
};