//-------------------------------------------------------------------------------
// Copyright (c) 2004 TENGWU Entertainment All rights reserved.
// filename: quest.h
// actor:
// data: 2008-9-1
// last:
// brief: ������
//-------------------------------------------------------------------------------
#pragma once
#include "..\WorldDefine\script_data.h"

struct tagQuestProto;
class Role;
class QuestScript;

class Quest:public ScriptData<ESD_Quest>
{
public:
	//----------------------------------------------------------------------------
	// Constructor&Destructor
	//----------------------------------------------------------------------------
	Quest();
	~Quest();

	//----------------------------------------------------------------------------
	// ��ʼ��
	//----------------------------------------------------------------------------
	VOID Init(const tagQuestProto* pQuest, Role* pRole, INT nIndex);
	VOID Init(const tagQuestSave* pQuestSave, Role* pRole, INT nIndex);

	//----------------------------------------------------------------------------
	// �¼�
	//----------------------------------------------------------------------------
	VOID OnAccept(Creature* pNPC);
	VOID OnComplete(Creature* pNPC);
	VOID OnCancel();

	//----------------------------------------------------------------------------
	// ����
	//----------------------------------------------------------------------------
	VOID Destroy();

	//----------------------------------------------------------------------------
	// ����
	//----------------------------------------------------------------------------
	VOID InitQuestSave(OUT tagQuestSave* pQuestSave);

	//----------------------------------------------------------------------------
	// ������Ϣ�ṹ
	//----------------------------------------------------------------------------
	VOID GenerateMsgInfo(tagIncompleteQuestMsgInfo* pInfo, DWORD &dwMsgSize, DWORD &dwQuestSize);

	//----------------------------------------------------------------------------
	// �õ������ʼ��Ʒ
	//----------------------------------------------------------------------------
	VOID GetInitQuestItem(INT16* const n16ItemCount);

	//----------------------------------------------------------------------------
	// �õ�����̬Ŀ��
	//----------------------------------------------------------------------------
	VOID GetInitDynamicTarget(tagQuestDynamicTarget* pInfo, DWORD &dwSize);

	//----------------------------------------------------------------------------
	// ����Get
	//----------------------------------------------------------------------------
	const tagQuestProto*	GetProto()			{ return m_pProto; }
	UINT16					GetID()				{ return P_VALID(m_pProto) ? m_pProto->id : GT_INVALID; }
	DWORD					GetAcceptTime()		{ return m_dwStartTime; }
	INT						GetIndex()			{ return m_nIndex; }
	tagQuestDynamicTarget*	GetDynamicTarget()	{ return m_pDynamicTarget; }

	BOOL					IsValid()			{ return P_VALID(m_pProto); }

	//----------------------------------------------------------------------------
	// ���������Ʒ�Ƿ��Ѿ�����
	//----------------------------------------------------------------------------
	BOOL					IsQuestItemFull(DWORD dwItemTypeID);

	//----------------------------------------------------------------------------
	// ����Set
	//----------------------------------------------------------------------------
	VOID					SetProto(const tagQuestProto* pQuestProto) { m_pProto = pQuestProto; }
	VOID					SetOwner(Role* pRole) { m_pOwner = pRole; }
	VOID					SetCompleteMark(BOOL bComplete) { m_bComplete = bComplete; }

	//----------------------------------------------------------------------------
	// �Ƿ�������
	//----------------------------------------------------------------------------
	BOOL IsCanComplete(INT nChoiceItemIndex, Creature* pNPC=NULL);

	//----------------------------------------------------------------------------
	// �����¼�
	//----------------------------------------------------------------------------
	VOID OnEvent(EQuestEvent eQuestType, DWORD dwEventMisc1=0, DWORD dwEventMisc2=0, DWORD dwEventMisc3=0);

	//----------------------------------------------------------------------------
	// ɱ���¼�
	//----------------------------------------------------------------------------
	VOID OnEventCreatureKill(DWORD dwCreatureTypeID, INT nCreatureLevel);

	//----------------------------------------------------------------------------
	// ��Ʒ�¼�
	//----------------------------------------------------------------------------
	VOID OnEventItem(DWORD dwItemTypeID, INT nNum, BOOL bAdd);

	//----------------------------------------------------------------------------
	// NPC�Ի��¼�
	//----------------------------------------------------------------------------
	VOID OnEventNPCTalk(DWORD dwNPCID, DWORD dwNPCTypeID);

	//----------------------------------------------------------------------------
	// �������¼�
	//----------------------------------------------------------------------------
	VOID OnEventTrigger(DWORD dwTriggerSerial);

	//----------------------------------------------------------------------------
	// ��������¼�
	//----------------------------------------------------------------------------
	VOID OnEventInvest(DWORD dwNPCID, DWORD dwNPCTypeID);

	//----------------------------------------------------------------------------
	// �������ɿضԻ���ȱʡ�¼�
	//----------------------------------------------------------------------------
	VOID OnEventDlgDefault(DWORD dwDlgOption);

private:
	//----------------------------------------------------------------------------
	// �Ѽ���ʼ��Ʒ
	//----------------------------------------------------------------------------
	VOID InitQuestItem();

	//----------------------------------------------------------------------------
	// ɱ���Ƿ�����
	//----------------------------------------------------------------------------
	BOOL IsCanCompleteCreatureKill(BOOL bOnlyOne=FALSE);

	//----------------------------------------------------------------------------
	// ��Ʒ�Ƿ�����
	//----------------------------------------------------------------------------
	BOOL IsCanCompleteItem(BOOL bOnlyOne=FALSE);

	//----------------------------------------------------------------------------
	// NPC�Ƿ�����
	//----------------------------------------------------------------------------
	BOOL IsCanCompleteNPCTalk(BOOL bOnlyOne=FALSE);

	//----------------------------------------------------------------------------
	// �������Ƿ�����
	//----------------------------------------------------------------------------
	BOOL IsCanCompleteTrigger(BOOL bOnlyOne=FALSE);

	//----------------------------------------------------------------------------
	// ��������Ƿ�����
	//----------------------------------------------------------------------------
	BOOL IsCanCompleteInvest(BOOL bOnlyOne=FALSE);

	//----------------------------------------------------------------------------
	// ��Ǯ
	//----------------------------------------------------------------------------
	BOOL IsCanCompleteMoney(BOOL bOnlyOne=FALSE);

	//----------------------------------------------------------------------------
	// �ȼ�
	//----------------------------------------------------------------------------
	BOOL IsCanCompleteLevel(BOOL bOnlyOne=FALSE);

	//----------------------------------------------------------------------------
	// ��ͼ
	//----------------------------------------------------------------------------
	BOOL IsCanCompleteMap(BOOL bOnlyOne=FALSE);

	//----------------------------------------------------------------------------
	// ����
	//----------------------------------------------------------------------------
	BOOL IsCanCompleteReward(INT nChoiceItemIndex);

private:
	const tagQuestProto*	m_pProto;									// ��̬����
	Role*					m_pOwner;									// �������
	INT						m_nIndex;									// �����������б�����
	BOOL					m_bComplete;								// �Ƿ�ͨ��������ж�
	INT16					m_n16CreatureCount[QUEST_CREATURES_COUNT];	// ����Ѿ�ɱ�˹��������
	INT16					m_n16ItemCount[QUEST_ITEMS_COUNT];			// ����Ѿ��ռ�����Ʒ������
	bool					m_bSpeakNPC[QUEST_NPC_COUNT];				// ����Ѿ��Ի�����NPCID
	bool					m_bTrigger[QUEST_TRIGGERS_COUNT];			// ����Ѿ��ȵĴ�����
	bool					m_bInvest[DYNAMIC_TARGET_COUNT];			// ��ҵ�����ĵ���
	tagQuestDynamicTarget*	m_pDynamicTarget;							// ����̬Ŀ��

	DWORD					m_dwStartTime;								// �����ȡʱ��

	const QuestScript*		m_pScript;									// ����ű�
};