/////////////////////////////////////////////////////
// Name : SpriteManager
//
// Author : �R�c ����
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
// Over View : �R���X�g���N�^
//
// Argument : ����
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
// Over View : �f�X�g���N�^
//
// Argument : ����
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
// Over View : ����������
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void SpriteManager::Initialize()
{
}

/////////////////////////////////////////////////////
// Name : LoadTexture
//
// Over View : �摜�̓ǂݍ���
//
// Argument : �摜�̃p�X
//
// Return : �摜�̃|�C���^
/////////////////////////////////////////////////////
ID3D11ShaderResourceView* SpriteManager::LoadTexture(wchar_t* pass,RECT& rect)
{
	//�ǂݍ��񂾂��Ƃ��Ȃ�������ǂݍ���
	if (shaderResourceViewPool_.count(pass) <= 0)
	{
		auto device = DeviceResources::GetInstance()->GetD3DDevice();
		ID3D11ShaderResourceView* shaderResourceView;
		ID3D11Resource* resource;

		//�摜�̓ǂݍ���
		DirectX::CreateWICTextureFromFile(device, pass, &resource, &shaderResourceView);

		//�摜�T�C�Y�̎擾
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
// Over View : SpriteBatch�̎擾
//
// Argument : ����
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
// Over View : CommonState�̎擾
//
// Argument : ����
//
// Return : CommonState
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::CommonStates> SpriteManager::CommonState()
{
	return commonState_;
}