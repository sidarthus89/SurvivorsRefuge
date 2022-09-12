//oculta el aliento en la mascara

modded class PlayerBase extends ManBase
{
	override void SpawnBreathVaporEffect()
	{
		ItemBase mask = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.MASK));
		if(mask){
			return;
		}
		super.SpawnBreathVaporEffect();
	}
	override bool CanSpawnBreathVaporEffect()
	{
		ItemBase mask = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.MASK));
		if(mask){
			return false;
		}
		return super.CanSpawnBreathVaporEffect();
	}
}
