namespace PartWorkQualityManager
{
    partial class MainForm
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.menu_manager = new System.Windows.Forms.MenuStrip();
            this.데이터등록ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.개별등록ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.일괄등록ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.항목관리ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.초기화ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.차트출력ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.button20 = new System.Windows.Forms.Button();
            this.chart_display = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.dataGridView_QualityManager = new System.Windows.Forms.DataGridView();
            this.dataGridView_FileImage = new System.Windows.Forms.DataGridView();
            this.textBox_file_name = new System.Windows.Forms.TextBox();
            this.button_name_search = new System.Windows.Forms.Button();
            this.button_chart_by_selected_category = new System.Windows.Forms.Button();
            this.button_chart_by_selected_part = new System.Windows.Forms.Button();
            this.button_chart_by_allDays = new System.Windows.Forms.Button();
            this.button_chart_by_work = new System.Windows.Forms.Button();
            this.button_chart_by_category = new System.Windows.Forms.Button();
            this.button_chart_by_part = new System.Windows.Forms.Button();
            this.comboBox_dateList = new System.Windows.Forms.ComboBox();
            this.qualityManagerBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.label_qualityManager = new System.Windows.Forms.Label();
            this.label_FileImage = new System.Windows.Forms.Label();
            this.comboBox_categories = new System.Windows.Forms.ComboBox();
            this.label_category = new System.Windows.Forms.Label();
            this.label_date = new System.Windows.Forms.Label();
            this.button_chart_by_selected_work = new System.Windows.Forms.Button();
            this.button_chart_by_selected_days = new System.Windows.Forms.Button();
            this.folderBrowserDialog_QualityData = new System.Windows.Forms.FolderBrowserDialog();
            this.menu_manager.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart_display)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_QualityManager)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_FileImage)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.qualityManagerBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // menu_manager
            // 
            this.menu_manager.GripMargin = new System.Windows.Forms.Padding(2, 2, 0, 2);
            this.menu_manager.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menu_manager.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.데이터등록ToolStripMenuItem,
            this.항목관리ToolStripMenuItem,
            this.초기화ToolStripMenuItem,
            this.차트출력ToolStripMenuItem});
            this.menu_manager.Location = new System.Drawing.Point(0, 0);
            this.menu_manager.Name = "menu_manager";
            this.menu_manager.Size = new System.Drawing.Size(1924, 33);
            this.menu_manager.TabIndex = 0;
            this.menu_manager.Text = "메뉴";
            // 
            // 데이터등록ToolStripMenuItem
            // 
            this.데이터등록ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.개별등록ToolStripMenuItem,
            this.일괄등록ToolStripMenuItem});
            this.데이터등록ToolStripMenuItem.Name = "데이터등록ToolStripMenuItem";
            this.데이터등록ToolStripMenuItem.Size = new System.Drawing.Size(106, 29);
            this.데이터등록ToolStripMenuItem.Text = "품질 관리";
            // 
            // 개별등록ToolStripMenuItem
            // 
            this.개별등록ToolStripMenuItem.Name = "개별등록ToolStripMenuItem";
            this.개별등록ToolStripMenuItem.Size = new System.Drawing.Size(270, 34);
            this.개별등록ToolStripMenuItem.Text = "개별 등록";
            this.개별등록ToolStripMenuItem.Click += new System.EventHandler(this.개별등록ToolStripMenuItem_Click);
            // 
            // 일괄등록ToolStripMenuItem
            // 
            this.일괄등록ToolStripMenuItem.Name = "일괄등록ToolStripMenuItem";
            this.일괄등록ToolStripMenuItem.Size = new System.Drawing.Size(270, 34);
            this.일괄등록ToolStripMenuItem.Text = "일괄 등록";
            this.일괄등록ToolStripMenuItem.Click += new System.EventHandler(this.일괄등록ToolStripMenuItem_Click);
            // 
            // 항목관리ToolStripMenuItem
            // 
            this.항목관리ToolStripMenuItem.Name = "항목관리ToolStripMenuItem";
            this.항목관리ToolStripMenuItem.Size = new System.Drawing.Size(106, 29);
            this.항목관리ToolStripMenuItem.Text = "항목 관리";
            this.항목관리ToolStripMenuItem.Click += new System.EventHandler(this.항목관리ToolStripMenuItem_Click);
            // 
            // 초기화ToolStripMenuItem
            // 
            this.초기화ToolStripMenuItem.Name = "초기화ToolStripMenuItem";
            this.초기화ToolStripMenuItem.Size = new System.Drawing.Size(82, 29);
            this.초기화ToolStripMenuItem.Text = "초기화";
            this.초기화ToolStripMenuItem.Click += new System.EventHandler(this.초기화ToolStripMenuItem_Click);
            // 
            // 차트출력ToolStripMenuItem
            // 
            this.차트출력ToolStripMenuItem.Name = "차트출력ToolStripMenuItem";
            this.차트출력ToolStripMenuItem.Size = new System.Drawing.Size(106, 29);
            this.차트출력ToolStripMenuItem.Text = "차트 출력";
            this.차트출력ToolStripMenuItem.Click += new System.EventHandler(this.차트출력ToolStripMenuItem_Click);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(-307, 31);
            this.textBox2.Margin = new System.Windows.Forms.Padding(4);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(199, 28);
            this.textBox2.TabIndex = 34;
            // 
            // button20
            // 
            this.button20.Location = new System.Drawing.Point(-436, 25);
            this.button20.Margin = new System.Windows.Forms.Padding(4);
            this.button20.Name = "button20";
            this.button20.Size = new System.Drawing.Size(107, 34);
            this.button20.TabIndex = 33;
            this.button20.Text = "파일명검색";
            this.button20.UseVisualStyleBackColor = true;
            // 
            // chart_display
            // 
            chartArea2.AxisX.IntervalAutoMode = System.Windows.Forms.DataVisualization.Charting.IntervalAutoMode.VariableCount;
            chartArea2.AxisX.IsLabelAutoFit = false;
            chartArea2.AxisX.LabelAutoFitMaxFontSize = 7;
            chartArea2.AxisX.LabelAutoFitMinFontSize = 7;
            chartArea2.AxisX.LabelStyle.IsStaggered = true;
            chartArea2.AxisX.MajorGrid.LineColor = System.Drawing.Color.Silver;
            chartArea2.AxisX2.IntervalAutoMode = System.Windows.Forms.DataVisualization.Charting.IntervalAutoMode.VariableCount;
            chartArea2.AxisX2.IsLabelAutoFit = false;
            chartArea2.AxisX2.LabelAutoFitMaxFontSize = 7;
            chartArea2.AxisX2.LabelAutoFitMinFontSize = 7;
            chartArea2.AxisX2.LabelStyle.IsStaggered = true;
            chartArea2.AxisY.MajorGrid.LineColor = System.Drawing.Color.LightGray;
            chartArea2.Name = "ChartArea1";
            this.chart_display.ChartAreas.Add(chartArea2);
            legend2.Docking = System.Windows.Forms.DataVisualization.Charting.Docking.Top;
            legend2.Name = "Legend1";
            this.chart_display.Legends.Add(legend2);
            this.chart_display.Location = new System.Drawing.Point(13, 671);
            this.chart_display.Margin = new System.Windows.Forms.Padding(4);
            this.chart_display.Name = "chart_display";
            series2.ChartArea = "ChartArea1";
            series2.Legend = "Legend1";
            series2.Name = "Series1";
            this.chart_display.Series.Add(series2);
            this.chart_display.Size = new System.Drawing.Size(1796, 283);
            this.chart_display.TabIndex = 31;
            this.chart_display.Text = "chart1";
            // 
            // dataGridView_QualityManager
            // 
            this.dataGridView_QualityManager.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView_QualityManager.Location = new System.Drawing.Point(14, 178);
            this.dataGridView_QualityManager.Name = "dataGridView_QualityManager";
            this.dataGridView_QualityManager.RowHeadersWidth = 62;
            this.dataGridView_QualityManager.RowTemplate.Height = 30;
            this.dataGridView_QualityManager.Size = new System.Drawing.Size(1796, 232);
            this.dataGridView_QualityManager.TabIndex = 35;
            this.dataGridView_QualityManager.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_QualityManager_CellClick);
            this.dataGridView_QualityManager.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_QualityManager_CellDoubleClick);
            // 
            // dataGridView_FileImage
            // 
            this.dataGridView_FileImage.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView_FileImage.Location = new System.Drawing.Point(13, 442);
            this.dataGridView_FileImage.Name = "dataGridView_FileImage";
            this.dataGridView_FileImage.RowHeadersWidth = 62;
            this.dataGridView_FileImage.RowTemplate.Height = 30;
            this.dataGridView_FileImage.Size = new System.Drawing.Size(1796, 222);
            this.dataGridView_FileImage.TabIndex = 36;
            this.dataGridView_FileImage.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_FileImage_CellClick);
            this.dataGridView_FileImage.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_FileImage_CellDoubleClick);
            // 
            // textBox_file_name
            // 
            this.textBox_file_name.Location = new System.Drawing.Point(129, 90);
            this.textBox_file_name.Margin = new System.Windows.Forms.Padding(4);
            this.textBox_file_name.Name = "textBox_file_name";
            this.textBox_file_name.Size = new System.Drawing.Size(574, 28);
            this.textBox_file_name.TabIndex = 48;
            // 
            // button_name_search
            // 
            this.button_name_search.Location = new System.Drawing.Point(14, 85);
            this.button_name_search.Margin = new System.Windows.Forms.Padding(4);
            this.button_name_search.Name = "button_name_search";
            this.button_name_search.Size = new System.Drawing.Size(107, 34);
            this.button_name_search.TabIndex = 47;
            this.button_name_search.Text = "파일명검색";
            this.button_name_search.UseVisualStyleBackColor = true;
            this.button_name_search.Click += new System.EventHandler(this.button_name_search_Click);
            // 
            // button_chart_by_selected_category
            // 
            this.button_chart_by_selected_category.Location = new System.Drawing.Point(1059, 49);
            this.button_chart_by_selected_category.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_selected_category.Name = "button_chart_by_selected_category";
            this.button_chart_by_selected_category.Size = new System.Drawing.Size(181, 67);
            this.button_chart_by_selected_category.TabIndex = 46;
            this.button_chart_by_selected_category.Text = "선택 날짜 기준\r\n유형별 불량률 차트";
            this.button_chart_by_selected_category.UseVisualStyleBackColor = true;
            this.button_chart_by_selected_category.Click += new System.EventHandler(this.button_chart_by_selected_category_Click);
            // 
            // button_chart_by_selected_part
            // 
            this.button_chart_by_selected_part.Location = new System.Drawing.Point(1242, 59);
            this.button_chart_by_selected_part.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_selected_part.Name = "button_chart_by_selected_part";
            this.button_chart_by_selected_part.Size = new System.Drawing.Size(176, 57);
            this.button_chart_by_selected_part.TabIndex = 45;
            this.button_chart_by_selected_part.Text = "선택 날짜 기준\r\n부품별 불량률 차트";
            this.button_chart_by_selected_part.UseVisualStyleBackColor = true;
            this.button_chart_by_selected_part.Click += new System.EventHandler(this.button_chart_by_selected_part_Click);
            // 
            // button_chart_by_allDays
            // 
            this.button_chart_by_allDays.Location = new System.Drawing.Point(576, 49);
            this.button_chart_by_allDays.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_allDays.Name = "button_chart_by_allDays";
            this.button_chart_by_allDays.Size = new System.Drawing.Size(225, 34);
            this.button_chart_by_allDays.TabIndex = 43;
            this.button_chart_by_allDays.Text = "전체 날짜별 불량률 차트";
            this.button_chart_by_allDays.UseVisualStyleBackColor = true;
            this.button_chart_by_allDays.Click += new System.EventHandler(this.button_chart_by_allDays_Click);
            // 
            // button_chart_by_work
            // 
            this.button_chart_by_work.Location = new System.Drawing.Point(388, 49);
            this.button_chart_by_work.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_work.Name = "button_chart_by_work";
            this.button_chart_by_work.Size = new System.Drawing.Size(180, 34);
            this.button_chart_by_work.TabIndex = 42;
            this.button_chart_by_work.Text = "공정별 불량률 차트";
            this.button_chart_by_work.UseVisualStyleBackColor = true;
            this.button_chart_by_work.Click += new System.EventHandler(this.button_chart_by_work_Click);
            // 
            // button_chart_by_category
            // 
            this.button_chart_by_category.Location = new System.Drawing.Point(13, 49);
            this.button_chart_by_category.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_category.Name = "button_chart_by_category";
            this.button_chart_by_category.Size = new System.Drawing.Size(182, 34);
            this.button_chart_by_category.TabIndex = 41;
            this.button_chart_by_category.Text = "유형별 불량률 차트";
            this.button_chart_by_category.UseVisualStyleBackColor = true;
            this.button_chart_by_category.Click += new System.EventHandler(this.button_chart_by_category_Click);
            // 
            // button_chart_by_part
            // 
            this.button_chart_by_part.Location = new System.Drawing.Point(203, 49);
            this.button_chart_by_part.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_part.Name = "button_chart_by_part";
            this.button_chart_by_part.Size = new System.Drawing.Size(177, 34);
            this.button_chart_by_part.TabIndex = 40;
            this.button_chart_by_part.Text = "부품별 불량률 차트";
            this.button_chart_by_part.UseVisualStyleBackColor = true;
            this.button_chart_by_part.Click += new System.EventHandler(this.button_chart_by_part_Click);
            // 
            // comboBox_dateList
            // 
            this.comboBox_dateList.DataSource = this.qualityManagerBindingSource;
            this.comboBox_dateList.DisplayMember = "date_created";
            this.comboBox_dateList.FormattingEnabled = true;
            this.comboBox_dateList.Location = new System.Drawing.Point(1059, 123);
            this.comboBox_dateList.Name = "comboBox_dateList";
            this.comboBox_dateList.Size = new System.Drawing.Size(169, 26);
            this.comboBox_dateList.TabIndex = 39;
            this.comboBox_dateList.ValueMember = "date_created";
            // 
            // qualityManagerBindingSource
            // 
            this.qualityManagerBindingSource.DataSource = typeof(PartWorkQualityManager.QualityManager);
            // 
            // label_qualityManager
            // 
            this.label_qualityManager.AutoSize = true;
            this.label_qualityManager.Location = new System.Drawing.Point(22, 157);
            this.label_qualityManager.Name = "label_qualityManager";
            this.label_qualityManager.Size = new System.Drawing.Size(146, 18);
            this.label_qualityManager.TabIndex = 49;
            this.label_qualityManager.Text = "품질 데이터 목록";
            // 
            // label_FileImage
            // 
            this.label_FileImage.AutoSize = true;
            this.label_FileImage.Location = new System.Drawing.Point(22, 421);
            this.label_FileImage.Name = "label_FileImage";
            this.label_FileImage.Size = new System.Drawing.Size(104, 18);
            this.label_FileImage.TabIndex = 50;
            this.label_FileImage.Text = "이미지 목록";
            // 
            // comboBox_categories
            // 
            this.comboBox_categories.Enabled = false;
            this.comboBox_categories.FormattingEnabled = true;
            this.comboBox_categories.Location = new System.Drawing.Point(799, 90);
            this.comboBox_categories.Name = "comboBox_categories";
            this.comboBox_categories.Size = new System.Drawing.Size(166, 26);
            this.comboBox_categories.TabIndex = 51;
            // 
            // label_category
            // 
            this.label_category.AutoSize = true;
            this.label_category.Location = new System.Drawing.Point(710, 93);
            this.label_category.Name = "label_category";
            this.label_category.Size = new System.Drawing.Size(86, 18);
            this.label_category.TabIndex = 52;
            this.label_category.Text = "불량 유형";
            // 
            // label_date
            // 
            this.label_date.AutoSize = true;
            this.label_date.Location = new System.Drawing.Point(1009, 131);
            this.label_date.Name = "label_date";
            this.label_date.Size = new System.Drawing.Size(44, 18);
            this.label_date.TabIndex = 53;
            this.label_date.Text = "날짜";
            // 
            // button_chart_by_selected_work
            // 
            this.button_chart_by_selected_work.Location = new System.Drawing.Point(1424, 60);
            this.button_chart_by_selected_work.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_selected_work.Name = "button_chart_by_selected_work";
            this.button_chart_by_selected_work.Size = new System.Drawing.Size(172, 56);
            this.button_chart_by_selected_work.TabIndex = 54;
            this.button_chart_by_selected_work.Text = "선택 날짜 기준\r\n공정별 불량률 차트";
            this.button_chart_by_selected_work.UseVisualStyleBackColor = true;
            this.button_chart_by_selected_work.Click += new System.EventHandler(this.button_chart_by_selected_work_Click);
            // 
            // button_chart_by_selected_days
            // 
            this.button_chart_by_selected_days.Location = new System.Drawing.Point(1242, 119);
            this.button_chart_by_selected_days.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_selected_days.Name = "button_chart_by_selected_days";
            this.button_chart_by_selected_days.Size = new System.Drawing.Size(397, 30);
            this.button_chart_by_selected_days.TabIndex = 55;
            this.button_chart_by_selected_days.Text = "선택 날로부터 10일간의 불량률 차트";
            this.button_chart_by_selected_days.UseVisualStyleBackColor = true;
            this.button_chart_by_selected_days.Click += new System.EventHandler(this.button_chart_by_selected_days_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1924, 1050);
            this.Controls.Add(this.button_chart_by_selected_days);
            this.Controls.Add(this.button_chart_by_selected_work);
            this.Controls.Add(this.label_date);
            this.Controls.Add(this.label_category);
            this.Controls.Add(this.comboBox_categories);
            this.Controls.Add(this.label_FileImage);
            this.Controls.Add(this.label_qualityManager);
            this.Controls.Add(this.textBox_file_name);
            this.Controls.Add(this.button_name_search);
            this.Controls.Add(this.button_chart_by_selected_category);
            this.Controls.Add(this.button_chart_by_selected_part);
            this.Controls.Add(this.button_chart_by_allDays);
            this.Controls.Add(this.button_chart_by_work);
            this.Controls.Add(this.button_chart_by_category);
            this.Controls.Add(this.button_chart_by_part);
            this.Controls.Add(this.comboBox_dateList);
            this.Controls.Add(this.dataGridView_FileImage);
            this.Controls.Add(this.dataGridView_QualityManager);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.button20);
            this.Controls.Add(this.chart_display);
            this.Controls.Add(this.menu_manager);
            this.MainMenuStrip = this.menu_manager;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "KB 품질 관리 프로그램";
            this.menu_manager.ResumeLayout(false);
            this.menu_manager.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart_display)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_QualityManager)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_FileImage)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.qualityManagerBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menu_manager;
        private System.Windows.Forms.ToolStripMenuItem 데이터등록ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 개별등록ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 항목관리ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 일괄등록ToolStripMenuItem;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button button20;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart_display;
        private System.Windows.Forms.DataGridView dataGridView_QualityManager;
        private System.Windows.Forms.DataGridView dataGridView_FileImage;
        private System.Windows.Forms.TextBox textBox_file_name;
        private System.Windows.Forms.Button button_name_search;
        private System.Windows.Forms.Button button_chart_by_selected_category;
        private System.Windows.Forms.Button button_chart_by_selected_part;
        private System.Windows.Forms.Button button_chart_by_allDays;
        private System.Windows.Forms.Button button_chart_by_work;
        private System.Windows.Forms.Button button_chart_by_category;
        private System.Windows.Forms.Button button_chart_by_part;
        private System.Windows.Forms.ComboBox comboBox_dateList;
        private System.Windows.Forms.Label label_qualityManager;
        private System.Windows.Forms.Label label_FileImage;
        private System.Windows.Forms.ToolStripMenuItem 초기화ToolStripMenuItem;
        private System.Windows.Forms.ComboBox comboBox_categories;
        private System.Windows.Forms.Label label_category;
        private System.Windows.Forms.Label label_date;
        private System.Windows.Forms.Button button_chart_by_selected_work;
        private System.Windows.Forms.Button button_chart_by_selected_days;
        private System.Windows.Forms.BindingSource qualityManagerBindingSource;
        private System.Windows.Forms.ToolStripMenuItem 차트출력ToolStripMenuItem;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog_QualityData;
    }
}