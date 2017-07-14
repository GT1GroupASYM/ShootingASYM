/////////////////////////////////////////////////////
// Name : MachineGun
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../Weapon.h"

/////////////////////////////////////////////////////
// Name : MachineGun
//
// Over View : �}�V���K���N���X
/////////////////////////////////////////////////////
class MachineGun :public Weapon
{
private:
	float waitTime_;

	float currentTime_;

public:
	//�R���X�g���N�^
	MachineGun();

	//�f�X�g���N�^
	~MachineGun();

	//����������
	void Initialize() override;
	
	//�X�V����
	void Update(Character& character) override;
	
	//�`�揈��
	void Render() override;
};
