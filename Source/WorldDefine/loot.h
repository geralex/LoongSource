//-----------------------------------------------------------------------------
// Copyright (c) 2004 TENGWU Entertainment All rights reserved.
// filename: loot.h
// author: Aslan
// actor:
// data: 2008-08-10
// last: 2008-10-22
// brief: ���侲̬����
//-----------------------------------------------------------------------------
#pragma once

//------------------------------------------------------------------------
// �����������
//------------------------------------------------------------------------
enum ELootOpType
{
	ELOT_Common		= 0,	// ��ͨ���䣨������
	ELOT_OnlyOne	= 1,	// ��һ���䣨һ����
};

//------------------------------------------------------------------------
// ����ģʽ
//------------------------------------------------------------------------
enum ELootMode
{
	ELM_LootToGround = 0,		// ʵ�����
	ELM_LootToBag    = 1,		// ֱ�ӻ��
};

//------------------------------------------------------------------------
// ��������
//------------------------------------------------------------------------
enum ELootType
{
	ELT_Item = 0,		// ��Ʒ
	ELT_Set  = 1,		// ����
};

//------------------------------------------------------------------------
// ʰȡ��Χ
//------------------------------------------------------------------------
const float X_DEF_PICKUP_DIST = 40.0f*100.0f;		// ʰȡ��Χ��40��
const float X_DEF_PICKUP_DIST_SQ = 40.0f*100.0f * 40.0f*100.0f;
const float X_DEF_AUTO_PICKUP_DIST = 20.0f*100.0f;	// �Զ�ʰȡ��Χ��20��

//------------------------------------------------------------------------
// ������Ʒ����
//------------------------------------------------------------------------
const INT MAX_ITEM_SET_NUM = 20;	// ��Ʒ�����д�����Ʒ����

struct tagItemSet
{
	DWORD dwItemID; 	//��ƷID
	INT   nItemNum;    //��Ʒ����
};

struct tagLootItemSet
{
	DWORD  dwSetID;							//����id
	tagItemSet ItemSet[MAX_ITEM_SET_NUM];	//��Ʒ����
};

//------------------------------------------------------------------------
// ����������Ʒ
//------------------------------------------------------------------------
const INT MAX_LOOT_QUEST_ITEM_NUM = 5;	// ����������Ʒ����

struct tagQuestItem
{
	DWORD  dwQuestItemID;	//������ƷID
	FLOAT  fChance;			//������Ʒ����
	FLOAT  fTeamChance;		//С��������Ʒ����
};

struct tagLootQuestItem
{
	DWORD  dwCreatureID;								//����ID
	tagQuestItem QuestItem[MAX_LOOT_QUEST_ITEM_NUM];	//������Ʒ	
};

//-----------------------------------------------------------------------
// ����Ļ����ṹ�������ڹ�������Լ���Ʒ�ȵȵĵ��䷽ʽ
//-----------------------------------------------------------------------
struct tagLoot
{
	DWORD		dwItemID;		// ��ƷID�������������Ϊ���ϣ���Ϊ����ID��
	ELootType	eLootType;      // ��������
	INT			nMin;			// ��Ʒ����С����
	INT			nMax;			// ��Ʒ���������
	FLOAT		fChance;		// ���伸��
};

//------------------------------------------------------------------------
// �������ṹ
//------------------------------------------------------------------------
const INT MAX_CREATURE_LOOT_NUM = 20;	// �������������Ʒ����

struct tagCreatureLoot
{
	DWORD		dwLootID;						// ����ID
	ELootOpType		eOpType;						// ��������
	ELootMode	eLootMode;						// ����ģʽ
	INT			nMinMoney;						// ������С��Ǯ
	INT			nMaxMoney;						// ��������Ǯ

	tagLoot		Loot[MAX_CREATURE_LOOT_NUM];	// �������Ʒ����
};