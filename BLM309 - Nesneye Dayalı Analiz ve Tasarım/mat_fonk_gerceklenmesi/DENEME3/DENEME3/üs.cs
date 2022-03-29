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
    public partial class üs : Form
    {
        public üs()
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
            double n = Convert.ToDouble(textBox1.Text);
            int k = Convert.ToInt32(textBox2.Text);
            int negatif = 0, i = 0;
            double sonuc = 1;

            if ((n == 0) && (k == 0))
                sonuc = 0;
            else
            {
                if (k == 0)
                    sonuc = 1;
                else
                {
                    if (k < 0)
                    {
                        k *= -1;
                        negatif = 1;
                    }
                    for (i = 0; i < k; i++)
                    {
                        sonuc = sonuc * n;
                    }
                    if (negatif == 1)
                        sonuc = (1 / sonuc);

                    textBox3.Text = Convert.ToString(sonuc);

                    string dosya_yolu = @"C:\cikti.text";
                    FileStream fs = new FileStream(dosya_yolu, FileMode.Append, FileAccess.Write, FileShare.Write);
                    StreamWriter sw = new StreamWriter(fs);
                    sw.Write("n’nin k. kuvvetini bul: ");
                    sw.Write(textBox1.Text);
                    sw.Write(" ");
                    sw.WriteLine(textBox2.Text);
                    sw.WriteLine(textBox3.Text);
                    sw.WriteLine();
                    sw.Close();

                }
            }
        }
    }
}

