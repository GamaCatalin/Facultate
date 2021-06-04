using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using AspCoreMVCEF.Models;
using AspCoreMVCEF.Data;

namespace Library.Controllers
{
    public class MainController : Controller
    {
        private readonly DBWpContext _context;
        public MainController(DBWpContext context)
        {
            _context = context;
        }

        public string GetStudentsFromGroup(int group_id)
        {
            List<Student> slist = _context.Student.Where(stud => stud.Group_id == group_id).ToList();

            string result = "<table><thead><th>Id</th><th>Name</th><th>Password</th><th>Group_Id</th></thead>";

            foreach (Student stud in slist)
            {
                result += "<tr><td>" + stud.Id + "</td><td>" + stud.Name + "</td><td>" + stud.Password + "</td><td>" + stud.Group_id + "</td><td></tr>";
            }

            result += "</table>";
            return result;
        }

        public IActionResult Index()
        {
            return View();
        }

        public string Test()
        {
            return "It's working";
        }

        public string Test1(string param1 = "hello", int param2 = 0)
        {
            return "Result: " + param1 + param2.ToString();
        }

    }
}
