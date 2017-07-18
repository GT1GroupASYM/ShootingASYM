/////////////////////////////////////////////////////
// Name : Bullet
//
// Author : 山田 聖弥
//
// Day : 2017/7/14
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <d3d11.h>
#include <SimpleMath.h>

class Sprite;

namespace Math = DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : Bullet
//
// Over View : 弾の基底クラス
/////////////////////////////////////////////////////
class Bullet
{
protected:
	std::shared_ptr<Sprite> sprite_;

	//移動方向
	Math::Vector2 vel_;

	//移動速度
	float moveSpeed_;

	//攻撃力
	int power_;

public:
	Bullet();
	virtual ~Bullet();

	//初期化処理
	virtual void Initialize(Math::Vector2 pos,Math::Vector2 vel,int power);
	
	//更新処理
	virtual void Update();
	
	//描画処理
	virtual void Render();

	//大きさの取得と設定
	void Scale(float scale);
	float Scale();
};
