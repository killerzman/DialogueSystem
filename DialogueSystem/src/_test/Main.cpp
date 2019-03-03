#include "../DSys.h"

int main() {

	std::string path = "src/_test/file.txt";
	Reader reader1(ReaderType::_FILE, path);

	Writer writer1(reader1.getText());
	writer1.Write();

	while (true);
}