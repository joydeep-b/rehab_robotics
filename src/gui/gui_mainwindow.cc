//========================================================================
//  This software is free: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License Version 3,
//  as published by the Free Software Foundation.
//
//  This software is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  Version 3 in the file COPYING that came with this distribution.
//  If not, see <http://www.gnu.org/licenses/>.
//========================================================================
/*!
\file    gui_mainwindow.cc
\brief   GUI for F1/10 car.
\author  Joydeep Biswas, (C) 2019
*/
//========================================================================

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#include "gui_mainwindow.h"

#include <string>
#include <vector>

#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <QGroupBox>
#include <QTabWidget>

using std::string;
using std::vector;

namespace ut_automata_gui {


MainWindow::MainWindow(QWidget* parent) :
    main_layout_(nullptr) {

  // QPushButton* close_button = new QPushButton("Close");
  // close_button->setFocusPolicy(Qt::NoFocus);
  // close_button->setFixedHeight(60);
  // QHBoxLayout* top_bar = new QHBoxLayout();
  // font.setPointSize(20);
  // ipaddr_label_ = new QLabel();
  // ipaddr_label_->setWordWrap(true);
  // status_label_ = new QLabel("Mode: Autonomous\nBattery: 0V");
  // status_label_->setFont(font);
  // status_label_->setAlignment(Qt::AlignHCenter);
  // top_bar->addWidget(ipaddr_label_);
  // top_bar->addStretch();
  // top_bar->addWidget(status_label_);
  // top_bar->addStretch();
  // top_bar->addWidget(close_button);

  // tab_widget_ = new QTabWidget();
  // font.setPointSize(20);
  // tab_widget_->setFont(font);
  // {
  //   QWidget* ros_group = new QWidget();
  //   QSizePolicy expanding_policy;
  //   expanding_policy.setVerticalPolicy(QSizePolicy::Expanding);
  //   expanding_policy.setHorizontalPolicy(QSizePolicy::Expanding);
  //   QPushButton* start_ros = new QPushButton("Start roscore");
  //   QPushButton* stop_ros = new QPushButton("Stop roscore");
  //   QPushButton* start_car = new QPushButton("Start Car");
  //   QPushButton* stop_all = new QPushButton("Stop all nodes");
  //   start_ros->setFont(font);
  //   stop_ros->setFont(font);
  //   start_car->setFont(font);
  //   stop_all->setFont(font);
  //   start_ros->setSizePolicy(expanding_policy);
  //   stop_ros->setSizePolicy(expanding_policy);
  //   start_car->setSizePolicy(expanding_policy);
  //   stop_all->setSizePolicy(expanding_policy);
  //   connect(start_car, SIGNAL(clicked()), this, SLOT(StartCar()));
  //   connect(start_ros, SIGNAL(clicked()), this, SLOT(StartRos()));
  //   connect(stop_ros, SIGNAL(clicked()), this, SLOT(StopRos()));
  //   connect(stop_all, SIGNAL(clicked()), this, SLOT(StopAll()));
  //   QVBoxLayout* vbox = new QVBoxLayout();
  //   vbox->addWidget(start_ros);
  //   vbox->addWidget(stop_ros);
  //   vbox->addWidget(start_car);
  //   vbox->addWidget(stop_all);
  //   ros_group->setLayout(vbox);
    
  //   // Grid layout
  //   QWidget* main_widget = new QWidget();
  //   ros_led_ = new StatusLed("ROS");
  //   drive_led_ = new StatusLed("Drive");
  //   lidar_led_ = new StatusLed("LIDAR");
  //   camera_led_ = new StatusLed("Camera");
  //   throttle_status_ = new RealStatus(false);
  //   steering_status_ = new RealStatus(true);

  //   QGridLayout* main_layout = new QGridLayout();
  //   main_layout->addWidget(robot_label_, 0, 0, 4, 4);
  //   main_layout->addWidget(ros_led_, 0, 5, 1, 1);
  //   main_layout->addWidget(drive_led_, 0, 6, 1, 1);
  //   main_layout->addWidget(lidar_led_, 1, 5, 1, 1);
  //   main_layout->addWidget(camera_led_, 1, 6, 1, 1);
  //   main_layout->addWidget(throttle_status_, 0, 7, 3, 1);
  //   main_layout->addWidget(steering_status_, 3, 5, 1, 3);
  //   main_widget->setLayout(main_layout);

  //   tab_widget_->addTab(main_widget, "Main");
  //   tab_widget_->addTab(ros_group, tr("Startup / Shutdown"));
  // }

  main_layout_ = new QHBoxLayout(this);
  setLayout(main_layout_);
  // main_layout_->addWidget(tab_widget_);

}


void MainWindow::closeWindow() {
  close();
}



}  // namespace ut_automata_gui
