/////////////////////////////////////////////////////
// Name : Bullet
//
// Author : �R�c ����
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
// Over View : �e�̊��N���X
/////////////////////////////////////////////////////
class Bullet
{
protected:
	std::shared_ptr<Sprite> sprite_;

	//�ړ�����
	Math::Vector2 vel_;

	//�ړ����x
	float moveSpeed_;

public:
	Bullet();
	virtual ~Bullet();

	virtual void Initialize(Math::Vector2 pos,Math::Vector2 vel);
	virtual void Update();
	virtual void Render();
};

