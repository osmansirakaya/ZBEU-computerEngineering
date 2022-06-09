using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using stoktakip.Models.Entity;

namespace stoktakip.Controllers
{
    public class urunController : Controller
    {
        mvcstokEntities ra = new mvcstokEntities();

        // GET: urun
        public ActionResult Index()
        {
            var degerler = ra.urunler.ToList();
           
            return View(degerler);
        }
        [HttpGet]

        public ActionResult Urunekle()
        {
            return View();
        }
        [HttpPost]

        public ActionResult UrunEkle(urunler s1)
        {
            ra.urunler.Add(s1);
            ra.SaveChanges();
            return View();
        }

        public ActionResult Sil(int id)
        {
            var urun = ra.urunler.Find(id);
            ra.urunler.Remove(urun);
            ra.SaveChanges();

            return RedirectToAction("Index");
        }

        public ActionResult UrunGetir(int id)
        {
            var urun = ra.urunler.Find(id);
            return View("UrunGetir", urun);
        }

        public ActionResult Güncelle(urunler p1)
        {
            var urun = ra.urunler.Find(p1.urun_id);
            urun.urun_id = p1.urun_id;
            urun.urun_ad = p1.urun_ad;
            urun.urun_kategori = p1.urun_kategori;
            urun.fiyat = p1.fiyat;
            urun.marka = p1.marka;
            urun.stok = p1.stok;
            return RedirectToAction("Index");

        }
    }
}