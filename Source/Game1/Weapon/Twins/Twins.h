/////////////////////////////////////////////////////
// Name : Twins
//
// Author : �R�c ����
//
// Day : 2017/7/16
/////////////////////////////////////////////////////
#pragma once

#include "../Weapon.h"

/////////////////////////////////////////////////////
// Name : Twins
//
// Over View : �O�㌂���N���X
/////////////////////////////////////////////////////
class Twins:public Weapon
{
private:
	//�e�̑ł���
	float waitTime_;

	//�o�ߎ���
	float currentTime_;

public:
	//�R���X�g���N�^
	Twins();

	//�f�X�g���N�^
	~Twins();

	//����������
	void Initialize() override;

	//�X�V����
	void Update(Character& character) override;

	//�`�揈��
	void Render() override;
};

