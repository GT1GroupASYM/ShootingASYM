/////////////////////////////////////////////////////
// Name : Game1
//
// Author : �R�c ����
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#pragma once

#include <memory>

#include "../GameBase/GameMain/GameMain.h"

class Scene;

/////////////////////////////////////////////////////
// Name : Game
//
// Over View : �Q�[���N���X
/////////////////////////////////////////////////////
class Game1:public GameMain
{
private:
	std::shared_ptr<Scene> scene_;

public:
	//�R���X�g���N�^
	Game1();

	//�f�X�g���N�^
	~Game1();

	//����������
	void Initialize() override;

	//�X�V����
	void Update() override;
	
	//�`�揈��
	void Render() override;
};

