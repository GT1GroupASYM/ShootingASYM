/////////////////////////////////////////////////////
// Name : Weapon
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

class Character;

/////////////////////////////////////////////////////
// Name : Bullet
//
// Over View : �e�̊��N���X
/////////////////////////////////////////////////////
class Weapon
{
protected:

	//�R���X�g���N�^
	Weapon();
public:

	//�f�X�g���N�^
	~Weapon();

	//����������
	virtual void Initialize();
	
	//�X�V����
	virtual void Update(Character& character);
	
	//�`�揈��
	virtual void Render();
};

