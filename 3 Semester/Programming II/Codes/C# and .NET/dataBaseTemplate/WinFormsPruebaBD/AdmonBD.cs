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

namespace WinFormsPruebaBD
{

    public class AdmonBD
    {

        private MySqlConnection connection;

        public AdmonBD()
        {
            this.Connect();
        }

        public void Disconnect()
        {
            if (connection != null && connection.State == System.Data.ConnectionState.Open)
            {
                connection.Close();
                MessageBox.Show("Conexión cerrada correctamente.", "Información", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }


        public List<Productos> consulta()
        {
            List<Productos> data = new List<Productos>();
            Productos item;
            int id;
            string producto;
            string imagen;
            int precio;
            try
            {
                string query = "SELECT * FROM prendas";
                MySqlCommand command = new MySqlCommand(query, this.connection);

                // Ejecutar la consulta y leer los resultados
                MySqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    // Ejemplo: mostrar los datos de las columnas
                    id = Convert.ToInt32(reader["id"]);
                    producto = Convert.ToString(reader["producto"]) ?? "";
                    imagen = Convert.ToString(reader["imagen"]) ?? "";
                    precio = Convert.ToInt32(reader["precio"]);

                    item = new Productos(id, producto, imagen, precio);
                    data.Add(item);

                }
                reader.Close();
                data.ForEach((p) =>
                {
                    //MessageBox.Show(p.Id + "," + p.Producto + "," + p.Imagen + "," + p.Precio);

                });

            }
            catch (Exception ex)
            {
                MessageBox.Show("Error al leer la tabla de la base de datos: " + ex.Message);
                this.Disconnect();
            }
            return data;
        }

        public void insertar(int idp, string prod, string img,  int price)
        {
            string query="";
            try
            {

                /* Esta forma de insertar es la menos segura en cuanto ataques por mysql pero la mas sencilla por lo pronto*/
                   query = "INSERT INTO prendas (id,producto,imagen,precio) VALUES ("
                  + "'"+idp + "',"
                  + "'" + prod + "',"
                  + "'" + img + "', "
                  + "'" + price + "')";

               

                MySqlCommand cmd = new MySqlCommand(query, connection);
                cmd.ExecuteNonQuery();
                MessageBox.Show(query+"\nRegistro Agregado");
            }
            catch (Exception ex)
            {
                MessageBox.Show(query +  "\nClave duplicada"+ex.Message);
                this.Disconnect();
            }


        }

    public Productos consultaUnRegistro(int idp)
        {
           
            Productos item=null;
            int id;
            string producto;
            string imagen;
            int precio;
            try
            {
                string query = "SELECT * FROM prendas where id="+idp+";";
                MySqlCommand command = new MySqlCommand(query, this.connection);

                // Ejecutar la consulta y leer los resultados
                MySqlDataReader reader = command.ExecuteReader();
                while (reader.Read())  //solo encontrara un registro da una vuelta
                {
                    
                    id = Convert.ToInt32(reader["id"]);
                    producto = Convert.ToString(reader["producto"]) ?? "";
                    imagen = Convert.ToString(reader["imagen"]) ?? "";
                    precio = Convert.ToInt32(reader["precio"]);

                    item = new Productos(id, producto, imagen, precio);
                    

                }
                reader.Close();
               

            }
            catch (Exception ex)
            {
                MessageBox.Show("Error al leer la tabla de la base de datos: " + ex.Message);
                this.Disconnect();
            }
            return item;
        }


    public void eliminar(int idp)
        {
            string query = "";
            try
            {

                /* Esta forma de insertar es la menos segura en cuanto ataques por mysql pero la mas sencilla por lo pronto*/

                query="DELETE FROM prendas WHERE id="+idp+";";
             
                MySqlCommand cmd = new MySqlCommand(query, connection);
                cmd.ExecuteNonQuery();
                MessageBox.Show(query + "\nRegistro Eliminado");
            }
            catch (Exception ex)
            {
                MessageBox.Show(query + "\nError " + ex.Message);
                this.Disconnect();
            }
        }


        public void actualizar(int idp, string prod, string img, int price)
        {
            // UPDATE `prendas` SET `id`= '[value-1]',`producto`= '[value-2]',`imagen`= '[value-3]',`precio`= '[value-4]' WHERE 1
            try
            {
                string query = "UPDATE prendas SET id=" + "'"+idp+"'" + ",producto=" + "'" + prod + "'"+ ",imagen=" +"'"+ img + "'"+",precio="+ "'"+price+"'"+ "where id=" + idp + ";";
                MessageBox.Show(query);
                MySqlCommand cmd = new MySqlCommand(query, connection);
                cmd.ExecuteNonQuery();
                MessageBox.Show(query + "\nRegistro Actualizado");


            }
            catch (Exception ex)
            {
                MessageBox.Show("Error en la actualizacion: " + ex.Message);
                this.Disconnect();
            }
        }

    public void Connect()
        {
            string cadena = "Server=localhost; Database=productos; User=root; Password=; SslMode=none;";
            try
            {
                connection = new MySqlConnection(cadena);
                connection.Open();
                MessageBox.Show("Conexión establecida exitosamente.", "Información", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error al conectar con la base de datos: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
