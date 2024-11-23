namespace WinFormsMultipleForms
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            labelSecondaryTitle = new Label();
            textBoxName = new TextBox();
            buttonGoBack = new Button();
            textBoxNumber = new TextBox();
            buttonForm3 = new Button();
            textBoxFavAnimalCap = new TextBox();
            SuspendLayout();
            // 
            // labelSecondaryTitle
            // 
            labelSecondaryTitle.AutoSize = true;
            labelSecondaryTitle.BackColor = Color.Transparent;
            labelSecondaryTitle.Font = new Font("Lucida Calligraphy", 18F, FontStyle.Bold, GraphicsUnit.Point, 0);
            labelSecondaryTitle.ForeColor = SystemColors.ButtonFace;
            labelSecondaryTitle.Location = new Point(268, 67);
            labelSecondaryTitle.Name = "labelSecondaryTitle";
            labelSecondaryTitle.Size = new Size(279, 39);
            labelSecondaryTitle.TabIndex = 0;
            labelSecondaryTitle.Text = "Secondary Title";
            // 
            // textBoxName
            // 
            textBoxName.Enabled = false;
            textBoxName.Location = new Point(268, 142);
            textBoxName.Name = "textBoxName";
            textBoxName.Size = new Size(279, 27);
            textBoxName.TabIndex = 1;
            // 
            // buttonGoBack
            // 
            buttonGoBack.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonGoBack.Location = new Point(166, 334);
            buttonGoBack.Name = "buttonGoBack";
            buttonGoBack.Size = new Size(155, 43);
            buttonGoBack.TabIndex = 2;
            buttonGoBack.Text = "Go Back";
            buttonGoBack.UseVisualStyleBackColor = true;
            buttonGoBack.Click += buttonGoBack_Click;
            // 
            // textBoxNumber
            // 
            textBoxNumber.Enabled = false;
            textBoxNumber.Location = new Point(268, 197);
            textBoxNumber.Name = "textBoxNumber";
            textBoxNumber.Size = new Size(279, 27);
            textBoxNumber.TabIndex = 3;
            // 
            // buttonForm3
            // 
            buttonForm3.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonForm3.Location = new Point(473, 334);
            buttonForm3.Name = "buttonForm3";
            buttonForm3.Size = new Size(155, 43);
            buttonForm3.TabIndex = 4;
            buttonForm3.Text = "Form 3";
            buttonForm3.UseVisualStyleBackColor = true;
            buttonForm3.Click += buttonForm3_Click;
            // 
            // textBoxFavAnimalCap
            // 
            textBoxFavAnimalCap.Location = new Point(268, 255);
            textBoxFavAnimalCap.Name = "textBoxFavAnimalCap";
            textBoxFavAnimalCap.PlaceholderText = "Capture your fav animal";
            textBoxFavAnimalCap.Size = new Size(279, 27);
            textBoxFavAnimalCap.TabIndex = 5;
            textBoxFavAnimalCap.TextAlign = HorizontalAlignment.Center;
            // 
            // Form2
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.Black;
            ClientSize = new Size(800, 450);
            Controls.Add(textBoxFavAnimalCap);
            Controls.Add(buttonForm3);
            Controls.Add(textBoxNumber);
            Controls.Add(buttonGoBack);
            Controls.Add(textBoxName);
            Controls.Add(labelSecondaryTitle);
            Name = "Form2";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Form2";
            Load += Form2_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label labelSecondaryTitle;
        private TextBox textBoxName;
        private Button buttonGoBack;
        private TextBox textBoxNumber;
        private Button buttonForm3;
        private TextBox textBoxFavAnimalCap;
    }
}