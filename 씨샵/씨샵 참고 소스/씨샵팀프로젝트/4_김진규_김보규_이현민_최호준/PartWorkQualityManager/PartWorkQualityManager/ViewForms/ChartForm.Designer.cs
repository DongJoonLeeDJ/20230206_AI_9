namespace PartWorkQualityManager.Forms
{
    partial class ChartForm
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea5 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend5 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series5 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.button_chart_by_selected_days = new System.Windows.Forms.Button();
            this.button_chart_by_selected_work = new System.Windows.Forms.Button();
            this.button_chart_by_selected_category = new System.Windows.Forms.Button();
            this.button_chart_by_selected_part = new System.Windows.Forms.Button();
            this.button_chart_by_allDays = new System.Windows.Forms.Button();
            this.button_chart_by_work = new System.Windows.Forms.Button();
            this.button_chart_by_category = new System.Windows.Forms.Button();
            this.button_chart_by_part = new System.Windows.Forms.Button();
            this.comboBox_dateList = new System.Windows.Forms.ComboBox();
            this.chart_display = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.button_all_quality = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.chart_display)).BeginInit();
            this.SuspendLayout();
            // 
            // button_chart_by_selected_days
            // 
            this.button_chart_by_selected_days.Location = new System.Drawing.Point(986, 88);
            this.button_chart_by_selected_days.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_selected_days.Name = "button_chart_by_selected_days";
            this.button_chart_by_selected_days.Size = new System.Drawing.Size(397, 30);
            this.button_chart_by_selected_days.TabIndex = 64;
            this.button_chart_by_selected_days.Text = "선택 날로부터 10일간의 불량률 차트";
            this.button_chart_by_selected_days.UseVisualStyleBackColor = true;
            this.button_chart_by_selected_days.Click += new System.EventHandler(this.button_chart_by_selected_days_Click);
            // 
            // button_chart_by_selected_work
            // 
            this.button_chart_by_selected_work.Location = new System.Drawing.Point(1175, 24);
            this.button_chart_by_selected_work.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_selected_work.Name = "button_chart_by_selected_work";
            this.button_chart_by_selected_work.Size = new System.Drawing.Size(172, 56);
            this.button_chart_by_selected_work.TabIndex = 63;
            this.button_chart_by_selected_work.Text = "선택 날짜 기준\r\n공정별 불량률 차트";
            this.button_chart_by_selected_work.UseVisualStyleBackColor = true;
            this.button_chart_by_selected_work.Click += new System.EventHandler(this.button_chart_by_selected_work_Click);
            // 
            // button_chart_by_selected_category
            // 
            this.button_chart_by_selected_category.Location = new System.Drawing.Point(810, 13);
            this.button_chart_by_selected_category.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_selected_category.Name = "button_chart_by_selected_category";
            this.button_chart_by_selected_category.Size = new System.Drawing.Size(181, 67);
            this.button_chart_by_selected_category.TabIndex = 62;
            this.button_chart_by_selected_category.Text = "선택 날짜 기준\r\n유형별 불량률 차트";
            this.button_chart_by_selected_category.UseVisualStyleBackColor = true;
            this.button_chart_by_selected_category.Click += new System.EventHandler(this.button_chart_by_selected_category_Click);
            // 
            // button_chart_by_selected_part
            // 
            this.button_chart_by_selected_part.Location = new System.Drawing.Point(993, 23);
            this.button_chart_by_selected_part.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_selected_part.Name = "button_chart_by_selected_part";
            this.button_chart_by_selected_part.Size = new System.Drawing.Size(176, 57);
            this.button_chart_by_selected_part.TabIndex = 61;
            this.button_chart_by_selected_part.Text = "선택 날짜 기준\r\n부품별 불량률 차트";
            this.button_chart_by_selected_part.UseVisualStyleBackColor = true;
            this.button_chart_by_selected_part.Click += new System.EventHandler(this.button_chart_by_selected_part_Click);
            // 
            // button_chart_by_allDays
            // 
            this.button_chart_by_allDays.Location = new System.Drawing.Point(577, 13);
            this.button_chart_by_allDays.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_allDays.Name = "button_chart_by_allDays";
            this.button_chart_by_allDays.Size = new System.Drawing.Size(225, 34);
            this.button_chart_by_allDays.TabIndex = 60;
            this.button_chart_by_allDays.Text = "전체 날짜별 불량률 차트";
            this.button_chart_by_allDays.UseVisualStyleBackColor = true;
            this.button_chart_by_allDays.Click += new System.EventHandler(this.button_chart_by_allDays_Click);
            // 
            // button_chart_by_work
            // 
            this.button_chart_by_work.Location = new System.Drawing.Point(389, 13);
            this.button_chart_by_work.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_work.Name = "button_chart_by_work";
            this.button_chart_by_work.Size = new System.Drawing.Size(180, 34);
            this.button_chart_by_work.TabIndex = 59;
            this.button_chart_by_work.Text = "공정별 불량률 차트";
            this.button_chart_by_work.UseVisualStyleBackColor = true;
            this.button_chart_by_work.Click += new System.EventHandler(this.button_chart_by_work_Click);
            // 
            // button_chart_by_category
            // 
            this.button_chart_by_category.Location = new System.Drawing.Point(14, 13);
            this.button_chart_by_category.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_category.Name = "button_chart_by_category";
            this.button_chart_by_category.Size = new System.Drawing.Size(182, 34);
            this.button_chart_by_category.TabIndex = 58;
            this.button_chart_by_category.Text = "유형별 불량률 차트";
            this.button_chart_by_category.UseVisualStyleBackColor = true;
            this.button_chart_by_category.Click += new System.EventHandler(this.button_chart_by_category_Click);
            // 
            // button_chart_by_part
            // 
            this.button_chart_by_part.Location = new System.Drawing.Point(204, 13);
            this.button_chart_by_part.Margin = new System.Windows.Forms.Padding(4);
            this.button_chart_by_part.Name = "button_chart_by_part";
            this.button_chart_by_part.Size = new System.Drawing.Size(177, 34);
            this.button_chart_by_part.TabIndex = 57;
            this.button_chart_by_part.Text = "부품별 불량률 차트";
            this.button_chart_by_part.UseVisualStyleBackColor = true;
            this.button_chart_by_part.Click += new System.EventHandler(this.button_chart_by_part_Click);
            // 
            // comboBox_dateList
            // 
            this.comboBox_dateList.DisplayMember = "date_created";
            this.comboBox_dateList.FormattingEnabled = true;
            this.comboBox_dateList.Location = new System.Drawing.Point(810, 92);
            this.comboBox_dateList.Name = "comboBox_dateList";
            this.comboBox_dateList.Size = new System.Drawing.Size(169, 26);
            this.comboBox_dateList.TabIndex = 56;
            this.comboBox_dateList.ValueMember = "date_created";
            // 
            // chart_display
            // 
            chartArea5.AxisX.IntervalAutoMode = System.Windows.Forms.DataVisualization.Charting.IntervalAutoMode.VariableCount;
            chartArea5.AxisX.IsLabelAutoFit = false;
            chartArea5.AxisX.LabelAutoFitMaxFontSize = 7;
            chartArea5.AxisX.LabelAutoFitMinFontSize = 7;
            chartArea5.AxisX.LabelStyle.IsStaggered = true;
            chartArea5.AxisX.MajorGrid.LineColor = System.Drawing.Color.Silver;
            chartArea5.AxisX2.IntervalAutoMode = System.Windows.Forms.DataVisualization.Charting.IntervalAutoMode.VariableCount;
            chartArea5.AxisX2.IsLabelAutoFit = false;
            chartArea5.AxisX2.LabelAutoFitMaxFontSize = 7;
            chartArea5.AxisX2.LabelAutoFitMinFontSize = 7;
            chartArea5.AxisX2.LabelStyle.IsStaggered = true;
            chartArea5.AxisY.MajorGrid.LineColor = System.Drawing.Color.LightGray;
            chartArea5.Name = "ChartArea1";
            this.chart_display.ChartAreas.Add(chartArea5);
            legend5.Docking = System.Windows.Forms.DataVisualization.Charting.Docking.Top;
            legend5.Name = "Legend1";
            this.chart_display.Legends.Add(legend5);
            this.chart_display.Location = new System.Drawing.Point(14, 126);
            this.chart_display.Margin = new System.Windows.Forms.Padding(4);
            this.chart_display.Name = "chart_display";
            series5.ChartArea = "ChartArea1";
            series5.Legend = "Legend1";
            series5.Name = "Series1";
            this.chart_display.Series.Add(series5);
            this.chart_display.Size = new System.Drawing.Size(1796, 869);
            this.chart_display.TabIndex = 65;
            this.chart_display.Text = "chart1";
            // 
            // button_all_quality
            // 
            this.button_all_quality.Location = new System.Drawing.Point(14, 72);
            this.button_all_quality.Margin = new System.Windows.Forms.Padding(4);
            this.button_all_quality.Name = "button_all_quality";
            this.button_all_quality.Size = new System.Drawing.Size(182, 34);
            this.button_all_quality.TabIndex = 66;
            this.button_all_quality.Text = "전체 불량률 차트";
            this.button_all_quality.UseVisualStyleBackColor = true;
            this.button_all_quality.Click += new System.EventHandler(this.button_all_quality_Click);
            // 
            // ChartForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1924, 1050);
            this.Controls.Add(this.button_all_quality);
            this.Controls.Add(this.chart_display);
            this.Controls.Add(this.button_chart_by_selected_days);
            this.Controls.Add(this.button_chart_by_selected_work);
            this.Controls.Add(this.button_chart_by_selected_category);
            this.Controls.Add(this.button_chart_by_selected_part);
            this.Controls.Add(this.button_chart_by_allDays);
            this.Controls.Add(this.button_chart_by_work);
            this.Controls.Add(this.button_chart_by_category);
            this.Controls.Add(this.button_chart_by_part);
            this.Controls.Add(this.comboBox_dateList);
            this.Name = "ChartForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "데이터 차트 출력 화면";
            ((System.ComponentModel.ISupportInitialize)(this.chart_display)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button_chart_by_selected_days;
        private System.Windows.Forms.Button button_chart_by_selected_work;
        private System.Windows.Forms.Button button_chart_by_selected_category;
        private System.Windows.Forms.Button button_chart_by_selected_part;
        private System.Windows.Forms.Button button_chart_by_allDays;
        private System.Windows.Forms.Button button_chart_by_work;
        private System.Windows.Forms.Button button_chart_by_category;
        private System.Windows.Forms.Button button_chart_by_part;
        private System.Windows.Forms.ComboBox comboBox_dateList;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart_display;
        private System.Windows.Forms.Button button_all_quality;
    }
}