using Microsoft.AspNetCore.Mvc;
using Parte_IV.Models;
using System.Diagnostics;

namespace Parte_IV.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Inicio()
        {
            return View();
        }

        public IActionResult QuemSomos()
        {
            return View();
        }

        public IActionResult Cursos()
        {
            return View();
        }

        public IActionResult Contactos()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}