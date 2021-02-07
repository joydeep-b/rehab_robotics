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
\file    gui_mainwindow.h
\brief   GUI for F1/10 car.
\author  Joydeep Biswas, (C) 2019
*/
//========================================================================

#ifndef GUI_MAINWINDOW_H
#define GUI_MAINWINDOW_H

#include <string>
#include <vector>
#include <QBrush>
#include <QFrame>
#include <QPainter>
#include <QWidget>
#include <QMediaPlayer>
#include <QVBoxLayout>
#include <QString>

class QLabel;
class QHBoxLayout;
class QTabWidget;

namespace vector_display {
class VectorDisplay;
}  // namespace vector_display

namespace ut_automata_gui {

class MainWindow : public QWidget {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);

public slots:
  void closeWindow();
  void toggle();
  void mediaStatusChanged(QMediaPlayer::MediaStatus status);

signals:


protected:
  void keyPressEvent(QKeyEvent *event);
  void resizeEvent(QResizeEvent * event);

private:
  // QHBoxLayout* main_layout_;
  QVBoxLayout* main_layout_;
  std::vector<QString> videos_;
  void ReloadVideos();
  bool playing_ = false;
};


}  // namespace ut_automata_gui

#endif  // GUI_MAINWINDOW_H
