namespace Calculator
{
    partial class CalculatorForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tableLayoutPanel1 = new TableLayoutPanel();
            textOutput = new RichTextBox();
            tableLayoutPanel2 = new TableLayoutPanel();
            buttonSeven = new Button();
            buttonPlus = new Button();
            buttonEqual = new Button();
            buttonZero = new Button();
            buttonClean = new Button();
            buttonMinus = new Button();
            buttonThree = new Button();
            buttonTwo = new Button();
            buttonOne = new Button();
            buttonMultiplication = new Button();
            buttonSix = new Button();
            buttonFive = new Button();
            buttonFour = new Button();
            buttonDivision = new Button();
            buttonNine = new Button();
            buttonEight = new Button();
            tableLayoutPanel1.SuspendLayout();
            tableLayoutPanel2.SuspendLayout();
            SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.BackColor = Color.FromArgb(192, 192, 255);
            tableLayoutPanel1.ColumnCount = 1;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100F));
            tableLayoutPanel1.Controls.Add(textOutput, 0, 0);
            tableLayoutPanel1.Controls.Add(tableLayoutPanel2, 0, 1);
            tableLayoutPanel1.Dock = DockStyle.Fill;
            tableLayoutPanel1.Location = new Point(0, 0);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 2;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 35F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 65F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Absolute, 20F));
            tableLayoutPanel1.Size = new Size(400, 450);
            tableLayoutPanel1.TabIndex = 0;
            // 
            // textOutput
            // 
            textOutput.BackColor = SystemColors.Menu;
            textOutput.Dock = DockStyle.Fill;
            textOutput.Font = new Font("Segoe UI", 46F, FontStyle.Regular, GraphicsUnit.Point, 204);
            textOutput.Location = new Point(0, 0);
            textOutput.Margin = new Padding(0);
            textOutput.Name = "textOutput";
            textOutput.RightToLeft = RightToLeft.No;
            textOutput.Size = new Size(400, 157);
            textOutput.TabIndex = 0;
            textOutput.Text = "";
            // 
            // tableLayoutPanel2
            // 
            tableLayoutPanel2.ColumnCount = 4;
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel2.Controls.Add(buttonSeven, 0, 0);
            tableLayoutPanel2.Controls.Add(buttonPlus, 3, 3);
            tableLayoutPanel2.Controls.Add(buttonEqual, 2, 3);
            tableLayoutPanel2.Controls.Add(buttonZero, 1, 3);
            tableLayoutPanel2.Controls.Add(buttonClean, 0, 3);
            tableLayoutPanel2.Controls.Add(buttonMinus, 3, 2);
            tableLayoutPanel2.Controls.Add(buttonThree, 2, 2);
            tableLayoutPanel2.Controls.Add(buttonTwo, 1, 2);
            tableLayoutPanel2.Controls.Add(buttonOne, 0, 2);
            tableLayoutPanel2.Controls.Add(buttonMultiplication, 3, 1);
            tableLayoutPanel2.Controls.Add(buttonSix, 2, 1);
            tableLayoutPanel2.Controls.Add(buttonFive, 1, 1);
            tableLayoutPanel2.Controls.Add(buttonFour, 0, 1);
            tableLayoutPanel2.Controls.Add(buttonDivision, 3, 0);
            tableLayoutPanel2.Controls.Add(buttonNine, 2, 0);
            tableLayoutPanel2.Controls.Add(buttonEight, 1, 0);
            tableLayoutPanel2.Dock = DockStyle.Fill;
            tableLayoutPanel2.Location = new Point(3, 160);
            tableLayoutPanel2.Name = "tableLayoutPanel2";
            tableLayoutPanel2.RowCount = 4;
            tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel2.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel2.Size = new Size(394, 287);
            tableLayoutPanel2.TabIndex = 2;
            // 
            // buttonSeven
            // 
            buttonSeven.BackColor = SystemColors.ButtonFace;
            buttonSeven.Dock = DockStyle.Fill;
            buttonSeven.Font = new Font("Yu Gothic UI", 22.2F);
            buttonSeven.Location = new Point(0, 0);
            buttonSeven.Margin = new Padding(0);
            buttonSeven.Name = "buttonSeven";
            buttonSeven.Size = new Size(98, 71);
            buttonSeven.TabIndex = 0;
            buttonSeven.Text = "7";
            buttonSeven.UseVisualStyleBackColor = false;
            buttonSeven.Click += NumberButtonClick;
            // 
            // buttonPlus
            // 
            buttonPlus.BackColor = Color.FromArgb(255, 192, 192);
            buttonPlus.Dock = DockStyle.Fill;
            buttonPlus.Font = new Font("Yu Gothic UI", 22.2F);
            buttonPlus.Location = new Point(294, 213);
            buttonPlus.Margin = new Padding(0);
            buttonPlus.Name = "buttonPlus";
            buttonPlus.Size = new Size(100, 74);
            buttonPlus.TabIndex = 15;
            buttonPlus.Text = "+";
            buttonPlus.UseVisualStyleBackColor = false;
            buttonPlus.Click += OperationButtonClick;
            // 
            // buttonEqual
            // 
            buttonEqual.BackColor = Color.FromArgb(192, 192, 255);
            buttonEqual.Dock = DockStyle.Fill;
            buttonEqual.Font = new Font("Yu Gothic UI", 22.2F);
            buttonEqual.Location = new Point(196, 213);
            buttonEqual.Margin = new Padding(0);
            buttonEqual.Name = "buttonEqual";
            buttonEqual.Size = new Size(98, 74);
            buttonEqual.TabIndex = 14;
            buttonEqual.Text = "=";
            buttonEqual.UseVisualStyleBackColor = false;
            buttonEqual.Click += EqualsButtonClick;
            // 
            // buttonZero
            // 
            buttonZero.BackColor = SystemColors.ButtonFace;
            buttonZero.Dock = DockStyle.Fill;
            buttonZero.Font = new Font("Yu Gothic UI", 22.2F);
            buttonZero.Location = new Point(98, 213);
            buttonZero.Margin = new Padding(0);
            buttonZero.Name = "buttonZero";
            buttonZero.Size = new Size(98, 74);
            buttonZero.TabIndex = 13;
            buttonZero.Text = "0";
            buttonZero.UseVisualStyleBackColor = false;
            buttonZero.Click += NumberButtonClick;
            // 
            // buttonClean
            // 
            buttonClean.BackColor = Color.FromArgb(192, 192, 255);
            buttonClean.Dock = DockStyle.Fill;
            buttonClean.Font = new Font("Yu Gothic UI", 22.2F);
            buttonClean.Location = new Point(0, 213);
            buttonClean.Margin = new Padding(0);
            buttonClean.Name = "buttonClean";
            buttonClean.Size = new Size(98, 74);
            buttonClean.TabIndex = 12;
            buttonClean.Text = "C";
            buttonClean.UseVisualStyleBackColor = false;
            buttonClean.Click += ClearButtonClick;
            // 
            // buttonMinus
            // 
            buttonMinus.BackColor = Color.FromArgb(255, 192, 192);
            buttonMinus.Dock = DockStyle.Fill;
            buttonMinus.Font = new Font("Yu Gothic UI", 22.2F);
            buttonMinus.Location = new Point(294, 142);
            buttonMinus.Margin = new Padding(0);
            buttonMinus.Name = "buttonMinus";
            buttonMinus.Size = new Size(100, 71);
            buttonMinus.TabIndex = 11;
            buttonMinus.Text = "-";
            buttonMinus.UseVisualStyleBackColor = false;
            buttonMinus.Click += OperationButtonClick;
            // 
            // buttonThree
            // 
            buttonThree.BackColor = SystemColors.ButtonFace;
            buttonThree.Dock = DockStyle.Fill;
            buttonThree.Font = new Font("Yu Gothic UI", 22.2F);
            buttonThree.Location = new Point(196, 142);
            buttonThree.Margin = new Padding(0);
            buttonThree.Name = "buttonThree";
            buttonThree.Size = new Size(98, 71);
            buttonThree.TabIndex = 10;
            buttonThree.Text = "3";
            buttonThree.UseVisualStyleBackColor = false;
            buttonThree.Click += NumberButtonClick;
            // 
            // buttonTwo
            // 
            buttonTwo.BackColor = SystemColors.ButtonFace;
            buttonTwo.Dock = DockStyle.Fill;
            buttonTwo.Font = new Font("Yu Gothic UI", 22.2F);
            buttonTwo.Location = new Point(98, 142);
            buttonTwo.Margin = new Padding(0);
            buttonTwo.Name = "buttonTwo";
            buttonTwo.Size = new Size(98, 71);
            buttonTwo.TabIndex = 9;
            buttonTwo.Text = "2";
            buttonTwo.UseVisualStyleBackColor = false;
            buttonTwo.Click += NumberButtonClick;
            // 
            // buttonOne
            // 
            buttonOne.BackColor = SystemColors.ButtonFace;
            buttonOne.Dock = DockStyle.Fill;
            buttonOne.Font = new Font("Yu Gothic UI", 22.2F);
            buttonOne.Location = new Point(0, 142);
            buttonOne.Margin = new Padding(0);
            buttonOne.Name = "buttonOne";
            buttonOne.Size = new Size(98, 71);
            buttonOne.TabIndex = 8;
            buttonOne.Text = "1";
            buttonOne.UseVisualStyleBackColor = false;
            buttonOne.Click += NumberButtonClick;
            // 
            // buttonMultiplication
            // 
            buttonMultiplication.BackColor = Color.FromArgb(255, 192, 192);
            buttonMultiplication.Dock = DockStyle.Fill;
            buttonMultiplication.Font = new Font("Yu Gothic UI", 22.2F);
            buttonMultiplication.Location = new Point(294, 71);
            buttonMultiplication.Margin = new Padding(0);
            buttonMultiplication.Name = "buttonMultiplication";
            buttonMultiplication.Size = new Size(100, 71);
            buttonMultiplication.TabIndex = 7;
            buttonMultiplication.Text = "×";
            buttonMultiplication.UseVisualStyleBackColor = false;
            buttonMultiplication.Click += OperationButtonClick;
            // 
            // buttonSix
            // 
            buttonSix.BackColor = SystemColors.ButtonFace;
            buttonSix.Dock = DockStyle.Fill;
            buttonSix.Font = new Font("Yu Gothic UI", 22.2F);
            buttonSix.Location = new Point(196, 71);
            buttonSix.Margin = new Padding(0);
            buttonSix.Name = "buttonSix";
            buttonSix.Size = new Size(98, 71);
            buttonSix.TabIndex = 6;
            buttonSix.Text = "6";
            buttonSix.UseVisualStyleBackColor = false;
            buttonSix.Click += NumberButtonClick;
            // 
            // buttonFive
            // 
            buttonFive.BackColor = SystemColors.ButtonFace;
            buttonFive.Dock = DockStyle.Fill;
            buttonFive.Font = new Font("Yu Gothic UI", 22.2F);
            buttonFive.Location = new Point(98, 71);
            buttonFive.Margin = new Padding(0);
            buttonFive.Name = "buttonFive";
            buttonFive.Size = new Size(98, 71);
            buttonFive.TabIndex = 5;
            buttonFive.Text = "5";
            buttonFive.UseVisualStyleBackColor = false;
            buttonFive.Click += NumberButtonClick;
            // 
            // buttonFour
            // 
            buttonFour.BackColor = SystemColors.ButtonFace;
            buttonFour.Dock = DockStyle.Fill;
            buttonFour.Font = new Font("Yu Gothic UI", 22.2F);
            buttonFour.Location = new Point(0, 71);
            buttonFour.Margin = new Padding(0);
            buttonFour.Name = "buttonFour";
            buttonFour.Size = new Size(98, 71);
            buttonFour.TabIndex = 4;
            buttonFour.Text = "4";
            buttonFour.UseVisualStyleBackColor = false;
            buttonFour.Click += NumberButtonClick;
            // 
            // buttonDivision
            // 
            buttonDivision.BackColor = Color.FromArgb(255, 192, 192);
            buttonDivision.Dock = DockStyle.Fill;
            buttonDivision.Font = new Font("Yu Gothic UI", 22.2F);
            buttonDivision.Location = new Point(294, 0);
            buttonDivision.Margin = new Padding(0);
            buttonDivision.Name = "buttonDivision";
            buttonDivision.Size = new Size(100, 71);
            buttonDivision.TabIndex = 3;
            buttonDivision.Text = "÷";
            buttonDivision.UseVisualStyleBackColor = false;
            buttonDivision.Click += OperationButtonClick;
            // 
            // buttonNine
            // 
            buttonNine.BackColor = SystemColors.ButtonFace;
            buttonNine.Dock = DockStyle.Fill;
            buttonNine.Font = new Font("Yu Gothic UI", 22.2F);
            buttonNine.Location = new Point(196, 0);
            buttonNine.Margin = new Padding(0);
            buttonNine.Name = "buttonNine";
            buttonNine.Size = new Size(98, 71);
            buttonNine.TabIndex = 2;
            buttonNine.Text = "9";
            buttonNine.UseVisualStyleBackColor = false;
            buttonNine.Click += NumberButtonClick;
            // 
            // buttonEight
            // 
            buttonEight.BackColor = SystemColors.ButtonFace;
            buttonEight.Dock = DockStyle.Fill;
            buttonEight.Font = new Font("Yu Gothic UI", 22.2F);
            buttonEight.Location = new Point(98, 0);
            buttonEight.Margin = new Padding(0);
            buttonEight.Name = "buttonEight";
            buttonEight.Size = new Size(98, 71);
            buttonEight.TabIndex = 1;
            buttonEight.Text = "8";
            buttonEight.UseVisualStyleBackColor = false;
            buttonEight.Click += NumberButtonClick;
            // 
            // CalculatorForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(400, 450);
            Controls.Add(tableLayoutPanel1);
            Name = "CalculatorForm";
            Text = "Calculator";
            tableLayoutPanel1.ResumeLayout(false);
            tableLayoutPanel2.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private TableLayoutPanel tableLayoutPanel1;
        private RichTextBox textOutput;
        private TableLayoutPanel tableLayoutPanel2;
        private Button buttonSeven;
        private Button buttonPlus;
        private Button buttonEqual;
        private Button buttonZero;
        private Button buttonClean;
        private Button buttonMinus;
        private Button buttonThree;
        private Button buttonTwo;
        private Button buttonOne;
        private Button buttonMultiplication;
        private Button buttonSix;
        private Button buttonFive;
        private Button buttonFour;
        private Button buttonDivision;
        private Button buttonNine;
        private Button buttonEight;
    }
}
