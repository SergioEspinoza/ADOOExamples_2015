/**
 * @file TCPFSM.c
 *
 * @author FW Profile code generator version 3.1
 * @date Created on: May 26 2015
 */

#include <stdlib.h>
#include <stdio.h>

/** FW Profile function definitions */
#include "FwProfile/FwSmSCreate.h"
#include "FwProfile/FwSmConfig.h"

/** TCPFSM function definitions */
#include "TCPFSM.h"

void entryClosed(FwSmDesc_t arg)
{
    printf("entryClosed");
}
void exitClosed(FwSmDesc_t arg)
{
    printf("exitClosed");
}
void entryListen(FwSmDesc_t arg)
{
    printf("entryListen");
}
void exitListen(FwSmDesc_t arg)
{
    printf("exitListen");
}
void entrySynSent(FwSmDesc_t arg)
{
    printf("entrySynSent");
}
void exitSynSent(FwSmDesc_t arg)
{
    printf("exitSynSent");
}
void entrySynReceived(FwSmDesc_t arg)
{
    printf("entrySynReceived");
}
void exitSynReceived(FwSmDesc_t arg)
{
    printf("exitSynReceived");
}
void entryEstablished (FwSmDesc_t arg)
{
    printf("entryEstablished");
}
void exitEstablished(FwSmDesc_t arg)
{
    printf("exitEstablished");
}
void entryFinWait1 (FwSmDesc_t arg)
{
    printf("entryFinWait1");
}
void exitFinWait1(FwSmDesc_t arg)
{
    printf("exitFinWait1");
}
void entryCloseWait(FwSmDesc_t arg)
{
    printf("entryCloseWait");
}
void exitCloseWait(FwSmDesc_t arg)
{
    printf("exitCloseWait");
}
void entryClosing(FwSmDesc_t arg)
{
    printf("entryClosing");
}
void exitClosing(FwSmDesc_t arg)
{
    printf("exitClosing");
}
void entryTimeWait(FwSmDesc_t arg)
{
    printf("entryTimeWait");
}
void exitTimeWait(FwSmDesc_t arg)
{
    printf("exitTimeWait");
}
void entryLastAck(FwSmDesc_t arg)
{
    printf("entryLastAck");
}
void ExitLastAck(FwSmDesc_t arg)
{
    printf("ExitLastAck");
}

void Action1( FwSmDesc_t arg )
{
    printf( "Action 1" );
}

/* ----------------------------------------------------------------------------------------------------------------- */
FwSmDesc_t TCPFSMCreate(void* smData)
{
	const FwSmCounterU2_t CLOSED = 1;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_CLOSED = 2;	/* The number of transitions out of state */
	const FwSmCounterU2_t LISTEN = 2;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_LISTEN = 1;	/* The number of transitions out of state */
	const FwSmCounterU2_t SYN_SENT = 3;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_SYN_SENT = 1;	/* The number of transitions out of state */
	const FwSmCounterU2_t SYN_RECEIVED = 4;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_SYN_RECEIVED = 1;	/* The number of transitions out of state */
	const FwSmCounterU2_t ESTABLISHED = 5;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_ESTABLISHED = 2;	/* The number of transitions out of state */
	const FwSmCounterU2_t FIN_WAIT_1 = 6;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_FIN_WAIT_1 = 2;	/* The number of transitions out of state */
	const FwSmCounterU2_t CLOSE_WAIT = 7;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_CLOSE_WAIT = 1;	/* The number of transitions out of state */
	const FwSmCounterU2_t FIN_WAIT_2 = 8;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_FIN_WAIT_2 = 1;	/* The number of transitions out of state */
	const FwSmCounterU2_t CLOSING = 9;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_CLOSING = 1;	/* The number of transitions out of state */
	const FwSmCounterU2_t TIME_WAIT = 10;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_TIME_WAIT = 1;	/* The number of transitions out of state */
	const FwSmCounterU2_t LAST_ACK = 11;		/* The identifier of state */
	const FwSmCounterU2_t N_OUT_OF_LAST_ACK = 1;	/* The number of transitions out of state */

	/** Create state machine smDesc */
	FW_SM_INST(smDesc,
		11,	/* NSTATES - The number of states */
		0,	/* NCPS - The number of choice pseudo-states */
		15,	/* NTRANS - The number of transitions */
		21,	/* NACTIONS - The number of state and transition actions */
		0	/* NGUARDS - The number of transition guards */
	);
	FwSmInit(&smDesc);

	/** Configure the state machine smDesc */
	FwSmSetData(&smDesc, smData);
	FwSmAddState(&smDesc, CLOSED, N_OUT_OF_CLOSED, &entryClosed, &exitClosed, NULL, NULL);
	FwSmAddState(&smDesc, LISTEN, N_OUT_OF_LISTEN, &entryListen, &exitListen, NULL, NULL);
	FwSmAddState(&smDesc, SYN_SENT, N_OUT_OF_SYN_SENT, &entrySynSent, &exitSynSent, NULL, NULL);
	FwSmAddState(&smDesc, SYN_RECEIVED, N_OUT_OF_SYN_RECEIVED, &entrySynReceived, &exitSynReceived, NULL, NULL);
	FwSmAddState(&smDesc, ESTABLISHED, N_OUT_OF_ESTABLISHED, &entryEstablished, NULL, &exitEstablished, NULL);
	FwSmAddState(&smDesc, FIN_WAIT_1, N_OUT_OF_FIN_WAIT_1, &entryFinWait1, NULL, &exitFinWait1, NULL);
	FwSmAddState(&smDesc, CLOSE_WAIT, N_OUT_OF_CLOSE_WAIT, &entryCloseWait, &exitCloseWait, NULL, NULL);
	FwSmAddState(&smDesc, FIN_WAIT_2, N_OUT_OF_FIN_WAIT_2, &entryClosing, &exitClosing, NULL, NULL);
	FwSmAddState(&smDesc, CLOSING, N_OUT_OF_CLOSING, &entryClosing, &exitClosing, NULL, NULL);
	FwSmAddState(&smDesc, TIME_WAIT, N_OUT_OF_TIME_WAIT, &entryTimeWait, &exitTimeWait, NULL, NULL);
	FwSmAddState(&smDesc, LAST_ACK, N_OUT_OF_LAST_ACK, &entryLastAck, &ExitLastAck, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, PassiveOpen, CLOSED, LISTEN, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, ActiveOpen, CLOSED, SYN_SENT, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, ReceiveSyn, LISTEN, SYN_RECEIVED, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, ReceiveSyn, SYN_SENT, ESTABLISHED, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, ReceiveAck, SYN_RECEIVED, ESTABLISHED, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, Close, ESTABLISHED, FIN_WAIT_1, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, ReceiveFIN, ESTABLISHED, CLOSE_WAIT, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, ReceiveAck, FIN_WAIT_1, FIN_WAIT_2, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, ReceiveFIN, FIN_WAIT_1, CLOSING, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, CloseExt, CLOSE_WAIT, LAST_ACK, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, ReceiveFIN, FIN_WAIT_2, TIME_WAIT, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, ReceiveAck, CLOSING, TIME_WAIT, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, TimerExpire, TIME_WAIT, CLOSED, NULL, NULL);
	FwSmAddTransStaToSta(&smDesc, TimerExpire, LAST_ACK, CLOSED, NULL, NULL);
	FwSmAddTransIpsToSta(&smDesc, CLOSED, &Action1);

	return &smDesc;
}
