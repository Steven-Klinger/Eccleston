#include <windows.h>

//Copié collé d'OPEN CLASSROOM pour créer une fenetre avec WINAPI
LRESULT CALLBACK procedureFenetrePrincipale(HWND, UINT, WPARAM, LPARAM);

int WinMain(HINSTANCE cetteInstance, HINSTANCE precedenteInstance,
	LPSTR lignesDeCommande, int modeDAffichage)
{
	HWND fenetrePrincipale;
	MSG message;
	WNDCLASS classeFenetre;

	classeFenetre.style = 0;
	classeFenetre.lpfnWndProc = procedureFenetrePrincipale;
	classeFenetre.cbClsExtra = 0;
	classeFenetre.cbWndExtra = 0;
	classeFenetre.hInstance = NULL;
	classeFenetre.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	classeFenetre.hCursor = LoadCursor(NULL, IDC_ARROW);
	classeFenetre.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
	classeFenetre.lpszMenuName = NULL;
	classeFenetre.lpszClassName = "classeF";

	// On prévoit quand même le cas où ça échoue
	if (!RegisterClass(&classeFenetre)) return FALSE;

	fenetrePrincipale = CreateWindow("classeF", "Notification Leçon ajoutée!", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
		NULL, NULL, cetteInstance, NULL);
	if (!fenetrePrincipale) return FALSE;

	ShowWindow(fenetrePrincipale, modeDAffichage);
	UpdateWindow(fenetrePrincipale);


	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}

LRESULT CALLBACK procedureFenetrePrincipale(HWND fenetrePrincipale, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(fenetrePrincipale, message, wParam, lParam);
	}
}
