namespace WinFormsPruebaBD
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            richTextBox1 = new RichTextBox();
            buttonRefrescar = new Button();
            imageList1 = new ImageList(components);
            textBoxId = new TextBox();
            textBoxproducto = new TextBox();
            textBoxImagen = new TextBox();
            textBoxPrecio = new TextBox();
            buttonInsertar = new Button();
            buttonEliminar = new Button();
            textBoxEliminar = new TextBox();
            textBoxidMod = new TextBox();
            buttonver = new Button();
            textBoxModId = new TextBox();
            textBoxprodMod = new TextBox();
            textBoxImgMod = new TextBox();
            textBoxPrecioMod = new TextBox();
            buttonMod = new Button();
            label1 = new Label();
            SuspendLayout();
            // 
            // richTextBox1
            // 
            richTextBox1.Location = new Point(45, 31);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(662, 305);
            richTextBox1.TabIndex = 0;
            richTextBox1.Text = "";
            // 
            // buttonRefrescar
            // 
            buttonRefrescar.Location = new Point(45, 356);
            buttonRefrescar.Name = "buttonRefrescar";
            buttonRefrescar.Size = new Size(101, 46);
            buttonRefrescar.TabIndex = 2;
            buttonRefrescar.Text = "refrescar";
            buttonRefrescar.UseVisualStyleBackColor = true;
            buttonRefrescar.Click += button1_Click;
            // 
            // imageList1
            // 
            imageList1.ColorDepth = ColorDepth.Depth8Bit;
            imageList1.ImageSize = new Size(16, 16);
            imageList1.TransparentColor = Color.Transparent;
            // 
            // textBoxId
            // 
            textBoxId.Location = new Point(723, 31);
            textBoxId.Name = "textBoxId";
            textBoxId.PlaceholderText = "id";
            textBoxId.Size = new Size(136, 27);
            textBoxId.TabIndex = 3;
            // 
            // textBoxproducto
            // 
            textBoxproducto.Location = new Point(723, 83);
            textBoxproducto.Name = "textBoxproducto";
            textBoxproducto.PlaceholderText = "nombre producto";
            textBoxproducto.Size = new Size(136, 27);
            textBoxproducto.TabIndex = 4;
            // 
            // textBoxImagen
            // 
            textBoxImagen.Location = new Point(723, 136);
            textBoxImagen.Name = "textBoxImagen";
            textBoxImagen.PlaceholderText = "nombre imagen";
            textBoxImagen.Size = new Size(136, 27);
            textBoxImagen.TabIndex = 5;
            // 
            // textBoxPrecio
            // 
            textBoxPrecio.Location = new Point(723, 185);
            textBoxPrecio.Name = "textBoxPrecio";
            textBoxPrecio.PlaceholderText = "precio producto";
            textBoxPrecio.Size = new Size(136, 27);
            textBoxPrecio.TabIndex = 6;
            // 
            // buttonInsertar
            // 
            buttonInsertar.Location = new Point(723, 243);
            buttonInsertar.Name = "buttonInsertar";
            buttonInsertar.Size = new Size(94, 29);
            buttonInsertar.TabIndex = 7;
            buttonInsertar.Text = "Agregar";
            buttonInsertar.UseVisualStyleBackColor = true;
            buttonInsertar.Click += buttonInsertar_Click;
            // 
            // buttonEliminar
            // 
            buttonEliminar.Location = new Point(726, 386);
            buttonEliminar.Name = "buttonEliminar";
            buttonEliminar.Size = new Size(94, 29);
            buttonEliminar.TabIndex = 8;
            buttonEliminar.Text = "eliminar";
            buttonEliminar.UseVisualStyleBackColor = true;
            buttonEliminar.Click += buttonEliminar_Click;
            // 
            // textBoxEliminar
            // 
            textBoxEliminar.AllowDrop = true;
            textBoxEliminar.Location = new Point(582, 386);
            textBoxEliminar.Name = "textBoxEliminar";
            textBoxEliminar.PlaceholderText = "id a eliminar";
            textBoxEliminar.Size = new Size(125, 27);
            textBoxEliminar.TabIndex = 9;
            // 
            // textBoxidMod
            // 
            textBoxidMod.Location = new Point(991, 36);
            textBoxidMod.Name = "textBoxidMod";
            textBoxidMod.PlaceholderText = "id a modificar";
            textBoxidMod.Size = new Size(125, 27);
            textBoxidMod.TabIndex = 10;
            // 
            // buttonver
            // 
            buttonver.Location = new Point(1149, 35);
            buttonver.Name = "buttonver";
            buttonver.Size = new Size(230, 29);
            buttonver.TabIndex = 11;
            buttonver.Text = "ver datos de id a modificar";
            buttonver.UseVisualStyleBackColor = true;
            buttonver.Click += buttonver_Click;
            // 
            // textBoxModId
            // 
            textBoxModId.Location = new Point(991, 93);
            textBoxModId.Name = "textBoxModId";
            textBoxModId.Size = new Size(127, 27);
            textBoxModId.TabIndex = 12;
            // 
            // textBoxprodMod
            // 
            textBoxprodMod.Location = new Point(989, 146);
            textBoxprodMod.Name = "textBoxprodMod";
            textBoxprodMod.Size = new Size(127, 27);
            textBoxprodMod.TabIndex = 13;
            // 
            // textBoxImgMod
            // 
            textBoxImgMod.Location = new Point(989, 197);
            textBoxImgMod.Name = "textBoxImgMod";
            textBoxImgMod.Size = new Size(127, 27);
            textBoxImgMod.TabIndex = 14;
            // 
            // textBoxPrecioMod
            // 
            textBoxPrecioMod.Location = new Point(989, 245);
            textBoxPrecioMod.Name = "textBoxPrecioMod";
            textBoxPrecioMod.Size = new Size(127, 27);
            textBoxPrecioMod.TabIndex = 15;
            // 
            // buttonMod
            // 
            buttonMod.Location = new Point(989, 306);
            buttonMod.Name = "buttonMod";
            buttonMod.Size = new Size(119, 30);
            buttonMod.TabIndex = 16;
            buttonMod.Text = "modificar";
            buttonMod.UseVisualStyleBackColor = true;
            buttonMod.Click += buttonMod_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(12, 503);
            label1.Name = "label1";
            label1.Size = new Size(0, 20);
            label1.TabIndex = 17;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1461, 532);
            Controls.Add(label1);
            Controls.Add(buttonMod);
            Controls.Add(textBoxPrecioMod);
            Controls.Add(textBoxImgMod);
            Controls.Add(textBoxprodMod);
            Controls.Add(textBoxModId);
            Controls.Add(buttonver);
            Controls.Add(textBoxidMod);
            Controls.Add(textBoxEliminar);
            Controls.Add(buttonEliminar);
            Controls.Add(buttonInsertar);
            Controls.Add(textBoxPrecio);
            Controls.Add(textBoxImagen);
            Controls.Add(textBoxproducto);
            Controls.Add(textBoxId);
            Controls.Add(buttonRefrescar);
            Controls.Add(richTextBox1);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private RichTextBox richTextBox1;
        private Button buttonRefrescar;
        private ImageList imageList1;
        private TextBox textBoxId;
        private TextBox textBoxproducto;
        private TextBox textBoxImagen;
        private TextBox textBoxPrecio;
        private Button buttonInsertar;
        private Button buttonEliminar;
        private TextBox textBoxEliminar;
        private TextBox textBoxidMod;
        private Button buttonver;
        private TextBox textBoxModId;
        private TextBox textBoxprodMod;
        private TextBox textBoxImgMod;
        private TextBox textBoxPrecioMod;
        private Button buttonMod;
        private Label label1;
    }
}
