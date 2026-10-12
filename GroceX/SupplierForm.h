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

	// Screen 3: Manage suppliers (Add / View / Update / Delete).
	ref class SupplierForm : public System::Windows::Forms::Form
	{
	public:
		SupplierForm(Database^ database)
		{
			InitializeComponent();
			db = database;
			selectedId = 0;

			styleGrid(grid);
			grid->Columns->Add("Id", "ID");
			grid->Columns->Add("Name", "Name");
			grid->Columns->Add("Phone", "Phone");
			grid->Columns->Add("Supplies", "Supplies");
			grid->Columns["Id"]->FillWeight = 30;

			LoadGrid();
		}

	protected:
		~SupplierForm()
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
		System::Windows::Forms::Panel^ panelLeft;
		System::Windows::Forms::Label^ lblName;
		System::Windows::Forms::TextBox^ txtName;
		System::Windows::Forms::Label^ lblPhone;
		System::Windows::Forms::TextBox^ txtPhone;
		System::Windows::Forms::Label^ lblSupplies;
		System::Windows::Forms::TextBox^ txtSupplies;
		System::Windows::Forms::Button^ btnAdd;
		System::Windows::Forms::Button^ btnUpdate;
		System::Windows::Forms::Button^ btnDelete;
		System::Windows::Forms::Button^ btnClear;
		System::Windows::Forms::Panel^ panelRight;
		System::Windows::Forms::Panel^ panelSearch;
		System::Windows::Forms::Label^ lblSearch;
		System::Windows::Forms::TextBox^ txtSearch;
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
			this->panelLeft = (gcnew System::Windows::Forms::Panel());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblPhone = (gcnew System::Windows::Forms::Label());
			this->txtPhone = (gcnew System::Windows::Forms::TextBox());
			this->lblSupplies = (gcnew System::Windows::Forms::Label());
			this->txtSupplies = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->panelRight = (gcnew System::Windows::Forms::Panel());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->panelSearch = (gcnew System::Windows::Forms::Panel());
			this->lblSearch = (gcnew System::Windows::Forms::Label());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->panelHeader->SuspendLayout();
			this->panelLeft->SuspendLayout();
			this->panelRight->SuspendLayout();
			this->panelSearch->SuspendLayout();
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
			this->panelHeader->Size = System::Drawing::Size(1080, 70);
			this->panelHeader->TabIndex = 2;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(20, 14);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(120, 37);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"Suppliers";
			// 
			// panelLeft
			// 
			this->panelLeft->BackColor = System::Drawing::Color::FromArgb(241, 248, 233);
			this->panelLeft->Controls->Add(this->lblName);
			this->panelLeft->Controls->Add(this->txtName);
			this->panelLeft->Controls->Add(this->lblPhone);
			this->panelLeft->Controls->Add(this->txtPhone);
			this->panelLeft->Controls->Add(this->lblSupplies);
			this->panelLeft->Controls->Add(this->txtSupplies);
			this->panelLeft->Controls->Add(this->btnAdd);
			this->panelLeft->Controls->Add(this->btnUpdate);
			this->panelLeft->Controls->Add(this->btnDelete);
			this->panelLeft->Controls->Add(this->btnClear);
			this->panelLeft->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelLeft->Location = System::Drawing::Point(0, 70);
			this->panelLeft->Name = L"panelLeft";
			this->panelLeft->Size = System::Drawing::Size(290, 530);
			this->panelLeft->TabIndex = 1;
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblName->Location = System::Drawing::Point(20, 25);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(100, 19);
			this->lblName->TabIndex = 0;
			this->lblName->Text = L"Supplier Name";
			// 
			// txtName
			// 
			this->txtName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtName->Location = System::Drawing::Point(20, 48);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(245, 25);
			this->txtName->TabIndex = 1;
			// 
			// lblPhone
			// 
			this->lblPhone->AutoSize = true;
			this->lblPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblPhone->Location = System::Drawing::Point(20, 95);
			this->lblPhone->Name = L"lblPhone";
			this->lblPhone->Size = System::Drawing::Size(46, 19);
			this->lblPhone->TabIndex = 2;
			this->lblPhone->Text = L"Phone";
			// 
			// txtPhone
			// 
			this->txtPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPhone->Location = System::Drawing::Point(20, 118);
			this->txtPhone->Name = L"txtPhone";
			this->txtPhone->Size = System::Drawing::Size(245, 25);
			this->txtPhone->TabIndex = 3;
			// 
			// lblSupplies
			// 
			this->lblSupplies->AutoSize = true;
			this->lblSupplies->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblSupplies->Location = System::Drawing::Point(20, 165);
			this->lblSupplies->Name = L"lblSupplies";
			this->lblSupplies->Size = System::Drawing::Size(165, 19);
			this->lblSupplies->TabIndex = 4;
			this->lblSupplies->Text = L"Supplies (e.g. Vegetables)";
			// 
			// txtSupplies
			// 
			this->txtSupplies->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtSupplies->Location = System::Drawing::Point(20, 188);
			this->txtSupplies->Name = L"txtSupplies";
			this->txtSupplies->Size = System::Drawing::Size(245, 25);
			this->txtSupplies->TabIndex = 5;
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::Color::FromArgb(46, 125, 50);
			this->btnAdd->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAdd->FlatAppearance->BorderSize = 0;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnAdd->ForeColor = System::Drawing::Color::White;
			this->btnAdd->Location = System::Drawing::Point(20, 250);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(118, 38);
			this->btnAdd->TabIndex = 6;
			this->btnAdd->Text = L"Add";
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &SupplierForm::btnAdd_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::Color::FromArgb(245, 124, 0);
			this->btnUpdate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnUpdate->FlatAppearance->BorderSize = 0;
			this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnUpdate->ForeColor = System::Drawing::Color::White;
			this->btnUpdate->Location = System::Drawing::Point(147, 250);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(118, 38);
			this->btnUpdate->TabIndex = 7;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &SupplierForm::btnUpdate_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::Color::FromArgb(198, 40, 40);
			this->btnDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDelete->FlatAppearance->BorderSize = 0;
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnDelete->ForeColor = System::Drawing::Color::White;
			this->btnDelete->Location = System::Drawing::Point(20, 298);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(118, 38);
			this->btnDelete->TabIndex = 8;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &SupplierForm::btnDelete_Click);
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::FromArgb(96, 125, 139);
			this->btnClear->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnClear->FlatAppearance->BorderSize = 0;
			this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnClear->ForeColor = System::Drawing::Color::White;
			this->btnClear->Location = System::Drawing::Point(147, 298);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(118, 38);
			this->btnClear->TabIndex = 9;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &SupplierForm::btnClear_Click);
			// 
			// panelRight
			// 
			this->panelRight->Controls->Add(this->grid);
			this->panelRight->Controls->Add(this->panelSearch);
			this->panelRight->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelRight->Location = System::Drawing::Point(290, 70);
			this->panelRight->Name = L"panelRight";
			this->panelRight->Padding = System::Windows::Forms::Padding(10);
			this->panelRight->Size = System::Drawing::Size(790, 530);
			this->panelRight->TabIndex = 0;
			// 
			// grid
			// 
			this->grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grid->Location = System::Drawing::Point(10, 55);
			this->grid->Name = L"grid";
			this->grid->Size = System::Drawing::Size(770, 465);
			this->grid->TabIndex = 1;
			this->grid->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SupplierForm::grid_CellClick);
			// 
			// panelSearch
			// 
			this->panelSearch->Controls->Add(this->lblSearch);
			this->panelSearch->Controls->Add(this->txtSearch);
			this->panelSearch->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelSearch->Location = System::Drawing::Point(10, 10);
			this->panelSearch->Name = L"panelSearch";
			this->panelSearch->Size = System::Drawing::Size(770, 45);
			this->panelSearch->TabIndex = 0;
			// 
			// lblSearch
			// 
			this->lblSearch->AutoSize = true;
			this->lblSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblSearch->Location = System::Drawing::Point(3, 11);
			this->lblSearch->Name = L"lblSearch";
			this->lblSearch->Size = System::Drawing::Size(52, 19);
			this->lblSearch->TabIndex = 0;
			this->lblSearch->Text = L"Search:";
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtSearch->Location = System::Drawing::Point(65, 8);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(260, 25);
			this->txtSearch->TabIndex = 1;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &SupplierForm::txtSearch_TextChanged);
			// 
			// SupplierForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1080, 600);
			this->Controls->Add(this->panelRight);
			this->Controls->Add(this->panelLeft);
			this->Controls->Add(this->panelHeader);
			this->MinimumSize = System::Drawing::Size(1000, 600);
			this->Name = L"SupplierForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GroceX - Suppliers";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelLeft->ResumeLayout(false);
			this->panelLeft->PerformLayout();
			this->panelRight->ResumeLayout(false);
			this->panelSearch->ResumeLayout(false);
			this->panelSearch->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		void LoadGrid()
		{
			std::vector<Supplier*> list;
			try
			{
				list = db->getSuppliers(toNative(txtSearch->Text->Trim()));
				grid->Rows->Clear();
				for (size_t i = 0; i < list.size(); i++)
				{
					Supplier* s = list[i];
					grid->Rows->Add(gcnew array<Object^>{ s->getId(), toManaged(s->getName()), toManaged(s->getPhone()), toManaged(s->getSupplies()) });
				}
			}
			catch (Exception^ ex) { ShowError(ex->Message); }
			deleteAll(list);
		}

		void Save(bool isNew)
		{
			try
			{
				if (!isNew && selectedId == 0) { ShowError("Select a supplier from the table first."); return; }

				// Create a Supplier object (the constructor checks the values)
				Supplier s(isNew ? 0 : selectedId,
					toNative(txtName->Text->Trim()),
					toNative(txtPhone->Text->Trim()),
					toNative(txtSupplies->Text->Trim()));

				if (isNew) db->addSupplier(s); else db->updateSupplier(s);
				ClearInputs();
				LoadGrid();
			}
			catch (const std::invalid_argument& ex) { ShowError(toManaged(ex.what())); }
			catch (Exception^ ex) { ShowError("Database error: " + ex->Message); }
		}

		void ClearInputs()
		{
			selectedId = 0;
			txtName->Clear();
			txtPhone->Clear();
			txtSupplies->Clear();
			grid->ClearSelection();
		}

		void ShowError(String^ msg)
		{
			MessageBox::Show(msg, "GroceX", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) { Save(true); }
		System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) { Save(false); }
		System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) { ClearInputs(); }
		System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) { LoadGrid(); }

		System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedId == 0) { ShowError("Select a supplier from the table first."); return; }
			if (MessageBox::Show("Delete this supplier?", "Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
				!= System::Windows::Forms::DialogResult::Yes) return;
			try
			{
				db->deleteSupplier(selectedId);
				ClearInputs();
				LoadGrid();
			}
			catch (Exception^ ex) { ShowError(ex->Message); }
		}

		System::Void grid_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex < 0) return;
			DataGridViewRow^ r = grid->Rows[e->RowIndex];
			selectedId = Convert::ToInt32(r->Cells["Id"]->Value);
			txtName->Text = Convert::ToString(r->Cells["Name"]->Value);
			txtPhone->Text = Convert::ToString(r->Cells["Phone"]->Value);
			txtSupplies->Text = Convert::ToString(r->Cells["Supplies"]->Value);
		}
	};
}