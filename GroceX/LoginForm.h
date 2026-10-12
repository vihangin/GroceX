#pragma once
#include "Database.h"
#include "Theme.h"
#include "Helpers.h"
#include "SignUpForm.h"

namespace GroceX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Sign In screen.
	ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(Database^ database)
		{
			InitializeComponent();
			db = database;
			loggedInUser = nullptr;
		}

		// The user who signed in (nullptr if the window was closed).
		// The caller must delete this user when finished.
		User* getLoggedInUser() { return loggedInUser; }

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Database^ db;
		User* loggedInUser;

		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Label^ lblTitle;

		System::Windows::Forms::TextBox^ txtUsername;
		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::TextBox^ txtPassword;
		System::Windows::Forms::Button^ btnSignIn;
		System::Windows::Forms::Button^ btnSignUp;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ lblUsername;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnSignIn = (gcnew System::Windows::Forms::Button());
			this->btnSignUp = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->panelHeader->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->panelHeader->Controls->Add(this->lblTitle);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Margin = System::Windows::Forms::Padding(4);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(703, 111);
			this->panelHeader->TabIndex = 7;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 24));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(27, 25);
			this->lblTitle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(291, 54);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"GroceX Sign In";
			this->lblTitle->Click += gcnew System::EventHandler(this, &LoginForm::lblTitle_Click);
			// 
			// txtUsername
			// 
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtUsername->Location = System::Drawing::Point(151, 199);
			this->txtUsername->Margin = System::Windows::Forms::Padding(4);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(399, 30);
			this->txtUsername->TabIndex = 1;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F));
			this->lblPassword->Location = System::Drawing::Point(152, 257);
			this->lblPassword->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(101, 28);
			this->lblPassword->TabIndex = 2;
			this->lblPassword->Text = L"Password";
			// 
			// txtPassword
			// 
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPassword->Location = System::Drawing::Point(151, 289);
			this->txtPassword->Margin = System::Windows::Forms::Padding(4);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(399, 30);
			this->txtPassword->TabIndex = 3;
			this->txtPassword->UseSystemPasswordChar = true;
			this->txtPassword->TextChanged += gcnew System::EventHandler(this, &LoginForm::txtPassword_TextChanged);
			// 
			// btnSignIn
			// 
			this->btnSignIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->btnSignIn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSignIn->FlatAppearance->BorderSize = 0;
			this->btnSignIn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignIn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnSignIn->ForeColor = System::Drawing::Color::White;
			this->btnSignIn->Location = System::Drawing::Point(151, 383);
			this->btnSignIn->Margin = System::Windows::Forms::Padding(4);
			this->btnSignIn->Name = L"btnSignIn";
			this->btnSignIn->Size = System::Drawing::Size(400, 52);
			this->btnSignIn->TabIndex = 4;
			this->btnSignIn->Text = L"Sign In";
			this->btnSignIn->UseVisualStyleBackColor = false;
			this->btnSignIn->Click += gcnew System::EventHandler(this, &LoginForm::btnSignIn_Click);
			// 
			// btnSignUp
			// 
			this->btnSignUp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->btnSignUp->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSignUp->FlatAppearance->BorderSize = 0;
			this->btnSignUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignUp->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnSignUp->ForeColor = System::Drawing::Color::White;
			this->btnSignUp->Location = System::Drawing::Point(151, 447);
			this->btnSignUp->Margin = System::Windows::Forms::Padding(4);
			this->btnSignUp->Name = L"btnSignUp";
			this->btnSignUp->Size = System::Drawing::Size(400, 47);
			this->btnSignUp->TabIndex = 5;
			this->btnSignUp->Text = L"Create new account";
			this->btnSignUp->UseVisualStyleBackColor = false;
			this->btnSignUp->Click += gcnew System::EventHandler(this, &LoginForm::btnSignUp_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(703, 545);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->BackColor = System::Drawing::Color::Transparent;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUsername->Location = System::Drawing::Point(152, 167);
			this->lblUsername->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(107, 28);
			this->lblUsername->TabIndex = 0;
			this->lblUsername->Text = L"Username";
			// 
			// LoginForm
			// 
			this->AcceptButton = this->btnSignIn;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(703, 546);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->btnSignUp);
			this->Controls->Add(this->btnSignIn);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->panelHeader);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GroceX - Sign In";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void btnSignIn_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				User* u = db->getUser(toNative(txtUsername->Text->Trim()));
				if (u == nullptr || u->getPasswordHash() != hashPassword(toNative(txtPassword->Text)))
				{
					delete u;
					MessageBox::Show("Invalid username or password.", "GroceX", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				loggedInUser = u;
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Database error: " + ex->Message, "GroceX", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		System::Void btnSignUp_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SignUpForm^ f = gcnew SignUpForm(db);
			f->ShowDialog(this);
		}
	private: System::Void lblTitle_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}