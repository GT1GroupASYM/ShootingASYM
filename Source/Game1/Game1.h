/////////////////////////////////////////////////////
// Name : Game1
//
// Author : 山田 聖弥
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#pragma once

#include <memory>

#include "../GameBase/GameMain/GameMain.h"

class Sprite;

/////////////////////////////////////////////////////
// Name : Game
//
// Over View : ゲームクラス
/////////////////////////////////////////////////////
class Game1:public GameMain
{
private:
	std::shared_ptr<Sprite> sprite_;

public:
	//コンストラクタ
	Game1();

	//デストラクタ
	~Game1();

	//初期化処理
	void Initialize() override;

	//更新処理
	void Update() override;
	
	//描画処理
	void Render() override;
};

