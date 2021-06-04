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

namespace NewForm
{
    public partial class Form1 : Form
    {
        SqlConnection dbConn;
        SqlDataAdapter daShips, daPirates;
        DataSet ds;

        BindingSource bsShips, bsPirates;

        SqlCommandBuilder cbPirates;

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            daPirates.Update(ds, "Pirates");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dbConn = new SqlConnection(@"Data Source = DESKTOP-DJP760G; "+
                "Initial Catalog = Northwind; Integrated Security = SSPI");
            ds = new DataSet();

            daShips = new SqlDataAdapter("SELECT * FROM Ships", dbConn);
            daPirates = new SqlDataAdapter("SELECT * FROM Pirates", dbConn);

            cbPirates = new SqlCommandBuilder(daPirates);

            daShips.Fill(ds, "Ships");
            daPirates.Fill(ds, "Pirates");

            DataRelation dr = new DataRelation("FK_Pirates_Ships", ds.Tables["Ships"].Columns["ShipID"], ds.Tables["Pirates"].Columns["ShipID"]);
            //GetChildRows
            //GetParentRow

            ds.Relations.Add(dr);

            Console.WriteLine(ds.Tables["Ships"].Constraints.Count);
            Console.WriteLine(ds.Tables["Pirates"].Constraints.Count);



            bsShips = new BindingSource();
            bsShips.DataSource = ds;
            bsShips.DataMember = "Ships";

            bsPirates = new BindingSource();
            bsPirates.DataSource = bsShips;
            bsPirates.DataMember = "FK_Pirates_Ships";

            dgvShips.DataSource = bsShips;
            dgvPirates.DataSource = bsPirates;
        }

        public Form1()
        {
            InitializeComponent();
        }
    }
}
