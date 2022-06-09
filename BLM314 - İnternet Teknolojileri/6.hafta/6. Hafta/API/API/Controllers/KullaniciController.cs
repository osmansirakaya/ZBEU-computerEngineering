using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Http;

namespace API.Controllers
{
    public class KullaniciController:ApiController
    {
        intTek2oKullaniciEntities _ent = new intTek2oKullaniciEntities();
        [HttpGet]
        public List<Kullanici> TumKullanicilariGetir()
        {
            return _ent.Kullanici.ToList();
        }
        [HttpGet]
        public List<Kullanici> KullaniciAra(string kelime)
        {
            return _ent.Kullanici.Where(p => p.AdSoyad.Contains(kelime) ||
            p.MailAdresi.Contains(kelime) ||
            p.Tel.Contains(kelime)).ToList();
        }
        [HttpGet]
        public Kullanici IDyeGoreKullaniciGetir(int id)
        {
            return _ent.Kullanici.Find(id);
        }
        [HttpGet]
        public bool KullaniciSil(int kid)
        {
            try
            {
                Kullanici silinecekkullanici = _ent.Kullanici.Find(kid);
                _ent.Kullanici.Remove(silinecekkullanici);
                _ent.SaveChanges();
                return true;
            }
            catch (Exception ex)
            {
                return false;
            }
        }
        [HttpPost]
        public bool KullaniciKaydet(Kullanici veri)
        {
            try
            {
                _ent.Kullanici.Add(veri);
                _ent.SaveChanges();
                return true;
            }
            catch (Exception ex)
            {
                return false;
            }
        }
        [HttpPost]
        public bool KullaniciGuncelle(Kullanici yeni)
        {
            try
            {
                Kullanici eski = _ent.Kullanici.Find(yeni.KullaniciID);
                eski.AdSoyad = yeni.AdSoyad;
                eski.Adres = yeni.Adres;
                eski.MailAdresi = yeni.MailAdresi;
                _ent.SaveChanges();
                return true;
            }
            catch (Exception ex)
            {
                return false;
            }
        }
    }
}