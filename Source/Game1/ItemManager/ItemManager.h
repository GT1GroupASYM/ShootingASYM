/////////////////////////////////////////////////////
// Name : ItemManager
//
// Author : 山田 聖弥
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <list>

#include "../../GameBase/Utility/Singleton/Singleton.h"

class Item;

/////////////////////////////////////////////////////
// Name : ItemManager
//
// Over View : アイテムの管理クラス
/////////////////////////////////////////////////////
class ItemManager:public Singleton<ItemManager>
{
private:
	std::list <std::shared_ptr<Item>> itemList_;

	//コンストラクタ
	ItemManager();

	friend Singleton<ItemManager>;

public:

	//デストラクタ
	~ItemManager();

	//初期化処理
	void Initialize();

	//更新処理
	void Update();

	//描画処理
	void Render();

	//弾の追加
	void Add(std::shared_ptr<Item> item);

	//弾の全消去
	void Clear();
};