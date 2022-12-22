using System;
using System.ComponentModel.DataAnnotations;
using Microsoft.AspNetCore.Identity;

namespace FirstAppFirstClassPweb.Models
{
	public class ApplicationUser : IdentityUser
    {
		[Display(Name="Primeiro Nome")]
		public string PrimeiroNome { get; set; }

        [Display(Name = "Apelido")]
        public string UltimoNome { get; set; }

        [Display(Name = "Data de Nascimento")]
        public DateTime DataNascimento { get; set; }

        public int NIF { get; set; }

        public ICollection<Agendamento> Agendamentos { get; set; }
    }
}

