#pragma once
#include <SFML/Graphics.hpp>

#include<string>
#include<fstream>
using namespace std;
#include"tetrimino.h"
#include"well.h"
#include"Zshape.h"
#include"o.h"
#include"I.h"
#include"T.h"
#include"L.h"
#include"J.h"
#include"S.h"
class game:public well,public tetrimino,public Zshape ,public Oshape,public Ishape,public Tshape,public Lshape,public Jshape,public Sshape
{
public:
    string name;
    float tim;
    int f;
    int score;
    int lines;
    int level;
	game()
    {
        level = 0;
        lines = 0;
        score = 0;
        srand(time(0));
        f = rand() % 7;
        tim = 1;
        name = " ";
	}
    void startingwindow()
    {
       
        sf::Texture texture;
        if (!texture.loadFromFile("Capture.png"))
        {
        }
        sf::Sprite sprite(texture);
        sprite.scale(0.9, 0.9);
        sprite.setPosition(180, 10);

        sf::Texture texture1;
        if (!texture1.loadFromFile("menu.png"))
        {
        }
        sf::Sprite sprite1(texture1);
        sprite1.setPosition(163, 322);

        sf::RenderWindow window(sf::VideoMode(700, 700), "Tetris");
        sf::RectangleShape namebox(sf::Vector2f(500, 80));
        namebox.setPosition(100, 170);
        namebox.setFillColor(sf::Color::Black);
        namebox.setOutlineThickness(5.f);
        namebox.setOutlineColor(sf::Color::Red);

        sf::RectangleShape menubox(sf::Vector2f(398,290));
        menubox.setPosition(163,320);
        menubox.setFillColor(sf::Color::Black);
        menubox.setOutlineThickness(5.f);
        menubox.setOutlineColor(sf::Color::Yellow);

        sf::Font font;
        if (!font.loadFromFile("tet.ttf"))
        {
        }
        sf::Text textn;
        textn.setFont(font);
        textn.setCharacterSize(30);
        textn.setFillColor(sf::Color::Red);
        textn.setPosition(260, 265);

        sf::Text ins;
        ins.setFont(font);
        ins.setString("Enter  your  name  and  press  Enter");
        ins.setCharacterSize(40);
        ins.setPosition(150, 180);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();


                else if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode < 128)
                    {
                        if (event.text.unicode == '\b' && !name.empty())
                        {
                            name.pop_back();
                        }
                        else if (event.text.unicode != '\b')
                        {
                            name += static_cast<char>(event.text.unicode);
                        }
                    }
                }
                textn.setString(name);
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                {
                    window.close();
                    startgame();
                }
               
            }
            window.clear(sf::Color::Cyan);      
            window.draw(namebox);
            window.draw(ins);
            window.draw(menubox);
            window.draw(sprite);
            window.draw(sprite1);
            window.draw(textn);
            window.display();
        }
    }

    void text(sf::RenderWindow& window)
    {
        sf::Font f;
        f.loadFromFile("tet.ttf");
        sf::RectangleShape namebox(sf::Vector2f(280, 80));
        namebox.setPosition(370, 90);
        namebox.setFillColor(sf::Color::Black);
        namebox.setOutlineThickness(5.f);
        namebox.setOutlineColor(sf::Color::Red);
        sf::Text t;
        t.setFillColor(sf::Color::Red);
        t.setCharacterSize(40);
        t.setFont(f);
        t.setPosition(400, 103);
        t.setString("Name  "+name);
        sf::RectangleShape scorebox(sf::Vector2f(280, 80));
        scorebox.setPosition(370, 205);
        scorebox.setFillColor(sf::Color::Black);
        scorebox.setOutlineThickness(5.f);
        scorebox.setOutlineColor(sf::Color::Yellow);       
        window.draw(namebox);
        window.draw(scorebox);

        sf::RectangleShape linebox(sf::Vector2f(280, 80));
        linebox.setPosition(370, 317);
        linebox.setFillColor(sf::Color::Black);
        linebox.setOutlineThickness(5.f);
        linebox.setOutlineColor(sf::Color::Red);
       
        sf::RectangleShape lvlbox(sf::Vector2f(280, 80));
        lvlbox.setPosition(370, 429);
        lvlbox.setFillColor(sf::Color::Black);
        lvlbox.setOutlineThickness(5.f);
        lvlbox.setOutlineColor(sf::Color::Yellow);
        
        window.draw(t);
        window.draw(linebox);
        window.draw(lvlbox);
    }

    void scoring(sf::RenderWindow& window,int l,int s,int lvl)
    {
         sf::Font f;
            f.loadFromFile("tet.ttf");
            sf::Text score;
            score.setFillColor(sf::Color::Yellow);
            score.setCharacterSize(40);
            score.setFont(f);
            score.setPosition(400, 220);
            std::string sc= "Score          "+ std::to_string(s);
            score.setString(sc);

            sf::Text lines;
            lines.setFillColor(sf::Color::Red);
            lines.setCharacterSize(40);
            lines.setFont(f);
            lines.setPosition(400, 328);
            std::string li ="Lines          "+ std::to_string(l);
            lines.setString(li);

            sf::Text level;
            level.setFillColor(sf::Color::Yellow);
            level.setCharacterSize(40);
            level.setFont(f);
            level.setPosition(400, 440);
            std::string lev = "Level         "+std::to_string(lvl);
            level.setString(lev);
            window.draw(level);
            window.draw(lines);
            window.draw(score);
    }
  
    void gameend()
    {
        string n1, n2, n3, n4, n5;
        int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
        ifstream fin("score.txt");
        fin >> p1 >> p2 >> p3 >> p4 >> p5;
        ifstream finn("names.txt");
        getline(finn, n1);
        getline(finn, n2);
        getline(finn, n3);
        getline(finn, n4);
        getline(finn, n5);

        sf::Font f;
        f.loadFromFile("tet.ttf");

        sf::Text n11;
        n11.setFillColor(sf::Color::Red);
        n11.setCharacterSize(30);
        n11.setFont(f);
        n11.setPosition(210, 350);
        n11.setString(n1);

        sf::Text n12;
        n12.setFillColor(sf::Color::Red);
        n12.setCharacterSize(30);
        n12.setFont(f);
        n12.setPosition(210, 400);
        n12.setString(n2);

        sf::Text n13;
        n13.setFillColor(sf::Color::Red);
        n13.setCharacterSize(30);
        n13.setFont(f);
        n13.setPosition(210, 450);
        n13.setString(n3);

        sf::Text n14;
        n14.setFillColor(sf::Color::Red);
        n14.setCharacterSize(30);
        n14.setFont(f);
        n14.setPosition(210, 500);
        n14.setString(n4);

        sf::Text n15;
        n15.setFillColor(sf::Color::Red);
        n15.setCharacterSize(30);
        n15.setFont(f);
        n15.setPosition(210, 550);
        n15.setString(n5);

        sf::Text p11;
        p11.setFillColor(sf::Color::Red);
        p11.setCharacterSize(30);
        p11.setFont(f);
        p11.setPosition(390, 350);
        p11.setString("" + std::to_string(p1));

        sf::Text p12;
        p12.setFillColor(sf::Color::Red);
        p12.setCharacterSize(30);
        p12.setFont(f);
        p12.setPosition(390, 400);
        p12.setString("" + std::to_string(p2));

        sf::Text p13;
        p13.setFillColor(sf::Color::Red);
        p13.setCharacterSize(30);
        p13.setFont(f);
        p13.setPosition(390, 450);
        p13.setString("" + std::to_string(p3));

        sf::Text p14;
        p14.setFillColor(sf::Color::Red);
        p14.setCharacterSize(30);
        p14.setFont(f);
        p14.setPosition(390, 500);
        p14.setString("" + std::to_string(p4));

        sf::Text p15;
        p15.setFillColor(sf::Color::Red);
        p15.setCharacterSize(30);
        p15.setFont(f);
        p15.setPosition(390, 550);
        p15.setString("" + std::to_string(p5));



        sf::RenderWindow window(sf::VideoMode(700,700 ), "Tetris");
        window.setFramerateLimit(60);
        while (window.isOpen())
        {
            sf::RectangleShape scorebox(sf::Vector2f(280, 100));
            scorebox.setPosition(200, 250);
            scorebox.setFillColor(sf::Color::Black);
            scorebox.setOutlineThickness(5.f);
            scorebox.setOutlineColor(sf::Color::Yellow);
            sf::Font f;
            f.loadFromFile("tet.ttf");
            sf::Text t;
            t.setFillColor(sf::Color::Red);
            t.setCharacterSize(100);
            t.setFont(f);
            t.setPosition(200, 90);
            t.setString("GAME OVER");
            sf::Text t1;
            t1.setFillColor(sf::Color::Red);
            t1.setCharacterSize(40);
            t1.setFont(f);
            t1.setPosition(230, 270);
            std::string ys = "Your Score   " + std::to_string(score);
            t1.setString(ys);

            sf::RectangleShape high(sf::Vector2f(280, 250));
            high.setPosition(200, 350);
            high.setFillColor(sf::Color::Black);
            high.setOutlineThickness(5.f);
            high.setOutlineColor(sf::Color::Yellow);

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
            window.clear(sf::Color::Cyan);
            window.draw(t);
            window.draw(scorebox);
            window.draw(high);
            window.draw(t1);
            window.draw(n11);
            window.draw(n12);
            window.draw(n13);
            window.draw(n14);
            window.draw(n15);
            window.draw(p11);
            window.draw(p12);
            window.draw(p13);
            window.draw(p14);
            window.draw(p15);
            window.display();
        }
       
    }

    void leveling(int sco)
    {
        int sc = sco % 8001 ;
        if (sc < 1000)
            level = 0;
        else if (sc >= 1000 &&sc<2000)
            level = 1;
        else if (sc >= 2000 && sc < 3000)
            level = 2;
        else if (sc >= 3000 && sc < 4000)
            level = 3;
        else if (sc >=4000 && sc < 5000)
            level = 4;
        else if (sc >= 5000 && sc < 6000)
            level = 5;
        else if (sc >= 6000 && sc < 7000)
            level = 6;
        else if (sc >= 7000 && sc < 8000)
            level = 7;
        else if (sc >= 8000)
            level = 8;
    }
    void clearLine(int **ar)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int r = 19; r >= 0; r--)
            {
                bool clear = true;
                for (int i = 0; i < 10 && clear == true; i++)
                {
                    if (ar[r][i] == 0)
                    {
                        clear = false;
                    }
                }
                if (clear == true)
                {
                    lines++;
                    score += 100;
                    for (int k = r - 1; k >= 0; k--)
                    {
                        for (int j = 0; j < 10; j++)
                        {
                            ar[k + 1][j] = ar[k][j];
                        }
                    }
                    for (int h = 0; h < 10; h++)
                    {
                        ar[0][h] = 0;
                    }
                }
            }
        }
    }
    void timecontrol(int lvl)
    {
        if (lvl == 1)
            tim = 0.9;
        if (lvl == 2)
            tim = 0.81;
        if (lvl == 3)
            tim = 0.729;
        if (lvl == 4)
            tim = 0.6561;
        if (lvl == 5)
            tim = 0.59;
        if (lvl == 6)
            tim = 0.531;
        if (lvl == 7)
            tim = 0.48;
        if (lvl == 8)
            tim = 0.432;
    }
    void filemanage()
    {
        string n1, n2, n3, n4, n5;
        int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
        ifstream fin("score.txt");
        fin >> p1 >> p2 >> p3 >> p4 >> p5;
        ifstream finn("names.txt");
        getline(finn, n1);
        getline(finn, n2);
        getline(finn, n3);
        getline(finn, n4);
        getline(finn, n5);
        if (score > p1)
        {
            int t1 = p1;
            p1 = score;
            int t2 = p2;
            p2 = t1;
            int t3 = p3;
            p3 = t2;
            int t4 = p4;
            p4 = t3;
            int t5 = p5;
            p5 = t4;
            string m1 = n1;
            n1 = name;
            string m2 = n2;
            n2 = m1;
            string m3 = n3;
            n3 = m2;
            string m4 = n4;
            n4 = m3;
            string m5 = n5;
            n5 = m4;
        }
        else if (score > p2)
        {
            int t2 = p2;
            p2 = score;
            int t3 = p3;
            p3 = t2;
            int t4 = p4;
            p4 = t3;
            int t5 = p5;
            p5 = t4;
            string m2 = n2;
            n2 = name;
            string m3 = n3;
            n3 = m2;
            string m4 = n4;
            n4 = m3;
            string m5 = n5;
            n5 = m4;
        }
        else if (score > p3)
        {
            int t3 = p3;
            p3 = score;
            int t4 = p4;
            p4 = t3;
            int t5 = p5;
            p5 = t4;
            string m3 = n3;
            n3 = name;
            string m4 = n4;
            n4 = m3;
            string m5 = n5;
            n5 = m4;
        }
        else if (score > p4)
        {
            int t4 = p4;
            p4 = score;
            int t5 = p5;
            p5 = t4;
            string m4 = n4;
            n4 = name;
            string m5 = n5;
            n5 = m4;
        }
        else if (score > p5)
        {
            p5 = score;
            n5 = name;
        }
        ofstream fout;
        fout.open("score.txt");
        ofstream foutt;
        foutt.open("names.txt");
        fout << p1 << endl;
        fout << p2 << endl;
        fout << p3 << endl;
        fout << p4 << endl;
        fout << p5;
        foutt << n1 << endl;
        foutt << n2 << endl;
        foutt << n3 << endl;
        foutt << n4 << endl;
        foutt << n5 << endl;
    }
	void startgame()
	{ 
        sf::RenderWindow window(sf::VideoMode(700, 700), "Tetris");
        window.setFramerateLimit(60);
        sf::RectangleShape layout(sf::Vector2f(222, 442));
        layout.setPosition(100, 90);
        layout.setFillColor(sf::Color::Transparent);
        layout.setOutlineThickness(5.f);
        layout.setOutlineColor(sf::Color::Red);
        sf::Texture texture;
        if (!texture.loadFromFile("logo.png"))
        {
        }
        sf::Sprite sprite(texture);
        sprite.scale(0.9,0.9);
        sprite.setPosition(70,-40);
        tetrimino* ptr[8];
        Zshape z;
        well w;
        Oshape o;
        Ishape i;
        Tshape t;
        Lshape l;
        Jshape j;
        Sshape s;
        ptr[0] = &z;
        ptr[1] = &o;
        ptr[2] = &i;
        ptr[3] = &t;
        ptr[4] = &l;
        ptr[5] = &j;
        ptr[6] = &s;
        ptr[7] = &w;
        int r = 0;
        sf::Clock clock;
        sf::Time dropdelay = sf::seconds(tim);
        int li = 0;//lines
        int sc = 0;//score
       
        bool hasLanded = false;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    gameend();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                    gameend();
                }
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    score += 500;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    r++;
                    r = r % 4;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    ptr[f]->movel(r, w.ar);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    ptr[f]->mover(r, w.ar);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    ptr[f]->moved(r, w.ar);
                }
            }
            window.clear(sf::Color::Cyan);
            text(window);
            window.draw(sprite);
            ptr[f]->rotate(r);
            ptr[f]->draw(window, w.ar);
            leveling(score);
            timecontrol(level);
            window.draw(layout);
            ptr[f]->drawb(window, w.ar);
            scoring(window, lines, score, level);
            window.display();

            sf::Time elapsed = clock.getElapsedTime();
            if (elapsed >= dropdelay)
            {
                ptr[f]->drop(r, w.ar);
                clock.restart();
            }
            if (ptr[f]->stopgame(w.ar))
            {
                window.close();
                gameend();
            }

            if (ptr[f]->landed())
            {
                if (!hasLanded) {
                    clearLine(w.ar);
                    srand(time(nullptr));
                    f = rand()%7;
                    r = 0;
                    if (f == 1)
                    {
                        tetrimino::setlocationx(166);
                        tetrimino::setlocationy(68);
                    }
                    hasLanded = true;
                }
            }
            else {
                hasLanded = false;
            }
        }
        filemanage();
        
	}
   
};
