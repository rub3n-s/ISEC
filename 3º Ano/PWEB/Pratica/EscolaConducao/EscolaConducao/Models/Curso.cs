using System.ComponentModel.DataAnnotations;

namespace EscolaConducao.Models
{
	public class Curso
	{
		[Display(Name = "Id", Description = "Número de identificação único do curso")]
		public int Id { get; set; }
        [Display(Name = "Nome", Description = "Nome do curso", Prompt = "Introduza o nome do curso")]
        [Required]
        public string Nome { get; set; }
        [Display(Name = "Disponível", Description = "[Por fazer]", Prompt = "Indique se o curso está disponível")]
        public bool Disponivel { get; set; }
        [Display(Name = "Descrição", Description = "[Por fazer]", Prompt = "[Por fazer]")]
        public string Descricao { get; set; }
        [Display(Name = "Descrição Resumida", Description = "[Por fazer]", Prompt = "[Por fazer]")]
        public string DescricaoResumida { get; set; }
        [Display(Name = "Requisitos", Description = "[Por fazer]", Prompt = "[Por fazer]")]
        public string Requisitos { get; set; }
        [Display(Name = "Idade Mínima", Description = "[Por fazer]", Prompt = "[Por fazer]")]
        [Range(14, 100, ErrorMessage = "Mínimo: 14 anos, máximo: 100 anos")]
        public int IdadeMinima { get; set; }
        [Display(Name = "Preço", Description = "[Por fazer]", Prompt = "[Por fazer]")]
        [DataType(DataType.Currency)]
        public decimal? Preco { get; set; }
        [Display(Name = "Em Destaque", Description = "[Por fazer]", Prompt = "[Por fazer]")]
        public bool EmDestaque { get; set; }
        [Display(Name = "Id da Categoria", Description = "Identificação única da categoria do curso")]
        public int? CategoriaId { get; set; }
        [Display(Name = "Categoria", Description = "Categoria de veículo(s) associada ao curso", Prompt = "Introduza o nome do curso")]
        public Categoria Categoria { get; set; }
    }
}
