using ObsAPI.Tipler;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Http;

namespace ObsAPI.Controllers
{
    public class DersController : ApiController
    {
        intTekObsEntities _ent = new intTekObsEntities();
        [HttpGet]
        public List<DersTip> TumDersleriGetir()
        {
            return _ent.Ders.Select(p => new DersTip() { 
            DersId=p.DersId, // DersId, p'nin işaret ettiği DersTip'deki DersId olacak
            DersAdi=p.DersAdi,
            DersiAlanOgrenciSayisi=p.Not.Count // dersId, Not tablosunda kaç kere geçmiş onu sayar
            }).ToList();
        }
    }
}