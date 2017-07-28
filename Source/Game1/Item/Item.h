/////////////////////////////////////////////////////
// Name : Item
//
// Author : 山田 聖弥
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <d3d11.h>
#include <SimpleMath.h>
#include "../../GameBase/Collision/Collision.h"

class Sprite;
class Player;

namespace Math = DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : Item
//
// Over View : アイテムの基底クラス
/////////////////////////////////////////////////////
class Item
{
protected:
	std::shared_ptr<Sprite> sprite_;

	//何かにあたったかのフラグ
	bool hit_;

public:
	//コンストラクタ
	Item();

	//デストラクタ
	virtual ~Item();

	virtual void Initialize(Math::Vector2 pos);

	//更新処理
	virtual bool Update();
	
	//描画処理
	virtual void Render();

	//アイテムの使用
	virtual void Used(Player& player) = 0;

	//座標の設定
	virtual void Pos(Math::Vector2 pos);

	//当たった時の処理
	void Hit();

	//当たり判定用のボックスの取得
	Collider::BoundingBox BoundingBox();
};