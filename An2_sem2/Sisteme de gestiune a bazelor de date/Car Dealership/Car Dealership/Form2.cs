using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Car_Dealership
{
    public partial class Form2 : Form
    {
        String errorMessage;

        public Form2(String message)
        {
            this.errorMessage = message;

            InitializeComponent();
        }

        private void exitForm(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            this.label1.Text = this.errorMessage;
        }
    }
}
