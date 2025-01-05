namespace WinFormsMultipleForms
{
    public partial class FormPrincipal : Form
    {
        public static int num = 21;
        //crear otro static
        public FormPrincipal()
        {
            InitializeComponent();
        }

        private void FormPrincipal_Load(object sender, EventArgs e)
        {

        }

        private void buttonForm2_Click(object sender, EventArgs e)
        {
            string data;
            data = this.textBoxData.Text;
            Form2 f2 = new Form2(data);
            this.Hide();
            f2.ShowDialog();
            this.Show();
        }

        private void buttonExit_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        private void buttonForm3_Click(object sender, EventArgs e)
        {
            Form3 f3 = new Form3();
            this.Hide();
            f3.ShowDialog();
            this.Show();
        }
    }
}
