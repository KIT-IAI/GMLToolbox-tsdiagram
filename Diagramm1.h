#pragma once

#include "AusblendenZeitreihen.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;
using namespace System::Windows::Forms::DataVisualization::Charting;

/// <summary>
/// Zusammenfassung für Diagramm
/// </summary>
public ref class Diagramm : public System::Windows::Forms::Form
{
public:
  enum class AGGREGATION { NONE, TAEGLICH, WOECHENTLICH, MONATLICH };
  enum class AGGREGATION_TYP { SUMME, MITTELWERT };

  typedef List<double> DataValues;

public:
  Diagramm()
  {
    InitializeComponent();

    m_hasDate = true;
    m_hasTime = true;

    m_valueAnz = 0;
    m_valueAnzMin = 24;
    m_missingValue = 9.99E20;
    m_seriesAnz = 0;
    m_chartAnzMax = 5;

    m_startTime = nullptr;
    m_endTime = nullptr;
    m_timeIncrement = nullptr;
    m_values = gcnew List<DataValues^>;

    m_chartList = gcnew List<int>;

    m_showSeries = gcnew List<bool>;
    m_seriesText = gcnew List<String ^>;

    m_nZoomLevel = 0;

    //      comboBoxZeitaufloesung->SelectedIndex = 0;
    m_aggregation = AGGREGATION::NONE;
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

private:
  System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;

private:
  /// <summary>
  /// Erforderliche Designervariable.
  DateTime ^  m_startTime;
  DateTime ^  m_endTime;
  DateTime ^  m_startTimeDisplay;
  DateTime ^  m_endTimeDisplay;
  TimeSpan ^  m_timeIncrement;
  double      m_missingValue;
  int         m_valueAnz;
  int         m_valueAnzMin;
  int         m_chartAnzMax;
  int         m_seriesAnz;
  List<DataValues^> ^ m_values;
  List<int> ^ m_chartList;

  bool        m_hasDate;
  bool        m_hasTime;

  List<bool>    ^ m_showSeries;
  List<String^> ^ m_seriesText;

  int         m_nZoomLevel;

  AGGREGATION       m_aggregation;
  Dictionary<int, AGGREGATION_TYP>   m_aggregationTyp;

  bool        panEnabled;
  List<int> ^ panIncrement;
  int         panIncrementAct;

private: System::ComponentModel::Container ^components;
private: System::Windows::Forms::ComboBox^  comboBoxZeitaufloesung;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Button^  buttonAusblenden;
private: System::Windows::Forms::CheckBox^  checkBoxZeitraum;
private: System::Windows::Forms::DateTimePicker^  ctlEndDate;
private: System::Windows::Forms::DateTimePicker^  ctlStartDate;
private: System::Windows::Forms::Label^  lblStartDateDisplay;
private: System::Windows::Forms::Label^  lblEndDateDisplay;
private: System::Windows::Forms::Button^  buttonExportZeitreihen;
private: System::Windows::Forms::SaveFileDialog^  saveFileDialogZeitreihen;
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
           this->checkBoxZeitraum = (gcnew System::Windows::Forms::CheckBox());
           this->ctlEndDate = (gcnew System::Windows::Forms::DateTimePicker());
           this->ctlStartDate = (gcnew System::Windows::Forms::DateTimePicker());
           this->lblStartDateDisplay = (gcnew System::Windows::Forms::Label());
           this->lblEndDateDisplay = (gcnew System::Windows::Forms::Label());
           this->buttonExportZeitreihen = (gcnew System::Windows::Forms::Button());
           this->saveFileDialogZeitreihen = (gcnew System::Windows::Forms::SaveFileDialog());
           (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
           this->SuspendLayout();
           // 
           // chart1
           // 
           this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
             | System::Windows::Forms::AnchorStyles::Left)
             | System::Windows::Forms::AnchorStyles::Right));
           this->chart1->BackColor = System::Drawing::Color::LightGoldenrodYellow;
           chartArea1->AxisX->Crossing = 1.7976931348623157E+308;
           chartArea1->AxisX->IsLabelAutoFit = false;
           chartArea1->AxisX->IsMarginVisible = false;
           chartArea1->AxisX->LabelAutoFitStyle = static_cast<System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles>(((System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::IncreaseFont | System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::DecreaseFont)
             | System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::WordWrap));
           chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::DeepSkyBlue;
           chartArea1->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
           chartArea1->AxisX->ScrollBar->BackColor = System::Drawing::SystemColors::ButtonFace;
           chartArea1->AxisX->ScrollBar->ButtonColor = System::Drawing::SystemColors::ScrollBar;
           chartArea1->AxisX->ScrollBar->IsPositionedInside = false;
           chartArea1->AxisX->ScrollBar->LineColor = System::Drawing::SystemColors::ActiveCaptionText;
           chartArea1->AxisX->ScrollBar->Size = 16;
           chartArea1->AxisX->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
           chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
           chartArea1->AxisY->IsLabelAutoFit = false;
           chartArea1->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
           chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
             static_cast<System::Byte>(0)));
           chartArea1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
             static_cast<System::Int32>(static_cast<System::Byte>(255)));
           chartArea1->Name = L"ChartArea1";
           chartArea1->Visible = false;
           chartArea2->AxisX->Crossing = 1.7976931348623157E+308;
           chartArea2->AxisX->IsLabelAutoFit = false;
           chartArea2->AxisX->IsMarginVisible = false;
           chartArea2->AxisX->LabelAutoFitStyle = static_cast<System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles>(((System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::IncreaseFont | System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::DecreaseFont)
             | System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::WordWrap));
           chartArea2->AxisX->MajorGrid->LineColor = System::Drawing::Color::DeepSkyBlue;
           chartArea2->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
           chartArea2->AxisX->ScrollBar->BackColor = System::Drawing::SystemColors::ButtonFace;
           chartArea2->AxisX->ScrollBar->ButtonColor = System::Drawing::SystemColors::ScrollBar;
           chartArea2->AxisX->ScrollBar->IsPositionedInside = false;
           chartArea2->AxisX->ScrollBar->LineColor = System::Drawing::SystemColors::ActiveCaptionText;
           chartArea2->AxisX->ScrollBar->Size = 16;
           chartArea2->AxisX->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
           chartArea2->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
           chartArea2->AxisY->IsLabelAutoFit = false;
           chartArea2->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
           chartArea2->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
           chartArea2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
             static_cast<System::Int32>(static_cast<System::Byte>(255)));
           chartArea2->Name = L"ChartArea2";
           chartArea2->Visible = false;
           chartArea3->AxisX->Crossing = 1.7976931348623157E+308;
           chartArea3->AxisX->IsLabelAutoFit = false;
           chartArea3->AxisX->IsMarginVisible = false;
           chartArea3->AxisX->LabelAutoFitStyle = static_cast<System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles>(((System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::IncreaseFont | System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::DecreaseFont)
             | System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::WordWrap));
           chartArea3->AxisX->MajorGrid->LineColor = System::Drawing::Color::DeepSkyBlue;
           chartArea3->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
           chartArea3->AxisX->ScrollBar->BackColor = System::Drawing::SystemColors::ButtonFace;
           chartArea3->AxisX->ScrollBar->ButtonColor = System::Drawing::SystemColors::ScrollBar;
           chartArea3->AxisX->ScrollBar->IsPositionedInside = false;
           chartArea3->AxisX->ScrollBar->LineColor = System::Drawing::SystemColors::ActiveCaptionText;
           chartArea3->AxisX->ScrollBar->Size = 16;
           chartArea3->AxisX->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
           chartArea3->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
           chartArea3->AxisY->IsLabelAutoFit = false;
           chartArea3->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
           chartArea3->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
           chartArea3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
             static_cast<System::Int32>(static_cast<System::Byte>(255)));
           chartArea3->Name = L"ChartArea3";
           chartArea3->Visible = false;
           chartArea4->AxisX->Crossing = 1.7976931348623157E+308;
           chartArea4->AxisX->IsLabelAutoFit = false;
           chartArea4->AxisX->IsMarginVisible = false;
           chartArea4->AxisX->LabelAutoFitStyle = static_cast<System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles>(((System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::IncreaseFont | System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::DecreaseFont)
             | System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::WordWrap));
           chartArea4->AxisX->MajorGrid->LineColor = System::Drawing::Color::DeepSkyBlue;
           chartArea4->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
           chartArea4->AxisX->ScrollBar->BackColor = System::Drawing::SystemColors::ButtonFace;
           chartArea4->AxisX->ScrollBar->ButtonColor = System::Drawing::SystemColors::ScrollBar;
           chartArea4->AxisX->ScrollBar->IsPositionedInside = false;
           chartArea4->AxisX->ScrollBar->LineColor = System::Drawing::SystemColors::ActiveCaptionText;
           chartArea4->AxisX->ScrollBar->Size = 16;
           chartArea4->AxisX->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
           chartArea4->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
           chartArea4->AxisY->IsLabelAutoFit = false;
           chartArea4->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
           chartArea4->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
           chartArea4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
             static_cast<System::Int32>(static_cast<System::Byte>(255)));
           chartArea4->Name = L"ChartArea4";
           chartArea4->Visible = false;
           chartArea5->AxisX->Crossing = 1.7976931348623157E+308;
           chartArea5->AxisX->IsLabelAutoFit = false;
           chartArea5->AxisX->IsMarginVisible = false;
           chartArea5->AxisX->LabelAutoFitStyle = static_cast<System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles>(((System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::IncreaseFont | System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::DecreaseFont)
             | System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::WordWrap));
           chartArea5->AxisX->MajorGrid->LineColor = System::Drawing::Color::DeepSkyBlue;
           chartArea5->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
           chartArea5->AxisX->ScrollBar->BackColor = System::Drawing::SystemColors::ButtonFace;
           chartArea5->AxisX->ScrollBar->ButtonColor = System::Drawing::SystemColors::ScrollBar;
           chartArea5->AxisX->ScrollBar->IsPositionedInside = false;
           chartArea5->AxisX->ScrollBar->LineColor = System::Drawing::SystemColors::ActiveCaptionText;
           chartArea5->AxisX->ScrollBar->Size = 16;
           chartArea5->AxisX->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
           chartArea5->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
           chartArea5->AxisY->IsLabelAutoFit = false;
           chartArea5->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Rotated270;
           chartArea5->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
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
           this->chart1->Location = System::Drawing::Point(0, 0);
           this->chart1->Margin = System::Windows::Forms::Padding(0);
           this->chart1->Name = L"chart1";
           this->chart1->Size = System::Drawing::Size(868, 598);
           this->chart1->TabIndex = 0;
           this->chart1->Text = L"chart1";
           this->chart1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Diagramm::chart1_KeyDown);
           this->chart1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Diagramm::chart1_MouseClick);
           this->chart1->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Diagramm::chart1_PreviewKeyDown);
           // 
           // buttonBeenden
           // 
           this->buttonBeenden->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
           this->buttonBeenden->DialogResult = System::Windows::Forms::DialogResult::Cancel;
           this->buttonBeenden->Location = System::Drawing::Point(730, 619);
           this->buttonBeenden->Name = L"buttonBeenden";
           this->buttonBeenden->Size = System::Drawing::Size(120, 37);
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
           this->buttonAusblenden->Location = System::Drawing::Point(150, 619);
           this->buttonAusblenden->Name = L"buttonAusblenden";
           this->buttonAusblenden->Size = System::Drawing::Size(120, 37);
           this->buttonAusblenden->TabIndex = 13;
           this->buttonAusblenden->Text = L"Auswahl Zeitreihen";
           this->buttonAusblenden->UseVisualStyleBackColor = true;
           this->buttonAusblenden->Click += gcnew System::EventHandler(this, &Diagramm::buttonAusblenden_Click);
           // 
           // checkBoxZeitraum
           // 
           this->checkBoxZeitraum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
           this->checkBoxZeitraum->AutoSize = true;
           this->checkBoxZeitraum->Checked = true;
           this->checkBoxZeitraum->CheckState = System::Windows::Forms::CheckState::Checked;
           this->checkBoxZeitraum->Location = System::Drawing::Point(289, 630);
           this->checkBoxZeitraum->Margin = System::Windows::Forms::Padding(2);
           this->checkBoxZeitraum->Name = L"checkBoxZeitraum";
           this->checkBoxZeitraum->Size = System::Drawing::Size(67, 17);
           this->checkBoxZeitraum->TabIndex = 14;
           this->checkBoxZeitraum->Text = L"Zeitraum";
           this->checkBoxZeitraum->UseVisualStyleBackColor = true;
           this->checkBoxZeitraum->CheckedChanged += gcnew System::EventHandler(this, &Diagramm::checkBoxZeitraum_CheckedChanged);
           // 
           // ctlEndDate
           // 
           this->ctlEndDate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
           this->ctlEndDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
           this->ctlEndDate->Location = System::Drawing::Point(460, 619);
           this->ctlEndDate->Name = L"ctlEndDate";
           this->ctlEndDate->Size = System::Drawing::Size(84, 20);
           this->ctlEndDate->TabIndex = 27;
           this->ctlEndDate->ValueChanged += gcnew System::EventHandler(this, &Diagramm::ctlStartEndDate_ValueChanged);
           // 
           // ctlStartDate
           // 
           this->ctlStartDate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
           this->ctlStartDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
           this->ctlStartDate->Location = System::Drawing::Point(370, 619);
           this->ctlStartDate->Name = L"ctlStartDate";
           this->ctlStartDate->Size = System::Drawing::Size(84, 20);
           this->ctlStartDate->TabIndex = 26;
           this->ctlStartDate->ValueChanged += gcnew System::EventHandler(this, &Diagramm::ctlStartEndDate_ValueChanged);
           // 
           // lblStartDateDisplay
           // 
           this->lblStartDateDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
           this->lblStartDateDisplay->AutoSize = true;
           this->lblStartDateDisplay->Location = System::Drawing::Point(370, 643);
           this->lblStartDateDisplay->Name = L"lblStartDateDisplay";
           this->lblStartDateDisplay->Size = System::Drawing::Size(75, 13);
           this->lblStartDateDisplay->TabIndex = 28;
           this->lblStartDateDisplay->Text = L"Anfangsdatum";
           // 
           // lblEndDateDisplay
           // 
           this->lblEndDateDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
           this->lblEndDateDisplay->AutoSize = true;
           this->lblEndDateDisplay->Location = System::Drawing::Point(460, 643);
           this->lblEndDateDisplay->Name = L"lblEndDateDisplay";
           this->lblEndDateDisplay->Size = System::Drawing::Size(55, 13);
           this->lblEndDateDisplay->TabIndex = 29;
           this->lblEndDateDisplay->Text = L"Enddatum";
           // 
           // buttonExportZeitreihen
           // 
           this->buttonExportZeitreihen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
           this->buttonExportZeitreihen->Location = System::Drawing::Point(581, 619);
           this->buttonExportZeitreihen->Name = L"buttonExportZeitreihen";
           this->buttonExportZeitreihen->Size = System::Drawing::Size(120, 37);
           this->buttonExportZeitreihen->TabIndex = 26;
           this->buttonExportZeitreihen->Text = L"Export Zeitreihen";
           this->buttonExportZeitreihen->UseVisualStyleBackColor = true;
           this->buttonExportZeitreihen->Click += gcnew System::EventHandler(this, &Diagramm::buttonExportZeitreihen_Click);
           // 
           // saveFileDialogZeitreihen
           // 
           this->saveFileDialogZeitreihen->Filter = L"(*.csv)|*.csv";
           this->saveFileDialogZeitreihen->Title = L"Export der gewählten Zeitreihen ";
           // 
           // Diagramm
           // 
           this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
           this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
           this->AutoScroll = true;
           this->CancelButton = this->buttonBeenden;
           this->ClientSize = System::Drawing::Size(869, 676);
           this->Controls->Add(this->lblEndDateDisplay);
           this->Controls->Add(this->lblStartDateDisplay);
           this->Controls->Add(this->ctlEndDate);
           this->Controls->Add(this->ctlStartDate);
           this->Controls->Add(this->checkBoxZeitraum);
           this->Controls->Add(this->buttonAusblenden);
           this->Controls->Add(this->label1);
           this->Controls->Add(this->comboBoxZeitaufloesung);
           this->Controls->Add(this->buttonExportZeitreihen);
           this->Controls->Add(this->buttonBeenden);
           this->Controls->Add(this->chart1);
           this->KeyPreview = true;
           this->Name = L"Diagramm";
           this->Text = L"Diagramm";
           this->Shown += gcnew System::EventHandler(this, &Diagramm::Diagramm_Shown);
           this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Diagramm::Diagramm_KeyDown);
           this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Diagramm::Diagramm_MouseWheel);
           (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
           this->ResumeLayout(false);
           this->PerformLayout();

         }
#pragma endregion

#pragma region Public Accessors

public: System::Void setStartTime(int year, int month, int day, int hour, int minute, int second)
{
  if (month > 0 && day > 0)
  {
    if (year <= 0) year = 2022;

    if (hour >= 0 && minute >= 0 && second >= 0)
    {
      m_startTime = gcnew DateTime(year, month, day, hour, minute, second);
      m_hasTime = true;
      m_hasDate = true;
    }
    else
    {
      m_startTime = gcnew DateTime(year, month, day);
      m_hasTime = false;
      m_hasDate = true;
    }
  }
  else
  {
    m_startTime = gcnew DateTime(2022, 1, 1, hour, minute, second);
    m_hasTime = true;
    m_hasDate = false;
  }
  m_startTimeDisplay = m_startTime;

  updateDateControlLimits();
}

public: System::Void setEndTime(int year, int month, int day, int hour, int minute, int second)
{
  if (month > 0 && day > 0)
  {
    if (year <= 0) year = 2022;

    if (hour >= 0 && minute >= 0 && second >= 0)
    {
      m_endTime = gcnew DateTime(year, month, day, hour, minute, second);
      m_hasTime = true;
      m_hasDate = true;
    }
    else
    {
      m_endTime = gcnew DateTime(year, month, day);
      m_hasTime = false;
      m_hasDate = true;
    }

  }
  else
  {
    m_endTime = gcnew DateTime(2022, 1, 1, hour, minute, second);
    m_hasTime = true;
    m_hasDate = false;
  }
  m_endTimeDisplay = m_endTime;

  updateDateControlLimits();
}

public: System::Void setTimeIncrement(int days, int hours, int minutes, int seconds)
{
  m_timeIncrement = gcnew TimeSpan(days, hours, minutes, seconds);
}

public: System::Void setValues(DataValues ^ values, String ^  theme, String ^ uom, int chartNum, AGGREGATION_TYP aggregationType)
{
  setValues(values, theme, uom, chartNum, aggregationType, true);
}

public: System::Void setValues(DataValues ^ values, String ^  theme, String ^ uom, int chartNum, AGGREGATION_TYP aggregationType, bool showSerie)
{
  if (chartNum > m_chartAnzMax - 1)
    return;

  // TODO: Warum werden die Daten hier kopiert? Darf der Aufrufer die Daten beliebig ändern?
  DataValues ^ valueList = gcnew DataValues(values);

  m_values->Add(valueList);

  m_aggregationTyp[chartNum] = aggregationType;

  m_chartList->Add(chartNum);

  m_showSeries->Add(showSerie);
  m_seriesText->Add(theme);

  m_seriesAnz++;

  Series ^  series = gcnew Series();

  String ^seriesName = String::Concat("Series", Convert::ToString(m_seriesAnz));

  series->ChartArea = chart1->ChartAreas[chartNum]->Name;
  series->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
  series->EmptyPointStyle->Color = System::Drawing::Color::Red;
  series->EmptyPointStyle->MarkerColor = System::Drawing::Color::Fuchsia;
  series->EmptyPointStyle->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
  series->Legend = chart1->Legends[chartNum]->Name;
  series->LegendText = theme;
  series->Name = seriesName;
  series->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
  series->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
  series->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;

  ChartArea ^ pChartArea = chart1->ChartAreas[chartNum];
  pChartArea->AxisY->Title = uom;
  this->chart1->Series->Add(series);

  int valueAnz = valueList->Count;
  if (valueAnz < m_valueAnz || m_valueAnz == 0)
  {
    m_valueAnz = valueAnz;
    //prepareZoomstufen();
  }

  checkChartVisibility();
}

public: System::Void setMissingValue(double value)
{
  m_missingValue = value;
}

#pragma endregion

#pragma region Drawing helpers

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

private: System::Void FillDataSeries()
{
  List<double>    ^ values = gcnew List<double>;
  List<int>       ^ dateTimeIndices = gcnew List<int>;

  // For some aggregation types we modifiy the timestamp to have the value in the middle of an interval
  TimeSpan tmOffset;
  switch (m_aggregation)
  {
  case AGGREGATION::TAEGLICH:
    tmOffset = TimeSpan::FromHours(12);
    break;

  case AGGREGATION::WOECHENTLICH:
    tmOffset = TimeSpan::FromHours(3 * 24 + 12);
    break;

  case AGGREGATION::MONATLICH:
    tmOffset = TimeSpan::FromDays(15);
    break;
  }

  for (int i = 0; i < m_seriesAnz; i++)
  {
    Series ^ series = this->chart1->Series[i];
    series->Enabled = m_showSeries[i];

    series->Points->Clear();
    values->Clear();
    dateTimeIndices->Clear();

    int anz = getValues(i, m_aggregation, m_aggregationTyp[m_chartList[i]], values, dateTimeIndices);
    for (int j = 0; j < anz; j++)
    {
      double value = values[j];
      DateTime ^dateTime = getTimePosition(dateTimeIndices[j]);

      DataPoint ^dataPoint = gcnew DataPoint();
      if (value == m_missingValue)
      {
        dataPoint->SetValueXY(dateTime->Add(tmOffset), 0.0);
        dataPoint->IsEmpty = true;
      }
      else
      {
        dataPoint->SetValueXY(dateTime->Add(tmOffset), value);
      }

      series->Points->Add(dataPoint);
    }
  }
}

private: RectangleF ChartAreaClientRectangle(Chart ^chart, ChartArea ^CA)
{
  RectangleF CAR = CA->Position->ToRectangleF();
  float pw = chart->ClientSize.Width / 100.0f;
  float ph = chart->ClientSize.Height / 100.0f;
  return RectangleF(pw * CAR.X, ph * CAR.Y, pw * CAR.Width, ph * CAR.Height);
}

private: RectangleF InnerPlotPositionClientRectangle(Chart ^chart, ChartArea ^CA)
{
  RectangleF IPP = CA->InnerPlotPosition->ToRectangleF();
  RectangleF CArp = ChartAreaClientRectangle(chart, CA);

  float pw = CArp.Width / 100.0f;
  float ph = CArp.Height / 100.0f;

  return RectangleF(CArp.X + pw * IPP.X, CArp.Y + ph * IPP.Y,
    pw * IPP.Width, ph * IPP.Height);
}

private: System::Void performZoom(int nDelta, double fPos)
{
  if (!chart1->ChartAreas[m_chartList[0]]->AxisX->ScaleView->Zoomable)
    return;

  // Calculate a temporaray zoom level from the delta, limit downwards to 0
  int nZoomLevel = Math::Max(0, m_nZoomLevel + nDelta);

  // Get the absolute limits (in real units) of the provided data
  double fScaleStart = m_startTimeDisplay->ToOADate(); // getTimePosition(0)->ToOADate();
  double fScaleEnd = m_endTimeDisplay->ToOADate(); // getTimePosition(m_valueAnz - 1)->ToOADate();

  // Calculate the current scale factor and the left and right limit using this scale,
  // so that the point under the mouse position does not move while scaling
  double fScale = Math::Pow(1.2, nZoomLevel / 120.0);
  fScaleStart = (fScaleStart - fPos) / fScale + fPos;
  fScaleEnd = (fScaleEnd - fPos) / fScale + fPos;

  // If the scale gets to small do not apply the calcualted zoom
  double fHours = TimeSpan::FromDays(fScaleEnd - fScaleStart).TotalHours;
  if (fHours >= 6)
  {
    // Determine time format for X axis
    String^ sLabelFormat = "d";
    DateTimeIntervalType eType = DateTimeIntervalType::Days;
    if (fHours <= 72)
    {
      sLabelFormat = "g";
      eType = DateTimeIntervalType::Hours;
    }

    for (int i = 0; i < m_chartAnzMax; ++i)
    {
      chart1->ChartAreas[i]->AxisX->ScaleView->Zoom(fScaleStart, fScaleEnd);
      //chart1->ChartAreas[i]->AxisX->LabelStyle->Format = sLabelFormat;
      //chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalType = eType;
    }
    m_nZoomLevel = nZoomLevel;

    ApplyAxisFormatting();
  }
}

private: System::Void performPan(int nDelta, double fMin, double fMax)
{
  if (!chart1->ChartAreas[m_chartList[0]]->AxisX->ScaleView->Zoomable)
    return;

  // Calculate the proposed movement (currently 10% of the range per nDelta fraction)
  double fOffset = (fMax - fMin) * nDelta / 120 * 0.1;

  // Apply the offset, but respect absolute limits of the actual data
  double fMinData = m_startTimeDisplay->ToOADate(); // getTimePosition(0)->ToOADate();
  double fMinNew = Math::Max(fMinData, fMin + fOffset);
  if (fMinNew == fMinData)
  {
    fOffset = -(fMin - fMinData);
  }

  double fMaxData = m_endTimeDisplay->ToOADate(); // getTimePosition(m_valueAnz - 1)->ToOADate();
  double fMaxNew = Math::Min(fMaxData, fMax + fOffset);
  if (fMaxNew == fMaxData)
  {
    fOffset = Math::Min(fMaxData, fMax) - fMax;
    fMinNew = fMin + fOffset;
  }

  // Apply the calculated limits
  for (int i = 0; i < m_chartAnzMax; ++i)
  {
    chart1->ChartAreas[i]->AxisX->ScaleView->Zoom(fMinNew, fMaxNew);
  }
}

private: unsigned int getValues(int index, AGGREGATION aggregation, AGGREGATION_TYP aggregationTyp,
  List<double> ^ valuesAggregated, List<int> ^ dateTimeIndices)
{
  double         value, valueAggregated;
  int            anzValue, anzDay;
  int            month, day, ind;
  DataValues ^   values = m_values[index];

  valueAggregated = 0;
  anzValue = 0;
  anzDay = 0;
  month = m_startTimeDisplay->Month;
  day = m_startTimeDisplay->Day;
  ind = 0;

  bool first = true;
  for (int i = 0; i < m_valueAnz; i++)
  {
    DateTime ^ actTime = getTimePosition(i);
    if (*actTime < *m_startTimeDisplay)
      continue;

    if (first)
    {
      ind = i;
      first = false;
    }
    value = values[i];

    if (*actTime >= *m_endTimeDisplay)
    {
      if (aggregation == AGGREGATION::NONE)
      {
        valuesAggregated->Add(value);
        dateTimeIndices->Add(i);
      }
      else
      {
        if (anzValue > 0)
        {
          if (aggregationTyp == AGGREGATION_TYP::MITTELWERT)
            valueAggregated = valueAggregated / anzValue;
        }
        else
          valueAggregated = m_missingValue;

        valuesAggregated->Add(valueAggregated);
        dateTimeIndices->Add(ind);
        anzValue = 0;
      }
      break;
    }

    if (aggregation == AGGREGATION::NONE)
    {
      valuesAggregated->Add(value);
      dateTimeIndices->Add(i);
      continue;
    }

    if (actTime->Day != day && aggregation != AGGREGATION::MONATLICH)
    {
      anzDay++;
      day = actTime->Day;
      if ((aggregation == AGGREGATION::TAEGLICH && anzDay == 1) || (aggregation == AGGREGATION::WOECHENTLICH && anzDay == 7))
      {
        if (anzValue > 0)
        {
          if (aggregationTyp == AGGREGATION_TYP::MITTELWERT)
          {
            valueAggregated = valueAggregated / anzValue;
          }
        }
        else
        {
          valueAggregated = m_missingValue;
        }

        valuesAggregated->Add(valueAggregated);
        dateTimeIndices->Add(ind);

        ind = i;
        anzDay = 0;
        anzValue = 0;
        valueAggregated = 0.0;
      }
    }

    if (actTime->Month != month && aggregation == AGGREGATION::MONATLICH)
    {
      month = actTime->Month;
      if (anzValue > 0)
      {
        if (aggregationTyp == AGGREGATION_TYP::MITTELWERT)
        {
          valueAggregated = valueAggregated / anzValue;
        }
      }
      else
      {
        valueAggregated = m_missingValue;
      }

      valuesAggregated->Add(valueAggregated);
      dateTimeIndices->Add(ind);

      ind = i;
      anzValue = 0;
      valueAggregated = 0.0;
    }

    if (value != m_missingValue)
    {
      valueAggregated = valueAggregated + value;
      anzValue++;
    }
  }

  if (anzValue > 0)
  {
    if (aggregationTyp == AGGREGATION_TYP::MITTELWERT)
    {
      valueAggregated = valueAggregated / anzValue;
    }

    // Skip the last interval for weekly accumulation only
    if (aggregation != AGGREGATION::WOECHENTLICH || aggregationTyp != AGGREGATION_TYP::SUMME)
    {
      valuesAggregated->Add(valueAggregated);
      dateTimeIndices->Add(ind);
    }
  }

  return valuesAggregated->Count;
}

private: DateTime ^  getTimePosition(unsigned int count)
{
  int days = m_timeIncrement->Days;
  int hours = m_timeIncrement->Hours;
  int minutes = m_timeIncrement->Minutes;
  int seconds = m_timeIncrement->Seconds;


  TimeSpan ^ timeSpan = gcnew TimeSpan(days*count, hours*count, minutes*count, seconds*count);
  DateTime ^ newDateTime = gcnew DateTime;
  newDateTime = *m_startTime + *timeSpan;
  return newDateTime;
}

private: System::Void refreshSeries()
{
  for (int i = 0; i < m_seriesAnz; i++)
  {
    Series ^ series = this->chart1->Series[i];
    series->Enabled = m_showSeries[i];
  }

  ApplySeriesSettings();
  FillDataSeries();

  checkChartVisibility();
  chart1->Refresh();
}

private: System::Void ApplySeriesSettings()
{
  // Enable or disable markers, depending on the aggregation type
  bool bShowMarkers;
  switch (m_aggregation)
  {
  case AGGREGATION::MONATLICH:
  case AGGREGATION::WOECHENTLICH:
    bShowMarkers = true;
    break;

  case AGGREGATION::TAEGLICH:
  default:
    bShowMarkers = false;
    break;
  }
  for (int i = 0; i < m_seriesAnz; ++i)
  {
    chart1->Series[i]->MarkerStyle = bShowMarkers ? MarkerStyle::Circle : MarkerStyle::None;
  }
}

private: System::Void ApplyAxisFormatting()
{
  DateTimeIntervalType eIntervalType;
  String ^sIntervalFormat;
  double nInterval = 1;
  double nOffset = 0.5;

  // Determine the visible range
  //double fStart = chart1->ChartAreas[m_chartList[0]]->AxisX->ScaleView->ViewMinimum;
  //double fEnd = chart1->ChartAreas[m_chartList[0]]->AxisX->ScaleView->ViewMaximum;
  double fStart = m_startTimeDisplay->ToOADate();
  double fEnd = m_endTimeDisplay->ToOADate();
  if (!double::IsNaN(fStart) && !double::IsNaN(fEnd))
  {
    DateTime tmStart = DateTime::FromOADate(fStart);
    DateTime tmEnd = DateTime::FromOADate(fEnd);
    TimeSpan tSpan = tmEnd - tmStart;

    // Hint: The label type changes when there are less than 3 intervalls visible!
    if (tSpan.TotalHours < 6)
    {
      // Less than 3 double hours visible, show hours
      sIntervalFormat = "{0:d.M. HH:mm}";
      eIntervalType = DateTimeIntervalType::Hours;
      nInterval = 1;
    }
    else if (tSpan.TotalHours < 18)
    {
      // Less than 3 quarter days visible, show double hours
      sIntervalFormat = "{0:d.M. HH:mm}";
      eIntervalType = DateTimeIntervalType::Hours;
      nInterval = 2;
    }
    else if (tSpan.TotalDays < 3)
    {
      // Less than 3 days visible, show quarter days
      sIntervalFormat = "{0:d. MMM, HH:mm}";
      eIntervalType = DateTimeIntervalType::Hours;
      nInterval = 6;
    }
    else if (tSpan.TotalDays < 10)
    {
      // Less than 10 days visible, show single days
      sIntervalFormat = "{0:d. MMM}";
      eIntervalType = DateTimeIntervalType::Days;
      nInterval = 1;
    }
    else if (tSpan.TotalDays < 21)
    {
      // Less than 3 weeks visible, show half weeks
      sIntervalFormat = "{0:d. MMM yyyy}";
      eIntervalType = DateTimeIntervalType::Weeks;
      nInterval = 0.5;
    }
    else if (tSpan.TotalDays < 42)
    {
      // Less than 6 weeks visible, show single weeks
      sIntervalFormat = "{0:d. MMM yyyy}";
      eIntervalType = DateTimeIntervalType::Weeks;
      nInterval = 1;
    }
    else if (tSpan.TotalDays < 90)
    {
      // There are less than 3 month visible, show double weeks (max. 13 weeks)
      sIntervalFormat = "{0:d. MMM yyyy}";
      eIntervalType = DateTimeIntervalType::Weeks;
      nInterval = 2;
    }
    else if (tSpan.TotalDays < 180)
    {
      // There are less than 6 month visible, show single months
      sIntervalFormat = "{0:d. MMM yyyy}";
      eIntervalType = DateTimeIntervalType::Months;
      nInterval = 1;
    }
    else
    {
      // show the year in quarters
      sIntervalFormat = "{0:MMM yyyy}";
      eIntervalType = DateTimeIntervalType::Months;
      nInterval = 3;
    }

    nOffset = nInterval / 2;
    Trace::WriteLine(String::Format("{0} {1} {2} {3}", eIntervalType, nInterval, nOffset, sIntervalFormat));
  }

  for (int i = 0; i < m_chartAnzMax; ++i)
  {
    chart1->ChartAreas[i]->AxisX->LabelStyle->Format = sIntervalFormat;
    chart1->ChartAreas[i]->AxisX->LabelStyle->IntervalType = eIntervalType;
    chart1->ChartAreas[i]->AxisX->LabelStyle->IntervalOffsetType = eIntervalType;
    chart1->ChartAreas[i]->AxisX->LabelStyle->IntervalOffset = nOffset;
    chart1->ChartAreas[i]->AxisX->LabelStyle->Interval = nInterval;
    chart1->ChartAreas[i]->AxisX->IntervalType = eIntervalType;
    chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalType = eIntervalType;
    chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalOffsetType = eIntervalType;
    chart1->ChartAreas[i]->AxisX->MajorTickMark->IntervalOffset = nOffset;
    chart1->ChartAreas[i]->AxisX->MajorTickMark->Interval = nInterval;
    chart1->ChartAreas[i]->AxisX->MajorGrid->IntervalType = eIntervalType;
    chart1->ChartAreas[i]->AxisX->MajorGrid->IntervalOffsetType = eIntervalType;
    chart1->ChartAreas[i]->AxisX->MajorGrid->Interval = nInterval;
    chart1->ChartAreas[i]->AxisX->Minimum = fStart; //getTimePosition(0)->ToOADate();
    chart1->ChartAreas[i]->AxisX->Maximum = fEnd;//getTimePosition(m_valueAnz - 1)->ToOADate();
  }
}

private: void updateDateControlLimits()
{
  if (m_startTime != nullptr && m_endTime != nullptr)
  {
    ctlStartDate->Value = *m_startTime;
    ctlStartDate->MinDate = *m_startTime;
    ctlEndDate->MinDate = *m_startTime;
    ctlEndDate->Value = *m_endTime;
    ctlEndDate->MaxDate = *m_endTime;
    ctlStartDate->MaxDate = *m_endTime;
  }
}

private: Void applyDateRange()
{
  if (ctlStartDate->Value > ctlEndDate->Value)
  {
    ctlEndDate->Value = ctlStartDate->Value;
  }

  m_startTimeDisplay = ctlStartDate->Value;
  m_endTimeDisplay = ctlEndDate->Value;

  ApplyAxisFormatting();

  refreshSeries();
}

#pragma endregion

#pragma region Event handlers

private: System::Void Diagramm_Shown(System::Object^  sender, System::EventArgs^  e)
{
  comboBoxZeitaufloesung->SelectedIndex = 0;
  chart1->Focus();
}

private: System::Void Diagramm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
  if (e->KeyCode == Keys::Escape)
  {
    this->Close();
  }
}

private: System::Void Diagramm_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^ e)
{
  // Determine a valid chart area
  for (int i = 0; i < m_chartAnzMax; ++i)
  {
    RectangleF rc = InnerPlotPositionClientRectangle(chart1, chart1->ChartAreas[i]);
    if (!rc.IsEmpty)
    {
      // Determine X value/index at cursor position
      RectangleF rc = InnerPlotPositionClientRectangle(chart1, chart1->ChartAreas[i]);
      int nPos = Math::Min(Math::Max(int(rc.Left), e->X), int(rc.Right));
      double fPos = chart1->ChartAreas[i]->AxisX->PixelPositionToValue(nPos);

      // Perform zooming relative to the given position
      performZoom(e->Delta, fPos);
      break;
    }
  }

}

private: System::Void buttonBeenden_Click(System::Object^  sender, System::EventArgs^  e)
{
  Close();
}

private: System::Void buttonAusblenden_Click(System::Object^  sender, System::EventArgs^  e)
{
  AusblendenZeitreihen ^ pDialog = gcnew AusblendenZeitreihen(m_seriesText, m_showSeries);

  System::Windows::Forms::DialogResult ok = pDialog->ShowDialog();

  if (ok == System::Windows::Forms::DialogResult::OK)
  {
    pDialog->getResult(m_showSeries);
    refreshSeries();
  }
}

private: System::Void checkBoxZeitraum_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
  ctlStartDate->Visible = checkBoxZeitraum->Checked;
  ctlEndDate->Visible = checkBoxZeitraum->Checked;
  lblStartDateDisplay->Visible = checkBoxZeitraum->Checked;
  lblEndDateDisplay->Visible = checkBoxZeitraum->Checked;

  if (!checkBoxZeitraum->Checked)
  {
    m_startTimeDisplay = m_startTime;
    m_endTimeDisplay = m_endTime;
  }
  else
  {
    m_startTimeDisplay = ctlStartDate->Value;
    m_endTimeDisplay = ctlEndDate->Value;
  }

  ApplyAxisFormatting();
  refreshSeries();
}

private: System::Void comboBoxZeitaufloesung_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
  m_aggregation = (Diagramm::AGGREGATION)comboBoxZeitaufloesung->SelectedIndex;

  ApplySeriesSettings();
  FillDataSeries();

  ApplyAxisFormatting();
}

private: System::Void chart1_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e)
{
  if (e->KeyCode == System::Windows::Forms::Keys::Right ||
    e->KeyCode == System::Windows::Forms::Keys::Left ||
    e->KeyCode == System::Windows::Forms::Keys::Up ||
    e->KeyCode == System::Windows::Forms::Keys::Down)
    e->IsInputKey = true;
}

private: System::Void chart1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
  switch (e->KeyCode)
  {
  case System::Windows::Forms::Keys::Right:
  {
    int nScale = 1;
    if (e->Control) nScale = 10;
    performPan(+120 * nScale, chart1->ChartAreas[m_chartList[0]]->AxisX->ScaleView->ViewMinimum, chart1->ChartAreas[m_chartList[0]]->AxisX->ScaleView->ViewMaximum);
    break;
  }

  case System::Windows::Forms::Keys::Left:
  {
    int nScale = 1;
    if (e->Control) nScale = 10;
    performPan(-120 * nScale, chart1->ChartAreas[m_chartList[0]]->AxisX->ScaleView->ViewMinimum, chart1->ChartAreas[m_chartList[0]]->AxisX->ScaleView->ViewMaximum);
    break;
  }

  case System::Windows::Forms::Keys::Up:
  {
    int nScale = 1;
    if (e->Control) nScale = 4;
    performZoom(+120 * nScale, (chart1->ChartAreas[m_chartList[0]]->AxisX->Minimum + chart1->ChartAreas[m_chartList[0]]->AxisX->Maximum) / 2);
    break;
  }

  case System::Windows::Forms::Keys::Down:
  {
    int nScale = 1;
    if (e->Control) nScale = 4;
    performZoom(-120 * nScale, (chart1->ChartAreas[m_chartList[0]]->AxisX->Minimum + chart1->ChartAreas[m_chartList[0]]->AxisX->Maximum) / 2);
    break;
  }
  }
}

private: System::Void chart1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
  chart1->Focus();
}

private: System::Void ctlStartEndDate_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
  applyDateRange();
}

private: System::Void buttonExportZeitreihen_Click(System::Object^  sender, System::EventArgs^  e) 
{
  String ^ STR;
  int      i, j;

  if ( saveFileDialogZeitreihen->ShowDialog() != System::Windows::Forms::DialogResult::OK )
    return;

  if ( m_seriesAnz == 0 )
    return;

  System::IO::StreamWriter ^ pWriter = gcnew System::IO::StreamWriter ( saveFileDialogZeitreihen->FileName );

  STR = "Time;";
  for ( i = 0; i < m_seriesAnz; i++ )
  {
    if ( i < m_seriesAnz - 1 )
     STR = String::Concat( STR, m_seriesText[i], ";" );
    else
      STR = String::Concat( STR, m_seriesText[i], "\n");
  }

  pWriter->Write( STR );

  for ( j = 0; j < m_valueAnz; j++ )
  {
    DateTime ^ dateTime = getTimePosition ( j );
    STR = String::Concat ( dateTime->ToString(), ";" );

    for ( i = 0; i < m_seriesAnz; i++ )
    {
      if (m_showSeries[i] == true)
      {
        List<double> ^ values = dynamic_cast<List<double>^>(m_values[i]);
        if ( j < values->Count )
          STR = String::Concat ( STR, Convert::ToString( values[j] ) );
      }

      if ( i < m_seriesAnz - 1 )
        STR = String::Concat( STR, ";" );
      else
        STR = String::Concat( STR, "\n" );
    }
    pWriter->Write( STR );
  }
  pWriter->Flush();
  pWriter->Close();
}

#pragma endregion
};
