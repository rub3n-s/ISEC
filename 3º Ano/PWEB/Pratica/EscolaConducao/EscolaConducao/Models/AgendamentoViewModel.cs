using System.ComponentModel.DataAnnotations;
using System.Xml.Linq;

namespace EscolaConducao.Models
{
    public class AgendamentoViewModel
    {
        public DateTime DataInicio { get; set; }
        public DateTime DataFim { get; set; }

        [Display(Name = "Tipo de aula", Prompt = "Escolha o tipo de aula que pretende")]
        public int TipoDeAulaId { get; set; }
    }
}
