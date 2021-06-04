using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace AspCoreMVCEF.Models
{
    public class Book
    {
        public int bookID { get; set; }
        public string author { get; set; }
        public string title { get; set; }
        public int pagesNr { get; set; }
        public string genre { get; set; }
    }
}
