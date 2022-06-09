using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using stoktakip.Models.Entity;

namespace stoktakip.Controllers
{
    public class musteriController : Controller
    {
        mvcstokEntities db = new mvcstokEntities();
        // GET: müsteri
        public ActionResult Index()
        {
            var degerler = db.musteriler.ToList();
            return View(degerler);
        }

        [HttpGet]

        public ActionResult YeniMusteri()
        {
            return View();
        }
        [HttpPost]

        public ActionResult YeniMusteri(musteriler p1)
        {
            if (!ModelState.IsValid)
            {
                return View("YeniMusteri");
            }
            db.musteriler.Add(p1);
            db.SaveChanges();
            return View();
        }


        public ActionResult Sil(int id)
        {
            var musteri = db.musteriler.Find(id);
            db.musteriler.Remove(musteri);
            db.SaveChanges();

            return RedirectToAction("Index");
        }
    
        public ActionResult MusteriGetir(int id)
        {
            var musteri = db.musteriler.Find(id);
            return View("MusteriGetir", musteri);
        }

        public ActionResult Güncelle(musteriler p1)
        {
            var musteri = db.musteriler.Find(p1.musteri_id);
            musteri.musteri_id = p1.musteri_id;
            musteri.musteri_ad = p1.musteri_ad;
            musteri.musteri_soyad = p1.musteri_soyad;
            db.SaveChanges();
            return RedirectToAction("Index");
        }

    }
}