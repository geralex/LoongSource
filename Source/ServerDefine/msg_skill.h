//-----------------------------------------------------------------------------
// Copyright (c) 2004 TENGWU Entertainment All rights reserved.
// filename: msg_quest.h
// author: 
// actor:
// data: 2008-09-11
// last:
// brief: �������
//-----------------------------------------------------------------------------
#pragma once

#pragma pack(push)
#pragma pack(1)
//-----------------------------------------------------------------------------


#include "role_data_define.h"

//-----------------------------------------------------------------------------
// ���Ӽ���
//-----------------------------------------------------------------------------
CMD_START(NDBC_AddSkill)						// ���Ӽ���
	DWORD			dwRoleID;
	tagSkillSave	Skill;	
CMD_END

//-----------------------------------------------------------------------------
// ���漼��
//-----------------------------------------------------------------------------
CMD_START(NDBC_UpdateSkill)						// ���漼��
	DWORD			dwRoleID;
	tagSkillSave	Skill;	
CMD_END

//-----------------------------------------------------------------------------
// ɾ������
//-----------------------------------------------------------------------------
CMD_START(NDBC_RemoveSkill)
	DWORD			dwRoleID;
	DWORD			dwSkillID;
CMD_END

#pragma pack(pop)