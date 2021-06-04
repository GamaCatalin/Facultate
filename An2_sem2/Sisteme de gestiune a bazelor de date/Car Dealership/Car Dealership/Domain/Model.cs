using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Dealership.Domain
{
    class Model
    {
        public String modelName { get; set; }
        public String manufacturerName { get; set; }
        public int categoryId { get; set; }
        public String description { get; set; }

        public Model(String modelName, String manufacturerName,int categoryId,String description)
        {
            this.modelName = modelName;
            this.manufacturerName = manufacturerName;
            this.categoryId = categoryId;
            this.description = description;
        }

        public String toString()
        {
            return "'" + this.modelName + "', '" + this.manufacturerName + "', " + this.categoryId + ", '" + this.description+"'";
        }
    }
}
