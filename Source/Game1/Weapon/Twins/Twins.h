/////////////////////////////////////////////////////
// Name : Twins
//
// Author : �R�c ����
//
// Day : 2017/7/25
/////////////////////////////////////////////////////
#pragma once

#include <Mouse.h>

#include "../Weapon.h"

namespace Math = DirectX::SimpleMath;

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

	//�U���̌���
	int dir_;

	//���̑傫���̏㏸�l
	const float bulletIncreaseValue_ = 0.25f;

	//����ł�
	void BulletFire(DirectX::Mouse* mouse,Character& caracter);

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

