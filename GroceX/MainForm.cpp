#include "MainForm.h"
#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	GroceX::Database^ db = gcnew GroceX::Database();
	try
	{
		db->initialize();
	}
	catch (Exception^ ex) // catch the error (exception) 
	{
		MessageBox::Show(
			"Cannot connect to MySQL. Make sure MySQL is running and the user/password in Database.h are correct.\n\n" + ex->Message,
			"GroceX", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 1;
	}

	// Sign In -> Dashboard. After "Log Out" the Sign In screen appears again.
	while (true)
	{
		GroceX::LoginForm^ login = gcnew GroceX::LoginForm(db);
		if (login->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			break;

		User* user = login->getLoggedInUser();      // created with new, so we delete it below
		GroceX::MainForm^ dashboard = gcnew GroceX::MainForm(db, user);
		dashboard->ShowDialog();

		bool showLoginAgain = dashboard->isLoggedOut();
		delete user;
		if (!showLoginAgain)
			break;
	}
	return 0;
}