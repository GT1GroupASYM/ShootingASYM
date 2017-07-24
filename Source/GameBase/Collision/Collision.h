/////////////////////////////////////////////////////
// Name : Collision
//
// Author : �R�c ����
//
// Day : 2017/7/24
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>

namespace Math = DirectX::SimpleMath;

namespace Collider
{
	/////////////////////////////////////////////////////
	// Name : BoundingBox
	//
	// Over View : �����蔻��p�̃{�b�N�X
	/////////////////////////////////////////////////////
	struct BoundingBox
	{
		float top_;
		float bottom_;
		float left_;
		float right_;

		BoundingBox(float top, float bottom, float left, float right)
			:top_(top), bottom_(bottom), left_(left), right_(right)
		{

		}
	};

	/////////////////////////////////////////////////////
	// Name : Circle
	//
	// Over View : �����蔻��p�̉~
	/////////////////////////////////////////////////////
	struct Circle
	{
		Math::Vector2 center_;
		float radius_;

		Circle(Math::Vector2 center, float radius)
			:center_(center), radius_(radius)
		{

		}
	};
}

/////////////////////////////////////////////////////
// Name : Collision
//
// Over View : �����蔻��N���X
/////////////////////////////////////////////////////
class Collision
{
private:

public:
	Collision();
	~Collision();

	//�{�b�N�X�ƃ{�b�N�X�̓����蔻��
	bool Box2Box(Collider::BoundingBox box1, Collider::BoundingBox box2);
	
	//�~�Ɖ~�̓����蔻��
	bool Circle2Circle(Collider::Circle circle1, Collider::Circle circle2);
};