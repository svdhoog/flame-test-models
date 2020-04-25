#include "header.h"
#include "Receiver_agent_header.h"

int receiver_reads_mesg()
{
	int other_id;

	START_HELLO_MESSAGE_LOOP
		other_id = hello_message->id;
	FINISH_HELLO_MESSAGE_LOOP

	printf("\n\nI am Agent %d; I received the message from Agent %d!\n", ID, other_id);

	return 0;
}
