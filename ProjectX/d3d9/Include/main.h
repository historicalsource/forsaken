#ifndef MAIN_INCLUDED
#define MAIN_INCLUDED

/*===================================================================
	Game Status Defines...
===================================================================*/

#define	STATUS_Title									2	// On the Title Screen...
#define	STATUS_StartingMultiplayer						4	// On the Multiplayer Starting Screen...
#define	STATUS_PreStartingMultiplayerSynch				5	// Waiting for everyone to have loaded the right level and be ready
#define	STATUS_StartingMultiplayerSynch					6	// Waiting for everyone to have loaded the right level and be ready
							// to Start...
#define	STATUS_QuitCurrentGame							7	// About to quit a game and return to the title screen..
#define	STATUS_GetPlayerNum								8	// Trying to aquire a Player Number...
#define	STATUS_PlayingDemo								9	// Playing Back a Demo...
#define	STATUS_Normal 									10	// normal in game...
#define	STATUS_LevelEnd									11	// the level has ended tell the host I know the level has ended...
#define	STATUS_BetweenLevels    						12	// in title room between levels

#define	STATUS_ViewingScore								13	// tell the host I am looking at the Score....
#define	STATUS_WaitingAfterScore						14	// waiting for other players or waitng for the host to start...
#define	STATUS_Joining									15	// I Want to join your game....
#define	STATUS_Left										16	// I have left your game...
#define	STATUS_ChangeLevelPostInitView					17	// after a change level init view
#define	STATUS_ChangeLevelPostPlayingDemo				18	// after a change level Playing Demo...
											
#define	STATUS_StartingSinglePlayer						32	// Starting Single Player in game...
#define	STATUS_PostStartingSinglePlayer					33	// Starting Single Player in game after the level has been loaded...
#define	STATUS_SinglePlayer								34	// Single Player in game...
#define	STATUS_ViewingStats								35	// Viewing Stats Single Player...

#define	STATUS_TitleLoadGameStartingSinglePlayer		36
#define	STATUS_TitleLoadGamePostStartingSinglePlayer	37
#define	STATUS_ChangeLevelPostLoadGame					38
#define	STATUS_InGameLoadGameStartingSinglePlayer		39

#define	STATUS_WaitingToStartSinglePlayer				48	// waiting to start single player game...
#define	STATUS_WaitingToStartMultiPlayerHost			49	// waiting to start multi player game for host...
#define	STATUS_WaitingToStartMultiPlayerClient			50	// waiting to start multi player game for client...
#define	STATUS_WaitingToStartTeamGame					51	// waiting to start multi player game for client...
#define STATUS_QuittingFromTitles						52	// quitting game from title screen
#define STATUS_WaitingToStartDemo						53	// waiting to start demo
#define STATUS_WaitingToStartEndGameSequence			54	// waiting to start end of game demo playback sequence

#define	STATUS_InitView_0								128	// 0 of Preping for a level..
#define	STATUS_InitView_1								129	// 1 of Preping for a level..
#define	STATUS_InitView_2								130	// 2 of Preping for a level..
#define	STATUS_InitView_3								131	// 3 of Preping for a level..
#define	STATUS_InitView_4								132	// 4 of Preping for a level..
#define	STATUS_InitView_5								133	// 5 of Preping for a level..
#define	STATUS_InitView_6								134	// 6 of Preping for a level..
#define	STATUS_InitView_7								135	// 7 of Preping for a level..
#define	STATUS_InitView_8								136	// 8 of Preping for a level..
#define	STATUS_InitView_9								137	// 9 of Preping for a level..
#define	STATUS_InitView_10								138	// 10 of Preping for a level..

#define STATUS_LeftCrashed								254	// I have left and crashed...
#define STATUS_Null										255	// Im not doing anything yet...


/*===================================================================
	Screen Mode Defines...
===================================================================*/

#define Mode320X200 0
#define Mode320X240 1
#define Mode320X400 2
#define Mode512X384 3
#define Mode640X400 4
#define Mode640X480 5
#define Mode800X600 6
#define Mode1024X768 7

/*===================================================================
	Some Global Defines...
===================================================================*/

#define START_FOV			(90.0F) // initial horizontal field-of-view (in degrees)
#define MAX_FOV				(120.0F) // max horizontal field-of-view (in degrees)

#define MAXLEVELS			(64)
#define	MAGIC_NUMBER		0x584A5250

#endif	// MAIN_INCLUDED