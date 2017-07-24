/////////////////////////////////////////////////////
// Name : Scene
//
// Author : 山田 聖弥
//
// Day : 2017/7/24
/////////////////////////////////////////////////////
#include "../../../pch.h"
#include "Collision.h"


/////////////////////////////////////////////////////
// Name : Collision
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Collision::Collision()
{
}

/////////////////////////////////////////////////////
// Name : ~Collision
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Collision::~Collision()
{
}

/////////////////////////////////////////////////////
// Name : Box2Box
//
// Over View : ボックスとボックスの当たり判定
//
// Argument : 当たり判定を行うボックス２つ
//
// Return : 当たったらtrue
/////////////////////////////////////////////////////
bool Collision::Box2Box(Collider::BoundingBox box1, Collider::BoundingBox box2)
{
	if (box1.top_ < box2.bottom_ && box1.bottom_ > box2.top_
		&& box1.left_ < box2.right_ && box1.right_ > box2.left_)
	{
		return true;
	}

	return false;
}

/////////////////////////////////////////////////////
// Name : Circle2Circle
//
// Over View : 円と円の当たり判定
//
// Argument : 当たり判定を行う円２つ
//
// Return : 当たったらtrue
/////////////////////////////////////////////////////
bool Collision::Circle2Circle(Collider::Circle circle1, Collider::Circle circle2)
{
	auto sub = circle2.center_ - circle1.center_;
	auto disSqr = sub.x * sub.x + sub.y * sub.y;
	auto radiusSqr = circle1.radius_ * circle2.radius_;

	if (disSqr <= radiusSqr)
	{
		return true;
	}

	return false;
}
