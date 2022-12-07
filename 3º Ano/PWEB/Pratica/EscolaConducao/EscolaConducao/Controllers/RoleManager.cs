using EscolaConducao.Data;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace EscolaConducao.Controllers
{
    [Authorize(Roles = "Admin")]
    public class RoleManagerController : Controller
    {
        private readonly RoleManager<IdentityRole> _roleManager;
        
        public RoleManagerController(RoleManager<IdentityRole> roleManager)
        {
            _roleManager = roleManager;
        }
        public async Task<IActionResult> Index()
        {
            var roles = await _roleManager.Roles.OrderBy(a => a.Name).ToListAsync();
            return View(roles);
        }
        [HttpPost]
        public async Task<IActionResult> AddRole(string roleName)
        {
            if (roleName != null)
            {
                await _roleManager.CreateAsync(new IdentityRole(roleName.Trim()));
            }
            return RedirectToAction("Index");
        }

        public async Task<IActionResult> Delete(string id)
        {
            var role = _roleManager.Roles.Where(r => r.Id == id).FirstOrDefault();
            if (role != null)
            {
                await _roleManager.DeleteAsync(role);
            }
            return RedirectToAction("Index");
        }
    }
}
