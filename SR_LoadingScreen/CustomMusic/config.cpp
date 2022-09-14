
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

class CfgSoundShaders
{
	class SurvivorsRefuge_Music_1_SoundShader
	{
		samples[] = {{"SurvivorsRefuge\SR_LoadingScreen\CustomMusic\StrivingForChange",1}};
		volume=40.0;
	};
};

class CfgSoundSets
{	
	class SurvivorsRefuge_Music_1_SoundSet
	{
		soundShaders[]=
		{
			"SurvivorsRefuge_Music_1_SoundShader"
		};
		volumeFactor=1;
		frequencyFactor=1;
		spatial=0;
	};
};