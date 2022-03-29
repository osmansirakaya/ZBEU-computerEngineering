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
    public partial class carpanlarin : Form
    {
        public carpanlarin()
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
            int sayi1 = Convert.ToInt32(textBox2.Text);
            int bolen = 0;

            for (int i = 1; i < sayi1; i++)
            {
                if (sayi1 % i == 0)
                {
                    bolen += i;
                }
            }
            textBox3.Text = Convert.ToString(bolen);

            string dosya_yolu = @"C:\cikti.text";
            FileStream fs = new FileStream(dosya_yolu, FileMode.Append, FileAccess.Write, FileShare.Write);
            StreamWriter sw = new StreamWriter(fs);
            sw.Write("çarpanlarin toplamani bul: ");
            sw.WriteLine(textBox2.Text);
            sw.WriteLine(textBox3.Text);
            sw.WriteLine();
            sw.Close();


        }
    }
}
