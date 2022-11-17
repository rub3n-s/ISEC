using System.ComponentModel.DataAnnotations;

namespace FirstAppFirstClassPweb.Models
    
{
    public class Curso
    {
        public int Id { get; set; }
        public string Nome { get; set; }
        public bool Disponivel { get; set; }
        public string Descricao {get;set;}
        public string DescricaoResumida {get;set;}
        public string Requisitos { get;set;}
        public int IdadeMinima { get; set; }

        [Display(Name = "Preco")]
        public float? Preco { get; set; }
        // Convenção número 4

        [Display(Name = "Categoria")]
        public int? CategoriaId { get; set; }
        //public int CategoriaId { get; set; }
        public Categoria categoria { get; set; }

        public bool EmDestaque { get; set; }
    }
}
