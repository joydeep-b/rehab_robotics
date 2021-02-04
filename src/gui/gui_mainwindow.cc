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
#include <QMediaPlayer>
#include <QPainter>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <QGroupBox>
#include <QTabWidget>
#include <QVideoWidget>
#include <QKeyEvent>

using std::string;
using std::vector;

QMediaPlayer* player1;
QMediaPlayer* player2;
QMediaPlayer* player3;
QVideoWidget* videoWidget1;
QVideoWidget* videoWidget2;
QVideoWidget* videoWidget3;

namespace ut_automata_gui {


MainWindow::MainWindow(QWidget* parent) :
    main_layout_(nullptr) {

  player1 = new QMediaPlayer;
  player2 = new QMediaPlayer;
  player3 = new QMediaPlayer;
  videoWidget1 = new QVideoWidget;
  videoWidget2 = new QVideoWidget;
  videoWidget3 = new QVideoWidget;
  // videoWidget3->setAutoOrientation(true);
  player1->setVideoOutput(videoWidget1);
  player2->setVideoOutput(videoWidget2);
  player3->setVideoOutput(videoWidget3);
  player1->setMedia(QUrl::fromLocalFile("/home/joydeepb/projects/rehab_robotics/media/1.mp4"));
  player2->setMedia(QUrl::fromLocalFile("/home/joydeepb/projects/rehab_robotics/media/2.mp4"));
  player3->setMedia(QUrl::fromLocalFile("/home/joydeepb/projects/rehab_robotics/media/3.mp4"));
  main_layout_ = new QHBoxLayout(this);
  main_layout_->addWidget(videoWidget1);
  main_layout_->addWidget(videoWidget2);
  main_layout_->addWidget(videoWidget3);
  setLayout(main_layout_);
  player1->setMuted(true);
  player2->setMuted(true);
  player3->setMuted(true);
  player1->play();
  player2->play();
  player3->play();
  player1->pause();
  player2->pause();
  player3->pause();
  // main_layout_->addWidget(tab_widget_);
  // connect(this, SIGNAL(keyPressEvent()), this, SLOT(toggle()));
  /*
  Three-button to four-button choices, triggered by one key per video.
  Have a preview keyframe
  After the video finishes, go back to preview keyframes
  Check and rotate video orientation from metadata
  Check compilation on Windows.
  */
}

void MainWindow::toggle() {
  player1->pause();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_1) {
    player1->play();
    player2->pause();
    player3->pause();
  } else if (event->key() == Qt::Key_2) {
    player1->pause();
    player3->pause();
    player2->play();
  } else if (event->key() == Qt::Key_3) {
    player1->pause();
    player2->pause();
    player3->play();
  } else {
    player1->pause();
    player2->pause();
    player3->pause();
  }
}

void MainWindow::closeWindow() {
  close();
}



}  // namespace ut_automata_gui
