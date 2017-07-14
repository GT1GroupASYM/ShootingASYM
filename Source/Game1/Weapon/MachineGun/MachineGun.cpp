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
// Name : MachineGun
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
MachineGun::MachineGun()
	:waitTime_(0.1f), currentTime_(0.0f)
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

		//�e�̐���
		std::shared_ptr<Bullet> bullet;
		bullet.reset(new Bullet);
		bullet->Initialize(pos, vel);
		BulletManager::GetInstance()->Add(bullet);

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