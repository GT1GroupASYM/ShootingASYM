/////////////////////////////////////////////////////
// Name : Sprite
//
// Author : 山田 聖弥
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#include "Sprite.h"
#include "SpriteManager/SpriteManager.h"

using namespace DirectX;
using namespace Math;

/////////////////////////////////////////////////////
// Name : Sprite
//
// Over View : コンストラクタ
//
// Argument : 画像のパス
/////////////////////////////////////////////////////
Sprite::Sprite(wchar_t* texturePass,RECT rect)
	:texture_(nullptr),pos_(Vector2::Zero),rect_(rect)
	,rot_(0.0f),scale_(1.0f),origine_(Vector2::Zero)
	,color_(Colors::White)
{
	texture_ = SpriteManager::GetInstance()->LoadTexture(texturePass);
}

/////////////////////////////////////////////////////
// Name : ~Sprite
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Sprite::~Sprite()
{
	texture_ = nullptr;
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : 座標
//
// Return : 無し
/////////////////////////////////////////////////////
void Sprite::Initialize(Vector2 pos)
{
	pos_ = pos;
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
void Sprite::Render()
{
	auto spriteBatch = SpriteManager::GetInstance()->SpriteBatch();

	spriteBatch->Draw(texture_, pos_, &rect_, color_, rot_, origine_,scale_);

	Circle();
}

/////////////////////////////////////////////////////
// Name : Pos
//
// Over View : 座標のセッター
//
// Argument : 座標
//
// Return : 無し
/////////////////////////////////////////////////////
void Sprite::Pos(Math::Vector2 pos)
{
	pos_ = pos;
}

/////////////////////////////////////////////////////
// Name : Pos
//
// Over View : 座標のゲッター
//
// Argument : 無し
//
// Return : 座標
/////////////////////////////////////////////////////
Vector2 Sprite::Pos()
{
	return pos_;
}

/////////////////////////////////////////////////////
// Name : Rect
//
// Over View : 画像の切り取り範囲のセッター
//
// Argument : 画像の切り取り範囲
//
// Return : 無し
/////////////////////////////////////////////////////
void Sprite::Rect(RECT rect)
{
	rect_ = rect;
}

/////////////////////////////////////////////////////
// Name : Rect
//
// Over View : 画像の切り取り範囲のゲッター
//
// Argument : 無し
//
// Return : 画像の切り取り範囲
/////////////////////////////////////////////////////
RECT Sprite::Rect()
{
	return rect_;
}

/////////////////////////////////////////////////////
// Name : Rotation
//
// Over View : 回転角のセッター
//
// Argument : 回転角
//
// Return : 無し
/////////////////////////////////////////////////////
void Sprite::Rotation(float rot)
{
	rot_ = rot;
}

/////////////////////////////////////////////////////
// Name : Rotation
//
// Over View : 回転角のゲッター
//
// Argument : 無し
//
// Return : 回転角
/////////////////////////////////////////////////////
float Sprite::Rotation()
{
	return rot_;
}

/////////////////////////////////////////////////////
// Name : Scale
//
// Over View : 拡大率のセッターとゲッター
//
// Argument : 拡大率
//
// Return : 無し
/////////////////////////////////////////////////////
void Sprite::Scale(float scale)
{
	scale_ = scale;
}

/////////////////////////////////////////////////////
// Name : Scale
//
// Over View : 拡大率のゲッター
//
// Argument : 無し
//
// Return : 拡大率
/////////////////////////////////////////////////////
float Sprite::Scale()
{
	return scale_;
}

/////////////////////////////////////////////////////
// Name : Origine
//
// Over View : アンカーのゲッター
//
// Argument : アンカーポイント
//
// Return : 無し
/////////////////////////////////////////////////////
void Sprite::Origine(Math::Vector2 origine)
{
	origine_ = origine;
}

/////////////////////////////////////////////////////
// Name : Origine
//
// Over View : アンカーのゲッター
//
// Argument : 無し
//
// Return : アンカーポイント
/////////////////////////////////////////////////////
Math::Vector2 Sprite::Origine()
{
	return origine_;
}

/////////////////////////////////////////////////////
// Name : Color
//
// Over View : 色のセッター
//
// Argument : 色
//
// Return : 無し
/////////////////////////////////////////////////////
void Sprite::Color(Math::Color color)
{
	color_ = color;
}

/////////////////////////////////////////////////////
// Name : Color
//
// Over View : 色のゲッター
//
// Argument : 無し
//
// Return : 色
/////////////////////////////////////////////////////
Math::Color Sprite::Color()
{
	return color_;
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
Collider::BoundingBox Sprite::BoundingBox()
{
	//中心点から各頂点の計算
	auto top = pos_.y - origine_.y;
	auto bottom = pos_.y + ((rect_.bottom - rect_.top) - origine_.y);
	auto left = pos_.x - origine_.x;
	auto right = pos_.x + ((rect_.right - rect_.left) - origine_.x);

	top *= scale_;
	bottom *= scale_;
	left *= scale_;
	right *= scale_;

	return Collider::BoundingBox(top, bottom, left, right);
}

/////////////////////////////////////////////////////
// Name : Circle
//
// Over View : 当たり判定用の円の取得
//
// Argument : 無し
//
// Return : 当たり判定用の円
/////////////////////////////////////////////////////
Collider::Circle Sprite::Circle()
{
	//中心点から画像の中心の計算
	Vector2 center;
	center.x = pos_.x + (rect_.right - rect_.left) / 2 - origine_.x;
	center.y = pos_.y + (rect_.bottom - rect_.top) / 2 - origine_.y;

	//半径
	auto radius = (rect_.right - rect_.left) / 2;

	center *= scale_;
	radius *= scale_;

	return Collider::Circle(center, radius);
}
