/////////////////////////////////////////////////////
// Name : Weapon
//
// Author : �R�c ����
//
// Day : 2017/7/25
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

	enum WEAPONID
	{
		NONE,
		MACHINEGUN,
		TWINS
	};

	//���탌�x��
	int level_;

	//���탌�x���̏��
	 static const int maxLevel_ = 3;

	 //�U���͂̃e�[�u��
	 int powerTable_[maxLevel_] =
	 {
		 20,25,50
	 };


	 //�U����
	 int power_;

	//�R���X�g���N�^
	Weapon(int power);
public:

	//�f�X�g���N�^
	~Weapon();

	//����������
	virtual void Initialize();
	
	//�X�V����
	virtual void Update(Character& character);
	
	//�`�揈��
	virtual void Render();

	//���x�����オ��
	virtual void LevelUp();

	//�U���͂̎擾
	int Power();

	//����ID�̎擾
	virtual WEAPONID ID() { return NONE; }
};