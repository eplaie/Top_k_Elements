#include "heap.hpp"
#include "hash.hpp"

#include <iomanip>

#define MAX 20
#define N 10
using namespace std;

int main() {

    string nome = "—ainda";

    std::locale::global(std::locale(""));
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
    wstring palavra = converter.from_bytes(nome);
    wstring aux = converter.from_bytes("—");
    size_t pos = palavra.find(aux);

    while (pos != string::npos && palavra.find(aux, pos) != string::npos) {
        palavra.replace(pos, 1, L"*");
        pos = palavra.find(aux, pos);
    }
    string new_str = converter.to_bytes(palavra);

    // cout << "\nNew_str:" << new_str << "\n";

    vector<string> textos;
    const string caminho("./dataset/input");
    string caminhoatual("");

    for (int i = 1; i <= N; i++) {
        caminhoatual.assign(caminho).append(to_string(i)).append(".txt");
        textos.push_back(TextCollector(caminhoatual));
    }

    unordered_set<string> stopwords = StopWordExtractor("./dataset/stopwords.txt");
    unordered_map<string, int> frequencia;

    for (const string &texto : textos) {
        string texto_tratado = TextAnalyzer(texto);
        string texto_semSW = stopWordCleaner(texto_tratado, stopwords);

        unordered_map<string, int> texto_frequencia = occurrenceCounter(texto_semSW);

        for (const auto &item : texto_frequencia) {
            frequencia[item.first] += item.second;
        }
    }

    HeapMAX HeapMaxima;

    for (const auto &item : frequencia) {
        HeapMaxima.inserir(DataPair(item.first, item.second));
    }
    HeapMaxima.cont = 0;
    cout << "------------------------------" << endl << endl; 
    cout << "Impressão da Heap" << endl << endl; 
    for (int i = 0; i < MAX; ++i) {
        auto valor = HeapMaxima. getheap(i);
        int space = (50 - valor.palavra.size() - 1);
        cout << valor.palavra << setw(space) << left << " " << setw(10) << right << valor.freq << endl;
    }
    cout << "\nImpressão da Heap Ordenada" << endl << endl; 
    for (size_t i = 0; i < MAX; ++i) { 
        DataPair pair = HeapMaxima.PesquisaMAX();
        int space = (50 - pair.palavra.size() - 1);
        cout << pair.palavra << setw(space) << left << " " << setw(10) << right << pair.freq << endl;
    }

    return 0;
}
