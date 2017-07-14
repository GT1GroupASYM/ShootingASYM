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

public:
	//�R���X�g���N�^
	Character(wchar_t* texturePass);

	//�f�X�g���N�^
	virtual ~Character();

	//����������
	virtual void Initialize();
	
	//�X�V����
	virtual void Update();
	
	//�`�揈��
	virtual void Render();
};