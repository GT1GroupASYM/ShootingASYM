/////////////////////////////////////////////////////
// Name : SceneState
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include <memory>

/////////////////////////////////////////////////////
// Name : SceneState
//
// Over View : シーンの基底クラス
/////////////////////////////////////////////////////
class SceneState
{
private:

public:
	//コンストラクタ
	SceneState();

	//デストラクタ
	virtual ~SceneState();

	//初期化処理
	virtual void Initialize();

	//次のシーンの取得
	virtual std::shared_ptr<SceneState> Input();
	
	//更新処理
	virtual void Update();

	//描画処理
	virtual void Render();
};

