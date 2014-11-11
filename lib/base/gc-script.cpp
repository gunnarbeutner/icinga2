/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2015 Icinga Development Team (http://www.icinga.org)    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#include "base/dictionary.hpp"
#include "base/function.hpp"
#include "base/functionwrapper.hpp"
#include "base/scriptframe.hpp"
#include "base/initialize.hpp"
#include "base/gc.hpp"

using namespace icinga;

static Dictionary::Ptr l_GCObj;

static void GCCollect(void)
{
	GC_enable();
	GC_gcollect();
	GC_disable();

	l_GCObj->Set("heap", GC_get_heap_size());
	l_GCObj->Set("free", GC_get_free_bytes());
	l_GCObj->Set("total", GC_get_total_bytes());
}

static void InitializeGCObj(void)
{
	l_GCObj = new Dictionary();

	/* Methods */
	l_GCObj->Set("collect", new Function("GC#collect", GCCollect));
	l_GCObj->Set("heap", 0);
	l_GCObj->Set("free", 0);
	l_GCObj->Set("total", 0);

	ScriptGlobal::Set("GC", l_GCObj);
}

INITIALIZE_ONCE(InitializeGCObj);

