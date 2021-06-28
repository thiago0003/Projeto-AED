#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include <chrono>
#include "pilha.h"
#include "fila.h"

using namespace std;
using namespace sf;
using namespace std::chrono;

const int M = 20;
const int N = 10;

int field[M][N] = { 0 };

sf::Font font;

int figures[7][4] =
{
    1,3,5,7, // I
    2,4,5,7, // Z
    3,5,4,6, // S
    3,5,4,7, // T
    2,3,5,7, // L
    3,5,7,6, // J
    2,3,4,5, // O
};

pecas pecasA;
pecas pecasB;
pecas pecasC;
pecas pecasD;
pecas pecasAuxiliar;

bool check()
{
    //Verifica se a peça chegou ao final
    for (int i = 0; i < 4; i++)
        if (pecasA.x[i] < 0 || pecasA.x[i] >= N || pecasA.y[i] >= M)
            return 0;
        else 
            if(field[pecasA.y[i]][pecasA.x[i]])
                return 0;

    return 1;
};

void rotacao(bool rotate)
{
    //Verifica se é para rotacionar a peça
    if (rotate)
    {
        pecas p = pecasA;

        //Rotaciona todos os quadrados das peças
        for (int i = 0; i < 4; i++)
        {
            int x = pecasA.y[i] - p.y[1];
            int y = pecasA.x[i] - p.x[1];
            pecasA.x[i] = p.x[1] - x;
            pecasA.y[i] = p.y[1] + y;
        }

        //Verifica se a peça chegou no final
        if (!check()) 
            //Coloca a peça na tela 
            pecasA = pecasAuxiliar;
    }
}

void mover(int dx)
{
    //Copia os dados para a variável auxiliar
    pecasAuxiliar = pecasA;

    //Verifica se é para mover a peça em X
    for (int i = 0; i < 4; i++) 
        pecasA.x[i] += dx;
    
    //Verifica se a peça chegou no final
    if (!check())
        //Coloca a peça na tela
        pecasA = pecasAuxiliar;
}

void alocarFila(fila& fila)
{
    pecas auxiliar;

    if (!fila.vazia())
    {
        for (int k = 0; k < 3; k++)
        {
            //Sorteia a figura
            int n = rand() % 7;

            //Cria um proximo elemento
            for (int i = 0; i < 4; i++)
            {
                auxiliar.x[i] = figures[n][i] % 2;
                auxiliar.y[i] = figures[n][i] / 2;
            }

            fila.inserir(auxiliar);
        }
    }
    else
    {
        fila.inserir(pecasB);
        fila.inserir(pecasC);
        fila.inserir(pecasD);
    }
}

void desenvolverPeca(fila &fila)
{
    //Verifica se a fila está vazia
    if (!fila.vazia())
    {
        //Caso não esteja vazia, retira o elemento da fila e coloca na tela
        pecasA = fila.retirar();


        if (!fila.vazia())
            pecasB = fila.retornarValor(0);

        if (!fila.vazia())
            pecasC = fila.retornarValor(1);

        //fila.inserir(pecasB);
        //fila.inserir(pecasC);
    }
    else
    {
        //Sorteia a figura
        int n = rand() % 7;

        //Gera a elemento quando a fila está fazia
        for (int i = 0; i < 4; i++)
        {
            pecasA.x[i] = figures[n][i] % 2;
            pecasA.y[i] = figures[n][i] / 2;
        }

        n = rand() % 7;

        //Gera a elemento quando a fila está fazia
        for (int i = 0; i < 4; i++)
        {
            pecasB.x[i] = figures[n][i] % 2;
            pecasB.y[i] = figures[n][i] / 2;
        }

        n = rand() % 7;

        //Gera a elemento quando a fila está fazia
        for (int i = 0; i < 4; i++)
        {
            pecasC.x[i] = figures[n][i] % 2;
            pecasC.y[i] = figures[n][i] / 2;
        }

        n = rand() % 7;

        //Gera a elemento quando a fila está fazia
        for (int i = 0; i < 4; i++)
        {
            pecasD.x[i] = figures[n][i] % 2;
            pecasD.y[i] = figures[n][i] / 2;
        }
    }

    alocarFila(fila);
}

void desenvolverPeca(int &colorNum, float &timer, float delay, fila &fila)
{
    if (timer > delay)
    {
        //Copia os dados para a variável auxiliar
        pecasAuxiliar = pecasA;

        for (int i = 0; i < 4; i++) 
            pecasA.y[i] += 1;

        //Verifica se a peça chegou no final
        if (!check())
        {
            //Move a peça em Y
            for (int i = 0; i < 4; i++)
                field[pecasAuxiliar.y[i]][pecasAuxiliar.x[i]] = colorNum;

            //Sorteia o número da cor
            colorNum = 1 + rand() % 7;
            
            //Desenvolve a peça
            desenvolverPeca(fila);
        }

        timer = 0;
    }
}


void sleep(float seconds) {

    //Implementação da função de espera.
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    
    while (clock() < startClock + secondsAhead);
    return;
}

int checagemLinha(pilha &pilha)
{
    int k = M - 1;
    for (int i = M - 1; i > 0; i--)
    {
        
        //Verifica se foi completada a linha para retirar
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (field[i][j])
                count++;
               
            field[k][j] = field[i][j];
        }
        
        if (count < N)
            k--;

        //Função perdeu 
        if(k == 0 && count != 0)
        {
            //Cria uma nova tela
            RenderWindow window(VideoMode(500, 500), "Você perdeu!");

            //Insere a imagem na tela
            Texture a1;
            a1.loadFromFile("images/perdeu.png");
            Sprite s(a1);
            window.draw(s);

            sf::Text texto("Evolução da pontuação", font);
            texto.setCharacterSize(20);
            texto.setFillColor(Color::Black);
            texto.setPosition(100, 10);

            window.draw(texto);

            int t = 0;

            while (!pilha.vazia())
            {
                dadosJogador dados = pilha.retirar();

                //Criação de fonte
                sf::Text texto("Tempo : " + std::to_string(dados.timer) + " Pontuação : " + std::to_string(dados.pontuacao), font);
                texto.setCharacterSize(20);
                texto.setFillColor(Color::Black);
                texto.setPosition(100, 35 + t);

                t = t + 25;

                window.draw(texto);
            }
            
            window.display();
            
            //Espera 10 segundos
            sleep(10.0);

            //Fecha a tela 
            exit(0);
        }
    }

    return k;
}

void principal()
{
    
    pilha pilha; // Pilha para pontuação
    fila fila; // Fila para proximas peças
    dadosJogador dadosJogador1;
    int pontuacao = 0;
    srand(time(0));
    auto now = system_clock::now(); //Ativa o clock

    //Cria a tela do jogo
    RenderWindow window(VideoMode(500, 420), "Tetris, o jogo!");

    //Carrega as imagens
    Texture t1, t2, t3;
    t1.loadFromFile("images/tiles.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/crianca.png");

    Sprite s(t1), background(t2), crianca(t3), pecaProximo1(t1), pecaProximo2(t1);

    //Declara as variáveis 
    int dx = 0; bool rotate = 0; int colorNum = 1;
    float timer = 0, delay = 0.3;

    Clock clock;

    while (window.isOpen())
    {
        //Dispara o clock
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        //Verifica se foi apertado algum botão do teclado
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

            if (e.type == Event::KeyPressed)
                if (e.key.code == Keyboard::Up) rotate = true;
                else if (e.key.code == Keyboard::Left) dx = -1;
                else if (e.key.code == Keyboard::Right) dx = 1;
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;

        // Move
        mover(dx);

        //Girar
        rotacao(rotate);

        //Criar peça
        desenvolverPeca(colorNum, timer, delay, fila);

        //Checa Linhas//
        int linhaCheck = checagemLinha(pilha);

        //Insere a pontuação na pilha
        if (linhaCheck != 0)
        {
            dadosJogador1.pontuacao += linhaCheck;
            dadosJogador1.timer = system_clock::to_time_t(now);
            pilha.inserir(dadosJogador1);
        }

        
        dx = 0; rotate = 0; delay = 0.3;

        //Criação de fonte
        sf::Text texto("Pontuação: " + std::to_string(dadosJogador1.pontuacao), font);
        texto.setCharacterSize(20);
        texto.setFillColor(Color::Black);
        texto.setPosition(300, 10);

        sf::Text proxPeca("Proximas Peças - ", font);
        proxPeca.setCharacterSize(20);
        proxPeca.setFillColor(Color::Black);
        proxPeca.setPosition(300, 60);

        //Desenho
        window.clear(Color::Color(0, 173, 148));
        window.draw(texto);
        window.draw(proxPeca);
        window.draw(background);
        crianca.setPosition(246, 260);
        window.draw(crianca);

        //Cria a base onde vai parar as peças
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                if (field[i][j] == 0)
                    continue;

                s.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
                s.setPosition(j * 18, i * 18);
                s.move(28, 35); //offset
                window.draw(s);
            }

        //Cria a peça
        for (int i = 0; i < 4; i++)
        {
            s.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
            s.setPosition(pecasA.x[i] * 18, pecasA.y[i] * 18);
            s.move(28, 35); //offset
            window.draw(s);

            //Cria a proxima peça 
            pecaProximo1.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
            pecaProximo1.setPosition(pecasB.x[i] * 18, pecasB.y[i] * 18);
            pecaProximo1.move(360, 91); //offset
            window.draw(pecaProximo1);

            //Cria a proxima peça 
            pecaProximo2.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
            pecaProximo2.setPosition(pecasC.x[i] * 18, pecasC.y[i] * 18);
            pecaProximo2.move(300, 91); //offset
            window.draw(pecaProximo2);
        }

        window.display();
    }
}

int main(){

    // Tela de inicialização e Musica
    font.loadFromFile("Fonte/eczar-semi-bold.ttf");

    /*sf::Music music;
        if (!music.openFromFile("Music\\BRABA.ogg"))
            return -1; // error
        music.play();
        music.setPitch(1.25);
        music.setLoop(true);

    RenderWindow window1(VideoMode(500, 500), "Bem-Vindo a, Tetris O jogo!");
        Texture j1;
        j1.loadFromFile("images/inicio.png");
        Sprite j(j1);
        window1.draw(j);
        window1.display();
        sleep(15.0);
        window1.close();
        */
   //Chama a função principal do jogo 
    principal();
   
    return 0;
}
