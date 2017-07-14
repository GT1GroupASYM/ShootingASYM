/////////////////////////////////////////////////////
// Name : Bullet
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <d3d11.h>
#include <SimpleMath.h>

class Sprite;

namespace Math = DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : Bullet
//
// Over View : 弾の基底クラス
/////////////////////////////////////////////////////
class Bullet
{
protected:
	std::shared_ptr<Sprite> sprite_;

	//移動方向
	Math::Vector2 vel_;

	//移動速度
	float moveSpeed_;

public:
	Bullet();
	virtual ~Bullet();

	virtual void Initialize(Math::Vector2 pos,Math::Vector2 vel);
	virtual void Update();
	virtual void Render();
};

