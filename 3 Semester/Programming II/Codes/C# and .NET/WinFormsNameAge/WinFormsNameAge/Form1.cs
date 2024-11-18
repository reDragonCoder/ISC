using System.Data;
using WinFormsNameAge.Data;
using WinFormsNameAge.Model;

namespace WinFormsNameAge
{
    public partial class Form1 : Form
    {
        DataTable table;
        User data = new User();

        public Form1()
        {
            InitializeComponent();
            Start();
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            Save();
            Start();
            Clear();
            See();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            Clear();
        }
        private void Start()
        {
            table = new DataTable();
            table.Columns.Add("Name");
            table.Columns.Add("Age");
            gridA.DataSource = table;

        }
        private void Save()
        {
            UserModel model = new UserModel()
            {
                Name = txtName.Text,
                Age = int.Parse(txtAge.Text)
            };
            data.Save(model);
        }
        private void See()
        {
            foreach (var item in data.See())
            {
                DataRow row = table.NewRow();
                row["Name"] = item.Name;
                row["Age"] = item.Age;
                table.Rows.Add(row);
            }
        }
        private void Clear()
        {
            txtName.Text = "";
            txtAge.Text = "";
        }

        private void gridA_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
