using System.ComponentModel.DataAnnotations;
using System.Xml.Linq;

namespace EscolaConducao.Models
{
    public class Categoria
    {
        [Display(Name = "Id", Description = "Número de identificação único da categoria")]
        [Required]
        public int Id { get; set; }
        [Display(Name = "Nome", Description = "Nome da categoria")]
        [Required]
        public string Nome { get; set; }
        [Display(Name = "Descrição", Description = "Descrição da categoria")]
        public string Descricao { get; set; }
        [Display(Name = "Disponível?", Description = "Disponibilidade da categoria")]
        [Required]
        public bool Disponivel { get; set; }

        [Display(Name = "ListaCursos", Description = "Lista de cursos com esta categoria")]
        public ICollection<Curso> Cursos { get; set; }
    }
}
