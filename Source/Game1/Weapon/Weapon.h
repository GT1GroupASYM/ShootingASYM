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
	//���탌�x��
	int level_;

	//���탌�x���̏��
	 const int maxLevel_ = 3;

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
};