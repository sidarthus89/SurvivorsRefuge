//permite activar el la vision noctura en un vehiculo

class ToggleNVGFromVehicleActionInput : DefaultActionInput
{
	ref ActionTarget target_new;
	
	void ToggleNVGFromVehicleActionInput(PlayerBase player)
	{
		SetInput("UAToggleNVG");
		m_InputType = ActionInputType.AIT_HOLDSINGLE;
	}
	
	override void UpdatePossibleActions(PlayerBase player, ActionTarget target, ItemBase item, int action_condition_mask)
	{
		if( ForceActionCheck(player) )
		{
			m_SelectAction = m_ForcedActionData.m_Action;
			return;
		}

		m_SelectAction = NULL;
		array<ActionBase_Basic> possible_actions;
		ActionBase action;
		int i;

		m_MainItem = NULL;
		if ( player && !player.IsInVehicle() ) 
		{
			Clothing headgear = Clothing.Cast(player.FindAttachmentBySlotName("Headgear"));
			if ( headgear )
			{
				target_new = new ActionTarget(headgear, null, -1, vector.Zero, -1);
				ForceActionTarget(target_new);
			}
			else
				ClearForcedTarget();
		}
		else if ( player && player.IsInVehicle() )
		{
			HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
			if( vehCommand )
			{
				Transport trans = vehCommand.GetTransport();
				if( trans )
				{
					target_new = new ActionTarget(trans, null, -1, vector.Zero, -1);
					ForceActionTarget(target_new);
				}
			}
			
			if ( !target_new )
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
};

class ActionToggleNVGInVehicle: ActionBase
{
	void ActionToggleNVGInVehicle()
	{}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool IsInstant()
	{
		return true;
	}

	override typename GetInputType()
	{
		return ToggleNVGFromVehicleActionInput;
	}
	
	override bool HasTarget()
	{
		return true;
	}
	
	override bool UseMainItem()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();

		if ( vehCommand )
		{
			Transport trans = vehCommand.GetTransport();
			if ( trans )
			{
				CarScript car;
				if ( Class.CastTo(car, trans) )
				{
					if ( player ) 
					{
						Mich2001Helmet helmet = Mich2001Helmet.Cast(player.FindAttachmentBySlotName("Headgear"));
						NVGHeadstrap headstrap = NVGHeadstrap.Cast(player.FindAttachmentBySlotName("Eyewear"));
						Object o;
						if ( helmet)
						{
							o = helmet.FindAttachmentBySlotName("NVG");
						}	
						if (headstrap)
						{
							o = headstrap.FindAttachmentBySlotName("NVG");
						}	
						if(o){
							return true;
						}						
					}
				}
			}
		}
		return false;
	}
	
	override void Start( ActionData action_data )
	{
		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
		if ( vehCommand )
		{
			Transport trans = vehCommand.GetTransport();
			if ( trans )
			{
				CarScript car;
				if ( Class.CastTo(car, trans) )
				{
					if ( action_data.m_Player ) 
					{
						NVGoggles goggles;
						Mich2001Helmet helmet = Mich2001Helmet.Cast(action_data.m_Player.FindAttachmentBySlotName("Headgear"));
						NVGHeadstrap headstrap = NVGHeadstrap.Cast(action_data.m_Player.FindAttachmentBySlotName("Eyewear"));
						if ( helmet )
						{
							goggles = NVGoggles.Cast(helmet.FindAttachmentBySlotName("NVG"));
						}
						else if ( headstrap )
						{
							goggles = NVGoggles.Cast(headstrap.FindAttachmentBySlotName("NVG"));
						}
						if(goggles)
						{
							goggles.RotateGoggles(goggles.m_IsLowered);
						}
					}
				}
			}
		}
	}

	override bool CanBeUsedInVehicle()
	{
		return true;
	}
};

modded class CarScript
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionToggleNVGInVehicle);
	}
}


modded class ActionConstructor
{
	void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);	
		actions.Insert(ActionToggleNVGInVehicle);
	}
}