using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using EscolaConducao.Data;
using EscolaConducao.Models;
using Microsoft.AspNetCore.Authorization;

namespace EscolaConducao.Controllers
{
    public class CursosController : Controller
    {
        private readonly ApplicationDbContext _context;

        public CursosController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: Cursos
        public async Task<IActionResult> Index(bool? disponivel)
        {
            //  var cursosT = await _context.Cursos.Where(d => d.Id == 1).ToListAsync();
            //  ViewBag.vCursos =  "TESTE";

            ViewBag.ListaDeCategorias = new SelectList(await _context.Categorias.ToListAsync(),
                "Id", "Nome");

            if (disponivel == null)
            {
                ViewData["Title"] = "Lista de Cursos";
                var cursos = await _context.Cursos.ToListAsync();
                //ViewBag.vCursos = cursos;
                return View(cursos);
            }
            else if (disponivel == true)
                ViewData["Title"] = "Lista de Cursos disponíveis";
            else
                ViewData["Title"] = "Lista de Cursos não disponíveis";

            return View(await _context.Cursos.Where(c => c.Disponivel == disponivel).ToListAsync());
        }

        // POST: Cursos
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Index(string TextoAPesquisar, int? CategoriaId)
        {
            ViewData["Title"] = "Lista de Cursos com '" + TextoAPesquisar + "'";
            
            if (CategoriaId == null) {
                return View(await _context.Cursos.Where(
                    c => (c.Nome.Contains(TextoAPesquisar) || c.Descricao.Contains(TextoAPesquisar))
                    && c.CategoriaId == CategoriaId).ToListAsync());
            }

            // LINQ Query Syntax:
            return View(await (from c in _context.Cursos
                         where c.Nome.Contains(TextoAPesquisar) || c.Descricao.Contains(TextoAPesquisar)
                         select c).ToListAsync());
            // LINQ Method Syntax:
            // return View(await _context.Cursos.Where(c => c.Nome.Contains(pesquisa) || c.Descricao.Contains(pesquisa)).ToListAsync());
        }

        // GET: Search
        public async Task<IActionResult> Search(string? textoAPesquisar)
        {
            PesquisaCursoViewModel pcvm = new PesquisaCursoViewModel();
            if (textoAPesquisar == null)
            {
                ViewData["Title"] = "Lista de Cursos";
                pcvm.ListaDeCursos = await _context.Cursos.ToListAsync();
            }
            else
            {
                ViewData["Title"] = "Lista de Cursos com '" + textoAPesquisar + "'";
                pcvm.ListaDeCursos = await (from c in _context.Cursos
                                            where c.Nome.Contains(textoAPesquisar) || c.Descricao.Contains(textoAPesquisar)
                                            select c).ToListAsync();
            }
            pcvm.NumResultados = pcvm.ListaDeCursos.Count;
            return View(pcvm);
        }

        // POST: Search (c/ Bind)
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Search([Bind("TextoAPesquisar")]PesquisaCursoViewModel pesquisaCurso)
        {
            ViewData["Title"] = "Lista de Cursos com '" + pesquisaCurso.TextoAPesquisar + "'";
            pesquisaCurso.ListaDeCursos = await (
                from c in _context.Cursos
                where c.Nome.Contains(pesquisaCurso.TextoAPesquisar) || c.Descricao.Contains(pesquisaCurso.TextoAPesquisar)
                select c).ToListAsync();
            pesquisaCurso.NumResultados = pesquisaCurso.ListaDeCursos.Count;
            return View(pesquisaCurso);
        }

        // POST: Search (s/ Bind)
/*        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Search(string? textoAPesquisar)
        {
            ViewData["Title"] = "Lista de Cursos com '" + textoAPesquisar + "'";

            var pesquisaVM = new PesquisaCursoViewModel();

            if (string.IsNullOrWhiteSpace(textoAPesquisar)) {
                pesquisaVM.ListaDeCursos = await _context.Cursos.ToListAsync();
                pesquisaVM.NumResultados = pesquisaVM.ListaDeCursos.Count;
                return View(pesquisaVM);
            }

            pesquisaVM.ListaDeCursos = await (
                from c in _context.Cursos
                where c.Nome.Contains(textoAPesquisar) || c.Descricao.Contains(textoAPesquisar)
                select c).ToListAsync();
            pesquisaVM.NumResultados = pesquisaVM.ListaDeCursos.Count;
            return View(pesquisaVM);
        }*/

        // GET: Cursos/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null || _context.Cursos == null)
            {
                return NotFound();
            }

            var curso = await _context.Cursos.FirstOrDefaultAsync(m => m.Id == id);
            if (curso == null)
            {
                return NotFound();
            }

            return View(curso);
        }

        // GET: Cursos/Create
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> Create()
        {
            ViewData["ListaDeCategorias"] = new SelectList(await _context.Categorias.ToListAsync(),
                "Id", "Nome");
            return View();
        }

        // POST: Cursos/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> Create([Bind("Id,Nome,Disponivel,Descricao,DescricaoResumida,Requisitos,IdadeMinima,Preco,EmDestaque,CategoriaId")] Curso curso)
        {
            ModelState.Remove(nameof(curso.Categoria));

            if (ModelState.IsValid)
            {
                _context.Add(curso);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(curso);
        }

        // GET: Cursos/Edit/5
        [Authorize(Roles = "Admin")]
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

            ViewData["ListaDeCategorias"] = new SelectList(await _context.Categorias.ToListAsync(),
                "Id", "Nome");

            return View(curso);
        }

        // POST: Cursos/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> Edit(int id, [Bind("Id,Nome,Disponivel,Descricao,DescricaoResumida,Requisitos,IdadeMinima,Preco,EmDestaque,CategoriaId")] Curso curso)
        {
            if (id != curso.Id)
            {
                return NotFound();
            }

            ModelState.Remove(nameof(curso.Categoria));

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
        [Authorize(Roles = "Admin")]
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
        [Authorize(Roles = "Admin")]
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
          return _context.Cursos.Any(e => e.Id == id);
        }
    }
}
