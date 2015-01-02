// GT_HelloWorldWin32.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <iostream>
#include "projResource.h"
#include "ModelEccleston.h"
#include "Admin.h"

using namespace std;

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Win32 Guided Tour Application");

HINSTANCE hInst;

ModelEccleston *model = new ModelEccleston();

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{

	User *us = new User("Klinger", "Steven", "PhantomD", "123", "email@mol.com", model);
	us->checkEmail();
	
	Admin *adm = new Admin("Raphael", "Merkling", "aze", "Desmero", "machin@mail.com", model);
	model->addUser(*adm);
	
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance; // Store instance handle in our global variable

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// 500, 100: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 450,
		NULL,
		NULL,
		hInstance,
		NULL
		);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND boutonsLogin[2] = { NULL };
	static HWND labelLogin[2] = { NULL };
	static HWND textLogin[2] = { NULL };

	switch (message)
	{
	case WM_CREATE:
		boutonsLogin[0] = CreateWindow("button", "Connexion", WS_CHILD | WS_VISIBLE, 50, 150, 80, 30, hWnd, (HMENU) ID_B_CONNECT, hInst, NULL);
		boutonsLogin[1] = CreateWindow("button", "Quitter", WS_CHILD | WS_VISIBLE, 250, 150, 80, 30, hWnd, (HMENU) ID_FILE_EXIT, hInst, NULL);
		labelLogin[0] = CreateWindow("static", "Login :", WS_CHILD | WS_VISIBLE, 50, 50, 80, 30, hWnd, NULL, hInst, NULL);
		labelLogin[1] = CreateWindow("static", "Mot de passe :", WS_CHILD | WS_VISIBLE, 50, 100, 100, 30, hWnd, NULL, hInst, NULL);
		textLogin[0] = CreateWindow("EDIT", "ici", WS_CHILD | WS_VISIBLE, 250, 50, 80, 30, hWnd, NULL, hInst, NULL);
		textLogin[1] = CreateWindow("EDIT", "ici", WS_CHILD | WS_VISIBLE, 250, 100, 80, 30, hWnd, NULL, hInst, NULL);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_B_CONNECT:
		{
			if (model->checkLogin("Desmero", "aze")) {
				MessageBox(hWnd, "Vous alez etre conneccté", "Woo!", MB_OK);
			}
			break;
		}
		case ID_FILE_EXIT:
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			break;
		case ID_STUFF_GO:
			MessageBox(hWnd, "You clicked Go!", "Woo!", MB_OK);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}
