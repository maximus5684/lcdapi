/* Copyright 2012-2013 Simon Dawson <spdawson@gmail.com>

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

#include <lcdapi/api/LCDMutex.h>

namespace lcdapi {

using namespace std;

LCDMutex::LCDMutex()
  : _mutex(), _owner(static_cast<pthread_t>(-1))
{
  ::pthread_mutex_init(&_mutex, 0);
}

LCDMutex::~LCDMutex()
{
  ::pthread_mutex_destroy(&_mutex);
}

void LCDMutex::lock()
{
  if (_owner != ::pthread_self())
  {
    ::pthread_mutex_lock(&_mutex);
    _owner = ::pthread_self();
  }
}

void LCDMutex::unlock()
{
  _owner = static_cast<pthread_t>(-1);
  ::pthread_mutex_unlock(&_mutex);
}

} // end of lcdapi namespace
