#include <windows.h>
#include <memory>
#include "../header/MainClass.h"

namespace ILEngine
{
	INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
	{
		if (hInstance == nullptr)
			hInstance = static_cast<HINSTANCE>(GetModuleHandle(nullptr));

		std::shared_ptr<ILEngine::MainClass> winMain = std::make_shared<MainClass>("DirectXWindow", hInstance);

		return winMain.get()->RegisterWindow();
	}
}

