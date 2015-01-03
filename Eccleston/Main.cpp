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
						  int type = model->getCurrentUserType();
						  //int type = model->getCurrentUser().getUserType();
						  string fullName;
						  switch (type)
						  {
						  case 0: {
									  Admin* admin = model->getCurrentAdmin();
									  fullName.append(admin->getFirstName() + " " + admin->getName() + " : Administrateur");
									  for (Lesson* les : model->getWaitingLessons()) {
										  string name = les->getName();
										  int index = SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_ADDSTRING, 0, (LPARAM)name.c_str());
										  SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  }
									  break;
						  }
						  case 1: {
									  Teacher* teacher = model->getCurrentTeacher();
									  fullName.append(teacher->getFirstName() + " " + teacher->getName() + " : Professeur");
									  for (Lesson* les : teacher->getLessons()) {
										  string name = les->getName();
										  int index = SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_ADDSTRING, 0, (LPARAM)name.c_str());
										  SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  }
									  break;
						  }
						  case 2: {
									  Student* student = model->getCurrentStudent();
									  fullName.append(student->getFirstName() + " " + student->getName() + " : Étudiant");
									  for (Lesson* les : student->getLessons()) {
										  string name = les->getName();
										  int index = SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_ADDSTRING, 0, (LPARAM)name.c_str());
										  SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  }
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
								GlobalFree((HANDLE)buf);
							}
							len = GetWindowTextLength(GetDlgItem(hwnd, IDC_TEXT_PASSW));
							if (len > 0) {
								char* buf;
								buf = (char*)GlobalAlloc(GPTR, len + 1);
								GetDlgItemText(hwnd, IDC_TEXT_PASSW, buf, len + 1);
								passW = buf;
								GlobalFree((HANDLE)buf);
							}
							if (model->checkLogin(login, passW)) {
								User* user = model->getUserByLogin(login);
								int userType = user->getUserType();
								PostMessage(hwnd, WM_CLOSE, 0, 0);
								string msg = "Bienvenue " + user->getFirstName();
								MessageBox(hwnd, msg.c_str(), "Connection", MB_OK);
								switch (userType)
								{
								case 0:{
										   Admin* admin = model->getAdminByLogin(login);
										   model->setCurrentUser(admin);
										   return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_ADMIN), NULL, DlgProc);
								}
								case 1:{
										   Teacher* teacher = model->getTeacherByLogin(login);
										   model->setCurrentUser(teacher);
										   return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_TEACHER), NULL, DlgProc);
								}
								case 2:{
										   Student* student = model->getStudentByLogin(login);
										   model->setCurrentUser(student);
										   return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_STUDENT), NULL, DlgProc);
								}
								default:{
											MessageBox(hwnd, "Problème de connexion : vôtre compte est corrompue", "Connection", MB_OK);
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
	
	Admin* Raphael = new Admin("Raphael", "Merkling", "aze", "Desmero", "plop@mail.fr", model);
	Teacher* Erwan = new Teacher("Erwan", "Mellinger", "aze", "Erwan", "mel@mail.com", model);
	Student* Steven = new Student("Steven", "Klinger", "aze", "PhantomD", "kli@mail.de", model);
	Student* Nicolas = new Student("Nicolas", "Anduze", "aze", "Mandra", "and@mail.net", model);

	Lesson* CPOA = new Lesson("CPOA", Erwan, 50);
	Lesson* toucan = new Lesson("Toucan", Erwan, 50);
	Lesson* Algo = new Lesson("Algo", Erwan, 50);
	toucan->setValidate(1);

	Nicolas->addLesson(toucan);
	Steven->addLesson(CPOA);

	model->addUser(Raphael);
	model->addUser(Erwan);
	model->addUser(Steven);
	model->addUser(Nicolas);

	model->addLesson(CPOA);
	model->addLesson(Algo);
	model->addLesson(toucan);

	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_CONNEXION), NULL, DlgProc);
}
