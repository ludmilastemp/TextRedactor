#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>

int n = 0;
int s = 0;
std::vector<std::string*> strings(100);
std::string mass[100] = { "123", "234", "3{4***}5", "4*3**7878*1", "ff{543}e67{ty8nkt32}1l26", "9rt57", "0789", "888", "901", "012" };
std::string functions[10] = { "Insert one line", "Insert multiple line", "Delete a line", "Insert substring", "Replace element", "Replace substring", "Removing leading zeros", "Numbers in ascending order", "Change the asterisks", "Remove curly braces" };
std::string questions[10] = { "Vedite cifry i stroky", "Vedite cifry i stroki", "Kakiu stroke ydalit?", "What xotite vsravit?", "Kakoi element xotite camenit&", "What? Na what?", "V kakix strokax ydali?", "V kakix strokax?", "V kakix strokax?", "V kakix strokax?" };

void FillingVector() {
    for (int i = 0; i < 100; ++i) strings[i] = &mass[i];
}

void Сourse(int n, int s, sf::Font& font, sf::RenderWindow& window) {
    sf::Text text;
    text.setFont(font);
    text.setString("|");
    text.setCharacterSize(13);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(s * 10 - 4, n * 20);
    window.draw(text);
}

void FillingFunctionWindow(sf::Font& font, sf::RenderWindow& window1) {
    for (int i = 0; i < 10; i++) {
        sf::Text text;
        text.setFont(font);
        text.setString(functions[i]);
        text.setCharacterSize(17);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        text.setPosition(0, 20 * i);
        window1.draw(text);
    }
}

void OutputStrings(int n, sf::Font& font, sf::RenderWindow& window) {
    std::string str;
    for (int i = 0; i < 100; i++) {
        if ((*strings[i]).size() > 30) {
            for (int j = 97; j > i; j--) {
                str = *strings[j];
                *strings[j + 1] = str;
            }
            str = "";
            for (int j = 30; j < (*strings[i]).size(); j++) str += (*strings[i])[j];
            *strings[i + 1] = str;
            (*strings[i]).erase(30);
            ++n;
        }
        sf::Text text;
        text.setFont(font);
        text.setString(*strings[i]);
        text.setCharacterSize(17);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Regular);
        text.setPosition(0, 20 * i);
        window.draw(text);
    }
}

void InputWindow(int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    sf::Text text;
    text.setFont(font);
    text.setString(questions[f]);
    text.setCharacterSize(17);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(0, 0);
    window2.draw(text);
    text.setFont(font);
    text.setString(a1);
    text.setCharacterSize(17);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(0, 20);
    window2.draw(text);
    text.setFont(font);
    text.setString(a2);
    text.setCharacterSize(17);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(0, 40);
    window2.draw(text);
    text.setFont(font);
    text.setString(a3);
    text.setCharacterSize(17);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(0, 60);
    window2.draw(text);
}

void Input(int f, std::string& a1, std::string& a2, std::string& a3, sf::Font& font, sf::RenderWindow& window2) {
    int y = 0;
    int intm;
    while (window2.isOpen())
    {
        sf::Event event;
        while (window2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window2.close();
            else if (y == 0) {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    if (f == 2 || f == 9)  window2.close();
                    else {
                        y = 1;
                        intm = stoi(a1);
                    }
                }
                else if (event.type == sf::Event::TextEntered && event.text.unicode != 13 && event.text.unicode != 8) {
                    a1 += event.text.unicode;
                }
                else if (event.key.code == sf::Keyboard::Backspace) {
                    int k = a1.size() - 1;
                    a1.erase(k);
                }
            }
            else if (y == 1) {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    if (f == 0 || f == 5 || f == 6 || f == 7 || f == 8) window2.close();
                    else if (f == 1) {
                        for (int q = 97; q >= intm; q--) {
                            std::string str = *strings[q];
                            *strings[q + 1] = str;
                        }
                        *strings[intm] = a2;
                        intm += 1;
                        n = intm + 1;
                        a2 = "";
                    }
                    else y = 2;
                }
                else if (event.type == sf::Event::TextEntered && event.text.unicode != 13 && event.text.unicode != 8) {
                    a2 += event.text.unicode;
                }
                else if (event.key.code == sf::Keyboard::Backspace) {
                    int k = a2.size() - 1;
                    a2.erase(k);
                }
            }
            else if (y == 2) {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    if (f == 3 || f == 4) window2.close();
                    else y = 3;
                }
                else if (event.type == sf::Event::TextEntered && event.text.unicode != 13 && event.text.unicode != 8) {
                    a3 += event.text.unicode;
                }
                else if (event.key.code == sf::Keyboard::Backspace) {
                    int k = a3.size() - 1;
                    a3.erase(k);
                }
            }
        }
        window2.clear();
        InputWindow(f, a1, a2, a3, font, window2);
        window2.display();
    }
}

void InsertOneLine(int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    Input(f, a1, a2, a3, font, window2);
    int intm = stoi(a1);
    for (int q = 97; q >= intm; q--) {
        std::string str = *strings[q];
        *strings[q + 1] = str;
    }
    *strings[intm] = a2;
    n = intm;
    s = (*strings[n]).size();
}

void InsertMultipleLine(int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    Input(f, a1, a2, a3, font, window2);
    s = (*strings[n]).size();
}

void DeleteLine(int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    Input(f, a1, a2, a3, font, window2);
    int intm = stoi(a1);
    for (int q = intm - 1; q <= 98; q++) {
        std::string str = *strings[q + 1];
        *strings[q] = str;
    }
    n = intm - 1;
    s = 0;
}

void InsertSubstrin(int& s, int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    Input(f, a1, a2, a3, font, window2);
    int intm = stoi(a1) - 1;
    int intc = stoi(a2);
    int z = (*strings[intm]).size();
    std::string str1 = *strings[intm];
    str1.erase(intc);
    str1 += a3;
    s = (str1).size();
    n = intm;
    for (int q = intc; q < z; q++) {
        char ch = (*strings[intm])[q];
        str1 += ch;
    }
    *strings[intm] = str1;
}

void ReplaceElement(int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    Input(f, a1, a2, a3, font, window2);
    int intm = stoi(a1) - 1;
    int intc = stoi(a2) - 1;
    (*strings[intm])[intc] = a3[0];
    s = intc + 1;
    n = intm;
}

void ReplaceSubstring(int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    Input(f, a1, a2, a3, font, window2);
    int k = a1.size() - 1;
    int r = a2.size() - 1;
    int t = 0;
    for (int i = 0; i <= 97; i++) {
        int p = (*strings[i]).size();
        for (int j = 0; j <= p - k; j++) {
            for (int q = 0; q <= k; q++) {
                if ((*strings[i])[j + q] == a1[q]) t += 1;
            }
            if (t == k + 1) {
                std::string str = *strings[i];
                str.erase(j);
                str += a2;
                for (int q = j + k + 1; q < p; q++)  str += (*strings[i])[q];
                if (k > r) str.erase(p - k + r);
                *strings[i] = str;
                n = i;
            }
            t = 0;
        }
    }
    s = (*strings[n]).size();
}

void RemovingLeadingZeros(int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    Input(f, a1, a2, a3, font, window2);
    int m = stoi(a1) - 1;
    int c = stoi(a2) - 1;
    char str;
    for (int i = m; i <= c; i++) {
        int p = (*strings[i]).size();
        for (int j = 0; j < p - 1; j++) {
            if (j == 0 && (*strings[i])[j] == '0' && (int)(*strings[i])[j + 1] > 47 && (int)(*strings[i])[j + 1] < 58) {
                for (int r = j; r < p - 1; r++) {
                    str = (*strings[i])[r + 1];
                    (*strings[i])[r] = str;
                }
                (*strings[i]).erase(p - 1);
                j -= 1;
            }
            else if ((*strings[i])[j] == '0' && (int)(*strings[i])[j + 1] > 47 && (int)(*strings[i])[j + 1] < 58 && ((int)(*strings[i])[j - 1] < 48 || (int)(*strings[i])[j - 1] > 57)) {
                for (int r = j; r < p - 1; r++) {
                    str = (*strings[i])[r + 1];
                    (*strings[i])[r] = str;
                }
                (*strings[i]).erase(p - 1);
                j -= 1;
            }
        }
    }
    s = (*strings[n]).size();
}

void NumbersAscendingOrder(int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    Input(f, a1, a2, a3, font, window2);
    int m = stoi(a1) - 1;
    int c = stoi(a2) - 1;
    int b = -1;
    int e = -1;
    int check = 0;
    char str;
    for (int i = m; i <= c; i++) {
        int p = (*strings[i]).size();
        int j = 0;
        while (j < p - 1 && p != 0) {
            while (((int)(*strings[i])[j] < 48 || (int)(*strings[i])[j] > 57) && j != p - 1) {
                j++;
            }
            b = j;
            while (((int)(*strings[i])[j] > 47 && (int)(*strings[i])[j] < 58) && j != p - 1) {
                j++;
            }
            e = j;
            if (j != p - 1) e -= 1;
            for (int r = b; r < e; r++) {
                if ((int)(*strings[i])[r] >= (int)(*strings[i])[r + 1]) {
                    check = 1;
                }
            }
            if (b == e && (int)(*strings[i])[b] > 47 && (int)(*strings[i])[b] < 58) {
                check = 1;
            }
            if (check == 1) {
                for (int r = 0; r < p - e + 1 && r < p - e - 1; r++) {
                    str = (*strings[i])[e + r + 1];
                    (*strings[i])[b + r] = str;
                }
                (*strings[i]).erase(p - e + b - 1);
                j = b;
            }
            if (check == 0) j += 1;
            b = -1;
            e = -1;
            check = 0;
            p = (*strings[i]).size();
        }
    }
    s = (*strings[n]).size();
}

void ChangeAsterisks(int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    Input(f, a1, a2, a3, font, window2);
    int m = stoi(a1) - 1;
    int c = stoi(a2) - 1;
    char str;
    for (int i = m; i <= c; i++) {
        int p = (*strings[i]).size();
        for (int j = 0; j < p - 1; j++) {
            if ((int)(*strings[i])[j] == 42 && (int)(*strings[i])[j + 1] == 42) {
                (*strings[i])[j] = '+';
                for (int r = j + 1; r < p - 1; r++) {
                    str = (*strings[i])[r + 1];
                    (*strings[i])[r] = str;
                }
                (*strings[i]).erase(p - 1);
                p -= 1;
            }
        }
    }
    s = (*strings[n]).size();
}

void RemoveCurlyBraces(int f, std::string a1, std::string a2, std::string a3, sf::Font& font, sf::RenderWindow& window2) {
    Input(f, a1, a2, a3, font, window2);
    int m = stoi(a1) - 1;
    char str;
    int check1 = 0;
    int check2 = 0;
    for (int i = m; i <= m; i++) {
        int p = (*strings[i]).size();
        int j = 0;
        while ((int)(*strings[i])[j] != 123 && j < p - 1) {
            j++;
        }
        check1 = j;
        while ((int)(*strings[i])[j] != 125 && j < p - 1) {
            j++;
        }
        check2 = j;
        if ((int)(*strings[i])[j] != 125 || (int)(*strings[i])[check1] != 123) {
            check2 = -1;
        }
        if (check2 != -1) {
            for (int r = 0; r < p - 1 && check2 + 1 + r < p; r++) {
                str = (*strings[i])[check2 + 1 + r];
                (*strings[i])[check1 + r] = str;
            }
            (*strings[i]).erase(p - check2 + check1 - 1);
            p = (*strings[i]).size();
            i -= 1;
        }
    }
    s = (*strings[n]).size();
}

void MainEvens(sf::RenderWindow& window) {
    while (window.isOpen())
    {
        sf::Font font;
        if (!font.loadFromFile("D:/Proga/TextRedactor/LiberationMono-Regular.ttf")){}
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                n = event.mouseButton.y / 20;
                s = event.mouseButton.x / 11 + 1;
                if (s > (*strings[n]).size()) {
                    s = (*strings[n]).size();
                }
            }
            else if (event.type == sf::Event::TextEntered && event.text.unicode != 13 && event.text.unicode != 8) {
                if ((*strings[n]).size() > 29) {
                    std::string str;
                    for (int j = 97; j > n; j--) {
                        str = *strings[j];
                        *strings[j + 1] = str;
                    }
                    *strings[n + 1] = "";
                    n += 1;
                    s = 0;
                }
                int z = (*strings[n]).size();
                std::string str1 = *strings[n];
                str1.erase(s);
                str1 += event.text.unicode;
                for (int q = s; q < z; q++) {
                    char ch = (*strings[n])[q];
                    str1 += ch;
                }
                *strings[n] = str1;
                s += 1;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace) {
                std::string str = *strings[n];
                int k = str.size();
                if (k == 0) {
                    for (int j = n; j < 97; j++) {
                        str = *strings[j + 1];
                        *strings[j] = str;
                    }
                    n -= 1;
                    if (n == -1) {
                        n = 0;
                        s = 0;
                    }
                    else s = (*strings[n]).size();
                }
                else if (s == 0) {
                    n -= 1;
                    if (n == -1) n = 0;
                    else s = (*strings[n]).size();
                }
                else {
                    str.erase(s - 1);
                    for (int q = s; q < k; q++) {
                        char ch = (*strings[n])[q];
                        str += ch;
                    }
                    str.erase(k - 1);
                    *strings[n] = str;
                    s -= 1;
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                for (int i = 98; i > n; i--) {
                    std::string str = *strings[i];
                    *strings[i + 1] = str;
                }
                *strings[n + 1] = "";
                n += 1;
                s = 0;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && n > 0) {
                if (s > (*strings[n - 1]).size()) {
                    s = (*strings[n - 1]).size();
                }
                n -= 1;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                n += 1;
                if (s > (*strings[n]).size()) {
                    s = (*strings[n]).size();
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
                if (s == 0 && n > 0) {
                    n -= 1;
                    s = (*strings[n]).size();
                }
                else if (s > 0) {
                    s -= 1;
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                if (s == (*strings[n]).size()) {
                    n += 1;
                    s = 0;
                }
                else s += 1;
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {       //открытие окна функций
                sf::RenderWindow window1(sf::VideoMode(300, 200), "Choose a team");
                while (window1.isOpen())
                {
                    sf::Event event;
                    while (window1.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                            window1.close();
                        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                            int f = event.mouseButton.y / 20;
                            std::string a1 = ""; //переменные для ввода
                            std::string a2 = "";
                            std::string a3 = "";
                            if (f == 0) { //вставить одну строку
                                sf::RenderWindow window2(sf::VideoMode(300, 200), "BB: n, s");
                                InsertOneLine(f, a1, a2, a3, font, window2);
                                window1.close();

                            }
                            else if (f == 1) { //вставить несколько строк
                                sf::RenderWindow window2(sf::VideoMode(300, 200), "BB: n, s, s...");
                                InsertMultipleLine(f, a1, a2, a3, font, window2);
                                window1.close();
                            }
                            else if (f == 2) { //удалить строку
                                sf::RenderWindow window2(sf::VideoMode(300, 200), "BB: n ");
                                DeleteLine(f, a1, a2, a3, font, window2);
                                window1.close();
                            }
                            else if (f == 3) {
                                sf::RenderWindow window2(sf::VideoMode(300, 200), "BB: n, n, s");
                                InsertSubstrin(s, f, a1, a2, a3, font, window2);
                                window1.close();
                            }
                            else if (f == 4) {
                                sf::RenderWindow window2(sf::VideoMode(300, 200), "BB: n, n, s");
                                ReplaceElement(f, a1, a2, a3, font, window2);
                                window1.close();
                            }
                            else if (f == 5) {
                                sf::RenderWindow window2(sf::VideoMode(300, 200), "BB: s, s");
                                ReplaceSubstring(f, a1, a2, a3, font, window2);
                                window1.close();
                            }
                            else if (f == 6) {
                                sf::RenderWindow window2(sf::VideoMode(300, 200), "BB: n, n");
                                RemovingLeadingZeros(f, a1, a2, a3, font, window2);
                                window1.close();
                            }
                            else if (f == 7) {
                                sf::RenderWindow window2(sf::VideoMode(300, 200), "BB: n, n");
                                NumbersAscendingOrder(f, a1, a2, a3, font, window2);
                                window1.close();
                            }
                            else if (f == 8) {
                                sf::RenderWindow window2(sf::VideoMode(300, 200), "BB: n, n");
                                ChangeAsterisks(f, a1, a2, a3, font, window2);
                                window1.close();
                            }
                            else if (f == 9) {
                                sf::RenderWindow window2(sf::VideoMode(300, 200), "BB: n");
                                RemoveCurlyBraces(f, a1, a2, a3, font, window2);
                                window1.close();
                            }
                        }
                    }
                    window1.clear();
                    FillingFunctionWindow(font, window1);
                    window1.display();
                }
            }
        }
        window.clear();
        OutputStrings(n, font, window);
        Сourse(n, s, font, window);
        if (n == -1) n = 0;
        window.display();
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");
    window.setKeyRepeatEnabled(false);
    FillingVector();
    MainEvens(window);
    return 0;
}