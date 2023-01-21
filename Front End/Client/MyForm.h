#pragma once
#include <iostream>
#include <string>
#include <iomanip>

namespace Project5 {
    using namespace std;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
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
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
    private: int player = 2;
    private: System::Windows::Forms::Button^ button9;
    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::Button^ button7;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label1;
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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1->SuspendLayout();
            this->SuspendLayout();
            //
            // tableLayoutPanel1
            //
            this->tableLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                  static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->tableLayoutPanel1->ColumnCount = 3;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                                                                                                  50)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                                                                                                  50)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                                                                                                  436)));
            this->tableLayoutPanel1->Controls->Add(this->button9, 2, 2);
            this->tableLayoutPanel1->Controls->Add(this->button8, 1, 2);
            this->tableLayoutPanel1->Controls->Add(this->button7, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->button6, 2, 1);
            this->tableLayoutPanel1->Controls->Add(this->button5, 1, 1);
            this->tableLayoutPanel1->Controls->Add(this->button4, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->button3, 2, 0);
            this->tableLayoutPanel1->Controls->Add(this->button2, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->button1, 0, 0);
            this->tableLayoutPanel1->Location = System::Drawing::Point(346, 137);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 3;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 360)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(1294, 1053);
            this->tableLayoutPanel1->TabIndex = 0;
            //
            // button9
            //
            this->button9->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->button9->ForeColor = System::Drawing::Color::Red;
            this->button9->Location = System::Drawing::Point(861, 695);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(420, 338);
            this->button9->TabIndex = 8;
            this->button9->Text = L" ";
            this->button9->UseVisualStyleBackColor = false;
            this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
            //
            // button8
            //
            this->button8->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->button8->ForeColor = System::Drawing::Color::Red;
            this->button8->Location = System::Drawing::Point(432, 695);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(420, 338);
            this->button8->TabIndex = 7;
            this->button8->Text = L" ";
            this->button8->UseVisualStyleBackColor = false;
            this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
            //
            // button7
            //
            this->button7->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->button7->ForeColor = System::Drawing::Color::Red;
            this->button7->Location = System::Drawing::Point(3, 695);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(420, 338);
            this->button7->TabIndex = 6;
            this->button7->Text = L" ";
            this->button7->UseVisualStyleBackColor = false;
            this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
            //
            // button6
            //
            this->button6->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->button6->ForeColor = System::Drawing::Color::Red;
            this->button6->Location = System::Drawing::Point(861, 349);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(420, 338);
            this->button6->TabIndex = 5;
            this->button6->Text = L" ";
            this->button6->UseVisualStyleBackColor = false;
            this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
            //
            // button5
            //
            this->button5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->button5->ForeColor = System::Drawing::Color::Red;
            this->button5->Location = System::Drawing::Point(432, 349);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(420, 338);
            this->button5->TabIndex = 4;
            this->button5->Text = L" ";
            this->button5->UseVisualStyleBackColor = false;
            this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
            //
            // button4
            //
            this->button4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->button4->ForeColor = System::Drawing::Color::Red;
            this->button4->Location = System::Drawing::Point(3, 349);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(420, 338);
            this->button4->TabIndex = 3;
            this->button4->Text = L" ";
            this->button4->UseVisualStyleBackColor = false;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
            //
            // button3
            //
            this->button3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->button3->ForeColor = System::Drawing::Color::Red;
            this->button3->Location = System::Drawing::Point(861, 3);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(420, 338);
            this->button3->TabIndex = 2;
            this->button3->Text = L" ";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            //
            // button2
            //
            this->button2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->button2->ForeColor = System::Drawing::Color::Red;
            this->button2->Location = System::Drawing::Point(432, 3);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(420, 338);
            this->button2->TabIndex = 1;
            this->button2->Text = L" ";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            //
            // button1
            //
            this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->button1->ForeColor = System::Drawing::Color::Red;
            this->button1->Location = System::Drawing::Point(3, 3);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(420, 338);
            this->button1->TabIndex = 0;
            this->button1->Text = L" ";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
            this->label1->Location = System::Drawing::Point(634, 53);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(92, 32);
            this->label1->TabIndex = 1;
            this->label1->Text = L"label1";
            this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
            //
            // MyForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->ClientSize = System::Drawing::Size(1965, 1304);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->tableLayoutPanel1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Location = System::Drawing::Point(1003, 827);
            this->Name = L"MyForm";
            this->Text = L"t";
            this->tableLayoutPanel1->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            if (player == 1) {
                this->button1->ForeColor = System::Drawing::Color::Red;
                this->button1->Text = L"O";
                player = 2;
            }
            else if (player == 2) {
                this->button1->ForeColor = System::Drawing::Color::Blue;
                this->button1->Text = L"X";
                player = 1;

            }
        }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
            if (player == 1) {
                this->button2->ForeColor = System::Drawing::Color::Red;
                this->button2->Text = L"O";
                player = 2;
            }
            else if (player == 2) {
                this->button2->ForeColor = System::Drawing::Color::Blue;
                this->button2->Text = L"X";
                player = 1;
            }

        }
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
            if (player == 1) {
                this->button3->ForeColor = System::Drawing::Color::Red;
                this->button3->Text = L"O";
                player = 2;

            }
            else if (player == 2) {
                this->button3->ForeColor = System::Drawing::Color::Blue;
                this->button3->Text = L"X";
                player = 1;
            }

        }
    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
            if (player == 1) {
                this->button4->ForeColor = System::Drawing::Color::Red;
                this->button4->Text = L"O";
                player = 2;

            }
            else if (player == 2) {
                this->button4->ForeColor = System::Drawing::Color::Blue;
                this->button4->Text = L"X";
                player = 1;
            }

        }
    private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
            if (player == 1) {
                this->button5->ForeColor = System::Drawing::Color::Red;
                this->button5->Text = L"O";
                player = 2;

            }
            else if (player == 2) {
                this->button5->ForeColor = System::Drawing::Color::Blue;
                this->button5->Text = L"X";
                player = 1;
            }

        }
    private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
            if (player == 1) {
                this->button6->ForeColor = System::Drawing::Color::Red;
                this->button6->Text = L"O";
                player = 2;

            }
            else if (player == 2) {
                this->button6->ForeColor = System::Drawing::Color::Blue;
                this->button6->Text = L"X";
                player = 1;
            }

        }
    private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
            if (player == 1) {
                this->button7->ForeColor = System::Drawing::Color::Red;
                this->button7->Text = L"O";
                player = 2;

            }
            else if (player == 2) {
                this->button7->ForeColor = System::Drawing::Color::Blue;
                this->button7->Text = L"X";
                player = 1;
            }

        }
    private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
            if (player == 1) {
                this->button8->ForeColor = System::Drawing::Color::Red;
                this->button8->Text = L"O";
                player = 2;

            }
            else if (player == 2) {
                this->button8->ForeColor = System::Drawing::Color::Blue;
                this->button8->Text = L"X";
                player = 1;
            }

        }
    private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
            if (player == 1) {
                this->button9->ForeColor = System::Drawing::Color::Red;
                this->button9->Text = L"O";
                player = 2;

            }
            else if (player == 2) {
                this->button9->ForeColor = System::Drawing::Color::Blue;
                this->button9->Text = L"X";
                player = 1;
            }
        }

    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
            this->label1->Text = L"player";

        }
    };
}