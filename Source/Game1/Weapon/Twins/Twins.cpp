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
// Name : Twins
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Twins::Twins()
	:waitTime_(0.1f),currentTime_(0.0f)
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
		bullet.reset(new Bullet);
		bullet->Initialize(pos, -vel);
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
void Twins::Render()
{
}
