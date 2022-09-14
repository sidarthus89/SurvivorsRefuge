class CfgPatches
{
	class SurvivorsRefuge
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DayZExpansion_Market_Structures","DayZExpansion_Scripts","DZ_Sounds_Effects","DZ_Weapons_Ammunition","DZ_Weapons_Magazines"};
	};
};
class CfgMods
{
	class SurvivorsRefuge
	{
		dir = "SurvivorsRefuge";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "Survivor's Refuge";
		author = "Sidarthus89";
		credits = "Sidarthus89";
		authorID = "0";
		version = "1.0";
		type = "mod";
		dependencies[] =
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"SurvivorsRefuge/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"SurvivorsRefuge/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"SurvivorsRefuge/Scripts/5_Mission"};
			};
		};
	};
};