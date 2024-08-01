#include <stdio.h>
#include <stdlib.h>

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
    switch (argv[1][0]) {
        case '+':
            if (argc == 2) goto print_help_message;

            if (argc == 3) {
                double param_one = atof(argv[2]);
                printf("%f\n", param_one);

                return 0;
            } else {
                double total = 0;

                // start of the indices offset by the program name + command 
                int i = 2;
                while (i < argc) {
                    total += atof(argv[i]);
                    i++;
                };

                printf("%f\n", total);
                return 0;
            };

            break;
        case '-': 
            break;
        default: 
            break;
    }

    return 0;
}
