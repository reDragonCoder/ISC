using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsPruebaBD
{
    public class Productos
    {
        private int id;
        private string producto;
        private string imagen;
        private int precio;

        public Productos()
        {

        }

        public Productos(int id, string producto, string imagen, int precio)
        {
            this.Id = id;
            this.Producto = producto;
            this.Imagen = imagen;
            this.Precio = precio;
        }

        public int Id { get => id; set => id = value; }
        public string Producto { get => producto; set => producto = value; }
        public string Imagen { get => imagen; set => imagen = value; }
        public int Precio { get => precio; set => precio = value; }
    }
}
