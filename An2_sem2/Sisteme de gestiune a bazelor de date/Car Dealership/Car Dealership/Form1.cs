using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Car_Dealership.Domain;
using Car_Dealership.Service;

namespace Car_Dealership
{
    public partial class Form1 : Form
    {
        private List<Manufacturer> manufacturers;
        private List<Model> models;
        SQLController controller = new SQLController();
        MainService service = new MainService();
        bool isSelected = false;
        int manufacturerIndex = 0;

        public Form1()
        {
            this.manufacturers = service.getAllManufacturers();
            this.models = service.getAllModels();
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.dataGridView1.DataSource = this.manufacturers;
            this.dataGridView2.DataSource = this.models;
        }

        private void updateTables()
        {
           

            this.models = service.getFilteredModels(this.manufacturerNameTextBox.Text);

            this.dataGridView2.DataSource = this.models;
            this.dataGridView2.Update();
            this.dataGridView2.Refresh();
        }

        private void dataGridView1_filterModels(object sender, DataGridViewCellMouseEventArgs e)
        {
            if(e.RowIndex > -1)
            {
                this.isSelected = false;

                String filterName = this.manufacturers[e.RowIndex].getName();
                this.manufacturerIndex = e.RowIndex;


                Console.WriteLine(filterName);

                this.models = service.getFilteredModels(filterName);


                this.dataGridView2.DataSource = this.models;
                this.dataGridView2.Update();
                this.dataGridView2.Refresh();
            }
            else
            {
                this.models = service.getAllModels();


                this.dataGridView2.DataSource = this.models;
                this.dataGridView2.Update();
                this.dataGridView2.Refresh();
            }
            

        }

        private void selectedModelRow(object sender, DataGridViewCellEventArgs e)
        {
            this.isSelected = true;

            this.modelNameTextBox.Text = this.models[e.RowIndex].modelName;
            this.manufacturerNameTextBox.Text = this.manufacturers[this.manufacturerIndex].manufacturerName;
            this.categoryIdTextBox.Text = this.models[e.RowIndex].categoryId.ToString();
            this.descriptionTextBox.Text = this.models[e.RowIndex].description;

            this.modelNameTextBox.Enabled = false;

            //this.updateTables();
        }

        private void clearTextBoxes()
        {
            this.modelNameTextBox.Text = "";
            //this.manufacturerNameTextBox.Text = "";
            this.categoryIdTextBox.Text = "";
            this.descriptionTextBox.Text = "";
        }

        private bool isValid()
        {
            int buffer;

            if(!int.TryParse(this.categoryIdTextBox.Text,out buffer)){
                return false;
            }
            if (this.modelNameTextBox.Text.Length == 0)
            {
                return false;
            }
            return true;
        }

        private void addModelButton_Click(object sender, EventArgs e)
        {
            if (this.isSelected)
            {
                Form2 errorBox = new Form2("A model is already selected!");
                errorBox.ShowDialog();
            }
            else
            {
                if (this.isValid())
                {
                    String modelName = this.modelNameTextBox.Text;
                    String manufacturerName = this.manufacturerNameTextBox.Text;
                    int categoryId = int.Parse(this.categoryIdTextBox.Text);
                    String description = this.descriptionTextBox.Text;

                    Model newModel = new Model(modelName, manufacturerName, categoryId, description);

                    this.service.addModel(newModel);

                    this.updateTables();
                }
                else
                {
                    Form2 errorBox = new Form2("Input is not valid!");
                    errorBox.ShowDialog();
                }
            }

            
        }

        private void updateModelButton_Click(object sender, EventArgs e)
        {
            if (!this.isSelected)
            {
                Form2 errorBox = new Form2("No model is selected!");
                errorBox.ShowDialog();
            }
            else
            {
                if (this.isValid())
                {
                    String modelName = this.modelNameTextBox.Text;
                    String manufacturerName = this.manufacturerNameTextBox.Text;
                    int categoryId = int.Parse(this.categoryIdTextBox.Text);
                    String description = this.descriptionTextBox.Text;

                    Model newModel = new Model(modelName, manufacturerName, categoryId, description);

                    this.service.updateModel(newModel);

                    this.updateTables();
                }
                else
                {
                    Form2 errorBox = new Form2("Input is not valid!");
                    errorBox.ShowDialog();
                }
            }
        }

        private void deleteModelButton_Click(object sender, EventArgs e)
        {
            if (!this.isSelected)
            {
                Form2 errorBox = new Form2("No model is selected!");
                errorBox.ShowDialog();
            }
            else
            {
                if (this.isValid())
                {
                    String modelName = this.modelNameTextBox.Text;
                    String manufacturerName = this.manufacturerNameTextBox.Text;
                    int categoryId = int.Parse(this.categoryIdTextBox.Text);
                    String description = this.descriptionTextBox.Text;

                    Model newModel = new Model(modelName, manufacturerName, categoryId, description);

                    this.service.deleteModel(newModel);

                    this.updateTables();
                }
                else
                {
                    Form2 errorBox = new Form2("Input is not valid!");
                    errorBox.ShowDialog();
                }
            }

        }

        private void leftModel(object sender, EventArgs e)
        {
            this.isSelected = false;
            this.clearTextBoxes();
            this.modelNameTextBox.Enabled = true;

            //this.updateTables();
        }
    }
}
