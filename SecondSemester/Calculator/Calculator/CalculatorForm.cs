// <copyright file="CalculatorForm.cs" company="PlaceholderCompany">
// Copyright (c) PlaceholderCompany. All rights reserved.
// </copyright>

namespace CalculatorApp
{
    /// <summary>
    /// Partial class for the calculator form.
    /// </summary>
    public partial class CalculatorForm : Form
    {
        private Calculator calculator = new Calculator();

        /// <summary>
        /// Initializes a new instance of the <see cref="CalculatorForm"/> class.
        /// Constructor for the calculator form.
        /// </summary>
        public CalculatorForm()
        {
            this.InitializeComponent();
        }

        private void NumberButtonClick(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            this.textOutput.AppendText(button.Text);

            this.calculator.InputNumber(button.Text[0]);
        }

        private void OperationButtonClick(object sender, EventArgs e)
        {
            Button button = (Button)sender;

            if (this.calculator.CurrentOperator != ' ')
            {
                this.calculator.InputOperator(button.Text[0]);
                this.textOutput.Text = this.calculator.CurrentValue.ToString();
                this.textOutput.AppendText(button.Text);
                return;
            }

            this.calculator.InputOperator(button.Text[0]);
            this.textOutput.AppendText(button.Text);
        }

        private void EqualsButtonClick(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            this.calculator.InputOperator(button.Text[0]);

            this.textOutput.Text = this.calculator.CurrentValue.ToString();
        }

        private void ClearButtonClick(object sender, EventArgs e)
        {
            this.textOutput.Clear();
            this.calculator.Clear();
        }
    }
}
