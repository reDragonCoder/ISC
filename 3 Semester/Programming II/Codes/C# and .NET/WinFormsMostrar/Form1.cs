using System.Windows.Forms;

namespace WinFormsMostrar
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttoncargar_Click(object sender, EventArgs e)
        {
            List<string> imagenes = new List<string>() { "spiderman.jpeg", "ironman.jpeg", "captain.jpeg", "batman.jpeg", "wolverine.jpeg", "deadpool.jpeg", "venom.jpeg" };

            for (int i = 0; i < imagenes.Count; i++)
            {
                switch (i)
                {
                    case 0:
                        this.pictureBox1.Image = System.Drawing.Image.FromFile(
    Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "imagenes", imagenes[0])); break;
                    case 1:
                        this.pictureBox2.Image = System.Drawing.Image.FromFile(
    Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "imagenes", imagenes[1])); break;
                    case 2:
                        this.pictureBox3.Image = System.Drawing.Image.FromFile(
    Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "imagenes", imagenes[2])); break;
                    case 3:
                        this.pictureBox4.Image = System.Drawing.Image.FromFile(
    Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "imagenes", imagenes[3])); break;
                    case 4:
                        this.pictureBox5.Image = System.Drawing.Image.FromFile(
    Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "imagenes", imagenes[4])); break;
                    case 5:
                        this.pictureBox6.Image = System.Drawing.Image.FromFile(
    Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "imagenes", imagenes[5])); break;
                    case 6:
                        this.pictureBox7.Image = System.Drawing.Image.FromFile(
    Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "imagenes", imagenes[6])); break;
                    case 7:
                        this.pictureBox8.Image = System.Drawing.Image.FromFile(
    Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "imagenes", imagenes[7])); break;
                }

            }
     

        }
    }
}
