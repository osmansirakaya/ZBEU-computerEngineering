using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace proje
{
    class Program
    {
        static void Main(string[] args)
        {
            string str;
            Console.Write("Dosya adi girin: ");
            str = Console.ReadLine();

            FileStream fin = new FileStream(str, FileMode.Open);
            StreamReader fstr_in = new StreamReader(fin);
            int i, a = 0, b = 0;
            string temp;
            string[] tokens;
            temp = fstr_in.ReadLine();
            i = int.Parse(temp);
            Stack<int> persons = new Stack<int>();
            List<int> know = new List<int>();

            while ((temp = fstr_in.ReadLine()) != null) {
                tokens = temp.Split();
                a = int.Parse(tokens[0]);
                b = int.Parse(tokens[1]);
                know.Add(a);
                know.Add(b);
            }
            for (int x = 0; x < i; x++) {
                persons.Push(x);
            }
            while (persons.Count > 1) {
                int x = persons.Pop();
                int y = persons.Pop();
                 if (knows(x, y)){
                    persons.Push(y);
                }
                 else {
                    persons.Push(x);
                }
            }
            if (knows2(persons.Peek())) { // yıgındaki elemanı getirir ama yıgından cıkarmaz
                persons.Pop();
            }
            if (persons.Count == 0){
                Console.WriteLine("ünlü kisi yoktur.");
            }
            else{
                Console.WriteLine("ünlü {0} numarali kisi.", persons.Peek());
            }
            bool knows(int x, int y) {
                for (int j = 0; j < know.Count; j += 2){
                    if (x == know[j] && y == know[j + 1]){
                        return true;
                    }
                }
                return false;
            }
            bool knows2(int x) {
                for (int j = 0; j < know.Count; j += 2){
                    if (x == know[j]){
                        return true;
                    }
                }
                return false;
            }
            Console.ReadLine();

        }
    }
}
