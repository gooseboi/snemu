#pragma once

struct Args {
	public:
		Args(int _argc, char **_argv) : argc{_argc}, argv{_argv} {}

		char *advance() {
			if (this->argc-- == 0) return nullptr;
			else return *(this->argv++);
		}

		void skip() {
			this->advance();
		}

		bool empty() const {
			return argc == 0;
		}

	private:
		int argc;
		char **argv;
};
