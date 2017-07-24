/////////////////////////////////////////////////////
// Name : Collision
//
// Author : 山田 聖弥
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
	// Over View : 当たり判定用のボックス
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
	// Over View : 当たり判定用の円
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
// Over View : 当たり判定クラス
/////////////////////////////////////////////////////
class Collision
{
private:

public:
	Collision();
	~Collision();

	//ボックスとボックスの当たり判定
	bool Box2Box(Collider::BoundingBox box1, Collider::BoundingBox box2);
	
	//円と円の当たり判定
	bool Circle2Circle(Collider::Circle circle1, Collider::Circle circle2);
};