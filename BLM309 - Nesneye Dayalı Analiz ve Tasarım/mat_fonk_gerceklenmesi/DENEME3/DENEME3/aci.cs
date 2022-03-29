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
    public partial class aci : Form
    {
        public aci()
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

            int dakika = Convert.ToInt32(textBox1.Text);
            int saat = Convert.ToInt32(textBox2.Text);
            double daci, saci, s;

            saat %= 12;
            daci = dakika * 6;
            saci = saat * 30 + (double)dakika / 2;
            s = saci - daci;
            if (s < 0)
                s *= -1;
            textBox3.Text = Convert.ToString(s);

            string dosya_yolu = @"C:\cikti.text";
            FileStream fs = new FileStream(dosya_yolu, FileMode.Append, FileAccess.Write, FileShare.Write);
            StreamWriter sw = new StreamWriter(fs);
            sw.Write("Akreple yelkovan arasindaki dar aciyi bul: ");
            sw.Write(textBox2.Text);
            sw.Write(" ");
            sw.WriteLine(textBox1.Text);
            sw.WriteLine(textBox3.Text);
            sw.WriteLine();
            sw.Close();
        }
    }
}
