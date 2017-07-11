/////////////////////////////////////////////////////
// Name : Game1
//
// Author : �R�c ����
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#include "../../pch.h"
#include "Game1.h"
#include "../GameBase/Sprite/Sprite.h"
#include "../GameBase/Sprite/SpriteManager/SpriteManager.h"
#include "../GameBase/ImputManager/InputManager.h"

#include <d3d11.h>
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : Game1
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Game1::Game1()
{
	sprite_.reset(new Sprite(L"Resources\\Images\\Ball.png"));
}

/////////////////////////////////////////////////////
// Name : ~Game1
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Game1::~Game1()
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
void Game1::Initialize()
{
	GameMain::Initialize();

	sprite_->Initialize(Vector2(300, 400));
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
void Game1::Update()
{
	GameMain::Update();
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
void Game1::Render()
{
	GameMain::Render();

	auto spriteBatch = SpriteManager::GetInstance()->SpriteBatch();
	auto commonState = SpriteManager::GetInstance()->CommonState();
	spriteBatch->Begin(DirectX::SpriteSortMode_Deferred,commonState->NonPremultiplied(),commonState->PointClamp());

	sprite_->Render();

	spriteBatch->End();
}
