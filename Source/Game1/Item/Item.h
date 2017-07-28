/////////////////////////////////////////////////////
// Name : Item
//
// Author : �R�c ����
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <d3d11.h>
#include <SimpleMath.h>
#include "../../GameBase/Collision/Collision.h"

class Sprite;
class Player;

namespace Math = DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : Item
//
// Over View : �A�C�e���̊��N���X
/////////////////////////////////////////////////////
class Item
{
protected:
	std::shared_ptr<Sprite> sprite_;

	//�����ɂ����������̃t���O
	bool hit_;

public:
	//�R���X�g���N�^
	Item();

	//�f�X�g���N�^
	virtual ~Item();

	virtual void Initialize(Math::Vector2 pos);

	//�X�V����
	virtual bool Update();
	
	//�`�揈��
	virtual void Render();

	//�A�C�e���̎g�p
	virtual void Used(Player& player) = 0;

	//���W�̐ݒ�
	virtual void Pos(Math::Vector2 pos);

	//�����������̏���
	void Hit();

	//�����蔻��p�̃{�b�N�X�̎擾
	Collider::BoundingBox BoundingBox();
};