/////////////////////////////////////////////////////
// Name : SpriteManager
//
// Author : 山田 聖弥
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#include "../../../../pch.h"

#include <WICTextureLoader.h>

#include "../../../../DeviceResources.h"
#include "SpriteManager.h"


/////////////////////////////////////////////////////
// Name : SpriteManager
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
SpriteManager::SpriteManager()
	:commonState_(nullptr)
{
	auto device = DeviceResources::GetInstance()->GetD3DDevice();
	auto context = DeviceResources::GetInstance()->GetD3DDeviceContext();

	spriteBatch_.reset(new DirectX::SpriteBatch(context));
	commonState_.reset(new DirectX::CommonStates(device));
}

/////////////////////////////////////////////////////
// Name : SpriteManager
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
SpriteManager::~SpriteManager()
{
	for(auto it = shaderResourceViewPool_.begin();it!=shaderResourceViewPool_.end();it++)
	{
		it->second->Release();
	}

	shaderResourceViewPool_.clear();
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void SpriteManager::Initialize()
{
}

/////////////////////////////////////////////////////
// Name : LoadTexture
//
// Over View : 画像の読み込み
//
// Argument : 画像のパス
//
// Return : 画像のポインタ
/////////////////////////////////////////////////////
ID3D11ShaderResourceView* SpriteManager::LoadTexture(wchar_t* pass,RECT& rect)
{
	//読み込んだことがなかったら読み込み
	if (shaderResourceViewPool_.count(pass) <= 0)
	{
		auto device = DeviceResources::GetInstance()->GetD3DDevice();
		ID3D11ShaderResourceView* shaderResourceView;
		ID3D11Resource* resource;

		//画像の読み込み
		DirectX::CreateWICTextureFromFile(device, pass, &resource, &shaderResourceView);

		//画像サイズの取得
		auto texture = static_cast<ID3D11Texture2D*>(resource);
		D3D11_TEXTURE2D_DESC desc;
		texture->GetDesc(&desc);
		rect.top = 0;
		rect.left = 0;
		rect.bottom = desc.Height;
		rect.right = desc.Width;

		resource->Release();

		shaderResourceViewPool_[pass] = shaderResourceView;
	}
	
	return shaderResourceViewPool_[pass];
}

/////////////////////////////////////////////////////
// Name : SpriteBatch
//
// Over View : SpriteBatchの取得
//
// Argument : 無し
//
// Return : SpriteBatch
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::SpriteBatch> SpriteManager::SpriteBatch()
{
	return spriteBatch_;
}

/////////////////////////////////////////////////////
// Name : CommonState
//
// Over View : CommonStateの取得
//
// Argument : 無し
//
// Return : CommonState
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::CommonStates> SpriteManager::CommonState()
{
	return commonState_;
}