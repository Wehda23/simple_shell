#include "waheed.h"

/**
 * signal_to_handle - Configures ^C not to terminate our shell
 * @sig: Incoming Signal
 */

void signal_to_handle(int sig)
{
	if (sig == SIGINT)
	{
		cprint("\n$ ");
	}
}