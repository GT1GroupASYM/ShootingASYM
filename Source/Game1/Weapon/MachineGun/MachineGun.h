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
	//�e�̑ł���
	float waitTime_;

	//�o�ߎ���
	float currentTime_;

	//���x������U���͂��Z�o
	int CalcPower();

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

