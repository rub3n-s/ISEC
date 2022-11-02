using System;
using System.ComponentModel.DataAnnotations;

namespace ficha3.Models
{
	public class Categoria
	{
		public int Id { get; set; }

		[Display(Name = "Categoria")]
		public string Nome { get; set; }

		public string Descricao { get; set; }

		public Boolean Disponivel { get; set; }

		public ICollection<Curso> Cursos { get; set; }
	}
}

