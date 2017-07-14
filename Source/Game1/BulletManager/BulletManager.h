/////////////////////////////////////////////////////
// Name : BulletManager
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <list>

#include "../../GameBase/Utility/Singleton/Singleton.h"

class Bullet;

/////////////////////////////////////////////////////
// Name : BulletManager
//
// Over View : �e�̊Ǘ��N���X
/////////////////////////////////////////////////////
class BulletManager:public Singleton<BulletManager>
{
private:
	std::list <std::shared_ptr<Bullet>> bulletList_;

	//�R���X�g���N�^
	BulletManager();

	friend Singleton<BulletManager>;

public:

	//�f�X�g���N�^
	~BulletManager();

	//����������
	void Initialize();

	//�X�V����
	void Update();

	//�`�揈��
	void Render();

	//�e�̒ǉ�
	void Add(std::shared_ptr<Bullet> bullet);

	//�e�̑S����
	void Clear();
};