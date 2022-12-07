namespace EscolaConducao.Models
{
    public class Agendamento
    {
        public int Id { get; set; }
        public DateTime DataInicio { get; set; }
        public DateTime DataFim { get; set; }
        public int DuracaoEmHoras { get; set; }
        public int DuracaoEmMinutos { get; set; }
        public decimal Preco { get; set; }
        public DateTime DataHoraDoPedido { get; set; }

        public int TipoDeAulaId { get; set; }
        public TipoDeAula TipoDeAula { get; set; }
        public ApplicationUser ApplicationUser { get; set; }
        public string ApplicationUserId { get; set; }
    }
}
