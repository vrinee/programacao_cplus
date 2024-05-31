#include <iostream>
#include <vector>
#include <myClasses.cpp>

using namespace std;

int loginAdmin(vector<admin> &admins){
    string name;
    string password;
    cout << "Digite o nome do administrador: ";
    cin >> name;
    cout << "Digite a senha do administrador: ";
    cin >> password;
    for (int i = 0; i < admins.size(); i++){
        if (admins[i].nome == name && admins[i].getSenha() == password){
            return i;
        }
    }
    int op;
    cout << "Nome ou senha invalidos." << endl;
    cout << "Tentar novamente.(1 - sim 0 - não)" << endl;
    cin >> op;
    if (op == 1){
        return loginAdmin(admins);
    }
    return -1;

}

admin createAdmin(){
    string name;
    string password;
    cout << "Digite o nome do administrador: ";
    cin >> name;
    cout << "Digite a senha do administrador: ";
    cin >> password;
    admin newAdmin(name, password);
    return newAdmin;
}

// funções de criação
    void createUser(vector<usuario> &usuarios, admin &admin){
        usuarios.push_back(admin.cadastrarUsuario());
        usuarios[usuarios.size() - 1].setId(usuarios);   
    }

    int loginUser(vector<usuario> &usuarios){
        string email;
        string password;
        cout << "Digite o email do usuario: ";
        cin >> email;
        cout << "Digite a senha do usuario: ";
        cin >> password;
        for (int i = 0; i < usuarios.size(); i++){
            if (usuarios[i].getEmail() == email && usuarios[i].getSenha() == password){
                return i;
            }
        }
        int op;
        cout << "Email ou senha invalidos." << endl;
        cout << "Tentar novamente.(1 - sim 0 - não)" << endl;
        cin >> op;
        if (op == 1){
            return loginUser(usuarios);
        }
        return -1;
    }

    void createBook(vector<livro> &livros, admin &admin){
        livros.push_back(admin.novoLivro());
        livros[livros.size() - 1].setId(livros);
    }

    void createChamada(vector<chamada> &chamadas,vector<usuario> &usuarios, vector<livro> &livros, admin &admin){
        chamadas.push_back(admin.novoEmprestimo(livros, usuarios));
    }
// Fim das funções de criação

// Funções de listagem
    void listarUsuarios(vector<usuario> &usuarios){
        for (int i = 0; i < usuarios.size(); i++){
            cout << "ID: " << usuarios[i].getId() << " Nome: " << usuarios[i].nome << " Email: " << usuarios[i].getEmail() << endl;
        }
    }

    void listarAtributosUser(usuario user, vector<chamada> &chamadas){
        cout << "ID: " << user.getId() << endl;
        cout << "Nome: " << user.nome << endl;
        cout << "Email: " << user.getEmail() << endl;
        cout << "Data de nascimento: " << user.getDtaNascimento() << endl;
        cout << "Telefone: " << user.getTelefone() << endl;
        cout << "Multas: " << user.getMulta(chamadas) << endl;
        if(user.getStatus() == 1){
            cout << "Status: Ativo" << endl;
        }else{
            cout << "Status: Bloqueado" << endl;
        }
        cout << "Livros alugados: " << user.getEmprestimos() << endl;
    }

    void listarAdmins(vector<admin> &admins){
        for (int i = 0; i < admins.size(); i++){
            cout << "Nome: " << admins[i].nome << endl;
        }
    }

    void listarLivros(vector<livro> &livros){
        for (int i = 0; i < livros.size(); i++){
            cout << "ID: " << livros[i].getId() << " Nome: " << livros[i].titulo << " Autor: " << livros[i].autor << " Isbn: " << livros[i].getIsbn() << endl;
        }
    }

    void listarAtributosLivro(livro book){
        cout << "ID: " << book.getId() << endl;
        cout << "Titulo: " << book.titulo << endl;
        cout << "Autor: " << book.autor << endl;
        cout << "Editora: " << book.editora << endl;
        cout << "Isbn: " << book.getIsbn() << endl;
        cout << "Publicação: " << book.getPublicacao() << endl;
        cout << "Exemplares disponiveis: " << book.getExemplares() << endl;
    }

    void listarChamadas(vector<chamada> &chamadas, vector<usuario> &usuarios, vector<livro> &livros){
        for (int i = 0; i < chamadas.size(); i++){
            cout << "ID:" << i << " Usuario: " << usuarios[chamadas[i].getIdUsuario()].nome << " Livro: " << livros[chamadas[i].getIdLivro()].titulo << " Data de emprestimo: " << chamadas[i].getDtaEmprestimo() << endl;
        }
    }

    void listarAtributosChamada(chamada call, vector<usuario> &usuarios, vector<livro> &livros){
        cout << "ID: " << call.getId() << endl;
        cout << "Usuario: " << usuarios[call.getIdUsuario()].nome << endl;
        cout << "Livro: " << livros[call.getIdLivro()].titulo << endl;
        cout << "Data de emprestimo: " << call.getDtaEmprestimo() << endl;
        cout << "Data de vencimento: " << call.getDtaVenc() << endl;
        if (call.getStatus() == 1){
            cout << "Status: Ativo" << endl;
        }else{
            cout << "Status: Encerrado" << endl;
        }
        if (call.getAtrasado() == 1){
            cout << "Atrasado: Sim" << endl;
        }else{
            cout << "Atrasado: Não" << endl;
        }
    }
// Fim das funções de listagem

// Funções de ação
    void pagamento(usuario &user, vector<chamada> &chamadas){
        float multa = user.getMulta(chamadas);
        if (multa == 0){
            cout << "Não há multas a serem pagas." << endl;
            return;
        }
        float valor;
        cout << "O valor da multa é de: " << multa << endl;
        cout << "Digite o valor a ser pago: ";
        cin >> valor;
        user.pagarMulta(valor,chamadas);
    }

    void devolucao(usuario &user, vector<livro> &livros, vector<chamada> &chamadas){
        int op;
        int qnt;
        cout << "Quantas devoluções deseja fazer?" << endl;
        cin >> qnt;
        for (int i = 0; i < qnt; i++){
            user.devolverLivro(chamadas, livros);
        }
        cout << "Deseja pagar a multa?(1 - sim 0 - não)" << endl;
        cin >> op;
        if (op == 1){
            pagamento(user, chamadas);
        }

    }

    void mudarAtributosUser(usuario &user){
        int op;
        int dta[3];
        string placeholder;
        cout << "O que deseja alterar?" << endl;
        cout << "1 - Nome" << endl;
        cout << "2 - Email" << endl;
        cout << "3 - Data de nascimento" << endl;
        cout << "4 - Telefone" << endl;
        cout << "5 - Senha" << endl;
        cin >> op;
        switch (op){
            case 1:
                cout << "Digite o novo nome: ";
                cin >> placeholder;
                user.nome = placeholder;
                break;
            case 2:
                cout << "Digite o novo email: ";
                cin >> placeholder;
                user.setEmail(placeholder);
                break;
            case 3:
                cout << "Digite o dia de nascimento: ";
                cin >> dta[0];
                cout << "Digite o mes de nascimento: ";
                cin >> dta[1];
                cout << "Digite o ano de nascimento: ";
                cin >> dta[2];
                user.setDtaNascimento(dta);
                break;
            case 4:
                cout << "Digite o novo telefone: ";
                cin >> placeholder;
                user.setTelefone(placeholder);
                break;
            case 5:
                cout << "Digite a nova senha: ";
                cin >> placeholder;
                user.setSenha(placeholder);
                break;
            default:
                cout << "Opção invalida." << endl;
                cout << "Tentar novamente?(1 - sim 0 - não)" << endl;
                cin >> op;
                if (op == 1){
                    mudarAtributosUser(user);
                }
                break;
        }
    }