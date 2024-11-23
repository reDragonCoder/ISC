namespace WinFormsMultiplePictureBoxes
{
    public partial class Form1 : Form
    {
        OpenFileDialog opeN = new OpenFileDialog();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            opeN.Filter = "PNG|*.png|JPEG|*.jpeg|GIF|*.gif";
            opeN.Multiselect = true;

            if (opeN.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                pb1.Image = System.Drawing.Image.FromFile(opeN.FileNames[0].ToString());
                pb2.Image = System.Drawing.Image.FromFile(opeN.FileNames[1].ToString());
                pb3.Image = System.Drawing.Image.FromFile(opeN.FileNames[2].ToString());
                pb4.Image = System.Drawing.Image.FromFile(opeN.FileNames[3].ToString());
                pb5.Image = System.Drawing.Image.FromFile(opeN.FileNames[4].ToString());
                pb6.Image = System.Drawing.Image.FromFile(opeN.FileNames[5].ToString());
            }
        }
    }
}
