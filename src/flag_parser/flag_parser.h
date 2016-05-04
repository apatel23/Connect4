/**
 * Header file containing a couple simple methods that can handle flag parsing,
 * as well as a struct to hold the results.
 *
 * Feel free to do this differently if you want to.
 */

#pragma once
#include <string>


/**
 * Enum representing the replacement strategy to use.
 */
enum class HeuristicStrategy {
  SIMPLE
};

enum class WhoVWho {
  PvP,
  CvP,
  CvC
};


/**
 * The options derived from command-line flags.
 */
struct FlagOptions {

  /**
   * The replacement strategy to use.
   */
  HeuristicStrategy strategy = HeuristicStrategy::SIMPLE;

  /**
   * Whether information needs to be output for each memory access.
   */
  WhoVWho whovwho = WhoVWho::CvP;

  /**
   * The maximum number of frames that can be allocated to a process.
   */
  int max_depth = 8;
};


/**
 * Prints information about how to use this program.
 */
void print_usage();


/**
 * Parses any provided flags, populating the provided FlagOptions instance.
 * Returns true if the parsing succeeded, or false in the case of errors. If the
 * -h flag is detected, instructions are printed and the program exists instead.
 */
bool parse_flags(int argc, char** argv, FlagOptions& flags);