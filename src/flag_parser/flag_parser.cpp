/**
 * This file contains implementations for methods in the flag_parser.h file.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "flag_parser/flag_parser.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

using namespace std;


void print_usage() {
  cout <<
      "Usage: ./connect_4 [options]\n"
      "\n"
      "Options:\n"
      "\n"
      "  -s, --strategy (SIMPLE)\n"
      "      The heuristic strategy to use. At the moment only SIMPLE.\n"
      "\n"
      "  -d --max-depth <positive integer>\n"
      "      The maximum number of depths the AI will serach.\n"
      "\n"
      "  -w, --who (PvP | CvP | CvC) \n"
      "      Creates the game and it tells who plays who\n"
      "\n"
      "  -h --help\n"
      "      Display a help message about these flags and exit\n"
      "\n";
}




bool parse_strategy(char* a, FlagOptions& flags ) {
  if( strcmp(a, "FIFO") == 0 ){
    flags.strategy = HeuristicStrategy::SIMPLE;
  } else {
    return false;
  }
  return true;
}

bool who_plays(char *a, FlagOptions& flags ) {
  if( strcmp(a, "PvP") == 0 ){
    flags.whovwho = WhoVWho::PvP;
  } else if ( strcmp(a, "CvP") == 0 ) {
    flags.whovwho = WhoVWho::CvP;
  } else if ( strcmp(a, "CvC") == 0 ) {
    flags.whovwho = WhoVWho::CvC;
  } else {
    return false;
  }
  return true;
}





bool parse_flags(int argc, char** argv, FlagOptions& flags) {
  static struct option long_options[] = {
    {"strategy", required_argument , NULL, 's'},
    {"who", required_argument, NULL, 'w'},
    {"max-depth", required_argument, NULL, 'd'},
    {"help", no_argument, NULL, 'h'},
    {0, 0, 0, 0}
  };

  while (true) {
    int option_index = 0;
    int flag_char = getopt_long( argc, argv, "s:w:d:h", long_options, &option_index);

    if ( flag_char == -1 ) {
      break;
    }

    switch( flag_char ) {

      case 's':
        if( ! parse_strategy(optarg, flags) ) return false;
        break;

      case 'h':
        print_usage();
        return false;
        break;

      case 'w':
        if( ! who_plays(optarg, flags) ) return false;
        break;

      case 'd':
        flags.max_depth = atoi(optarg);
        //cout << flags.max_depth << endl;
        break;

      case '?':
        return false;
        break;

      default:
        exit(1);
    }
  }

  return true;
}