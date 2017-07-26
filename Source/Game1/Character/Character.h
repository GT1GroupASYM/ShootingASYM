/////////////////////////////////////////////////////
// Name : Character
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
// Name : Character
//
// Over View : �L�����N�^�[�̊�ꃉ�X
/////////////////////////////////////////////////////
class Character
{
protected:
	std::shared_ptr<Sprite> sprite_;

	//�ړ�����
	Math::Vector2 vel_;

	//�ړ����x
	float moveSpeed_;

	//�ő�HP
	int maxHp_;

	//���C�t
	int hp_;

public:
	//�R���X�g���N�^
	Character(wchar_t* texturePass,RECT rect);

	//�f�X�g���N�^
	virtual ~Character();

	//����������
	virtual void Initialize();
	
	//�X�V����
	virtual void Update();
	
	//�`�揈��
	virtual void Render();

	//���W�̎擾
	Math::Vector2 Pos();

	//�����蔻��p�̃{�b�N�X�̎擾
	Collider::BoundingBox BoundingBox();
};