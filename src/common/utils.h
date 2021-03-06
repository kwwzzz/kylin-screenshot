/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>
           2020 KylinSoft Co., Ltd.
 Modified by:
   huanhuan zhang <zhanghuanhuan@kylinos.cn>
This file is part of Kylin-Screenshot.
Kylin-Screenshot is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
Kylin-Screenshot is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with Kylin-Screenshot.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef UTILS_H
#define UTILS_H

#include "src/core/Global.h"
#include <QApplication>

std::vector<QRect> GetScreenGeometries();

QRect CombineScreenGeometries(const std::vector<QRect>& screen_geometries);

// This does some sanity checking on the rubber band rectangle before creating it.
// Rubber bands with width or height zero or extremely large appear to cause problems.
QRect ValidateRubberBandRectangle(QRect rect);

QRect MapToLogicalCoordinates(const QRect& rect);

QPoint GetMousePhysicalCoordinates();

// Tries to find the real window that corresponds to a top-level window (the actual window without window manager decorations).
// Returns None if it can't find the window (probably because the window is not handled by the window manager).
// Based on the xprop source code (http://cgit.freedesktop.org/xorg/app/xprop/tree/clientwin.c).
Window X11FindRealWindow(Display* display, Window window);

QString GetNewSegmentFile(const QString& file, bool add_timestamp);

QString ReadableTime(int64_t time_micro);

QString ReadableWidthHeight(unsigned int width, unsigned int height);

QString ReadableSizeIEC(uint64_t size, const QString& suffix);

QString ReadableSizeSI(uint64_t size, const QString& suffix);

#endif // UTILS_H
