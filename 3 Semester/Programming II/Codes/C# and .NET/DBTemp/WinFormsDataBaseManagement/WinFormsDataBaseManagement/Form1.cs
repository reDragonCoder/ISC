using MySql.Data.MySqlClient;
using System.Windows.Forms;

namespace WinFormsDataBaseManagement
{
    public partial class Form1 : Form
    {
        List<Clients> data;
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            AdmonDB obj = new AdmonDB();
            data = obj.consultation();

            /*show info*/
            this.richTextBox1.Clear();
            data.ForEach(p =>
            {
                this.richTextBox1.AppendText("id=" + p.Id + " Name=" + p.Name + " Surname=" + p.Surname + " Visits=" + p.Visits + "\n");
            });

            obj.Disconnect();
        }

        public void clean()
        {
            MessageBox.Show("Go in to clean");

            this.textBoxId.Clear();
            this.textBoxName.Clear();
            this.textBoxSurname.Clear();
            this.textBoxVisits.Clear();

            this.textBoxId.PlaceholderText = "id";
            this.textBoxName.PlaceholderText = "name";
            this.textBoxSurname.PlaceholderText = "surname";
            this.textBoxVisits.PlaceholderText = "visits";
        }


        private void buttonAdd_Click(object sender, EventArgs e)
        {
            int id;
            string name;
            string surname;
            int visits;
            id = Convert.ToInt32(this.textBoxId.Text);
            name = this.textBoxName.Text;
            surname = this.textBoxSurname.Text;
            visits = Convert.ToInt32(this.textBoxVisits.Text);

            AdmonDB obj = new AdmonDB();
            obj.insert(id, name, surname, visits);
            clean();
            obj.Disconnect();
        }

        private void textBoxName_TextChanged(object sender, EventArgs e)
        {

        }

        private void buttonEliminate_Click(object sender, EventArgs e)
        {
            AdmonDB obj = new AdmonDB();
            obj.delete(Convert.ToInt32(this.textBoxEliminateId.Text));
            this.textBoxEliminateId.Clear();
            this.textBoxEliminateId.PlaceholderText = "ID to eliminate";
            obj.Disconnect();
        }

        private void buttonShowInfo_Click(object sender, EventArgs e)
        {
            AdmonDB obj = new AdmonDB();
            Clients aux = obj.queryARegistry(Convert.ToInt32(this.textBoxToModify.Text));
            MessageBox.Show("aux=" + aux.Id + " " + aux.Name + " " + aux.Surname + " " + aux.Visits);


            this.textBoxModifyId.Text = Convert.ToString(aux.Id);
            this.textBoxModifyName.Text = aux.Name;
            this.textBoxModifySurname.Text = aux.Surname;
            this.textBoxModifyVisits.Text = Convert.ToString(aux.Visits);


            obj.Disconnect();
        }

        private void buttonModify_Click(object sender, EventArgs e)
        {
            int id;
            string name;
            string surname;
            int visits;

            id = Convert.ToInt32(this.textBoxModifyId.Text);
            name = this.textBoxModifyName.Text;
            surname = this.textBoxModifySurname.Text;
            visits = Convert.ToInt32(this.textBoxModifyVisits.Text);


            AdmonDB obj = new AdmonDB();

            obj.update(id, name, surname, visits);
            obj.Disconnect();
        }
    }
}
