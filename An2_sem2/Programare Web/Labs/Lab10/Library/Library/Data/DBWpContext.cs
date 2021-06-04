using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

using Microsoft.EntityFrameworkCore;
using MySql.Data.EntityFrameworkCore;
using AspCoreMVCEF.Models;

namespace AspCoreMVCEF.Data
{
	public class DBWpContext : DbContext
	{
		public DBWpContext(DbContextOptions options) : base(options)
		{
		}

		public DbSet<Student> Student { get; set; }
	}
}