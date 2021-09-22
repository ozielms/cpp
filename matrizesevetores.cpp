#include <iostream>
using namespace std;

/*
Desenvolver um programa para realizar a correção de uma prova de múltipla escolha.
Os dados iniciais a serem lidos são:

- A quantidade de candidatos (N) e
- A quantidade de questões aplicadas (M).
As respostas possíveis que poderão se aceitas são: A, B, C, D e E.
1ª etapa: O primeiro conjunto de dados a ser lido será o gabarito com as respostas corretas das M questôes.
2ª etapa: Após o gabarito, serão lidos os nomes e as respostas de cada candidato.
Os valores das questões são iguais.
A nota máxima é 10 e a de classificação é 5.
As estruturas de armazenamento que deverão ser utilizadas estão dispostas abaixo para um melhor entendimento.

O programa deverá:
a) Gerar o vetor NOTA;
b) Apresentar o relatório geral contendo o nome do candidato e sua nota;
c) Calcular e apresentar a média geral dos candidatos;
d) Apresentar a quantidade e o percentual de classificados e desclassificados;
e) Apresentar o relatório de candidatos classificados;
f) Apresentar a melhor nota obtida e seu(s) respectivo(s) candidato(s);
g) Ter, pelo menos, 3 subprogramas;
DESAFIO (ponto extra)
h) Gerar o vetor ACERTOS com o percentual correspondente e apresentá-lo.
*/
// https://ozzybr.com.br



float CalculaNota(float m);
float MediaGeral(float a, float b);
string Separador();
float CalculaPorcentagem(float a, float b);


main()
{
	setlocale(LC_ALL, "portuguese");
	
	// DECLARAÇÃO DE VARIÁVEIS
	int N, M, i, j, acerto, classificados, desclassificados;
	float porcClass = 0;
	float porcDesc = 0;
	float notaAluno[10];
	float percAcerto[10];
	float melhorNota = 0;
	string alunoMelhorNota = "";
	char gabarito[10];
	string nome[10];
	char resp;
	float media = 0;
	char gabaritoTemp; // Gabarito temporário
	char respTemp; // Resposta temporária
	

//	PRENCHER GABARITO-----------------------------------
	cout<<"Qual a quantidade de questões aplicadas? "; cin>>M;

	cout<<"\nGabarito\n__________________________\n";
	for (i = 0; i < M; i++) {
		while (gabarito[i] != 'A' && gabarito[i] != 'B' && gabarito[i] != 'C' && gabarito[i] != 'D' && gabarito[i] != 'E' ) {
			cout<<"Questão "<<i+1<<": ";
			cin>>gabaritoTemp;
			gabarito[i]=toupper(gabaritoTemp);
			if (gabarito[i] != 'A' && gabarito[i] != 'B' && gabarito[i] != 'C' && gabarito[i] != 'D' && gabarito[i] != 'E' ) {
				cout<<"Entre apenas com as alternativas A, B, C, D ou E "<<i+1<<": ";
			}
		}
	}
	
	
//	-----------------------------------------------------

	system("cls");
	
//	PREENCHER QUANTIDADE DE CANDIDATOS-------------------

	cout<<"\nQuantidade de candidatos: "; cin>>N;

//	-----------------------------------------------------	

	system("cls");

//	PREENCHER NOME DO CANDIDATO E RESPOSTAS--------------
	for (i = 0; i < N; i++) {
		cout<<"\n__________________________\n";
		cout<<"Nome do candidato "<<i+1<<": "; cin>>nome[i];
		acerto = 0;
		cout<<"\n__________________________\n";
		
		for(j = 0; j < M; j++ ) {
			respTemp= 'x';
			resp = 'x';
			while (resp != 'A' && resp != 'B' && resp != 'C' && resp != 'D' && resp != 'E' ) {
				cout<<"Questão "<<j+1<<": "; cin>>respTemp;
				resp=toupper(respTemp);
				if(resp != 'A' && resp != 'B' && resp != 'C' && resp != 'D' && resp != 'E' ) {
					cout<<"Entre apenas com as alternativas A, B, C, D ou E: "<<j+1<<": ";
				}
		}
			
			if (resp == gabarito[j]) {
				acerto++;
			}

			notaAluno[i] = acerto * CalculaNota(M);
		}
//	VERIFICAR ALUNO(S) COM MELHOR NOTA------------------
		if (notaAluno[i] == melhorNota) { 
			alunoMelhorNota.append("\n").append(nome[i]);
		} else if (notaAluno[i] > melhorNota) { 
			melhorNota = notaAluno[i]; 
			alunoMelhorNota = nome[i];
		} 
//	-----------------------------------------------------
		percAcerto[i] = CalculaPorcentagem(acerto, M);
		media = media + notaAluno[i];
		system("cls");

	}

//	-----------------------------------------------------

	classificados = 0;
	desclassificados = 0;


// Exibe nome, nota, classificacao e porc de acerto-----
	for (i = 0; i < N; i++) {
		cout<<"Nota de "<<nome[i]<<": "<<notaAluno[i]<<endl;
		if (notaAluno[i] >= 5) {
			cout<<"Aprovado.\n";
			classificados++;
		} else {
			cout<<"Reprovado.\n";
			desclassificados++;
		}
		cout<<percAcerto[i]<<"% de acerto.\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
	}
	
//	-----------------------------------------------------

//	RELATÓRIOS-------------------------------------------
	porcClass = (classificados * 100)/N;
	porcDesc = (desclassificados * 100)/N;
	
	cout<<Separador();
	cout<<"------------ MEDIA GERAL ------------"<<endl;
	cout<<MediaGeral(media, N)<<endl;
	cout<<Separador();
	
	cout<<"\n----------- PERCENTUAL E QTD DE CLASSIFICADOS -----------"<<endl;
	cout<<classificados<<endl;
	cout<<porcClass<<"%"<<endl;
	cout<<Separador();
	
	cout<<"\n---------- PERCENTURAL E QTD DE DESCLASSIFICADOS ----------"<<endl;
	cout<<desclassificados<<endl;
	cout<<porcDesc<<"%"<<endl;
	cout<<Separador();
	
	cout<<"\n---------- CANDIDATOS CLASSIFICADOS ----------"<<endl;
	for (i = 0; i < N; i++) {
		if(notaAluno[i] >= 5) {
			cout<<nome[i]<<endl;
		}
	}
	cout<<Separador();
	
	cout<<"\n---------- MELHOR NOTA ----------"<<endl;
	cout<<"Nota: "<<melhorNota<<"\n----"<<endl;
	cout<<"Nome(s): \n"<<alunoMelhorNota<<endl;
//	-----------------------------------------------------

}
	
//	FIM DO PROGRAMA-------------------------------------

//	-----------------------------------------------------

//	SUBPROGRAMAS----------------------------------------
	
	float CalculaNota(float m) {
		return 10 / m;
	}
	
	float MediaGeral(float a, float b) {
		return a/b;
	}
	
	string Separador() {
		return "---------------------------------------------------------------\n\n";
	}
	
	float CalculaPorcentagem(float a, float b) {
		return (a * 100) / b;
	}
	
//	-----------------------------------------------------
