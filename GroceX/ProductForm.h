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

	// Screen 2: Manage products (Add / View / Update / Delete).
	ref class ProductForm : public System::Windows::Forms::Form
	{
	public:
		ProductForm(Database^ database)
		{
			InitializeComponent();
			db = database;
			selectedId = 0;

			// Grid styling + columns (kept in code so the designer stays simple)
			styleGrid(grid);
			grid->Columns->Add("Id", "ID");
			grid->Columns->Add("Name", "Name");
			grid->Columns->Add("Type", "Type");
			grid->Columns->Add("Price", "Price (Rs.)");
			grid->Columns->Add("Final", "Final Price (Rs.)");
			grid->Columns->Add("Qty", "Quantity");
			grid->Columns->Add("Stock", "Stock");
			grid->Columns["Id"]->FillWeight = 30;

			cmbType->SelectedIndex = 0;
			LoadGrid();
		}

	protected:
		~ProductForm()
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
		System::Windows::Forms::Label^ lblType;
		System::Windows::Forms::ComboBox^ cmbType;
		System::Windows::Forms::Label^ lblPrice;
		System::Windows::Forms::TextBox^ txtPrice;
		System::Windows::Forms::Label^ lblQty;
		System::Windows::Forms::TextBox^ txtQty;
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
			this->lblType = (gcnew System::Windows::Forms::Label());
			this->cmbType = (gcnew System::Windows::Forms::ComboBox());
			this->lblPrice = (gcnew System::Windows::Forms::Label());
			this->txtPrice = (gcnew System::Windows::Forms::TextBox());
			this->lblQty = (gcnew System::Windows::Forms::Label());
			this->txtQty = (gcnew System::Windows::Forms::TextBox());
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
			this->lblTitle->Text = L"Products";
			// 
			// panelLeft
			// 
			this->panelLeft->BackColor = System::Drawing::Color::FromArgb(241, 248, 233);
			this->panelLeft->Controls->Add(this->lblName);
			this->panelLeft->Controls->Add(this->txtName);
			this->panelLeft->Controls->Add(this->lblType);
			this->panelLeft->Controls->Add(this->cmbType);
			this->panelLeft->Controls->Add(this->lblPrice);
			this->panelLeft->Controls->Add(this->txtPrice);
			this->panelLeft->Controls->Add(this->lblQty);
			this->panelLeft->Controls->Add(this->txtQty);
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
			this->lblName->Size = System::Drawing::Size(74, 19);
			this->lblName->TabIndex = 0;
			this->lblName->Text = L"Item Name";
			// 
			// txtName
			// 
			this->txtName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtName->Location = System::Drawing::Point(20, 48);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(245, 25);
			this->txtName->TabIndex = 1;
			// 
			// lblType
			// 
			this->lblType->AutoSize = true;
			this->lblType->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblType->Location = System::Drawing::Point(20, 95);
			this->lblType->Name = L"lblType";
			this->lblType->Size = System::Drawing::Size(36, 19);
			this->lblType->TabIndex = 2;
			this->lblType->Text = L"Type";
			// 
			// cmbType
			// 
			this->cmbType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbType->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->cmbType->FormattingEnabled = true;
			this->cmbType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Fresh", L"Packaged" });
			this->cmbType->Location = System::Drawing::Point(20, 118);
			this->cmbType->Name = L"cmbType";
			this->cmbType->Size = System::Drawing::Size(245, 25);
			this->cmbType->TabIndex = 3;
			// 
			// lblPrice
			// 
			this->lblPrice->AutoSize = true;
			this->lblPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblPrice->Location = System::Drawing::Point(20, 165);
			this->lblPrice->Name = L"lblPrice";
			this->lblPrice->Size = System::Drawing::Size(74, 19);
			this->lblPrice->TabIndex = 4;
			this->lblPrice->Text = L"Price (Rs.)";
			// 
			// txtPrice
			// 
			this->txtPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPrice->Location = System::Drawing::Point(20, 188);
			this->txtPrice->Name = L"txtPrice";
			this->txtPrice->Size = System::Drawing::Size(245, 25);
			this->txtPrice->TabIndex = 5;
			// 
			// lblQty
			// 
			this->lblQty->AutoSize = true;
			this->lblQty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblQty->Location = System::Drawing::Point(20, 235);
			this->lblQty->Name = L"lblQty";
			this->lblQty->Size = System::Drawing::Size(60, 19);
			this->lblQty->TabIndex = 6;
			this->lblQty->Text = L"Quantity";
			// 
			// txtQty
			// 
			this->txtQty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtQty->Location = System::Drawing::Point(20, 258);
			this->txtQty->Name = L"txtQty";
			this->txtQty->Size = System::Drawing::Size(245, 25);
			this->txtQty->TabIndex = 7;
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::Color::FromArgb(46, 125, 50);
			this->btnAdd->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAdd->FlatAppearance->BorderSize = 0;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnAdd->ForeColor = System::Drawing::Color::White;
			this->btnAdd->Location = System::Drawing::Point(20, 320);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(118, 38);
			this->btnAdd->TabIndex = 8;
			this->btnAdd->Text = L"Add";
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &ProductForm::btnAdd_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::Color::FromArgb(245, 124, 0);
			this->btnUpdate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnUpdate->FlatAppearance->BorderSize = 0;
			this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnUpdate->ForeColor = System::Drawing::Color::White;
			this->btnUpdate->Location = System::Drawing::Point(147, 320);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(118, 38);
			this->btnUpdate->TabIndex = 9;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &ProductForm::btnUpdate_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::Color::FromArgb(198, 40, 40);
			this->btnDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDelete->FlatAppearance->BorderSize = 0;
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnDelete->ForeColor = System::Drawing::Color::White;
			this->btnDelete->Location = System::Drawing::Point(20, 368);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(118, 38);
			this->btnDelete->TabIndex = 10;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &ProductForm::btnDelete_Click);
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::FromArgb(96, 125, 139);
			this->btnClear->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnClear->FlatAppearance->BorderSize = 0;
			this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			this->btnClear->ForeColor = System::Drawing::Color::White;
			this->btnClear->Location = System::Drawing::Point(147, 368);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(118, 38);
			this->btnClear->TabIndex = 11;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &ProductForm::btnClear_Click);
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
			this->grid->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ProductForm::grid_CellClick);
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
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &ProductForm::txtSearch_TextChanged);
			// 
			// ProductForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1080, 600);
			this->Controls->Add(this->panelRight);
			this->Controls->Add(this->panelLeft);
			this->Controls->Add(this->panelHeader);
			this->MinimumSize = System::Drawing::Size(1000, 600);
			this->Name = L"ProductForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GroceX - Products";
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
			std::vector<GroceryItem*> items;
			try
			{
				items = db->getProducts(toNative(txtSearch->Text->Trim()));
				grid->Rows->Clear();
				for (size_t i = 0; i < items.size(); i++)
				{
					GroceryItem* item = items[i];

					// POLYMORPHISM in action: getFinalPrice() and isLowStock() behave
					// differently for Fresh and Packaged items, but we call them the same way.
					bool low = item->isLowStock();
					int row = grid->Rows->Add(gcnew array<Object^>{
						item->getId(),
						toManaged(item->getName()),
						toManaged(item->getTypeName()),
						String::Format("{0:0.00}", item->getPrice()),
						String::Format("{0:0.00}", item->getFinalPrice()),
						item->getQuantity(),
						low ? "LOW" : "OK" });
					if (low)
						grid->Rows[row]->Cells["Stock"]->Style->ForeColor = redColor();
				}
			}
			catch (Exception^ ex) { ShowError(ex->Message); }
			deleteAll(items);
		}

		// Adds or updates one product. "item" can be a FreshItem or a PackagedItem.
		void SaveProduct(GroceryItem& item, bool isNew)
		{
			if (isNew) db->addProduct(item); else db->updateProduct(item);
			ClearInputs();
			LoadGrid();
		}

		void Save(bool isNew)
		{
			try
			{
				if (!isNew && selectedId == 0) { ShowError("Select a product from the table first."); return; }
				double price;
				int qty;
				if (!Double::TryParse(txtPrice->Text, price)) { ShowError("Price must be a number."); return; }
				if (!Int32::TryParse(txtQty->Text, qty)) { ShowError("Quantity must be a whole number."); return; }

				std::string name = toNative(txtName->Text->Trim());
				int id = isNew ? 0 : selectedId;

				// Create a Fresh or Packaged object (the constructor checks the values)
				if (cmbType->Text == "Fresh")
				{
					FreshItem item(id, name, price, qty);
					SaveProduct(item, isNew);
				}
				else
				{
					PackagedItem item(id, name, price, qty);
					SaveProduct(item, isNew);
				}
			}
			catch (const std::invalid_argument& ex) { ShowError(toManaged(ex.what())); }
			catch (Exception^ ex) { ShowError("Database error: " + ex->Message); }
		}

		void ClearInputs()
		{
			selectedId = 0;
			txtName->Clear();
			txtPrice->Clear();
			txtQty->Clear();
			cmbType->SelectedIndex = 0;
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
			if (selectedId == 0) { ShowError("Select a product from the table first."); return; }
			if (MessageBox::Show("Delete this product?", "Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
				!= System::Windows::Forms::DialogResult::Yes) return;
			try
			{
				db->deleteProduct(selectedId);
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
			cmbType->SelectedItem = Convert::ToString(r->Cells["Type"]->Value);
			txtPrice->Text = Convert::ToString(r->Cells["Price"]->Value);
			txtQty->Text = Convert::ToString(r->Cells["Qty"]->Value);
		}
	};
}