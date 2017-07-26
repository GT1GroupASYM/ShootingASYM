/////////////////////////////////////////////////////
// Name : CollisionManager
//
// Author : �R�c ����
//
// Day : 2017/7/25
/////////////////////////////////////////////////////
#pragma once

#include <vector>
#include "../../GameBase/Utility/Singleton/Singleton.h"

class Player;
class Enemy;
class PlayerBullet;
class EnemyBullet;
class Item;

/////////////////////////////////////////////////////
// Name : CollisionManager
//
// Over View : �����蔻��Ǘ��N���X
/////////////////////////////////////////////////////
class CollisionManager:public Singleton<CollisionManager>
{
private:
	std::vector<Player*> playerList_;
	std::vector<Enemy*> enemyList_;
	std::vector<PlayerBullet*> playerBulletList_;
	std::vector<EnemyBullet*> enemyBulletList_;
	std::vector<Item*> itemList_;

	friend Singleton<CollisionManager>;

	//�R���X�g���N�^
	CollisionManager();
public:

	//�f�X�g���N�^
	~CollisionManager();

	//�X�V����
	void Update();

	//�o�^�����Z�b�g����
	void Clear();

	//�����蔻��ɓo�^
	void Entry(Player* player);
	void Entry(Enemy* enemy);
	void Entry(Item* item);
	void Entry(PlayerBullet* bullet);
	void Entry(EnemyBullet* bullet);
};