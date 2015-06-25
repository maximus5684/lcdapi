/* Copyright 2012-2015 Joshua Whitley <maximus5684@gmail.com> / Simon Dawson <spdawson@gmail.com>

   This file is part of lcdapi.

   lcdapi is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation, either version 3 of
   the License, or (at your option) any later version.

   lcdapi is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with lcdapi.  If not,
   see <http://www.gnu.org/licenses/>. */

#include <lcdapi/api/LCDMenu.h>

namespace lcdapi {

using namespace std;

LCDMenu::LCDMenu(LCDElement *parent, const string &id) : LCDMenuItem(id, parent, "menu")
{
}

LCDMenu::LCDMenu(const string &text, const bool &isHidden, const string &next, const string &prev, LCDElement *parent, const string &id)
    : LCDMenuItem(id, parent, "menu")
{
    _text = text;
    _isHidden = isHidden;
    _next = next;
    _prev = prev;

    _optionsList["text"] = text;
    _optionsList["is_hidden"] = (isHidden ? "true" : "false");
    _optionsList["next"] = next;
    _optionsList["prev"] = prev;
    notifyChanged();
}

} // end of lcdapi namespace
