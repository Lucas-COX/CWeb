/*
 * =====================================================================================
 *
 *       Filename:  config.c
 *
 *    Description:  Utility functions related to CLI configuration
 *
 *        Version:  1.0
 *        Created:  15/04/2024 10:05:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <my_config.h>

#include <stdlib.h>

/**
 * @brief Frees the config memory
 *
 * @param[my_config_t *] config config object to be freed
 */
void my_config_cleanup(my_config_t *config)
{
    if (config) {
        free(config);
    }
}

/**
 * @brief Parses the command line arguments
 *
 * @param[int] argc Count of arguments
 * @param[char **] argv Arguments
 * @return A config object with the parsed arguments
 */
my_config_t *my_config_parse(int argc, char **argv)
{
    my_config_t *config = malloc(sizeof(my_config_t));

    // TODO: parse cli options and remove from argv
    // port should be the only argument that remains after removing options
    if (argc < 2) {
        free(config);
        return NULL;
    }
    config->port = atoi(argv[1]);
    return config;
}
