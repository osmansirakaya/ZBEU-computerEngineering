using ObsAPI.Tipler;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Http;

namespace ObsAPI.Controllers
{   // ana tabloya tüm notları getirme kısmı
    public class NotController : ApiController
    {
        intTekObsEntities _ent = new intTekObsEntities(); 
        [HttpGet]
        public List<NotTip> TumNotlariGetir()
        {
           return _ent.Not.Select(p => new NotTip() { // tür dönüşümü yapıyoruz. Yeni bir NotTip olusturcak
            DersId=p.DersId,
            NotId=p.NotId,
            OgrenciId=p.OgrenciId,
            Vize=p.Vize,
            Final=p.Final,
            DersAdi=p.Ders.DersAdi,
            OgrenciAdSoyad=p.Ogrenci.AdSoyad,
            OgrenciNo=p.Ogrenci.OgrenciNo
            }).ToList();
        }

        public void DersveOgrenciyeGoreNotGetir(int dersiid, int ogrenciid)
        {
            _ent.Not.Where(p => p.DersId == dersiid && p.OgrenciId == ogrenciid).//not tablosunda, dersi sorgulanan ders, ogrencisi sorgulanan ogrenci olan 
                Select(p => new NotTip()  //kaydı NotTip'e dönüştür 
                {  
                    DersId = p.DersId,
                    NotId = p.NotId,
                    OgrenciId = p.OgrenciId,
                    Vize = p.Vize,
                    Final = p.Final,
                    DersAdi = p.Ders.DersAdi,
                    OgrenciAdSoyad = p.Ogrenci.AdSoyad,
                    OgrenciNo = p.Ogrenci.OgrenciNo
                }).FirstOrDefault(); // ve ilkini getir. 

           /* eğer bu tablodan NULL gelirse, o ders o ögrenciye daha onceden verilmemıs, kaydı yok. 
              NULL dısında dolu bir veri gelirse, daha once o ders, o ogrencıye atılmıs. Veri ekleme değil, veri guncelleme kısmı
              gelmesı gerektiğini algılıcaz  */     
        }
        [HttpPost]
        public  bool NotKaydet(NotTip veri)
        {
            try
            {
                Not n = new Not();
                n.DersId = veri.DersId;
                n.OgrenciId = veri.OgrenciId;
                n.Vize = veri.Vize;
                n.Final = veri.Final;
                _ent.Not.Add(n);
                _ent.SaveChanges();
                return true;
            }
            catch(Exception)
            {
                return false;
            }
        }

        [HttpPost]
        public bool NotGuncelle(NotTip veri)
        {
            try
            {
                Not n = _ent.Not.Find(veri.NotId); // veri tabanından guncelleyecek oldugu notu bulacak
                //n.DersId = veri.DersId;
                //n.OgrenciId = veri.OgrenciId;
                n.Vize = veri.Vize;
                n.Final = veri.Final;
                _ent.SaveChanges();
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }
    }
}