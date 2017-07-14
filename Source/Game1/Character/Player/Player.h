/////////////////////////////////////////////////////
// Name : Player
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../Character.h"

class PlayerState;

/////////////////////////////////////////////////////
// Name : Player
//
// Over View : �v���C���[�N���X
/////////////////////////////////////////////////////
class Player :public Character
{
private:
	std::shared_ptr<PlayerState> state_;

public:
	//�R���X�g���N�^
	Player(wchar_t* texturePass);

	//�f�X�g���N�^
	~Player();

	//����������
	void Initialize() override;

	//�X�V����
	void Update() override;

	//�`�揈��
	void Render() override;
};

