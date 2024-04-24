/*
 * =====================================================================================
 *
 *       Filename:  config.h
 *
 *    Description:  Configuration definition for C web server
 *
 *        Version:  1.0
 *        Created:  15/04/2024 09:58:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef CONFIG_H_
#define CONFIG_H_

/* *********** Typedefs *********** */

typedef struct my_config my_config_t;

/* *********** Config *********** */

struct my_config {
    int port;
};

my_config_t *my_config_parse(int argc, char **argv);
void my_config_cleaup(my_config_t *config);

#endif /* CONFIG_H_ */
