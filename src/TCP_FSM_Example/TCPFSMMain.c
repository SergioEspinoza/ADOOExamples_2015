/**
 * @file TCPFSMMain.c
 *
 * @author FW Profile code generator version 3.1
 * @date Created on: May 26 2015
 */

#include <stdio.h>
#include <stdlib.h>

/** FW Profile function definitions */
#include "FwProfile/FwSmConstants.h"
#include "FwProfile/FwSmSCreate.h"
#include "FwProfile/FwSmConfig.h"
#include "FwProfile/FwSmCore.h"

/** TCPFSM function definitions */
#include "TCPFSM.h"

int main(void)
{
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
	FwSmMakeTrans(smDesc, PassiveOpen);
	FwSmMakeTrans(smDesc, ActiveOpen);
	FwSmMakeTrans(smDesc, ReceiveSyn);
	FwSmMakeTrans(smDesc, ReceiveAck);
	FwSmMakeTrans(smDesc, Close);
	FwSmMakeTrans(smDesc, ReceiveFIN);
	FwSmMakeTrans(smDesc, CloseExt);
	FwSmMakeTrans(smDesc, TimerExpire);

	return EXIT_SUCCESS;
}