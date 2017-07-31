/////////////////////////////////////////////////////
// Name : PlayScene
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "PlayScene.h"
#include "../../Character/Player/Player.h"
#include "../../BulletManager/BulletManager.h"
#include "../../Item/LevelUpItem/LevelUpItem.h"
#include "../../Item/MachineGunItem/MachineGunItem.h"
#include "../../Item/TwinsItem/TwinsItem.h"
#include "../../ItemManager/ItemManager.h"

/////////////////////////////////////////////////////
// Name : PlayScene
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
PlayScene::PlayScene()
	:Scene()
{
	RECT rect{ 0,0,32,32 };
	player_.reset(new Player(L"Resources\\Images\\Ball.png",rect));
}

/////////////////////////////////////////////////////
// Name : ~PlayScene
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
PlayScene::~PlayScene()
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
void PlayScene::Initialize()
{
	player_->Initialize();

	ItemManager::GetInstance()->Initialize();
	BulletManager::GetInstance()->Initialize();

	std::shared_ptr<Item> item;
	item.reset(new LevelUpItem);
	item->Pos(Math::Vector2(100, 100));
	ItemManager::GetInstance()->Add(item);

	item.reset(new MachineGunItem);
	item->Pos(Math::Vector2(200, 100));
	ItemManager::GetInstance()->Add(item);

	item.reset(new TwinsItem);
	item->Pos(Math::Vector2(200, 200));
	ItemManager::GetInstance()->Add(item);
}

/////////////////////////////////////////////////////
// Name : input
//
// Over View : �V�[���؂�ւ�
//
// Argument : ����
//
// Return : ���̃V�[��
/////////////////////////////////////////////////////
std::shared_ptr<Scene> PlayScene::Input()
{
	std::shared_ptr<Scene> next = nullptr;

	return next;
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �`�揈��
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void PlayScene::Update()
{
	player_->Update();


	ItemManager::GetInstance()->Update();
	BulletManager::GetInstance()->Update();
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
void PlayScene::Render()
{
	player_->Render();

	ItemManager::GetInstance()->Render();
	BulletManager::GetInstance()->Render();
}