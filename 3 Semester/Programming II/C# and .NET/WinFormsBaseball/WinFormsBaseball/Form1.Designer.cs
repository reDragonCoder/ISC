namespace WinFormsBaseball
{
    partial class Player
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
            groupBoxPosition = new GroupBox();
            radioButtonBatter = new RadioButton();
            radioButtonPlayer = new RadioButton();
            radioButtonPitcher = new RadioButton();
            buttonCapture = new Button();
            buttonSHow = new Button();
            buttonExit = new Button();
            groupBoxData = new GroupBox();
            numHits = new NumericUpDown();
            txtMistakes = new TextBox();
            txtStrikes = new TextBox();
            txtName = new TextBox();
            txtUniformNum = new TextBox();
            labelMistakes = new Label();
            labelHits = new Label();
            labelStrikes = new Label();
            labelName = new Label();
            labelUniformNum = new Label();
            txtSample = new TextBox();
            groupBoxPosition.SuspendLayout();
            groupBoxData.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)numHits).BeginInit();
            SuspendLayout();
            // 
            // groupBoxPosition
            // 
            groupBoxPosition.Controls.Add(radioButtonBatter);
            groupBoxPosition.Controls.Add(radioButtonPlayer);
            groupBoxPosition.Controls.Add(radioButtonPitcher);
            groupBoxPosition.Font = new Font("Courier New", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            groupBoxPosition.Location = new Point(105, 35);
            groupBoxPosition.Name = "groupBoxPosition";
            groupBoxPosition.Size = new Size(226, 242);
            groupBoxPosition.TabIndex = 0;
            groupBoxPosition.TabStop = false;
            groupBoxPosition.Text = "Player Position";
            // 
            // radioButtonBatter
            // 
            radioButtonBatter.AutoSize = true;
            radioButtonBatter.ForeColor = SystemColors.ActiveCaptionText;
            radioButtonBatter.Location = new Point(28, 160);
            radioButtonBatter.Name = "radioButtonBatter";
            radioButtonBatter.Size = new Size(90, 24);
            radioButtonBatter.TabIndex = 2;
            radioButtonBatter.TabStop = true;
            radioButtonBatter.Text = "Batter";
            radioButtonBatter.UseVisualStyleBackColor = true;
            // 
            // radioButtonPlayer
            // 
            radioButtonPlayer.AutoSize = true;
            radioButtonPlayer.ForeColor = SystemColors.ActiveCaptionText;
            radioButtonPlayer.Location = new Point(28, 106);
            radioButtonPlayer.Name = "radioButtonPlayer";
            radioButtonPlayer.Size = new Size(180, 24);
            radioButtonPlayer.TabIndex = 1;
            radioButtonPlayer.TabStop = true;
            radioButtonPlayer.Text = "Position player";
            radioButtonPlayer.UseVisualStyleBackColor = true;
            // 
            // radioButtonPitcher
            // 
            radioButtonPitcher.AutoSize = true;
            radioButtonPitcher.ForeColor = SystemColors.ActiveCaptionText;
            radioButtonPitcher.Location = new Point(28, 54);
            radioButtonPitcher.Name = "radioButtonPitcher";
            radioButtonPitcher.Size = new Size(100, 24);
            radioButtonPitcher.TabIndex = 0;
            radioButtonPitcher.TabStop = true;
            radioButtonPitcher.Text = "Pitcher";
            radioButtonPitcher.UseVisualStyleBackColor = true;
            // 
            // buttonCapture
            // 
            buttonCapture.Font = new Font("Courier New", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonCapture.Location = new Point(105, 629);
            buttonCapture.Name = "buttonCapture";
            buttonCapture.Size = new Size(94, 29);
            buttonCapture.TabIndex = 1;
            buttonCapture.Text = "Capture";
            buttonCapture.UseVisualStyleBackColor = true;
            buttonCapture.Click += buttonCapture_Click;
            // 
            // buttonSHow
            // 
            buttonSHow.Font = new Font("Courier New", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonSHow.Location = new Point(555, 629);
            buttonSHow.Name = "buttonSHow";
            buttonSHow.Size = new Size(94, 29);
            buttonSHow.TabIndex = 2;
            buttonSHow.Text = "Show";
            buttonSHow.UseVisualStyleBackColor = true;
            buttonSHow.Click += buttonSHow_Click;
            // 
            // buttonExit
            // 
            buttonExit.Font = new Font("Courier New", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            buttonExit.Location = new Point(965, 629);
            buttonExit.Name = "buttonExit";
            buttonExit.Size = new Size(94, 29);
            buttonExit.TabIndex = 3;
            buttonExit.Text = "Exit";
            buttonExit.UseVisualStyleBackColor = true;
            buttonExit.Click += buttonExit_Click;
            // 
            // groupBoxData
            // 
            groupBoxData.Controls.Add(numHits);
            groupBoxData.Controls.Add(txtMistakes);
            groupBoxData.Controls.Add(txtStrikes);
            groupBoxData.Controls.Add(txtName);
            groupBoxData.Controls.Add(txtUniformNum);
            groupBoxData.Controls.Add(labelMistakes);
            groupBoxData.Controls.Add(labelHits);
            groupBoxData.Controls.Add(labelStrikes);
            groupBoxData.Controls.Add(labelName);
            groupBoxData.Controls.Add(labelUniformNum);
            groupBoxData.Font = new Font("Courier New", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            groupBoxData.Location = new Point(639, 35);
            groupBoxData.Name = "groupBoxData";
            groupBoxData.Size = new Size(420, 311);
            groupBoxData.TabIndex = 4;
            groupBoxData.TabStop = false;
            groupBoxData.Text = "Player Data";
            groupBoxData.Enter += groupBoxData_Enter;
            // 
            // numHits
            // 
            numHits.Location = new Point(218, 211);
            numHits.Name = "numHits";
            numHits.Size = new Size(125, 27);
            numHits.TabIndex = 9;
            // 
            // txtMistakes
            // 
            txtMistakes.Location = new Point(218, 260);
            txtMistakes.Name = "txtMistakes";
            txtMistakes.Size = new Size(125, 27);
            txtMistakes.TabIndex = 8;
            txtMistakes.TextChanged += textBox1_TextChanged;
            // 
            // txtStrikes
            // 
            txtStrikes.Location = new Point(218, 157);
            txtStrikes.Name = "txtStrikes";
            txtStrikes.Size = new Size(125, 27);
            txtStrikes.TabIndex = 7;
            // 
            // txtName
            // 
            txtName.Location = new Point(218, 103);
            txtName.Name = "txtName";
            txtName.Size = new Size(125, 27);
            txtName.TabIndex = 6;
            // 
            // txtUniformNum
            // 
            txtUniformNum.Location = new Point(218, 53);
            txtUniformNum.Name = "txtUniformNum";
            txtUniformNum.Size = new Size(125, 27);
            txtUniformNum.TabIndex = 5;
            // 
            // labelMistakes
            // 
            labelMistakes.AutoSize = true;
            labelMistakes.Location = new Point(44, 263);
            labelMistakes.Name = "labelMistakes";
            labelMistakes.Size = new Size(89, 20);
            labelMistakes.TabIndex = 4;
            labelMistakes.Text = "Mistakes";
            // 
            // labelHits
            // 
            labelHits.AutoSize = true;
            labelHits.Location = new Point(44, 213);
            labelHits.Name = "labelHits";
            labelHits.Size = new Size(49, 20);
            labelHits.TabIndex = 3;
            labelHits.Text = "Hits";
            // 
            // labelStrikes
            // 
            labelStrikes.AutoSize = true;
            labelStrikes.Location = new Point(44, 160);
            labelStrikes.Name = "labelStrikes";
            labelStrikes.Size = new Size(79, 20);
            labelStrikes.TabIndex = 2;
            labelStrikes.Text = "Strikes";
            // 
            // labelName
            // 
            labelName.AutoSize = true;
            labelName.Location = new Point(44, 106);
            labelName.Name = "labelName";
            labelName.Size = new Size(49, 20);
            labelName.TabIndex = 1;
            labelName.Text = "Name";
            // 
            // labelUniformNum
            // 
            labelUniformNum.AutoSize = true;
            labelUniformNum.Location = new Point(44, 54);
            labelUniformNum.Name = "labelUniformNum";
            labelUniformNum.Size = new Size(129, 20);
            labelUniformNum.TabIndex = 0;
            labelUniformNum.Text = "Uniform Num.";
            // 
            // txtSample
            // 
            txtSample.Font = new Font("Courier New", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtSample.Location = new Point(105, 374);
            txtSample.Multiline = true;
            txtSample.Name = "txtSample";
            txtSample.Size = new Size(954, 228);
            txtSample.TabIndex = 5;
            txtSample.TextChanged += txtSample_TextChanged;
            // 
            // Player
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(176, 190, 197);
            ClientSize = new Size(1191, 725);
            Controls.Add(txtSample);
            Controls.Add(groupBoxData);
            Controls.Add(buttonExit);
            Controls.Add(buttonSHow);
            Controls.Add(buttonCapture);
            Controls.Add(groupBoxPosition);
            ForeColor = SystemColors.ActiveCaptionText;
            Name = "Player";
            Text = "Baseball ";
            Load += Form1_Load;
            groupBoxPosition.ResumeLayout(false);
            groupBoxPosition.PerformLayout();
            groupBoxData.ResumeLayout(false);
            groupBoxData.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)numHits).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private GroupBox groupBoxPosition;
        private RadioButton radioButtonPitcher;
        private RadioButton radioButtonBatter;
        private RadioButton radioButtonPlayer;
        private Button buttonCapture;
        private Button buttonSHow;
        private Button buttonExit;
        private GroupBox groupBoxData;
        private Label labelHits;
        private Label labelStrikes;
        private Label labelName;
        private Label labelUniformNum;
        private TextBox txtMistakes;
        private TextBox txtStrikes;
        private TextBox txtName;
        private TextBox txtUniformNum;
        private Label labelMistakes;
        private NumericUpDown numHits;
        private TextBox txtSample;
    }
}
