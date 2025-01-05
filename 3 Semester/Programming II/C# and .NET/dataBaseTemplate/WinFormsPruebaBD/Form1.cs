using MySql.Data.MySqlClient;
using System.Windows.Forms;

namespace WinFormsPruebaBD
{
    public partial class Form1 : Form
    {

        List<Productos> data;
        public Form1()
        {
            InitializeComponent();

        }



        private void Form1_Load(object sender, EventArgs e)
        {


        }



        private void button1_Click(object sender, EventArgs e)
        {
            AdmonBD obj = new AdmonBD();
            data = obj.consulta();

            /*muestra informacion*/
            this.richTextBox1.Clear();
            data.ForEach(p =>
            {
                this.richTextBox1.AppendText("id=" + p.Id + " producto=" + p.Producto + " Imagen=" + p.Imagen + " Precio:" + p.Precio + "\n");
            });

            obj.Disconnect();
        }

        private async void buttonInsertar_Click(object sender, EventArgs e)
        {
            int id;
            string producto;
            string imagen;
            int precio;
            id = Convert.ToInt32(this.textBoxId.Text);
            producto = this.textBoxproducto.Text;
            imagen = this.textBoxImagen.Text;
            precio = Convert.ToInt32(this.textBoxPrecio.Text);

            AdmonBD obj = new AdmonBD();
            obj.insertar(id, producto, imagen, precio);
            limpiar();
            obj.Disconnect();

        }

        public void limpiar()
        {
            MessageBox.Show("entre a limpiar");
            this.textBoxId.PlaceholderText = "id";
            this.textBoxImagen.PlaceholderText = "nombre imagen";
            this.textBoxPrecio.PlaceholderText = "nombre precio";
            this.textBoxproducto.PlaceholderText = "nombre producto";

        }

        private void buttonEliminar_Click(object sender, EventArgs e)
        {
            AdmonBD obj = new AdmonBD();
            obj.eliminar(Convert.ToInt32(this.textBoxEliminar.Text));
            this.textBoxEliminar.PlaceholderText = "id eliminar";
            obj.Disconnect();

        }

        private void buttonver_Click(object sender, EventArgs e)
        {
            AdmonBD obj = new AdmonBD();
            Productos aux = obj.consultaUnRegistro(Convert.ToInt32(this.textBoxidMod.Text));
            MessageBox.Show("aux=" + aux.Id + " " + aux.Producto + " " + aux.Imagen + " " + aux.Precio);


            this.textBoxModId.Text = Convert.ToString(aux.Id);
            this.textBoxprodMod.Text = aux.Producto;
            this.textBoxImgMod.Text = aux.Imagen;
            this.textBoxPrecioMod.Text = Convert.ToString(aux.Precio);


            obj.Disconnect();
        }

        private void buttonMod_Click(object sender, EventArgs e)
        {
            int id;
            string producto;
            string imagen;
            int precio;

            id = Convert.ToInt32(this.textBoxModId.Text);
            producto = this.textBoxprodMod.Text;
            imagen = this.textBoxImgMod.Text;
            precio = Convert.ToInt32(this.textBoxPrecioMod.Text);


            AdmonBD obj = new AdmonBD();

            obj.actualizar(id, producto, imagen, precio);
            obj.Disconnect();
        }
 
    }
}
    
    
        
