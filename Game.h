//
// Game.h
//

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"

class GameMain;


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game : public IDeviceNotify
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    // Rendering loop timer.
    DX::StepTimer                           m_timer;

	std::shared_ptr<GameMain> gameMain_;
};