using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp07
{
    public partial class Form3 : Form
    {

        bool FindBook(Book x)
        {
            return x.userId == textBox1.Text;
        }
        public Form3()
        {
            InitializeComponent();
            dataGridView1.DataSource = null;
            if (DataManager.Users.Count > 0)
                dataGridView1.DataSource = DataManager.Users;

            dataGridView1.CellClick += DataGridViewCellClick;

            //람다
            button1.Click += (s, e) =>
            {
                // 반환은 true/false 매개변수는 해당 List의 구성요소
                //여기선 User
                if(DataManager.Users.Exists(x=>x.id==textBox1.Text))
                {
                    MessageBox.Show("해당 ID 이미 있음");
                }
                else
                {
                    User u = new User() {id=textBox1.Text,name=textBox2.Text };
                    DataManager.Users.Add(u);
                    dataGridView1.DataSource = null;
                    dataGridView1.DataSource = DataManager.Users;
                    DataManager.Save();
                }
            };

            //무명 델리게이트
            button2.Click += delegate (object s, EventArgs e)
            {
                try
                {
                    User u = DataManager.Users.Single
                    (x=>x.id==textBox1.Text);
                    u.name = textBox2.Text;
                    try
                    {
                        //Single에 해당하는 게 없으면
                        //바로 catch로 빠지는 특징이 있다.
                        // Book b = DataManager.Books.Single
                        // (x=>x.userId==textBox1.Text);

                        //Book b=DataManager.Books.Single(
                        //delegate (Book x) { return x.userId == textBox1.Text; });

                        Book b = DataManager.Books.Single(FindBook);
                        
                        b.userName = textBox2.Text;
                    }
                    catch (Exception ex)
                    {
                       //MessageBox.Show(ex.Message);
                       //MessageBox.Show(ex.StackTrace);
                       //MessageBox.Show("없는 userId");
                    }
                }
                catch (Exception)
                {
                    MessageBox.Show("없는 ID");
                }
                dataGridView1.DataSource = null;
                dataGridView1.DataSource = DataManager.Users;
                DataManager.Save();

            };

            //EventHandler deleteBtn = delegate(object s, EventArgs e) { }
            EventHandler deleteBtn = (s, e) =>
            {
                try
                {
                    User u = DataManager.Users.Single(
                        x=>x.id==textBox1.Text);
                    DataManager.Users.Remove(u);

                    dataGridView1.DataSource = null; 
                    if(DataManager.Users.Count>0)
                        dataGridView1.DataSource = DataManager.Users;
                    DataManager.Save();
                }
                catch (Exception)
                {

                }
            };
            button3.Click += deleteBtn;
        }

        private void DataGridViewCellClick(object sender, DataGridViewCellEventArgs e)
        {
            User u = 
                (sender as DataGridView).CurrentRow.DataBoundItem as User;
            textBox1.Text = u.id;
            textBox2.Text = u.name;
        }
    }
}
