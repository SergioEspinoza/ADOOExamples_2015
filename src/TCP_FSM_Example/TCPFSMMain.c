/**
 * @file TCPFSMMain.c
 *
 * @author FW Profile code generator version 3.1
 * @date Created on: May 26 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

/** FW Profile function definitions */
#include "FwProfile/FwSmConstants.h"
#include "FwProfile/FwSmSCreate.h"
#include "FwProfile/FwSmConfig.h"
#include "FwProfile/FwSmCore.h"

/** TCPFSM function definitions */
#include "TCPFSM.h"



static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}


int main(void)
{
    char inputChar;

	/** Define the state machine descriptor (SMD) */
	FwSmDesc_t smDesc = TCPFSMCreate(NULL);

	/** Check that the SM is properly configured */
	if (FwSmCheckRec(smDesc) != smSuccess) {
		printf("The state machine is NOT properly configured ... FAILURE\n");
		return EXIT_FAILURE;
	}
	else {
		printf("The state machine is properly configured ... SUCCESS\n");
	}

	/** Start the SM, send a few transition commands to it, and execute it */
	FwSmStart(smDesc);


    inputChar = getche( );

    printf( "press e for exit\n" );


    while( inputChar != 'e'  )
    {

        switch ( inputChar )
        {

            case  'p'    :
                FwSmMakeTrans(smDesc, PassiveOpen);
                break;
            case 'a'    :
                FwSmMakeTrans(smDesc, ActiveOpen);
                break;
            case 'r'    :
                FwSmMakeTrans(smDesc, ReceiveSyn);
                break;
            case  's'   :
                FwSmMakeTrans(smDesc, ReceiveAck);
                break;
            case  'c'   :
                FwSmMakeTrans(smDesc, Close);
                break;
            case  'f'   :
                FwSmMakeTrans(smDesc, ReceiveFIN);
                break;
            case  'e'   :
                FwSmMakeTrans(smDesc, CloseExt);
                break;
            case  't'   :
                FwSmMakeTrans(smDesc, TimerExpire);
                break;

            default:
                printf( "unrecognized key" );
                break;

        }
    }
	return EXIT_SUCCESS;
}
