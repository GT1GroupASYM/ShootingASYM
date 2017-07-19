/////////////////////////////////////////////////////
// Name : MachineGun
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "../../../../pch.h"
#include "MachineGun.h"
#include "../../../GameBase/ImputManager/InputManager.h"
#include "../../BulletManager/BulletManager.h"
#include "../../Bullet/Bullet.h"
#include "../../Character/Character.h"

using namespace DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : CalcPower
//
// Over View : ���x������U���͂��Z�o
//
// Argument : ����
//
// Return : �U����
/////////////////////////////////////////////////////
int MachineGun::CalcPower()
{
	auto power = 0;

	//20 -> 25 -> 50
	for (auto i = 0; i < 5; i++)
	{
		auto num = 100 % (5 - (level_ - 1) - i);
		if (num == 0)
		{
			power = 100 / (5 - (level_ - 1) - i);
			break;
		}
	}

	return power;
}

/////////////////////////////////////////////////////
// Name : MachineGun
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
MachineGun::MachineGun()
	:Weapon(20),waitTime_(0.1f)
	, currentTime_(0.0f)
{
}

/////////////////////////////////////////////////////
// Name : ~MachineGun
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
MachineGun::~MachineGun()
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
void MachineGun::Initialize()
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
void MachineGun::Update(Character& character)
{
	if (currentTime_ < waitTime_)
	{
		currentTime_ += 1.0f / 60;
		return;
	}

	auto mouse = InputManager::GetInstance()->Mouse();
	if (mouse->GetState().leftButton)
	{
		auto x = mouse->GetState().x;
		auto y = mouse->GetState().y;
		auto pos = character.Pos();
		auto vel = Vector2(x, y) - pos;
		auto power = CalcPower();

		for (auto i = 0; i < level_; i++)
		{
			//�e�̐���
			std::shared_ptr<Bullet> bullet;
			bullet.reset(new Bullet);
			bullet->Initialize(pos, vel, power_);
			BulletManager::GetInstance()->Add(bullet);

			if (i == 0) continue;
		}
		//�}�V���K���̑ҋ@���Ԃ̏�����
		currentTime_ = 0.0f;
	}
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
void MachineGun::Render()
{
}