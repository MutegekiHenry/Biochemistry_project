#include <time.h>
#include <argp.h>
#include <stdio.h>
#include <stdlib.h>

const char *argp_program_version = "program-version 1.0";
const char *argp_program_bug_address = "<lubegaritah@gmail.com>";

/* Program documentation. */
static char doc[] = "Some documentation";

/* Our argument parser.  The options, parser, and
   args_doc fields are zero because we have neither options or
   arguments; doc and argp_program_bug_address will be
   used in the output for ‘--help’, and the ‘--version’
   option will print out argp_program_version. */
static struct argp argp = { 0, 0, 0, doc };


int main(int argc, char *argv[])
{
    argp_parse (0, argc, argv, 0, 0, 0);
    exit (0);



}