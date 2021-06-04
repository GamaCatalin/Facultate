using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using Newtonsoft.Json;

namespace Car_Dealership
{
    public partial class Lab2Form : Form
    {

        SqlConnection dbConnection;
        SqlDataAdapter daParent, daChild;
        DataSet ds;

        BindingSource bsParent, bsChild;

        SqlCommandBuilder cbChild;

        string parentTableName="";
        string childTableName="";
        string fkString="";
        string linkingId = "";

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                daChild.Update(ds, this.childTableName);
                MessageBox.Show("Changes saved Successfully!");
            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.Message);
            }
        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            try
            {
                this.refreshConnection();
                //Refresh connection!
                MessageBox.Show("Connection refreshed!");
            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.Message);
            }
        }

        public Lab2Form()
        {
            InitializeComponent();
        }


        private void refreshConnection()
        {
            dbConnection = new SqlConnection(@"Data Source = DESKTOP-DJP760G; " +
                "Initial Catalog = Car Dealership; Integrated Security = SSPI");
            ds = new DataSet();


            daParent = new SqlDataAdapter("SELECT * FROM "+this.parentTableName, dbConnection);
            daChild = new SqlDataAdapter("SELECT * FROM " + this.childTableName, dbConnection);

            cbChild = new SqlCommandBuilder(daChild);

            daParent.Fill(ds, this.parentTableName);
            daChild.Fill(ds, this.childTableName);


            DataRelation dr = new DataRelation(this.fkString, ds.Tables[this.parentTableName].Columns[this.linkingId], ds.Tables[this.childTableName].Columns[this.linkingId]);


            ds.Relations.Add(dr);


            bsParent = new BindingSource();
            bsParent.DataSource = ds;
            bsParent.DataMember = this.parentTableName;

            bsChild = new BindingSource();
            bsChild.DataSource = bsParent;
            bsChild.DataMember = this.fkString;

            parentDataGridView.DataSource = bsParent;
            childDataGridView.DataSource = bsChild;
        }


        void readConfig()
        {

            string dirPath = Directory.GetParent(Environment.CurrentDirectory).Parent.FullName;
            string cfgPath = dirPath + "\\jsconfig1.json";


            JsonTextReader reader = new JsonTextReader(new StreamReader(cfgPath));
            ;
            reader.Read();


            //Read parent Name
            reader.Read();
            parentTableName = reader.ReadAsString();
            Console.WriteLine(this.parentTableName);


            //Read child name
            reader.Read();
            childTableName = reader.ReadAsString();
            Console.WriteLine(this.childTableName);


            //Read relation column name
            reader.Read();
            linkingId = reader.ReadAsString();
            Console.WriteLine(this.linkingId);


            this.fkString = "";
            this.fkString = "FK_" + this.childTableName + "_" + this.parentTableName;

        }


        private void Lab2Form_Load(object sender, EventArgs e)
        {
            readConfig();
            this.refreshConnection();
            this.labelChild.Text = this.childTableName;
            this.labelParent.Text = this.parentTableName;
        }
    }
}
