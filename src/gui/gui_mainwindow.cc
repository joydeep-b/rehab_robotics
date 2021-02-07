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
#include <QMediaPlaylist>
#include <QPainter>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <QGroupBox>
#include <QTabWidget>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QDir>
#include <QFileDialog>

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
  QString dir = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"),
      QDir::currentPath(),
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
  QDir directory(dir);
  QStringList files = directory.entryList(QStringList() << "*.mp4" << "*.mov",QDir::Files);
  if (files.length() < 3) {
    fprintf(stderr, "ERROR: not enough videos found!\n");
    exit(1);
  }
  videos_.push_back(dir + "/" + files[0]);
  videos_.push_back(dir + "/" + files[1]);
  videos_.push_back(dir + "/" + files[2]);

  player1 = new QMediaPlayer;
  player2 = new QMediaPlayer;
  player3 = new QMediaPlayer;
  videoWidget1 = new QVideoWidget;
  videoWidget2 = new QVideoWidget;
  videoWidget3 = new QVideoWidget;
  player1->setVideoOutput(videoWidget1);
  player2->setVideoOutput(videoWidget2);
  player3->setVideoOutput(videoWidget3);

  ReloadVideos();
  main_layout_ = new QVBoxLayout(this);
  main_layout_->addWidget(videoWidget1);
  main_layout_->addWidget(videoWidget2);
  main_layout_->addWidget(videoWidget3);
  setLayout(main_layout_);
  
  connect(player1, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));
  connect(player2, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));
  connect(player3, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));
  /*
  When playing, play in full screen?
  How to load new videos Using QDir - load the first three
  
  Check compilation on Windows.
  */
}

void MainWindow::mediaStatusChanged(QMediaPlayer::MediaStatus status) {
  printf("Status changed to %d num video: %d\n", 
  status,
  main_layout_->count());
  if (status == QMediaPlayer::EndOfMedia) {
    ReloadVideos();
    playing_ = false;
  }
}

void MainWindow::toggle() {
  player1->pause();
}

void MainWindow::ReloadVideos() {
  const float h = this->height() / 3.1;
  videoWidget1->setFixedHeight(h);
  videoWidget2->setFixedHeight(h);
  videoWidget3->setFixedHeight(h);
  player1->setMedia(QUrl::fromLocalFile(videos_[0]));
  player2->setMedia(QUrl::fromLocalFile(videos_[1]));
  player3->setMedia(QUrl::fromLocalFile(videos_[2]));
  player1->play();
  player2->play();
  player3->play();
  player1->pause();
  player2->pause();
  player3->pause();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_1) {
    videoWidget1->setFixedHeight(this->height());
    videoWidget2->setFixedHeight(0);
    videoWidget3->setFixedHeight(0);
    player1->play();
    player2->pause();
    player3->pause();
    playing_ = true;
  } else if (event->key() == Qt::Key_2) {
    videoWidget2->setFixedHeight(this->height());
    videoWidget1->setFixedHeight(0);
    videoWidget3->setFixedHeight(0);
    player1->pause();
    player3->pause();
    player2->play();
    playing_ = true;
  } else if (event->key() == Qt::Key_3) {
    videoWidget3->setFixedHeight(this->height());
    videoWidget2->setFixedHeight(0);
    videoWidget1->setFixedHeight(0);
    player1->pause();
    player2->pause();
    player3->play();
    playing_ = true;
  } else if (event->key() == Qt::Key_Escape) {
    this->close();
  } else {
    player1->pause();
    player2->pause();
    player3->pause();
  }
}

void MainWindow::closeWindow() {
  close();
}

void MainWindow::resizeEvent(QResizeEvent * event) {
  const auto w = this->width() / 1.05;
  videoWidget1->setFixedWidth(w);
  videoWidget2->setFixedWidth(w);
  videoWidget3->setFixedWidth(w);
  if (!playing_) {
    const float h = this->height() / 3.1;
    videoWidget1->setFixedHeight(h);
    videoWidget2->setFixedHeight(h);
    videoWidget3->setFixedHeight(h);
  }
}

}  // namespace ut_automata_gui
