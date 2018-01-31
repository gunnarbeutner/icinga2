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

#include "db_ido/dbquery.hpp"
#include "base/initialize.hpp"
#include "base/scriptglobal.hpp"

using namespace icinga;

INITIALIZE_ONCE(&DbQuery::StaticInitialize);

std::map<String, int> DbQuery::m_CategoryFilterMap;

void DbQuery::StaticInitialize()
{
	ScriptGlobal::Set("Constants.DbCatConfig", DbCatConfig);
	ScriptGlobal::Set("Constants.DbCatState", DbCatState);
	ScriptGlobal::Set("Constants.DbCatAcknowledgement", DbCatAcknowledgement);
	ScriptGlobal::Set("Constants.DbCatComment", DbCatComment);
	ScriptGlobal::Set("Constants.DbCatDowntime", DbCatDowntime);
	ScriptGlobal::Set("Constants.DbCatEventHandler", DbCatEventHandler);
	ScriptGlobal::Set("Constants.DbCatExternalCommand", DbCatExternalCommand);
	ScriptGlobal::Set("Constants.DbCatFlapping", DbCatFlapping);
	ScriptGlobal::Set("Constants.DbCatCheck", DbCatCheck);
	ScriptGlobal::Set("Constants.DbCatLog", DbCatLog);
	ScriptGlobal::Set("Constants.DbCatNotification", DbCatNotification);
	ScriptGlobal::Set("Constants.DbCatProgramStatus", DbCatProgramStatus);
	ScriptGlobal::Set("Constants.DbCatRetention", DbCatRetention);
	ScriptGlobal::Set("Constants.DbCatStateHistory", DbCatStateHistory);

	ScriptGlobal::Set("Constants.DbCatEverything", DbCatEverything);

	m_CategoryFilterMap["DbCatConfig"] = DbCatConfig;
	m_CategoryFilterMap["DbCatState"] = DbCatState;
	m_CategoryFilterMap["DbCatAcknowledgement"] = DbCatAcknowledgement;
	m_CategoryFilterMap["DbCatComment"] = DbCatComment;
	m_CategoryFilterMap["DbCatDowntime"] = DbCatDowntime;
	m_CategoryFilterMap["DbCatEventHandler"] = DbCatEventHandler;
	m_CategoryFilterMap["DbCatExternalCommand"] = DbCatExternalCommand;
	m_CategoryFilterMap["DbCatFlapping"] = DbCatFlapping;
	m_CategoryFilterMap["DbCatCheck"] = DbCatCheck;
	m_CategoryFilterMap["DbCatLog"] = DbCatLog;
	m_CategoryFilterMap["DbCatNotification"] = DbCatNotification;
	m_CategoryFilterMap["DbCatProgramStatus"] = DbCatProgramStatus;
	m_CategoryFilterMap["DbCatRetention"] = DbCatRetention;
	m_CategoryFilterMap["DbCatStateHistory"] = DbCatStateHistory;
	m_CategoryFilterMap["DbCatEverything"] = DbCatEverything;
}

const std::map<String, int>& DbQuery::GetCategoryFilterMap()
{
	return m_CategoryFilterMap;
}
