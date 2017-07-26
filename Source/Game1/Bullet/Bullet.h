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
#include "../../GameBase/Collision/Collision.h"

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

	//�U����
	int power_;

	//�����ɂ����������̃t���O
	bool hit_;

public:
	Bullet();
	virtual ~Bullet();

	//����������
	virtual void Initialize(Math::Vector2 pos,Math::Vector2 vel,int power);
	
	//�X�V����
	virtual bool Update();
	
	//�`�揈��
	virtual void Render();

	//�傫���̎擾�Ɛݒ�
	void Scale(float scale);
	float Scale();

	//�����蔻��p�̃{�b�N�X�̎擾
	Collider::BoundingBox BoundingBox();

	//�U���͂̎擾
	int Power();

	//�����������̏���
	void Hit();
};
