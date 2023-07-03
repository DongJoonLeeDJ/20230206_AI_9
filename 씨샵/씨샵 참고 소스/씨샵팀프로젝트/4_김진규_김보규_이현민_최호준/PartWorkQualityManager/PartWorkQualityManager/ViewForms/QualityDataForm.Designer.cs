namespace PartWorkQualityManager.Forms
{
    partial class QualityDataForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.button_read_json = new System.Windows.Forms.Button();
            this.checkBox_only_fileImage = new System.Windows.Forms.CheckBox();
            this.label_file_name = new System.Windows.Forms.Label();
            this.pictureBox_FileImage = new System.Windows.Forms.PictureBox();
            this.button_insert_Quality = new System.Windows.Forms.Button();
            this.textBox_file_name = new System.Windows.Forms.TextBox();
            this.checkBox_quality = new System.Windows.Forms.CheckBox();
            this.comboBox_part = new System.Windows.Forms.ComboBox();
            this.comboBox_work = new System.Windows.Forms.ComboBox();
            this.comboBox_category_id = new System.Windows.Forms.ComboBox();
            this.textBox_real_file_path = new System.Windows.Forms.TextBox();
            this.button_read_file = new System.Windows.Forms.Button();
            this.label_category = new System.Windows.Forms.Label();
            this.label_part = new System.Windows.Forms.Label();
            this.label_work = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label_file_real_path = new System.Windows.Forms.Label();
            this.button_update_Quality = new System.Windows.Forms.Button();
            this.button_delete_Quality = new System.Windows.Forms.Button();
            this.openFileDialog_Quality = new System.Windows.Forms.OpenFileDialog();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_FileImage)).BeginInit();
            this.SuspendLayout();
            // 
            // button_read_json
            // 
            this.button_read_json.Location = new System.Drawing.Point(12, 196);
            this.button_read_json.Name = "button_read_json";
            this.button_read_json.Size = new System.Drawing.Size(197, 29);
            this.button_read_json.TabIndex = 0;
            this.button_read_json.Text = "json 파일 읽기";
            this.button_read_json.UseVisualStyleBackColor = true;
            this.button_read_json.Click += new System.EventHandler(this.button_read_json_Click);
            // 
            // checkBox_only_fileImage
            // 
            this.checkBox_only_fileImage.AutoSize = true;
            this.checkBox_only_fileImage.Location = new System.Drawing.Point(15, 241);
            this.checkBox_only_fileImage.Name = "checkBox_only_fileImage";
            this.checkBox_only_fileImage.Size = new System.Drawing.Size(130, 22);
            this.checkBox_only_fileImage.TabIndex = 1;
            this.checkBox_only_fileImage.Text = "사진만 등록";
            this.checkBox_only_fileImage.UseVisualStyleBackColor = true;
            this.checkBox_only_fileImage.CheckedChanged += new System.EventHandler(this.checkBox_only_fileImage_CheckedChanged);
            // 
            // label_file_name
            // 
            this.label_file_name.AutoSize = true;
            this.label_file_name.Location = new System.Drawing.Point(30, 283);
            this.label_file_name.Name = "label_file_name";
            this.label_file_name.Size = new System.Drawing.Size(62, 18);
            this.label_file_name.TabIndex = 2;
            this.label_file_name.Text = "파일명";
            // 
            // pictureBox_FileImage
            // 
            this.pictureBox_FileImage.Location = new System.Drawing.Point(649, 23);
            this.pictureBox_FileImage.Name = "pictureBox_FileImage";
            this.pictureBox_FileImage.Size = new System.Drawing.Size(1183, 549);
            this.pictureBox_FileImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox_FileImage.TabIndex = 4;
            this.pictureBox_FileImage.TabStop = false;
            // 
            // button_insert_Quality
            // 
            this.button_insert_Quality.Location = new System.Drawing.Point(15, 12);
            this.button_insert_Quality.Name = "button_insert_Quality";
            this.button_insert_Quality.Size = new System.Drawing.Size(170, 29);
            this.button_insert_Quality.TabIndex = 5;
            this.button_insert_Quality.Text = "데이터 등록";
            this.button_insert_Quality.UseVisualStyleBackColor = true;
            this.button_insert_Quality.Click += new System.EventHandler(this.button_insert_Quality_Click);
            // 
            // textBox_file_name
            // 
            this.textBox_file_name.Location = new System.Drawing.Point(101, 280);
            this.textBox_file_name.Name = "textBox_file_name";
            this.textBox_file_name.Size = new System.Drawing.Size(536, 28);
            this.textBox_file_name.TabIndex = 29;
            // 
            // checkBox_quality
            // 
            this.checkBox_quality.AutoSize = true;
            this.checkBox_quality.Location = new System.Drawing.Point(101, 168);
            this.checkBox_quality.Name = "checkBox_quality";
            this.checkBox_quality.Size = new System.Drawing.Size(70, 22);
            this.checkBox_quality.TabIndex = 33;
            this.checkBox_quality.Text = "양품";
            this.checkBox_quality.UseVisualStyleBackColor = true;
            // 
            // comboBox_part
            // 
            this.comboBox_part.FormattingEnabled = true;
            this.comboBox_part.Location = new System.Drawing.Point(104, 93);
            this.comboBox_part.Name = "comboBox_part";
            this.comboBox_part.Size = new System.Drawing.Size(309, 26);
            this.comboBox_part.TabIndex = 32;
            // 
            // comboBox_work
            // 
            this.comboBox_work.FormattingEnabled = true;
            this.comboBox_work.Location = new System.Drawing.Point(104, 125);
            this.comboBox_work.Name = "comboBox_work";
            this.comboBox_work.Size = new System.Drawing.Size(309, 26);
            this.comboBox_work.TabIndex = 31;
            // 
            // comboBox_category_id
            // 
            this.comboBox_category_id.FormattingEnabled = true;
            this.comboBox_category_id.Location = new System.Drawing.Point(104, 61);
            this.comboBox_category_id.Name = "comboBox_category_id";
            this.comboBox_category_id.Size = new System.Drawing.Size(309, 26);
            this.comboBox_category_id.TabIndex = 30;
            // 
            // textBox_real_file_path
            // 
            this.textBox_real_file_path.Location = new System.Drawing.Point(101, 314);
            this.textBox_real_file_path.Name = "textBox_real_file_path";
            this.textBox_real_file_path.Size = new System.Drawing.Size(536, 28);
            this.textBox_real_file_path.TabIndex = 34;
            // 
            // button_read_file
            // 
            this.button_read_file.Location = new System.Drawing.Point(12, 348);
            this.button_read_file.Name = "button_read_file";
            this.button_read_file.Size = new System.Drawing.Size(625, 32);
            this.button_read_file.TabIndex = 35;
            this.button_read_file.Text = "사진 찾기";
            this.button_read_file.UseVisualStyleBackColor = true;
            this.button_read_file.Click += new System.EventHandler(this.button_read_file_Click);
            // 
            // label_category
            // 
            this.label_category.AutoSize = true;
            this.label_category.Location = new System.Drawing.Point(12, 64);
            this.label_category.Name = "label_category";
            this.label_category.Size = new System.Drawing.Size(86, 18);
            this.label_category.TabIndex = 36;
            this.label_category.Text = "불량 유형";
            // 
            // label_part
            // 
            this.label_part.AutoSize = true;
            this.label_part.Location = new System.Drawing.Point(54, 101);
            this.label_part.Name = "label_part";
            this.label_part.Size = new System.Drawing.Size(44, 18);
            this.label_part.TabIndex = 37;
            this.label_part.Text = "부품";
            // 
            // label_work
            // 
            this.label_work.AutoSize = true;
            this.label_work.Location = new System.Drawing.Point(54, 133);
            this.label_work.Name = "label_work";
            this.label_work.Size = new System.Drawing.Size(44, 18);
            this.label_work.TabIndex = 38;
            this.label_work.Text = "공정";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 168);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(86, 18);
            this.label5.TabIndex = 39;
            this.label5.Text = "양품 여부";
            // 
            // label_file_real_path
            // 
            this.label_file_real_path.AutoSize = true;
            this.label_file_real_path.Location = new System.Drawing.Point(12, 317);
            this.label_file_real_path.Name = "label_file_real_path";
            this.label_file_real_path.Size = new System.Drawing.Size(80, 18);
            this.label_file_real_path.TabIndex = 40;
            this.label_file_real_path.Text = "실제경로";
            // 
            // button_update_Quality
            // 
            this.button_update_Quality.Location = new System.Drawing.Point(209, 12);
            this.button_update_Quality.Name = "button_update_Quality";
            this.button_update_Quality.Size = new System.Drawing.Size(170, 29);
            this.button_update_Quality.TabIndex = 41;
            this.button_update_Quality.Text = "데이터 수정";
            this.button_update_Quality.UseVisualStyleBackColor = true;
            this.button_update_Quality.Click += new System.EventHandler(this.button_update_Quality_Click);
            // 
            // button_delete_Quality
            // 
            this.button_delete_Quality.Location = new System.Drawing.Point(403, 12);
            this.button_delete_Quality.Name = "button_delete_Quality";
            this.button_delete_Quality.Size = new System.Drawing.Size(170, 29);
            this.button_delete_Quality.TabIndex = 42;
            this.button_delete_Quality.Text = "데이터 삭제";
            this.button_delete_Quality.UseVisualStyleBackColor = true;
            this.button_delete_Quality.Click += new System.EventHandler(this.button_delete_Quality_Click);
            // 
            // QualityDataForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1924, 627);
            this.Controls.Add(this.button_delete_Quality);
            this.Controls.Add(this.button_update_Quality);
            this.Controls.Add(this.label_file_real_path);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label_work);
            this.Controls.Add(this.label_part);
            this.Controls.Add(this.label_category);
            this.Controls.Add(this.button_read_file);
            this.Controls.Add(this.textBox_real_file_path);
            this.Controls.Add(this.checkBox_quality);
            this.Controls.Add(this.comboBox_part);
            this.Controls.Add(this.comboBox_work);
            this.Controls.Add(this.comboBox_category_id);
            this.Controls.Add(this.textBox_file_name);
            this.Controls.Add(this.button_insert_Quality);
            this.Controls.Add(this.pictureBox_FileImage);
            this.Controls.Add(this.label_file_name);
            this.Controls.Add(this.checkBox_only_fileImage);
            this.Controls.Add(this.button_read_json);
            this.Name = "QualityDataForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "QualityData";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_FileImage)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button_read_json;
        private System.Windows.Forms.CheckBox checkBox_only_fileImage;
        private System.Windows.Forms.Label label_file_name;
        private System.Windows.Forms.PictureBox pictureBox_FileImage;
        private System.Windows.Forms.Button button_insert_Quality;
        private System.Windows.Forms.TextBox textBox_file_name;
        private System.Windows.Forms.CheckBox checkBox_quality;
        private System.Windows.Forms.ComboBox comboBox_part;
        private System.Windows.Forms.ComboBox comboBox_work;
        private System.Windows.Forms.ComboBox comboBox_category_id;
        private System.Windows.Forms.TextBox textBox_real_file_path;
        private System.Windows.Forms.Button button_read_file;
        private System.Windows.Forms.Label label_category;
        private System.Windows.Forms.Label label_part;
        private System.Windows.Forms.Label label_work;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label_file_real_path;
        private System.Windows.Forms.Button button_update_Quality;
        private System.Windows.Forms.Button button_delete_Quality;
        private System.Windows.Forms.OpenFileDialog openFileDialog_Quality;
    }
}