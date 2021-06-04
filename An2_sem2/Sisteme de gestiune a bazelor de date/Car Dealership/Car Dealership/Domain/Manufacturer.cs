using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Dealership.Domain
{
    class Manufacturer
    {
        public String manufacturerName { get; set; }
        public String details { get; set; }

        public Manufacturer(String manufacturerName,String details)
        {
            this.manufacturerName = manufacturerName;
            this.details = details;
        }

        public String getName()
        {
            return this.manufacturerName;
        }

        public String toString()
        {
            return manufacturerName + ", " + details;
        }
    }
}
