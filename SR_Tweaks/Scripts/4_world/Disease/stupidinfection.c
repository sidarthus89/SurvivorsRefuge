modded class WoundInfectStage1Mdfr: ModifierBase
{
	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}
	
	override bool DeactivateCondition(PlayerBase player)
	{
		return true;
	}
};

modded class WoundInfectStage2Mdfr: ModifierBase
{
	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}
	
	override bool DeactivateCondition(PlayerBase player)
	{   
		return true;
	}
};