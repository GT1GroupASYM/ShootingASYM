/////////////////////////////////////////////////////
// Name : Item
//
// Author : 山田 聖弥
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#include "Item.h"
#include "../../GameBase/Sprite/Sprite.h"

/////////////////////////////////////////////////////
// Name : Item
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Item::Item()
	:hit_(false)
{

}

/////////////////////////////////////////////////////
// Name : ~Item
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Item::~Item()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void Item::Initialize(Math::Vector2 pos)
{
	sprite_->Initialize(pos);
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : 更新処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
bool Item::Update()
{
	if (hit_)
		return false;

	return true;
}

/////////////////////////////////////////////////////
// Name : Render
//
// Over View : 描画処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void Item::Render()
{
	sprite_->Render();
}

/////////////////////////////////////////////////////
// Name : Pos
//
// Over View : 座標の設定
//
// Argument : 座標
//
// Return : 無し
/////////////////////////////////////////////////////
void Item::Pos(Math::Vector2 pos)
{
	sprite_->Pos(pos);
}

/////////////////////////////////////////////////////
// Name : Hit
//
// Over View : 当たった時の処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void Item::Hit()
{
	hit_ = true;
}

/////////////////////////////////////////////////////
// Name : BoundingBox
//
// Over View : 当たり判定用のボックスの取得
//
// Argument : 無し
//
// Return : 当たり判定用のボックス
/////////////////////////////////////////////////////
Collider::BoundingBox Item::BoundingBox()
{
	return sprite_->BoundingBox();
}
