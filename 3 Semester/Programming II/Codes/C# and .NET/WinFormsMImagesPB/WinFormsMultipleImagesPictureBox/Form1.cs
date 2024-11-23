using System.Windows.Forms;

namespace WinFormsMultipleImagesPictureBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void buttonJason_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = WinFormsMultipleImagesPictureBox.Properties.Resources.jason1;
        }

        private void buttonFreddy_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = WinFormsMultipleImagesPictureBox.Properties.Resources.freddy1;
        }

        private void buttonSaw_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = WinFormsMultipleImagesPictureBox.Properties.Resources.saw1;
        }

        private void buttonIt_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = WinFormsMultipleImagesPictureBox.Properties.Resources.it1;
        }
    }
}
