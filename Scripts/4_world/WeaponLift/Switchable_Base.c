modded class Switchable_Base extends ItemBase
{
	bool m_IsEnabled;
	
	void Switchable_Base()
	{
		RegisterNetSyncVariableBool("m_IsEnabled");
	}
	
	bool IsEnabled()
	{
		return m_IsEnabled;
	}
	
	void SetEnabled(bool enable)
	{		
		m_IsEnabled = enable;
		
		this.SetSynchDirty();
	}
}

modded class ActionTurnOnWeaponFlashlight: ActionSingleUseBase
{
	Switchable_Base m_light;
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( item.IsInherited(Rifle_Base) )
		{
			//m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_LIGHTFLARE;
			m_light = ItemBase.Cast(item.FindAttachmentBySlotName("weaponFlashlight"));
		}
		else if (item.IsInherited(Pistol_Base))
		{
			//m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_LITCHEMLIGHT;
			m_light = ItemBase.Cast(item.FindAttachmentBySlotName("pistolFlashlight"));
		}
		else //is not valid item
			return false;
		
		if ( m_light && !m_light.IsEnabled()  ) //TODO review conditions for turning off
		{
			return true;
		}
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		m_light.SetEnabled(true);
		m_light.SetSynchDirty();
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		m_light.SetEnabled(true);
	}
}


modded class ActionTurnOffWeaponFlashlight: ActionSingleUseBase
{
	Switchable_Base m_light;
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( item.IsInherited(Rifle_Base) )
		{
			//m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_LIGHTFLARE;
			m_light = ItemBase.Cast(item.FindAttachmentBySlotName("weaponFlashlight"));
		}
		else if (item.IsInherited(Pistol_Base))
		{
			//m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_LITCHEMLIGHT;
			m_light = ItemBase.Cast(item.FindAttachmentBySlotName("pistolFlashlight"));
		}
		else //is not valid item
			return false;
		
		if ( m_light && m_light.IsEnabled() ) //TODO review conditions for turning off
		{
			return true;
		}
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{	
		m_light.SetEnabled(false);
		m_light.SetSynchDirty();
	}

	override void OnExecuteClient( ActionData action_data )
	{	
		m_light.SetEnabled(false);
	}
}
