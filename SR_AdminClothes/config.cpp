class CfgPatches
{
	class Admin_Clothes
	{
		units[] = {"Boots_Admin","Pants_Admin","Top_Admin","Arms_Admin","Head_Admin","Backpack_Admin","Hatchet_Admin","Shovel_Admin"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Characters_Backpacks","DZ_Characters_Pants","DZ_Characters_Tops","DZ_Characters_Gloves","DZ_Gear_Containers","DZ_Characters_Headgear","DZ_Characters_Masks","DZ_Characters_Shoes","DZ_Data","DZ_Characters_Heads","DZ_Weapons_Firearms","DZ_Weapons_Magazines"};
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class Boots_Admin: Inventory_Base
	{
		scope = 2;
		displayName = "Admin Feet";
		itemSize[] = {2,2};
		descriptionShort = "Admin Feet of invisability by Pope";
		model = "invisible.p3d";
		inventorySlot = "Feet";
		itemInfo[] = {"Clothing","Feet"};
		visibilityModifier = 0.8;
		weight = 1230;
		durability = 0.5;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		absorbency = 0.1;
		heatIsolation = 0.5;
	};
	class HunterPants_ColorBase;
	class Pants_Admin: HunterPants_ColorBase
	{
		displayName = "Admin Pants";
		descriptionShort = "Admin Pants of invisability by Pope";
		scope = 2;
		visibilityModifier = 0;
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,1,1,0.3,ca)","\SurvivorsRefuge\SR_AdminClothes\Data\Invisible_ca.paa","\SurvivorsRefuge\SR_AdminClothes\Data\Invisible_ca.paa"};
	};
	class GorkaEJacket_ColorBase;
	class Top_Admin: GorkaEJacket_ColorBase
	{
		displayName = "Admin Top";
		descriptionShort = "Admin Top of invisability by Pope";
		scope = 2;
		visibilityModifier = 0;
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,1,1,0.3,ca)","\SurvivorsRefuge\SR_AdminClothes\Data\Invisible_ca.paa","\SurvivorsRefuge\SR_AdminClothes\Data\Invisible_ca.paa"};
	};
	class Arms_Admin: Inventory_Base
	{
		scope = 2;
		displayName = "Admin Arms";
		itemSize[] = {2,2};
		descriptionShort = "Admin Arms of invisability by Pope";
		model = "invisible.p3d";
		inventorySlot = "Gloves";
		visibilityModifier = 0;
	};
	class Head_Admin: Inventory_Base
	{
		scope = 2;
		displayName = "Admin head";
		itemSize[] = {2,2};
		descriptionShort = "Admin Head of invisability by Pope";
		model = "invisible.p3d";
		inventorySlot = "Head";
		simulation = "head";
	};
	class AliceBag_ColorBase;
	class Backpack_Admin: AliceBag_ColorBase
	{
		displayName = "Admin Backpack";
		descriptionShort = "Admin Backpack of invisability by Pope";
		scope = 2;
		visibilityModifier = 0;
		itemsCargoSize[] = {10,200};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(1,1,1,0.3,ca)","\SurvivorsRefuge\SR_AdminClothes\Data\Invisible_ca.paa","\SurvivorsRefuge\SR_AdminClothes\Data\Invisible_ca.paa"};
	};
	class Hatchet;
	class Hatchet_Admin: Hatchet
	{
		scope = 2;
		displayName = "Admin Courgette of Unbreaking (Hatchet)";
		descriptionShort = "Damage 10, Durability 10000.";
		model = "\dz\gear\food\zucchini.p3d";
		build_action_type = 10;
		dismantle_action_type = 10;
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		rotationFlags = 17;
		weight = 1133;
		itemSize[] = {1,2};
		fragility = 1e-07;
		inventorySlot[] = {"Shoulder","Melee"};
		lootCategory = "Tools";
		lootTag[] = {"Work","Forester","Camping"};
		itemInfo[] = {"Axe"};
		openItemSpillRange[] = {20,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100000;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\hatchet.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\hatchet.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\hatchet_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "woodaxe";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeHatchet";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeHatchet_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeHatchet_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
				class ShoulderR_Hide
				{
					soundset = "ShoulderR_Hide_SoundSet";
					id = 1210;
				};
				class ShoulderR_Show
				{
					soundset = "ShoulderR_Show_SoundSet";
					id = 1211;
				};
				class WoodHammer_SoundSet
				{
					soundSet = "WoodHammer_SoundSet";
					id = 11161;
				};
			};
		};
	};
	class Shovel_Admin: Hatchet
	{
		scope = 2;
		displayName = "Admin Chicken of Unbreaking (Shovel)";
		descriptionShort = "Damage 10, Durability 10000.";
		model = "\DZ\animals\gallus_gallus_domesticus\gallus_gallus_domesticus.p3d";
		build_action_type = 4;
		dismantle_action_type = 4;
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		rotationFlags = 17;
		weight = 1133;
		itemSize[] = {1,2};
		fragility = 1e-07;
		inventorySlot[] = {"Shoulder","Melee"};
		lootCategory = "Tools";
		lootTag[] = {"Work","Forester","Camping"};
		itemInfo[] = {"Axe"};
		openItemSpillRange[] = {20,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100000;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\hatchet.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\hatchet.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\hatchet_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "woodaxe";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeHatchet";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeHatchet_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeHatchet_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
				class ShoulderR_Hide
				{
					soundset = "ShoulderR_Hide_SoundSet";
					id = 1210;
				};
				class ShoulderR_Show
				{
					soundset = "ShoulderR_Show_SoundSet";
					id = 1211;
				};
				class WoodHammer_SoundSet
				{
					soundSet = "WoodHammer_SoundSet";
					id = 11161;
				};
			};
		};
	};
};
