using System;
using System.ComponentModel.DataAnnotations;

namespace ficha3.Models
{
	public class Curso
	{
        public int Id { get; set; }

        [Display(Name = "Nome")]
        public string Nome { get; set; }

        [Display(Name = "Está disponivel?")]
        public bool Disponivel { get; set; }

        [Display(Name = "Descrição")]
        public string Descricao { get; set; }

        [Display(Name = "Descrição Resumida")]
        public string DescricaoResumida { get; set; }

        [Display(Name = "Requisitos")]
        public string Requisitos { get; set; }

        [Display(Name = "Idade Mínima", Prompt = "Introduza a idade")]
        [Range(14,100,ErrorMessage = "Tem que ter entre 14 e 100 anos")]
        public int IdadeMinima { get; set; }

        [Display(Name = "Preço")]
        public decimal? Preco { get; set; }

        [Display(Name = "Curso em destaque na primeira página?")]
        public bool EmDestaque { get; set; }

        public int? CategoriaId { get; set; }
        public Categoria categoria { get; set; }
    }
}

