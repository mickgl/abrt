/*
    Copyright (C) 2010  ABRT team
    Copyright (C) 2010  RedHat Inc

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
#ifndef CATCUT_H_
#define CATCUT_H_

#include "Plugin.h"
#include "Reporter.h"

class CReporterCatcut : public CReporter
{
    private:
	std::string m_sCatcutURL;
	std::string m_sLogin;
	std::string m_sPassword;
	bool m_bNoSSLVerify;
	int m_nRetryCount;
	int m_nRetryDelay;

    public:
        CReporterCatcut();
        virtual ~CReporterCatcut();

        virtual void SetSettings(const map_plugin_settings_t& pSettings);

        virtual std::string Report(const map_crash_data_t& pCrashData,
                                   const map_plugin_settings_t& pSettings,
                                   const char *Args);
};

#endif /* CATCUT_H_ */
