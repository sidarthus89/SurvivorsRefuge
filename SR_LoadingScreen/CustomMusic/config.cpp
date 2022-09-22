
class CfgPatches
{
	class SurvivorsRefuge_ExpansionCustomMusic
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
        {
            "DZ_Sounds_Effects"
        };
	};
};

class CfgSoundSets
{
	class Main_Music_Menu_SoundSet
	{
		soundShaders[] = {"Main_Music_Menu_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 0;
	};
};	
class CfgSoundShaders
{
	class Main_Music_Menu_SoundShader
	{
		samples[] = {{"SurvivorsRefuge\SR_LoadingScreen\CustomMusic\When-All-Kingdoms-Fall.ogg",1}};
		volume = 0.50000000;
	};
};
