/////////////////////////////////////////////////////
// Name : Game1
//
// Author : �R�c ����
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#include "Game1.h"
#include "Scene\Scene\Scene.h"
#include "Scene\PlayScene\PlayScene.h"
#include "../GameBase/Sprite/SpriteManager/SpriteManager.h"
#include "../GameBase/ImputManager/InputManager.h"
#include "CollisionManager\CollisionManager.h"

/////////////////////////////////////////////////////
// Name : Game1
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Game1::Game1()
{
	scene_.reset(new PlayScene);
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

	scene_->Initialize();
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

	//�V�[���؂�ւ�
	auto next = scene_->Input();
	if (next)
	{
		scene_ = next;
		scene_->Initialize();
	}

	//�V�[���̍X�V
	scene_->Update();

	CollisionManager::GetInstance()->Update();
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

	scene_->Render();

	spriteBatch->End();
}
