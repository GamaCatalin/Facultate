using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


using System.Data.SqlClient;
using System.Data;

namespace Attendance
{
    class Program
    {
        static void Main(string[] args)
        {
            //SqlCommand - ExecuteScalar, ExecuteNonQuery, ExecuteReadear
            //SqlDataAdapter - delete/update





            SqlConnectionStringBuilder builder = new SqlConnectionStringBuilder();


            builder["Data Source"] = "(local)";
            builder["Integrated Security"] = true;
            builder["Initial Catalog"] = "AdventureWorks2017;NewValue=Bad";

            

            SqlConnection sqlConnection = new SqlConnection();


            

            sqlConnection.ConnectionString = "Data Source=DESKTOP-DJP760G;Initial Catalog=Car Dealership;Integrated Security=True";
            
            sqlConnection.Open();
            
            DataSet dataSet = new DataSet();

            SqlDataAdapter dataAdapter = new SqlDataAdapter("SELECT * FROM S", sqlConnection);

            dataAdapter.Fill(dataSet, "S");
           

            foreach (DataRow dataRow in dataSet.Tables["S"].Rows)
            {
                Console.WriteLine("{0},{1}", dataRow["ID"], dataRow["ColumnA"]);
            }



            DataRow addedDataRow = dataSet.Tables["S"].NewRow();
            addedDataRow["ID"] = 312;
            addedDataRow["ColumnA"] = "vv";
            dataSet.Tables["S"].Rows.Add(addedDataRow);


            


            foreach (DataRow dataRow in dataSet.Tables["S"].Rows)
            {
                Console.WriteLine("{0},{1}", dataRow["ID"], dataRow["ColumnA"]);
            }



            SqlCommand deleteCommand = new SqlCommand("DELETE FROM S WHERE ID = @ID");
            SqlCommand updateCommand = new SqlCommand("UPDATE S SET ID = @ID, ColumnA = @ColumnA");
            SqlCommand insertCommand = new SqlCommand("INSERT INTO S (ID,ColumnA) VALUES (@ID,@ColumnA)");

            deleteCommand.Parameters.Add("@ID", SqlDbType.Int).Value = 1;
            updateCommand.Parameters.Add("@ID", SqlDbType.Int).Value = 1;
            updateCommand.Parameters.Add("@ColumnA", SqlDbType.VarChar).Value = "Updated Column";
            insertCommand.Parameters.Add("@ID", SqlDbType.Int).Value = 3;
            insertCommand.Parameters.Add("@ColumnA", SqlDbType.VarChar).Value = "Inserted Column";


            dataAdapter.UpdateCommand = updateCommand;
            dataAdapter.DeleteCommand = deleteCommand;
            dataAdapter.InsertCommand = insertCommand;
            dataAdapter.InsertCommand = new SqlCommand("INSERT INTO S (ID,ColumnA) VALUES (@ID,@ColumnA)", sqlConnection);

            dataAdapter.Update(dataSet, "S");

            foreach (DataRow dataRow in dataSet.Tables["S"].Rows)
            {
                Console.WriteLine("{0},{1}", dataRow["ID"], dataRow["ColumnA"]);
            }




            sqlConnection.Close();





        }
    }
}
