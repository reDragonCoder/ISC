using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;

namespace WinFormsDataBaseManagement
{
    public class Clients
    {
        private int id;
        private string name;
        private string surname;
        private int visits;

        public Clients()
        { 
        }

        public Clients(int id, string name, string surname, int visits)
        {
            this.id = id;
            this.name = name;
            this.surname = surname;
            this.visits = visits;
        }

        public int Id { get => id; set => id = value; }
        public string Name { get => name; set => name = value; }
        public string Surname { get => surname; set => surname = value; }
        public int Visits { get => visits; set => visits = value; }
    }
}
