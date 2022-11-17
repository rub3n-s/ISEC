using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using FirstAppFirstClassPweb.Data;
using FirstAppFirstClassPweb.Models;

namespace FirstAppFirstClassPweb.Controllers
{
    public class TipoDeAulaController : Controller
    {
        private readonly ApplicationDbContext _context;

        public TipoDeAulaController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: TipoDeAula
        public async Task<IActionResult> Index()
        {
              return _context.TiposDeAulas != null ? 
                          View(await _context.TiposDeAulas.ToListAsync()) :
                          Problem("Entity set 'ApplicationDbContext.TiposDeAulas'  is null.");
        }

        // GET: TipoDeAula/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null || _context.TiposDeAulas == null)
            {
                return NotFound();
            }

            var tipoDeAula = await _context.TiposDeAulas
                .FirstOrDefaultAsync(m => m.Id == id);
            if (tipoDeAula == null)
            {
                return NotFound();
            }

            return View(tipoDeAula);
        }

        // GET: TipoDeAula/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: TipoDeAula/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Id,Nome,ValorHora")] TipoDeAula tipoDeAula)
        {
            if (ModelState.IsValid)
            {
                _context.Add(tipoDeAula);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(tipoDeAula);
        }

        // GET: TipoDeAula/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null || _context.TiposDeAulas == null)
            {
                return NotFound();
            }

            var tipoDeAula = await _context.TiposDeAulas.FindAsync(id);
            if (tipoDeAula == null)
            {
                return NotFound();
            }
            return View(tipoDeAula);
        }

        // POST: TipoDeAula/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Id,Nome,ValorHora")] TipoDeAula tipoDeAula)
        {
            if (id != tipoDeAula.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(tipoDeAula);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!TipoDeAulaExists(tipoDeAula.Id))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index));
            }
            return View(tipoDeAula);
        }

        // GET: TipoDeAula/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null || _context.TiposDeAulas == null)
            {
                return NotFound();
            }

            var tipoDeAula = await _context.TiposDeAulas
                .FirstOrDefaultAsync(m => m.Id == id);
            if (tipoDeAula == null)
            {
                return NotFound();
            }

            return View(tipoDeAula);
        }

        // POST: TipoDeAula/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            if (_context.TiposDeAulas == null)
            {
                return Problem("Entity set 'ApplicationDbContext.TiposDeAulas'  is null.");
            }
            var tipoDeAula = await _context.TiposDeAulas.FindAsync(id);
            if (tipoDeAula != null)
            {
                _context.TiposDeAulas.Remove(tipoDeAula);
            }
            
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool TipoDeAulaExists(int id)
        {
          return (_context.TiposDeAulas?.Any(e => e.Id == id)).GetValueOrDefault();
        }
    }
}
