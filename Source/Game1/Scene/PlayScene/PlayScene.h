/////////////////////////////////////////////////////
// Name : PlayScene
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../Scene/Scene.h"

class Player;

/////////////////////////////////////////////////////
// Name : PlayScene
//
// Over View : プレイシーン
/////////////////////////////////////////////////////
class PlayScene:public Scene
{
private:
	std::shared_ptr<Player> player_;

public:
	//コンストラクタ
	PlayScene();

	//デストラクタ
	~PlayScene();

	//初期化処理
	virtual void Initialize() override;

	//シーン切り替え
	std::shared_ptr<Scene> Input() override;
	
	//更新処理
	void Update() override;

	//描画処理
	void Render() override;
};

