#pragma once


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
  using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Zusammenfassung für AusblendenZeitreihen
	/// </summary>
	public ref class AusblendenZeitreihen : public System::Windows::Forms::Form
	{
	public:
		AusblendenZeitreihen( List<String^> ^vThemen, List<bool> ^ vAnzeigen, List<double> ^vLiniendicken, 
							List<System::Drawing::Color> ^ vFarben, List<ChartDashStyle> ^ vLineStyles )
		{
      DataGridViewRow          ^ row;
      DataGridViewTextBoxCell  ^ textCell;
      DataGridViewCheckBoxCell ^ checkBoxCell; 
//			DataGridViewButtonCell   ^ buttonCell; 
			DataGridViewComboBoxCell ^ comboBoxCell; 
			int                        i;
			
			InitializeComponent();

			for ( i = 0; i < vThemen->Count; ++i )
				m_vThemen.Add ( vThemen[i] );

      for ( i = 0; i < vAnzeigen->Count; i++ )
        m_vAnzeigen.Add( vAnzeigen[i] );

			for ( i = 0; i < vLiniendicken->Count; ++i )
				m_vLiniendicken.Add ( vLiniendicken[i] );

			for ( i = 0; i < vFarben->Count; ++i )
				m_vFarben.Add ( vFarben[i] );

			for ( i = 0; i < vLineStyles->Count; ++i )
				m_vLineStyles.Add ( vLineStyles[i] );

      m_anz = vThemen->Count;

      dataGridViewAusblenden->ColumnCount = 5;
      dataGridViewAusblenden->ColumnHeadersVisible = true;

      dataGridViewAusblenden->DefaultCellStyle->WrapMode = DataGridViewTriState::True;

      DataGridViewCellStyle ^ columnHeaderStyle = gcnew DataGridViewCellStyle;
      columnHeaderStyle->BackColor = Color::Aqua;
      columnHeaderStyle->Font = gcnew System::Drawing::Font( "Verdana",8,FontStyle::Bold );
      columnHeaderStyle->WrapMode = DataGridViewTriState::True;

      dataGridViewAusblenden->ColumnHeadersDefaultCellStyle = columnHeaderStyle;
      dataGridViewAusblenden->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;

      dataGridViewAusblenden->Columns[0]->Name = "Zeitreihe        ";
      dataGridViewAusblenden->Columns[1]->Name = "Anzeigen";
			dataGridViewAusblenden->Columns[2]->Name = "Liniendicke";
			dataGridViewAusblenden->Columns[3]->Name = "Farbe";
			dataGridViewAusblenden->Columns[4]->Name = "Linienstil";

      for ( int i = 0; i < vThemen->Count; i++ )
      {
        row = gcnew DataGridViewRow;

        textCell = gcnew DataGridViewTextBoxCell;
        textCell->Value    = vThemen[i];
        row->Cells->Add( textCell );

        checkBoxCell = gcnew DataGridViewCheckBoxCell;
        row->Cells->Add( checkBoxCell );
        if ( vAnzeigen[i] )
          checkBoxCell->Value = true;
        else
          checkBoxCell->Value = false;

				textCell = gcnew DataGridViewTextBoxCell;
				textCell->Value = Convert::ToString ( vLiniendicken[i] );
				row->Cells->Add( textCell );
//				textCell->ReadOnly = true;

				textCell = gcnew DataGridViewTextBoxCell;
				textCell->Value = "Ändern";
				textCell->Style->BackColor = vFarben[i];
				row->Cells->Add( textCell );

				comboBoxCell = gcnew DataGridViewComboBoxCell;
				row->Cells->Add( comboBoxCell );
				comboBoxCell->Items->Add ( "Unbestimmt" );
				comboBoxCell->Items->Add ( "Gestrichelt" );
				comboBoxCell->Items->Add ( "Strich-Punkt Muster" );
				comboBoxCell->Items->Add ( "Strich-Punkt-Punkt Muster" );
				comboBoxCell->Items->Add ( "Gepunktet" );
				comboBoxCell->Items->Add ( "Durchgehend" );

				switch ( vLineStyles[i ] )
				{
				case ChartDashStyle::NotSet:
					comboBoxCell->Value = "Unbestimmt";
					break;

				case ChartDashStyle::Dash:
					comboBoxCell->Value = "Gestrichelt";
					break;

				case ChartDashStyle::DashDot:
					comboBoxCell->Value = "Strich-Punkt Muster";
					break;

				case ChartDashStyle::DashDotDot:
					comboBoxCell->Value = "Strich-Punkt-Punkt Muster";
					break;

				case ChartDashStyle::Dot:
					comboBoxCell->Value = "Gepunktet";
					break;

				case ChartDashStyle::Solid:
					comboBoxCell->Value = "Durchgehend";
					break;
				}		
        dataGridViewAusblenden->Rows->Add( row );
      }	
			System::Drawing::Size gridSize = dataGridViewAusblenden->Size;
			System::Drawing::Size controlSize = this->Size;
			this->Size = System::Drawing::Size ( gridSize.Width+100, controlSize.Height);
			
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

    List<bool>									 m_vAnzeigen;
		List<String^>								 m_vThemen;
		List<double>								 m_vLiniendicken;
		List<System::Drawing::Color> m_vFarben;
		List<ChartDashStyle>         m_vLineStyles;
    int													 m_anz;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridViewAusblenden = ( gcnew System::Windows::Forms::DataGridView () );
			this->buttonOk = ( gcnew System::Windows::Forms::Button () );
			this->buttonCancel = ( gcnew System::Windows::Forms::Button () );
			( cli::safe_cast<System::ComponentModel::ISupportInitialize^>( this->dataGridViewAusblenden ) )->BeginInit ();
			this->SuspendLayout ();
			// 
			// dataGridViewAusblenden
			// 
			this->dataGridViewAusblenden->Anchor = static_cast<System::Windows::Forms::AnchorStyles>( ( ( ( System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom )
				| System::Windows::Forms::AnchorStyles::Left )
				| System::Windows::Forms::AnchorStyles::Right ) );
			this->dataGridViewAusblenden->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAusblenden->Location = System::Drawing::Point ( 1, 0 );
			this->dataGridViewAusblenden->Name = L"dataGridViewAusblenden";
			this->dataGridViewAusblenden->Size = System::Drawing::Size ( 541, 237 );
			this->dataGridViewAusblenden->TabIndex = 0;
			this->dataGridViewAusblenden->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler ( this, &AusblendenZeitreihen::dataGridViewAusblenden_CellClick );
			// 
			// buttonOk
			// 
			this->buttonOk->Anchor = static_cast<System::Windows::Forms::AnchorStyles>( ( System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right ) );
			this->buttonOk->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonOk->Location = System::Drawing::Point ( 452, 260 );
			this->buttonOk->Name = L"buttonOk";
			this->buttonOk->Size = System::Drawing::Size ( 78, 23 );
			this->buttonOk->TabIndex = 1;
			this->buttonOk->Text = L"Übernehmen";
			this->buttonOk->UseVisualStyleBackColor = true;
			this->buttonOk->Click += gcnew System::EventHandler ( this, &AusblendenZeitreihen::buttonOk_Click );
			// 
			// buttonCancel
			// 
			this->buttonCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>( ( System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left ) );
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point ( 13, 260 );
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size ( 75, 23 );
			this->buttonCancel->TabIndex = 2;
			this->buttonCancel->Text = L"Abbrechen";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// AusblendenZeitreihen
			// 
			this->AcceptButton = this->buttonOk;
			this->AutoScaleDimensions = System::Drawing::SizeF ( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size ( 542, 298 );
			this->Controls->Add ( this->buttonCancel );
			this->Controls->Add ( this->buttonOk );
			this->Controls->Add ( this->dataGridViewAusblenden );
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AusblendenZeitreihen";
			this->Text = L"Einstellung der angezeigten Zeitreihen";
			( cli::safe_cast<System::ComponentModel::ISupportInitialize^>( this->dataGridViewAusblenden ) )->EndInit ();
			this->ResumeLayout ( false );

		}
#pragma endregion
  private: System::Void buttonOk_Click(System::Object^  sender, System::EventArgs^  e)
           {
						 String									  ^ STR;
						 DataGridViewTextBoxCell  ^ textBoxCell;
						 DataGridViewCheckBoxCell ^ checkBoxCell;
						 DataGridViewComboBoxCell ^ comboBoxCell;

             for ( int i = 0; i < m_anz; i++ )
             {
               DataGridViewRow ^ row = dataGridViewAusblenden->Rows[i];
							 
							 textBoxCell =  dynamic_cast<DataGridViewTextBoxCell^>(row->Cells[0]);
							 String ^ thema = dynamic_cast<String^>(textBoxCell->Value);
							 m_vThemen[i] = thema;

               checkBoxCell = dynamic_cast<DataGridViewCheckBoxCell^>(row->Cells[1]);
               System::Boolean select = (System::Boolean)(checkBoxCell->Value );
               if (select )
                 m_vAnzeigen[i] = true;
               else
                 m_vAnzeigen[i] = false;

							textBoxCell =  dynamic_cast<DataGridViewTextBoxCell^>(row->Cells[2]);
							STR = dynamic_cast<String^>(textBoxCell->Value);
							m_vLiniendicken[i] = Convert::ToDouble ( STR );

							textBoxCell = dynamic_cast<DataGridViewTextBoxCell^>(row->Cells[3]);
							System::Drawing::Color color = textBoxCell->Style->BackColor;
							m_vFarben[i] = color;

							comboBoxCell =  dynamic_cast<DataGridViewComboBoxCell^>(row->Cells[4]);
							STR = dynamic_cast<String^>(comboBoxCell->Value);

							if ( STR->CompareTo ( "Unbestimmt" ) == 0 )
								m_vLineStyles[i] = ChartDashStyle::NotSet;
							else
							if ( STR->CompareTo ( "Gestrichelt" ) == 0 )
								m_vLineStyles[i] = ChartDashStyle::Dash;
							else
							if ( STR->CompareTo ( "Strich-Punkt Muster" ) == 0 )
								m_vLineStyles[i] = ChartDashStyle::DashDot;
							else
							if ( STR->CompareTo ( "Strich-Punkt-Punkt Muster" ) == 0 )
								m_vLineStyles[i] = ChartDashStyle::DashDotDot;
							else
							if ( STR->CompareTo ( "Gepunktet" ) == 0 )
								m_vLineStyles[i] = ChartDashStyle::Dot;
							else
							if ( STR->CompareTo ( "Durchgehend" ) == 0 )
								m_vLineStyles[i] = ChartDashStyle::Solid;
             }
             Close();
           }

public: System::Void getResultAnzeige( List<bool> ^ result )
        {
          for ( int i = 0; i < m_anz; i++)
            result[i] = m_vAnzeigen[i];
        }

public: System::Void getResultThemen( List<String^> ^ result )
				{
					for ( int i = 0; i < m_anz; i++)
						result[i] = m_vThemen[i];
				}		

public: System::Void getResultLiniendicke( List<double> ^ result )
				{
					for ( int i = 0; i < m_anz; i++)
						result[i] = m_vLiniendicken[i];
				}

public: System::Void getResultFarbe( List<System::Drawing::Color> ^ result )
				{
					for ( int i = 0; i < m_anz; i++)
						result[i] = m_vFarben[i];
				}

public: System::Void getResultLineStyle( List<ChartDashStyle> ^ result )
				{
					for ( int i = 0; i < m_anz; i++)
						result[i] = m_vLineStyles[i];
				}

private: System::Void dataGridViewAusblenden_CellClick ( System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e )
{
	if ( e->ColumnIndex != 3 )
		return;

	int index = e->RowIndex;
	if ( index < 0 )
		return;

	System::Drawing::Color color = dataGridViewAusblenden->Rows[index]->Cells[3]->Style->BackColor;

	ColorDialog ^ colorDialog = gcnew ColorDialog;
	colorDialog->Color = color;
	System::Windows::Forms::DialogResult result = colorDialog->ShowDialog();
	if ( result == System::Windows::Forms::DialogResult::OK )
		dataGridViewAusblenden->Rows[index]->Cells[3]->Style->BackColor = colorDialog->Color;

	dataGridViewAusblenden->Refresh();
}
};
