/*
    Copyright (C) 2009  Abrt team.
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
#ifndef CRASHTYPES_H_
#define CRASHTYPES_H_

#include "abrt_types.h"

// Filenames in dump directory:
// filled by a hook:
#define FILENAME_ANALYZER     "analyzer"
#define FILENAME_EXECUTABLE   "executable"
#define FILENAME_BINARY       "binary"
#define FILENAME_CMDLINE      "cmdline"
#define FILENAME_REASON       "reason"
#define FILENAME_COREDUMP     "coredump"
#define FILENAME_BACKTRACE    "backtrace"
#define FILENAME_MEMORYMAP    "memorymap"
// Used by CCpp analyzer to cache GetGlobalUUID() calls.
#define FILENAME_GLOBAL_UUID    "global_uuid"
// Name of the function where the application crashed.
// Optional.
#define FILENAME_CRASH_FUNCTION "crash_function"
// filled by CDebugDump::Create() (which also fills CD_UID):
#define FILENAME_ARCHITECTURE "architecture"
#define FILENAME_KERNEL       "kernel"
#define FILENAME_TIME         "time"
#define FILENAME_RELEASE      "release"  /* from /etc/redhat-release */
// filled by <what?>
#define FILENAME_PACKAGE      "package"
#define FILENAME_COMPONENT    "component"
#define FILENAME_DESCRIPTION  "description" /* package descr (not crash descr) */
#define FILENAME_COMMENT      "comment"
#define FILENAME_REPRODUCE    "reproduce"
#define FILENAME_RATING       "rating"
#define FILENAME_HOSTNAME     "hostname"
#define FILENAME_TAINTED      "tainted"
// Optional. Set to "1" by abrt-handle-upload for every unpacked crashdump
#define FILENAME_REMOTE       "remote"
// TODO: TicketUploader also has open-coded "TICKET", "CUSTOMER" files

// Apart from CD_UID, which is also stored as a file in dump directory,
// these items only exist in db. (CD_UID is also a file because
// dump directory is created before its DB entry, and DB has to learn
// CD_UID from _somewhere_ in order to be able to store it in DB record,
// right?)
#define CD_UID          "uid"   /* lowercase: compat with older versions */
#define CD_UUID         "UUID"
#define CD_INFORMALL    "InformAll"
#define CD_DUPHASH      "DUPHASH"
#define CD_DUMPDIR      "DumpDir"
#define CD_COUNT        "Count"
#define CD_REPORTED     "Reported"
#define CD_MESSAGE      "Message"


// Crash data is a map of 3-element vectors of strings: type, editable, content
#define CD_TYPE         0
#define CD_EDITABLE     1
#define CD_CONTENT      2

// SYS - system value, should not be displayed
// BIN - binary data
// TXT - text data, can be displayed
#define CD_SYS          "s"
#define CD_BIN          "b"
#define CD_TXT          "t"
// Text bigger than this usually is attached, not added inline
#define CD_TEXT_ATT_SIZE (2*1024)

#define CD_ISEDITABLE    "y"
#define CD_ISNOTEDITABLE "n"


extern const char *const must_have_files[];

bool is_editable_file(const char *file_name);

// <key, data>
typedef map_vector_string_t map_crash_data_t;
typedef std::vector<map_crash_data_t> vector_map_crash_data_t;

void add_to_crash_data_ext(map_crash_data_t& pCrashData,
		const char *pItem,
		const char *pType,
		const char *pEditable,
		const char *pContent);
// Uses type:CD_TXT, editable:CD_ISNOTEDITABLE
void add_to_crash_data(map_crash_data_t& pCrashData,
		const char *pItem,
		const char *pContent);

const char *get_crash_data_item_content_or_NULL(const map_crash_data_t& crash_data, const char *key);
// Aborts if key is not found:
const std::string& get_crash_data_item_content(const map_crash_data_t& crash_data, const char *key);

void log_map_crash_data(const map_crash_data_t& data, const char *name);

#endif