#pragma once
#include "Database.h"
#include "Theme.h"
#include "Helpers.h"
#include "ProductForm.h"
#include "SupplierForm.h"
#include "UserForm.h"

namespace GroceX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Screen 1: Dashboard with summary cards and navigation.
	ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(Database^ database, User* user)
		{
			InitializeComponent();
			db = database;
			currentUser = user;
			loggedOut = false;
			lblUser->Text = "Signed in as: " + toManaged(user->getUsername()) + "  (" + toManaged(user->getRole()) + ")";
			ApplyRole();
			RefreshStats();
		}

		// True when the user pressed Log Out (so the Sign In screen should appear again).
		bool isLoggedOut() { return loggedOut; }

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Database^ db;
		User* currentUser;
		bool loggedOut;

		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Panel^ cardProducts;
		System::Windows::Forms::Label^ lblProductsTitle;
		System::Windows::Forms::Label^ lblProducts;
		System::Windows::Forms::Panel^ cardLow;
		System::Windows::Forms::Label^ lblLowTitle;
		System::Windows::Forms::Label^ lblLow;
		System::Windows::Forms::Panel^ cardValue;
		System::Windows::Forms::Label^ lblValueTitle;
		System::Windows::Forms::Label^ lblValue;
		System::Windows::Forms::Panel^ cardSuppliers;
		System::Windows::Forms::Label^ lblSuppliersTitle;
		System::Windows::Forms::Label^ lblSuppliers;
		System::Windows::Forms::Button^ btnProducts;
		System::Windows::Forms::Button^ btnSuppliers;
		System::Windows::Forms::Button^ btnRefresh;
		System::Windows::Forms::Label^ lblFooter;
		System::Windows::Forms::Label^ lblUser;
		System::Windows::Forms::Label^ lblNotice;
		System::Windows::Forms::Button^ btnUsers;
		System::Windows::Forms::Button^ btnLogout;

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
			this->cardProducts = (gcnew System::Windows::Forms::Panel());
			this->lblProductsTitle = (gcnew System::Windows::Forms::Label());
			this->lblProducts = (gcnew System::Windows::Forms::Label());
			this->cardLow = (gcnew System::Windows::Forms::Panel());
			this->lblLowTitle = (gcnew System::Windows::Forms::Label());
			this->lblLow = (gcnew System::Windows::Forms::Label());
			this->cardValue = (gcnew System::Windows::Forms::Panel());
			this->lblValueTitle = (gcnew System::Windows::Forms::Label());
			this->lblValue = (gcnew System::Windows::Forms::Label());
			this->cardSuppliers = (gcnew System::Windows::Forms::Panel());
			this->lblSuppliersTitle = (gcnew System::Windows::Forms::Label());
			this->lblSuppliers = (gcnew System::Windows::Forms::Label());
			this->btnProducts = (gcnew System::Windows::Forms::Button());
			this->btnSuppliers = (gcnew System::Windows::Forms::Button());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->lblFooter = (gcnew System::Windows::Forms::Label());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->lblNotice = (gcnew System::Windows::Forms::Label());
			this->btnUsers = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->panelHeader->SuspendLayout();
			this->cardProducts->SuspendLayout();
			this->cardLow->SuspendLayout();
			this->cardValue->SuspendLayout();
			this->cardSuppliers->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(46, 125, 50);
			this->panelHeader->Controls->Add(this->lblUser);
			this->panelHeader->Controls->Add(this->lblTitle);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(930, 90);
			this->panelHeader->TabIndex = 0;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(20, 10);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(400, 37);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"GroceX  -  Grocery Inventory System";
			// 
			// cardProducts
			// 
			this->cardProducts->BackColor = System::Drawing::Color::FromArgb(46, 125, 50);
			this->cardProducts->Controls->Add(this->lblProductsTitle);
			this->cardProducts->Controls->Add(this->lblProducts);
			this->cardProducts->Location = System::Drawing::Point(30, 120);
			this->cardProducts->Name = L"cardProducts";
			this->cardProducts->Size = System::Drawing::Size(205, 120);
			this->cardProducts->TabIndex = 1;
			// 
			// lblProductsTitle
			// 
			this->lblProductsTitle->AutoSize = true;
			this->lblProductsTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblProductsTitle->ForeColor = System::Drawing::Color::White;
			this->lblProductsTitle->Location = System::Drawing::Point(14, 14);
			this->lblProductsTitle->Name = L"lblProductsTitle";
			this->lblProductsTitle->Size = System::Drawing::Size(100, 19);
			this->lblProductsTitle->TabIndex = 0;
			this->lblProductsTitle->Text = L"Total Products";
			// 
			// lblProducts
			// 
			this->lblProducts->AutoSize = true;
			this->lblProducts->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 22));
			this->lblProducts->ForeColor = System::Drawing::Color::White;
			this->lblProducts->Location = System::Drawing::Point(12, 50);
			this->lblProducts->Name = L"lblProducts";
			this->lblProducts->Size = System::Drawing::Size(30, 41);
			this->lblProducts->TabIndex = 1;
			this->lblProducts->Text = L"0";
			// 
			// cardLow
			// 
			this->cardLow->BackColor = System::Drawing::Color::FromArgb(198, 40, 40);
			this->cardLow->Controls->Add(this->lblLowTitle);
			this->cardLow->Controls->Add(this->lblLow);
			this->cardLow->Location = System::Drawing::Point(250, 120);
			this->cardLow->Name = L"cardLow";
			this->cardLow->Size = System::Drawing::Size(205, 120);
			this->cardLow->TabIndex = 1;
			// 
			// lblLowTitle
			// 
			this->lblLowTitle->AutoSize = true;
			this->lblLowTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblLowTitle->ForeColor = System::Drawing::Color::White;
			this->lblLowTitle->Location = System::Drawing::Point(14, 14);
			this->lblLowTitle->Name = L"lblLowTitle";
			this->lblLowTitle->Size = System::Drawing::Size(100, 19);
			this->lblLowTitle->TabIndex = 0;
			this->lblLowTitle->Text = L"Low Stock Items";
			// 
			// lblLow
			// 
			this->lblLow->AutoSize = true;
			this->lblLow->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 22));
			this->lblLow->ForeColor = System::Drawing::Color::White;
			this->lblLow->Location = System::Drawing::Point(12, 50);
			this->lblLow->Name = L"lblLow";
			this->lblLow->Size = System::Drawing::Size(30, 41);
			this->lblLow->TabIndex = 1;
			this->lblLow->Text = L"0";
			// 
			// cardValue
			// 
			this->cardValue->BackColor = System::Drawing::Color::FromArgb(245, 124, 0);
			this->cardValue->Controls->Add(this->lblValueTitle);
			this->cardValue->Controls->Add(this->lblValue);
			this->cardValue->Location = System::Drawing::Point(470, 120);
			this->cardValue->Name = L"cardValue";
			this->cardValue->Size = System::Drawing::Size(205, 120);
			this->cardValue->TabIndex = 1;
			// 
			// lblValueTitle
			// 
			this->lblValueTitle->AutoSize = true;
			this->lblValueTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblValueTitle->ForeColor = System::Drawing::Color::White;
			this->lblValueTitle->Location = System::Drawing::Point(14, 14);
			this->lblValueTitle->Name = L"lblValueTitle";
			this->lblValueTitle->Size = System::Drawing::Size(100, 19);
			this->lblValueTitle->TabIndex = 0;
			this->lblValueTitle->Text = L"Stock Value (Rs.)";
			// 
			// lblValue
			// 
			this->lblValue->AutoSize = true;
			this->lblValue->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 22));
			this->lblValue->ForeColor = System::Drawing::Color::White;
			this->lblValue->Location = System::Drawing::Point(12, 50);
			this->lblValue->Name = L"lblValue";
			this->lblValue->Size = System::Drawing::Size(30, 41);
			this->lblValue->TabIndex = 1;
			this->lblValue->Text = L"0";
			// 
			// cardSuppliers
			// 
			this->cardSuppliers->BackColor = System::Drawing::Color::FromArgb(96, 125, 139);
			this->cardSuppliers->Controls->Add(this->lblSuppliersTitle);
			this->cardSuppliers->Controls->Add(this->lblSuppliers);
			this->cardSuppliers->Location = System::Drawing::Point(690, 120);
			this->cardSuppliers->Name = L"cardSuppliers";
			this->cardSuppliers->Size = System::Drawing::Size(205, 120);
			this->cardSuppliers->TabIndex = 1;
			// 
			// lblSuppliersTitle
			// 
			this->lblSuppliersTitle->AutoSize = true;
			this->lblSuppliersTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblSuppliersTitle->ForeColor = System::Drawing::Color::White;
			this->lblSuppliersTitle->Location = System::Drawing::Point(14, 14);
			this->lblSuppliersTitle->Name = L"lblSuppliersTitle";
			this->lblSuppliersTitle->Size = System::Drawing::Size(100, 19);
			this->lblSuppliersTitle->TabIndex = 0;
			this->lblSuppliersTitle->Text = L"Suppliers";
			// 
			// lblSuppliers
			// 
			this->lblSuppliers->AutoSize = true;
			this->lblSuppliers->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 22));
			this->lblSuppliers->ForeColor = System::Drawing::Color::White;
			this->lblSuppliers->Location = System::Drawing::Point(12, 50);
			this->lblSuppliers->Name = L"lblSuppliers";
			this->lblSuppliers->Size = System::Drawing::Size(30, 41);
			this->lblSuppliers->TabIndex = 1;
			this->lblSuppliers->Text = L"0";
			// 
			// btnProducts
			// 
			this->btnProducts->BackColor = System::Drawing::Color::FromArgb(46, 125, 50);
			this->btnProducts->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnProducts->FlatAppearance->BorderSize = 0;
			this->btnProducts->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProducts->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnProducts->ForeColor = System::Drawing::Color::White;
			this->btnProducts->Location = System::Drawing::Point(30, 310);
			this->btnProducts->Name = L"btnProducts";
			this->btnProducts->Size = System::Drawing::Size(260, 60);
			this->btnProducts->TabIndex = 2;
			this->btnProducts->Text = L"Manage Products";
			this->btnProducts->UseVisualStyleBackColor = false;
			this->btnProducts->Click += gcnew System::EventHandler(this, &MainForm::btnProducts_Click);
			// 
			// btnSuppliers
			// 
			this->btnSuppliers->BackColor = System::Drawing::Color::FromArgb(27, 94, 32);
			this->btnSuppliers->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSuppliers->FlatAppearance->BorderSize = 0;
			this->btnSuppliers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSuppliers->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnSuppliers->ForeColor = System::Drawing::Color::White;
			this->btnSuppliers->Location = System::Drawing::Point(310, 310);
			this->btnSuppliers->Name = L"btnSuppliers";
			this->btnSuppliers->Size = System::Drawing::Size(260, 60);
			this->btnSuppliers->TabIndex = 3;
			this->btnSuppliers->Text = L"Manage Suppliers";
			this->btnSuppliers->UseVisualStyleBackColor = false;
			this->btnSuppliers->Click += gcnew System::EventHandler(this, &MainForm::btnSuppliers_Click);
			// 
			// btnRefresh
			// 
			this->btnRefresh->BackColor = System::Drawing::Color::FromArgb(96, 125, 139);
			this->btnRefresh->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRefresh->FlatAppearance->BorderSize = 0;
			this->btnRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefresh->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnRefresh->ForeColor = System::Drawing::Color::White;
			this->btnRefresh->Location = System::Drawing::Point(590, 310);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(160, 60);
			this->btnRefresh->TabIndex = 4;
			this->btnRefresh->Text = L"Refresh";
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &MainForm::btnRefresh_Click);
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblUser->ForeColor = System::Drawing::Color::White;
			this->lblUser->Location = System::Drawing::Point(24, 58);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(100, 19);
			this->lblUser->TabIndex = 1;
			this->lblUser->Text = L"Signed in as:";
			// 
			// lblNotice
			// 
			this->lblNotice->AutoSize = true;
			this->lblNotice->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->lblNotice->ForeColor = System::Drawing::Color::FromArgb(198, 40, 40);
			this->lblNotice->Location = System::Drawing::Point(30, 262);
			this->lblNotice->Name = L"lblNotice";
			this->lblNotice->Size = System::Drawing::Size(100, 19);
			this->lblNotice->TabIndex = 6;
			this->lblNotice->Text = L"";
			// 
			// btnUsers
			// 
			this->btnUsers->BackColor = System::Drawing::Color::FromArgb(245, 124, 0);
			this->btnUsers->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnUsers->FlatAppearance->BorderSize = 0;
			this->btnUsers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUsers->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnUsers->ForeColor = System::Drawing::Color::White;
			this->btnUsers->Location = System::Drawing::Point(30, 390);
			this->btnUsers->Name = L"btnUsers";
			this->btnUsers->Size = System::Drawing::Size(260, 60);
			this->btnUsers->TabIndex = 7;
			this->btnUsers->Text = L"Manage Users";
			this->btnUsers->UseVisualStyleBackColor = false;
			this->btnUsers->Click += gcnew System::EventHandler(this, &MainForm::btnUsers_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->BackColor = System::Drawing::Color::FromArgb(198, 40, 40);
			this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLogout->FlatAppearance->BorderSize = 0;
			this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnLogout->ForeColor = System::Drawing::Color::White;
			this->btnLogout->Location = System::Drawing::Point(310, 390);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(160, 60);
			this->btnLogout->TabIndex = 8;
			this->btnLogout->Text = L"Log Out";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &MainForm::btnLogout_Click);			// 
			// lblFooter
			// 
			this->lblFooter->AutoSize = true;
			this->lblFooter->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblFooter->ForeColor = System::Drawing::Color::FromArgb(96, 125, 139);
			this->lblFooter->Location = System::Drawing::Point(30, 480);
			this->lblFooter->Name = L"lblFooter";
			this->lblFooter->Size = System::Drawing::Size(400, 19);
			this->lblFooter->TabIndex = 5;
			this->lblFooter->Text = L"ICT 1306 - OOP Group Assignment  |  Rajarata University of Sri Lanka";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(930, 520);
			this->Controls->Add(this->cardProducts);
			this->Controls->Add(this->cardLow);
			this->Controls->Add(this->cardValue);
			this->Controls->Add(this->cardSuppliers);
			this->Controls->Add(this->btnProducts);
			this->Controls->Add(this->btnSuppliers);
			this->Controls->Add(this->btnRefresh);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->btnUsers);
			this->Controls->Add(this->lblNotice);
			this->Controls->Add(this->lblFooter);
			this->Controls->Add(this->panelHeader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GroceX - Grocery Inventory System";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->cardProducts->ResumeLayout(false);
			this->cardProducts->PerformLayout();
			this->cardLow->ResumeLayout(false);
			this->cardLow->PerformLayout();
			this->cardValue->ResumeLayout(false);
			this->cardValue->PerformLayout();
			this->cardSuppliers->ResumeLayout(false);
			this->cardSuppliers->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		// Enables / disables features depending on the signed-in user's role.
		void ApplyRole()
		{
			btnProducts->Enabled = currentUser->canManageProducts();
			btnSuppliers->Enabled = currentUser->canManageSuppliers();
			btnUsers->Visible = currentUser->canManageUsers();
			if (!currentUser->isApproved())
				lblNotice->Text = "Your account is waiting for the super admin to assign a role. You cannot use the system yet.";
			else if (!currentUser->canManageSuppliers())
				lblNotice->Text = "Your role (Staff) can manage products only.";
		}

		System::Void btnUsers_Click(System::Object^ sender, System::EventArgs^ e)
		{
			UserForm^ f = gcnew UserForm(db);
			f->ShowDialog(this);
		}

		System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e)
		{
			loggedOut = true;
			this->Close();
		}

		void RefreshStats()
		{
			if (!currentUser->isApproved()) return;

			std::vector<GroceryItem*> items;
			try
			{
				items = db->getProducts("");
				int low = 0;
				double total = 0;
				for (size_t i = 0; i < items.size(); i++)
				{
					if (items[i]->isLowStock()) low++;      // polymorphism: Fresh and Packaged differ
					total = total + items[i]->getStockValue();
				}
				lblProducts->Text = items.size().ToString();
				lblLow->Text = low.ToString();
				lblValue->Text = total.ToString("N0");

				std::vector<Supplier*> suppliers = db->getSuppliers("");
				lblSuppliers->Text = suppliers.size().ToString();
				deleteAll(suppliers);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Could not read from MySQL:\n" + ex->Message, "GroceX");
			}
			deleteAll(items);
		}

		System::Void btnProducts_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ProductForm^ f = gcnew ProductForm(db);
			f->ShowDialog(this);
			RefreshStats();
		}

		System::Void btnSuppliers_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SupplierForm^ f = gcnew SupplierForm(db);
			f->ShowDialog(this);
			RefreshStats();
		}

		System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) { RefreshStats(); }
	};
}