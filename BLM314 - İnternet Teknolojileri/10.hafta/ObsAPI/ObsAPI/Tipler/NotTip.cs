using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ObsAPI.Tipler
{
    public class NotTip
    {
        public int NotId { get; set; }
        public int OgrenciId { get; set; }
        public int DersId { get; set; }
        public Nullable<int> Vize { get; set; }
        public Nullable<int> Final { get; set; }

        public virtual Ders Ders { get; set; }
        public virtual Ogrenci Ogrenci { get; set; }
        public string OgrenciAdSoyad { get; set; }
        public string OgrenciNo { get; set; }
        public string DersAdi { get; set; }
    }
}