/////////////////////////////////////////////////////
// Name : PlayerInvicibleState
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "../../../../../pch.h"
#include "PlayerInvicibleState.h"
#include "../PlayerNormalState/PlayerNormalState.h"

/////////////////////////////////////////////////////
// Name : PlayerInvicibleState
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
PlayerInvicibleState::PlayerInvicibleState()
{
}

/////////////////////////////////////////////////////
// Name : ~PlayerInvicibleState
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
PlayerInvicibleState::~PlayerInvicibleState()
{
}

/////////////////////////////////////////////////////
// Name : Input
//
// Over View : ��Ԃ̐؂�ւ�
//
// Argument : �v���C���[�ւ̎Q��
//
// Return : ���̏��
/////////////////////////////////////////////////////
std::shared_ptr<PlayerState> PlayerInvicibleState::Input(Player & player)
{
	std::shared_ptr<PlayerState> next = nullptr;

	return next;
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �X�V�����ύX
//
// Argument : �v���C���[�ւ̎Q��
//
// Return : ����
/////////////////////////////////////////////////////
void PlayerInvicibleState::Update(Player & player)
{
	PlayerNormalState normalState;
	normalState.Update(player);
}