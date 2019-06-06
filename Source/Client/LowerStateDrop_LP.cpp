#include "StdAfx.h"
#include "LowerStateDrop_LP.h"
#include "CombatEvent.h"
#include "LocalPlayer.h"
#include "FSM_LP.h"
#include "PreState.h"
#include "EffectMgr.h"
#include "CombatSysUtil.h"

LowerStateDrop_LP::LowerStateDrop_LP(void)
{}

LowerStateDrop_LP::~LowerStateDrop_LP(void)
{}

void LowerStateDrop_LP::Active( tagGameEvent* pEvent,NavMap* pNav,LocalPlayer* pRole,tagPreState* pPreState )
{
	ASSERT(pEvent->strEventName==_T("tagDropEvent"));
	tagDropEvent* pDropEvent=(tagDropEvent*)pEvent;

	if(pPreState!=NULL)
		m_prestate=*pPreState;
	else
		m_prestate.state=tagPreState::EState_None;

	m_actDrop.Active(pDropEvent->start,pDropEvent->dir,pNav,pRole);
}

void LowerStateDrop_LP::Update( NavMap* pNav,LocalPlayer* pRole )
{
	m_actDrop.Update(!m_prestate.IsMoving(),pNav,pRole);
	if(m_actDrop.IsClosed())
	{
		if(m_actDrop.GetResult()==ActionDrop_LP::ER_VDrop)
		{
			tagVDropEvent event(_T("tagVDropEvent"),NULL);
			event.start=pRole->GetPos();
			m_pFSM->Change2LowerState(FSM_LP::ELowerState_VDrop,&event,&m_prestate);
		}
		else if(m_actDrop.GetResult()==ActionDrop_LP::ER_Slide)
		{
			tagSlideEvent event(_T("tagSlideEvent"),NULL);
			event.start=pRole->GetPos();
			m_pFSM->Change2LowerState(FSM_LP::ELowerState_Slide,&event,&m_prestate);
		}
		else if(m_prestate.state!=tagPreState::EState_None)
		{
			m_prestate.Change2LowerState(m_pFSM,pRole,
				m_actDrop.GetResult()==ActionDrop_LP::ER_Swim,
				m_actDrop.GetResult()==ActionDrop_LP::ER_OnWater);
		}
		else if(m_actDrop.GetResult()==ActionDrop_LP::ER_Swim)
		{
			m_pFSM->Change2LowerState_Float();
		}
		else if(m_actDrop.GetResult()==ActionDrop_LP::ER_OnWater)
		{
			m_pFSM->Change2LowerState_WaterStand();
		}
		else
		{
			m_pFSM->Change2LowerState_Stand();	
		}
	}
}

void LowerStateDrop_LP::OnGameEvent( tagGameEvent* pEvent )
{
	if(pEvent->strEventName==_T("tagKeyboardMoveEvent"))//�����ƶ���Ϸ�¼�
	{
		tagKeyboardMoveEvent* pMoveEvent=(tagKeyboardMoveEvent*)pEvent;

		if(m_actDrop.IsLanding())
		{
			m_pFSM->TryChange2LowerState(FSM_LP::ELowerState_KeyboardMove,pEvent);
		}
		else
		{
			m_prestate.state=tagPreState::EState_KeyboardMove;
			m_prestate.keyboardMove=*pMoveEvent;
		}
	}
	else if(pEvent->strEventName==_T("tagStopKeyboardMoveEvent"))//ֹͣ�����ƶ���Ϸ�¼�
	{
		if(m_prestate.state==tagPreState::EState_KeyboardMove)
			m_prestate.state=tagPreState::EState_None;
	}
	else if(pEvent->strEventName==_T("tagJumpEvent"))//��Ծ��Ϸ�¼�
	{
		if(m_actDrop.IsLanding())//���ڲ�����ض���
		{
			m_pFSM->TryChange2LowerState(FSM_LP::ELowerState_Jump,pEvent,&m_prestate);
		}
	}
	else if(pEvent->strEventName==_T("tagMouseMoveEvent"))//����ƶ���Ϸ�¼�
	{
		if(m_actDrop.IsLanding())//���ڲ�����ض���
		{
			m_pFSM->TryChange2LowerState(FSM_LP::ELowerState_MouseMove,pEvent);
		}
	}
	else if(pEvent->strEventName==_T("tagStopPursueEvent"))//ֹͣ׷��
	{
		if(m_prestate.state==tagPreState::EState_Pursue)
			m_prestate.state=tagPreState::EState_None;
	}
}

void LowerStateDrop_LP::ReplayAni( LocalPlayer* pRole )
{
	m_actDrop.ReplayAni(pRole);
}

bool LowerStateDrop_LP::IfCanChange2UpperState( FSM_LP::EUpperState state,tagGameEvent* pEvent )
{
	switch(state)
	{
	case FSM_LP::EUpperState_Idle:		//����
	case FSM_LP::EUpperState_Dead:		//����
	case FSM_LP::EUpperState_Dazzy:		//����
	case FSM_LP::EUpperState_Tie:		//����
	case FSM_LP::EUpperState_Sopor:		//��˯
		{
			return true;
		}
		break;
	}

	return false;
}

bool LowerStateDrop_LP::IfCanChange2LowerState( FSM_LP::ELowerState state,tagGameEvent* pEvent )
{
	return true;
}