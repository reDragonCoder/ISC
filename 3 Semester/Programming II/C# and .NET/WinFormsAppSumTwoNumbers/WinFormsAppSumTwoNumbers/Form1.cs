namespace WinFormsAppSumTwoNumbers
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtFirstNum.Text = "";
            txtSecondNum.Text = "";
            txtResult.Text = "";
        }

        private void btnCalculate_Click(object sender, EventArgs e)
        {
            double n1, n2, r;
            n1 = double.Parse(txtFirstNum.Text);
            n2 = double.Parse(txtSecondNum.Text);
            r = n1 + n2;
            txtResult.Text = r.ToString();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
