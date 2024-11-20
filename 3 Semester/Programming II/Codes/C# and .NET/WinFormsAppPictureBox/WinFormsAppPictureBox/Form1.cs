namespace WinFormsAppPictureBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnUploadImage_Click(object sender, EventArgs e)
        {
            OpenFileDialog openImage = new OpenFileDialog();
            
            //we open the file explorer in Windows
            if(openImage.ShowDialog() == DialogResult.OK)
            {
                pictureBox1.ImageLocation = openImage.FileName;
                pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            }
        }
    }
}
