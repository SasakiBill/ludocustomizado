#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#define facesDado 6
using namespace std;

/*@version 1.0.0
*  @author: João Pedro Kelniar
*  Função void sem parâmetros e sem retorno (1° requisito do trabalho), para fazer uma introducao ao jogo.*/
void introducao() {
	cout << "--------------------------------------------------------\n" << endl;
	Sleep(2000);
	cout << "Ola! Sejam bem vindos ao Ludo Customizado!" << endl;
	Sleep(2000);
	cout << "--------------------------------------------------------\n" << endl;
	Sleep(2000);
}

/*@version 1.0.0
* @author: João Pedro Kelniar
* Função do tipo void recebendo dois vetores por valor e sem retorno (2° requisito do trabalho).
* Função responsável para verficiar a condição de vitória de um jogador; bem como o encerramento desse software.*/
void verificaVencedores(int pont[], int pontTot[], int winner = 0) {
	if (pont[1] == 1) {
		cout << "We have a winner!\n";
		cout << "Jogador 1 ganhou com pontuacao: " << pont[1] << " - " << pontTot[1];
		winner = 1;
		exit(0);
	}
	if (pont[2] == 1) {
		cout << "We have a winner!\n";
		cout << "Jogador 2 ganhou com pontuacao: " << pont[2] << " - " << pontTot[2];
		winner = 1;
		exit(0);
	}
}
 
/*@version 1.0.0
* @author: João Pedro Kelniar
* Função do tipo void recebendo duas strings por referência sem retorno (4° requisito do trabalho).
* Responsável para determinar o nome dos jogadores.*/
void nomeJogadores(string* jogador1, string* jogador2) {
	cout << "Bem vindo Jogador 1! Digite seu nick:\n" << endl;
	cin >> *jogador1;
	cout << "Seu Nick ficou como\n" << *jogador1;
	Sleep(2000);
	system("CLS");
	Sleep(2000);
	cout << "Bem vindo Jogador 2! Digite seu nick:\n" << endl;
	cin >> *jogador2;
	cout << "Seu Nick ficou como\n" << *jogador2;
	Sleep(2000);
	system("CLS");
}

/*@version 1.0.0
* @author: João Pedro Kelniar
* Função do tipo void recebendo três variáveis por referência, inclusive uma delas sendo 
* um vetor por referência sem retorno (5° requisito do trabalho), para escolher a trilha*/
void escolheTr(int* escolha, int* player, int* tr) {
	cout << "Escolha uma trilha" << endl;
	cin >> *escolha;
	if ((*player % 2) != 0 && (*escolha % 2) == 0 || *escolha > 8 || tr[*escolha] >= 20) {
		while ((*player % 2) != 0 && (*escolha % 2) == 0 || *escolha > 8 || tr[*escolha] >= 20) {
			cout << "Trilha invalida!" << endl;
			cin >> *escolha;
		}
	}
	if ((*player % 2) == 0 && (*escolha % 2) != 0 || *escolha > 8 || tr[*escolha] >= 20) {
		while ((*player % 2) == 0 && (*escolha % 2) != 0 || *escolha > 8 || tr[*escolha] >= 20) {
			cout << "Trilha invalida!" << endl;
			cin >> *escolha;
		}
	}
}

/*@version 1.0.0
* @author: João Pedro Kelniar
* Função do tipo void sem retorno, recebendo um vetor do tipo inteiro como parâmetro por referência, responsável por demonstrar o tabuleiro a cada rodada*/
void tabuleiro(int* tr2) {
	for (int i = 1; i < 9; i++) {
		if ((i % 2) != 0) {
			cout << "\nTrilha numero" << i << " - " << tr2[i] << endl;
		}
		if ((i % 2) == 0) {

			cout << "\nTrilha numero" << i << " - " << tr2[i] << endl;
		}
	}
}

/*@version 1.0.0
* @author: João Pedro Kelniar
* Função do tipo void sem retorno, recebendo três ponteiros do tipo inteiro, e um vetor passado por referência.
* Função responsável por realizar o esvaziamento de uma trilha adversária, após um 6 retirado no dado.*/
void zeraDado(int* dad, int* choice, int* player, int* tr) {
	if (*dad == 6) {
		cout << "Escolha uma trilha do oponente para zerar" << endl;
		cin >> *choice;
		if ((*player % 2) != 0 && (*choice % 2) != 0) {
			while ((*player % 2) != 0 && (*choice % 2) != 0) {
				cout << "Trilha invalida!" << endl;
				cin >> *choice;
			}
		}
		if ((*player % 2) == 0 && (*choice % 2) == 0) {
			while ((*player % 2) == 0 && (*choice % 2) == 0) {
				cout << "Trilha invalida!" << endl;
				cin >> *choice;
			}
		}
		tr[*choice] = 0;
	}
}

/*@version: 1.0.0
* @author: João Pedro Kelniar
* Função do tipo void sem retorno, recebendo um ponteiro do tipo inteiro por referência.
* Função responsável por realizar a operação de soma de um novo dado, com o 1 retirado.
*/
void dadoMisericordia(int* dadoo) {
	if (*dadoo == 1) {
		*dadoo += (rand() % facesDado) + 1;
		cout << "Novo valor do dado: " << *dadoo << endl;
	}
}

/*@version: 1.0.0
* @author: João Pedro Kelniar
* Função do tipo void sem retorno, recebendo dois ponteiros do tipo inteiro por referência e
* um vetor por passagem de referência. Função responsável por verificar se um peão está no mesmo lugar que outro.
*/
void verificaPeao(int* player, int*choice, int* tr) {
	if (*player % 2 == 0 && tr[*choice] < 20 && tr[*choice] == tr[*choice - 1]) {
		tr[*choice - 1] = 0;
	}
	if (*player % 2 == 0 && tr[*choice] < 20 && tr[*choice] == tr[*choice - 1]) {
		tr[*choice + 1] = 0;
	}
}

/*@version: 1.0.0
* @author: João Pedro Kelniar
* Função do tipo void sem retorno, com dois vetores passados por valor, e dois vetores passados por referência.
* Função responsável por atualizar o placar da partida.
*/
void placar(int ponTotal[], int pont[], int* tr, int* trClosed) {
	ponTotal[1] = tr[1] + tr[3] + tr[5] + tr[7];
	ponTotal[2] = tr[2] + tr[4] + tr[6] + tr[8];
	pont[1] = 0;
	pont[2] = 0;
	for (int i = 1; i < 9; i++) {
		if (tr[i] >= 20) {
			trClosed[i] = true;
		}
	}
	for (int i = 1; i < 9; i++) {
		if (trClosed[i] && i % 2 != 0) {
			pont[1]++;
		}
		if (trClosed[i] && i % 2 == 0) {
			pont[2]++;
		}
	}
}

/*@version 1.0.0
  @author: João Pedro Kelniar
Função main responsável por operações com números randômicos, prints e demais chamadas de funções para execução do jogo*/
int main() {
	int valorDado = 0, escolhaTrilha, rodadas = 1, trilhas[9] = { 0 }, pontuacao[3] = { 0 }, pontuacaoTotal[3] = { 0 }, trilhas_fechadas[9] = { 0 };
	int vencedor = 0;

	string pl1, pl2;

	srand(time(NULL));

	introducao();

	nomeJogadores(&pl1, &pl2);

	while (vencedor == 0) {
		for (int jogadorDaVez = 1; jogadorDaVez < 3; jogadorDaVez++) {
			valorDado += (rand() % facesDado) + 1;

			cout << "Rodada " << rodadas << endl;

			Sleep(1000);
			if (jogadorDaVez == 1) {
				cout << "\nSua vez --->" << pl1 << endl;
			}else {
				cout << "\nSua vez ---> " << pl2 << endl;
			}
			cout << "Valor do dado: " << valorDado << endl;
			Sleep(1000);
			cout << endl;
			cout << "Jogador 1 - Trilhas fechadas / Pont. Total :  " << pontuacao[1] << " - " << pontuacaoTotal[1] << endl;
			cout << "Jogador 2 - Trilhas fechadas / Pont. Total :  " << pontuacao[2] << " - " << pontuacaoTotal[2] << endl;
			cout << endl;
			cout << "1 - 3 - 5 - 7 ->" << pl1 << endl;
			cout << "2 - 4 - 6 - 8 ->" << pl2 << endl;

			tabuleiro(trilhas);

			cout << endl;

			zeraDado(&valorDado, &escolhaTrilha, &jogadorDaVez, trilhas);

			dadoMisericordia(&valorDado);
			
			escolheTr(&escolhaTrilha, &jogadorDaVez, trilhas);

			trilhas[escolhaTrilha] += valorDado;

			valorDado = 0;
			system("cls");

			verificaPeao(&jogadorDaVez, &escolhaTrilha, trilhas);

			placar(pontuacaoTotal, pontuacao, trilhas, trilhas_fechadas);
			
			verificaVencedores(pontuacao, pontuacaoTotal, vencedor);

			rodadas++;
		}
	}
}

