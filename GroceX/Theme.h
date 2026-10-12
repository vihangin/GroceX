#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

// Shared colours and a grid style so that all screens look the same.

inline Color greenColor() { return Color::FromArgb(46, 125, 50); }
inline Color lightColor() { return Color::FromArgb(241, 248, 233); }
inline Color redColor() { return Color::FromArgb(198, 40, 40); }

inline void styleGrid(DataGridView^ g)
{
	g->BackgroundColor = Color::White;
	g->BorderStyle = BorderStyle::None;
	g->EnableHeadersVisualStyles = false;
	g->ColumnHeadersDefaultCellStyle->BackColor = greenColor();
	g->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
	g->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 10.0f);
	g->ColumnHeadersHeight = 38;
	g->DefaultCellStyle->Font = gcnew System::Drawing::Font("Segoe UI", 10.0f);
	g->DefaultCellStyle->SelectionBackColor = Color::FromArgb(200, 230, 201);
	g->DefaultCellStyle->SelectionForeColor = Color::Black;
	g->AlternatingRowsDefaultCellStyle->BackColor = lightColor();
	g->RowHeadersVisible = false;
	g->AllowUserToAddRows = false;
	g->ReadOnly = true;
	g->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
	g->MultiSelect = false;
	g->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
}