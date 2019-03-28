#include "../DSys.h"

int main() {

	std::string path = "src/_test/file.txt";
	DS::Reader reader1(DS::ReaderType::_FILE, path);

	DS::Writer writer1(reader1.getText());
	writer1.Write();

	while (true);
}