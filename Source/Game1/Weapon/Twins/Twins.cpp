/////////////////////////////////////////////////////
// Name : Twins
//
// Author : �R�c ����
//
// Day : 2017/7/16
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>

#include "../../../../pch.h"
#include "Twins.h"
#include "../../../GameBase/ImputManager/InputManager.h"
#include "../../Bullet/Bullet.h"
#include "../../BulletManager/BulletManager.h"
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
int Twins::CalcPower()
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
// Name : Twins
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Twins::Twins()
	:Weapon(20),waitTime_(0.3f)
	,currentTime_(0.0f),dir_(1)
{
}

/////////////////////////////////////////////////////
// Name : ~Twins
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Twins::~Twins()
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
void Twins::Initialize()
{
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �X�V����
//
// Argument : �L�����N�^�[�ւ̎Q��
//
// Return : ����
/////////////////////////////////////////////////////
void Twins::Update(Character & character)
{
	if (currentTime_ < waitTime_)
	{
		currentTime_ += 1.0f / 60;
		return;
	}

	if (InputManager::GetInstance()->KeyInputDown(DirectX::Keyboard::R))
		level_--;
	if (InputManager::GetInstance()->KeyInputDown(DirectX::Keyboard::T))
		LevelUp();

	auto mouse = InputManager::GetInstance()->Mouse();
	if (mouse->GetState().leftButton)
	{
		auto x = (float)mouse->GetState().x;
		auto y = (float)mouse->GetState().y;
		auto pos = character.Pos();
		auto vel = Vector2(x, y) - pos;

		//�e�̐���
		std::shared_ptr<Bullet> bullet;
		bullet.reset(new Bullet);
		auto power = CalcPower();
		bullet->Initialize(pos, vel * dir_, power);
		bullet->Scale(1 + (level_ - 1) * bulletIncreaseValue_);
		BulletManager::GetInstance()->Add(bullet);

		//�U���̌����̕ύX
		dir_ *= -1;

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
void Twins::Render()
{
}