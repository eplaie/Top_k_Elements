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
    string Texto_tratado;

    for (char c : texto) {
        Texto_tratado += tolower(c);
    }

    Texto_tratado.erase(remove_if(Texto_tratado.begin(), Texto_tratado.end(), ::ispunct), Texto_tratado.end());

    return Texto_tratado;
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
    string texto_semSW;

    while (separador >> palavra) {
        if (stopwords.find(palavra) == stopwords.end() && palavra.find_first_of("—-") == string::npos) {
            texto_semSW += palavra + " ";
        }
    }

    return texto_semSW;
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
