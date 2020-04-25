#include "header.h"
#include "Sender_agent_header.h"

int sender_sends_mesg()
{
	printf("\n\nI am Agent %d: Hello, World!\n", ID);

	add_hello_message(ID);

	return 0;
}
