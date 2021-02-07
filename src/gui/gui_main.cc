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
\file    gui_main.cc
\brief   GUI for F1/10 car.
\author  Joydeep Biswas, (C) 2019
*/
//========================================================================

#include <pthread.h>

#include <string>
#include <vector>
#include <signal.h>
#include <QApplication>
#include <QPushButton>
#include <QMetaType>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>

#include "gui_mainwindow.h"
#include "shared/util/timer.h"

void Test() {
  QMediaPlayer *player;
  QVideoWidget *videoWidget;
  QMediaPlaylist *playlist;

  player = new QMediaPlayer;

  playlist = new QMediaPlaylist(player);
  playlist->addMedia(QUrl::fromLocalFile("/home/joydeepb/projects/rehab_robotics/media/4.mp4"));
  playlist->addMedia(QUrl::fromLocalFile("/home/joydeepb/projects/rehab_robotics/media/5.mp4"));
  playlist->addMedia(QUrl::fromLocalFile("/home/joydeepb/projects/rehab_robotics/media/6.mp4"));
  playlist->setCurrentIndex(0);
  player->setPlaylist(playlist);
  videoWidget = new QVideoWidget;
  player->setVideoOutput(videoWidget);

  videoWidget->show();
  player->play();
}

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  // Test();
  ut_automata_gui::MainWindow main_window;
  // main_window.show();
  main_window.showFullScreen();
  return app.exec();
}
