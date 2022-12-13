/*
Вариант 3
В текстовом файле input.txt записан русский текст. Найти в тексте слова,
содержащие ровно одну из 10 наиболее часто встречающихся букв текста записать их заглавными буквами
и указать после каждого такого слова в скобках найденную букву. Полученный текст записать в файл output.txt.
Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>



int main()
{
    setlocale(LC_ALL, "rus");
    int cnt_letters[33] = {};
    char alph[33] = { 'а', 'б', 'в', 'г', 'д','е','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я','ё' };
    //коды ё = 184 168 
    std::ifstream in("input.txt", std::ios::in);
    std::string arr_text[1000];
    int ind_text = 0;
    while (!in.eof())
    {
        char word[35];
        in >> word;

        arr_text[ind_text] = word;

        for (int i = 0; i < strlen(word) - 1; i++)
        {
            char k = word[i];
            int ind = (int)static_cast<unsigned char>(k);
            if (224 <= ind and ind <= 255) // коды строчных букв
            {   
                ind -= 32;
            }
            // подсчет букв
            if (192 <= ind and ind <= 223) // коды заглавных букв
            {
                //std::cout << ind - 192 << ' ' << k <<  '\n';
                cnt_letters[ind - 192] += 1;
            }
            if (ind == 184 or ind == 168)
            {
                cnt_letters[32] += 1;
            }
        }
        ind_text += 1;
    }

    // сортировка букв
    for (int i = 0; i < 32; i++)
    {
        for (int j = i + 1; j < 33; j++)
        {
            if (cnt_letters[i] < cnt_letters[j])
            {
                std::swap(cnt_letters[i], cnt_letters[j]);
                std::swap(alph[i], alph[j]);
            }
        }

    }

    char max_cnt_letters[10];
    for (int i = 0; i < 10; i++)
    {
        max_cnt_letters[i] = alph[i];
    }
    
    std::ofstream out("output.txt", std::ios::out);

   //проверка на единственность символа в слове и его запись
    for (int i = 0; i < 1000; i++)
    {
        char word[35];
        int cur_cnt = 0;
        strcpy_s(word, arr_text[i].c_str());
        char cur_letter;
        //word = (char)(arr_text[i]);
        for (int j = 0; j < 10; j++)
        {
            
            for (int k = 0; k < 35; k++)
            {
                if (word[k] == max_cnt_letters[j])
                {
                    cur_cnt += 1;
                    cur_letter = word[k];
                    
                    break;
                }
            }
            
        }
        if (cur_cnt == 1)
        {
            char done_word[35]{};
            for (int p = 0; p < 35; p++)
            {
                if (192 <= static_cast<unsigned char>(word[p]) and static_cast<unsigned char>(word[p]) <= 223 or static_cast<unsigned char>(word[p]) == 168)
                {
                    done_word[p] = word[p];
                }
                else if (224 <= static_cast<unsigned char>(word[p]) and static_cast<unsigned char>(word[p]) <= 255 or static_cast<unsigned char>(word[p]) == 184)
                {
                    unsigned char cur_l;
                    cur_l = static_cast<char>(static_cast<unsigned char>(word[p]) - 32);

                    done_word[p] = cur_l;
                }
            }
            //out << done_word << '(' << max_cnt_letters[j] << ')' << '\n';
            std::string write_in_word = done_word;
            write_in_word = write_in_word + '(' + cur_letter + ')';
            arr_text[i] = write_in_word;         
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        out << arr_text[i] << ' ';
    }
}