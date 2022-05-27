#ifndef MAP_TESTER
#define MAP_TESTER

#include <map>
#include "../../map.hpp" //path to map
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <streambuf>


#define SIZE_MAP 150
#define START_TIME _clock = clock();
#define FINISH_TIME double(clock() - _clock) / double(CLOCKS_PER_SEC / 1000);
#define MAP std::map<T_key, T_value>
#define FT_MAP ft::map<T_key, T_value>
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define END "\033[0m"
#define YELLOW "\033[1;33m"


template <class T_key,class T_value>
class map_tester
{
    public:
        typedef struct s_result
        {
            double time1;
            double time2;
            std::string s1;
            std::string s2;
            bool error;

            void clear() 
            {
                time1 = 0;
                time2 = 0;
                s1.clear();
                s2.clear();
                error = false;
            }

        } t_result;


        void result(std::string name)
        {
            log << compare(_result.s1, _result.s2);
            log << name;
            log << "  " << _result.time1 << "  " << _map->size() << "\n";
            if (_result.error)
                printf("%s%-20s %10s %12.20sError %s", YELLOW, name.c_str(), END, RED, END);
            else
                printf("%s%-20s %10s %12.20sPassed%s", YELLOW, name.c_str(), END, GREEN, END);
            if (_result.time2 > (_result.time1 * 3))
                printf("%s %15f %s", RED, _result.time2, END);
            else
                printf("%s %15f %s", GREEN, _result.time2, END);
            if (_map->size() != _ft_map->size())
                printf("%s %zu %s\n", RED, _ft_map->size(), END);
            else
                printf("%s %zu %s\n", GREEN, _ft_map->size(), END);
            _result.clear();
        } 

        std::string compare(std::string &a, std::string &b)
        {
            std::string diff;
            int i = 0;

            while (a[i] || b[i])
            {
                if (a[i] != b[i])
                {
                    if (a[i])
                    {
                        diff.push_back(a[i]);
                        diff.push_back(' ');
                    }
                    else
                    {
                        diff.push_back(b[i]);
                        diff.push_back(' ');
                    }
                    _result.error = true;
                }
                ++i;
            }
            return diff;
        }

        void print()
        {    
            std::stringstream ss;
            std::stringstream ss2;

            std::streambuf *old_buf = std::cout.rdbuf(ss.rdbuf());

            for (auto it = _map->begin(); it != _map->end(); ++it)
                std::cout << it->first << it->second;

            std::cout.rdbuf(old_buf);
            _result.s1 = ss.str();

            old_buf = std::cout.rdbuf(ss2.rdbuf());

            for (auto it = _ft_map->begin(); it != _ft_map->end(); ++it)
                std::cout << it->first << it->second;

            std::cout.rdbuf(old_buf);
            _result.s2 = ss2.str();
        }


        void init()
        {
            if (_map)
            {
                delete _map;
                _map = nullptr;
            }
            if (_ft_map)
            {
                delete _ft_map;
                _ft_map = nullptr;
            }
            _map = new MAP;
            _ft_map = new FT_MAP;

            for (int i = 50; i < SIZE_MAP; ++i)
            {
                int rd = rand() % 100 + 1;
                _map->insert(std::make_pair(rd, char(i)));
                _ft_map->insert(ft::make_pair(rd, char(i)));
            }
        }

        void Insert()
        {
            init();
            START_TIME;
            for (int i = 50; i < 100; ++i)
                _map->insert(std::make_pair(i * 4, char(i)));
            _result.time1 = FINISH_TIME;

            START_TIME;
            for (int i = 50; i < 100; ++i)
                _ft_map->insert(ft::make_pair(i * 4, char(i)));
            _result.time2 = FINISH_TIME;

            print();
            result("Insert");
            _result.clear();
        }

        void InserRange()
        {
            init();

            FT_MAP temp1 = *_ft_map;
            MAP temp2 = *_map;

            START_TIME;
            _map->insert(temp2.begin(), temp2.end());
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_map->insert(temp1.begin(), temp1.end());
            _result.time2 = FINISH_TIME;

            print();
            result("InserRange");
            _result.clear();
        }

        void ConstructorRangeAssignOperator()
        {
            init();

            FT_MAP temp1 = *_ft_map;
            MAP temp2 = *_map;

            if(_ft_map)
                delete _ft_map;
            if (_map)
                delete _map;
            START_TIME;
            _map = new MAP(temp2.begin(), temp2.end());
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_map = new FT_MAP(temp1.begin(), temp1.end());
            _result.time2 = FINISH_TIME;

            print();
            result("CtorAssignOperator");
            _result.clear();
        }

        void Erase()
        {
            init();
            START_TIME;
            _map->erase(10);
            _map->erase(20);
            _map->erase(35);
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_map->erase(10);
            _ft_map->erase(20);
            _ft_map->erase(35);
            _result.time2 = FINISH_TIME;

            print();
            result("Erase");
            _result.clear();
        }


        void EraseIterator()
        {
            init();
            START_TIME;
            _map->erase(_map->begin());
            _map->erase(_map->begin());
            _map->erase(_map->begin());
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_map->erase(_ft_map->begin());
            _ft_map->erase(_ft_map->begin());
            _ft_map->erase(_ft_map->begin());
            _result.time2 = FINISH_TIME;

            print();
            result("EraseIterator");
            _result.clear();

        }

        void EraseRange()
        {
            init();
            START_TIME;
            _map->erase(_map->begin(), _map->end());
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_map->erase(_ft_map->begin(), _ft_map->end());
            _result.time2 = FINISH_TIME;

            print();
            result("EraseRange");
            _result.clear();

        }

        void Clear()
        {
             init();
            START_TIME;
            _map->clear();
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_map->clear();
            _result.time2 = FINISH_TIME;

            print();
            result("Clear");
            _result.clear();
        }

        map_tester()
        {
            std::cout << "Test" << std::setw(33) << "Diff" << std::setw(14) << "Time"
            <<  std::setw(10) << "Size" << std::endl;
        }

        ~map_tester()
        {
            log.close();
            if (_map)
                delete _map;
            if (_ft_map)
                delete _ft_map;
        }

    private:
        std::ofstream log{ "Logs.txt"};
        t_result _result;
        MAP *_map = nullptr;
        FT_MAP *_ft_map = nullptr;
        clock_t _clock;
};

#endif