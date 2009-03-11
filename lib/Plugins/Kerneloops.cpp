/*
 * Copyright 2009, Red Hat Inc.
 *
 * This file is part of %TBD%
 *
 * This program file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program in a file named COPYING; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * Authors:
 *      Anton Arapov <anton@redhat.com>
 */

#include "DebugDump.h"
#include "DynamicLibrary.h"

#include <ctype.h>
#include <sstream>

#include "Kerneloops.h"
#include "KerneloopsDmesg.h"

std::string CApplicationKerneloops::GetLocalUUID(const std::string& pDebugDumpDir)
{
	std::string m_sOops;
	std::stringstream m_sHash;
	CDebugDump dd;
	dd.Open(pDebugDumpDir);
	dd.LoadText(FILENAME_TEXTDATA1, m_sOops);

	/* An algorithm proposed by Donald E. Knuth in The Art Of Computer
	 * Programming Volume 3, under the topic of sorting and search
	 * chapter 6.4.
	 */
	unsigned int m_nHash = static_cast<unsigned int>(m_sOops.length());
	for(std::size_t i = 0; i < m_sOops.length(); i++)
	{
		m_nHash = ((m_nHash << 5) ^ (m_nHash >> 27)) ^ m_sOops[i];
	}
	m_sHash << (m_nHash & 0x7FFFFFFF);

	return m_sHash.str();
}

std::string CApplicationKerneloops::GetGlobalUUID(const std::string& pDebugDumpDir)
{
	return GetLocalUUID(pDebugDumpDir);
}

void CApplicationKerneloops::Init()
{
	scan_logs();
}
