/////////////////////////////////////////////////////
// Name : PlayState
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../SceneState/SceneState.h"

/////////////////////////////////////////////////////
// Name : PlayState
//
// Over View : �v���C�V�[��
/////////////////////////////////////////////////////
class PlayState:public SceneState
{
private:

public:
	//�R���X�g���N�^
	PlayState();

	//�f�X�g���N�^
	~PlayState();

	//����������
	virtual void Initialize() override;

	//�V�[���؂�ւ�
	std::shared_ptr<SceneState> Input() override;
	
	//�X�V����
	void Update() override;

	//�`�揈��
	void Render() override;
};

