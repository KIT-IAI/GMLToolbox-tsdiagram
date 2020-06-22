#pragma once


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
  using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Jahreswerte
	/// </summary>
	public ref class Jahreswerte : public System::Windows::Forms::Form
	{
	public:
		Jahreswerte( List<double> ^ werte, List<String^> ^ themen, List<String^> ^ uoms )
		{
			InitializeComponent();

      m_Werte  = werte;
      m_Themen = themen;
      m_Uoms   = uoms;

      initialize();
			
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Jahreswerte()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::DataGridView^  dataGridViewWerte;
  private: System::Windows::Forms::Button^  buttonBeenden;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

    List<double>  ^ m_Werte;
    List<String^> ^ m_Themen;
    List<String^> ^ m_Uoms;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
      this->dataGridViewWerte = ( gcnew System::Windows::Forms::DataGridView() );
      this->buttonBeenden = ( gcnew System::Windows::Forms::Button() );
      ( cli::safe_cast<System::ComponentModel::ISupportInitialize^>( this->dataGridViewWerte ) )->BeginInit();
      this->SuspendLayout();
      // 
      // dataGridViewWerte
      // 
      this->dataGridViewWerte->Anchor = static_cast<System::Windows::Forms::AnchorStyles>( ( ( ( System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom )
        | System::Windows::Forms::AnchorStyles::Left )
        | System::Windows::Forms::AnchorStyles::Right ) );
      this->dataGridViewWerte->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
      this->dataGridViewWerte->Location = System::Drawing::Point( 0, 2 );
      this->dataGridViewWerte->Name = L"dataGridViewWerte";
      this->dataGridViewWerte->Size = System::Drawing::Size( 418, 220 );
      this->dataGridViewWerte->TabIndex = 0;
      // 
      // buttonBeenden
      // 
      this->buttonBeenden->DialogResult = System::Windows::Forms::DialogResult::OK;
      this->buttonBeenden->Location = System::Drawing::Point( 333, 250 );
      this->buttonBeenden->Name = L"buttonBeenden";
      this->buttonBeenden->Size = System::Drawing::Size( 75, 23 );
      this->buttonBeenden->TabIndex = 1;
      this->buttonBeenden->Text = L"Beenden";
      this->buttonBeenden->UseVisualStyleBackColor = true;
      // 
      // Jahreswerte
      // 
      this->AcceptButton = this->buttonBeenden;
      this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size( 420, 285 );
      this->Controls->Add( this->buttonBeenden );
      this->Controls->Add( this->dataGridViewWerte );
      this->MaximizeBox = false;
      this->MinimizeBox = false;
      this->Name = L"Jahreswerte";
      this->Text = L"Jahreswerte";
      ( cli::safe_cast<System::ComponentModel::ISupportInitialize^>( this->dataGridViewWerte ) )->EndInit();
      this->ResumeLayout( false );

    }
#pragma endregion

  System::Void initialize()
  {
    String                   ^ STR;
    DataGridViewRow          ^ row;
    DataGridViewTextBoxCell  ^ cell;
    dataGridViewWerte->Rows->Clear();

    dataGridViewWerte->ColumnCount = 2;
    dataGridViewWerte->ColumnHeadersVisible = true;
    dataGridViewWerte->DefaultCellStyle->WrapMode = DataGridViewTriState::True;


    DataGridViewCellStyle ^ columnHeaderStyle = gcnew DataGridViewCellStyle;
    columnHeaderStyle->BackColor = Color::Aqua;
    columnHeaderStyle->Font = gcnew System::Drawing::Font( "Verdana", 8, FontStyle::Bold );
    columnHeaderStyle->WrapMode = DataGridViewTriState::True;

    dataGridViewWerte->ColumnHeadersDefaultCellStyle = columnHeaderStyle;
    dataGridViewWerte->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

    dataGridViewWerte->Columns[0]->Name = "Thema";
    dataGridViewWerte->Columns[1]->Name = "Jahreswert";

    for ( int i = 0; i < m_Werte->Count; i++ )
    {
      row = gcnew DataGridViewRow;
      cell = gcnew DataGridViewTextBoxCell;
      cell->Value = m_Themen[i];
      row->Cells->Add( cell );

      cell = gcnew DataGridViewTextBoxCell;
      STR = String ::Concat ( Double ( m_Werte[i] ).ToString ( "F2" ), " [", m_Uoms[i], "]" );
      cell->Value = STR;
      row->Cells->Add( cell );

      dataGridViewWerte->Rows->Add ( row );
    }
  
  }
  
  };
