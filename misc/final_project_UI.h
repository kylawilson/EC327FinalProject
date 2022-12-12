//---------------------------------------------------------------------------

#ifndef final_project_UIH
#define final_project_UIH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *assignment_bar;
	TListBox *assignment_box;
	TLabel *Label4;
	TEdit *due_date_bar;
	TButton *due_date_button;
	TListBox *due_date_box;
	TLabel *Label5;
	TEdit *class_bar;
	TButton *class_button;
	TListBox *class_box;
	TButton *assignment_add_button;
	void __fastcall due_date_buttonClick(TObject *Sender);
	void __fastcall class_buttonClick(TObject *Sender);
	void __fastcall assignment_add_buttonClick(TObject *Sender);
	void __fastcall assignment_boxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall due_date_boxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall class_boxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);



private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
