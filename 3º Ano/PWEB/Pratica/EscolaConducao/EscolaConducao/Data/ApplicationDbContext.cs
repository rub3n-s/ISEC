using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;
using EscolaConducao.Models;

namespace EscolaConducao.Data
{
	public class ApplicationDbContext : IdentityDbContext<ApplicationUser>
	{
		public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
			: base(options)
		{
		}
		public DbSet<Curso> Cursos { get; set; }
		public DbSet<Categoria> Categorias { get; set; }
		public DbSet<TipoDeAula> TiposDeAula { get; set; }
		public DbSet<Agendamento> Agendamentos { get; set; }
	}
}