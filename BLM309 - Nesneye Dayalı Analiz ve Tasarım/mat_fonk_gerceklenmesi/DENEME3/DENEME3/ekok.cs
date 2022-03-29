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
    public partial class ekok : Form
    {
        public ekok()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1 ana = new Form1();
            ana.Show();
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int sayi1 = Convert.ToInt32(textBox1.Text);
            int sayi2 = Convert.ToInt32(textBox2.Text);

            int max = sayi1 * sayi2;
            int ekok = 0;
            for (int i = max; i > 0; i--)
            {
                if (i % sayi1 == 0 && i % sayi2 == 0)
                {
                    ekok = i;
                }
            }
            textBox3.Text = Convert.ToString(ekok);

           string dosya_yolu = @"C:\cikti.text";
            FileStream fs = new FileStream(dosya_yolu, FileMode.Append, FileAccess.Write, FileShare.Write);
            StreamWriter sw = new StreamWriter(fs);
            sw.Write("Ekok Bul: ");
            sw.Write(textBox1.Text);
            sw.Write(" ");
            sw.WriteLine(textBox2.Text);
            sw.WriteLine(textBox3.Text);
            sw.WriteLine();
            sw.Close();
           
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
