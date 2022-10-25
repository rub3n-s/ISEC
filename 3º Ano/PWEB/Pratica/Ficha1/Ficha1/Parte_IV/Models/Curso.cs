using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace Parte_IV.Models
{
    public class Curso
    {
        public int Id { get; set; }
        public string Nome { get; set; }
        public string Categoria { get; set; }
        public string Requisitos { get; set; }
        
        [Display(Name = "Idade Minima", Prompt = "Introduza a idade minima", Description = "Idade minima para poder frequentar")]
        [Range(14,100,ErrorMessage ="Mínimo: 14 anos, Máximo: 100 anos")]
        public int IdadeMinima { get; set; }
        
        public string Descricao { get; set; }
        public string DescricaoResumida { get; set; }
        public decimal? Preco { get; set; }
        public bool Disponivel { get; set; }
        
        [Display(Name = "Curso em destaque na primeira pagina?")]
        public bool EmDestaque { get; set; }
    }
}
