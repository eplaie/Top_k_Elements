#include "hash.hpp"

string TextCollector(const string &text_position) {
    ifstream arq(text_position);
    string conteudo;

    if (arq.is_open()) {
        string line;
        while (getline(arq, line)) {
            conteudo += line + "\n";
        }
        arq.close();
    }
    return conteudo;
}

string TextAnalyzer(const string &texto) {
    string New_text;

    for (char c : texto) {
        New_text += tolower(c);
    }

    New_text.erase(remove_if(New_text.begin(), New_text.end(), ::ispunct), New_text.end());

    return New_text;
}

unordered_set<string> StopWordExtractor(const string &text_position) {
    unordered_set<string> stopwords;
    ifstream arq(text_position);

    if (arq.is_open()) {
        string palavra;

        while (arq >> palavra) {
            stopwords.insert(palavra);
        }
        arq.close();
    } 
    return stopwords;
}

string stopWordCleaner(const string &text_final, unordered_set<string> &stopwords) {
    stringstream concatenada(text_final);
    string palavra;
    string text_s_StopWord;

    while (concatenada >> palavra) {
        if (stopwords.find(palavra) == stopwords.end() && palavra.find_first_of("—-") == string::npos) {
            text_s_StopWord += palavra + " ";
        }
    }

    return text_s_StopWord;
}

unordered_map<string, int> occurrenceCounter(const string &texto) {
    unordered_map<string, int> indice;
    istringstream concatenada(texto);
    string palavra;

    while (concatenada >> palavra) {
        indice[palavra]++;
    }

    return indice;
}
