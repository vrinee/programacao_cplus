#include <iostream>
#include <vector>

using namespace std;


class livro{
    public:
        string titulo;
        string autor;
        string editora;

        livro(string _titulo, string _autor, string _editora, string _publicacao, string _isbn){
            titulo = _titulo;
            autor = _autor;
            editora = _editora;
            publicacao = _publicacao;
            isbn = _isbn;
            exemplares = 1;
        }

        string getPublicacao(){
            return publicacao;
        }

        string getIsbn(){
            return isbn;
        }

        void novoExemplar(){
            exemplares++;
        }

        bool checarDisponibilidade(){
            if(exemplares > 0){
                return true;
            }else{
                return false;
            }
        }

        
    
    private:
        string publicacao;
        string isbn;
        int exemplares;

};

class usuario{
    public:
        string nome;
        
        usuario(string _nome, string _senha, int _dtaNascimento, string _email, string _telefone){
            nome = _nome;
            senha = _senha;
            dtaNascimento = _dtaNascimento;
            email = _email;
            telefone = _telefone;
            multa = 0;
            status = true;
        }
    
    private:
        string senha;
        int dtaNascimento;
        string email;
        string telefone;
        float multa;
        bool status;

};


class admin{
    public:
        string nome;

        admin(string _nome, string _senha){
            nome = _nome;
            senha = _senha;
        }

        string getSenha(){
            return senha;
        }   

        usuario cadastrarUsuario(){
            string nome;
            string senha;
            int dtaNascimento;
            string email;
            string telefone;
            cout << "Digite o nome do usuario: ";
            cin >> nome;
            cout << "Digite a senha do usuario: ";
            cin >> senha;
            cout << "Digite a data de nascimento do usuario: ";
            cin >> dtaNascimento;
            cout << "Digite o email do usuario: ";
            cin >> email;
            cout << "Digite o telefone do usuario: ";
            cin >> telefone;
            usuario user(nome, senha, dtaNascimento, email, telefone);
            return user;
        }

        void deletarUsuario(vector<usuario> &usuarios){
            string nome;
            cout << "Digite o nome do usuario que deseja deletar: ";
            cin >> nome;
            for(int i = 0; i < usuarios.size(); i++){
                if(usuarios.at(i).nome == nome){
                    usuarios.erase(usuarios.begin() + i);
                    cout << "Usuario deletado com sucesso!" << endl;
                    return;
                }
            }
            cout << "Usuario nao encontrado!" << endl;
        }

        livro novoLivro(){
            string titulo;
            string autor;
            string editora;
            string publicacao;
            string isbn;
            cout << "Digite o titulo do livro: ";
            cin >> titulo;
            cout << "Digite o autor do livro: ";
            cin >> autor;
            cout << "Digite a editora do livro: ";
            cin >> editora;
            cout << "Digite a data de publicacao do livro: ";
            cin >> publicacao;
            cout << "Digite o ISBN do livro: ";
            cin >> isbn;
            livro book(titulo, autor, editora, publicacao, isbn);
            return book;
        }

        void deletarLivro(vector<livro> &livros){
            string titulo;
            cout << "Digite o titulo do livro que deseja deletar: ";
            cin >> titulo;
            for(int i = 0; i < livros.size(); i++){
                if(livros.at(i).titulo == titulo){
                    livros.erase(livros.begin() + i);
                    cout << "Livro deletado com sucesso!" << endl;
                    return;
                }
            }
            cout << "Livro nao encontrado!" << endl;
        }



    private:
        string senha;
};
class chamada{
    public:
        int dataVenc[3];
        //fazer sistema no constructor para definir vencimento

};


/* 
usuarios.push_back(adm.cadastrarUsuario());
usuarios.at(0); // Nome = Jorge
usuarios.push_back(adm.cadastrarUsuario());
usuarios.at(1); // Nome = Joao */