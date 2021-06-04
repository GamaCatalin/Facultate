using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Car_Dealership.Domain;
using System.Data;

namespace Car_Dealership.Service
{
    class MainService
    {
        private SQLController repository;
        public MainService()
        {
            this.repository = new SQLController();
        }

        public List<Manufacturer> getAllManufacturers()
        {
            List<Manufacturer> manufacturers = new List<Manufacturer>();

            DataSet manufacturersSet = this.repository.getManufacturers();

            for (int i = 0; i < manufacturersSet.Tables[0].Rows.Count; i++)
            {
                String manufacturerName = manufacturersSet.Tables[0].Rows[i]["manufacturerName"].ToString();
                String manufacturerDetails = manufacturersSet.Tables[0].Rows[i]["details"].ToString();


                Manufacturer manufacturer = new Manufacturer(manufacturerName,manufacturerDetails);
                manufacturers.Add(manufacturer);
            }
            return manufacturers;
        }

        public List<Model> getAllModels()
        {
            List<Model> models = new List<Model>();

            DataSet modelsSet = this.repository.getModels();

            for(int i = 0; i < modelsSet.Tables[0].Rows.Count; i++)
            {
                String modelName = modelsSet.Tables[0].Rows[i]["modelName"].ToString();
                String manufacturerName = modelsSet.Tables[0].Rows[i]["manufacturerName"].ToString();
                int categoryId = int.Parse(modelsSet.Tables[0].Rows[i]["categoryId"].ToString());
                String description = modelsSet.Tables[0].Rows[i]["description"].ToString();

                Model model = new Model(modelName, manufacturerName, categoryId, description);
                models.Add(model);
            }
            return models;
        }

        public List<Model> getFilteredModels(String filterManufacturerName)
        {

            if(filterManufacturerName == "")
            {
                return this.getAllModels();
            }

            List<Model> models = new List<Model>();

            DataSet modelsSet = this.repository.getModels();

            for (int i = 0; i < modelsSet.Tables[0].Rows.Count; i++)
            {
                String modelName = modelsSet.Tables[0].Rows[i]["modelName"].ToString();
                String manufacturerName = modelsSet.Tables[0].Rows[i]["manufacturerName"].ToString();
                int categoryId = int.Parse(modelsSet.Tables[0].Rows[i]["categoryId"].ToString());
                String description = modelsSet.Tables[0].Rows[i]["description"].ToString();

                if(filterManufacturerName == manufacturerName)
                {
                    Model model = new Model(modelName, manufacturerName, categoryId, description);
                    models.Add(model);
                }               
            }
            return models;
        }

        public void addModel(Model model)
        {
            this.repository.addModel(model);
        }

        public void updateModel(Model model)
        {
            this.repository.updateModel(model);
        }
        public void deleteModel(Model model)
        {
            this.repository.deleteModel(model);
        }
    }
}
