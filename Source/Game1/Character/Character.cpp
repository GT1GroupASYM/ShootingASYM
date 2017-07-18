/////////////////////////////////////////////////////
// Name : Character
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "../../../pch.h"
#include "Character.h"
#include "../../GameBase/Sprite/Sprite.h"

using namespace Math;

/////////////////////////////////////////////////////
// Name : Character
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Character::Character(wchar_t* texturePass,RECT rect)
	:vel_(Vector2::Zero), moveSpeed_(3.0f)
{
	sprite_.reset(new Sprite(texturePass,rect));
	sprite_->Origine(Vector2(rect.bottom / 2, rect.right / 2));
}

/////////////////////////////////////////////////////
// Name : ~Character
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Character::~Character()
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
void Character::Initialize()
{
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
void Character::Update()
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
void Character::Render()
{
	sprite_->Render();
}

/////////////////////////////////////////////////////
// Name : Pos
//
// Over View : 座標の取得
//
// Argument : 無し
//
// Return : 座標
/////////////////////////////////////////////////////
Math::Vector2 Character::Pos()
{
	return sprite_->Pos();
}
