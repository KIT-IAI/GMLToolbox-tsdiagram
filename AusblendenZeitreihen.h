#pragma once


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
  using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für AusblendenZeitreihen
	/// </summary>
	public ref class AusblendenZeitreihen : public System::Windows::Forms::Form
	{
	public:
		AusblendenZeitreihen( List<String^> ^vThemen, List<bool> ^ vAnzeigen )
		{
      DataGridViewRow          ^ row;
      DataGridViewTextBoxCell  ^ textCell;
      DataGridViewCheckBoxCell ^ checkBoxCell; 
      int                        i;

			InitializeComponent();

      for ( i = 0; i < vAnzeigen->Count; i++ )
        m_vAnzeigen.Add( vAnzeigen[i] );

      m_anz = vThemen->Count;

      dataGridViewAusblenden->ColumnCount = 2;
      dataGridViewAusblenden->ColumnHeadersVisible = true;

      dataGridViewAusblenden->DefaultCellStyle->WrapMode = DataGridViewTriState::True;


      DataGridViewCellStyle ^ columnHeaderStyle = gcnew DataGridViewCellStyle;
      columnHeaderStyle->BackColor = Color::Aqua;
      columnHeaderStyle->Font = gcnew System::Drawing::Font( "Verdana",8,FontStyle::Bold );
      columnHeaderStyle->WrapMode = DataGridViewTriState::True;

      dataGridViewAusblenden->ColumnHeadersDefaultCellStyle = columnHeaderStyle;
      dataGridViewAusblenden->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

      dataGridViewAusblenden->Columns[0]->Name = "Zeitreihe";
      dataGridViewAusblenden->Columns[0]->Width = 200;

      dataGridViewAusblenden->Columns[1]->Name = "Anzeigen";
      dataGridViewAusblenden->Columns[1]->Width = 100;

      for ( int i = 0; i < vThemen->Count; i++ )
      {
        row = gcnew DataGridViewRow;

        textCell = gcnew DataGridViewTextBoxCell;
        textCell->Value    = vThemen[i];
        row->Cells->Add( textCell );
        textCell->ReadOnly = true;

        checkBoxCell = gcnew DataGridViewCheckBoxCell;
        row->Cells->Add( checkBoxCell );
        if ( vAnzeigen[i] )
          checkBoxCell->Value = true;
        else
          checkBoxCell->Value = false;

        dataGridViewAusblenden->Rows->Add( row );
   }	
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~AusblendenZeitreihen()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::DataGridView^  dataGridViewAusblenden;
  private: System::Windows::Forms::Button^  buttonOk;
  private: System::Windows::Forms::Button^  buttonCancel;
  protected: 

  protected: 

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;
    List<bool> m_vAnzeigen;
    int        m_anz;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
      this->dataGridViewAusblenden = (gcnew System::Windows::Forms::DataGridView());
      this->buttonOk = (gcnew System::Windows::Forms::Button());
      this->buttonCancel = (gcnew System::Windows::Forms::Button());
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAusblenden))->BeginInit();
      this->SuspendLayout();
      // 
      // dataGridViewAusblenden
      // 
      this->dataGridViewAusblenden->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
        | System::Windows::Forms::AnchorStyles::Left)
        | System::Windows::Forms::AnchorStyles::Right));
      this->dataGridViewAusblenden->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
      this->dataGridViewAusblenden->Location = System::Drawing::Point(1, 0);
      this->dataGridViewAusblenden->Name = L"dataGridViewAusblenden";
      this->dataGridViewAusblenden->Size = System::Drawing::Size(385, 237);
      this->dataGridViewAusblenden->TabIndex = 0;
      // 
      // buttonOk
      // 
      this->buttonOk->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
      this->buttonOk->DialogResult = System::Windows::Forms::DialogResult::OK;
      this->buttonOk->Location = System::Drawing::Point(296, 260);
      this->buttonOk->Name = L"buttonOk";
      this->buttonOk->Size = System::Drawing::Size(78, 23);
      this->buttonOk->TabIndex = 1;
      this->buttonOk->Text = L"Übernehmen";
      this->buttonOk->UseVisualStyleBackColor = true;
      this->buttonOk->Click += gcnew System::EventHandler(this, &AusblendenZeitreihen::buttonOk_Click);
      // 
      // buttonCancel
      // 
      this->buttonCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
      this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
      this->buttonCancel->Location = System::Drawing::Point(13, 260);
      this->buttonCancel->Name = L"buttonCancel";
      this->buttonCancel->Size = System::Drawing::Size(75, 23);
      this->buttonCancel->TabIndex = 2;
      this->buttonCancel->Text = L"Abbrechen";
      this->buttonCancel->UseVisualStyleBackColor = true;
      // 
      // AusblendenZeitreihen
      // 
      this->AcceptButton = this->buttonOk;
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->CancelButton = this->buttonCancel;
      this->ClientSize = System::Drawing::Size(386, 298);
      this->Controls->Add(this->buttonCancel);
      this->Controls->Add(this->buttonOk);
      this->Controls->Add(this->dataGridViewAusblenden);
      this->MaximizeBox = false;
      this->MinimizeBox = false;
      this->Name = L"AusblendenZeitreihen";
      this->Text = L"Einstellung der angezeigten Zeitreihen";
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAusblenden))->EndInit();
      this->ResumeLayout(false);

    }
#pragma endregion
  private: System::Void buttonOk_Click(System::Object^  sender, System::EventArgs^  e)
           {
             for ( int i = 0; i < m_anz; i++ )
             {
               DataGridViewRow ^ row = dataGridViewAusblenden->Rows[i];
               DataGridViewCheckBoxCell ^ checkBoxCell = dynamic_cast<DataGridViewCheckBoxCell^>(row->Cells[1]);
               System::Boolean select = (System::Boolean)(checkBoxCell->Value );
               if (select )
                 m_vAnzeigen[i] = true;
               else
                 m_vAnzeigen[i] = false;
             }
             Close();
           }

public: System::Void getResult( List<bool> ^ result )
        {
          for ( int i = 0; i < m_anz; i++)
            result[i] = m_vAnzeigen[i];
        }
};
