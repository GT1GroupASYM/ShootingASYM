/////////////////////////////////////////////////////
// Name : Bullet
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "../../../pch.h"
#include "Bullet.h"
#include "../../GameBase/Sprite/Sprite.h"

using namespace Math;

/////////////////////////////////////////////////////
// Name : Bullet
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Bullet::Bullet()
	:vel_(Vector2::Zero), moveSpeed_(15.0f)
{
	RECT rect{ 0,0,32,32 };
	sprite_.reset(new Sprite(L"Resources\\Images\\Ball.png",rect));
}

/////////////////////////////////////////////////////
// Name : ~デストラクタ
//
// Over View : デストラクタ
//
// Argument : ~Bullet
/////////////////////////////////////////////////////
Bullet::~Bullet()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : 画像のパス
//
// Return : 無し
/////////////////////////////////////////////////////
void Bullet::Initialize(Vector2 pos,Vector2 vel)
{
	sprite_->Pos(pos);
	vel_ = vel;
	vel_.Normalize();
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
void Bullet::Update()
{
	sprite_->Pos(sprite_->Pos() + vel_ * moveSpeed_);
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
void Bullet::Render()
{
	sprite_->Render();
}
