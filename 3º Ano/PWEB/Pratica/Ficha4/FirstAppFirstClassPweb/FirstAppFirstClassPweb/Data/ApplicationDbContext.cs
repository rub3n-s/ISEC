using FirstAppFirstClassPweb.Models;
using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;

namespace FirstAppFirstClassPweb.Data
{
    public class ApplicationDbContext : IdentityDbContext
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }
        public DbSet<Curso> Cursos { get; set; }

        public DbSet<Categoria> Categorias { get; set; }

        public DbSet<TipoDeAula> TiposDeAulas { get; set; }

        public DbSet<Agendamento> Agendamentos { get; set; }
    }
}