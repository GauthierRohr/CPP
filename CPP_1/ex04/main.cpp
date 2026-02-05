// Il faut :
// 	1.	Lire une ligne (getline)
// 	2.	Chercher s1 (find)
// 	3.	Découper la ligne (substr)
// 	4.	Construire la nouvelle ligne (+=)
// 	5.	Écrire dans le fichier (ofstream)

// Create a program that takes three parameters in the following order: a filename and
// two strings, s1 and s2.
// It must open the file <filename> and copy its content into a new file
// <filename>.replace, replacing every occurrence of s1 with s2.
// Using C file manipulation functions is forbidden and will be considered cheating.
// All the member functions of the class std::string are allowed, except replace.
// Use them wisely!
// Of course, handle unexpected inputs and errors. You must create and turn in your
// own tests to ensure that your program works as expected.

#include <iostream>
#include <fstream>
#include <string>

// Vérifie args :
// - s1 pas vide
// - fichier src ouvrable
// - fichier dest creable
//
int check_args(	const std::string& filename,
				const std::string& s1)
{
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: cannot open input file" << std::endl;
		return 1;
	}
	infile.close();

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: cannot create output file" << std::endl;
		return 1;
	}
	outfile.close();

	return 0;
}

// Remplace toutes les occurrences de s1 par s2 dans une ligne
//
std::string replace_line(const std::string& line,
						 const std::string& s1,
						 const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += line.substr(pos);

	return result;
}

// Lit fichier source, replace + écrit dans le fichier destination
//
void process_file(const std::string& filename,
				  const std::string& s1,
				  const std::string& s2)
{
	std::ifstream infile(filename.c_str());
	std::ofstream outfile((filename + ".replace").c_str());

	std::string line;
	while (std::getline(infile, line))
	{
		outfile << replace_line(line, s1, s2);
		if (!infile.eof())
			outfile << std::endl;
	}

	infile.close();
	outfile.close();
}

int main(int argc, char **argv)
{
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	if (check_args(filename, s1))
	{
		return 1;
	}
	process_file(filename, s1, s2);
	return 0;
}
