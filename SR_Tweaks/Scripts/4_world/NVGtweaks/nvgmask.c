//segunda parte del mod anterior

modded class ToggleNVGActionInput : DefaultActionInput
{
	override void UpdatePossibleActions(PlayerBase player, ActionTarget target, ItemBase item, int action_condition_mask)
	{
		super.UpdatePossibleActions(player, target, item, action_condition_mask);
		if(m_SelectAction==NULL){
			if( ForceActionCheck(player) )
			{
				m_SelectAction = m_ForcedActionData.m_Action;
				return;
			}
			array<ActionBase_Basic> possible_actions;
			ActionBase action;
			int i;
			m_MainItem = NULL;
			if ( player ) 
			{
				NVGHeadstrap strap = NVGHeadstrap.Cast(player.FindAttachmentBySlotName("Mask"));
				if ( strap )
				{
					target_new = new ActionTarget(strap, null, -1, vector.Zero, -1);
					ForceActionTarget(target_new);
				}
				else
					ClearForcedTarget();
			}
			
			target = m_ForcedTarget;
			m_Target = m_ForcedTarget;
			
			if(target && target.GetObject())
			{
				target.GetObject().GetActions(this.Type(), possible_actions);
				if(possible_actions)
				{
					for (i = 0; i < possible_actions.Count(); i++)
					{
						action = ActionBase.Cast(possible_actions.Get(i));
						if ( action.Can(player, target, m_MainItem, action_condition_mask) )
						{
							m_SelectAction = action;
							return;
						}
					}
				}
			}
		}
	}
};