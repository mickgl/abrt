/*
    Copyright (C) 2009  Zdenek Prikryl (zprikryl@redhat.com)
    Copyright (C) 2009  RedHat inc.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include "Plugin.h"

CPlugin::CPlugin() {}

/* class CPlugin's virtuals */
CPlugin::~CPlugin() {}
void CPlugin::Init() {}
void CPlugin::DeInit() {}
void CPlugin::SetSettings(const map_plugin_settings_t& pSettings)
{
    m_pSettings = pSettings;
}

const map_plugin_settings_t& CPlugin::GetSettings()
{
    return m_pSettings;
}
