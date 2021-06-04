using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Car_Dealership
{
    public partial class UpdatedLab1Form : Form
    {
        SqlConnection dbConnection;
        SqlDataAdapter daManufacturers, daModels;
        DataSet ds;

        BindingSource bsManufacturers, bsModels;

        SqlCommandBuilder cbModels;

        public UpdatedLab1Form()
        {
            InitializeComponent();
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            daModels.Update(ds, "Models");
        }

        private void UpdatedLab1Form_Load(object sender, EventArgs e)
        {
            dbConnection = new SqlConnection(@"Data Source = DESKTOP-DJP760G; " +
                "Initial Catalog = Car Dealership; Integrated Security = SSPI");
            ds = new DataSet();

            daManufacturers = new SqlDataAdapter("SELECT * FROM MANUFACTURERS", dbConnection);
            daModels = new SqlDataAdapter("SELECT * FROM MODELS", dbConnection);

            cbModels = new SqlCommandBuilder(daModels);

            daManufacturers.Fill(ds, "MANUFACTURERS");
            daModels.Fill(ds, "MODELS");

            DataRelation dr = new DataRelation("FK_MODELS_MANUFACTURERS", ds.Tables["MANUFACTURERS"].Columns["manufacturerName"], ds.Tables["MODELS"].Columns["manufacturerName"]);


            ds.Relations.Add(dr);


            bsManufacturers = new BindingSource();
            bsManufacturers.DataSource = ds;
            bsManufacturers.DataMember = "MANUFACTURERS";

            bsModels = new BindingSource();
            bsModels.DataSource = bsManufacturers;
            bsModels.DataMember = "FK_MODELS_MANUFACTURERS";

            manufacturersDataGridView.DataSource = bsManufacturers;
            modelsDataGridView.DataSource = bsModels;
        }
    }
}
