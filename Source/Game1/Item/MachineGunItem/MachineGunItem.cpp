/////////////////////////////////////////////////////
// Name : MachineGunItem
//
// Author : �R�c ����
//
// Day : 2017/7/28
/////////////////////////////////////////////////////
#include "MachineGunItem.h"
#include "../../../GameBase/Sprite/Sprite.h"
#include "../../Weapon/MachineGun/MachineGun.h"
#include "../../Character/Player/Player.h"
#include "../../CollisionManager/CollisionManager.h"

/////////////////////////////////////////////////////
// Name : MachineGunItem
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
MachineGunItem::MachineGunItem()
	:Item()
{
	sprite_.reset(new Sprite(L"Resources\\Images\\MachineGunItem.png", RECT{ 0,0,32,32 }));
	sprite_->Origine(Math::Vector2(16, 16));
}

/////////////////////////////////////////////////////
// Name : ~MachineGunItem
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
MachineGunItem::~MachineGunItem()
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
bool MachineGunItem::Update()
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
void MachineGunItem::Used(Player & player)
{
	std::shared_ptr<MachineGun> machineGun;
	machineGun.reset(new MachineGun);
	player.ChangeWeapon(machineGun);
}