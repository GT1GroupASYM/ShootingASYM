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

using namespace Math;

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
// Name : BulletFire
//
// Over View : ��������
//
// Argument : �}�E�X�A�L�����N�^�[�ւ̎Q��
//
// Return : ����
/////////////////////////////////////////////////////
void MachineGun::BulletFire(DirectX::Mouse * mouse, Character & character)
{
	auto x = mouse->GetState().x;
	auto y = mouse->GetState().y;
	auto pos = character.Pos();
	auto vel = Vector2((float)x, (float)y) - pos;
	auto power = CalcPower();

	for (auto i = 0; i < level_; i++)
	{
		Fire(pos, vel, 1, i);

		if (i == 0) continue;

		Fire(pos, vel, -1, i);
	}
}

/////////////////////////////////////////////////////
// Name : Fire
//
// Over View : ��������(���ۂɌĂяo���̂�BulletFire�̒�)
//
// Argument : ���W�A���x�A�L����p�x�̌����A�����ڂ�
//
// Return : ����
/////////////////////////////////////////////////////
void MachineGun::Fire(Vector2 pos,Vector2 vel, int dir,int bulletCount)
{
	auto angle = atan2f(vel.y, vel.x);
	angle += (bulletCount * 5) * 3.14f / 180 * dir;
	Matrix rot = Matrix::CreateRotationZ(angle);
	vel = Vector2::TransformNormal(Vector2(1.0f, 0.0f), rot);

	//�e�̐���
	std::shared_ptr<Bullet> bullet;
	bullet.reset(new Bullet);
	bullet->Initialize(pos, vel, power_);
	BulletManager::GetInstance()->Add(bullet);
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

	if (InputManager::GetInstance()->KeyInputDown(DirectX::Keyboard::T))
		LevelUp();
	if (InputManager::GetInstance()->KeyInputDown(DirectX::Keyboard::R))
		level_--;

	auto mouse = InputManager::GetInstance()->Mouse();
	if (mouse->GetState().leftButton)
	{
		//��������
		BulletFire(mouse, character);

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