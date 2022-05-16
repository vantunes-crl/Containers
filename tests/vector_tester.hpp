#ifndef VECTOR_TESTER_HPP
#define VECTOR_TESTER_HPP

#include <vector>
#include "../vector.hpp"
#include <iostream>
#include "print.hpp"
#include <chrono>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <functional>


#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define END "\033[0m"
#define YELLOW "\033[1;33m"

template<class T>
class vector_test
{
    private:
        std::ofstream log{ "Logs"};
        std::vector<T> _vec;
        ft::vector<T> _ft_vec;
    public:
        /************ Constructors ************/
        vector_test()
        {
            std::cout << std::setw(7) << "Test" << std::setw(25) << "Diff" << std::setw(13) << "Time" << std::endl;
        }

        /************ Functions ***************/

        void Push_back()
        {
            clock_t start, end;

            //execution time and test vector
            start = clock();
            for (int i = 0; i < 500; ++i)
                _vec.push_back(i);
            end = clock();
            double result1 = double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            for (int i = 0; i < 500; ++i)
                _ft_vec.push_back(i);
            end = clock();
            double result2 = double(end - start) / double(CLOCKS_PER_SEC);

            std::string vec1;
            std::string vec2;

            vec1 = print(_vec);
            vec2 = print(_ft_vec);

            result(vec1, vec2, result1, result2, "Push_back");
        }

        void Assign()
        {
            clock_t start, end;

            //execution time and test vector
            start = clock();
            _vec.assign(100,200);
            end = clock();
            double result1 = double(end - start) / double(CLOCKS_PER_SEC);

            start = clock();
            _ft_vec.assign(100,200);
            end = clock();
            double result2 = double(end - start) / double(CLOCKS_PER_SEC);

            std::string vec1;
            std::string vec2;

            vec1 = print(_vec);
            vec2 = print(_ft_vec);

            result(vec1, vec2, result1, result2, "Assign");
        }

        void result(std::string &s1, std::string &s2, double time1, double time2, std::string name)
        {
            bool error = false;
            log << compare(s1, s2, &error);
            log << name;
            if (error)
                printf("%10s%-10s Test%10s %10sError%10s", YELLOW, name.c_str(), END, RED, END);
            else
                printf("%10s%-10s Test%10s %10sPassed%10s", YELLOW, name.c_str(), END, GREEN, END);
            if (time2 > (time1 * 3))
                printf("%s %f %s\n", RED, time2, END);
            else
                printf("%s %f %s\n", GREEN, time2, END);
        } 

        std::string compare(std::string &a, std::string &b, bool *error)
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
                    *error = true;
                }
                ++i;
            }
            
            return diff;
        }


        ~vector_test() {
            log.close();
        }
};

#endif