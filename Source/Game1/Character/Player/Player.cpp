/////////////////////////////////////////////////////
// Name : Player
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "../../../../pch.h"
#include "Player.h"
#include "PlayerState\PlayerState.h"
#include "PlayerState\PlayerNormalState\PlayerNormalState.h"
#include "../../Weapon/MachineGun/MachineGun.h"
#include "../../Weapon/Twins/Twins.h"


/////////////////////////////////////////////////////
// Name : Player
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Player::Player(wchar_t* texturePass,RECT rect)
	:Character(texturePass,rect)
{
	state_.reset(new PlayerNormalState);
	weapon_.reset(new Twins);
}

/////////////////////////////////////////////////////
// Name : ~Player
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Player::~Player()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : ����������
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void Player::Initialize()
{
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �X�V����
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void Player::Update()
{
	auto next = state_->Input(*this);
	if (next)
	{
		state_ = next;
	}

	state_->Update(*this);

	Character::Update();
}

/////////////////////////////////////////////////////
// Name : Render
//
// Over View : �`�揈��
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void Player::Render()
{
	Character::Render();
}