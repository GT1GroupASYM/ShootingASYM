/////////////////////////////////////////////////////
// Name : MachineGun
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#include "CollisionManager.h"
#include "../../GameBase/Collision/Collision.h"
#include "../Character/Player/Player.h"
#include "../Bullet/Bullet.h"
#include "../Bullet/PlayerBullet/PlayerBullet.h"
#include "../Bullet/EnemyBullet/EnemyBullet.h"
#include "../Item/Item.h"

/////////////////////////////////////////////////////
// Name : CollisionManager
//
// Over View : �R���X�g���N�^
//
// Argument : �f�X�g���N�^
/////////////////////////////////////////////////////
CollisionManager::CollisionManager()
{
	Clear();
}

/////////////////////////////////////////////////////
// Name : ~CollisionManager
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
CollisionManager::~CollisionManager()
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
void CollisionManager::Update()
{
	Collision collision;
	
	for each(auto player in playerList_)
	{
		for each(auto enemy in enemyList_)
		{

		}
	}

	for each(auto player in playerList_)
	{
		for each (auto bullet in enemyBulletList_)
		{
			auto box1 = player->BoundingBox();
			auto box2 = bullet->BoundingBox();

			if (collision.Box2Box(box1, box2))
			{
				player->Hit(bullet);
				bullet->Hit();
			}
		}
	}

	for each(auto player in playerList_)
	{
		for each(auto item in itemList_)
		{
			auto box1 = player->BoundingBox();
			auto box2 = item->BoundingBox();

			if (collision.Box2Box(box1, box2))
			{
				player->Hit(item);
				item->Hit();
			}
		}
	}
	for each(auto enemy in enemyList_)
	{
		for each(auto bullet in playerBulletList_)
		{
		}
	}

	Clear();
}

/////////////////////////////////////////////////////
// Name : Clear
//
// Over View : �o�^�����Z�b�g
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void CollisionManager::Clear()
{
	playerList_.clear();
	enemyList_.clear();
	playerBulletList_.clear();
	enemyBulletList_.clear();
	itemList_.clear();
}

/////////////////////////////////////////////////////
// Name : Entry
//
// Over View : �����蔻��ɓo�^����
//
// Argument : Player�̃|�C���^
//
// Return : ����
/////////////////////////////////////////////////////
void CollisionManager::Entry(Player * player)
{
	playerList_.push_back(player);
}

/////////////////////////////////////////////////////
// Name : Entry
//
// Over View : �����蔻��ɓo�^����
//
// Argument : Enemy�̃|�C���^
//
// Return : ����
/////////////////////////////////////////////////////
void CollisionManager::Entry(Enemy * enemy)
{
	enemyList_.push_back(enemy);
}

/////////////////////////////////////////////////////
// Name : Entry
//
// Over View : �����蔻��ɓo�^����
//
// Argument : Item�̃|�C���^
//
// Return : ����
/////////////////////////////////////////////////////
void CollisionManager::Entry(Item * item)
{
	itemList_.push_back(item);
}

/////////////////////////////////////////////////////
// Name : Entry
//
// Over View : �����蔻��ɓo�^����
//
// Argument : Bullet�̃|�C���^
//
// Return : ����
/////////////////////////////////////////////////////
void CollisionManager::Entry(PlayerBullet* bullet)
{
	playerBulletList_.push_back(bullet);
}

/////////////////////////////////////////////////////
// Name : Entry
//
// Over View : �����蔻��ɓo�^����
//
// Argument : Bullet�̃|�C���^
//
// Return : ����
/////////////////////////////////////////////////////
void CollisionManager::Entry(EnemyBullet * bullet)
{
	
}
