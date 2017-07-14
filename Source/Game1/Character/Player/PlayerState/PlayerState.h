/////////////////////////////////////////////////////
// Name : PlayerState
//
// Author : �R�c ����
//
// Day : 2017/7/12
/////////////////////////////////////////////////////
#pragma once

#include <memory>

class Player;

/////////////////////////////////////////////////////
// Name : PlayerState
//
// Over View : �v���C���[�̏�ԊǗ��̊��N���X
/////////////////////////////////////////////////////
class PlayerState
{
private:

	//�R���X�g���N�^
	PlayerState() {}
public:
	//�f�X�g���N�^
	virtual ~PlayerState() {}

	//��Ԃ̕ύX
	virtual std::shared_ptr<PlayerState> Input(Player& player);
	
	//�X�V����
	virtual void Update(Player& player);
};