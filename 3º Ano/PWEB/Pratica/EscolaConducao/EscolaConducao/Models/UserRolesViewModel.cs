using System.ComponentModel.DataAnnotations;

namespace EscolaConducao.Models
{
    public class UserRolesViewModel
    {
        public string UserId { get; set; }
        
        [Display(Name = "First Name")]
        public string PrimeiroNome { get; set; }
        
        [Display(Name = "Last Name")]
        public string UltimoNome { get; set; }
        
        [Display(Name = "Email")]
        public string Email { get; set; }
        
        [Display(Name = "Username")]
        public string UserName { get; set; }
        
        [Display(Name = "Avatar")]
        public byte[]? Avatar { get; set; }
        
        
        public IEnumerable<string> Roles { get; set; }
    }
}
