/////////////////////////////////////////////////////
// Name : TwinsItem
//
// Author : �R�c ����
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#include "TwinsItem.h"
#include "../../../GameBase/Sprite/Sprite.h"
#include "../../Weapon/Twins/Twins.h"
#include "../../Character/Player/Player.h"
#include "../../CollisionManager/CollisionManager.h"

/////////////////////////////////////////////////////
// Name : TwinsItem
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
TwinsItem::TwinsItem()
	:Item()
{
	sprite_.reset(new Sprite(L"Resources\\Images\\TwinsItem.png", RECT{ 0,0,32,32 }));
	sprite_->Origine(Math::Vector2(16, 16));
}

/////////////////////////////////////////////////////
// Name : ~MachineGunItem
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
TwinsItem::~TwinsItem()
{
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �X�V����
//
// Argument : ����
//
// Return : �����ɓ���������false
/////////////////////////////////////////////////////
bool TwinsItem::Update()
{
	if (hit_)
		return false;

	CollisionManager::GetInstance()->Entry(this);

	return true;
}

/////////////////////////////////////////////////////
// Name : Used
//
// Over View : �A�C�e�����g��
//
// Argument : �v���C���[�ւ̎Q��
//
// Return : ����
/////////////////////////////////////////////////////
void TwinsItem::Used(Player & player)
{
	std::shared_ptr<Twins> twins;
	twins.reset(new Twins);
	player.ChangeWeapon(twins);
}