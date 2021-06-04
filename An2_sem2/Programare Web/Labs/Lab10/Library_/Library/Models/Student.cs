using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace AspCoreMVCEF.Models
{
	public class Student
	{
		public int Id { get; set; }
		public string Name { get; set; }
		public string Password { get; set; }
		public int Group_id { get; set; }
	}
}