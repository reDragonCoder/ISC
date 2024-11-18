namespace WinFormsAppSumTwoNumbers
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
            labelTitle = new Label();
            labelFirstNum = new Label();
            labelSecondNum = new Label();
            labelResult = new Label();
            txtFirstNum = new TextBox();
            txtSecondNum = new TextBox();
            txtResult = new TextBox();
            btnClear = new Button();
            btnCalculate = new Button();
            btnExit = new Button();
            SuspendLayout();
            // 
            // labelTitle
            // 
            labelTitle.AutoEllipsis = true;
            labelTitle.AutoSize = true;
            labelTitle.BorderStyle = BorderStyle.Fixed3D;
            labelTitle.Font = new Font("Lucida Console", 10.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            labelTitle.ForeColor = Color.Lime;
            labelTitle.Location = new Point(298, 33);
            labelTitle.Name = "labelTitle";
            labelTitle.Size = new Size(190, 20);
            labelTitle.TabIndex = 0;
            labelTitle.Text = "TWO NUMBERS SUM";
            // 
            // labelFirstNum
            // 
            labelFirstNum.AutoSize = true;
            labelFirstNum.Font = new Font("Consolas", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            labelFirstNum.ForeColor = Color.Lime;
            labelFirstNum.Location = new Point(255, 110);
            labelFirstNum.Name = "labelFirstNum";
            labelFirstNum.Size = new Size(117, 20);
            labelFirstNum.TabIndex = 1;
            labelFirstNum.Text = "First number";
            // 
            // labelSecondNum
            // 
            labelSecondNum.AutoSize = true;
            labelSecondNum.Font = new Font("Consolas", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            labelSecondNum.ForeColor = Color.Lime;
            labelSecondNum.Location = new Point(255, 173);
            labelSecondNum.Name = "labelSecondNum";
            labelSecondNum.Size = new Size(126, 20);
            labelSecondNum.TabIndex = 2;
            labelSecondNum.Text = "Second number";
            // 
            // labelResult
            // 
            labelResult.AutoSize = true;
            labelResult.Font = new Font("Consolas", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            labelResult.ForeColor = Color.Lime;
            labelResult.Location = new Point(255, 238);
            labelResult.Name = "labelResult";
            labelResult.Size = new Size(63, 20);
            labelResult.TabIndex = 3;
            labelResult.Text = "Result";
            // 
            // txtFirstNum
            // 
            txtFirstNum.Font = new Font("Consolas", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtFirstNum.Location = new Point(433, 103);
            txtFirstNum.Name = "txtFirstNum";
            txtFirstNum.Size = new Size(125, 27);
            txtFirstNum.TabIndex = 4;
            // 
            // txtSecondNum
            // 
            txtSecondNum.Font = new Font("Consolas", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtSecondNum.Location = new Point(433, 166);
            txtSecondNum.Name = "txtSecondNum";
            txtSecondNum.Size = new Size(125, 27);
            txtSecondNum.TabIndex = 5;
            // 
            // txtResult
            // 
            txtResult.Font = new Font("Consolas", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtResult.Location = new Point(433, 231);
            txtResult.Name = "txtResult";
            txtResult.Size = new Size(125, 27);
            txtResult.TabIndex = 6;
            // 
            // btnClear
            // 
            btnClear.BackColor = Color.LimeGreen;
            btnClear.Font = new Font("Consolas", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnClear.ForeColor = Color.Black;
            btnClear.Location = new Point(111, 324);
            btnClear.Name = "btnClear";
            btnClear.Size = new Size(92, 39);
            btnClear.TabIndex = 7;
            btnClear.Text = "Clear";
            btnClear.UseVisualStyleBackColor = false;
            btnClear.Click += btnClear_Click;
            // 
            // btnCalculate
            // 
            btnCalculate.BackColor = Color.LimeGreen;
            btnCalculate.Font = new Font("Consolas", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnCalculate.Location = new Point(389, 324);
            btnCalculate.Name = "btnCalculate";
            btnCalculate.Size = new Size(98, 39);
            btnCalculate.TabIndex = 8;
            btnCalculate.Text = "Calculate";
            btnCalculate.UseVisualStyleBackColor = false;
            btnCalculate.Click += btnCalculate_Click;
            // 
            // btnExit
            // 
            btnExit.BackColor = Color.LimeGreen;
            btnExit.Font = new Font("Consolas", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnExit.Location = new Point(611, 324);
            btnExit.Name = "btnExit";
            btnExit.Size = new Size(106, 39);
            btnExit.TabIndex = 9;
            btnExit.Text = "Exit";
            btnExit.UseVisualStyleBackColor = false;
            btnExit.Click += btnExit_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ActiveCaptionText;
            ClientSize = new Size(800, 450);
            Controls.Add(btnExit);
            Controls.Add(btnCalculate);
            Controls.Add(btnClear);
            Controls.Add(txtResult);
            Controls.Add(txtSecondNum);
            Controls.Add(txtFirstNum);
            Controls.Add(labelResult);
            Controls.Add(labelSecondNum);
            Controls.Add(labelFirstNum);
            Controls.Add(labelTitle);
            Name = "Form1";
            Text = "Sumatory";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label labelTitle;
        private Label labelFirstNum;
        private Label labelSecondNum;
        private Label labelResult;
        private TextBox txtFirstNum;
        private TextBox txtSecondNum;
        private TextBox txtResult;
        private Button btnClear;
        private Button btnCalculate;
        private Button btnExit;
    }
}
