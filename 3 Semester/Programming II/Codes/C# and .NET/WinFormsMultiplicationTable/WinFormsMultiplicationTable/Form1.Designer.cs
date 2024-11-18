namespace WinFormsMultiplicationTable
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
            panel_main = new Panel();
            richTextBox_results = new RichTextBox();
            button_see = new Button();
            textBox_number = new TextBox();
            label_number = new Label();
            label_title = new Label();
            panel_main.SuspendLayout();
            SuspendLayout();
            // 
            // panel_main
            // 
            panel_main.BackColor = Color.Black;
            panel_main.Controls.Add(richTextBox_results);
            panel_main.Controls.Add(button_see);
            panel_main.Controls.Add(textBox_number);
            panel_main.Controls.Add(label_number);
            panel_main.Controls.Add(label_title);
            panel_main.Location = new Point(12, 12);
            panel_main.Name = "panel_main";
            panel_main.Size = new Size(776, 426);
            panel_main.TabIndex = 0;
            // 
            // richTextBox_results
            // 
            richTextBox_results.Font = new Font("Consolas", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            richTextBox_results.Location = new Point(487, 108);
            richTextBox_results.Name = "richTextBox_results";
            richTextBox_results.Size = new Size(193, 258);
            richTextBox_results.TabIndex = 4;
            richTextBox_results.Text = "";
            // 
            // button_see
            // 
            button_see.AutoSize = true;
            button_see.BackColor = Color.LimeGreen;
            button_see.Font = new Font("Consolas", 9F, FontStyle.Bold, GraphicsUnit.Point, 0);
            button_see.ForeColor = SystemColors.ControlText;
            button_see.Location = new Point(129, 270);
            button_see.Name = "button_see";
            button_see.Size = new Size(103, 29);
            button_see.TabIndex = 3;
            button_see.Text = "See Table";
            button_see.TextImageRelation = TextImageRelation.ImageAboveText;
            button_see.UseVisualStyleBackColor = false;
            button_see.Click += button_see_Click;
            // 
            // textBox_number
            // 
            textBox_number.Font = new Font("Consolas", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBox_number.Location = new Point(112, 191);
            textBox_number.Name = "textBox_number";
            textBox_number.Size = new Size(146, 27);
            textBox_number.TabIndex = 2;
            // 
            // label_number
            // 
            label_number.AutoSize = true;
            label_number.Font = new Font("Consolas", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label_number.ForeColor = Color.Lime;
            label_number.Location = new Point(58, 130);
            label_number.Name = "label_number";
            label_number.Size = new Size(274, 23);
            label_number.TabIndex = 1;
            label_number.Text = "Which table do you want?";
            label_number.Click += label1_Click;
            // 
            // label_title
            // 
            label_title.AutoSize = true;
            label_title.Font = new Font("Consolas", 18F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label_title.ForeColor = Color.Lime;
            label_title.Location = new Point(210, 37);
            label_title.Name = "label_title";
            label_title.Size = new Size(335, 36);
            label_title.TabIndex = 0;
            label_title.Text = "MULTIPLICATION TABLE";
            label_title.Click += label_title_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(panel_main);
            Name = "Form1";
            Text = "Form1";
            panel_main.ResumeLayout(false);
            panel_main.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private Panel panel_main;
        private Label label_number;
        private Label label_title;
        private RichTextBox richTextBox_results;
        private Button button_see;
        private TextBox textBox_number;
    }
}
