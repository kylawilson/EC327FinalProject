//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "final_project_UI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::due_date_buttonClick(TObject *Sender)
{
			 String dateText=due_date_bar->Text;
			 due_date_box->Items->Add(dateText);

			 due_date_bar->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::class_buttonClick(TObject *Sender)
{
			String classText=class_bar->Text;
			 class_box->Items->Add(classText);

			 class_bar->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::assignment_add_buttonClick(TObject *Sender)
{
  String AssignmentText=assignment_bar->Text;
			 assignment_box->Items->Add(AssignmentText);

			 assignment_bar->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::assignment_boxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{
int index= Item->Index;
	assignment_box->Items->Delete(index);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::due_date_boxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{
           int index= Item->Index;
	due_date_box->Items->Delete(index);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::class_boxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{
int index= Item->Index;
	class_box->Items->Delete(index);
}
//---------------------------------------------------------------------------

