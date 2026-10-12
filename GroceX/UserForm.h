#pragma once
#include "Database.h"
#include "Theme.h"
#include "Helpers.h"

namespace GroceX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Super admin screen: list all sign-ups, assign a role or delete an account.
	ref class UserForm : public System::Windows::Forms::Form
	{
	public:
		UserForm(Database^ database)
		{
			InitializeComponent();
			db = database;
			selectedId = 0;

			styleGrid(grid);
			grid->Columns->Add("Id", "ID");
			grid->Columns->Add("Username", "Username");
			grid->Columns->Add("Role", "Role");
			grid->Columns["Id"]->FillWeight = 30;

			cmbRole->SelectedIndex = 0;
			LoadGrid();
		}

	protected:
		~UserForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Database^ db;
		int selectedId;

		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Panel^ panelBottom;
		System::Windows::Forms::Label^ lblRole;
		System::Windows::Forms::ComboBox^ cmbRole;
		System::Windows::Forms::Button^ btnAssign;
		System::Windows::Forms::Button^ btnDelete;
		System::Windows::Forms::Button^ btnRefresh;
		System::Windows::Forms::DataGridView^ grid;

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
			this->panelBottom = (gcnew System::Windows::Forms::Panel());
			this->lblRole = (gcnew System::Windows::Forms::Label());
			this->cmbRole = (gcnew System::Windows::Forms::ComboBox());
			this->btnAssign = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->panelHeader->SuspendLayout();
			this->panelBottom->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->BeginInit();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(46, 125, 50);
			this->panelHeader->Controls->Add(this->lblTitle);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(820, 70);
			this->panelHeader->TabIndex = 2;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(20, 14);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(260, 37);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"Manage Users (Super Admin)";
			// 
			// panelBottom
			// 
			this->panelBottom->BackColor = System::Drawing::Color::FromArgb(241, 248, 233);
			this->panelBottom->Controls->Add(this->lblRole);
			this->panelBottom->Controls->Add(this->cmbRole);
			this->panelBottom->Controls->Add(this->btnAssign);
			this->panelBottom->Controls->Add(this->btnDelete);
			this->panelBottom->Controls->Add(this->btnRefresh);
			this->panelBottom->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panelBottom->Location = System::Drawing::Point(0, 450);
			this->panelBottom->Name = L"panelBottom";
			this->panelBottom->Size = System::Drawing::Size(820, 70);
			this->panelBottom->TabIndex = 1;
			// 
			// lblRole
			// 
			this->lblRole->AutoSize = true;
			this->lblRole->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblRole->Location = System::Drawing::Point(20, 24);
			this->lblRole->Name = L"lblRole";
			this->lblRole->Size = System::Drawing::Size(36, 19);
			this->lblRole->TabIndex = 0;
			this->lblRole->Text = L"Role:";
			// 
			// cmbRole
			// 
			this->cmbRole->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbRole->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->cmbRole->FormattingEnabled = true;
			this->cmbRole->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Manager", L"Staff", L"Pending" });
			this->cmbRole->Location = System::Drawing::Point(65, 20);
			this->cmbRole->Name = L"cmbRole";
			this->cmbRole->Size = System::Drawing::Size(160, 25);
			this->cmbRole->TabIndex = 1;
			// 
			// btnAssign
			// 
			this->btnAssign->BackColor = System::Drawing::Color::FromArgb(46, 125, 50);
			this->btnAssign->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAssign->FlatAppearance->BorderSize = 0;
			this->btnAssign->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAssign->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnAssign->ForeColor = System::Drawing::Color::White;
			this->btnAssign->Location = System::Drawing::Point(245, 16);
			this->btnAssign->Name = L"btnAssign";
			this->btnAssign->Size = System::Drawing::Size(130, 38);
			this->btnAssign->TabIndex = 2;
			this->btnAssign->Text = L"Assign Role";
			this->btnAssign->UseVisualStyleBackColor = false;
			this->btnAssign->Click += gcnew System::EventHandler(this, &UserForm::btnAssign_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::Color::FromArgb(198, 40, 40);
			this->btnDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDelete->FlatAppearance->BorderSize = 0;
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnDelete->ForeColor = System::Drawing::Color::White;
			this->btnDelete->Location = System::Drawing::Point(385, 16);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(130, 38);
			this->btnDelete->TabIndex = 3;
			this->btnDelete->Text = L"Delete User";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &UserForm::btnDelete_Click);
			// 
			// btnRefresh
			// 
			this->btnRefresh->BackColor = System::Drawing::Color::FromArgb(96, 125, 139);
			this->btnRefresh->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRefresh->FlatAppearance->BorderSize = 0;
			this->btnRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefresh->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnRefresh->ForeColor = System::Drawing::Color::White;
			this->btnRefresh->Location = System::Drawing::Point(525, 16);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(130, 38);
			this->btnRefresh->TabIndex = 4;
			this->btnRefresh->Text = L"Refresh";
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &UserForm::btnRefresh_Click);
			// 
			// grid
			// 
			this->grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grid->Location = System::Drawing::Point(0, 70);
			this->grid->Name = L"grid";
			this->grid->Size = System::Drawing::Size(820, 380);
			this->grid->TabIndex = 0;
			this->grid->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UserForm::grid_CellClick);
			// 
			// UserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(820, 520);
			this->Controls->Add(this->grid);
			this->Controls->Add(this->panelBottom);
			this->Controls->Add(this->panelHeader);
			this->MinimumSize = System::Drawing::Size(700, 450);
			this->Name = L"UserForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GroceX - Manage Users";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelBottom->ResumeLayout(false);
			this->panelBottom->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		void LoadGrid()
		{
			std::vector<User*> users;
			try
			{
				users = db->getUsers();
				grid->Rows->Clear();
				for (size_t i = 0; i < users.size(); i++)
				{
					User* u = users[i];
					int row = grid->Rows->Add(gcnew array<Object^>{ u->getId(), toManaged(u->getUsername()), toManaged(u->getRole()) });
					if (!u->isApproved())
						grid->Rows[row]->Cells["Role"]->Style->ForeColor = redColor();
				}
				selectedId = 0;
			}
			catch (Exception^ ex) { ShowError(ex->Message); }
			deleteAll(users);
		}

		void ShowError(String^ msg)
		{
			MessageBox::Show(msg, "GroceX", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		System::Void grid_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex < 0) return;
			DataGridViewRow^ r = grid->Rows[e->RowIndex];
			selectedId = Convert::ToInt32(r->Cells["Id"]->Value);
			cmbRole->SelectedItem = Convert::ToString(r->Cells["Role"]->Value);
		}

		System::Void btnAssign_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedId == 0) { ShowError("Select a user from the table first."); return; }
			try
			{
				db->updateUserRole(selectedId, toNative(cmbRole->Text));
				LoadGrid();
			}
			catch (Exception^ ex) { ShowError(ex->Message); }
		}

		System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedId == 0) { ShowError("Select a user from the table first."); return; }
			if (MessageBox::Show("Delete this user?", "Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
				!= System::Windows::Forms::DialogResult::Yes) return;
			try
			{
				db->deleteUser(selectedId);
				LoadGrid();
			}
			catch (Exception^ ex) { ShowError(ex->Message); }
		}

		System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) { LoadGrid(); }
	};
}