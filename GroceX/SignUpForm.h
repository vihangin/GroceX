#pragma once
#include "Database.h"
#include "Theme.h"
#include "Helpers.h"

namespace GroceX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Sign Up screen: creates a new account with the "Pending" role.
	ref class SignUpForm : public System::Windows::Forms::Form
	{
	public:
		SignUpForm(Database^ database)
		{
			InitializeComponent();
			db = database;
		}

	protected:
		~SignUpForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Database^ db;

		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblUsername;
		System::Windows::Forms::TextBox^ txtUsername;
		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::TextBox^ txtPassword;
		System::Windows::Forms::Label^ lblConfirm;
		System::Windows::Forms::TextBox^ txtConfirm;
		System::Windows::Forms::Button^ btnRegister;
		System::Windows::Forms::Button^ btnCancel;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblConfirm = (gcnew System::Windows::Forms::Label());
			this->txtConfirm = (gcnew System::Windows::Forms::TextBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->panelHeader->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(46, 125, 50);
			this->panelHeader->Controls->Add(this->lblTitle);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(400, 80);
			this->panelHeader->TabIndex = 9;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(20, 20);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(200, 37);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"Create Account";
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblUsername->Location = System::Drawing::Point(50, 105);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(70, 19);
			this->lblUsername->TabIndex = 0;
			this->lblUsername->Text = L"Username";
			// 
			// txtUsername
			// 
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtUsername->Location = System::Drawing::Point(50, 128);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(300, 25);
			this->txtUsername->TabIndex = 1;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblPassword->Location = System::Drawing::Point(50, 170);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(65, 19);
			this->lblPassword->TabIndex = 2;
			this->lblPassword->Text = L"Password";
			// 
			// txtPassword
			// 
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPassword->Location = System::Drawing::Point(50, 193);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(300, 25);
			this->txtPassword->TabIndex = 3;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// lblConfirm
			// 
			this->lblConfirm->AutoSize = true;
			this->lblConfirm->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblConfirm->Location = System::Drawing::Point(50, 235);
			this->lblConfirm->Name = L"lblConfirm";
			this->lblConfirm->Size = System::Drawing::Size(110, 19);
			this->lblConfirm->TabIndex = 4;
			this->lblConfirm->Text = L"Confirm Password";
			// 
			// txtConfirm
			// 
			this->txtConfirm->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtConfirm->Location = System::Drawing::Point(50, 258);
			this->txtConfirm->Name = L"txtConfirm";
			this->txtConfirm->Size = System::Drawing::Size(300, 25);
			this->txtConfirm->TabIndex = 5;
			this->txtConfirm->UseSystemPasswordChar = true;
			// 
			// btnRegister
			// 
			this->btnRegister->BackColor = System::Drawing::Color::FromArgb(46, 125, 50);
			this->btnRegister->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRegister->FlatAppearance->BorderSize = 0;
			this->btnRegister->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnRegister->ForeColor = System::Drawing::Color::White;
			this->btnRegister->Location = System::Drawing::Point(50, 315);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(300, 42);
			this->btnRegister->TabIndex = 6;
			this->btnRegister->Text = L"Sign Up";
			this->btnRegister->UseVisualStyleBackColor = false;
			this->btnRegister->Click += gcnew System::EventHandler(this, &SignUpForm::btnRegister_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::FromArgb(96, 125, 139);
			this->btnCancel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCancel->FlatAppearance->BorderSize = 0;
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnCancel->ForeColor = System::Drawing::Color::White;
			this->btnCancel->Location = System::Drawing::Point(50, 367);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(300, 38);
			this->btnCancel->TabIndex = 7;
			this->btnCancel->Text = L"Back to Sign In";
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &SignUpForm::btnCancel_Click);
			// 
			// SignUpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(400, 430);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->txtConfirm);
			this->Controls->Add(this->lblConfirm);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->panelHeader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SignUpForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GroceX - Sign Up";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		void ShowError(String^ msg)
		{
			MessageBox::Show(msg, "GroceX", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				if (txtPassword->Text->Length < 4) { ShowError("Password must be at least 4 characters."); return; }
				if (txtPassword->Text != txtConfirm->Text) { ShowError("Passwords do not match."); return; }

				std::string username = toNative(txtUsername->Text->Trim());

				// The User constructor checks the username rules.
				// New accounts always start with the "Pending" role.
				User newUser(0, username, hashPassword(toNative(txtPassword->Text)), "Pending");

				User* existing = db->getUser(username);
				if (existing != nullptr)
				{
					delete existing;
					ShowError("That username is already taken.");
					return;
				}

				db->addUser(newUser);
				MessageBox::Show("Account created!\nThe super admin must assign you a role before you can use the system.",
					"GroceX", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
			catch (const std::invalid_argument& ex) { ShowError(toManaged(ex.what())); }
			catch (Exception^ ex) { ShowError("Database error: " + ex->Message); }
		}

		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) { this->Close(); }
	};
}