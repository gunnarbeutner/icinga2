/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2014 Icinga Development Team (http://www.icinga.org)    *
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

#include "base/gc.hpp"

using namespace icinga;

void GC::Initialize(void)
{
	static bool init_called = false;

	if (!init_called) {
#ifdef I2_DEBUG
		GC_set_find_leak(1);
#endif /* I2_DEBUG */

		GC_init();
		GC_allow_register_threads();
		GC_disable();

		init_called = true;
	}
}

static void GCThreadBase(const boost::function<void (void)>& callback)
{
	struct GC_stack_base stack_base;

	GC_get_stack_base(&stack_base);
	GC_register_my_thread(&stack_base);
	callback();
	GC_unregister_my_thread();
}

boost::function<void (void)> GC::WrapThread(const boost::function<void (void)>& callback)
{
	return std::bind(GCThreadBase, callback);
}

