using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using FirstAppFirstClassPweb.Data;
using FirstAppFirstClassPweb.Models;
using FirstAppFirstClassPweb.ViewModel;
using NuGet.Versioning;
using Microsoft.AspNetCore.Mvc.Rendering;

namespace FirstAppFirstClassPweb.Controllers
{
    public class CoursesController : Controller
    {
        private readonly ApplicationDbContext _context;

        public CoursesController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: Courses
       
        public async Task<IActionResult> Index()

        {
          
          return View(await _context.Cursos.Include("categoria").ToListAsync());
        }
       
        [HttpPost]
        public async Task<IActionResult> Index(string pesquisa)
        {
            
            if (string.IsNullOrWhiteSpace(pesquisa))
            {
                return View(_context.Cursos);
            }
            else 
                return View(await _context.Cursos.Include("categoria").Where(c=>c.Nome.Contains(pesquisa)).ToListAsync());
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
                pesquisaVM.ListaDeCursos = await _context.Cursos.Include("categoria").Where(c => c.Nome.Contains(TextoAPesquisar)).ToListAsync();
                pesquisaVM.TextoAPesquisar = TextoAPesquisar;
            }
            pesquisaVM.NumResultados = pesquisaVM.ListaDeCursos.Count();
          
            return View(pesquisaVM);               
        }
        [HttpPost]
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
            ViewData["ListaDeCategorias"] = 
                new SelectList(_context.Categorias.ToList(), "Id","Nome");
            return View();
        }
        
        public IActionResult Todos()
        {
            return View();
        }
        
        public IActionResult Inactivos()
        {
            List <Course>  cursosInativos = new List<Course>();
            foreach(var course in _context.Cursos)
            {
                if(course.Disponivel == false)
                {
                    cursosInativos.Add(course);
                }

            }
            return View(cursosInativos);
        }

        public IActionResult Activos()
        {
            List<Course> cursosAtivos = new List<Course>();
            foreach (var course in _context.Cursos)
            {
                if (course.Disponivel != false)
                {
                    cursosAtivos.Add(course);
                }

            }
            return View(cursosAtivos);
        }

        // POST: Courses/   
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Id,Nome,Disponivel,Descricao,DescricaoResumida,Requisitos,IdadeMinima,CategoriaId,EmDestaque")] Course course)
        {
            ModelState.Remove(nameof(course.categoria));
            // manter o restante código existente:
            if (ModelState.IsValid)
            {
                _context.Add(course);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(course);
        }

        // GET: Courses/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            ViewData["ListaDeCategorias"] =
                new SelectList(_context.Categorias.ToList(), "Id", "Nome");
            if (id == null || _context.Cursos == null)
            {
                return NotFound();
            }

            var course = await _context.Cursos.FindAsync(id);
            if (course == null)
            {
                return NotFound();
            }
            return View(course);
        }

        // POST: Courses/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Id,Nome,Disponivel,Descricao,DescricaoResumida,Requisitos,IdadeMinima,CategoriaId;EmDestaque")] Course course)
        {
            
            if (id != course.Id)
            {
                return NotFound();
            }

            ModelState.Remove(nameof(course.categoria));
            // manter o restante código existente:
            if (ModelState.IsValid)
            {
                _context.Update(course);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
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
