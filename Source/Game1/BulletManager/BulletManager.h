/////////////////////////////////////////////////////
// Name : BulletManager
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <list>

#include "../../GameBase/Utility/Singleton/Singleton.h"

class Bullet;

/////////////////////////////////////////////////////
// Name : BulletManager
//
// Over View : 弾の管理クラス
/////////////////////////////////////////////////////
class BulletManager:public Singleton<BulletManager>
{
private:
	std::list <std::shared_ptr<Bullet>> bulletList_;

	//コンストラクタ
	BulletManager();

	friend Singleton<BulletManager>;

public:

	//デストラクタ
	~BulletManager();

	//初期化処理
	void Initialize();

	//更新処理
	void Update();

	//描画処理
	void Render();

	//弾の追加
	void Add(std::shared_ptr<Bullet> bullet);

	//弾の全消去
	void Clear();
};