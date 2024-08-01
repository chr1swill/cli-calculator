#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PROGRAM_NAME argv[0]

#define INDEX_INTO_ARGV_COMMAND 1
#define INDEX_INTO_ARGV_PARAM_ONE 2
#define INDEX_INTO_ARGV_PARAM_TWO 3

#define ARGC_WITH_NO_PARAMS 2
#define ARGC_WITH_ONE_PARAM 3

int main(int argc, char **argv) {
    if (argc < 3) {
print_help_message: 
        puts("Syntax: <command> [...parameters]\n");
        puts("Accepted commands: \n");
        puts("  [+] - addition ..................... returns the sum.\n");
        puts("  [-] - subtraction .................. returns the difference.\n");
        puts("  [x] - multiplication ............... returns the product.\n");
        puts("  [/] - division ..................... returns the quotient.\n");
        puts("  [help] ............................. to print this help message\n");
        puts("\n");
        puts("Example:\n");
        printf("Input: %s + 10 10\n", PROGRAM_NAME);
        puts("Output: 20\n");

        return 0;
    };

    if (argv[INDEX_INTO_ARGV_COMMAND]) {
        int help_needed = strncmp(argv[INDEX_INTO_ARGV_COMMAND], "help", sizeof("help"));
        if (help_needed == 0) {
            goto print_help_message;
        };
    };

    if (argv[INDEX_INTO_ARGV_PARAM_ONE]) {
        int help_needed = strncmp(argv[INDEX_INTO_ARGV_PARAM_ONE], "help", sizeof("help"));
        if (help_needed == 0) {
            goto print_help_message;
        };
    };

    if (argv[INDEX_INTO_ARGV_PARAM_TWO]) {
        int help_needed = strncmp(argv[INDEX_INTO_ARGV_PARAM_TWO], "help", sizeof("help"));
        if (help_needed == 0) {
            goto print_help_message;
        };
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
        case 'x': 
            if (argc == ARGC_WITH_NO_PARAMS) goto print_help_message;

            if (argc == ARGC_WITH_ONE_PARAM) {
                double param_one = atof(argv[INDEX_INTO_ARGV_PARAM_ONE]);
                printf("%f\n", param_one);
                return 0;
            } else {
                double total = atof(argv[INDEX_INTO_ARGV_PARAM_ONE]);

                int i = INDEX_INTO_ARGV_PARAM_TWO;
                while (i < argc) {
                    total *= atof(argv[i]);
                    i++;
                };

                printf("%f\n", total);
                return 0;
            };

            break;
        case '/': 
            if (argc == ARGC_WITH_NO_PARAMS) goto print_help_message;

            if (argc == ARGC_WITH_ONE_PARAM) {
                double param_one = atof(argv[INDEX_INTO_ARGV_PARAM_ONE]);
                printf("%f\n", param_one);
                return 0;
            } else {
                double total = atof(argv[INDEX_INTO_ARGV_PARAM_ONE]);

                int i = INDEX_INTO_ARGV_PARAM_TWO;
                while (i < argc) {
                    total /= atof(argv[i]);
                    i++;
                };

                printf("%f\n", total);
                return 0;
            };

            break;
        case '!':
            if (argc == ARGC_WITH_NO_PARAMS) goto print_help_message;

            // right now factorial will only work with one numeber
            if (argc > ARGC_WITH_ONE_PARAM) puts("Command ! is only able to process a single parameter");

            // check of param is negative number
            if (atof(argv[INDEX_INTO_ARGV_PARAM_ONE]) < 0) {
                puts("undefined");
                return 0;
            };

            // check if param is 0
            if (atof(argv[INDEX_INTO_ARGV_PARAM_ONE]) == 0) {
                puts("0");
                return 0;
            };

            double total = round(atof(argv[INDEX_INTO_ARGV_PARAM_ONE]));
            printf("init total: %f\n", total);

            double param = round(atof(argv[INDEX_INTO_ARGV_PARAM_ONE])) - 1;
            printf("init param: %f\n", param);
            while (param > 0) {
                total *= param;
                param--;
            };

            printf("%f\n", total);
            return 0;

            break;
        default: 
            fprintf(stderr, "Invalid command was provided: %s\n", argv[INDEX_INTO_ARGV_COMMAND]);
            return -1;
            break;
    };

    return 0;
}
