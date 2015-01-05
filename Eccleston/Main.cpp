#include <windows.h>
#include <string>
#include <sstream>

#include "resource.h" 
#include "ModelEccleston.h"
#include "User.h"
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"
#include "ResourceFile.h"

ModelEccleston* model;
HINSTANCE hInst;

BOOL CALLBACK DlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_INITDIALOG:
	{
						  int type = model->getCurrentUserType();
						  string fullName;
						  switch (type)
						  {
						  case 0: {
									  int index;
									  string header;
									  Admin* admin = model->getCurrentAdmin();
									  fullName.append(admin->getFirstName() + " " + admin->getName() + " : Administrateur");
									  header = "Cours en attente de validation";
									  index = SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_ADDSTRING, 0, (LPARAM)header.c_str());
									  SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  for (Lesson* les : model->getWaitingLessons()) {
										  string name = les->getName();
										  name.append("; ");
										  name.append(les->getTeacher()->getName());
										  name.append("; ");
										  name.append(std::to_string(les->getMaxStudents()));
										  index = SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_ADDSTRING, 0, (LPARAM)name.c_str());
										  SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  }
									  header = "Administrateurs";
									  index = SendDlgItemMessage(hwnd, IDC_LIST_ADMIN, LB_ADDSTRING, 0, (LPARAM)header.c_str());
									  SendDlgItemMessage(hwnd, IDC_LIST_ADMIN, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  for (Admin* user : model->getAdmins()) {
										  string name = user->getName();
										  name.append("; ");
										  name.append(user->getFirstName());
										  name.append("; ");
										  name.append(user->getLogin());
										  name.append("; ");
										  name.append(user->getPassword());
										  index = SendDlgItemMessage(hwnd, IDC_LIST_ADMIN, LB_ADDSTRING, 0, (LPARAM)name.c_str());
										  SendDlgItemMessage(hwnd, IDC_LIST_ADMIN, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  }
									  header = "Professeurs";
									  index = SendDlgItemMessage(hwnd, IDC_LIST_TEACHER, LB_ADDSTRING, 0, (LPARAM)header.c_str());
									  SendDlgItemMessage(hwnd, IDC_LIST_TEACHER, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  for (Teacher* user : model->getTeachers()) {
										  string name = user->getName();
										  name.append("; ");
										  name.append(user->getFirstName());
										  name.append("; ");
										  name.append(user->getLogin());
										  name.append("; ");
										  name.append(user->getPassword());
										  index = SendDlgItemMessage(hwnd, IDC_LIST_TEACHER, LB_ADDSTRING, 0, (LPARAM)name.c_str());
										  SendDlgItemMessage(hwnd, IDC_LIST_TEACHER, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  }
									  header = "Étudiants";
									  index = SendDlgItemMessage(hwnd, IDC_LIST_STUDENT, LB_ADDSTRING, 0, (LPARAM)header.c_str());
									  SendDlgItemMessage(hwnd, IDC_LIST_STUDENT, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  for (Student* user : model->getStudents()) {
										  string name = user->getName();
										  name.append("; ");
										  name.append(user->getFirstName());
										  name.append("; ");
										  name.append(user->getLogin());
										  name.append("; ");
										  name.append(user->getPassword());
										  int index = SendDlgItemMessage(hwnd, IDC_LIST_STUDENT, LB_ADDSTRING, 0, (LPARAM)name.c_str());
										  SendDlgItemMessage(hwnd, IDC_LIST_STUDENT, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  }
									  break;
						  }
						  case 1: {
									  Teacher* teacher = model->getCurrentTeacher();
									  fullName.append(teacher->getFirstName() + " " + teacher->getName() + " : Professeur");
									  for (Lesson* les : teacher->getLessons()) {
										  stringstream streamName;
										  streamName << les->getName() << "; " << les->getMaxStudents() << "; " << les->getNumbreStudent();
										  string name = streamName.str();
										  if (!les->isValidated()){
											  name.append("; En attenter de validation");
										  }
										  int index = SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_ADDSTRING, 0, (LPARAM)name.c_str());
										  SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
									  }
									  /*									  for (ResourceFile* res : teacher->getLesson(0)->getResourceFiles()) {
																				string name = res->getName();
																				int index = SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_ADDSTRING, 0, (LPARAM)name.c_str());
																				SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
																				}
																				*/
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
									  /*									  for (ResourceFile* res : student->getLesson(0)->getResourceFiles()) {
																				string name = res->getName();
																				int index = SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_ADDSTRING, 0, (LPARAM)name.c_str());
																				SendDlgItemMessage(hwnd, IDC_LIST_LESSON, LB_SETITEMDATA, (WPARAM)index, (LPARAM)1);
																				}
																				*/
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
		case IDC_BUTTON_CONNECT:
		{
								   int len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_LOGIN));
								   string login, passW;
								   if (len > 0) {
									   char* buf;
									   buf = (char*)GlobalAlloc(GPTR, len + 1);
									   GetDlgItemText(hwnd, IDC_EDIT_LOGIN, buf, len + 1);
									   login = buf;
									   GlobalFree((HANDLE)buf);
								   }
								   len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_PASSW));
								   if (len > 0) {
									   char* buf;
									   buf = (char*)GlobalAlloc(GPTR, len + 1);
									   GetDlgItemText(hwnd, IDC_EDIT_PASSW, buf, len + 1);
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
												  break;
									   }
									   case 1:{
												  Teacher* teacher = model->getTeacherByLogin(login);
												  model->setCurrentUser(teacher);
												  return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_TEACHER), NULL, DlgProc);
												  break;
									   }
									   case 2:{
												  Student* student = model->getStudentByLogin(login);
												  model->setCurrentUser(student);
												  return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_STUDENT), NULL, DlgProc);
												  break;
									   }
									   default:{
												   MessageBox(hwnd, "Problème de connexion : vôtre compte est corrompue", "Connection", MB_OK);
									   }
									   }
								   }
								   else {
									   MessageBox(hwnd, "Login ou mot de passe incorrect", "Connection", MB_OK);
								   }
		}
			break;
		case IDC_BUTTON_LESSON:
		{
								  PostMessage(hwnd, WM_CLOSE, 0, 0);
								  int userType = model->getCurrentUserType();
								  switch (userType)
								  {
								  case 1: {
											  return DialogBox(hInst, MAKEINTRESOURCE(IDD_LESSON_TEACHER), NULL, DlgProc);
											  break;
								  }
								  case 2: {
											  return DialogBox(hInst, MAKEINTRESOURCE(IDD_LESSON_STUDENT), NULL, DlgProc);
											  break;
								  }
								  }
								  break;
		}
		case IDC_BUTTON_MAIN:
		{
								PostMessage(hwnd, WM_CLOSE, 0, 0);
								int userType = model->getCurrentUserType();
								switch (userType)
								{
								case 0: {
											return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_ADMIN), NULL, DlgProc);
											break;
								}
								case 1: {
											return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_TEACHER), NULL, DlgProc);
											break;
								}
								case 2: {
											return DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN_STUDENT), NULL, DlgProc);
											break;
								}
								}
								break;

		}
		case IDC_BUTTON_VALIDLESSON:
		{
									   HWND hList = GetDlgItem(hwnd, IDC_LIST_LESSON);
									   int count = SendMessage(hList, LB_GETSELCOUNT, 0, 0);
									   if (count != LB_ERR)
									   {
										   int i;
										   int *buf = (int*)GlobalAlloc(GPTR, sizeof(int)* count);
										   SendMessage(hList, LB_GETSELITEMS, (WPARAM)count, (LPARAM)buf);
										   for (i = count - 1; i >= 0; i--)
										   {
											   if (buf[i] != 0){
												   model->getWaitingLessons().at(buf[i] - 1)->setValidate(1);
												   SendMessage(hList, LB_DELETESTRING, (WPARAM)buf[i], 0);
											   }
										   }
										   GlobalFree(buf);
									   }
									   else
									   {
										   MessageBox(hwnd, "Error counting items :(", "Warning", MB_OK);
									   }
									   break;
		}
		case IDC_BUTTON_ADDUSER:
		{
								   return DialogBox(hInst, MAKEINTRESOURCE(IDD_ADDUSER), NULL, DlgProc);
								   break;
		}
		case IDC_BUTTON_ADDUSER_VALIDATE:
		{
											int dataValide = 1;
											string name;
											int len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDUSER_NAME));
											if (len > 0) {
												char* buf;
												buf = (char*)GlobalAlloc(GPTR, len + 1);
												GetDlgItemText(hwnd, IDC_EDIT_ADDUSER_NAME, buf, len + 1);
												name = buf;
												GlobalFree((HANDLE)buf);
											}
											else {
												dataValide = 0;
												MessageBox(hwnd, "Le champ Nom n'est pas remplit", "Erreur", MB_OK);
											}
											string firstName;
											len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDUSER_FIRSTNAME));
											if (len > 0) {
												char* buf;
												buf = (char*)GlobalAlloc(GPTR, len + 1);
												GetDlgItemText(hwnd, IDC_EDIT_ADDUSER_FIRSTNAME, buf, len + 1);
												firstName = buf;
												GlobalFree((HANDLE)buf);
											}
											else {
												dataValide = 0;
												MessageBox(hwnd, "Le champ Prenom n'est pas remplit", "Erreur", MB_OK);
											}
											string eMail;
											len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDUSER_EMAIL));
											if (len > 0) {
												char* buf;
												buf = (char*)GlobalAlloc(GPTR, len + 1);
												GetDlgItemText(hwnd, IDC_EDIT_ADDUSER_EMAIL, buf, len + 1);
												eMail = buf;
												GlobalFree((HANDLE)buf);
											}
											else {
												dataValide = 0;
												MessageBox(hwnd, "Le champ eMail n'est pas remplit", "Erreur", MB_OK);
											}
											string login;
											len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDUSER_LOGIN));
											if (len > 0) {
												char* buf;
												buf = (char*)GlobalAlloc(GPTR, len + 1);
												GetDlgItemText(hwnd, IDC_EDIT_ADDUSER_LOGIN, buf, len + 1);
												login = buf;
												GlobalFree((HANDLE)buf);
											}
											else {
												dataValide = 0;
												MessageBox(hwnd, "Le champ Login n'est pas remplit", "Erreur", MB_OK);
											}
											string passWord;
											len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDUSER_PASSWORD));
											if (len > 0) {
												char* buf;
												buf = (char*)GlobalAlloc(GPTR, len + 1);
												GetDlgItemText(hwnd, IDC_EDIT_ADDUSER_PASSWORD, buf, len + 1);
												passWord = buf;
												GlobalFree((HANDLE)buf);
											}
											else {
												dataValide = 0;
												MessageBox(hwnd, "Le champ Mot de passe n'est pas remplit", "Erreur", MB_OK);
											}
											if (dataValide) {
												if (IsDlgButtonChecked(hwnd, IDC_RADIO_ADDUSER_ADMIN)) {
													Admin* adm = new Admin(name, firstName, passWord, login, eMail, model);
													model->addUser(adm);
													PostMessage(hwnd, WM_CLOSE, 0, 0);
												}
												else if (IsDlgButtonChecked(hwnd, IDC_RADIO_ADDUSER_TEACH)) {
													Teacher* adm = new Teacher(name, firstName, passWord, login, eMail, model);
													model->addUser(adm);
													PostMessage(hwnd, WM_CLOSE, 0, 0);
												}
												else if (IsDlgButtonChecked(hwnd, IDC_RADIO_ADDUSER_STUD)) {
													Student* adm = new Student(name, firstName, passWord, login, eMail, model);
													model->addUser(adm);
													PostMessage(hwnd, WM_CLOSE, 0, 0);
												}
												else {
													MessageBox(hwnd, "Le champ Type d'utilisateur n'est pas remplit", "Erreur", MB_OK);
												}
											}
											break;
		}
		case IDC_BUTTON_USER:
		{
								PostMessage(hwnd, WM_CLOSE, 0, 0);
								return DialogBox(hInst, MAKEINTRESOURCE(IDD_STUDENT), NULL, DlgProc);
								break;
		}
		case IDC_BUTTON_REMOVE_USER:
		{
									   HWND hList = GetDlgItem(hwnd, IDC_LIST_ADMIN);
									   int count = SendMessage(hList, LB_GETSELCOUNT, 0, 0);
									   if (count != LB_ERR)
									   {
										   int i;
										   int *buf = (int*)GlobalAlloc(GPTR, sizeof(int)* count);
										   SendMessage(hList, LB_GETSELITEMS, (WPARAM)count, (LPARAM)buf);
										   for (i = count - 1; i >= 0; i--)
										   {
											   if (buf[i] != 0){
												   model->removeUser(model->getAdmin(buf[i] - 1));
												   SendMessage(hList, LB_DELETESTRING, (WPARAM)buf[i], 0);
											   }
										   }
										   GlobalFree(buf);
									   }
									   else
									   {
										   MessageBox(hwnd, "Error counting items :(", "Warning", MB_OK);
									   }
									   hList = GetDlgItem(hwnd, IDC_LIST_TEACHER);
									   count = SendMessage(hList, LB_GETSELCOUNT, 0, 0);
									   if (count != LB_ERR)
									   {
										   int i;
										   int *buf = (int*)GlobalAlloc(GPTR, sizeof(int)* count);
										   SendMessage(hList, LB_GETSELITEMS, (WPARAM)count, (LPARAM)buf);
										   for (i = count - 1; i >= 0; i--)
										   {
											   if (buf[i] != 0){
												   model->removeUser(model->getTeacher(buf[i] - 1));
												   SendMessage(hList, LB_DELETESTRING, (WPARAM)buf[i], 0);
											   }
										   }
										   GlobalFree(buf);
									   }
									   else
									   {
										   MessageBox(hwnd, "Error counting items :(", "Warning", MB_OK);
									   }
									   hList = GetDlgItem(hwnd, IDC_LIST_STUDENT);
									   count = SendMessage(hList, LB_GETSELCOUNT, 0, 0);
									   if (count != LB_ERR)
									   {
										   int i;
										   int *buf = (int*)GlobalAlloc(GPTR, sizeof(int)* count);
										   SendMessage(hList, LB_GETSELITEMS, (WPARAM)count, (LPARAM)buf);
										   for (i = count - 1; i >= 0; i--)
										   {
											   if (buf[i] != 0){
												   model->removeUser(model->getStudent(buf[i] - 1));
												   SendMessage(hList, LB_DELETESTRING, (WPARAM)buf[i], 0);
											   }
										   }
										   GlobalFree(buf);
									   }
									   else
									   {
										   MessageBox(hwnd, "Error counting items :(", "Warning", MB_OK);
									   }
		}
			break;
		case IDC_BUTTON_ADDLESSON:
		{
									 return DialogBox(hInst, MAKEINTRESOURCE(IDD_ADDLESSON), NULL, DlgProc);
									 break;
		}
		case IDC_BUTTON_ADDLESSON_VALIDATE:
		{
											  int dataValide = 1;
											  string name;
											  int len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDLESSON_NAME));
											  if (len > 0) {
												  char* buf;
												  buf = (char*)GlobalAlloc(GPTR, len + 1);
												  GetDlgItemText(hwnd, IDC_EDIT_ADDLESSON_NAME, buf, len + 1);
												  name = buf;
												  GlobalFree((HANDLE)buf);
											  }
											  else {
												  dataValide = 0;
												  MessageBox(hwnd, "Le champ Nom n'est pas remplit", "Erreur", MB_OK);
											  }
											  int maxStud;
											  len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDLESSON_MAXSTUD));
											  if (len > 0) {
												  char* buf;
												  buf = (char*)GlobalAlloc(GPTR, len + 1);
												  GetDlgItemText(hwnd, IDC_EDIT_ADDLESSON_MAXSTUD, buf, len + 1);
												  maxStud = atoi(buf);
												  GlobalFree((HANDLE)buf);
											  }
											  else {
												  dataValide = 0;
												  MessageBox(hwnd, "Le champ Max étudiants n'est pas remplit", "Erreur", MB_OK);
											  }
											  int startDay;
											  len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDLESSON_DATESTART_DAY));
											  if (len > 0) {
												  char* buf;
												  buf = (char*)GlobalAlloc(GPTR, len + 1);
												  GetDlgItemText(hwnd, IDC_EDIT_ADDLESSON_DATESTART_DAY, buf, len + 1);
												  startDay = atoi(buf);
												  GlobalFree((HANDLE)buf);
											  }
											  else {
												  dataValide = 0;
												  MessageBox(hwnd, "Le champ Date début n'est pas remplit", "Erreur", MB_OK);
											  }
											  int startMonth;
											  len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDLESSON_DATESTART_MON));
											  if (len > 0) {
												  char* buf;
												  buf = (char*)GlobalAlloc(GPTR, len + 1);
												  GetDlgItemText(hwnd, IDC_EDIT_ADDLESSON_DATESTART_MON, buf, len + 1);
												  startMonth = atoi(buf);
												  GlobalFree((HANDLE)buf);
											  }
											  else {
												  dataValide = 0;
												  MessageBox(hwnd, "Le champ Date début n'est pas remplit", "Erreur", MB_OK);
											  }
											  int startYear;
											  len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDLESSON_DATESTART_YEA));
											  if (len > 0) {
												  char* buf;
												  buf = (char*)GlobalAlloc(GPTR, len + 1);
												  GetDlgItemText(hwnd, IDC_EDIT_ADDLESSON_DATESTART_YEA, buf, len + 1);
												  startYear = atoi(buf);
												  GlobalFree((HANDLE)buf);
											  }
											  else {
												  dataValide = 0;
												  MessageBox(hwnd, "Le champ Date début n'est pas remplit", "Erreur", MB_OK);
											  }
											  int endDay;
											  len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDLESSON_DATEEND_DAY));
											  if (len > 0) {
												  char* buf;
												  buf = (char*)GlobalAlloc(GPTR, len + 1);
												  GetDlgItemText(hwnd, IDC_EDIT_ADDLESSON_DATEEND_DAY, buf, len + 1);
												  endDay = atoi(buf);
												  GlobalFree((HANDLE)buf);
											  }
											  else {
												  dataValide = 0;
												  MessageBox(hwnd, "Le champ Date fin n'est pas remplit", "Erreur", MB_OK);
											  }
											  int endMonth;
											  len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDLESSON_DATEEND_MON));
											  if (len > 0) {
												  char* buf;
												  buf = (char*)GlobalAlloc(GPTR, len + 1);
												  GetDlgItemText(hwnd, IDC_EDIT_ADDLESSON_DATEEND_MON, buf, len + 1);
												  endMonth = atoi(buf);
												  GlobalFree((HANDLE)buf);
											  }
											  else {
												  dataValide = 0;
												  MessageBox(hwnd, "Le champ Date fin n'est pas remplit", "Erreur", MB_OK);
											  }
											  int endYear;
											  len = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT_ADDLESSON_DATEEND_YEA));
											  if (len > 0) {
												  char* buf;
												  buf = (char*)GlobalAlloc(GPTR, len + 1);
												  GetDlgItemText(hwnd, IDC_EDIT_ADDLESSON_DATEEND_YEA, buf, len + 1);
												  endYear = atoi(buf);
												  GlobalFree((HANDLE)buf);
											  }
											  else {
												  dataValide = 0;
												  MessageBox(hwnd, "Le champ Date fin n'est pas remplit", "Erreur", MB_OK);
											  }
											  if (dataValide) {
												  Lesson* les = new Lesson(name, model->getCurrentTeacher(), maxStud);
												  model->addLesson(les);
												  PostMessage(hwnd, WM_CLOSE, 0, 0);
											  }
											  break;
		}
		case IDC_BUTTON_STUDENT_INS:
		{
									   PostMessage(hwnd, WM_CLOSE, 0, 0);
									   return DialogBox(hInst, MAKEINTRESOURCE(IDD_STUDENT_INS), NULL, DlgProc);
									   break;
		}
		case IDC_BUTTON_DECONNECT:
			PostMessage(hwnd, WM_CLOSE, 0, 0);
			return DialogBox(hInst, MAKEINTRESOURCE(IDD_CONNEXION), NULL, DlgProc);
		case IDC_BUTTON_EXIT:
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

	Admin* Raphael = new Admin("Merkling", "Raphael", "Desmero", "aze", "plop@mail.fr", model);
/*	Teacher* Erwan = new Teacher("Mellinger", "Erwan", "Erwan", "aze", "mel@mail.com", model);
	Student* Steven = new Student("Steven", "Klinger", "PhantomD", "aze", "kli@mail.de", model);
	Student* Nicolas = new Student("Anduze", "Nicolas", "Mandra", "aze", "and@mail.net", model);

	Lesson* CPOA = new Lesson("CPOA", Erwan, 50);
	Lesson* toucan = new Lesson("Toucan", Erwan, 50);
	Lesson* Algo = new Lesson("Algo", Erwan, 50);
	toucan->setValidate(1);

	Nicolas->addLesson(toucan);
	Steven->addLesson(CPOA);
*/
	model->addUser(Raphael);
/*	model->addUser(Erwan);
	model->addUser(Steven);
	model->addUser(Nicolas);

	model->addLesson(CPOA);
	model->addLesson(Algo);
	model->addLesson(toucan);
*/
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_CONNEXION), NULL, DlgProc);
}
