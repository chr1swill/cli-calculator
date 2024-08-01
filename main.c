#include <stdio.h>
#include <stdlib.h>

#define INDEX_INTO_ARGV_COMMAND 1
#define INDEX_INTO_ARGV_PARAM_ONE 2
#define INDEX_INTO_ARGV_PARAM_TWO 3

#define ARGC_WITH_NO_PARAMS 2
#define ARGC_WITH_ONE_PARAM 3

int main(int argc, char **argv) {
    if (argc < 3) {
print_help_message: 
        puts("No input was provided to process\n");
        puts("Syntax: <command> [...parameters]\n");
        puts("Accepted commands: \n");
        puts("  + ..................... returns the sum of the provided parameters.\n");
        puts("  - ..................... returns the difference of the provided parameters.\n");

        return 0;
    };

    // checking provided command
    switch (argv[INDEX_INTO_ARGV_COMMAND][0]) {
        case '+':
            if (argc == ARGC_WITH_NO_PARAMS) goto print_help_message;

            if (argc == ARGC_WITH_ONE_PARAM) {
                double param_one = atof(argv[INDEX_INTO_ARGV_PARAM_ONE]);
                printf("%f\n", param_one);

                return 0;
            } else {
                double total = 0;

                // start of the indices offset by the program name + command 
                int i = INDEX_INTO_ARGV_PARAM_ONE;
                while (i < argc) {
                    total += atof(argv[i]);
                    i++;
                };

                printf("%f\n", total);
                return 0;
            };

            break;
        case '-': 
            if (argc == ARGC_WITH_NO_PARAMS) goto print_help_message;

            if (argc == ARGC_WITH_ONE_PARAM) {
                double param_one = atof(argv[INDEX_INTO_ARGV_PARAM_ONE]);
                printf("%f\n", param_one);

                return 0;
            } else {
                double total = atof(argv[INDEX_INTO_ARGV_PARAM_ONE]);

                int i = INDEX_INTO_ARGV_PARAM_TWO;
                while (i < argc) {
                    total -= atof(argv[i]);
                    i++;
                };

                printf("%f\n", total);
                return 0;
            };

            break;
        default: 
            fprintf(stderr, "Invalid command was provided: %s\n", argv[INDEX_INTO_ARGV_COMMAND]);
            return -1;
            break;
    }

    return 0;
}
