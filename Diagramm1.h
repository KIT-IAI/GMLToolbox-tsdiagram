#pragma once

#include "AusblendenZeitreihen.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace  System::Windows::Forms::DataVisualization::Charting;

/// <summary>
/// Zusammenfassung für Diagramm
/// </summary>
public ref class Diagramm : public System::Windows::Forms::Form
{
  public:
    enum class AGGREGATION {  NONE, TAEGLICH, WOECHENTLICH, MONATLICH  };
    enum class AGGREGATION_TYP  {  SUMME, MITTELWERT  };

    public:
    Diagramm()
    {
      InitializeComponent();

//      m_pChartArea = chart1->ChartAreas[0];
//      m_pChartArea->AxisX->Title = "Zeit";

      m_hasDate = true;
      m_hasTime = true;

      m_valueAnz        = 0;
      m_valueAnzMin     = 24;
      m_missingValue    = 9.99E20;
      m_seriesAnz       = 0;
      m_chartAnzMax     = 5;

      m_startTime = nullptr;
      m_endTime   = nullptr;
      m_timeIncrement = nullptr;
      m_values = gcnew ArrayList;

      m_chartList = gcnew List<int>;

      m_showSeries = gcnew List<bool>;
      m_seriesText = gcnew List<String ^>;

//      comboBoxZeitaufloesung->SelectedIndex = 0;
      m_aggregation = AGGREGATION::NONE;

      m_aggregationTyp.Add ( AGGREGATION_TYP::MITTELWERT );
      m_aggregationTyp.Add ( AGGREGATION_TYP::MITTELWERT );
      m_aggregationTyp.Add ( AGGREGATION_TYP::MITTELWERT );
      m_aggregationTyp.Add ( AGGREGATION_TYP::MITTELWERT );
      m_aggregationTyp.Add ( AGGREGATION_TYP::MITTELWERT );
    }

  protected:
    /// <summary>
    /// Verwendete Ressourcen bereinigen.
    /// </summary>
    ~Diagramm()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
  protected: 

  private:
    /// <summary>
    /// Erforderliche Designervariable.
    DateTime ^  m_startTime;
    DateTime ^  m_endTime;
    TimeSpan ^  m_timeIncrement;
    double      m_missingValue;
    int         m_valueAnz;
    int         m_valueAnzMin;
    int         m_chartAnzMax;
    int         m_seriesAnz;
    ArrayList ^ m_values;
    List<int> ^ m_chartList;

    bool        m_hasDate;
    bool        m_hasTime;
    
    List<bool>    ^ m_showSeries;
    List<String^> ^ m_seriesText;

    int              startIndex;
    int              endIndex;
    int              valuesSpanAct;
    bool             zoomEnabled;
    int              zoomstufeAct;
    int              zoomstufeMax;

    List<int>                  ^ zoomIncrement;
    List<DateTimeIntervalType> ^ axisTypes;
    List<int>                  ^ axisOffsets;
    ArrayList                  ^ axisFormats;  

    AGGREGATION             m_aggregation;
    List<AGGREGATION_TYP>   m_aggregationTyp;

    bool        panEnabled;
    List<int> ^ panIncrement;
    int         panIncrementAct;

//    RegularTimeSeries  * m_pTimeSeries;
//    ChartArea          ^ m_pChartArea;
//    Series             ^ m_pSeries;
//    Legend             ^ m_pLegend;

    /// </summary>
    System::ComponentModel::Container ^components;
  private: System::Windows::Forms::ComboBox^  comboBoxZeitaufloesung;
  private: System::Windows::Forms::Label^  label1;
  private: System::Windows::Forms::Button^  buttonAusblenden;
  private: System::Windows::Forms::Button^  buttonBeenden;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Erforderliche Methode für die Designerunterstützung.
    /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
    /// </summary>
    void InitializeComponent(void)
    {
      System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
      System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
      System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
      System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
      System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
      System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
      System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
      System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
      System::Windows::Forms::DataVisualization::Charting::Legend^  legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
      System::Windows::Forms::DataVisualization::Charting::Legend^  legend5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
      this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
      this->buttonBeenden = (gcnew System::Windows::Forms::Button());
      this->comboBoxZeitaufloesung = (gcnew System::Windows::Forms::ComboBox());
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->buttonAusblenden = (gcnew System::Windows::Forms::Button());
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
      this->SuspendLayout();
      // 
      // chart1
      // 
      this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
        | System::Windows::Forms::AnchorStyles::Left)
        | System::Windows::Forms::AnchorStyles::Right));
      this->chart1->BackColor = System::Drawing::Color::LightGoldenrodYellow;
      chartArea1->AxisX->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
      chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
      chartArea1->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
      chartArea1->AxisY->Title = L"Y-Achse";
      chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
      chartArea1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)));
      chartArea1->Name = L"ChartArea1";
      chartArea1->Visible = false;
      chartArea2->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      chartArea2->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
      chartArea2->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      chartArea2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)));
      chartArea2->Name = L"ChartArea2";
      chartArea2->Visible = false;
      chartArea3->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      chartArea3->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
      chartArea3->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      chartArea3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)));
      chartArea3->Name = L"ChartArea3";
      chartArea3->Visible = false;
      chartArea4->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      chartArea4->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
      chartArea4->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      chartArea4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)));
      chartArea4->Name = L"ChartArea4";
      chartArea4->Visible = false;
      chartArea5->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      chartArea5->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
      chartArea5->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      chartArea5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)));
      chartArea5->Name = L"ChartArea5";
      chartArea5->Visible = false;
      this->chart1->ChartAreas->Add(chartArea1);
      this->chart1->ChartAreas->Add(chartArea2);
      this->chart1->ChartAreas->Add(chartArea3);
      this->chart1->ChartAreas->Add(chartArea4);
      this->chart1->ChartAreas->Add(chartArea5);
      legend1->DockedToChartArea = L"ChartArea1";
      legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
      legend1->IsDockedInsideChartArea = false;
      legend1->Name = L"Legend1";
      legend2->DockedToChartArea = L"ChartArea2";
      legend2->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
      legend2->IsDockedInsideChartArea = false;
      legend2->Name = L"Legend2";
      legend3->DockedToChartArea = L"ChartArea3";
      legend3->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
      legend3->IsDockedInsideChartArea = false;
      legend3->Name = L"Legend3";
      legend4->DockedToChartArea = L"ChartArea4";
      legend4->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
      legend4->IsDockedInsideChartArea = false;
      legend4->Name = L"Legend4";
      legend5->DockedToChartArea = L"ChartArea5";
      legend5->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
      legend5->IsDockedInsideChartArea = false;
      legend5->Name = L"Legend5";
      this->chart1->Legends->Add(legend1);
      this->chart1->Legends->Add(legend2);
      this->chart1->Legends->Add(legend3);
      this->chart1->Legends->Add(legend4);
      this->chart1->Legends->Add(legend5);
      this->chart1->Location = System::Drawing::Point(-7, 0);
      this->chart1->Margin = System::Windows::Forms::Padding(1);
      this->chart1->Name = L"chart1";
      this->chart1->Size = System::Drawing::Size(877, 598);
      this->chart1->TabIndex = 0;
      this->chart1->Text = L"chart1";
      this->chart1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Diagramm::chart1_KeyUp);
      this->chart1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Diagramm::chart1_MouseClick);
      this->chart1->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Diagramm::chart1_PreviewKeyDown);
      // 
      // buttonBeenden
      // 
      this->buttonBeenden->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
      this->buttonBeenden->DialogResult = System::Windows::Forms::DialogResult::Cancel;
      this->buttonBeenden->Location = System::Drawing::Point(782, 619);
      this->buttonBeenden->Name = L"buttonBeenden";
      this->buttonBeenden->Size = System::Drawing::Size(75, 37);
      this->buttonBeenden->TabIndex = 1;
      this->buttonBeenden->Text = L"Schließen";
      this->buttonBeenden->UseVisualStyleBackColor = true;
      this->buttonBeenden->Click += gcnew System::EventHandler(this, &Diagramm::buttonBeenden_Click);
      // 
      // comboBoxZeitaufloesung
      // 
      this->comboBoxZeitaufloesung->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
      this->comboBoxZeitaufloesung->FormattingEnabled = true;
      this->comboBoxZeitaufloesung->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Stunden", L"Tage", L"Wochen", L"Monate" });
      this->comboBoxZeitaufloesung->Location = System::Drawing::Point(12, 619);
      this->comboBoxZeitaufloesung->Name = L"comboBoxZeitaufloesung";
      this->comboBoxZeitaufloesung->Size = System::Drawing::Size(121, 21);
      this->comboBoxZeitaufloesung->TabIndex = 2;
      this->comboBoxZeitaufloesung->SelectedIndexChanged += gcnew System::EventHandler(this, &Diagramm::comboBoxZeitaufloesung_SelectedIndexChanged);
      // 
      // label1
      // 
      this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
      this->label1->AutoSize = true;
      this->label1->Location = System::Drawing::Point(9, 643);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(97, 13);
      this->label1->TabIndex = 3;
      this->label1->Text = L"Zeitliche Auflösung";
      // 
      // buttonAusblenden
      // 
      this->buttonAusblenden->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
      this->buttonAusblenden->Location = System::Drawing::Point(168, 619);
      this->buttonAusblenden->Name = L"buttonAusblenden";
      this->buttonAusblenden->Size = System::Drawing::Size(121, 37);
      this->buttonAusblenden->TabIndex = 13;
      this->buttonAusblenden->Text = L"Auswahl Zeitreihen";
      this->buttonAusblenden->UseVisualStyleBackColor = true;
      this->buttonAusblenden->Click += gcnew System::EventHandler(this, &Diagramm::buttonAusblenden_Click);
      // 
      // Diagramm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->AutoScroll = true;
      this->CancelButton = this->buttonBeenden;
      this->ClientSize = System::Drawing::Size(869, 676);
      this->Controls->Add(this->buttonAusblenden);
      this->Controls->Add(this->label1);
      this->Controls->Add(this->comboBoxZeitaufloesung);
      this->Controls->Add(this->buttonBeenden);
      this->Controls->Add(this->chart1);
      this->KeyPreview = true;
      this->Name = L"Diagramm";
      this->Text = L"Diagramm";
      this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Diagramm::Diagramm_KeyDown);
      this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Diagramm::Diagramm_KeyUp);
      this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Diagramm::Diagramm_MouseWheel);
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  

    /////////////////////////////////////////////////////
    //  Public Methoden

  public: System::Void setStartTime ( int year, int month, int day, int hour, int minute, int second )
          {
            if ( month > 0 && day > 0 )
            {
              if ( year <= 0 ) year = 2022;

              if ( hour >= 0 && minute >= 0 && second >= 0 )
              {
                m_startTime = gcnew DateTime ( year, month, day, hour, minute, second );
                m_hasTime = true;
                m_hasDate = true;
              }
              else
              {
                m_startTime = gcnew DateTime ( year, month, day );
                m_hasTime = false;
                m_hasDate = true;
              }
            }
            else
            {
              m_startTime = gcnew DateTime ( 2022, 1, 1, hour, minute, second );
              m_hasTime = true;
              m_hasDate = false;
            }
          }

  public: System::Void setEndTime ( int year, int month, int day, int hour, int minute, int second )
          {
            if ( month > 0 && day > 0 )
            {
              if ( year <= 0 ) year = 2022;

              if ( hour >= 0 && minute >= 0 && second >= 0 )
              {
                m_endTime = gcnew DateTime ( year, month, day, hour, minute, second );
                m_hasTime = true;
                m_hasDate = true;
              }
              else
              {
                m_endTime = gcnew DateTime ( year, month, day );
                m_hasTime = false;
                m_hasDate = true;
              }

            }
            else
            {
              m_endTime = gcnew DateTime ( 2022, 1, 1, hour, minute, second );
              m_hasTime = true;
              m_hasDate = false;
            }
          }

  public: System::Void setTimeIncrement ( int days, int hours, int minutes, int seconds )
          {
            m_timeIncrement = gcnew TimeSpan ( days, hours, minutes, seconds );
          }

  public: System::Void setValues(List<double> ^ values, String ^  theme, String ^ uom, int chartNum, AGGREGATION_TYP aggregationType)
          {
            setValues(values, theme, uom, chartNum, aggregationType, true);
          }

  public: System::Void setValues ( List<double> ^ values,  String ^  theme, String ^ uom, int chartNum, AGGREGATION_TYP aggregationType, bool showSerie )
          {
            List<double> ^ valueList = gcnew List<double>;

            if ( chartNum > m_chartAnzMax-1 )
              return;

            for ( int i = 0; i < values->Count; i++ )
              valueList->Add( values[i] );

            m_values->Add( valueList );

            m_aggregationTyp[chartNum] = aggregationType;

            m_chartList->Add( chartNum );

            m_showSeries->Add (showSerie);
            m_seriesText->Add( theme );

            m_seriesAnz++;

            Series ^  series = gcnew Series();
//            System::Windows::Forms::DataVisualization::Charting::Legend^  legend = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());

            String ^seriesName = String::Concat ( "Series", Convert::ToString ( m_seriesAnz ) );
//            String ^legendName = String::Concat ( "Legend", Convert::ToString ( m_seriesAnz ) );

            series->ChartArea = chart1->ChartAreas[chartNum]->Name;
            series->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
            series->EmptyPointStyle->Color = System::Drawing::Color::Red;
            series->EmptyPointStyle->MarkerColor = System::Drawing::Color::Fuchsia;
            series->EmptyPointStyle->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
            series->Legend = chart1->Legends[chartNum]->Name;;
            series->LegendText = theme;
            series->Name = seriesName;
            series->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
            series->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
            
            ChartArea ^ pChartArea = chart1->ChartAreas[chartNum];
            pChartArea->AxisY->Title = uom;
            this->chart1->Series->Add(series);

            int valueAnz = valueList->Count;
            if ( valueAnz < m_valueAnz || m_valueAnz == 0 )
            {
              m_valueAnz = valueAnz;
              prepareZoomstufen();
            }

            pChartArea->AxisX->IntervalOffsetType =  axisTypes[0];
            pChartArea->AxisX->IntervalOffset = axisOffsets[0];
            pChartArea->AxisX->MajorTickMark->IntervalOffset = axisOffsets[0];
            pChartArea->AxisX->MajorTickMark->IntervalOffsetType = axisTypes[0];
            pChartArea->AxisX->MajorTickMark->IntervalType = axisTypes[0];
            pChartArea->AxisX->LabelStyle->Format = dynamic_cast<String^>(axisFormats[0]);

            checkChartVisibility();
          }

  private: System::Void checkChartVisibility()
          {
            for (int i = 0; i < m_chartAnzMax; i++)
            {
              bool showChart = false;
              for (int j = 0; j < m_seriesAnz; j++)
              {
                if (m_chartList[j] == i && m_showSeries[j] == true)
                  showChart = true;
              }
              if (showChart)
                chart1->ChartAreas[i]->Visible = true;
              else
                chart1->ChartAreas[i]->Visible = false;
            }
          }

  public: System::Void setMissingValue ( double value )
          {
            m_missingValue = value;
          }

  public: System::Void initialize ()
          {
            comboBoxZeitaufloesung->SelectedIndex = 0;
          }


private: System::Void buttonBeenden_Click(System::Object^  sender, System::EventArgs^  e)
           {
             Close();
           }

private: System::Void prepareZoomstufen()
         {
           int valueAnz, zoomstufe, anzHours, anzHoursIncrement;

           zoomIncrement = gcnew List<int>;
           panIncrement  = gcnew List<int>;
           axisTypes     = gcnew List<DateTimeIntervalType>;
           axisOffsets   = gcnew List<int>;
           axisFormats   = gcnew ArrayList;

          anzHoursIncrement = 24*m_timeIncrement->Days + m_timeIncrement->Hours;

           zoomstufe = 0;
           valueAnz = m_valueAnz;
           if ( valueAnz <= m_valueAnz )
           {
             axisTypes->Add ( DateTimeIntervalType::Hours );
             axisOffsets->Add( 1 );
             axisFormats->Add ( "d" );
           }

           while ( valueAnz > m_valueAnzMin )
           {
             int inc = int ( valueAnz / 4.0 );
             zoomIncrement->Add(  inc );
//             valuesSpan->Add( valueAnz );
             panIncrement->Add( int ( valueAnz / 10.0) );
             
             zoomstufe++;
             valueAnz = valueAnz - 2*inc;
             anzHours = anzHoursIncrement * valueAnz;
             if ( anzHours > 2160 )
             {
               axisTypes->Add ( DateTimeIntervalType::Months );
               axisFormats->Add ( "d" );
               axisOffsets->Add( 1 );
             }
             else
             if ( anzHours > 720 )
             {
               axisTypes->Add ( DateTimeIntervalType::Days );
               axisFormats->Add ( "d" );
               axisOffsets->Add( 14 );
             }
             else
             if ( anzHours > 360 )
             {
               axisTypes->Add ( DateTimeIntervalType::Days );
               axisOffsets->Add( 7 );
               axisFormats->Add ( "d" );
             }
             else
             if ( anzHours > 180 )
             {
               axisTypes->Add ( DateTimeIntervalType::Days );
               axisOffsets->Add( 3 );
               axisFormats->Add ( "d" );
             }
             else
             if ( anzHours > 90 )
             {
               axisTypes->Add ( DateTimeIntervalType::Days );
               axisOffsets->Add( 1 );
               axisFormats->Add ( "d" );
             }
             else
             if ( anzHours > 45 )
             {
               axisTypes->Add ( DateTimeIntervalType::Hours );
               axisOffsets->Add( 12 );
               axisFormats->Add ( "g" );
             }
             else
             {
               axisTypes->Add ( DateTimeIntervalType::Hours );
               axisOffsets->Add( 6 );
               axisFormats->Add ( "g" );
             }

           }
           zoomstufeMax = zoomstufe;
           zoomstufeAct = 0;
           zoomEnabled = true;

           panEnabled  = false;
           panIncrementAct = 0;

           startIndex      = 0;
           endIndex        = m_valueAnz;
           valuesSpanAct   = m_valueAnz;


         }

private: System::Void comboBoxZeitaufloesung_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
         {
           int                            i, j, anz;
           double                         value;
           DateTime                     ^ dateTime;
           DataPoint                    ^ dataPoint;

           m_aggregation =  (Diagramm::AGGREGATION)comboBoxZeitaufloesung->SelectedIndex;

           if ( comboBoxZeitaufloesung->SelectedIndex == 0 )
           {
             zoomEnabled = true;

             fillChart();
             chart1->Focus();
           }
           else
           {
             List<double>    ^ values = gcnew List<double>;
             List<int>       ^ dateTimeIndices = gcnew List<int>;
             zoomEnabled = false;

//             m_pSeries->LegendText = String::Concat( m_theme, ", ", zeitaufloesung );
             for ( i = 0; i < m_chartAnzMax; i++ )
             {
               chart1->ChartAreas[i]->AxisX->IntervalOffsetType =  axisTypes[0];
               chart1->ChartAreas[i]->AxisX->IntervalOffset = axisOffsets[0];
               chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalOffset = axisOffsets[0];
               chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalOffsetType = axisTypes[0];
               chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalType = axisTypes[0];
               chart1->ChartAreas[i]->AxisX->LabelStyle->Format = dynamic_cast<String^>(axisFormats[0]);
             }

             for ( i = 0; i < m_seriesAnz; i++ )
             {
               Series ^ series = dynamic_cast<Series^>(this->chart1->Series[i]);

               series->Enabled = m_showSeries[i];

               series->Points->Clear();
               values->Clear();
               dateTimeIndices->Clear();

               anz = getValues( i, m_aggregation, m_aggregationTyp[m_chartList[i]], values, dateTimeIndices );
               for ( j = 0; j <anz; j++ )
               {
                 value = values[j];
                 dateTime = getTimePosition ( dateTimeIndices[j] );

                 dataPoint = gcnew DataPoint ();
                 if ( value == m_missingValue )
                 {
                   dataPoint->SetValueXY( dateTime, 0.0 );
                   dataPoint->IsEmpty = true;
                 }
                 else
                   dataPoint->SetValueXY( dateTime, value );

                 series->Points->Add( dataPoint);
               }
             }
           }
           chart1->Refresh();
         }

private: System::Void fillChart()
         {
           int           i, j;
           double        value;
           DateTime    ^ dateTime;
           DataPoint   ^ dataPoint;

           for ( i = 0; i < m_seriesAnz; i++ )
           {
             Series       ^ series = dynamic_cast<Series^>(this->chart1->Series[i]);
             List<double> ^ values  = dynamic_cast<List<double>^>(m_values[i]);
             if ( m_showSeries[i] )
               series->Enabled = true;
             else
               series->Enabled = false;

             series->Points->Clear();
             for ( j = startIndex; j < endIndex;  j++ )
             {
               value    = values[j];          
               dateTime =  getTimePosition ( j );

               dataPoint = gcnew DataPoint ();
               if ( value ==m_missingValue )
               {
                 dataPoint->SetValueXY( dateTime, 0.0 );
                 dataPoint->IsEmpty = true;
               }
               else
                 dataPoint->SetValueXY( dateTime, value );

               series->Points->Add( dataPoint);
             }
           }
         }


private: System::Void Diagramm_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^ e)
         {
           if ( !zoomEnabled )
             return;

            int delta = e->Delta;
            changeZoomstufe( delta );

         }

private: System::Void changeZoomstufe ( int delta )
         {
           if ( delta > 0 && zoomstufeAct < zoomstufeMax-1 )
           {
             startIndex = startIndex + zoomIncrement[zoomstufeAct];
             endIndex   = endIndex   - zoomIncrement[zoomstufeAct];
             valuesSpanAct = valuesSpanAct - 2*zoomIncrement[zoomstufeAct];

             zoomstufeAct++;
             panIncrementAct = panIncrement[zoomstufeAct];

             for ( int i = 0; i < m_chartAnzMax; i++ )
             {
               chart1->ChartAreas[i]->AxisX->IntervalOffsetType =  axisTypes[zoomstufeAct];
               chart1->ChartAreas[i]->AxisX->IntervalOffset = axisOffsets[zoomstufeAct];
               chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalOffset = axisOffsets[zoomstufeAct];
               chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalOffsetType = axisTypes[zoomstufeAct];
               chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalType = axisTypes[zoomstufeAct];
               chart1->ChartAreas[i]->AxisX->LabelStyle->Format = dynamic_cast<String^>(axisFormats[zoomstufeAct]);
             }

             fillChart();
           }
           else
           if ( delta < 0 && zoomstufeAct > 0 )
           {
             zoomstufeAct = zoomstufeAct - 1;
             valuesSpanAct      = valuesSpanAct + 2*zoomIncrement[zoomstufeAct];
             panIncrementAct = panIncrement[zoomstufeAct];             

             if ( endIndex + zoomIncrement[zoomstufeAct] <= m_valueAnz && startIndex - zoomIncrement[zoomstufeAct] >= 0 )
             {
               startIndex      = startIndex -  zoomIncrement[zoomstufeAct];
               endIndex        = endIndex   + zoomIncrement[zoomstufeAct];
             }
             else
             if ( endIndex + zoomIncrement[zoomstufeAct] > m_valueAnz )
             {
               startIndex = m_valueAnz - valuesSpanAct;
               endIndex   = m_valueAnz;
             }
             else
             {
               startIndex = 0;
               endIndex   = valuesSpanAct;
             }

             for ( int i = 0; i < m_chartAnzMax; i++ )
             {
                chart1->ChartAreas[i]->AxisX->IntervalOffsetType =  axisTypes[zoomstufeAct];
                chart1->ChartAreas[i]->AxisX->IntervalOffset = axisOffsets[zoomstufeAct];
                chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalOffset = axisOffsets[zoomstufeAct];
                chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalOffsetType = axisTypes[zoomstufeAct];
                chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalType = axisTypes[zoomstufeAct];
                chart1->ChartAreas[i]->AxisX->LabelStyle->Format = dynamic_cast<String^>(axisFormats[zoomstufeAct]);
             }

             fillChart();
           }
         }

private: System::Void Diagramm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
         {
         }

private: System::Void Diagramm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
         {
           if (e->KeyCode == Keys::Escape)
           {
             this->Close();
           }
         }

private: System::Void radioButtonZoom_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e)
         {
         }
private: System::Void chart1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
         {
           if ( zoomstufeAct == 0 )
             return;

           if ( e->KeyCode == System::Windows::Forms::Keys::Right )
           {
             if ( endIndex == m_valueAnz ) return;

             if ( endIndex + panIncrementAct <= m_valueAnz )
             {
               startIndex = startIndex + panIncrementAct;
               endIndex   = endIndex   + panIncrementAct;
             }
             else
             {
               endIndex = m_valueAnz;
               startIndex = m_valueAnz - valuesSpanAct;
             }
             fillChart();
           }
           else
           if ( e->KeyCode == System::Windows::Forms::Keys::Left )
           {
             if ( startIndex == 0 ) return;

             if ( startIndex - panIncrementAct >= 0 )
             {
               startIndex = startIndex - panIncrementAct;
               endIndex   = endIndex   - panIncrementAct;
             }
             else
             {
               startIndex = 0;
               endIndex   = valuesSpanAct;
             }
             fillChart();
           }
           else
           if ( e->KeyCode == System::Windows::Forms::Keys::Up )
             changeZoomstufe( 120 );
           else
           if ( e->KeyCode == System::Windows::Forms::Keys::Down )
             changeZoomstufe( -120 );
         }

private: System::Void chart1_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e)
         {
           if ( e->KeyCode == System::Windows::Forms::Keys::Right || 
                e->KeyCode == System::Windows::Forms::Keys::Left ||
                e->KeyCode == System::Windows::Forms::Keys::Up   ||
                e->KeyCode == System::Windows::Forms::Keys::Down )
             e->IsInputKey = true;
         }

private: System::Void chart1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
         {
           chart1->Focus();
         }

private: unsigned int getValues ( int index, AGGREGATION aggregation, AGGREGATION_TYP aggregationTyp, List<double> ^ valuesAggregated, List<int> ^ dateTimeIndices )
         {
           double         value, valueAggregated;
           int            anzValue, anzDay;
           int            month, day, ind;
           List<double> ^ values = dynamic_cast<List<double>^>(m_values[index]);

           valueAggregated = 0;
           anzValue        = 0;
           anzDay          = 0;
           month           = m_startTime->Month;
           day             = m_startTime->Day;
           DateTime ^ startTime = getTimePosition ( 0 );
           ind             = 0;

           for ( int i = 0; i  < m_valueAnz; i++ )
           {
             DateTime ^ actTime = getTimePosition( i );
             value = values[i];
             if ( aggregation == AGGREGATION::NONE )
             {
               valuesAggregated->Add( value );
               dateTimeIndices->Add( i );
               continue;
             }

             if ( actTime->Day != day && aggregation != AGGREGATION::MONATLICH )
             {
               anzDay++;
               day =  actTime->Day;
               if ( (aggregation == AGGREGATION::TAEGLICH && anzDay == 1) || (aggregation == AGGREGATION::WOECHENTLICH && anzDay == 7) )
               {
                 if ( anzValue > 0)
                 {
                   if ( aggregationTyp == AGGREGATION_TYP::MITTELWERT  )
                     valueAggregated = valueAggregated / anzValue;
                 }
                 else
                   valueAggregated = m_missingValue;

                 valuesAggregated->Add( valueAggregated );
                 dateTimeIndices->Add ( ind );

                 startTime = actTime;
                 ind       = i;
                 anzDay = 0;
                 anzValue = 0;
                 valueAggregated = 0.0;
               }
             }

             if ( actTime->Month != month && aggregation == AGGREGATION::MONATLICH )
             {
               month = actTime->Month;
               if ( anzValue > 0 )
               {
                 if ( aggregationTyp == AGGREGATION_TYP::MITTELWERT  )
                   valueAggregated = valueAggregated / anzValue;
               }
               else
                 valueAggregated =m_missingValue;

               valuesAggregated->Add( valueAggregated );
               dateTimeIndices->Add( ind );

               startTime = actTime;
               ind = i;
               anzValue = 0;
               valueAggregated = 0.0;
             }

             if ( value !=m_missingValue )
             {
               valueAggregated = valueAggregated + value;
               anzValue++;
             }
           }

           if ( anzValue > 0 )
           {
             if ( aggregationTyp == AGGREGATION_TYP::MITTELWERT  )
               valueAggregated = valueAggregated / anzValue;  
             else
               valueAggregated = m_missingValue;

             valuesAggregated->Add( valueAggregated );
             dateTimeIndices->Add( ind );
           }

           return valuesAggregated->Count;
         }

private: DateTime ^  getTimePosition( unsigned int count )
         {
           int days = m_timeIncrement->Days;
           int hours = m_timeIncrement->Hours;
           int minutes = m_timeIncrement->Minutes;
           int seconds = m_timeIncrement->Seconds;


           TimeSpan ^ timeSpan = gcnew TimeSpan ( days*count, hours*count, minutes*count, seconds*count );
           DateTime ^ newDateTime = gcnew DateTime;
           newDateTime = *m_startTime + *timeSpan;
           return newDateTime;         
         }


private: System::Void refreshSeries() 
         {
           int               i, j, anz;
           List<double>    ^ values = gcnew List<double>;
           List<int>       ^ dateTimeIndices = gcnew List<int>;
           double            value;
           DateTime        ^ dateTime;
           DataPoint       ^ dataPoint;

           for ( i = 0; i < m_seriesAnz; i++ )
           {
             Series ^ series = dynamic_cast<Series^>(this->chart1->Series[i]);

             series->Enabled = m_showSeries[i];

             series->Points->Clear();
             values->Clear();
             dateTimeIndices->Clear();

             anz = getValues( i, m_aggregation, m_aggregationTyp[m_chartList[i]], values, dateTimeIndices );
             for ( j = 0; j <anz; j++ )
             {
               value = values[j];
               dateTime = getTimePosition ( dateTimeIndices[j] );

               dataPoint = gcnew DataPoint ();
               if ( value == m_missingValue )
               {
                 dataPoint->SetValueXY( dateTime, 0.0 );
                 dataPoint->IsEmpty = true;
               }
               else
                 dataPoint->SetValueXY( dateTime, value );

               series->Points->Add( dataPoint);
             }
           }

           checkChartVisibility();

           chart1->Refresh();
         }

private: System::Void buttonAusblenden_Click(System::Object^  sender, System::EventArgs^  e)
         {
           AusblendenZeitreihen ^ pDialog = gcnew AusblendenZeitreihen ( m_seriesText, m_showSeries );

           System::Windows::Forms::DialogResult ok = pDialog->ShowDialog();

           if (  ok == System::Windows::Forms::DialogResult::OK )
           {
             pDialog->getResult( m_showSeries );
             refreshSeries();
           }
         }
};
