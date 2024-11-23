namespace WinFormsMultiplePictureBoxes
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
            pictureBox3 = new PictureBox();
            button1 = new Button();
            pb1 = new PictureBox();
            pb2 = new PictureBox();
            pb3 = new PictureBox();
            pb4 = new PictureBox();
            pb5 = new PictureBox();
            pb6 = new PictureBox();
            label1 = new Label();
            ((System.ComponentModel.ISupportInitialize)pictureBox3).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pb1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pb2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pb3).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pb4).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pb5).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pb6).BeginInit();
            SuspendLayout();
            // 
            // pictureBox3
            // 
            pictureBox3.Location = new Point(-1, 327);
            pictureBox3.Name = "pictureBox3";
            pictureBox3.Size = new Size(0, 0);
            pictureBox3.TabIndex = 2;
            pictureBox3.TabStop = false;
            // 
            // button1
            // 
            button1.BackColor = SystemColors.ActiveCaption;
            button1.Font = new Font("Comic Sans MS", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button1.Location = new Point(357, 537);
            button1.Name = "button1";
            button1.Size = new Size(159, 54);
            button1.TabIndex = 9;
            button1.Text = "Upload Images";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // pb1
            // 
            pb1.Location = new Point(54, 38);
            pb1.Name = "pb1";
            pb1.Size = new Size(200, 200);
            pb1.TabIndex = 10;
            pb1.TabStop = false;
            // 
            // pb2
            // 
            pb2.Location = new Point(338, 38);
            pb2.Name = "pb2";
            pb2.Size = new Size(200, 200);
            pb2.TabIndex = 11;
            pb2.TabStop = false;
            // 
            // pb3
            // 
            pb3.Location = new Point(615, 38);
            pb3.Name = "pb3";
            pb3.Size = new Size(200, 200);
            pb3.TabIndex = 12;
            pb3.TabStop = false;
            // 
            // pb4
            // 
            pb4.Location = new Point(54, 284);
            pb4.Name = "pb4";
            pb4.Size = new Size(200, 200);
            pb4.TabIndex = 13;
            pb4.TabStop = false;
            // 
            // pb5
            // 
            pb5.Location = new Point(338, 284);
            pb5.Name = "pb5";
            pb5.Size = new Size(200, 200);
            pb5.TabIndex = 14;
            pb5.TabStop = false;
            // 
            // pb6
            // 
            pb6.Location = new Point(615, 284);
            pb6.Name = "pb6";
            pb6.Size = new Size(200, 200);
            pb6.TabIndex = 15;
            pb6.TabStop = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(0, 0);
            label1.Name = "label1";
            label1.Size = new Size(50, 20);
            label1.TabIndex = 16;
            label1.Text = "label1";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ActiveCaptionText;
            ClientSize = new Size(876, 652);
            Controls.Add(label1);
            Controls.Add(pb6);
            Controls.Add(pb5);
            Controls.Add(pb4);
            Controls.Add(pb3);
            Controls.Add(pb2);
            Controls.Add(pb1);
            Controls.Add(button1);
            Controls.Add(pictureBox3);
            Name = "Form1";
            Text = "Multiple PictureBoxes";
            ((System.ComponentModel.ISupportInitialize)pictureBox3).EndInit();
            ((System.ComponentModel.ISupportInitialize)pb1).EndInit();
            ((System.ComponentModel.ISupportInitialize)pb2).EndInit();
            ((System.ComponentModel.ISupportInitialize)pb3).EndInit();
            ((System.ComponentModel.ISupportInitialize)pb4).EndInit();
            ((System.ComponentModel.ISupportInitialize)pb5).EndInit();
            ((System.ComponentModel.ISupportInitialize)pb6).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private PictureBox pictureBox3;
        private Button button1;
        private PictureBox pb1;
        private PictureBox pb2;
        private PictureBox pb3;
        private PictureBox pb4;
        private PictureBox pb5;
        private PictureBox pb6;
        private Label label1;
    }
}
