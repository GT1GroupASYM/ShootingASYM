/////////////////////////////////////////////////////
// Name : PlayScene
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../Scene/Scene.h"

class Player;

/////////////////////////////////////////////////////
// Name : PlayScene
//
// Over View : �v���C�V�[��
/////////////////////////////////////////////////////
class PlayScene:public Scene
{
private:
	std::shared_ptr<Player> player_;

public:
	//�R���X�g���N�^
	PlayScene();

	//�f�X�g���N�^
	~PlayScene();

	//����������
	virtual void Initialize() override;

	//�V�[���؂�ւ�
	std::shared_ptr<Scene> Input() override;
	
	//�X�V����
	void Update() override;

	//�`�揈��
	void Render() override;
};

