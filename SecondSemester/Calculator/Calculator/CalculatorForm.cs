namespace CalculatorApp
{
    public partial class CalculatorForm : Form
    {
        private Calculator calculator = new Calculator();

        public CalculatorForm()
        {
            InitializeComponent();
        }

        private void NumberButtonClick(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            textOutput.AppendText(button.Text);

            calculator.InputNumber(button.Text[0]);
        }

        private void OperationButtonClick(object sender, EventArgs e)
        {
            Button button = (Button)sender;

            if (calculator.CurrentOperator != ' ')
            {
                calculator.InputOperator(button.Text[0]);
                textOutput.Text = calculator.CurrentValue.ToString();
                textOutput.AppendText(button.Text);
                return;
            }

            calculator.InputOperator(button.Text[0]);
            textOutput.AppendText(button.Text);
        }

        private void EqualsButtonClick(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            calculator.InputOperator(button.Text[0]);

            textOutput.Text = calculator.CurrentValue.ToString();
        }

        private void ClearButtonClick(object sender, EventArgs e)
        {
            textOutput.Clear();
            calculator.Clear();
        }
    }
}
