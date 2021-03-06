#pragma once
#include <memory>
#include "../../PacketType.h"
enum EventTypes
{
	EVT_ERROR,
	EVT_NONE,
	EVT_OK,
	EVT_SUBMIT_NAME,
	EVT_SUBMIT_MAP,
	EVT_MY_TURN,
	EVT_SUBMIT_ATTACK,
	EVT_AttackResult,

	EVT_NEW_GAME,
	EVT_ADD_PLAYER_1_IN_GAME,
	EVT_ADD_PLAYER_2_IN_GAME,
	EVT_GAME_START,
	EVT_GAME_OVER,
	EVT_NEXT_GAME,
	EVT_ALL_OVER,

	EVT_DISCONNECT,

	EVT_GAME_START_BUTTON,
	EVT_ADD_PLAYER_TO_BATTLEBOARD,
	EVT_BATTLEBOARD_INIT,

	EVT_CURSOR_UP,
	EVT_CURSOR_DOWN,
	EVT_SELECT_STUDENT,
} ;

struct EventHeader
{
	EventTypes event_type_;
};

namespace Event
{

	struct ErrorEvent : public EventHeader
	{
		ErrorEvent()
		{
			event_type_ = EVT_ERROR;
			error_type_ = ET_UNKNOWN;
		}
		ErrorTypes error_type_;
		PlayerNumber player_number_;
	};

	struct OKEvent : public EventHeader
	{
		OKEvent()
		{
			event_type_ = EVT_OK;
		}
		PlayerNumber player_number_;
	};

	struct SubmitNameEvent : public EventHeader
	{
		SubmitNameEvent()
		{
			event_type_ = EVT_SUBMIT_NAME;
			memset(name_, 0, sizeof(name_));
		}
		void SetName(wchar_t* name, int length)
		{
			memcpy(name_, name, sizeof(wchar_t) * min(MAX_NAME_LEN, length));
		}
		PlayerNumber player_number_;
		wchar_t name_[MAX_NAME_LEN];
	};

	struct GameStartEvent : public EventHeader
	{
		GameStartEvent()
		{
			event_type_ = EVT_GAME_START;
			game_number_ = -1;
		}
		GameNumber game_number_;
	};

	struct SubmitMapEvent : public EventHeader
	{
		SubmitMapEvent()
		{
			event_type_ = EVT_SUBMIT_MAP;
			memset(mMap, MI_EMPTY, sizeof(mMap));
		}
		PlayerNumber player_number_;
		char mMap[8][8];
	};

	struct MyTurnEvent : public EventHeader
	{
		MyTurnEvent()
		{
			event_type_ = EVT_MY_TURN;
		}
		PlayerNumber player_number_;
	};

	struct SubmitAttackEvent : public EventHeader
	{
		SubmitAttackEvent()
		{
			event_type_ = EVT_SUBMIT_ATTACK;
		}
		PlayerNumber player_number_;
		Coord coord_;
	};

	struct AttackEvent : public EventHeader
	{
		AttackEvent()
		{
			event_type_ = EVT_AttackResult;
			AttackResult_ = AR_NONE;
			isMine = false;
		}
		PlayerNumber player_number_;
		Coord coord_;
		bool isMine;    
		AttackResultTypes AttackResult_;
	};
	struct GameOverEvent : public EventHeader
	{
		GameOverEvent()
		{
			event_type_ = EVT_GAME_OVER;
			turns_ = -1;
			winner_ = -1;
			game_number_ = -1;
		}
		PlayerNumber winner_;
		int turns_;
		GameNumber game_number_;
	};

	struct NextGameEvent : public EventHeader
	{
		NextGameEvent()
		{
			event_type_ = EVT_NEXT_GAME;
			game_number_ = -1;
		}
		GameNumber game_number_;
	};

	struct AllOverEvent : public EventHeader
	{
		AllOverEvent()
		{
			event_type_ = EVT_ALL_OVER;
			game_number_ = -1;
		}
		GameNumber game_number_;
	};
	
	struct NewGameEvent : public EventHeader
	{
		NewGameEvent()
		{
			event_type_ = EVT_NEW_GAME;
		}
		GameNumber game_number_;
	};
	
	struct AddPlayer1InGameEvent : public EventHeader
	{
		AddPlayer1InGameEvent()
		{
			event_type_ = EVT_ADD_PLAYER_1_IN_GAME;
			player_number_ = -1;
			game_number_ = -1;
		}
		GameNumber game_number_;
		PlayerNumber player_number_;
	};


	struct AddPlayer2InGameEvent : public EventHeader
	{
		AddPlayer2InGameEvent()
		{
			event_type_ = EVT_ADD_PLAYER_2_IN_GAME;
			player_number_ = -1;
			game_number_ = -1;
		}
		GameNumber game_number_;
		PlayerNumber player_number_;
	};
	
	struct DisconnectEvent : public EventHeader
	{
		DisconnectEvent()
		{
			event_type_ = EVT_DISCONNECT;
			player_number_ = -1;
		}
		PlayerNumber player_number_;
	};

	struct GameStartButtonEvent : public EventHeader
	{
		GameStartButtonEvent()
		{
			event_type_ = EVT_GAME_START_BUTTON;
		}
	};

	struct AddPlayerToBattleBaordEvent : public EventHeader
	{
		AddPlayerToBattleBaordEvent()
		{
			event_type_ = EVT_ADD_PLAYER_TO_BATTLEBOARD;
			player_number_ = -1;
		}
		PlayerNumber player_number_;
	};
	struct BattleBoardInitEvent : public EventHeader
	{
		BattleBoardInitEvent()
		{
			event_type_ = EVT_BATTLEBOARD_INIT;
		}
	};
	struct CursorUpEvent : public EventHeader
	{
		CursorUpEvent()
		{
			event_type_ = EVT_CURSOR_UP;
		}
	};	
	struct CursorDownEvent : public EventHeader
	{
		CursorDownEvent()
		{
			event_type_ = EVT_CURSOR_DOWN;
		}
	};	
	struct SelectStudentEvent : public EventHeader
	{
		SelectStudentEvent()
		{
			event_type_ = EVT_SELECT_STUDENT;
		}
	};
}