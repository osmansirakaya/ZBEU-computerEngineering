using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Http;

namespace api.Controllers
{
    public class kullaniciController:ApiController
    {
        // tablo üzerinden tümünü listeleme
        intTek2oKullaniciEntities _ent = new intTek2oKullaniciEntities(); //_ent-> nesnenin ismi
        [HttpGet]
        public List<kullanici> tumKullanicilariGetir(){
           return _ent.kullanici.ToList();
        }

        // arama kısmı
        [HttpGet]
        public List<kullanici> kullaniciAra(string kelime){
          return  _ent.kullanici.Where(p => p.adSoyad.Contains(kelime) ||
                                      p.mailAdresi.Contains(kelime) ||
                                      p.tel.Contains(kelime)).ToList(); //liste döndürür
        }

        // id'ye göre arama
        [HttpGet]
        public kullanici idyeGoreKullaniciGetir(int id){
            return _ent.kullanici.Find(id); // primaryKey de arama yapılacaksa bu fonk kullanılır. tek kullanıcı döndürür

        }

        //silme olayı
        [HttpGet]
        public bool kullaniciSil(int kid){

            try {
                kullanici silinecekKullanici = _ent.kullanici.Find(kid);
                _ent.kullanici.Remove(silinecekKullanici); // tek kullanıcı sil
                _ent.SaveChanges(); // değişiklik olunca kaydet
                return true;
            }
            catch(Exception ex){
                return false;
            }         
        }
        
        //kullanıcı kaydetme(veri ekleme)
        [HttpPost]
        public bool kullaniciKaydet(kullanici veri){
            try{
                _ent.kullanici.Add(veri);
                _ent.SaveChanges();
                return true;
               }
            catch(Exception ex){
                return false;
            }           
        }
        
        //guncelleme işlemi
        [HttpPost]
            public  bool  kullaniciGuncelle(kullanici yeni){
            try{
                kullanici eski = _ent.kullanici.Find(yeni.kullaniciID);
                eski.adSoyad = yeni.adSoyad;
                eski.adres = yeni.adres;
                eski.mailAdresi = yeni.mailAdresi;
                _ent.SaveChanges();
                return true;
            }
            catch{
                return false;
            }
        }



       /* [HttpGet]   // api metdolari nasıl kullanılır/nasıl istek yapılır
        public string adSoyadGetir(){
            return "osman sırakaya";
        }
        [HttpGet]
        public string telNoGetir(){
            return "123";
        }
        string[] dizi = { "ali", "ahmet", "yunus", "sultan", "ayşe" };
        [HttpGet]
        public string diziElemaniniGetir(int siraNo){
            return dizi[siraNo];
        } */
    }
}