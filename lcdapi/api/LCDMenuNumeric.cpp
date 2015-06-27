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

#include <lcdapi/api/LCDMenuNumeric.h>

namespace lcdapi {

using namespace std;

LCDMenuNumeric::LCDMenuNumeric(const string &text, LCDElement *parent, const string &id)
    : LCDMenuItem(id, parent, "numeric", text),
    _value(0),
    _minValue(0),
    _maxValue(100)
{
}

LCDMenuNumeric::LCDMenuNumeric(const string &text, const bool &isHidden, const string &next, const string &prev, 
        const unsigned long &value, const unsigned long &minValue, const unsigned long &maxValue, LCDElement *parent, const string &id)
    : LCDMenuItem(id, parent, "numeric", text),
    _value(value),
    _minValue(minValue),
    _maxValue(maxValue)
{
    _isHidden = isHidden;
    _next = next;
    _prev = prev;

    _optionsList["is_hidden"] = (isHidden ? "true" : "false");
    _optionsList["next"] = (next.empty() ? "\"\"" : next);
    _optionsList["prev"] = (prev.empty() ? "\"\"" : prev);
    _optionsList["value"] = LCDUtils::toString(value);
    _optionsList["minvalue"] = LCDUtils::toString(minValue);
    _optionsList["maxvalue"] = LCDUtils::toString(maxValue);
    notifyChanged();
}

bool LCDMenuNumeric::setValue(const unsigned long &value)
{
    unsigned long newValue = 0;

    if (value < _minValue)
    {
        newValue = _minValue;
    }
    else if (value > _maxValue)
    {
        newValue = _maxValue;
    }
    else
    {
        newValue = value;
    }

    _value = newValue;
    _optionsList["value"] = LCDUtils::toString(_value);

    try
    {
        notifyChanged();
    }
    catch (LCDException ex)
    {
        _optionsList.clear();
        return false;
    }

    return true;
}

bool LCDMenuNumeric::setMinValue(const unsigned long &minValue)
{
    if (minValue > _maxValue)
    {
        return false;
    }
    else
    {
        if (_value < minValue)
        {
            _value = minValue;
            _optionsList["value"] = LCDUtils::toString(_value);
        }

        _minValue = minValue;
        _optionsList["minvalue"] = LCDUtils::toString(minValue);

        try
        {
            notifyChanged();
        }
        catch (LCDException ex)
        {
            _optionsList.clear();
            return false;
        }
    }

    return true;
}

bool LCDMenuNumeric::setMaxValue(const unsigned long &maxValue)
{
    if (maxValue < _minValue)
    {
        return false;
    }
    else
    {
        if (_value > maxValue)
        {
            _value = maxValue;
            _optionsList["value"] = LCDUtils::toString(_value);
        }

        _maxValue = maxValue;
        _optionsList["maxvalue"] = LCDUtils::toString(maxValue);

        try
        {
            notifyChanged();
        }
        catch (LCDException ex)
        {
            _optionsList.clear();
            return false;
        }
    }

    return true;
}

} // end of lcdapi namespace
