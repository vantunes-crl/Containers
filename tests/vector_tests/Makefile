CC = clang++

LOG:
	@[ ! -d "logs" ] && mkdir -p "logs" || [ $$? -eq 1 ]

PUSH_BACK: LOG
	@echo "Start push_back tests!"
	@$(CC) push_back.cpp -DNAMESPACE="ft" -o push_back && ./push_back > push_back.ft
	@$(CC) push_back.cpp -DNAMESPACE="std" -o push_back && ./push_back > push_back.std
	@(diff push_back.ft push_back.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/push_back.log
	@rm -f push_back.ft push_back.std
	@if [ "$(shell wc -l logs/push_back.log)" = "0 logs/push_back.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

ASSING_RANGE: LOG
	@echo "Start assign_range tests!"
	@$(CC) assign_range.cpp -DNAMESPACE="ft" -o assign_range && ./assign_range > assign_range.ft
	@$(CC) assign_range.cpp -DNAMESPACE="std" -o assign_range && ./assign_range > assign_range.std
	@(diff assign_range.ft assign_range.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/assign_range.log
	@rm -f assign_range.ft assign_range.std
	@if [ "$(shell wc -l logs/assign_range.log)" = "0 logs/assign_range.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

ASSING: LOG
	@echo "Start assign tests!"
	@$(CC) assign.cpp -DNAMESPACE="ft" -o assign && ./assign > assign.ft
	@$(CC) assign.cpp -DNAMESPACE="std" -o assign && ./assign > assign.std
	@(diff assign.ft assign.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/assign.log
	@rm -f assign.ft assign.std
	@if [ "$(shell wc -l logs/assign.log)" = "0 logs/assign.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

AT: LOG
	@echo "Start at tests!"
	@$(CC) at.cpp -DNAMESPACE="ft" -o at && ./at > at.ft
	@$(CC) at.cpp -DNAMESPACE="std" -o at && ./at > at.std
	@(diff at.ft at.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/at.log
	@rm -f at.ft at.std
	@if [ "$(shell wc -l logs/at.log)" = "0 logs/at.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

BACK: LOG
	@echo "Start back tests!"
	@$(CC) back.cpp -DNAMESPACE="ft" -o back && ./back > back.ft
	@$(CC) back.cpp -DNAMESPACE="std" -o back && ./back > back.std
	@(diff back.ft back.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/back.log
	@rm -f back.ft back.std
	@if [ "$(shell wc -l logs/back.log)" = "0 logs/back.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

CLEAR: LOG
	@echo "Start clear tests!"
	@$(CC) clear.cpp -DNAMESPACE="ft" -o clear && ./clear > clear.ft
	@$(CC) clear.cpp -DNAMESPACE="std" -o clear && ./clear > clear.std
	@(diff clear.ft clear.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/clear.log
	@rm -f clear.ft clear.std
	@if [ "$(shell wc -l logs/clear.log)" = "0 logs/clear.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

EQUAL: LOG
	@echo "Start equal tests!"
	@$(CC) equal.cpp -DNAMESPACE="ft" -o equal && ./equal > equal.ft
	@$(CC) equal.cpp -DNAMESPACE="std" -o equal && ./equal > equal.std
	@(diff equal.ft equal.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/equal.log
	@rm -f equal.ft equal.std
	@if [ "$(shell wc -l logs/equal.log)" = "0 logs/equal.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

ERASE_RANGE: LOG
	@echo "Start erase_range tests!"
	@$(CC) erase_range.cpp -DNAMESPACE="ft" -o erase_range && ./erase_range > erase_range.ft
	@$(CC) erase_range.cpp -DNAMESPACE="std" -o erase_range && ./erase_range > erase_range.std
	@(diff erase_range.ft erase_range.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/erase_range.log
	@rm -f erase_range.ft erase_range.std
	@if [ "$(shell wc -l logs/erase_range.log)" = "0 logs/erase_range.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

ERASE: LOG
	@echo "Start erase tests!"
	@$(CC) erase.cpp -DNAMESPACE="ft" -o erase && ./erase > erase.ft
	@$(CC) erase.cpp -DNAMESPACE="std" -o erase && ./erase > erase.std
	@(diff erase.ft erase.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/erase.log
	@rm -f erase.ft erase.std
	@if [ "$(shell wc -l logs/erase.log)" = "0 logs/erase.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

FRONT: LOG
	@echo "Start front tests!"
	@$(CC) front.cpp -DNAMESPACE="ft" -o front && ./front > front.ft
	@$(CC) front.cpp -DNAMESPACE="std" -o front && ./front > front.std
	@(diff front.ft front.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/front.log
	@rm -f front.ft front.std
	@if [ "$(shell wc -l logs/front.log)" = "0 logs/front.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

INSERT_RANGE: LOG
	@echo "Start insert_range tests!"
	@$(CC) insert_range.cpp -DNAMESPACE="ft" -o insert_range && ./insert_range > insert_range.ft
	@$(CC) insert_range.cpp -DNAMESPACE="std" -o insert_range && ./insert_range > insert_range.std
	@(diff insert_range.ft insert_range.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/insert_range.log
	@rm -f insert_range.ft insert_range.std
	@if [ "$(shell wc -l logs/insert_range.log)" = "0 logs/insert_range.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

INSERT_SIZE: LOG
	@echo "Start insert_size tests!"
	@$(CC) insert_size.cpp -DNAMESPACE="ft" -o insert_size && ./insert_size > insert_size.ft
	@$(CC) insert_size.cpp -DNAMESPACE="std" -o insert_size && ./insert_size > insert_size.std
	@(diff insert_size.ft insert_size.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/insert_size.log
	@rm -f insert_size.ft insert_size.std
	@if [ "$(shell wc -l logs/insert_size.log)" = "0 logs/insert_size.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

INSERT: LOG
	@echo "Start insert tests!"
	@$(CC) insert.cpp -DNAMESPACE="ft" -o insert && ./insert > insert.ft
	@$(CC) insert.cpp -DNAMESPACE="std" -o insert && ./insert > insert.std
	@(diff insert.ft insert.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/insert.log
	@rm -f insert.ft insert.std
	@if [ "$(shell wc -l logs/insert.log)" = "0 logs/insert.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

ITERATOR: LOG
	@echo "Start iterator tests!"
	@$(CC) iterator.cpp -DNAMESPACE="ft" -o iterator && ./iterator > iterator.ft
	@$(CC) iterator.cpp -DNAMESPACE="std" -o iterator && ./iterator > iterator.std
	@(diff iterator.ft iterator.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/iterator.log
	@rm -f iterator.ft iterator.std
	@if [ "$(shell wc -l logs/iterator.log)" = "0 logs/iterator.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

LEXICOGRAFICAL_COMPARE: LOG
	@echo "Start lexicographical_compare tests!"
	@$(CC) lexicographical_compare.cpp -DNAMESPACE="ft" -o lexicographical_compare && ./lexicographical_compare > lexicographical_compare.ft
	@$(CC) lexicographical_compare.cpp -DNAMESPACE="std" -o lexicographical_compare && ./lexicographical_compare > lexicographical_compare.std
	@(diff lexicographical_compare.ft lexicographical_compare.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/lexicographical_compare.log
	@rm -f lexicographical_compare.ft lexicographical_compare.std
	@if [ "$(shell wc -l logs/lexicographical_compare.log)" = "0 logs/lexicographical_compare.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

PAIR: LOG
	@echo "Start pair tests!"
	@$(CC) pair.cpp -DNAMESPACE="ft" -o pair && ./pair > pair.ft
	@$(CC) pair.cpp -DNAMESPACE="std" -o pair && ./pair > pair.std
	@(diff pair.ft pair.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/pair.log
	@rm -f pair.ft pair.std
	@if [ "$(shell wc -l logs/pair.log)" = "0 logs/pair.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

POP_BACK: LOG
	@echo "Start pop_back tests!"
	@$(CC) pop_back.cpp -DNAMESPACE="ft" -o pop_back && ./pop_back > pop_back.ft
	@$(CC) pop_back.cpp -DNAMESPACE="std" -o pop_back && ./pop_back > pop_back.std
	@(diff pop_back.ft pop_back.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/pop_back.log
	@rm -f pop_back.ft pop_back.std
	@if [ "$(shell wc -l logs/pop_back.log)" = "0 logs/pop_back.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

RELATIONAL_OPERATORS: LOG
	@echo "Start relational_operators tests!"
	@$(CC) relational_operators.cpp -DNAMESPACE="ft" -o relational_operators && ./relational_operators > relational_operators.ft
	@$(CC) relational_operators.cpp -DNAMESPACE="std" -o relational_operators && ./relational_operators > relational_operators.std
	@(diff relational_operators.ft relational_operators.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/relational_operators.log
	@rm -f relational_operators.ft relational_operators.std
	@if [ "$(shell wc -l logs/relational_operators.log)" = "0 logs/relational_operators.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

RESERVE_RESIZE: LOG
	@echo "Start reserve_resize tests!"
	@$(CC) reserve_resize.cpp -DNAMESPACE="ft" -o reserve_resize && ./reserve_resize > reserve_resize.ft
	@$(CC) reserve_resize.cpp -DNAMESPACE="std" -o reserve_resize && ./reserve_resize > reserve_resize.std
	@(diff reserve_resize.ft reserve_resize.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/reserve_resize.log
	@rm -f reserve_resize.ft reserve_resize.std
	@if [ "$(shell wc -l logs/reserve_resize.log)" = "0 logs/reserve_resize.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

REVERSE_ITERATOR: LOG
	@echo "Start reverse_iterator tests!"
	@$(CC) reverse_iterator.cpp -DNAMESPACE="ft" -o reverse_iterator && ./reverse_iterator > reverse_iterator.ft
	@$(CC) reverse_iterator.cpp -DNAMESPACE="std" -o reverse_iterator && ./reverse_iterator > reverse_iterator.std
	@(diff reverse_iterator.ft reverse_iterator.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/reverse_iterator.log
	@rm -f reverse_iterator.ft reverse_iterator.std
	@if [ "$(shell wc -l logs/reverse_iterator.log)" = "0 logs/reverse_iterator.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

SWAP_MEMBER: LOG
	@echo "Start swap_member tests!"
	@$(CC) swap_member.cpp -DNAMESPACE="ft" -o swap_member && ./swap_member > swap_member.ft
	@$(CC) swap_member.cpp -DNAMESPACE="std" -o swap_member && ./swap_member > swap_member.std
	@(diff swap_member.ft swap_member.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/swap_member.log
	@rm -f swap_member.ft swap_member.std
	@if [ "$(shell wc -l logs/swap_member.log)" = "0 logs/swap_member.log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

all: PUSH_BACK ASSING_RANGE ASSING AT BACK CLEAR EQUAL ERASE_RANGE ERASE FRONT \
	INSERT_RANGE INSERT_SIZE INSERT ITERATOR LEXICOGRAFICAL_COMPARE \
	PAIR POP_BACK RELATIONAL_OPERATORS RESERVE_RESIZE SWAP_MEMBER

clean:
	@rm -f push_back assign_range assign at back clear equal erase_range erase front
	@rm -f insert_range insert_size insert iterator lexicographical_compare pair pop_back
	@rm -f relational_operators reserve_resize reverse_iterator swap_member
	@echo "\033[1;34mEverything CLEAR"

fclean: clean
	rm -rf logs
