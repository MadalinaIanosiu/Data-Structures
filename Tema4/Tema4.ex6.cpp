#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

struct Nod
{
    char caracter;
    int freq;
    string codificare;
    Nod* parinte;
    Nod* stanga;
    Nod* dreapta;

    Nod()
    {
        caracter = NULL;
        codificare = "";
        freq = 0;
        parinte = nullptr;
        stanga = nullptr;
        dreapta = nullptr;
    }

    Nod(int prioritate)
    {
        caracter = NULL;
        freq = prioritate;
        codificare = "";
        parinte = nullptr;
        stanga = nullptr;
        dreapta = nullptr;
    }

};

class PRIORITY_QUEUE {
private:
    vector<Nod*> DATA;
    int SIZE;

public:
    PRIORITY_QUEUE()
    {
        SIZE = 0;
    }

    void INSERT(Nod* nou);
    void EXTRACT_MIN();
    Nod* MIN_ELEMENT();
    void DECREASE_KEY(int pos, Nod* val);
    void MIN_HEAPFY(int pos);
    void DISPLAY();
    int GET_SIZE()
    {
        return SIZE;
    }
};


class Huffman {
private:
    Nod* radacina;
public:
    Huffman()
    {
        radacina = nullptr;
    }
    void formareHuffman(PRIORITY_QUEUE prioritate);
    void afisareHuffman(string spatiu, Nod* nod_curent, bool stanga, bool radacina);
    Nod* get_radacina() {
        return radacina;
    }
    string creareCod(char litera_c)
    {
        queue<Nod*> v_caut;

        v_caut.push(radacina);
        while (!v_caut.empty())
        {
            Nod* aux = v_caut.front();
            v_caut.pop();
            //cout << aux->caracter;
            if (aux != nullptr && aux->caracter == litera_c)
            {
                string cod = "";
                Nod* curent = aux;
                while (curent != radacina)
                {
                    if (curent == curent->parinte->stanga)
                        cod += '0';
                    else if (curent == curent->parinte->dreapta)
                        cod += '1';
                    curent = curent->parinte;
                }
                reverse(cod.begin(), cod.end());
                return cod;
            }
            if (aux->stanga != nullptr)
                v_caut.push(aux->stanga);
            if (aux->dreapta != nullptr)
                v_caut.push(aux->dreapta);
        }
        return "EROARE";
    }
};

void citire(string& text)
{
    ifstream f("text.txt");
    stringstream buffer;
    buffer << f.rdbuf();
    text = buffer.str();
}

void prelucrare(vector<Nod*>& tabel, string text, PRIORITY_QUEUE& prioritate)
{
    for (int i = 0; i < 127; i++)
    {
        Nod* to_add = new Nod;
        to_add->caracter = (char)i;
        tabel.push_back(to_add);
    }

    int l_text = text.size();
    for (int i = 0; i < l_text; i++)
        tabel[(int)text[i]]->freq++;

    for (int i = 0; i < 127; i++)
        if (tabel[i]->freq)
            prioritate.INSERT(tabel[i]);
}

void creareCoduri(vector<Nod*> tabel, Huffman arbore)
{
    for (int i = 0; i < 127; i++)
    {
        if (tabel[i]->freq)
            tabel[i]->codificare = arbore.creareCod(tabel[i]->caracter);
    }
}

void afisareCoduri(vector<Nod*> tabel)
{
    cout << "Char    Cod" << endl;
    for (int i = 0; i < 127; i++)
        if (tabel[i]->freq)
        {
            cout << "' " << tabel[i]->caracter << " '" << "   " << tabel[i]->codificare << endl;
        }
}

void afisareTextCodificat(vector<Nod*> tabel, string text)
{
    for (int i = 0; i < text.size(); i++)
        cout << tabel[(int)text[i]]->codificare << " ";
}

int main()
{
    string text;
    vector<Nod*> tabel;
    PRIORITY_QUEUE prioritate;
    Huffman arbore;
    citire(text);
    prelucrare(tabel, text, prioritate);
    arbore.formareHuffman(prioritate);
    arbore.afisareHuffman("", arbore.get_radacina(), false, true);
    creareCoduri(tabel, arbore);
    afisareCoduri(tabel);
    afisareTextCodificat(tabel, text);
    return 0;
}

void PRIORITY_QUEUE::INSERT(Nod* nou)
{
    Nod* insert = new Nod;
    insert->freq = 99999999;
    DATA.push_back(insert);
    SIZE++;
    DECREASE_KEY(SIZE - 1, nou);
}

void PRIORITY_QUEUE::EXTRACT_MIN()
{
    if (SIZE > 1)
    {
        DATA[0] = DATA[SIZE - 1];
        DATA.pop_back();
        SIZE--;
        MIN_HEAPFY(0);
        return;
    }
    if (SIZE == 1)
    {
        SIZE--;
        DATA.clear();
        return;
    }
    if (SIZE == 0)
    {
        cout << "Coada este goala!" << endl;
    }
}

Nod* PRIORITY_QUEUE::MIN_ELEMENT()
{
    try {
        return DATA[0];
    }

    catch (...)
    {
        cout << "Coada este goala" << endl;
    }
}

void PRIORITY_QUEUE::DECREASE_KEY(int pos, Nod* val)
{
    if (pos <= SIZE - 1)
    {
        if (val->freq < DATA[pos]->freq)
        {
            DATA[pos] = val;
            int p = (pos - 1) / 2;
            while (pos > 0 && DATA[p]->freq > val->freq)
            {
                DATA[pos] = DATA[p];
                pos = p;
                p = (pos - 1) / 2;
            }
            DATA[pos] = val;
        }
    }
    else
        cout << "Nu exista pozitia specificata" << endl;
}

void PRIORITY_QUEUE::MIN_HEAPFY(int pos)
{
    if (pos <= SIZE - 1)
    {
        int st, dr, imin;
        st = 2 * pos + 1;
        dr = 2 * pos + 2;
        imin = pos;

        if (st < SIZE && DATA[st]->freq < DATA[imin]->freq)
            imin = st;
        if (dr < SIZE && DATA[dr]->freq < DATA[imin]->freq)
            imin = dr;
        if (imin != pos)
        {
            swap(DATA[pos], DATA[imin]);
            MIN_HEAPFY(imin);
        }
    }
    else
        cout << "Nu exista pozitia specificata" << endl;
}

void PRIORITY_QUEUE::DISPLAY()
{
    for (int i = 0; i < DATA.size(); i++)
        cout << DATA[i]->caracter << " ";
    cout << endl;
}

void Huffman::formareHuffman(PRIORITY_QUEUE prioritate)
{
    while (prioritate.GET_SIZE() != 1)
    {
        Nod* aux1, * aux2;
        Nod* nou = new Nod;
        aux1 = prioritate.MIN_ELEMENT();
        prioritate.EXTRACT_MIN();
        aux2 = prioritate.MIN_ELEMENT();
        prioritate.EXTRACT_MIN();
        nou->freq = aux1->freq + aux2->freq;
        nou->stanga = aux1;
        nou->dreapta = aux2;
        aux1->parinte = nou;
        aux2->parinte = nou;
        prioritate.INSERT(nou);
    }
    radacina = prioritate.MIN_ELEMENT();

}

void Huffman::afisareHuffman(string spatiu, Nod* nod_curent, bool stanga, bool radacina)
{
    if (nod_curent != nullptr)
    {
        cout << spatiu;
        if (!radacina)
        {
            if (stanga)
                cout << "|-0-";
            else
                cout << "`-1-";
        }
        if (!radacina)
        {
            if (nod_curent->caracter)
                cout << nod_curent->caracter << endl;
            else
                cout << "nil" << endl;
        }
        else
            cout << "nil--." << endl;

        afisareHuffman(spatiu + (stanga ? "|    " : "     "), nod_curent->stanga, true, false);
        afisareHuffman(spatiu + (stanga ? "|    " : "     "), nod_curent->dreapta, false, false);
    }
}
