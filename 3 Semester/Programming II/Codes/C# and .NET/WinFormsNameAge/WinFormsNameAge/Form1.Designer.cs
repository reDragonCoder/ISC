namespace WinFormsNameAge
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
            labelName = new Label();
            labelAge = new Label();
            txtName = new TextBox();
            txtAge = new TextBox();
            btnSave = new Button();
            btnClear = new Button();
            gridA = new DataGridView();
            ((System.ComponentModel.ISupportInitialize)gridA).BeginInit();
            SuspendLayout();
            // 
            // labelName
            // 
            labelName.AutoSize = true;
            labelName.BackColor = Color.Transparent;
            labelName.Font = new Font("Consolas", 13.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            labelName.ForeColor = Color.Lime;
            labelName.Location = new Point(50, 52);
            labelName.Name = "labelName";
            labelName.Size = new Size(90, 27);
            labelName.TabIndex = 0;
            labelName.Text = "Name: ";
            // 
            // labelAge
            // 
            labelAge.AutoSize = true;
            labelAge.Font = new Font("Consolas", 13.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            labelAge.ForeColor = Color.Lime;
            labelAge.Location = new Point(50, 101);
            labelAge.Name = "labelAge";
            labelAge.Size = new Size(77, 27);
            labelAge.TabIndex = 1;
            labelAge.Text = "Age: ";
            // 
            // txtName
            // 
            txtName.Font = new Font("Consolas", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtName.Location = new Point(168, 54);
            txtName.Name = "txtName";
            txtName.Size = new Size(391, 27);
            txtName.TabIndex = 2;
            // 
            // txtAge
            // 
            txtAge.Font = new Font("Consolas", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtAge.Location = new Point(168, 103);
            txtAge.Name = "txtAge";
            txtAge.Size = new Size(125, 27);
            txtAge.TabIndex = 3;
            // 
            // btnSave
            // 
            btnSave.BackColor = Color.LimeGreen;
            btnSave.Font = new Font("Consolas", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnSave.ForeColor = Color.Black;
            btnSave.Location = new Point(653, 49);
            btnSave.Name = "btnSave";
            btnSave.Size = new Size(121, 81);
            btnSave.TabIndex = 4;
            btnSave.Text = "Save";
            btnSave.UseVisualStyleBackColor = false;
            btnSave.Click += btnSave_Click;
            // 
            // btnClear
            // 
            btnClear.BackColor = Color.LimeGreen;
            btnClear.Font = new Font("Consolas", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnClear.Location = new Point(829, 49);
            btnClear.Name = "btnClear";
            btnClear.Size = new Size(124, 81);
            btnClear.TabIndex = 5;
            btnClear.Text = "Clear";
            btnClear.UseVisualStyleBackColor = false;
            btnClear.Click += btnClear_Click;
            // 
            // gridA
            // 
            gridA.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
            gridA.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
            gridA.BackgroundColor = Color.Black;
            gridA.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            gridA.GridColor = Color.Black;
            gridA.Location = new Point(50, 157);
            gridA.Name = "gridA";
            gridA.RowHeadersWidth = 51;
            gridA.Size = new Size(903, 320);
            gridA.TabIndex = 6;
            gridA.CellContentClick += gridA_CellContentClick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ActiveCaptionText;
            ClientSize = new Size(1009, 541);
            Controls.Add(gridA);
            Controls.Add(btnClear);
            Controls.Add(btnSave);
            Controls.Add(txtAge);
            Controls.Add(txtName);
            Controls.Add(labelAge);
            Controls.Add(labelName);
            Name = "Form1";
            Text = "Data Grid";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)gridA).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label labelName;
        private Label labelAge;
        private TextBox txtName;
        private TextBox txtAge;
        private Button btnSave;
        private Button btnClear;
        private DataGridView gridA;
    }
}
