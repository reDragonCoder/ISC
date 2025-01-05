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
    public partial class Form3 : Form
    {
        private string favAnimal;

        public static string color2;

        public Form3()
        {
            InitializeComponent();
        }

        public Form3(string favAnimal)
        {
            this.favAnimal = favAnimal;
            Form3.color2 = Form2.color;
            InitializeComponent();
            this.textBoxFavAnimal.Text = favAnimal;
            this.textBoxColor.Text = Form3.color2;
        }

        private void buttonGoBack2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("I'm going back");
            this.Close();
        }
    }
}
