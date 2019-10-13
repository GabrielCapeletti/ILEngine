#pragma once
#include <windows.h>
#include "ILRenderer.h"

namespace ILEngine
{
	class MainClass : ILRenderer
	{
	public:
		static LPCSTR WindowName;
		static HINSTANCE HInstance;	

		static LRESULT CALLBACK StaticWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		MainClass(LPCSTR windowName, HINSTANCE hInstance);
		~MainClass();
		HRESULT RegisterWindow();
		void Update() override;
		void Render() override;

	private:
		LPCSTR _windowClassName;
		HWND _hWnd;
	};
}
