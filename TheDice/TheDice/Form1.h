/*
	Written by : Scott Morton
	scott at spm-e dot com
	Program rolls dice and provides basic stats in the form of - Probability of event A given B
	and determines that stat through direct observation

    Copyright (C) 2014  Scott P Morton

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 
	*/

#pragma once

namespace TheDice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int numRolls, eDelay, rnd;
	private: Random ^myRand ;
	
	private: System::Windows::Forms::Label^  D1;
	private: System::Windows::Forms::Label^  D2;
	private: System::Windows::Forms::Label^  D3;
	private: System::Windows::Forms::Label^  D4;
	private: System::Windows::Forms::Label^  D5;
	protected: 

	protected: 

	private: System::Windows::Forms::ComboBox^  Dice;
	private: System::Windows::Forms::ComboBox^  Runs;
	private: System::Windows::Forms::CheckBox^  Statistics;
	private: System::Windows::Forms::Button^  Roll;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  SelectedFace;

	private: System::Windows::Forms::ComboBox^  SUM;
	private: System::Windows::Forms::Label^  T_Face_L;
	private: System::Windows::Forms::Label^  T_Sum_L;
	private: System::Windows::Forms::Label^  Prob_L;
	private: System::Windows::Forms::Label^  T_Face;
	private: System::Windows::Forms::Label^  T_SUM;
	private: System::Windows::Forms::Label^  PROB;
	private: System::Windows::Forms::Label^  Delay_L;
	private: System::Windows::Forms::ComboBox^  Event_Delay;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  Exit;
	private: System::Windows::Forms::CheckBox^  waitEvent;

	private: System::Windows::Forms::Button^  Continue;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Label^  label5;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->D1 = (gcnew System::Windows::Forms::Label());
			this->D2 = (gcnew System::Windows::Forms::Label());
			this->D3 = (gcnew System::Windows::Forms::Label());
			this->D4 = (gcnew System::Windows::Forms::Label());
			this->D5 = (gcnew System::Windows::Forms::Label());
			this->Dice = (gcnew System::Windows::Forms::ComboBox());
			this->Runs = (gcnew System::Windows::Forms::ComboBox());
			this->Statistics = (gcnew System::Windows::Forms::CheckBox());
			this->Roll = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SelectedFace = (gcnew System::Windows::Forms::ComboBox());
			this->SUM = (gcnew System::Windows::Forms::ComboBox());
			this->T_Face_L = (gcnew System::Windows::Forms::Label());
			this->T_Sum_L = (gcnew System::Windows::Forms::Label());
			this->Prob_L = (gcnew System::Windows::Forms::Label());
			this->T_Face = (gcnew System::Windows::Forms::Label());
			this->T_SUM = (gcnew System::Windows::Forms::Label());
			this->PROB = (gcnew System::Windows::Forms::Label());
			this->Delay_L = (gcnew System::Windows::Forms::Label());
			this->Event_Delay = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->waitEvent = (gcnew System::Windows::Forms::CheckBox());
			this->Continue = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// D1
			// 
			this->D1->AutoSize = true;
			this->D1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D1->Location = System::Drawing::Point(13, 224);
			this->D1->Name = L"D1";
			this->D1->Size = System::Drawing::Size(98, 108);
			this->D1->TabIndex = 0;
			this->D1->Text = L"1";
			// 
			// D2
			// 
			this->D2->AutoSize = true;
			this->D2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D2->Location = System::Drawing::Point(111, 224);
			this->D2->Name = L"D2";
			this->D2->Size = System::Drawing::Size(98, 108);
			this->D2->TabIndex = 1;
			this->D2->Text = L"1";
			// 
			// D3
			// 
			this->D3->AutoSize = true;
			this->D3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D3->Location = System::Drawing::Point(209, 224);
			this->D3->Name = L"D3";
			this->D3->Size = System::Drawing::Size(98, 108);
			this->D3->TabIndex = 2;
			this->D3->Text = L"1";
			// 
			// D4
			// 
			this->D4->AutoSize = true;
			this->D4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D4->Location = System::Drawing::Point(307, 224);
			this->D4->Name = L"D4";
			this->D4->Size = System::Drawing::Size(98, 108);
			this->D4->TabIndex = 3;
			this->D4->Text = L"1";
			// 
			// D5
			// 
			this->D5->AutoSize = true;
			this->D5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->D5->Location = System::Drawing::Point(405, 224);
			this->D5->Name = L"D5";
			this->D5->Size = System::Drawing::Size(98, 108);
			this->D5->TabIndex = 4;
			this->D5->Text = L"1";
			// 
			// Dice
			// 
			this->Dice->DropDownHeight = 80;
			this->Dice->DropDownWidth = 20;
			this->Dice->FormattingEnabled = true;
			this->Dice->IntegralHeight = false;
			this->Dice->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"1", L"2", L"3", L"4", L"5"});
			this->Dice->Location = System::Drawing::Point(12, 26);
			this->Dice->Name = L"Dice";
			this->Dice->Size = System::Drawing::Size(70, 21);
			this->Dice->TabIndex = 1;
			this->Dice->Text = L"# of Dice";
			this->Dice->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::Dice_SelectedIndexChanged);
			// 
			// Runs
			// 
			this->Runs->FormattingEnabled = true;
			this->Runs->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"1", L"10", L"100", L"1000", L"3000", L"5000", L"10000", 
				L"100000"});
			this->Runs->Location = System::Drawing::Point(88, 26);
			this->Runs->Name = L"Runs";
			this->Runs->Size = System::Drawing::Size(121, 21);
			this->Runs->TabIndex = 2;
			this->Runs->Text = L"# of Rolls / Run";
			this->Runs->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::Runs_SelectedIndexChanged);
			// 
			// Statistics
			// 
			this->Statistics->AutoSize = true;
			this->Statistics->Location = System::Drawing::Point(12, 71);
			this->Statistics->Name = L"Statistics";
			this->Statistics->Size = System::Drawing::Size(68, 17);
			this->Statistics->TabIndex = 3;
			this->Statistics->Text = L"Statistics";
			this->Statistics->UseVisualStyleBackColor = true;
			this->Statistics->CheckStateChanged += gcnew System::EventHandler(this, &Form1::Statistics_CheckStateChanged);
			// 
			// Roll
			// 
			this->Roll->Location = System::Drawing::Point(14, 415);
			this->Roll->Name = L"Roll";
			this->Roll->Size = System::Drawing::Size(75, 23);
			this->Roll->TabIndex = 8;
			this->Roll->Text = L"Roll Dice";
			this->Roll->UseVisualStyleBackColor = true;
			this->Roll->Click += gcnew System::EventHandler(this, &Form1::Roll_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 129);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Event that the SUM of the dice = :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Event that ONE of the dice is a    :";
			// 
			// SelectedFace
			// 
			this->SelectedFace->FormattingEnabled = true;
			this->SelectedFace->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"1", L"2", L"3", L"4", L"5", L"6"});
			this->SelectedFace->Location = System::Drawing::Point(186, 97);
			this->SelectedFace->Name = L"SelectedFace";
			this->SelectedFace->Size = System::Drawing::Size(51, 21);
			this->SelectedFace->TabIndex = 4;
			this->SelectedFace->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::SelectedFace_SelectedIndexChanged);
			// 
			// SUM
			// 
			this->SUM->FormattingEnabled = true;
			this->SUM->Location = System::Drawing::Point(186, 126);
			this->SUM->Name = L"SUM";
			this->SUM->Size = System::Drawing::Size(51, 21);
			this->SUM->TabIndex = 5;
			// 
			// T_Face_L
			// 
			this->T_Face_L->AutoSize = true;
			this->T_Face_L->Location = System::Drawing::Point(301, 89);
			this->T_Face_L->Name = L"T_Face_L";
			this->T_Face_L->Size = System::Drawing::Size(113, 13);
			this->T_Face_L->TabIndex = 16;
			this->T_Face_L->Text = L"Total of selected face:";
			// 
			// T_Sum_L
			// 
			this->T_Sum_L->AutoSize = true;
			this->T_Sum_L->Location = System::Drawing::Point(298, 113);
			this->T_Sum_L->Name = L"T_Sum_L";
			this->T_Sum_L->Size = System::Drawing::Size(116, 13);
			this->T_Sum_L->TabIndex = 17;
			this->T_Sum_L->Text = L"Total of selected SUM:";
			// 
			// Prob_L
			// 
			this->Prob_L->AutoSize = true;
			this->Prob_L->Location = System::Drawing::Point(302, 139);
			this->Prob_L->Name = L"Prob_L";
			this->Prob_L->Size = System::Drawing::Size(112, 13);
			this->Prob_L->TabIndex = 18;
			this->Prob_L->Text = L"    Probability of event:";
			// 
			// T_Face
			// 
			this->T_Face->AutoSize = true;
			this->T_Face->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->T_Face->Location = System::Drawing::Point(422, 89);
			this->T_Face->Name = L"T_Face";
			this->T_Face->Size = System::Drawing::Size(14, 13);
			this->T_Face->TabIndex = 19;
			this->T_Face->Text = L"0";
			// 
			// T_SUM
			// 
			this->T_SUM->AutoSize = true;
			this->T_SUM->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->T_SUM->Location = System::Drawing::Point(422, 114);
			this->T_SUM->Name = L"T_SUM";
			this->T_SUM->Size = System::Drawing::Size(14, 13);
			this->T_SUM->TabIndex = 20;
			this->T_SUM->Text = L"0";
			// 
			// PROB
			// 
			this->PROB->AutoSize = true;
			this->PROB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->PROB->Location = System::Drawing::Point(422, 139);
			this->PROB->Name = L"PROB";
			this->PROB->Size = System::Drawing::Size(14, 13);
			this->PROB->TabIndex = 21;
			this->PROB->Text = L"0";
			// 
			// Delay_L
			// 
			this->Delay_L->AutoSize = true;
			this->Delay_L->Location = System::Drawing::Point(20, 169);
			this->Delay_L->Name = L"Delay_L";
			this->Delay_L->Size = System::Drawing::Size(131, 13);
			this->Delay_L->TabIndex = 22;
			this->Delay_L->Text = L"Event delay (milliseconds):";
			// 
			// Event_Delay
			// 
			this->Event_Delay->FormattingEnabled = true;
			this->Event_Delay->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"0", L"10", L"100", L"1000", L"2000"});
			this->Event_Delay->Location = System::Drawing::Point(150, 166);
			this->Event_Delay->Name = L"Event_Delay";
			this->Event_Delay->Size = System::Drawing::Size(59, 21);
			this->Event_Delay->TabIndex = 6;
			this->Event_Delay->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::Event_Delay_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 10);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 24;
			this->label3->Text = L"# of Die";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(88, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 25;
			this->label4->Text = L"# of Rolls";
			// 
			// Exit
			// 
			this->Exit->Location = System::Drawing::Point(447, 415);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(75, 23);
			this->Exit->TabIndex = 10;
			this->Exit->Text = L"Exit";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &Form1::Exit_Click);
			// 
			// waitEvent
			// 
			this->waitEvent->AutoSize = true;
			this->waitEvent->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->waitEvent->Location = System::Drawing::Point(306, 170);
			this->waitEvent->Name = L"waitEvent";
			this->waitEvent->Size = System::Drawing::Size(166, 17);
			this->waitEvent->TabIndex = 7;
			this->waitEvent->Text = L"Stop for each matching event";
			this->waitEvent->UseVisualStyleBackColor = true;
			// 
			// Continue
			// 
			this->Continue->Location = System::Drawing::Point(105, 415);
			this->Continue->Name = L"Continue";
			this->Continue->Size = System::Drawing::Size(75, 23);
			this->Continue->TabIndex = 28;
			this->Continue->Text = L"Continue";
			this->Continue->UseVisualStyleBackColor = true;
			this->Continue->Click += gcnew System::EventHandler(this, &Form1::Continue_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(286, 29);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(199, 13);
			this->linkLabel1->TabIndex = 29;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"http://opensource.org/licenses/GPL-3.0";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::linkLabel1_LinkClicked);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(286, 10);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 13);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Licensed through:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 462);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->Continue);
			this->Controls->Add(this->waitEvent);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Event_Delay);
			this->Controls->Add(this->Delay_L);
			this->Controls->Add(this->PROB);
			this->Controls->Add(this->T_SUM);
			this->Controls->Add(this->T_Face);
			this->Controls->Add(this->Prob_L);
			this->Controls->Add(this->T_Sum_L);
			this->Controls->Add(this->T_Face_L);
			this->Controls->Add(this->SUM);
			this->Controls->Add(this->SelectedFace);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Roll);
			this->Controls->Add(this->Statistics);
			this->Controls->Add(this->Runs);
			this->Controls->Add(this->Dice);
			this->Controls->Add(this->D5);
			this->Controls->Add(this->D4);
			this->Controls->Add(this->D3);
			this->Controls->Add(this->D2);
			this->Controls->Add(this->D1);
			this->MaximumSize = System::Drawing::Size(550, 500);
			this->MinimumSize = System::Drawing::Size(550, 500);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Roll the Dice - Scott Morton 2014";
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
private: System::Void Dice_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		D1->Visible=false;
		D2->Visible=false;
		D3->Visible=false;
		D4->Visible=false;
		D5->Visible=false;

		switch (Dice->SelectedIndex)
		{
			case 4: D5->Visible=true;
			case 3: D4->Visible=true;
			case 2: D3->Visible=true;
			case 1: D2->Visible=true;
			case 0:	D1->Visible=true;

		default:
			break;
		}

		Roll->Enabled = true;

		if (Dice->SelectedIndex > 0)
		{
			if (Statistics->Enabled)
			{
				SUM->Items->Clear();
				 for (int i = (SelectedFace->SelectedIndex + (Dice->SelectedIndex + 1)); i <= (Dice->SelectedIndex + 1) * 6 - (6 - (SelectedFace->SelectedIndex + 1)); i++)
				 {
					 SUM->Items->Add(i.ToString());
				 }
				 SUM->SelectedIndex = 0;
			}
			if (!(Statistics->Enabled))
			{
				Statistics->Enabled = true;
			}
		}
		else
		{
			Statistics->Checked = false;
			Statistics->Enabled = false;
		}
	}

private: System::Void Runs_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		switch (Runs->SelectedIndex)
		{
			case 7: numRolls = 100000; break;
			case 6: numRolls = 10000; break;
			case 5: numRolls = 5000; break;
			case 4: numRolls = 3000; break;
			case 3: numRolls = 1000; break;
			case 2: numRolls = 100; break;
			case 1:	numRolls = 10; break;
			case 0:	numRolls = 1; break;

			default:
				break;
		}
		
	}
private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) 
		 {
			numRolls = 0;
			eDelay = 0;
			D1->Visible=false;
			D2->Visible=false;
			D3->Visible=false;
			D4->Visible=false;
			D5->Visible=false;
			Statistics->Enabled = false;
			SUM->Enabled = false;
			SelectedFace->Enabled = false;
			Event_Delay->SelectedIndex = 0;
			Runs->SelectedIndex = 0;
			Roll->Enabled = false;
			Continue->Enabled = false;
			myRand = gcnew Random();
			rnd = myRand->Next(1, 7);
		
		 }
private: System::Void Roll_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			rnd = myRand->Next(1, 7);
			 Roll->Enabled = false;
			 float totalFace = 0.0, totalSum = 0.0, currentSUM;
			 float probability = 0.0;
			 array<int>^die = gcnew array<int>(6);

			T_SUM->Text = totalSum.ToString();
			T_Face->Text = totalFace.ToString();
			PROB->Text = probability.ToString();

			Continue->Enabled = false;
			 
			 for (int l = 1; l <= numRolls; l++)
			 {
				for (int i = 0; i <= Dice->SelectedIndex; i++)
				{
					rnd = myRand->Next(1, 7);
					switch (i)
					{
						case 4: D5->Text = rnd.ToString(); break;
						case 3: D4->Text = rnd.ToString(); break;
						case 2: D3->Text = rnd.ToString(); break;
						case 1: D2->Text = rnd.ToString(); break;
						case 0: D1->Text = rnd.ToString(); break;
						default: break;
					}
					die[i] = rnd;
				}

				if (die[0] == (SelectedFace->SelectedIndex + 1) || die[1] == (SelectedFace->SelectedIndex + 1) ||
						die[2] == (SelectedFace->SelectedIndex + 1)  || die[3] == (SelectedFace->SelectedIndex + 1) ||
							die[4] == (SelectedFace->SelectedIndex + 1))
				{
					if (Statistics->Checked)
					{
						totalFace += 1;
						T_Face->Text = totalFace.ToString();

						currentSUM = 0;

						for (int s = 0; s <= Dice->SelectedIndex; s++)
						{
							currentSUM += die[s];
						}

						if (currentSUM == (SUM->SelectedIndex + Dice->SelectedIndex + SelectedFace->SelectedIndex + 1))
						{
							totalSum += 1;
							T_SUM->Text = totalSum.ToString();

							if (waitEvent->Checked)
							{
								Continue->Enabled = true;
								Continue->Focus();
							}
						}
					}
				}


				Application::DoEvents();

				if (numRolls > 1)
				{
					Threading::Thread::Sleep(eDelay);
				}

				if (waitEvent->Checked)
				{
					while (Continue->Enabled)
					{
						Threading::Thread::Sleep(eDelay);
						Application::DoEvents();
					}
				}
			 }
			
			if (Statistics->Checked)
			{
				if (totalFace)
				{
					probability = totalSum / totalFace;
					PROB->Text = probability.ToString();
				}
			}

			Roll->Enabled = true;
		}

private: System::Void Statistics_CheckStateChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (Statistics->Checked)
			 {
					SUM->Items->Clear();
					SelectedFace->SelectedIndex = 0;
					SelectedFace->Enabled = true;
			 }

			 else
			 {
					SUM->Items->Clear();
 					SUM->Enabled = false;
					SelectedFace->Enabled = false;
			 }
		 }

private: System::Void Event_Delay_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			switch (Event_Delay->SelectedIndex)
			{
				case 4: eDelay = 2000; break;
				case 3: eDelay = 1000; break;
				case 2: eDelay = 100; break;
				case 1: eDelay = 10; break;
				case 0:	eDelay = 0; break;

				default:
					break;
			}
		 }

private: System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
 			 Continue->Enabled = false;
			 Application::Exit();
		 }

private: System::Void SelectedFace_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 SUM->Enabled = true;
			 SUM->Items->Clear();
			 for (int i = (SelectedFace->SelectedIndex + (Dice->SelectedIndex + 1)); i <= (Dice->SelectedIndex + 1) * 6 - (6 - (SelectedFace->SelectedIndex + 1)); i++)
			 {
				 SUM->Items->Add(i.ToString());
			 }
			 SUM->SelectedIndex = 0;
		 }

private: System::Void Continue_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Continue->Enabled = false;
		 }

private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
		 {
			 System::Diagnostics::Process::Start( "http://opensource.org/licenses/GPL-3.0" );
		 }
};
}

