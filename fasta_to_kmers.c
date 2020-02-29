#include <time.h>
#include <argp.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>

const char *argp_program_version = "fasta_to_kmers 1.0";
const char *argp_program_bug_address ="<lubegaritah@gmail.com>";

/* Program documentation. */
static char doc[] =
  "fasta_to_kmers -- a program with options and arguments using argp";

/* The options we understand. */

static struct argp_option options[] = {
 
  {"output",   'o', "FILE", 0,
   "Output to FILE instead of standard output" },
    {"input",   'i', "FILE", 0,
   "Input file for the DNA patterns" },
   {"kmer",   'k', "COUNT", OPTION_ARG_OPTIONAL,
   "kmer size the program  (default 10)"},
  { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments
{
  char *output_file;
  char *input_file;
  int kmer_size;             /* count arg for kmer size */
};

/* Parse a single option. */
static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
  /* Get the input argument from argp_parse, which we
     know is a pointer to our arguments structure. */
  struct arguments *arguments = state->input;

  switch (key)
    {
  
    case 'o':
      arguments->output_file = arg;
      break;

      case 'i':
      arguments->input_file = arg;
      break;


      case 'k':
      arguments->kmer_size = arg ? atoi (arg) : 10;
      break;

    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

/* Our argp parser. */
static struct argp argp = { options, parse_opt,doc };




int main(int argc, char *argv[])
{
    struct arguments arguments;

  /* Default values. */
  arguments.output_file = "-";
  arguments.input_file = "-";
  arguments.kmer_size = 10;

  char *keys[7];
  char *values[18];
  int i=0;

  /* Parse our arguments; every option seen by parse_opt will
     be reflected in arguments. */
  argp_parse (&argp, argc, argv, 0, 0, &arguments);
// for (int i = 0; i <= arguments.kmer_size; i++)
// {
//    printf ("OUTPUT_FILE = %s\nINPUT FILE = %s",
//           arguments.output_file,arguments.input_file);
// }


FILE *fp = fopen("genes.fa", "r");
      if(fp == NULL) {
         perror("Unable to open file!");
         exit(1);
     }
     char chunk[128];
     while(fgets(chunk, sizeof(chunk), fp) != NULL) {

            if(strchr(chunk, '>') != NULL) //checks if the line has an '>' character
        {
          keys[i]=chunk;
          fputs(keys[i], stdout);
         fputs("|*\n", stdout);  // marker string used to show where the content of the chunk array has ended
         
        }else
        {
           values[i]=chunk;
           fputs(values[i], stdout);
           fputs("|*\n", stdout);
        }
        
        i++; 
     }
 
     fclose(fp);
  

 
  exit (0);

}