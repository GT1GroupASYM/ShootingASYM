/////////////////////////////////////////////////////
// Name : LevelUpItem
//
// Author : �R�c ����
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#pragma once

#include "../Item.h"

/////////////////////////////////////////////////////
// Name : LevelUpItem
//
// Over View : ���탌�x�����グ��A�C�e��
/////////////////////////////////////////////////////
class LevelUpItem :public Item
{
private:

public:
	
	//�R���X�g���N�^
	LevelUpItem();

	//�f�X�g���N�^
	~LevelUpItem();

	//�X�V����
	bool Update() override;

	//�A�C�e���̎g�p
	void Used(Player& player) override;
};

