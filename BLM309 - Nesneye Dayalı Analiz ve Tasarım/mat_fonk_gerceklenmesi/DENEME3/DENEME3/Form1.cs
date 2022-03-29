using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace DENEME3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ebob hsp = new ebob();
            hsp.Show();
            this.Hide();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ekok hsp = new ekok();
            hsp.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            carpanlarin hsp = new carpanlarin();
            hsp.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            üs hsp = new üs();
            hsp.Show();
            this.Hide();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            aci hsp = new aci();
            hsp.Show();
            this.Hide();
        }

        public void Form1_Load(object sender, EventArgs e)
        {
            
        }
    }
}
