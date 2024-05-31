#include <iostream>
#include <vector>

using namespace std;

void adicionarDias(int dtaInicial[3], int dias, int (*dtaFinal)[3]){
    int dia = dtaInicial[0] ;
    int mes = dtaInicial[1];
    int ano = dtaInicial[2];

    for(int i = 0; i < dias; i++){
        dia++;
        if(dia > 31 and (mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10)){
            dia = 1;
            mes++;
        }else if(dia > 30 and (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
            dia = 1;
            mes++;
        }else if(mes == 2){
            if(ano % 4 == 0){
                if(dia > 29){
                    dia = 1;
                    mes++;
                }
            }else{
                if(dia > 28){
                    dia = 1;
                    mes++;
                }
            }
        }else if(dia > 31 and mes == 12){
            dia = 1;
            mes = 1;
            ano++;
        }
    }

    *dtaFinal[0] = dia;
    *dtaFinal[1] = mes;
    *dtaFinal[2] = ano;
}

int diasAte(int dtaInicial[3], int dtaFinal[3]){
    int diaInicial = dtaInicial[0];
    int mesInicial = dtaInicial[1];
    int anoInicial = dtaInicial[2];
    int diaFinal = dtaFinal[0];
    int mesFinal = dtaFinal[1];
    int anoFinal = dtaFinal[2];
    int dias = 0;

    while(diaInicial or diaFinal or mesInicial != mesFinal or anoInicial != anoFinal){
        diaInicial++;
        dias++;
        if(diaInicial > 31 and (mesInicial == 1 or mesInicial == 3 or mesInicial == 5 or mesInicial == 7 or mesInicial == 8 or mesInicial == 10)){
            diaInicial = 1;
            mesInicial++;
        }else if(diaInicial > 30 and (mesInicial == 4 || mesInicial == 6 || mesInicial == 9 || mesInicial == 11)){
            diaInicial = 1;
            mesInicial++;
        }else if(mesInicial == 2){
            if(anoInicial % 4 == 0){
                if(diaInicial > 29){
                    diaInicial = 1;
                    mesInicial++;
                }
            }else{
                if(diaInicial > 28){
                    diaInicial = 1;
                    mesInicial++;
                }
            }
        }else if(diaInicial > 31 and mesInicial == 12){
            diaInicial = 1;
            mesInicial = 1;
            anoInicial++;
        }
    }

    return dias;

}

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

        int getExemplares(){
            return exemplares;
        }

        void deletarExemplar(){
            exemplares--;
        }

        bool checarDisponibilidade(){
            if(exemplares > 0){
                return true;
            }else{
                return false;
            }
        }

        void setId(vector<livro> &livros){
            for (int i = 0; i < livros.size(); i++){
                if(livros.at(i).getIsbn() == isbn){
                    id = i;
                }
            }
        }
        
        int getId(){
            return id;
        }
    
    private:
        string publicacao;
        string isbn;
        int exemplares;
        int id;

};
class usuario{
    public:
        string nome;
        
        usuario(string _nome, string _senha, int _dtaNascimento[3], string _email, string _telefone){
            nome = _nome;
            senha = _senha;
            dtaNascimento[0] = _dtaNascimento[0];
            dtaNascimento[1] = _dtaNascimento[1];
            dtaNascimento[2] = _dtaNascimento[2];
            email = _email;
            telefone = _telefone;
            multa = 0;
            status = true;
        }

        void setNome(string _nome){
            nome = _nome;
        }

        string getSenha(){
            return senha;
        }

        void setSenha(string _senha){
            senha = _senha;
        }

        int *getDtaNascimento(){
            return dtaNascimento;
        }

        void setDtaNascimento(int _dtaNascimento[3]){
            dtaNascimento[0] = _dtaNascimento[0];
            dtaNascimento[1] = _dtaNascimento[1];
            dtaNascimento[2] = _dtaNascimento[2];
        }

        string getEmail(){
            return email;
        }

        void setEmail(string _email){
            email = _email;
        }

        string getTelefone(){
            return telefone;
        }

        void setTelefone(string _telefone){
            telefone = _telefone;
        }

        float getMulta(vector<chamada> &chamadas){
            checarMulta(chamadas);
            return multa;
        }

        bool getStatus(){
            checarStatus();
            return status;
        }

        void checarStatus(){
            if(multa > 50){
                status = false;
            }else{
                status = true;
            }
        }

        void setId(vector<usuario> &usuarios){
            for (int i = 0; i < usuarios.size(); i++){
                if(usuarios.at(i).getEmail() == email){
                    id = i;
                }
            }
        }

        int getId(){
            return id;
        }

        int getEmprestimos(){
            return emprestimos;
        }

        void addEmprestimo(){
            emprestimos++;
        }

        void checarMulta(vector<chamada> &chamadas){
            int dtaAtual[3];
            int timesRan = 0;
            cout << "Digite o dia atual: ";
            cin >> dtaAtual[0];
            cout << "Digite o mes atual: ";
            cin >> dtaAtual[1];
            cout << "Digite o ano atual: ";
            cin >> dtaAtual[2];
            while(timesRan < emprestimos){
                for (int i = 0; i < chamadas.size(); i++){
                    if(chamadas.at(i).getIdUsuario() == id) {
                        if(chamadas.at(i).getAtrasado()){
                            int dias = diasAte(chamadas.at(i).getDtaVenc(), dtaAtual);

                            if(dias > 0){
                                multa += dias * 2;
                                chamadas.at(i).setAtrasado();
                            }
                        }
                        timesRan++; 
                    }
                }

            }
        }

        void pagarMulta(float valor, vector<chamada> &chamadas){
            checarMulta(chamadas);
            multa -= valor;
        }

        void devolverLivro(vector<chamada> &chamadas, vector<livro> &livros){
            string titulo;
            int diaAtual[3];
            int idLivro;
            int op;
            cout << "Digite o dia atual: ";
            cin >> diaAtual[0];
            cout << "Digite o mes atual: ";
            cin >> diaAtual[1];
            cout << "Digite o ano atual: ";
            cin >> diaAtual[2];
            cout << "Digite o titulo do livro que deseja devolver: ";
            cin >> titulo;
            for(int i = 0; i < livros.size(); i++){
                if(livros.at(i).titulo == titulo){
                    idLivro = i;
                    break;
                }
            }
            cout << "Livro nao encontrado!" << endl;
            cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
            cin >> op;
            if(op == 1){
                devolverLivro(chamadas, livros);
                return;
            }

            for(int i = 0; i < chamadas.size(); i++){
                if(chamadas.at(i).getIdUsuario() == id and chamadas.at(i).getIdLivro() == idLivro){
                    chamadas.at(i).setStatus();
                    int dias = diasAte(chamadas.at(i).getDtaVenc(), diaAtual);
                    if(dias > 0 and  chamadas.at(i).getAtrasado() == false){
                        multa += dias * 2;
                        chamadas.at(i).setAtrasado();
                    }
                    livros.at(idLivro).novoExemplar();
                    cout << "Livro devolvido com sucesso!" << endl;
                    return;
                }
            }

        }

    private:
        string senha;
        int dtaNascimento[3];
        string email;
        string telefone;
        float multa;
        bool status;
        int id;
        int emprestimos = 0;

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
            int dtaNascimento[3];
            string email;
            string telefone;
            cout << "Digite o nome do usuario: ";
            cin >> nome;
            cout << "Digite a senha do usuario: ";
            cin >> senha;
            cout << "Digite o dia de nascimento do usuario: ";
            cin >> dtaNascimento[0];
            cout << "Digite o mes de nascimento do usuario: ";
            cin >> dtaNascimento[1];
            cout << "Digite o ano de nascimento do usuario: ";
            cin >> dtaNascimento[2];
            cout << "Digite o email do usuario: ";
            cin >> email;
            cout << "Digite o telefone do usuario: ";
            cin >> telefone;
            usuario user(nome, senha, dtaNascimento, email, telefone);
            return user;
        }

        void deletarUsuario(vector<usuario> &usuarios){
            string nome;
            int op;
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
            cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
            cin >> op;
            if(op == 1){
                deletarUsuario(usuarios);
            }

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
            int op;
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
            cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
            cin >> op;
            if(op == 1){
                deletarLivro(livros);
            }
        }

        chamada novoEmprestimo(vector<livro> &livros, vector<usuario> &usuarios){
            string titulo;
            string nome;
            int op;
            int dtaEmprestimo[3];
            cout << "Digite o titulo do livro que deseja emprestar: ";
            cin >> titulo;
            cout << "Digite o nome do usuario que deseja emprestar o livro: ";
            cin >> nome;
            for(int i = 0; i < livros.size(); i++){
                if(livros.at(i).titulo == titulo){
                    for(int j = 0; j < usuarios.size(); j++){
                        if(usuarios.at(j).nome == nome){
                            if(livros.at(i).checarDisponibilidade()){
                                cout << "Livro disponivel!" << endl;
                                cout << "Digite o dia de emprestimo: " << endl;
                                cin >> dtaEmprestimo[0];
                                cout << "Digite o mes de emprestimo: " << endl;
                                cin >> dtaEmprestimo[1];
                                cout << "Digite o ano de emprestimo: " << endl;
                                cin >> dtaEmprestimo[2];
                                livros.at(i).deletarExemplar();
                                chamada call(dtaEmprestimo,i,j);
                                usuarios.at(j).addEmprestimo();
                                return call;
                            }else{
                                cout << "Livro nao disponivel!" << endl;
                                return;
                            }
                        }
                    }
                    cout << "Usuario nao encontrado!" << endl;
                    cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
                    cin >> op;
                    if(op == 1){
                        novoEmprestimo(livros, usuarios);
                    }
                    return;
                }
            }
            cout << "Livro nao encontrado!" << endl;
            cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
            cin >> op;
            if(op == 1){
                novoEmprestimo(livros, usuarios);
            }
        }

    private:
        string senha;
};
class chamada{
    public:
        
        chamada(int _dtaEmprestimo[3], int _idLivro, int _idUsuario){
            dtaEmprestimo[0] = _dtaEmprestimo[0];
            dtaEmprestimo[1] = _dtaEmprestimo[1];
            dtaEmprestimo[2] = _dtaEmprestimo[2];
            adicionarDias(dtaEmprestimo, 15, &dtaVenc);
            idLivro = _idLivro;
            idUsuario = _idUsuario;
            status = true;
            atrasado = false;
        }

        int *getDtaVenc(){
            return dtaVenc;
        }

        void setDtaVenc(int &_dtaVenc){
            *dtaVenc = _dtaVenc;
        }

        int *getDtaEmprestimo(){
            return dtaEmprestimo;
        }

        int getIdLivro(){
            return idLivro;
        }

        int getIdUsuario(){
            return idUsuario;
        }

        bool getStatus(){
            return status;
        }

        void setStatus(){
            if(status){
                status = false;
            }else{
                status = true;
            }
        }

        bool getAtrasado(){
            return atrasado;
        }

        void setAtrasado(){
            if (atrasado){
                atrasado = false;
            }else{
                atrasado = true;
            }
        }

        int getId(){
            return id;
        }

        void setId(vector<chamada> &chamadas){
            for (int i = 0; i < chamadas.size(); i++){
                if(chamadas.at(i).getIdLivro() == idLivro and chamadas.at(i).getIdUsuario() == idUsuario and dtaEmprestimo == chamadas.at(i).getDtaEmprestimo()){
                    id = i;
                }
            }
        }

        //terminar gets e sets, fazer checagem de multa, devolver livro
    private:
        int dtaVenc[3];
        int dtaEmprestimo[3];
        int idLivro;
        int idUsuario;
        bool status;
        bool atrasado;
        int id;


};
