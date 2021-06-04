using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;
using Car_Dealership.Domain;


namespace Car_Dealership
{
    class SQLController
    {
        private String connectionString = "Data Source=DESKTOP-DJP760G;Initial Catalog=Car Dealership;Integrated Security=True";

        public SQLController()
        {

        }

        public SqlConnection getConnection()
        {
            SqlConnection sqlConnection = new SqlConnection(this.connectionString);

            return sqlConnection;
        }
            
        public DataSet getManufacturers()
        {
            using (SqlConnection sqlConnection = this.getConnection())
            {
                SqlDataAdapter dataAdapter = new SqlDataAdapter();

                dataAdapter.SelectCommand = new SqlCommand("SELECT * FROM MANUFACTURERS;",sqlConnection);

                DataSet dataSet = new DataSet();

                dataAdapter.Fill(dataSet);

                return dataSet;
            }
        }

        public DataSet getModels()
        {
            using (SqlConnection sqlConnection = this.getConnection())
            {
                SqlDataAdapter dataAdapter = new SqlDataAdapter();

                dataAdapter.SelectCommand = new SqlCommand("SELECT * FROM MODELS;", sqlConnection);

                DataSet dataSet = new DataSet();

                dataAdapter.Fill(dataSet);

                return dataSet;
            }
        }

        public void addModel(Model model)
        {
            using (SqlConnection sqlConnection = this.getConnection())
            {
                sqlConnection.Open();

                SqlCommand addCommand = new SqlCommand("INSERT INTO MODELS(modelName, manufacturerName, categoryId, description)" +
                    " VALUES (@modelName, @manufacturerName, @categoryId, @description);", sqlConnection);

                addCommand.Parameters.Add("@modelName", SqlDbType.VarChar, 20);
                addCommand.Parameters.Add("@manufacturerName", SqlDbType.VarChar, 50);
                addCommand.Parameters.Add("@categoryId", SqlDbType.TinyInt);
                addCommand.Parameters.Add("@description", SqlDbType.VarChar, 100);

                addCommand.Parameters["@modelName"].Value = model.modelName;
                addCommand.Parameters["@manufacturerName"].Value = model.manufacturerName;
                addCommand.Parameters["@categoryId"].Value = model.categoryId;
                addCommand.Parameters["@description"].Value = model.description;

                addCommand.ExecuteNonQuery();

                sqlConnection.Close();
            }
        }

        public void updateModel(Model model)
        {
            using (SqlConnection sqlConnection = this.getConnection())
            {
                sqlConnection.Open();

                SqlCommand updateCommand = new SqlCommand("UPDATE MODELS " +
                    "SET categoryId = @categoryId, description = @description " +
                    "WHERE modelName = @modelName;", sqlConnection);

                updateCommand.Parameters.Add("@modelName", SqlDbType.VarChar, 20);
                updateCommand.Parameters.Add("@manufacturerName", SqlDbType.VarChar, 50);
                updateCommand.Parameters.Add("@categoryId", SqlDbType.TinyInt);
                updateCommand.Parameters.Add("@description", SqlDbType.VarChar, 100);

                updateCommand.Parameters["@modelName"].Value = model.modelName;
                updateCommand.Parameters["@manufacturerName"].Value = model.manufacturerName;
                updateCommand.Parameters["@categoryId"].Value = model.categoryId;
                updateCommand.Parameters["@description"].Value = model.description;

                updateCommand.ExecuteNonQuery();

                sqlConnection.Close();
            }
        }

        public void deleteModel(Model model)
        {
            using (SqlConnection sqlConnection = this.getConnection())
            {
                sqlConnection.Open();

                SqlCommand deleteCommand = new SqlCommand("DELETE FROM MODELS " +
                    "WHERE modelName = @modelName;", sqlConnection);

                deleteCommand.Parameters.Add("@modelName", SqlDbType.VarChar, 20);
                

                deleteCommand.Parameters["@modelName"].Value = model.modelName;
                

                deleteCommand.ExecuteNonQuery();

                sqlConnection.Close();
            }
        }
    }
}
