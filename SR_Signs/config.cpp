class CfgPatches
{
	class SR_Signs
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DayZExpansion_Market_Structures"  
		};
	};
};
class CfgVehicles
{
	class ExpansionSign_Color;
	class Trader_Sign_Ammo_Attachments: ExpansionSign_Color	
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\Ammo_Attachments.paa"};
		vehicleClass = "Expansion_Sign";
	};
	class Trader_Sign_BaseImprovement: ExpansionSign_Color
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\Gardening_Containers_Tents_Furniture.paa"};
		vehicleClass = "Expansion_Sign";
	};	
	class Trader_Sign_CivilianGear: ExpansionSign_Color
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\CivilianGear.paa"};
		vehicleClass = "Expansion_Sign";
	};
	class Trader_Sign_Consumables: ExpansionSign_Color	
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\Consumables.paa"};
		vehicleClass = "Expansion_Sign";
	};
	class Trader_Sign_Hunting: ExpansionSign_Color
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\Hunting_Fishing.paa"};
		vehicleClass = "Expansion_Sign";
	};
	class Trader_Sign_Medical: ExpansionSign_Color	
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\Medic.paa"};
		vehicleClass = "Expansion_Sign";
	};
	class Trader_Sign_MilitaryGear: ExpansionSign_Color	
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\MilitaryGear.paa"};
		vehicleClass = "Expansion_Sign";
	};
	class Trader_Sign_Tools: ExpansionSign_Color	
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\Tools_Supplies.paa"};
		vehicleClass = "Expansion_Sign";
	};
	class Trader_Sign_VehiclesParts: ExpansionSign_Color	
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\GroundVehicles_Parts.paa"};
		vehicleClass = "Expansion_Sign";
	};
	class Trader_Sign_Weapons: ExpansionSign_Color	
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\Weapons.paa"};
		vehicleClass = "Expansion_Sign";
	};
	class Trader_Sign_Rules: ExpansionSign_Color	
	{
		scope = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\Rules.paa"};
		vehicleClass = "Expansion_Sign";
	};
	
	class ExpansionSignBig_Color;
    class Trader_Sign_Rules_Big: ExpansionSignBig_Color
    {
        scope = 1;
        displayName = "";
        descriptionShort = "";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\SurvivorsRefuge\SR_Signs\data\Rules_Big.paa"};
        vehicleClass="Expansion_Sign";
    };	
};