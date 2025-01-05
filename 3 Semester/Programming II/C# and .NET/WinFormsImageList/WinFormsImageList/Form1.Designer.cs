namespace WinFormsImageList
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            imglPhotos = new ImageList(components);
            lblPhoto = new Label();
            btnChange = new Button();
            label1 = new Label();
            SuspendLayout();
            // 
            // imglPhotos
            // 
            imglPhotos.ColorDepth = ColorDepth.Depth32Bit;
            imglPhotos.ImageStream = (ImageListStreamer)resources.GetObject("imglPhotos.ImageStream");
            imglPhotos.TransparentColor = Color.Transparent;
            imglPhotos.Images.SetKeyName(0, "1.jpeg");
            imglPhotos.Images.SetKeyName(1, "2.jpeg");
            imglPhotos.Images.SetKeyName(2, "3.jpeg");
            imglPhotos.Images.SetKeyName(3, "4.jpeg");
            imglPhotos.Images.SetKeyName(4, "5.jpeg");
            imglPhotos.Images.SetKeyName(5, "6.jpeg");
            imglPhotos.Images.SetKeyName(6, "7.jpeg");
            imglPhotos.Images.SetKeyName(7, "8.jpeg");
            // 
            // lblPhoto
            // 
            lblPhoto.ImageIndex = 0;
            lblPhoto.ImageList = imglPhotos;
            lblPhoto.Location = new Point(206, 51);
            lblPhoto.Name = "lblPhoto";
            lblPhoto.Size = new Size(300, 300);
            lblPhoto.TabIndex = 0;
            // 
            // btnChange
            // 
            btnChange.BackColor = SystemColors.GradientActiveCaption;
            btnChange.Font = new Font("Comic Sans MS", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnChange.Location = new Point(266, 384);
            btnChange.Name = "btnChange";
            btnChange.Size = new Size(182, 57);
            btnChange.TabIndex = 1;
            btnChange.Text = "Change Image";
            btnChange.UseVisualStyleBackColor = false;
            btnChange.Click += btnChange_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = SystemColors.ActiveCaptionText;
            label1.Font = new Font("Comic Sans MS", 10.8F, FontStyle.Italic, GraphicsUnit.Point, 0);
            label1.ForeColor = SystemColors.Control;
            label1.Location = new Point(12, 525);
            label1.Name = "label1";
            label1.Size = new Size(0, 26);
            label1.TabIndex = 2;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ActiveCaptionText;
            ClientSize = new Size(701, 560);
            Controls.Add(label1);
            Controls.Add(btnChange);
            Controls.Add(lblPhoto);
            Name = "Form1";
            Text = "Image List";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ImageList imglPhotos;
        private Label lblPhoto;
        private Button btnChange;
        private Label label1;
    }
}
