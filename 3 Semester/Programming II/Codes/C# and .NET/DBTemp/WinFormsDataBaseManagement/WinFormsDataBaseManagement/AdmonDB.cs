using MySql.Data.MySqlClient;
using System.Collections.Generic;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.Runtime.Intrinsics.Arm;
using Mysqlx.Crud;
using Microsoft.VisualBasic;

namespace WinFormsDataBaseManagement
{
    public class AdmonDB
    {
        private MySqlConnection connection;

        public AdmonDB()
        {
            this.Connect();
        }

        public void Disconnect()
        {
            if (connection != null && connection.State == System.Data.ConnectionState.Open)
            {
                connection.Close();
                MessageBox.Show("Connection closed successfully", "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        public List<Clients> consultation()
        {
            List<Clients> data = new List<Clients>();
            Clients person;
            int id;
            string name;
            string surname;
            int visits;
            try
            {
                string query = "SELECT * FROM storenorth";
                MySqlCommand command = new MySqlCommand(query, this.connection);

                //Run the query and read the results
                MySqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    //Example: show column data
                    id = Convert.ToInt32(reader["id"]);
                    name = Convert.ToString(reader["name"]) ?? "";
                    surname = Convert.ToString(reader["surname"]) ?? "";
                    visits = Convert.ToInt32(reader["visits"]);

                    person = new Clients(id, name, surname, visits);
                    data.Add(person);
                }
                reader.Close();
                data.ForEach((p) =>
                {
                    //MessageBox.Show(p.Id + "," + p.Name + "," + p.Surname + "," + p.visits);

                });
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error reading database table: " + ex.Message);
                this.Disconnect();
            }
            return data;
        }

        public void insert(int idp, string nm, string snm, int vs)
        {
            string query = "";
            try
            {
                /* This way of inserting is the least safe in terms of attacks by mysql but the simplest for now */
                query = "INSERT INTO storenorth (id,name,surname,visits) VALUES ("
                  + "'" + idp + "',"
                  + "'" + nm + "',"
                  + "'" + snm + "', "
                  + "'" + vs + "')";

                MySqlCommand cmd = new MySqlCommand(query, connection);
                cmd.ExecuteNonQuery();
                MessageBox.Show(query + "\nAdded Record");
            }
            catch (Exception ex)
            {
                MessageBox.Show(query + "\nDuplicate key" + ex.Message);
                this.Disconnect();
            }
        }

        public Clients queryARegistry(int idp)
        {
            Clients person = null;
            int id;
            string name;
            string surname;
            int visits;
            try
            {
                string query = "SELECT * FROM storenorth where id=" + idp + ";";
                MySqlCommand command = new MySqlCommand(query, this.connection);

                //Run the query and read the results
                MySqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    id = Convert.ToInt32(reader["id"]);
                    name = Convert.ToString(reader["name"]) ?? "";
                    surname = Convert.ToString(reader["surname"]) ?? "";
                    visits = (int)Convert.ToInt64(reader["visits"]);

                    person = new Clients(id, name, surname, visits);
                }
                reader.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error reading database table: " + ex.Message);
                this.Disconnect();
            }
            return person;
        }

        public void delete(int idp)
        {
            string query = "";
            try
            {
                query = "DELETE FROM storenorth WHERE id=" + idp + ";";

                MySqlCommand cmd = new MySqlCommand(query, connection);
                cmd.ExecuteNonQuery();
                MessageBox.Show(query + "\nDeleted Record");
            }
            catch (Exception ex)
            {
                MessageBox.Show(query + "\nError " + ex.Message);
                this.Disconnect();
            }
        }

        public void update(int idp, string nm, string snm, int phn)
        {
            // UPDATE `storenorth` SET `id`= '[value-1]',`name`= '[value-2]',`surname`= '[value-3]',`visits`= '[value-4]' WHERE 1
            try
            {
                string query = "UPDATE storenorth SET id=" + "'" + idp + "'" + ",name=" + "'" + nm + "'" + ",surname=" + "'" + snm + "'" + ",visits=" + "'" + phn + "'" + "where id=" + idp + ";";
                MessageBox.Show(query);
                MySqlCommand cmd = new MySqlCommand(query, connection);
                cmd.ExecuteNonQuery();
                MessageBox.Show(query + "\nUpdated Record");


            }
            catch (Exception ex)
            {
                MessageBox.Show("Update error: " + ex.Message);
                this.Disconnect();
            }
        }

        public void Connect()
        {
            string chain = "Server=localhost; Database=customers; User=root; Password=; SslMode=none;";
            try
            {
                connection = new MySqlConnection(chain);
                connection.Open();
                MessageBox.Show("Connection established successfully.", "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error connecting to the database: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }


    }

}
