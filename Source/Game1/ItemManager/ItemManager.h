/////////////////////////////////////////////////////
// Name : ItemManager
//
// Author : �R�c ����
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <list>

#include "../../GameBase/Utility/Singleton/Singleton.h"

class Item;

/////////////////////////////////////////////////////
// Name : ItemManager
//
// Over View : �A�C�e���̊Ǘ��N���X
/////////////////////////////////////////////////////
class ItemManager:public Singleton<ItemManager>
{
private:
	std::list <std::shared_ptr<Item>> itemList_;

	//�R���X�g���N�^
	ItemManager();

	friend Singleton<ItemManager>;

public:

	//�f�X�g���N�^
	~ItemManager();

	//����������
	void Initialize();

	//�X�V����
	void Update();

	//�`�揈��
	void Render();

	//�e�̒ǉ�
	void Add(std::shared_ptr<Item> item);

	//�e�̑S����
	void Clear();
};