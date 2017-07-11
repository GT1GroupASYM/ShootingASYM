/////////////////////////////////////////////////////
// Name : InputManager
//
// Author : 山田 聖弥
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#include "../../../pch.h"
#include "InputManager.h"
#include "../../../DeviceResources.h"

using namespace Math;

/////////////////////////////////////////////////////
// Name : InputManager
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
InputManager::InputManager()
{
	key_.reset(new DirectX::Keyboard);
	keyTracker_.reset(new DirectX::Keyboard::KeyboardStateTracker);

	mouse_.reset(new DirectX::Mouse);
	mouseTracker_.reset(new DirectX::Mouse::ButtonStateTracker);
}

/////////////////////////////////////////////////////
// Name : ~InputManager
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
InputManager::~InputManager()
{
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
void InputManager::Initialize()
{
	mouse_->SetMode(DirectX::Mouse::MODE_ABSOLUTE);
	Window(DeviceResources::GetInstance()->GetWindow());
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : 更新処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void InputManager::Update()
{
	keyTracker_->Update(key_->GetState());
	mouseTracker_->Update(mouse_->GetState());

	if (mouse_->GetState().x > 0)
	{
		int a = 0;
	}
}

/////////////////////////////////////////////////////
// Name : Window
//
// Over View : Windowの設定
//
// Argument : Window
//
// Return : 無し
/////////////////////////////////////////////////////
void InputManager::Window(HWND window)
{
	mouse_->SetWindow(window);
}

/////////////////////////////////////////////////////
// Name : KeyInput
//
// Over View : 指定したキーが押されてるか
//
// Argument : 判定したいキー
//
// Return : 無し
/////////////////////////////////////////////////////
bool InputManager::KeyInput(DirectX::Keyboard::Keys key)
{
	if (key_->GetState().IsKeyDown(key))
	{
		return true;
	}

	return false;
}

DirectX::Mouse::ButtonStateTracker* InputManager::MouseTacker()
{
	return mouseTracker_.get();
}

/////////////////////////////////////////////////////
// Name : MousePos
//
// Over View : マウスの座標の取得
//
// Argument : 無し
//
// Return : マウスの座標
/////////////////////////////////////////////////////
Math::Vector2 InputManager::MousePos()
{
	auto pos = Vector2(mouse_->GetState().x, mouse_->GetState().y);

	return pos;
}
