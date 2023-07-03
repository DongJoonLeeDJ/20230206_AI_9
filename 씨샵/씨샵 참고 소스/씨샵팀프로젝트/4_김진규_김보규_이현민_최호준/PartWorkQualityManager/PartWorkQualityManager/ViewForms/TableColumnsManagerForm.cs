using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PartWorkQualityManager.Forms
{
    public partial class TableColumnsManagerForm : Form
    {
        Dictionary<string, object> data = new Dictionary<string, object>();
        DataManager dataManager = DBManager.Instance;
        public TableColumnsManagerForm()
        {
            InitializeComponent();
            dataGridView_Category.DataSource = dataManager.categories;
            dataGridView_PartList.DataSource = dataManager.partLists;
            dataGridView_PartWorkList.DataSource = dataManager.partWorkLists;

            button_insert_Category.Click += ButtonClickEvent;
            button_update_Category.Click += ButtonClickEvent;
            button_delete_Category.Click += ButtonClickEvent;

            button_insert_PartList.Click += ButtonClickEvent;
            button_update_PartList.Click += ButtonClickEvent;
            button_delete_PartList.Click += ButtonClickEvent;

            button_insert_PartWorkList.Click += ButtonClickEvent;
            button_update_PartWorkList.Click += ButtonClickEvent;
            button_delete_PartWorkList.Click += ButtonClickEvent;

            dataGridView_Category.CellClick += DataGridView_Category_CellClick;
            dataGridView_PartList.CellClick += DataGridView_PartList_CellClick;
            dataGridView_PartWorkList.CellClick += DataGridView_PartWorkList_CellClick;

        }

        private void DataGridView_PartWorkList_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            PartWorkList w = (sender as DataGridView).CurrentRow.DataBoundItem as PartWorkList;
            textBox_name_PartWorkList.Text = w.workname; //수정할 값
            label_old_PartWorkList.Text = w.workname;//수정되기 전 값
        }

        private void DataGridView_PartList_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            PartList p = (sender as DataGridView).CurrentRow.DataBoundItem as PartList;
            textBox_name_PartList.Text = p.carPart; //수정할 값
            label_old_PartList.Text = p.carPart;//수정되기 전 값
        }

        private void DataGridView_Category_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            Category c = (sender as DataGridView).CurrentRow.DataBoundItem as Category;
            textBox_id_Category.Text = c.id;
            textBox_name_Category.Text = c.name;
            textBox_supercategory_Category.Text = c.supercategory;
        }

        private void ButtonClickEvent(object sender, EventArgs e)
        {
            //카테고리
            data = new Dictionary<string, object>();
            string[] columns = null;

            string tableName = (sender as Button).Name.Split('_')[2];
            switch (tableName)
            {
                case TableNames.CATEGORY:
                    Category c = new Category();
                    c.id = textBox_id_Category.Text;
                    c.name = textBox_name_Category.Text;
                    c.supercategory = textBox_supercategory_Category.Text;
                    data["data"] = c;
                    columns = new string[] { TableNames.ID, TableNames.NAME, TableNames.SUPERCATEGORY };
                    break;
                case TableNames.PARTLIST:
                    PartList p = new PartList();
                    p.carPart = textBox_name_PartList.Text;
                    data["data"] = p;
                    data["oldData"] = new PartList() { carPart = label_old_PartList.Text };
                    columns = new string[] { TableNames.CARPART };
                    break;
                case TableNames.PARTWORKLIST:
                    PartWorkList w = new PartWorkList();
                    w.workname = textBox_name_PartWorkList.Text;
                    data["data"] = w;
                    data["oldData"] = new PartWorkList() { workname = label_old_PartWorkList.Text };
                    columns = new string[] { TableNames.WORKNAME };
                    break;
                default:
                    break;
            }

            string command = (sender as Button).Name.Split('_')[1];
            data["tablename"] = tableName;
            dataManager.DataManaging(command, columns, data);
            
            switch (tableName)
            {
                case TableNames.CATEGORY:
                    dataGridView_Category.DataSource = null;
                    dataGridView_Category.DataSource = dataManager.categories;
                    break;
                case TableNames.PARTLIST:
                    dataGridView_PartList.DataSource = null;
                    dataGridView_PartList.DataSource = dataManager.partLists;

                    break;
                case TableNames.PARTWORKLIST:
                    dataGridView_PartWorkList.DataSource = null;
                    dataGridView_PartWorkList.DataSource = dataManager.partWorkLists;

                    break;
                default:
                    break;
            }
        }
    }
}
