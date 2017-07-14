/////////////////////////////////////////////////////
// Name : PlayerInvicibleState
//
// Author : R“c ¹–í
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../PlayerState.h"

/////////////////////////////////////////////////////
// Name : PlayerInvicibleState
//
// Over View : ”í’e‚Ì–³“Gó‘Ô
/////////////////////////////////////////////////////
class PlayerInvicibleState:public PlayerState
{
public:
	PlayerInvicibleState();
	~PlayerInvicibleState();

	std::shared_ptr<PlayerState> Input(Player& player) override;
	void Update(Player& player) override;
};

