using EscolaConducao.Models;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Razor.Infrastructure;
using Microsoft.EntityFrameworkCore;
using Newtonsoft.Json.Linq;

namespace EscolaConducao.Controllers
{
    public class UserRolesManagerController : Controller
    {
        private readonly UserManager<ApplicationUser> _userManager;
        private readonly RoleManager<IdentityRole> _roleManager;
        public UserRolesManagerController(UserManager<ApplicationUser> userManager,
            RoleManager<IdentityRole> roleManager)
        {
            _userManager = userManager;
            _roleManager = roleManager;
        }

        public async Task<IActionResult> Index()
        {
            var users = await _userManager.Users.OrderBy(a => a.PrimeiroNome).ToListAsync();
            var userRolesViewModel = new List<UserRolesViewModel>();


            foreach (ApplicationUser user in users)
            {
                var utilizadorVM = new UserRolesViewModel();
                utilizadorVM.UserId = user.Id;
                utilizadorVM.Email = user.Email;
                utilizadorVM.PrimeiroNome = user.PrimeiroNome;
                utilizadorVM.UltimoNome = user.UltimoNome;
                utilizadorVM.Roles = await GetUserRoles(user);
                userRolesViewModel.Add(utilizadorVM);
            }

            return View(userRolesViewModel);
            
            /*var users = await _userManager.Users.ToListAsync();
            var userRolesViewModel = new List<UserRolesViewModel>();
            foreach (var user in users)
            {
                userRolesViewModel.Add(new UserRolesViewModel()
                {
                    UserId = user.Id,
                    PrimeiroNome = user.PrimeiroNome,
                    UltimoNome = user.UltimoNome,
                    UserName = user.UserName,
                    Avatar = user.Avatar,
                    Roles = await GetUserRoles(user)
                    //Roles = await _userManager.GetRolesAsync(user)
                }
                );
                //var temp = new UserRolesViewModel();
                //temp.UserId = user.Id;
                //temp.PrimeiroNome = user.PrimeiroNome;
                //temp.UltimoNome = user.UltimoNome;
                //temp.UserName = user.UserName;
                //temp.Roles = await _userManager.GetRolesAsync(user);
                //userRolesViewModel.Add(temp);
            }
            return View(userRolesViewModel); */
        }

        private async Task<List<string>> GetUserRoles(ApplicationUser user)
        {
            return new List<string>(await _userManager.GetRolesAsync(user));
        }

        public async Task<IActionResult> Details(string userId)
        {
            ViewBag.userId = userId;
            var user = await _userManager.FindByIdAsync(userId);

            if (user == null)
            {
                ModelState.AddModelError("", $"Utilizador com o id = {userId} não encontrado.");
                return View();
            }

            ViewBag.UserName = user.UserName;
            
            var model = new List<ManageUserRolesViewModel>();
            foreach (var role in _roleManager.Roles)
            {
                var userRolesViewModel = new ManageUserRolesViewModel
                {
                    RoleId = role.Id,
                    RoleName = role.Name
                };
                if (await _userManager.IsInRoleAsync(user, role.Name))
                {
                    userRolesViewModel.Selected = true;
                }
                else
                {
                    userRolesViewModel.Selected = false;
                }
                model.Add(userRolesViewModel);
            }
            return View(model);
        }

        [HttpPost]
        public async Task<IActionResult> Details(List<ManageUserRolesViewModel> model, string userId)
        {
            var user = await _userManager.FindByIdAsync(userId);
            if (user == null)
            {
                return View();
            }

            var userRoles = await _userManager.GetRolesAsync(user);
            var result = await _userManager.RemoveFromRolesAsync(user, userRoles);
            if (!result.Succeeded)
            {
                ModelState.AddModelError("", "Unable to remove existing roles.");
                return View();
            }
            
            result = await _userManager.AddToRolesAsync(user,
                model
                .Where(r => r.Selected)
                .Select(r => r.RoleName));
            if (!result.Succeeded)
            {
                ModelState.AddModelError("", "Não é possivel adicionar esta Role a este utilizador.");
                return View();
            }
            
            return RedirectToAction("Index");
        }
    }
}
