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
#include "../../CollisionManager/CollisionManager.h"
#include "../../Bullet/Bullet.h"
#include "../../Item/Item.h"
#include "../../../GameBase/Utility/UtilityFunction/UtilityFunction.h"

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
	weapon_.reset(new MachineGun);
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

	CollisionManager::GetInstance()->Entry(this);
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

/////////////////////////////////////////////////////
// Name : Hit
//
// Over View : �����������̏���
//
// Argument : Bullet�̃|�C���^
//
// Return : ����
/////////////////////////////////////////////////////
void Player::Hit(Bullet * bullet)
{
	auto power = bullet->Power();

	hp_ -= power;

	hp_ = Clamp(hp_, 0, maxHp_);
}

/////////////////////////////////////////////////////
// Name : Hit
//
// Over View : �����������̏���
//
// Argument : Item�̃|�C���^
//
// Return : ����
/////////////////////////////////////////////////////
void Player::Hit(Item * item)
{
	item->Used(*this);
}

/////////////////////////////////////////////////////
// Name : LevelUp
//
// Over View : ���탌�x���̏㏸
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void Player::LevelUp()
{
	weapon_->LevelUp();
}

/////////////////////////////////////////////////////
// Name : ChangeWeapon
//
// Over View : ����̕ύX
//
// Argument : �V��������
//
// Return : ����
/////////////////////////////////////////////////////
void Player::ChangeWeapon(std::shared_ptr<Weapon> newWeapon)
{
	if (weapon_->ID() == newWeapon->ID()) return;

	weapon_ = newWeapon;
}