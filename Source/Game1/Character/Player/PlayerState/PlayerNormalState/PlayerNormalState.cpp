/////////////////////////////////////////////////////
// Name : PlayerNormalState
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "../../../../../pch.h"
#include "PlayerNormalState.h"
#include "../../Player.h"
#include "../../../../Weapon/Weapon.h"
#include "../../../../../GameBase/ImputManager/InputManager.h"

#include <d3d11.h>
#include <SimpleMath.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : PlayerNormalState
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
PlayerNormalState::PlayerNormalState()
{
}

/////////////////////////////////////////////////////
// Name : ~NormalPlayerState
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
PlayerNormalState::~PlayerNormalState()
{
}

/////////////////////////////////////////////////////
// Name : Input
//
// Over View : ��ԕύX
//
// Argument : �v���C���[�ւ̎Q��
//
// Return : ���̏��
/////////////////////////////////////////////////////
std::shared_ptr<PlayerState> PlayerNormalState::Input(Player & player)
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
void PlayerNormalState::Update(Player& player)
{
	player.weapon_->Update(player);

	Vector2 vel(0.0f, 0.0f);

	auto input = InputManager::GetInstance();

	if (input->KeyInput(Keyboard::A))
		vel += Vector2(-1.0f, 0.0f);
	if (input->KeyInput(Keyboard::D))
		vel += Vector2(1.0f, 0.0f);
	if (input->KeyInput(Keyboard::W))
		vel += Vector2(0.0f, -1.0f);
	if (input->KeyInput(Keyboard::S))
		vel += Vector2(0.0f, 1.0f);

	vel.Normalize();
	player.vel_ = vel;
}
