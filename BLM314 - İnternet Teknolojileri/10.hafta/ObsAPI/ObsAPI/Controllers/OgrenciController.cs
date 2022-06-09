using ObsAPI.Tipler;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Http;

namespace ObsAPI.Controllers
{
    public class OgrenciController: ApiController
    {
        intTekObsEntities _ent = new intTekObsEntities();
        [HttpGet]
        public List<OgrenciTip> TumOgrencileriGetir()
        {
            return _ent.Ogrenci.Select(p => new OgrenciTip() { 
            OgrenciId=p.OgrenciId,
            OgrenciNo=p.OgrenciNo,
            AdSoyad=p.AdSoyad
            }).ToList();
        }

        [HttpGet]
        public List<OgrenciTip> DersiAlanOgrencileriGetir(int DersId)
        {
            return _ent.Ogrenci.Where(p=>p.Not.Any(k=>k.DersId==DersId)).Select(p => new OgrenciTip()
            {
                OgrenciId = p.OgrenciId,
                OgrenciNo = p.OgrenciNo,
                AdSoyad = p.AdSoyad
            }).ToList();
        }
    }
}