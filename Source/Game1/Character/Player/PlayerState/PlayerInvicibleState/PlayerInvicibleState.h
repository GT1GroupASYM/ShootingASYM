/////////////////////////////////////////////////////
// Name : PlayerInvicibleState
//
// Author : �R�c ����
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../PlayerState.h"

/////////////////////////////////////////////////////
// Name : PlayerInvicibleState
//
// Over View : ��e���̖��G���
/////////////////////////////////////////////////////
class PlayerInvicibleState:public PlayerState
{
public:
	PlayerInvicibleState();
	~PlayerInvicibleState();

	std::shared_ptr<PlayerState> Input(Player& player) override;
	void Update(Player& player) override;
};

