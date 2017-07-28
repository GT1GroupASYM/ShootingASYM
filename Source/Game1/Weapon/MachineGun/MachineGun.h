/////////////////////////////////////////////////////
// Name : MachineGun
//
// Author : �R�c ����
//
// Day : 2017/7/25
/////////////////////////////////////////////////////
#pragma once

#include <Mouse.h>
#include <d3d11.h>
#include <SimpleMath.h>

#include "../Weapon.h"

namespace Math = DirectX::SimpleMath;

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

	//��������
	void BulletFire(DirectX::Mouse* mouse, Character& character);
	
	//����ł�
	void Fire(Math::Vector2 pos,Math::Vector2 vel, int dir,int bulletCount);

	//����ID
	static WEAPONID id_;

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

	//ID�̎擾
	WEAPONID ID() override;
};

