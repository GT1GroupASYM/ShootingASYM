/////////////////////////////////////////////////////
// Name : Scene
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include <memory>

/////////////////////////////////////////////////////
// Name : Scene
//
// Over View : シーンの基底クラス
/////////////////////////////////////////////////////
class Scene
{
private:

public:
	//コンストラクタ
	Scene();

	//デストラクタ
	virtual ~Scene();

	//初期化処理
	virtual void Initialize();

	//次のシーンの取得
	virtual std::shared_ptr<Scene> Input();
	
	//更新処理
	virtual void Update();

	//描画処理
	virtual void Render();
};

