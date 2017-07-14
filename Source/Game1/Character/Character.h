/////////////////////////////////////////////////////
// Name : Character
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
// Name : Character
//
// Over View : キャラクターの基底ラス
/////////////////////////////////////////////////////
class Character
{
protected:
	std::shared_ptr<Sprite> sprite_;

	//移動方向
	Math::Vector2 vel_;

	//移動速度
	float moveSpeed_;

public:
	//コンストラクタ
	Character(wchar_t* texturePass);

	//デストラクタ
	virtual ~Character();

	//初期化処理
	virtual void Initialize();
	
	//更新処理
	virtual void Update();
	
	//描画処理
	virtual void Render();
};