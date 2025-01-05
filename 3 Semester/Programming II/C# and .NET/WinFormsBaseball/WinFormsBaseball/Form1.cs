using System.Collections.Generic;
using System.ComponentModel;

namespace WinFormsBaseball
{
    public partial class Player : Form
    {
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string UniformNum { get; set; }
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public new string Name { get; set; }
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string Strikes { get; set; }
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string Mistakes { get; set; }
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string Position { get; set; }

        private int Hits { get; set; }

        //create the list that is going to save the information
        List<Player> players = new List<Player>();
        private string name;

        //Player list type named players
        //We instance the list

        public Player()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        //doing a click we are going to execute this
        private void buttonCapture_Click(object sender, EventArgs e)
        {
            //We want the data to be saved in the list when we click
            //and send us a message that they were saved
            //we will start by creating the object
            Player playerInfo = new Player(); //object of type Player named playerInfo

            //player info in its field x will be equal to txtName (form elements) in its text field
            //storing the form values ​​in the corresponding variables
            playerInfo.UniformNum = txtUniformNum.Text;
            playerInfo.Name = txtName.Text;
            playerInfo.Strikes = txtStrikes.Text;
            playerInfo.Hits = (int)numHits.Value;
            playerInfo.Mistakes = txtMistakes.Text;

            //capturing the position
            if (radioButtonPitcher.Checked)
            {
                playerInfo.Position = "Pitcher";
            }
            else if (radioButtonPlayer.Checked)
            {
                playerInfo.Position = "Position Player";
            }
            else if (radioButtonBatter.Checked)
            {
                playerInfo.Position = "Batter";
            }
            else
            {
                MessageBox.Show("Please select a position");
                return;
            }

            //the object is up to here but the information must be saved
            players.Add(playerInfo);

            //show a message that confirms the data
            MessageBox.Show("The data has been saved");
        }

        private void buttonSHow_Click(object sender, EventArgs e)
        {
            //now, when we click we want the information that we saved previously to be displayed
            //we want to show everything on the same screen using the TextBox
            //creating a string variable to display the data
            string playersInfo = "";
            //we have to loop through the list using a loop
            foreach (Player play in players)
            {
                //we add the information of each player to the accumulator string
                playersInfo += $"Name: {play.Name}\r\nUniform: {play.UniformNum}\r\n" +
                               $"Position: {play.Position}\r\nHits: {play.Hits}\r\n" +
                               $"Strikes: {play.Strikes}\r\nMistakes: {play.Mistakes}\r\n\n";
                //we send the infoPlayers variable to the textbox
                txtSample.Text = playersInfo;
            }
        }

        private void buttonExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void groupBoxData_Enter(object sender, EventArgs e)
        {

        }

        private void txtSample_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
