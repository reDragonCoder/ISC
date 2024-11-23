namespace WinFormsMultipleForms
{
    partial class FormPrincipal
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
            labelTitle = new Label();
            buttonForm2 = new Button();
            buttonForm3 = new Button();
            textBoxData = new TextBox();
            buttonExit = new Button();
            label1 = new Label();
            SuspendLayout();
            // 
            // labelTitle
            // 
            labelTitle.AutoSize = true;
            labelTitle.BackColor = Color.Transparent;
            labelTitle.Font = new Font("Lucida Calligraphy", 19.8000011F, FontStyle.Bold, GraphicsUnit.Point, 0);
            labelTitle.ForeColor = SystemColors.ButtonHighlight;
            labelTitle.Location = new Point(259, 64);
            labelTitle.Name = "labelTitle";
            labelTitle.Size = new Size(299, 44);
            labelTitle.TabIndex = 0;
            labelTitle.Text = "Principal Title";
            // 
            // buttonForm2
            // 
            buttonForm2.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonForm2.Location = new Point(247, 170);
            buttonForm2.Name = "buttonForm2";
            buttonForm2.Size = new Size(148, 67);
            buttonForm2.TabIndex = 1;
            buttonForm2.Text = "Form 2";
            buttonForm2.UseVisualStyleBackColor = true;
            buttonForm2.Click += buttonForm2_Click;
            // 
            // buttonForm3
            // 
            buttonForm3.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonForm3.Location = new Point(440, 170);
            buttonForm3.Name = "buttonForm3";
            buttonForm3.Size = new Size(148, 67);
            buttonForm3.TabIndex = 2;
            buttonForm3.Text = "Form 3";
            buttonForm3.UseVisualStyleBackColor = true;
            buttonForm3.Click += buttonForm3_Click;
            // 
            // textBoxData
            // 
            textBoxData.Location = new Point(301, 301);
            textBoxData.Name = "textBoxData";
            textBoxData.PlaceholderText = "Capture a name";
            textBoxData.Size = new Size(238, 27);
            textBoxData.TabIndex = 3;
            textBoxData.TextAlign = HorizontalAlignment.Center;
            // 
            // buttonExit
            // 
            buttonExit.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonExit.Location = new Point(673, 390);
            buttonExit.Name = "buttonExit";
            buttonExit.Size = new Size(115, 48);
            buttonExit.TabIndex = 4;
            buttonExit.Text = "Exit";
            buttonExit.UseVisualStyleBackColor = true;
            buttonExit.Click += buttonExit_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Lucida Calligraphy", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label1.ForeColor = SystemColors.ControlLightLight;
            label1.Location = new Point(12, 418);
            label1.Name = "label1";
            label1.Size = new Size(281, 23);
            label1.TabIndex = 5;
            label1.Text = "Cesar Andres Zuleta Malanco";
            // 
            // FormPrincipal
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = Properties.Resources.black_low_poly_geometric_background_vector__1_;
            ClientSize = new Size(800, 450);
            Controls.Add(label1);
            Controls.Add(buttonExit);
            Controls.Add(textBoxData);
            Controls.Add(buttonForm3);
            Controls.Add(buttonForm2);
            Controls.Add(labelTitle);
            Name = "FormPrincipal";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Principal Form";
            Load += FormPrincipal_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label labelTitle;
        private Button buttonForm2;
        private Button buttonForm3;
        private TextBox textBoxData;
        private Button buttonExit;
        private Label label1;
    }
}
