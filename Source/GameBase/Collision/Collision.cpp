/////////////////////////////////////////////////////
// Name : Scene
//
// Author : �R�c ����
//
// Day : 2017/7/24
/////////////////////////////////////////////////////
#include "../../../pch.h"
#include "Collision.h"


/////////////////////////////////////////////////////
// Name : Collision
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Collision::Collision()
{
}

/////////////////////////////////////////////////////
// Name : ~Collision
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Collision::~Collision()
{
}

/////////////////////////////////////////////////////
// Name : Box2Box
//
// Over View : �{�b�N�X�ƃ{�b�N�X�̓����蔻��
//
// Argument : �����蔻����s���{�b�N�X�Q��
//
// Return : ����������true
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
// Over View : �~�Ɖ~�̓����蔻��
//
// Argument : �����蔻����s���~�Q��
//
// Return : ����������true
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
