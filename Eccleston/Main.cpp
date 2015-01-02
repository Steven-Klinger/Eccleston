#include <windows.h>

#include "resource.h" 
#include "ModelEccleston.h"
#include "User.h"
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"

ModelEccleston* model;
HINSTANCE hInst;

BOOL CALLBACK DlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_INITDIALOG:
	{
						  // This is where we set up the dialog box, and initialise any default values
						  string fullName = model->getCurrentUser().getFirstName() + " " + model->getCurrentUser().getName() + " : ";
						  switch (model->getCurrentUser().getUserType())
						  {
						  case 0: {
									  fullName.append(" : Administrateur");
									  break;
						  }
						  case 1: {
									  fullName.append(" : Professeur");
									  break;
						  }
						  case 2: {
									  fullName.append(" : Étudiant");
									  break;
						  }
						  default:{
									  fullName.append(" : Erreur");
									  break;
						  }
						  }
						  SetDlgItemText(hwnd, IDC_STATIC_USERNAME, fullName.c_str());
						  break;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_CONNECT:
		{
							int len = GetWindowTextLength(GetDlgItem(hwnd, IDC_TEXT_LOGIN));
							string login, passW;
							if (len > 0) {
								char* buf;
								buf = (char*)GlobalAlloc(GPTR, len + 1);
								GetDlgItemText(hwnd, IDC_TEXT_LOGIN, buf, len + 1);
								login = buf;
							}
							len = GetWindowTextLength(GetDlgItem(hwnd, IDC_TEXT_PASSW));
							if (len > 0) {
								char* buf;
								buf = (char*)GlobalAlloc(GPTR, len + 1);
								GetDlgItemText(hwnd, IDC_TEXT_PASSW, buf, len + 1);
								passW = buf;
							}
							if (model->checkLogin(login, passW)) {
								User user = model->getUserByLogin(login);
								model->setCurrentUser(user);
								PostMessage(hwnd, WM_CLOSE, 0, 0);
								int val = user.getUserType();
								string msg = "Bienvenue " + user.getFirstName();
								MessageBox(hwnd, msg.c_str(), "Connection", MB_OK);
								switch (val)
								{
								case 0:{
										   return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_ADMIN), NULL, DlgProc);
								}
								case 1:{
										   return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_TEACHER), NULL, DlgProc);
								}
								case 2:{
										   return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_STUDENT), NULL, DlgProc);
								}
								default:{
											MessageBox(hwnd, "Problème d'héritage et de méthode virtuelle ", "Connection", MB_OK);
											return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_ADMIN), NULL, DlgProc);
								}
								}
							}
							else {
								MessageBox(hwnd, "Login ou mot de passe incorrecte", "Connection", MB_OK);
							}
		}
			break;
		case IDC_DECONNECT:
			PostMessage(hwnd, WM_CLOSE, 0, 0);
			return DialogBox(hInst, MAKEINTRESOURCE(IDD_CONNEXION), NULL, DlgProc);
		case IDC_EXIT:
			PostMessage(hwnd, WM_CLOSE, 0, 0);
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	default:
		return FALSE;
	}
	return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	hInst = hInstance;
	model = new ModelEccleston();
	model->addUser(Admin("Raphael", "Merkling", "aze", "Desmero", "plop@mail.fr", model));
	model->addUser(Teacher("Erwan", "Mellinger", "aze", "Erwan", "mel@mail.com", model));
	model->addUser(Student("Steven", "Klinger", "aze", "PhantomD", "kli@mail.de", model));
	model->addUser(Student("Nicolas", "Anduze", "aze", "Mandra", "and@mail.net", model));

	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_CONNEXION), NULL, DlgProc);
}
