namespace WinFormsImageList
{
    public partial class Form1 : Form
    {
        private int index;
        public Form1()
        {
            InitializeComponent();
            index = 0;
        }

        private void btnChange_Click(object sender, EventArgs e)
        {
            index++;
            if (index > 7)
                index = 0;
            lblPhoto.ImageIndex = index;
        }
    }
}
