/* Copyright 2012-2015 Joshua Whitley <maximus5684@gmail.com> / Simon Dawson <spdawson@gmail.com>

   This file is file is part of lcdapi.

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

#ifndef _LCDAPI_API_LCDMENUNUMERIC_H_
#define _LCDAPI_API_LCDMENUNUMERIC_H_

#include <lcdapi/api/LCDMenuItem.h>
#include <lcdapi/api/LCDUtils.h>
#include <lcdapi/api/LCDException.h>

namespace lcdapi {

/** \class LCDMenuNumeric LCDMenuNumeric.h "api/LCDMenuNumeric.h"
 *  \brief A MenuItem to create a numeric menu entry.
 *  \ingroup menuitems
 *  This widget is used to create numeric menu entries.
 */
class LCDMenuNumeric : public LCDMenuItem
{
    private:
        unsigned long _value, _minValue, _maxValue;
    public:
        /**
         * \brief Default Constructor.
         *
         * This constructor can be used without paramer in most cases 
         * but the widget will have to be added to a parent LCDMenu.
         * @param text The visible text of the menu entry. Due to a bug in LCDd, this is required in all constructors.
         * @param parent A pointer to the parent of this menu item. Must be either an LCDClient for the main menu or an LCDMenu for a submenu.
         * @param id A string that uniquely identifies this menu entry.
         */
        explicit LCDMenuNumeric(const std::string &text = "", LCDElement *parent = 0, const std::string &id = "");

        /**
         * \brief Constructor with default options specified.
         *
         * This constructor initializes the menu item with all of the available parameters.
         * @param text The visible text of the menu entry. Due to a bug in LCDd, this is required in all constructors.
         * @param isHidden Whether this menu item should be hidden or not.
         * @param next The id of the LCDMenuItem that should be shown when the user presses the Next button while this item is selected.
         * @param prev The id of the LCDMenuItem that should be shown when the user presses the Previous button while this item is selected.
         * @param value The initial numeric value of the menu entry.
         * @param minValue The minimum allowed value for the menu entry.
         * @param maxValue The maximum allowed value for the menu entry.
         * @param parent A pointer to the parent of this menu item. Must be either an LCDClient for the main menu or an LCDMenu for a submenu.
         * @param id A string that uniquely identifies this menu entry.
         */
        explicit LCDMenuNumeric(const std::string &text = "", const bool &isHidden = false, const std::string &next = "", const std::string &prev = "",
                const unsigned long &value = 0, const unsigned long &minValue = 0, const unsigned long &maxValue = 100, LCDElement *parent = 0, const std::string &id = "");

        /**
         * \brief Sets the value of the numeric menu entry.
         *
         * Sets the value of the numeric menu entry. Returns true if the set succeeded (was within min/max, no errors) and false if it failed.
         * @param value The new value for the menu entry.
         */
        bool setValue(const unsigned long &value);

        /**
         * \brief Sets the minimum value for the numeric menu entry.
         *
         * Sets the minimum value for the numeric menu entry. If the current value is less than the new minimum value, the current value is set to the new minimum.
         * Returns true if the set succeeded (min was not greater than max, no errors) and false if it failed.
         * @param minValue The new minimum value for the menu entry.
         */
        bool setMinValue(const unsigned long &minValue);

        /**
         * \brief Sets the maximum value for the numeric menu entry.
         *
         * Sets the maximum value for the numeric menu entry. If the current value is greater than the new maximum value, the current value is set to the new maximum.
         * Returns true if the set succeeded (max was not less than min, no errors) and false if it failed.
         * @param maxValue The new maximum value for the menu entry.
         */
        bool setMaxValue(const unsigned long &maxValue);
};

} // end lcdapi namespace

#endif
