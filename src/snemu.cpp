#include <iostream>
#include <cstring>
#include <string>

#include "args.h"
#include "config.h"

int main(int argc, char **argv) {
	Args args{argc, argv};

	char *program_name = args.advance();
	Region region = Region::US;
	char *input_file = nullptr;

	while (!args.empty()) {
		char *curr = args.advance();
		if (!curr) break;

		if (std::strcmp(curr, "-r") || std::strcmp(curr, "--region")) {
			char *region_str = args.advance();
			if (!region_str) {
				fprintf(stderr, "ERROR: Missing region!\n");
				exit(1);
			}

			if (std::strcmp(region_str, "US") == 0 || std::strcmp(region_str, "us") == 0) {
				region = Region::US;
			} else if (std::strcmp(region_str, "JPN") == 0 || std::strcmp(region_str, "jpn") == 0) {
				region = Region::JPN;
			} else if (std::strcmp(region_str, "PAL") == 0 || std::strcmp(region_str, "pal") == 0) {
				region = Region::PAL;
			} else {
				fprintf(stderr, "ERROR: Invalid region (%s)!\n", region_str);
				exit(1);
			}
		} else {
			input_file = curr;
			break;
		}
	}
}
