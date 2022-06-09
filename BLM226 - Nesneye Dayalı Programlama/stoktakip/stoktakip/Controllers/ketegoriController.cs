using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using stoktakip.Models.Entity;

namespace stoktakip.Controllers
{
    public class ketegoriController : Controller
    {
        mvcstokEntities db = new mvcstokEntities();

        public ActionResult Index()
        {
            var degerler = db.kategoriler.ToList();
            return View(degerler);
        }
        [HttpGet]

        public ActionResult Yenikategori()
        {
            return View();
        }

        [HttpPost]

        public ActionResult Yenikategori(kategoriler p1)
        {
            if (!ModelState.IsValid)
            {
                return View("YeniKategori");
            }
            db.kategoriler.Add(p1);
            db.SaveChanges();
            return View();


        }

        public ActionResult Sil(int id)
        {
            var kategori =db.kategoriler.Find(id);
            db.kategoriler.Remove(kategori);
            db.SaveChanges();

            return RedirectToAction("Index");
        }


        public ActionResult KategoriGetir(int id)
        {
            var ktgr = db.kategoriler.Find(id);
            return View("KategoriGetir", ktgr);
        }

        public ActionResult Güncelle(kategoriler p1)
        {
            var ktgr = db.kategoriler.Find(p1.kategori_id);
            ktgr.kategori_id = p1.kategori_id;
            ktgr.kategori_ad = p1.kategori_ad;
            db.SaveChanges();
            return RedirectToAction("Index");
        }
    }
}