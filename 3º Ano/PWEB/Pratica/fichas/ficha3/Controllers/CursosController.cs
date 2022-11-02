using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using ficha3.Data;
using ficha3.Models;

namespace ficha3.Controllers
{
    public class CursosController : Controller
    {
        private readonly ApplicationDbContext _context;

        public CursosController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: Cursos
        public async Task<IActionResult> Index(bool? disponivel,bool? emDestaque)
        {
            ViewData["ListadeCategorias"] = new SelectList(_context.Categorias.ToList(),"Id","Nome");

            if (disponivel != null)
            {
                if (disponivel == true)
                    ViewData["Title"] = "Lista de Cursos Disponiveis";
                else
                    ViewData["Title"] = "Lista de Cursos Indisponiveis";

                return View(await _context.Cursos.Include("categoria").Where(c => c.Disponivel == disponivel).ToListAsync());
                //return View(await _context.Cursos.Where(c => c.Disponivel == disponivel).ToListAsync());
            }
            else if (emDestaque != null)
            {
                if (emDestaque == true)
                {
                    ViewData["Title"] = "Lista de Cursos em Destaque";
                }
                else
                {
                    ViewData["Title"] = "Lista de Cursos em Destaque";
                }
                return View(await _context.Cursos.Include("categoria").Where(c => c.EmDestaque == emDestaque).ToListAsync());
                //return View(await _context.Cursos.Where(c => c.EmDestaque == emDestaque).ToListAsync());
            }
            else
            {
                return View(await _context.Cursos.ToListAsync());
            }
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Index(string TextoAPesquisar, int CategoriaId)
        {
            ViewData["ListadeCategorias"] = new SelectList(_context.Categorias.ToList(), "Id", "Nome");

            if (string.IsNullOrWhiteSpace(TextoAPesquisar))
                return View(_context.Cursos.Where(c => c.CategoriaId == CategoriaId));
            else
            {
                var resultado = from c in _context.Cursos
                                where c.Nome.Contains(TextoAPesquisar) && c.CategoriaId == CategoriaId
                                select c;
                return View(resultado);
            }
            return View();
        }

        // GET: Categorias
        public async Task<IActionResult> Search(bool? disponivel, bool? emDestaque)
        {
            ViewData["ListadeCategorias"] = new SelectList(_context.Categorias.ToList(), "Id", "Nome");

            if (disponivel != null)
            {
                if (disponivel == true)
                    ViewData["Title"] = "Lista de Cursos Disponiveis";
                else
                    ViewData["Title"] = "Lista de Cursos Indisponiveis";

                return View(await _context.Cursos.Include("categoria").Where(c => c.Disponivel == disponivel).ToListAsync());
                //return View(await _context.Cursos.Where(c => c.Disponivel == disponivel).ToListAsync());
            }
            else if (emDestaque != null)
            {
                if (emDestaque == true)
                {
                    ViewData["Title"] = "Lista de Cursos em Destaque";
                }
                else
                {
                    ViewData["Title"] = "Lista de Cursos em Destaque";
                }
                return View(await _context.Cursos.Include("categoria").Where(c => c.EmDestaque == emDestaque).ToListAsync());
                //return View(await _context.Cursos.Where(c => c.EmDestaque == emDestaque).ToListAsync());
            }
            else
            {
                return View(await _context.Cursos.ToListAsync());
            }
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Search(string TextoAPesquisar, int CategoriaId)
        {
            ViewData["ListadeCategorias"] = new SelectList(_context.Categorias.ToList(), "Id", "Nome");

            if (string.IsNullOrWhiteSpace(TextoAPesquisar))
                return View(_context.Cursos.Where(c => c.CategoriaId == CategoriaId));
            else
            {
                var resultado = from c in _context.Cursos
                                where c.Nome.Contains(TextoAPesquisar) && c.CategoriaId == CategoriaId
                                select c;
                return View(resultado);
            }
            return View();
        }

        // GET: Cursos/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null || _context.Cursos == null)
            {
                return NotFound();
            }

            var curso = await _context.Cursos
                .FirstOrDefaultAsync(m => m.Id == id);
            if (curso == null)
            {
                return NotFound();
            }

            return View(curso);
        }

        // GET: Cursos/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: Cursos/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Id,Nome,Disponivel,Categoria,Descricao,DescricaoResumida,Requisitos,IdadeMinima")] Curso curso)
        {
            if (ModelState.IsValid)
            {
                _context.Add(curso);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(curso);
        }

        // GET: Cursos/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null || _context.Cursos == null)
            {
                return NotFound();
            }

            var curso = await _context.Cursos.FindAsync(id);
            if (curso == null)
            {
                return NotFound();
            }
            return View(curso);
        }

        // POST: Cursos/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Id,Nome,Disponivel,Categoria,Descricao,DescricaoResumida,Requisitos,IdadeMinima,EmDestaque")] Curso curso)
        {
            if (id != curso.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(curso);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!CursoExists(curso.Id))
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
            return View(curso);
        }

        // GET: Cursos/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null || _context.Cursos == null)
            {
                return NotFound();
            }

            var curso = await _context.Cursos
                .FirstOrDefaultAsync(m => m.Id == id);
            if (curso == null)
            {
                return NotFound();
            }

            return View(curso);
        }

        // POST: Cursos/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            if (_context.Cursos == null)
            {
                return Problem("Entity set 'ApplicationDbContext.Cursos'  is null.");
            }
            var curso = await _context.Cursos.FindAsync(id);
            if (curso != null)
            {
                _context.Cursos.Remove(curso);
            }
            
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool CursoExists(int id)
        {
          return (_context.Cursos?.Any(e => e.Id == id)).GetValueOrDefault();
        }
    }
}
