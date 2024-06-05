#include <iostream>
#include <vector>

using namespace std;

class livro{
    public:
        string titulo;
        string autor;
        string editora;

        livro(string _titulo, string _autor, string _editora, string _publicacao, string _isbn);

        string getPublicacao();

        string getIsbn();

        void novoExemplar();

        int getExemplares();


        void deletarExemplar();

        bool checarDisponibilidade();

        void setId(vector<livro> &livros);
        
        int getId();
    
    private:
        string publicacao;
        string isbn;
        int exemplares;
        int id;

};