using System;
using System.ComponentModel.DataAnnotations;

namespace ficha3.Models
{
    public class PesquisaCursoViewModel
    {
        public List<Curso>? ListaDeCursos { get; set; }


        public int NumResultados { get; set; }

        [Required]
        [Display(Name = "Texto", Prompt = "Introduza o texto a pesquisar")]
        public string? TextoAPesquisar { get; set; }
    }
}

