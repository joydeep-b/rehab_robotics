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

signals:


private:

  // Main layout of the window.
  QHBoxLayout* main_layout_;

};


}  // namespace ut_automata_gui

#endif  // GUI_MAINWINDOW_H
