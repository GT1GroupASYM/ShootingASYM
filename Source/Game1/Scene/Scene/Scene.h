/////////////////////////////////////////////////////
// Name : Scene
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include <memory>

/////////////////////////////////////////////////////
// Name : Scene
//
// Over View : �V�[���̊��N���X
/////////////////////////////////////////////////////
class Scene
{
private:

public:
	//�R���X�g���N�^
	Scene();

	//�f�X�g���N�^
	virtual ~Scene();

	//����������
	virtual void Initialize();

	//���̃V�[���̎擾
	virtual std::shared_ptr<Scene> Input();
	
	//�X�V����
	virtual void Update();

	//�`�揈��
	virtual void Render();
};

