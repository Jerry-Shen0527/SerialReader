#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow), d_s_v_(serial_reader_.raw_data_), d_v_a_(d_s_v_.data_), chart_plotter_s_("Angle"),
	chart_plotter_v_("angular velocity"),
	chart_plotter_a_("Angular acceleration"),
	chart_plotter_s_a_("Angle to Angular acceleration")
{
	ui->setupUi(this);

	connect(&serial_reader_, &SerialReader::sig, this, &MainWindow::update);
	connect(ui->Begin_button, &QPushButton::clicked, this, [this] {read = true; });
	connect(ui->Stop_button, &QPushButton::clicked, this, [this] {read = false; });

	connect(ui->Clear_button, &QPushButton::clicked, this, [this] {clear(); });

	connect(ui->num_of_gaps, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [this] {set_gpr(); });
	connect(ui->OpenPort, &QPushButton::clicked, this, [this] {serial_reader_.init(ui->plainTextEdit->toPlainText()); ui->checkBox->setCheckState(Qt::Checked); });

	connect(ui->actionSave_raw_data, &QAction::triggered, this, [this] {std::ofstream out(".\\result.txt");
	for (auto raw_data : serial_reader_.raw_data_)
	{
		out << std::to_string(raw_data.x()) << ' ' << std::to_string(raw_data.y()) << '\n';
	}
	out.close();
		});
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::update()
{
	//ui->lcdNumber->display(serial_reader_.top());
	if (read)
	{
		chart_plotter_s_.update(serial_reader_.raw_data_);
		chart_plotter_s_.draw(ui->graphicsView);

		d_s_v_.update();

		chart_plotter_v_.update(d_s_v_.data_);
		chart_plotter_v_.draw(ui->graphicsView_2);

		d_v_a_.update();

		chart_plotter_a_.update(d_v_a_.data_);
		chart_plotter_a_.draw(ui->graphicsView_3);

		if (serial_reader_.raw_data_.size() >= 3)
		{
			while (count < d_v_a_.data_.size())
			{
				s_to_a_.emplace_back(serial_reader_.raw_data_[count].y(), d_v_a_.data_[count].y());
				count++;
			}
		}

		chart_plotter_s_a_.update(s_to_a_);
		chart_plotter_s_a_.draw(ui->graphicsView_4);
	}
}

void MainWindow::clear()
{
	chart_plotter_s_.clear();
	chart_plotter_v_.clear();
	chart_plotter_a_.clear();
	chart_plotter_s_a_.clear();

	d_s_v_.clear();
	d_v_a_.clear();

	s_to_a_.clear();

	serial_reader_.clear();

	count = 1;
	time_begin_ = 0;
	read = false;
}

void MainWindow::set_gpr()
{
	serial_reader_.set_gpr(ui->num_of_gaps->value());
}