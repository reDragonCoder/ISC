namespace WinFormsMultipleForms
{
    partial class Form3
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
            labelTerciaryTitle = new Label();
            textBoxFavAnimal = new TextBox();
            buttonGoBack2 = new Button();
            textBoxColor = new TextBox();
            SuspendLayout();
            // 
            // labelTerciaryTitle
            // 
            labelTerciaryTitle.AutoSize = true;
            labelTerciaryTitle.BackColor = Color.Transparent;
            labelTerciaryTitle.Font = new Font("Lucida Calligraphy", 18F, FontStyle.Bold, GraphicsUnit.Point, 0);
            labelTerciaryTitle.Location = new Point(323, 67);
            labelTerciaryTitle.Name = "labelTerciaryTitle";
            labelTerciaryTitle.Size = new Size(199, 39);
            labelTerciaryTitle.TabIndex = 0;
            labelTerciaryTitle.Text = "Third Title";
            // 
            // textBoxFavAnimal
            // 
            textBoxFavAnimal.Enabled = false;
            textBoxFavAnimal.Location = new Point(308, 150);
            textBoxFavAnimal.Name = "textBoxFavAnimal";
            textBoxFavAnimal.Size = new Size(236, 27);
            textBoxFavAnimal.TabIndex = 1;
            // 
            // buttonGoBack2
            // 
            buttonGoBack2.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonGoBack2.Location = new Point(356, 292);
            buttonGoBack2.Name = "buttonGoBack2";
            buttonGoBack2.Size = new Size(139, 53);
            buttonGoBack2.TabIndex = 2;
            buttonGoBack2.Text = "Go Back";
            buttonGoBack2.UseVisualStyleBackColor = true;
            buttonGoBack2.Click += buttonGoBack2_Click;
            // 
            // textBoxColor
            // 
            textBoxColor.Enabled = false;
            textBoxColor.Location = new Point(308, 213);
            textBoxColor.Name = "textBoxColor";
            textBoxColor.Size = new Size(236, 27);
            textBoxColor.TabIndex = 3;
            // 
            // Form3
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = Properties.Resources._360_F_695752295_JnkX56dpsh7RtUf5Lismfkd4p9ACFjJY__1___1_1;
            ClientSize = new Size(800, 450);
            Controls.Add(textBoxColor);
            Controls.Add(buttonGoBack2);
            Controls.Add(textBoxFavAnimal);
            Controls.Add(labelTerciaryTitle);
            Name = "Form3";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Form3";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label labelTerciaryTitle;
        private TextBox textBoxFavAnimal;
        private Button buttonGoBack2;
        private TextBox textBoxColor;
    }
}