#ifndef hash_HPP
#define hash_HPP

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <locale>
#include <codecvt>


using namespace std;

string TextCollector(const string& caminhoArquivo);
string TextAnalyzer(const string& texto);
unordered_set<string> StopWordExtractor(const string& caminhoArquivo);
string stopWordCleaner(const string& textoTratado, unordered_set<string>& stopwords);
unordered_map<string, int> occurrenceCounter(const string& texto);

#endif 

