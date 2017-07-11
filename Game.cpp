//
// Game.cpp
//

#include "pch.h"
#include "Game.h"
#include "Source/Game1/Game1.h"

extern void ExitGame();

using namespace DirectX;

using Microsoft::WRL::ComPtr;

Game::Game()
{
    DeviceResources::GetInstance()->RegisterDeviceNotify(this);
}

// Initialize the Direct3D resources required to run.
void Game::Initialize(HWND window, int width, int height)
{
    DeviceResources::GetInstance()->SetWindow(window, width, height);

    DeviceResources::GetInstance()->CreateDeviceResources();
    CreateDeviceDependentResources();

    DeviceResources::GetInstance()->CreateWindowSizeDependentResources();
    CreateWindowSizeDependentResources();

    // TODO: Change the timer settings if you want something other than the default variable timestep mode.
    // e.g. for 60 FPS fixed timestep update logic, call:
    /*
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 60);
    */
	gameMain_.reset(new Game1);
	gameMain_->Initialize();
}

#pragma region Frame Update
// Executes the basic game loop.
void Game::Tick()
{
    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();
}

// Updates the world.
void Game::Update(DX::StepTimer const& timer)
{
    float elapsedTime = float(timer.GetElapsedSeconds());

    // TODO: Add your game logic here.
    elapsedTime;

	gameMain_->Update();
}
#pragma endregion

#pragma region Frame Render
// Draws the scene.
void Game::Render()
{
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    Clear();

    DeviceResources::GetInstance()->PIXBeginEvent(L"Render");
    auto context = DeviceResources::GetInstance()->GetD3DDeviceContext();

    // TODO: Add your rendering code here.
    context;

	gameMain_->Render();

    DeviceResources::GetInstance()->PIXEndEvent();

    // Show the new frame.
    DeviceResources::GetInstance()->Present();
}

// Helper method to clear the back buffers.
void Game::Clear()
{
    DeviceResources::GetInstance()->PIXBeginEvent(L"Clear");

    // Clear the views.
    auto context = DeviceResources::GetInstance()->GetD3DDeviceContext();
    auto renderTarget = DeviceResources::GetInstance()->GetRenderTargetView();
    auto depthStencil = DeviceResources::GetInstance()->GetDepthStencilView();

    context->ClearRenderTargetView(renderTarget, Colors::CornflowerBlue);
    context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    context->OMSetRenderTargets(1, &renderTarget, depthStencil);

    // Set the viewport.
    auto viewport = DeviceResources::GetInstance()->GetScreenViewport();
    context->RSSetViewports(1, &viewport);

    DeviceResources::GetInstance()->PIXEndEvent();
}
#pragma endregion

#pragma region Message Handlers
// Message handlers
void Game::OnActivated()
{
    // TODO: Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: Game is being power-suspended (or minimized).
}

void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    // TODO: Game is being power-resumed (or returning from minimize).
}

void Game::OnWindowSizeChanged(int width, int height)
{
    if (!DeviceResources::GetInstance()->WindowSizeChanged(width, height))
        return;

    CreateWindowSizeDependentResources();

    // TODO: Game window is being resized.
}

// Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: Change to desired default window size (note minimum size is 320x200).
    width = 800;
    height = 600;
}
#pragma endregion

#pragma region Direct3D Resources
// These are the resources that depend on the device.
void Game::CreateDeviceDependentResources()
{
    auto device = DeviceResources::GetInstance()->GetD3DDevice();

    // TODO: Initialize device dependent objects here (independent of window size).
    device;
}

// Allocate all memory resources that change on a window SizeChanged event.
void Game::CreateWindowSizeDependentResources()
{
    // TODO: Initialize windows-size dependent objects here.
}

void Game::OnDeviceLost()
{
    // TODO: Add Direct3D resource cleanup here.
}

void Game::OnDeviceRestored()
{
    CreateDeviceDependentResources();

    CreateWindowSizeDependentResources();
}
#pragma endregion
