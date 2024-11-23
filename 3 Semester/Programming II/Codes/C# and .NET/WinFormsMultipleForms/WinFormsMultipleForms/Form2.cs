using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsMultipleForms
{
    public partial class Form2 : Form
    {
        private static int number;

        private string name;

        public static string color = "Red";
        public Form2()
        {
            InitializeComponent();
        }

        public Form2(string name)
        {
            this.name = name;
            Form2.number = FormPrincipal.num;
            InitializeComponent();
            this.textBoxName.Text = name;
            this.textBoxNumber.Text = Convert.ToString(Form2.number);
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void buttonGoBack_Click(object sender, EventArgs e)
        {
            MessageBox.Show("I'm going back");
            this.Close();
        }

        private void buttonForm3_Click(object sender, EventArgs e)
        {
            string favAnimal;
            favAnimal = this.textBoxFavAnimalCap.Text;
            Form3 f3 = new Form3(favAnimal);
            this.Hide();
            f3.ShowDialog();
            this.Show();
        }
    }
}
