//! Where are the files located
const string LOADING_SCREENS_PATH 	= "SurvivorsRefuge/SR_LoadingScreen/Data/LoadingImages.json";
const string LOADING_MESSAGES_PATH 	= "SurvivorsRefuge/SR_LoadingScreen/Data/LoadingMessages.json";
const string LOADING_SCREEN_LOGO 	= "SurvivorsRefuge/SR_LoadingScreen/Pictures/SR_Logo_With_Words.edds";
									//! ModName/Path/File

//! true  = yes
//! false = no
const bool UseCustomLoadingPictures = true;
const bool UseCustomLoadingMessages = true;
const bool UseCustomLogo 			= true;
const bool UseCustomLoadingBarColor = true;
const bool ShowModdedWarning 		= false;
const int CustomLoadingBarColor 	= ARGB( 255, 0, 0, 0 ); 	//! A = Alpha (opacity) / R = Red / G = Green / B = Blue
																//! Use a online ARGB color picker, make sure to not mix the values !

//! Do not touch anything bellow this line
modded class LoadingScreen
{
	void LoadingScreen(DayZGame game)
	{
		if ( UseCustomLoadingPictures )
		{
			JsonFileLoader< ref array< ref ExpansionLoadingScreenBackground > >.JsonLoadFile( LOADING_SCREENS_PATH, m_Backgrounds );
		}

		if ( UseCustomLoadingMessages )
		{
			JsonFileLoader< ref array< ref ExpansionLoadingScreenMessageData > >.JsonLoadFile( LOADING_MESSAGES_PATH, m_MessageJson );
		}
		
		m_ImageLogoMid.Show( ShowLogo );
		m_ImageLogoCorner.Show( ShowLogo );
		m_ModdedWarning.Show( ShowModdedWarning );
		m_LoadingMessage.Show( ShowLoadingMessages );
		m_LoadingMessageAuthor.Show( ShowLoadingAuthor );

		if ( UseCustomLogo )
		{
			m_ImageLogoMid.LoadImageFile( 0, LOADING_SCREEN_LOGO );
			m_ImageLogoCorner.LoadImageFile( 0, LOADING_SCREEN_LOGO );
		}

		if ( UseCustomLoadingBarColor )
		{
			m_ProgressLoading.SetColor( CustomLoadingBarColor );
		}
	};

	override void Show()
	{
		if ( UseCustomLoadingPictures )
		{
			m_Backgrounds.Clear();
			JsonFileLoader< ref array< ref ExpansionLoadingScreenBackground > >.JsonLoadFile( LOADING_SCREENS_PATH, m_Backgrounds );
		}

		if ( UseCustomLoadingMessages )
		{
			m_MessageJson.Clear();
			JsonFileLoader< ref array< ref ExpansionLoadingScreenMessageData > >.JsonLoadFile( LOADING_MESSAGES_PATH, m_MessageJson );
		}
		
		super.Show();
		
		m_LoadingMessage.Show( ShowLoadingMessages );
		m_LoadingMessageAuthor.Show( ShowLoadingAuthor );
	};
};
 
modded class LoginQueueBase 
{
	void LoginQueueBase()
	{
		if ( UseCustomLoadingPictures )
		{
			m_Backgrounds.Clear();
			JsonFileLoader< ref array< ref ExpansionLoadingScreenBackground > >.JsonLoadFile( LOADING_SCREENS_PATH, m_Backgrounds );
		}
	};
};
 
modded class LoginTimeBase 
{
	void LoginTimeBase()
	{
		if ( UseCustomLoadingPictures )
		{
			m_Backgrounds.Clear();
			JsonFileLoader< ref array< ref ExpansionLoadingScreenBackground > >.JsonLoadFile( LOADING_SCREENS_PATH, m_Backgrounds );
		}
	};
};
