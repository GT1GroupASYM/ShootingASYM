/////////////////////////////////////////////////////
// Name : PlayerNormalState
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../PlayerState.h"

/////////////////////////////////////////////////////
// Name : PlayerNormalState
//
// Over View : �ʏ���
/////////////////////////////////////////////////////
class PlayerNormalState:public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerNormalState();

	//�f�X�g���N�^
	~PlayerNormalState();

	//��Ԃ̐؂�ւ�
	std::shared_ptr<PlayerState> Input(Player& player) override;
	
	//�X�V����
	void Update(Player& player) override;
};