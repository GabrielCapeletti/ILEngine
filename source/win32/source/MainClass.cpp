// ReSharper disable CppMemberFunctionMayBeStatic
#include "../header/MainClass.h"

namespace ILEngine
{
	ILEngine::MainClass::MainClass(LPCSTR windowName, HINSTANCE hInstance)
	{
		WindowName = windowName;
		HInstance = hInstance;

		_windowClassName = "Direct3DWindowClass";
	}

	MainClass::~MainClass()
	{

	}

	// ReSharper disable CppMemberFunctionMayBeConst
	LRESULT CALLBACK MainClass::StaticWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	// ReSharper restore CppMemberFunctionMayBeConst
	{
		switch (uMsg)
		{
		case WM_CLOSE:
		{
			const HMENU hMenu = GetMenu(hWnd);
			if (hMenu != nullptr)
			{
				DestroyMenu(hMenu);
			}
			DestroyWindow(hWnd);
			UnregisterClass(
				MainClass::WindowName,
				MainClass::HInstance
			);
			return 0;
		}

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}

		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	HRESULT MainClass::RegisterWindow()
	{
		HICON hIcon = nullptr;	
		CHAR szExePath[MAX_PATH];
		GetModuleFileName(nullptr, szExePath, MAX_PATH);

		// If the icon is NULL, then use the first one found in the exe
		if (hIcon == nullptr)
			hIcon = ExtractIcon(HInstance, szExePath, 0);

		// Register the windows class
		WNDCLASS wndClass;
		wndClass.style = CS_DBLCLKS;
		wndClass.lpfnWndProc = StaticWindowProc;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hInstance = HInstance;
		wndClass.hIcon = hIcon;
		wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
		wndClass.lpszMenuName = nullptr;
		wndClass.lpszClassName = WindowName;

		if (!RegisterClass(&wndClass))
		{
			const DWORD dwError = GetLastError();
			if (dwError != ERROR_CLASS_ALREADY_EXISTS)
				return HRESULT_FROM_WIN32(dwError);
		}

		LPRECT rect = new tagRECT();

		int x = CW_USEDEFAULT;
		int y = CW_USEDEFAULT;
		int width = 640;
		int height = 480;

		SetRect(rect, 0, 0, width, height);
		AdjustWindowRect(
			rect,
			WS_OVERLAPPEDWINDOW,
			false
		);

		const HMENU hMenu = nullptr;

		// Create the window for our viewport.
		_hWnd = CreateWindow(
			_windowClassName,
			WindowName,
			WS_OVERLAPPEDWINDOW,
			x, y,
			(rect->right- rect->left), (rect->bottom - rect->top),
			nullptr,
			hMenu,
			HInstance,
			nullptr
		);

		if (_hWnd == nullptr)
		{
			const DWORD dwError = GetLastError();
			return HRESULT_FROM_WIN32(dwError);
		}

		return 0;
	}

	void MainClass::Update()
	{
		
	}

	void MainClass::Render()
	{

	}
}
