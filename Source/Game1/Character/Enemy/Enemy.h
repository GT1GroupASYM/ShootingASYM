/////////////////////////////////////////////////////
// Name : Enemy
//
// Author : ���� �ˑ�
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../Character.h"

/////////////////////////////////////////////////////
// Name : Enemy
//
// Over View : �G�l�~�[�N���X
/////////////////////////////////////////////////////
class Enemy : public Character
{
public:
	//�R���X�g���N�^
	Enemy(wchar_t* texturePass);

	//�f�X�g���N�^
	~Enemy();

	//����������
	void Initialize() override;

	//�X�V����
	void Update() override;

	//�`�揈��
	void Render() override;

};