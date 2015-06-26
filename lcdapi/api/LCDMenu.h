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

#ifndef _LCDAPI_API_LCDMENU_H_
#define _LCDAPI_API_LCDMENU_H_

#include <lcdapi/api/LCDMenuItem.h>

namespace lcdapi {

/** \class LCDMenu LCDMenu.h "api/LCDMenu.h"
 *  \brief A MenuItem to create a new menu.
 *  \ingroup menuitems
 *  This widget is used to create new menus or submenus.
 */
class LCDMenu : public LCDMenuItem
{
    public:
        /**
         * \brief Default Constructor.
         *
         * This constructor can be used without paramer in most cases 
         * but the widget will have to be added to a parent (LCDClient or LCDMenu).
         * @param text The visible text of the menu. Due to a bug in LCDd, this is required in all constructors.
         * @param parent A pointer to the parent of this menu. It should be either an LCDClient for the main menu or another LCDMenu for a submenu.
         * @param id A string that uniquely identifies this menu. If not provided, the empty string is assumed (making this the main menu).
         */
        explicit LCDMenu(const std::string &text = "", LCDElement *parent = 0, const std::string &id = "");

        /**
         * \brief Constructor with default options specified.
         *
         * This constructor initializes the menu with all of the available parameters.
         * @param text The visible text of the menu. Due to a bug in LCDd, this is required in all constructors.
         * @param isHidden Whether this menu should be hidden or not.
         * @param next The id of the LCDMenuItem that should be shown when the user presses the Next button while this item is selected.
         * @param prev The id of the LCDMenuItem that should be shown when the user presses the Previous button while this item is selected.
         * @param parent A pointer to the parent of this menu. It should be either an LCDClient for the main menu or another LCDMenu for a submenu.
         * @param id A string that uniquely identifies this menu. If not provided, the empty string is assumed (making this the main menu).
         */
        explicit LCDMenu(const std::string &text = "", const bool &isHidden = false, const std::string &next = "", const std::string &prev = "", LCDElement *parent = 0, const std::string &id = "");
};

} // end lcdapi namespace

#endif
