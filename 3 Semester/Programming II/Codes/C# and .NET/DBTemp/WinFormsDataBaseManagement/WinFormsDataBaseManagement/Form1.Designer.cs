namespace WinFormsDataBaseManagement
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
            richTextBox1 = new RichTextBox();
            buttonRefresh = new Button();
            textBoxEliminateId = new TextBox();
            buttonEliminate = new Button();
            label1 = new Label();
            label2 = new Label();
            textBoxId = new TextBox();
            textBoxName = new TextBox();
            textBoxSurname = new TextBox();
            textBoxVisits = new TextBox();
            textBoxToModify = new TextBox();
            label3 = new Label();
            textBoxModifyVisits = new TextBox();
            textBoxModifySurname = new TextBox();
            textBoxModifyName = new TextBox();
            textBoxModifyId = new TextBox();
            buttonShowInfo = new Button();
            buttonModify = new Button();
            buttonAdd = new Button();
            label4 = new Label();
            SuspendLayout();
            // 
            // richTextBox1
            // 
            richTextBox1.Enabled = false;
            richTextBox1.Location = new Point(48, 48);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(754, 421);
            richTextBox1.TabIndex = 0;
            richTextBox1.Text = "";
            // 
            // buttonRefresh
            // 
            buttonRefresh.BackColor = Color.PowderBlue;
            buttonRefresh.Font = new Font("Lucida Bright", 16.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonRefresh.Location = new Point(119, 511);
            buttonRefresh.Name = "buttonRefresh";
            buttonRefresh.Size = new Size(222, 96);
            buttonRefresh.TabIndex = 1;
            buttonRefresh.Text = "Refresh";
            buttonRefresh.UseVisualStyleBackColor = false;
            buttonRefresh.Click += buttonRefresh_Click;
            // 
            // textBoxEliminateId
            // 
            textBoxEliminateId.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBoxEliminateId.Location = new Point(502, 511);
            textBoxEliminateId.Name = "textBoxEliminateId";
            textBoxEliminateId.PlaceholderText = "ID to eliminate";
            textBoxEliminateId.Size = new Size(176, 25);
            textBoxEliminateId.TabIndex = 2;
            textBoxEliminateId.TextAlign = HorizontalAlignment.Center;
            // 
            // buttonEliminate
            // 
            buttonEliminate.BackColor = Color.PowderBlue;
            buttonEliminate.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonEliminate.Location = new Point(514, 570);
            buttonEliminate.Name = "buttonEliminate";
            buttonEliminate.Size = new Size(153, 46);
            buttonEliminate.TabIndex = 3;
            buttonEliminate.Text = "Eliminate";
            buttonEliminate.UseVisualStyleBackColor = false;
            buttonEliminate.Click += buttonEliminate_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Lucida Calligraphy", 13.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label1.Location = new Point(841, 51);
            label1.Name = "label1";
            label1.Size = new Size(191, 29);
            label1.TabIndex = 4;
            label1.Text = "Modify Panel";
            label1.Click += label1_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Transparent;
            label2.Font = new Font("Lucida Calligraphy", 13.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label2.Location = new Point(1108, 51);
            label2.Name = "label2";
            label2.Size = new Size(151, 29);
            label2.TabIndex = 5;
            label2.Text = "Add Panel";
            // 
            // textBoxId
            // 
            textBoxId.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBoxId.Location = new Point(1092, 106);
            textBoxId.Name = "textBoxId";
            textBoxId.PlaceholderText = "ID";
            textBoxId.Size = new Size(167, 25);
            textBoxId.TabIndex = 6;
            textBoxId.TextAlign = HorizontalAlignment.Center;
            // 
            // textBoxName
            // 
            textBoxName.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBoxName.Location = new Point(1092, 164);
            textBoxName.Name = "textBoxName";
            textBoxName.PlaceholderText = "Name";
            textBoxName.Size = new Size(167, 25);
            textBoxName.TabIndex = 7;
            textBoxName.TextAlign = HorizontalAlignment.Center;
            textBoxName.TextChanged += textBoxName_TextChanged;
            // 
            // textBoxSurname
            // 
            textBoxSurname.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBoxSurname.Location = new Point(1092, 224);
            textBoxSurname.Name = "textBoxSurname";
            textBoxSurname.PlaceholderText = "Surname";
            textBoxSurname.Size = new Size(167, 25);
            textBoxSurname.TabIndex = 8;
            textBoxSurname.TextAlign = HorizontalAlignment.Center;
            // 
            // textBoxVisits
            // 
            textBoxVisits.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBoxVisits.Location = new Point(1092, 277);
            textBoxVisits.Name = "textBoxVisits";
            textBoxVisits.PlaceholderText = "Visits";
            textBoxVisits.Size = new Size(167, 25);
            textBoxVisits.TabIndex = 9;
            textBoxVisits.TextAlign = HorizontalAlignment.Center;
            // 
            // textBoxToModify
            // 
            textBoxToModify.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBoxToModify.Location = new Point(853, 106);
            textBoxToModify.Name = "textBoxToModify";
            textBoxToModify.PlaceholderText = "ID to modify";
            textBoxToModify.Size = new Size(167, 25);
            textBoxToModify.TabIndex = 10;
            textBoxToModify.TextAlign = HorizontalAlignment.Center;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Transparent;
            label3.Font = new Font("Lucida Calligraphy", 12F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label3.Location = new Point(867, 235);
            label3.Name = "label3";
            label3.Size = new Size(136, 27);
            label3.TabIndex = 11;
            label3.Text = "Client Info";
            // 
            // textBoxModifyVisits
            // 
            textBoxModifyVisits.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBoxModifyVisits.Location = new Point(857, 455);
            textBoxModifyVisits.Name = "textBoxModifyVisits";
            textBoxModifyVisits.Size = new Size(167, 25);
            textBoxModifyVisits.TabIndex = 15;
            textBoxModifyVisits.TextAlign = HorizontalAlignment.Center;
            // 
            // textBoxModifySurname
            // 
            textBoxModifySurname.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBoxModifySurname.Location = new Point(857, 402);
            textBoxModifySurname.Name = "textBoxModifySurname";
            textBoxModifySurname.Size = new Size(167, 25);
            textBoxModifySurname.TabIndex = 14;
            textBoxModifySurname.TextAlign = HorizontalAlignment.Center;
            // 
            // textBoxModifyName
            // 
            textBoxModifyName.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBoxModifyName.Location = new Point(857, 342);
            textBoxModifyName.Name = "textBoxModifyName";
            textBoxModifyName.Size = new Size(167, 25);
            textBoxModifyName.TabIndex = 13;
            textBoxModifyName.TextAlign = HorizontalAlignment.Center;
            // 
            // textBoxModifyId
            // 
            textBoxModifyId.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textBoxModifyId.Location = new Point(857, 284);
            textBoxModifyId.Name = "textBoxModifyId";
            textBoxModifyId.Size = new Size(167, 25);
            textBoxModifyId.TabIndex = 12;
            textBoxModifyId.TextAlign = HorizontalAlignment.Center;
            // 
            // buttonShowInfo
            // 
            buttonShowInfo.BackColor = Color.PowderBlue;
            buttonShowInfo.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonShowInfo.Location = new Point(867, 160);
            buttonShowInfo.Name = "buttonShowInfo";
            buttonShowInfo.Size = new Size(136, 37);
            buttonShowInfo.TabIndex = 16;
            buttonShowInfo.Text = "Show ID info";
            buttonShowInfo.UseVisualStyleBackColor = false;
            buttonShowInfo.Click += buttonShowInfo_Click;
            // 
            // buttonModify
            // 
            buttonModify.BackColor = Color.PowderBlue;
            buttonModify.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonModify.Location = new Point(867, 523);
            buttonModify.Name = "buttonModify";
            buttonModify.Size = new Size(136, 37);
            buttonModify.TabIndex = 17;
            buttonModify.Text = "Modify";
            buttonModify.UseVisualStyleBackColor = false;
            buttonModify.Click += buttonModify_Click;
            // 
            // buttonAdd
            // 
            buttonAdd.BackColor = Color.PowderBlue;
            buttonAdd.Font = new Font("Lucida Bright", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonAdd.Location = new Point(1108, 330);
            buttonAdd.Name = "buttonAdd";
            buttonAdd.Size = new Size(136, 37);
            buttonAdd.TabIndex = 18;
            buttonAdd.Text = "Add";
            buttonAdd.UseVisualStyleBackColor = false;
            buttonAdd.Click += buttonAdd_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.BackColor = Color.Transparent;
            label4.Font = new Font("Lucida Calligraphy", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label4.ForeColor = SystemColors.ButtonHighlight;
            label4.Location = new Point(1016, 629);
            label4.Name = "label4";
            label4.Size = new Size(281, 23);
            label4.TabIndex = 19;
            label4.Text = "Cesar Andres Zuleta Malanco";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = Properties.Resources.forest;
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(1309, 661);
            Controls.Add(label4);
            Controls.Add(buttonAdd);
            Controls.Add(buttonModify);
            Controls.Add(buttonShowInfo);
            Controls.Add(textBoxModifyVisits);
            Controls.Add(textBoxModifySurname);
            Controls.Add(textBoxModifyName);
            Controls.Add(textBoxModifyId);
            Controls.Add(label3);
            Controls.Add(textBoxToModify);
            Controls.Add(textBoxVisits);
            Controls.Add(textBoxSurname);
            Controls.Add(textBoxName);
            Controls.Add(textBoxId);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(buttonEliminate);
            Controls.Add(textBoxEliminateId);
            Controls.Add(buttonRefresh);
            Controls.Add(richTextBox1);
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "DataBase Management";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private RichTextBox richTextBox1;
        private Button buttonRefresh;
        private TextBox textBoxEliminateId;
        private Button buttonEliminate;
        private Label label1;
        private Label label2;
        private TextBox textBoxId;
        private TextBox textBoxName;
        private TextBox textBoxSurname;
        private TextBox textBoxVisits;
        private TextBox textBoxToModify;
        private Label label3;
        private TextBox textBoxModifyVisits;
        private TextBox textBoxModifySurname;
        private TextBox textBoxModifyName;
        private TextBox textBoxModifyId;
        private Button buttonShowInfo;
        private Button buttonModify;
        private Button buttonAdd;
        private Label label4;
    }
}
