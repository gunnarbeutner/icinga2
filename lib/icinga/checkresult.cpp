/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2018 Icinga Development Team (https://www.icinga.com/)  *
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

#include "icinga/checkresult.hpp"
#include "icinga/checkresult-ti.cpp"
#include "base/scriptglobal.hpp"

using namespace icinga;

REGISTER_TYPE(CheckResult);

INITIALIZE_ONCE([]() {
	ScriptGlobal::Set("Constants.ServiceOK", ServiceOK);
	ScriptGlobal::Set("Constants.ServiceWarning", ServiceWarning);
	ScriptGlobal::Set("Constants.ServiceCritical", ServiceCritical);
	ScriptGlobal::Set("Constants.ServiceUnknown", ServiceUnknown);

	ScriptGlobal::Set("Constants.HostUp", HostUp);
	ScriptGlobal::Set("Constants.HostDown", HostDown);
})

double CheckResult::CalculateExecutionTime() const
{
	return GetExecutionEnd() - GetExecutionStart();
}

double CheckResult::CalculateLatency() const
{
	double latency = (GetScheduleEnd() - GetScheduleStart()) - CalculateExecutionTime();

	if (latency < 0)
		latency = 0;

	return latency;
}
