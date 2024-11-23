namespace WinFormsMultipleImagesPictureBox
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
            buttonJason = new Button();
            buttonFreddy = new Button();
            buttonSaw = new Button();
            buttonIt = new Button();
            pictureBox1 = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // buttonJason
            // 
            buttonJason.BackColor = SystemColors.ActiveCaption;
            buttonJason.Font = new Font("Comic Sans MS", 9F);
            buttonJason.Location = new Point(44, 379);
            buttonJason.Name = "buttonJason";
            buttonJason.Size = new Size(94, 29);
            buttonJason.TabIndex = 1;
            buttonJason.Text = "Jason";
            buttonJason.UseVisualStyleBackColor = false;
            buttonJason.Click += buttonJason_Click;
            // 
            // buttonFreddy
            // 
            buttonFreddy.BackColor = SystemColors.ActiveCaption;
            buttonFreddy.Font = new Font("Comic Sans MS", 9F);
            buttonFreddy.Location = new Point(177, 379);
            buttonFreddy.Name = "buttonFreddy";
            buttonFreddy.Size = new Size(94, 29);
            buttonFreddy.TabIndex = 2;
            buttonFreddy.Text = "Freddy";
            buttonFreddy.UseVisualStyleBackColor = false;
            buttonFreddy.Click += buttonFreddy_Click;
            // 
            // buttonSaw
            // 
            buttonSaw.BackColor = SystemColors.ActiveCaption;
            buttonSaw.Font = new Font("Comic Sans MS", 9F);
            buttonSaw.Location = new Point(315, 379);
            buttonSaw.Name = "buttonSaw";
            buttonSaw.Size = new Size(94, 29);
            buttonSaw.TabIndex = 3;
            buttonSaw.Text = "Saw";
            buttonSaw.UseVisualStyleBackColor = false;
            buttonSaw.Click += buttonSaw_Click;
            // 
            // buttonIt
            // 
            buttonIt.BackColor = SystemColors.ActiveCaption;
            buttonIt.Font = new Font("Comic Sans MS", 9F);
            buttonIt.Location = new Point(443, 379);
            buttonIt.Name = "buttonIt";
            buttonIt.Size = new Size(94, 29);
            buttonIt.TabIndex = 4;
            buttonIt.Text = "It";
            buttonIt.UseVisualStyleBackColor = false;
            buttonIt.Click += buttonIt_Click;
            // 
            // pictureBox1
            // 
            pictureBox1.Image = Properties.Resources.jason;
            pictureBox1.Location = new Point(79, 46);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(430, 290);
            pictureBox1.TabIndex = 5;
            pictureBox1.TabStop = false;
            pictureBox1.Click += pictureBox1_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ActiveCaptionText;
            ClientSize = new Size(591, 494);
            Controls.Add(pictureBox1);
            Controls.Add(buttonIt);
            Controls.Add(buttonSaw);
            Controls.Add(buttonFreddy);
            Controls.Add(buttonJason);
            Name = "Form1";
            Text = "Multiple Images";
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
        }

        #endregion
        private Button buttonJason;
        private Button buttonFreddy;
        private Button buttonSaw;
        private Button buttonIt;
        private PictureBox pictureBox1;
    }
}
