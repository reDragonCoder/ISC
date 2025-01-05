namespace WinFormsAppPictureBox
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
            btnUploadImage = new Button();
            pictureBox1 = new PictureBox();
            label1 = new Label();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // btnUploadImage
            // 
            btnUploadImage.BackColor = Color.LimeGreen;
            btnUploadImage.Font = new Font("Goudy Old Style", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnUploadImage.Location = new Point(140, 39);
            btnUploadImage.Name = "btnUploadImage";
            btnUploadImage.Size = new Size(258, 56);
            btnUploadImage.TabIndex = 0;
            btnUploadImage.Text = "Upload Image";
            btnUploadImage.UseVisualStyleBackColor = false;
            btnUploadImage.Click += btnUploadImage_Click;
            // 
            // pictureBox1
            // 
            pictureBox1.Location = new Point(12, 128);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(515, 301);
            pictureBox1.TabIndex = 1;
            pictureBox1.TabStop = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = SystemColors.InfoText;
            label1.Font = new Font("Goudy Old Style", 10.2F, FontStyle.Italic, GraphicsUnit.Point, 0);
            label1.ForeColor = Color.LawnGreen;
            label1.Location = new Point(12, 452);
            label1.Name = "label1";
            label1.Size = new Size(193, 19);
            label1.TabIndex = 2;
            label1.Text = "Cesar Andres Zuleta Malanco";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ActiveCaptionText;
            ClientSize = new Size(539, 491);
            Controls.Add(label1);
            Controls.Add(pictureBox1);
            Controls.Add(btnUploadImage);
            Name = "Form1";
            Text = "Image Display";
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button btnUploadImage;
        private PictureBox pictureBox1;
        private Label label1;
    }
}
