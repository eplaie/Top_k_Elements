#include "hash.hpp"

string TextCollector(const string &caminhoArquivo) {
    ifstream arquivo(caminhoArquivo);
    string conteudo;

    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            conteudo += linha + "\n";
        }
        arquivo.close();
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

unordered_set<string> StopWordExtractor(const string &caminhoArquivo) {
    unordered_set<string> stopwords;
    ifstream arquivo(caminhoArquivo);

    if (arquivo.is_open()) {
        string palavra;

        while (arquivo >> palavra) {
            stopwords.insert(palavra);
        }
        arquivo.close();
    } 
    return stopwords;
}

string stopWordCleaner(const string &textoTratado, unordered_set<string> &stopwords) {
    stringstream separador(textoTratado);
    string palavra;
    string text_s_StopWord;

    while (separador >> palavra) {
        if (stopwords.find(palavra) == stopwords.end() && palavra.find_first_of("—-") == string::npos) {
            text_s_StopWord += palavra + " ";
        }
    }

    return text_s_StopWord;
}

unordered_map<string, int> occurrenceCounter(const string &texto) {
    unordered_map<string, int> palavras;
    istringstream separador(texto);
    string palavra;

    while (separador >> palavra) {
        palavras[palavra]++;
    }

    return palavras;
}
