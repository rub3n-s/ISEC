﻿using FirstAppFirstClassPweb.Data;
using FirstAppFirstClassPweb.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace FirstAppFirstClassPweb.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly ApplicationDbContext _context;

        public HomeController(ILogger<HomeController> logger, ApplicationDbContext context)
        {
            _logger = logger;
            _context = context;
        }

        public IActionResult Index()
        {
            return View(_context.Cursos.Where(c => c.Disponivel == true && c.EmDestaque==true).ToList());
        }

        public IActionResult QuemSomos()
        {
            return View();
        }
        public IActionResult Cursos()
        {
            return View();
        }
        public IActionResult Contacts() {
            return View(); 
        }
        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}