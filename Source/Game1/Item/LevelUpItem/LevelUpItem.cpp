/////////////////////////////////////////////////////
// Name : LevelUpItem
//
// Author : �R�c ����
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#include "LevelUpItem.h"
#include "../../../GameBase/Sprite/Sprite.h"
#include "../../Character/Player/Player.h"
#include "../../CollisionManager/CollisionManager.h"

/////////////////////////////////////////////////////
// Name : LevelUpItem
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
LevelUpItem::LevelUpItem()
	:Item()
{
	sprite_.reset(new Sprite(L"Resources\\Images\\LevelUpItem.png", RECT{ 0,0,32,32 }));
	sprite_->Origine(Math::Vector2(16, 16));
}

/////////////////////////////////////////////////////
// Name : ~LevelUpItem
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
LevelUpItem::~LevelUpItem()
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
bool LevelUpItem::Update()
{
	if (hit_)
		return false;

	CollisionManager::GetInstance()->Entry(this);

	return true;
}

/////////////////////////////////////////////////////
// Name : Used
//
// Over View : �A�C�e�����g�p����
//
// Argument : �v���C���[�ւ̎Q��
//
// Return : ����
/////////////////////////////////////////////////////
void LevelUpItem::Used(Player & player)
{
	player.LevelUp();
}
