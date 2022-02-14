#include <stdio.h>
#include <stdlib.h>

typedef struct config {
    char* name;
    int mode;
} config_t;


/**
 * Parses command line arguments into a `config_t` struct. Returns a pointer
 * to the struct on success or NULL on failure.
*/
config_t* parse_command_line_arguments(int argc, char* argv[]) {
    config_t* config = malloc(12);

    if (argc != 3) {
        return NULL;
    }

    config->name = argv[1];
    config->mode = atoi(argv[2]);

    return config;
}

int main(int argc, char* argv[]) {
    config_t* config = parse_command_line_arguments(argc, argv);
   if (config == NULL) {
       fprintf(stderr, "Usage: ./mem_error1.c <name> <mode>\n");
       exit(EXIT_FAILURE);
   }

    // do some stuff
    printf("Starting the program in mode %d with name %s\n", config->mode, config->name); 
    
    // perform cleanup and exit
    free(config);
    exit(EXIT_SUCCESS);
}
