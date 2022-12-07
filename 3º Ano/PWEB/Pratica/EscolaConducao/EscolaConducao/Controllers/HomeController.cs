using EscolaConducao.Data;
using EscolaConducao.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System.Diagnostics;

namespace EscolaConducao.Controllers
{
	public class HomeController : Controller
    {
        private readonly ApplicationDbContext _context;
        private readonly ILogger<HomeController> _logger;

		public HomeController(ILogger<HomeController> logger, ApplicationDbContext context)
		{
			_logger = logger;
			_context = context;
		}

		public async Task<IActionResult> Index()
		{
			return View(await _context.Cursos.Where(d => d.Disponivel// && d.EmDestaque
					).ToListAsync());
		}

		public IActionResult Privacy()
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