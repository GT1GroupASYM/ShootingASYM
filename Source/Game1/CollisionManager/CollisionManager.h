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
class Bullet;

/////////////////////////////////////////////////////
// Name : CollisionManager
//
// Over View : �����蔻��Ǘ��N���X
/////////////////////////////////////////////////////
class CollisionManager:public Singleton<CollisionManager>
{
private:


	friend Singleton<CollisionManager>;

	//�R���X�g���N�^
	CollisionManager();
public:

	//�f�X�g���N�^
	~CollisionManager();

	//�X�V����
	void Update();
};

