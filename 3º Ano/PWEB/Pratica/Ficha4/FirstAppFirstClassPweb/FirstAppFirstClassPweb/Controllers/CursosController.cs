using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using FirstAppFirstClassPweb.Data;
using FirstAppFirstClassPweb.Models;
using FirstAppFirstClassPweb.ViewModel;

namespace FirstAppFirstClassPweb.Controllers
{
    public class CursosController : Controller
    {
        private readonly ApplicationDbContext _context;

        public CursosController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: Courses
        public async Task<IActionResult> Index()
        {
            var applicationDbContext = _context.Cursos.Include(c => c.categoria);
            return View(await applicationDbContext.ToListAsync());
        }
        [HttpPost]
        public async Task<IActionResult> Index(string pesquisa)
        {

            if (string.IsNullOrWhiteSpace(pesquisa))
            {
                return View(_context.Cursos);
            }
            else
                return View(await _context.Cursos.Include("categoria").Where(c => c.Nome.Contains(pesquisa)).ToListAsync());
        }

        public async Task<IActionResult> Search(string? TextoAPesquisar)
        {
            PesquisaCursoViewModel pesquisaVM = new PesquisaCursoViewModel();

            if (string.IsNullOrWhiteSpace(TextoAPesquisar))
            {
                pesquisaVM.ListaDeCursos = await _context.Cursos.Include("categoria").ToListAsync();
            }
            else
            {
                //pesquisaVM.ListaDeCursos = await _context.Cursos.Include("categoria").Where(c => c.Nome.Contains(TextoAPesquisar)).ToListAsync();
                
                pesquisaVM.ListaDeCursos = await _context.Cursos.Include("categoria").
                    Where(c => c.Nome.Contains(TextoAPesquisar) ||
                                c.Descricao.Contains(TextoAPesquisar) ||
                                c.DescricaoResumida.Contains(TextoAPesquisar)).ToListAsync();

                pesquisaVM.TextoAPesquisar = TextoAPesquisar;
            }
            pesquisaVM.NumResultados = pesquisaVM.ListaDeCursos.Count();

            return View(pesquisaVM);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Search([Bind("TextoAPesquisar")] PesquisaCursoViewModel pesquisaCurso)
        {
            if (string.IsNullOrEmpty(pesquisaCurso.TextoAPesquisar))
            {
                pesquisaCurso.ListaDeCursos = await _context.Cursos.ToListAsync();
                pesquisaCurso.NumResultados = pesquisaCurso.ListaDeCursos.Count();
            }
            else
            {
                pesquisaCurso.ListaDeCursos = await _context.Cursos.Where(c => c.Nome.Contains(pesquisaCurso.TextoAPesquisar)).ToListAsync();
                pesquisaCurso.NumResultados = pesquisaCurso.ListaDeCursos.Count();
            }
            return View(pesquisaCurso);
        }

        // GET: Courses/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null || _context.Cursos == null)
            {
                return NotFound();
            }

            var course = await _context.Cursos
                .Include(c => c.categoria)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (course == null)
            {
                return NotFound();
            }

            return View(course);
        }

        // GET: Courses/Create
        public IActionResult Create()
        {
            ViewData["CategoriaId"] = new SelectList(_context.Categorias, "Id", "Id");
            return View();
        }

        public IActionResult Todos()
        {
            return View();
        }

        public IActionResult Inactivos()
        {
            List<Curso> cursosInativos = new List<Curso>();
            foreach (var course in _context.Cursos)
            {
                if (course.Disponivel == false)
                {
                    cursosInativos.Add(course);
                }

            }
            return View(cursosInativos);
        }

        public IActionResult Activos()
        {
            List<Curso> cursosAtivos = new List<Curso>();
            foreach (var course in _context.Cursos)
            {
                if (course.Disponivel != false)
                {
                    cursosAtivos.Add(course);
                }

            }
            return View(cursosAtivos);
        }

        // POST: Courses/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Nome,Disponivel,Descricao,DescricaoResumida,Requisitos,IdadeMinima,Preco,CategoriaId,EmDestaque")] Curso course)
        {
            ModelState.Remove(nameof(course.categoria));

            if (ModelState.IsValid)
            {
                _context.Add(course);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["CategoriaId"] = new SelectList(_context.Categorias, "Id", "Id", course.CategoriaId);
            return View(course);
        }

        // GET: Courses/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null || _context.Cursos == null)
            {
                return NotFound();
            }

            var course = await _context.Cursos.FindAsync(id);
            if (course == null)
            {
                return NotFound();
            }
            ViewData["CategoriaId"] = new SelectList(_context.Categorias, "Id", "Id", course.CategoriaId);
            return View(course);
        }

        // POST: Courses/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Id,Nome,Disponivel,Descricao,DescricaoResumida,Requisitos,IdadeMinima,Preco,CategoriaId,EmDestaque")] Curso course)
        {
            ModelState.Remove(nameof(course.categoria));
            
            if (id != course.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(course);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!CourseExists(course.Id))
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
            ViewData["CategoriaId"] = new SelectList(_context.Categorias, "Id", "Id", course.CategoriaId);
            return View(course);
        }

        // GET: Courses/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null || _context.Cursos == null)
            {
                return NotFound();
            }

            var course = await _context.Cursos
                .Include(c => c.categoria)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (course == null)
            {
                return NotFound();
            }

            return View(course);
        }

        // POST: Courses/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            if (_context.Cursos == null)
            {
                return Problem("Entity set 'ApplicationDbContext.Cursos'  is null.");
            }
            var course = await _context.Cursos.FindAsync(id);
            if (course != null)
            {
                _context.Cursos.Remove(course);
            }
            
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool CourseExists(int id)
        {
          return _context.Cursos.Any(e => e.Id == id);
        }
    }
}
