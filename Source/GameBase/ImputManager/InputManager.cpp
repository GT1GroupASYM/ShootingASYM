/////////////////////////////////////////////////////
// Name : InputManager
//
// Author : �R�c ����
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
// Over View : �R���X�g���N�^
//
// Argument : ����
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
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
InputManager::~InputManager()
{
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
void InputManager::Initialize()
{
	mouse_->SetMode(DirectX::Mouse::MODE_ABSOLUTE);
	Window(DeviceResources::GetInstance()->GetWindow());
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �X�V����
//
// Argument : ����
//
// Return : ����
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
// Over View : Window�̐ݒ�
//
// Argument : Window
//
// Return : ����
/////////////////////////////////////////////////////
void InputManager::Window(HWND window)
{
	mouse_->SetWindow(window);
}

/////////////////////////////////////////////////////
// Name : KeyInput
//
// Over View : �w�肵���L�[��������Ă邩
//
// Argument : ���肵�����L�[
//
// Return : ����
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
// Over View : �}�E�X�̍��W�̎擾
//
// Argument : ����
//
// Return : �}�E�X�̍��W
/////////////////////////////////////////////////////
Math::Vector2 InputManager::MousePos()
{
	auto pos = Vector2(mouse_->GetState().x, mouse_->GetState().y);

	return pos;
}
