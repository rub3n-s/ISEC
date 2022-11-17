using System;
namespace FirstAppFirstClassPweb.Models
{
	public class Agendamento
	{
		public int Id { get; set; }
		public String Cliente { get; set; }
		public DateTime DataInicio { get; set; }
        public DateTime DataFim { get; set; }
		public int DuracaoEmHoras { get; set; }
        public int DuracaoEmMinutos { get; set; }
		public Decimal Preco { get; set; }
		public DateTime DataHoraDoPedido { get; set; }
		public int TipoDeAulaId { get; set; }
		public TipoDeAula tipoDeAula { get; set; }
    }
}

