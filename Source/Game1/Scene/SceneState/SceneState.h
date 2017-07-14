/////////////////////////////////////////////////////
// Name : SceneState
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include <memory>

/////////////////////////////////////////////////////
// Name : SceneState
//
// Over View : �V�[���̊��N���X
/////////////////////////////////////////////////////
class SceneState
{
private:

public:
	//�R���X�g���N�^
	SceneState();

	//�f�X�g���N�^
	virtual ~SceneState();

	//����������
	virtual void Initialize();

	//���̃V�[���̎擾
	virtual std::shared_ptr<SceneState> Input();
	
	//�X�V����
	virtual void Update();

	//�`�揈��
	virtual void Render();
};

