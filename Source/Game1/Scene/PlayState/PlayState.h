/////////////////////////////////////////////////////
// Name : PlayState
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include "../SceneState/SceneState.h"

/////////////////////////////////////////////////////
// Name : PlayState
//
// Over View : プレイシーン
/////////////////////////////////////////////////////
class PlayState:public SceneState
{
private:

public:
	//コンストラクタ
	PlayState();

	//デストラクタ
	~PlayState();

	//初期化処理
	virtual void Initialize() override;

	//シーン切り替え
	std::shared_ptr<SceneState> Input() override;
	
	//更新処理
	void Update() override;

	//描画処理
	void Render() override;
};

