#ifndef VECTOR_TESTER_HPP
#define VECTOR_TESTER_HPP

#include <vector>
#include "../vector.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <streambuf>

#define START_TIME _clock = clock();
#define FINISH_TIME double(clock() - _clock) / double(CLOCKS_PER_SEC / 1000);
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define END "\033[0m"
#define YELLOW "\033[1;33m"

template<class T>
class vector_test
{
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

    private:
        std::ofstream log{ "Logs"};
        t_result _result;
        std::vector<T> _vec;
        ft::vector<T> _ft_vec;
        clock_t _clock;

        void result(std::string name)
        {
            log << compare(_result.s1, _result.s2);
            log << name;
            log << "  " << _result.time1 << "  " << _vec.capacity() << "\n";
            if (_result.error)
                printf("%s%-20s %10s %12.20sError %s", YELLOW, name.c_str(), END, RED, END);
            else
                printf("%s%-20s %10s %12.20sPassed%s", YELLOW, name.c_str(), END, GREEN, END);
            if (_result.time2 > (_result.time1 * 3))
                printf("%s %15f %s", RED, _result.time2, END);
            else
                printf("%s %15f %s", GREEN, _result.time2, END);
            if (_vec.capacity() != _ft_vec.capacity())
                printf("%s %-10zu %s", RED, _ft_vec.capacity(), END);
            else
                printf("%s %-10zu %s", GREEN, _ft_vec.capacity(), END);
            if (_vec.size() != _ft_vec.size())
                printf("%s %zu %s\n", RED, _ft_vec.size(), END);
            else
                printf("%s %zu %s\n", GREEN, _ft_vec.size(), END);
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
                        diff.push_back(a[i]);
                    else
                        diff.push_back(b[i]);
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

            for (auto it = _vec.begin(); it != _vec.end(); ++it)
                std::cout << *it;

            std::cout.rdbuf(old_buf);
            _result.s1 = ss.str();

            old_buf = std::cout.rdbuf(ss2.rdbuf());

            for (auto it = _ft_vec.begin(); it != _ft_vec.end(); ++it)
                std::cout << *it;

            std::cout.rdbuf(old_buf);
            _result.s2 = ss2.str();
        }

    public:
        /************ Constructors ************/
        vector_test()
        {
            std::cout << "Test" << std::setw(33) << "Diff" << std::setw(14) << "Time"
            <<  std::setw(14) << "Capacity" <<  std::setw(8) << "Size" << std::endl;
        }

        /************ Functions ***************/
        void Push_back()
        {
            START_TIME;
            for (int i = 0; i < 100; ++i)
                _vec.push_back(i);
            _result.time1 = FINISH_TIME;

            START_TIME;
            for (int i = 0; i < 100; ++i)
                _ft_vec.push_back(i);
            _result.time2 = FINISH_TIME;

            print();
            result("Push_back");
            _result.clear();
        }

        void Pop_back()
        {
            START_TIME;
            for (int i = 0; i < 5; ++i)
                _vec.pop_back();
            _result.time1 = FINISH_TIME;

            START_TIME;
            for (int i = 0; i < 5; ++i)
                _ft_vec.pop_back();
            _result.time2 = FINISH_TIME;

            print();
            result("Pop_back");
            _result.clear();
        }

        void Assign()
        {
            START_TIME;
            _vec.assign(100, 200);
            _vec.assign(10, 10);
            _vec.assign(10, 30);
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_vec.assign(100, 200);
            _ft_vec.assign(10, 10);
            _ft_vec.assign(10, 30);
            _result.time2 = FINISH_TIME;

            print();
            result("Assing");
            _result.clear();
        }

        void Assign_range()
        {
            std::vector<T> temp1;
            ft::vector<T> temp2;
            for (int i = 0; i < 500; ++i)
            {
                temp1.push_back(i);
                temp2.push_back(i);
            }

            START_TIME;
            _vec.assign(temp1.begin(), temp1.end());
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_vec.assign(temp2.begin(), temp2.end());
            _result.time2 = FINISH_TIME;

            print();
            result("Assing_Range");
            _result.clear();
        }

        void Resize()
        {
             START_TIME;
            _vec.resize(_vec.size() + 500);
            _vec.resize(_vec.size() - 250);
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_vec.resize(_vec.size() + 500);
            _ft_vec.resize(_vec.size() - 250);
            _result.time2 = FINISH_TIME;

            print();
            result("Resize");
            _result.clear();
        }

        void At()
        {
            auto test1 = 0;
            auto test2 = 0;

            START_TIME;
            test1 = _vec.at(40);
            _result.time1 = FINISH_TIME;

            START_TIME;
            test2 = _ft_vec.at(40);
            _result.time2 = FINISH_TIME;

            if (test1 != test2)
                _result.error = true;
            result("At");
            _result.clear();
        }

        void Back()
        {
            auto test1 = 0;
            auto test2 = 0;

            START_TIME;
            test1 = _vec.back();
            _result.time1 = FINISH_TIME;

            START_TIME;
            test2 = _ft_vec.back();
            _result.time2 = FINISH_TIME;

            if (test1 != test2)
                _result.error = true;
            result("Back");
            _result.clear();
        }

        void Front()
        {
            auto test1 = 0;
            auto test2 = 0;

            START_TIME;
            test1 = _vec.front();
            _result.time1 = FINISH_TIME;

            START_TIME;
            test2 = _ft_vec.front();
            _result.time2 = FINISH_TIME;

            if (test1 != test2)
                _result.error = true;
            result("Front");
            _result.clear();

        }

        void Clear()
        {

            START_TIME;
            _vec.clear();
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_vec.clear();
            _result.time2 = FINISH_TIME;

            result("Clear");
            _result.clear();

        }

        void Erase()
        {
            START_TIME;
            _vec.erase(_vec.begin() + 2);
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_vec.erase(_ft_vec.begin() + 2);
            _result.time2 = FINISH_TIME;

            result("Erase");
            _result.clear();
        }

        void EraseRange()
        {
            START_TIME;
            _vec.erase(_vec.begin(), _vec.end());
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_vec.erase(_ft_vec.begin(), _ft_vec.end());
            _result.time2 = FINISH_TIME;

            result("Erase_Range");
            _result.clear();
        }

        void InsertRange()
        {
            ft::vector<T> temp1(10,15);
            std::vector<T> temp2(10,15);

            START_TIME;
            _vec.insert(_vec.begin(), temp2.begin(), temp2.end());
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_vec.insert(_ft_vec.begin(), temp2.begin(), temp2.end());
            _result.time2 = FINISH_TIME;

            result("Insert_Range");
            _result.clear();

            
        }

        void InsertPosRgn()
        {
            START_TIME;
             _vec.insert(_vec.begin(), 10, 49);
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_vec.insert(_ft_vec.begin(), 10, 49);
            _result.time2 = FINISH_TIME;

            result("Insert_Pos_Range");
            _result.clear();
           
        }

        void Insert()
        {
             START_TIME;
             _vec.insert((_vec.begin()), 10);
            _result.time1 = FINISH_TIME;

            START_TIME;
            _ft_vec.insert((_ft_vec.begin()), 10);
            _result.time2 = FINISH_TIME;

            result("Insert");
            _result.clear();
        }

        void Contructors()
        {
            START_TIME;
            std::vector<T> temp1(10,5);
            _vec = temp1;
            _result.time1 = FINISH_TIME;

            START_TIME;
            ft::vector<T> temp2(10,5);
            _ft_vec = temp2;
            _result.time2 = FINISH_TIME;

            result("Constructor");
            _result.clear();
        }

        void Contructor_Range()
        {
            std::vector<T> temp1(10,5);
            START_TIME;
            std::vector<T> temp3(temp1.begin(), temp1.end());
            _vec = temp3;
            _result.time1 = FINISH_TIME;

            ft::vector<T> temp2(10,5);
            START_TIME;
            ft::vector<T> temp4(temp2.begin(), temp2.end());
            _ft_vec = temp4;
            _result.time2 = FINISH_TIME;

            result("Constructor_Range");
            _result.clear();
        }



        
        ~vector_test() {
            log.close();
        }
};

#endif