CC = clang++

LOG:
	@[ ! -d "logs" ] && mkdir -p "logs" || [ $$? -eq 1 ]

PUSH_BACK: LOG
	@echo "Start push_back tests!"
	@$(CC) push_back.cpp -DNAMESPACE="ft" -o push_back && ./push_back > push_back.ft
	@$(CC) push_back.cpp -DNAMESPACE="std" -o push_back && ./push_back > push_back.std
	@if [ "$(shell diff push_back.ft push_back.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff push_back.ft push_back.std)" > logs/push_back.log;\
	fi;

ASSING_RANGE: LOG
	@echo "Start assign_range tests!"
	@$(CC) assign_range.cpp -DNAMESPACE="ft" -o assign_range && ./assign_range > assign_range.ft
	@$(CC) assign_range.cpp -DNAMESPACE="std" -o assign_range && ./assign_range > assign_range.std
	@if [ "$(shell diff assign_range.ft assign_range.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff assign_range.ft assign_range.std)" > logs/assign_range.log;\
	fi;

ASSING: LOG
	@echo "Start assign tests!"
	@$(CC) assign.cpp -DNAMESPACE="ft" -o assign && ./assign > assign.ft
	@$(CC) assign.cpp -DNAMESPACE="std" -o assign && ./assign > assign.std
	@if [ "$(shell diff assign.ft assign.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff assign.ft assign.std)" > logs/assign.log;\
	fi;

AT: LOG
	@echo "Start at tests!"
	@$(CC) at.cpp -DNAMESPACE="ft" -o at && ./at > at.ft
	@$(CC) at.cpp -DNAMESPACE="std" -o at && ./at > at.std
	@(diff at.ft at.std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/at.log
	@if [ "$(shell diff at.ft at.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff at.ft at.std)" > logs/at.log;\
	fi;

BACK: LOG
	@echo "Start back tests!"
	@$(CC) back.cpp -DNAMESPACE="ft" -o back && ./back > back.ft
	@$(CC) back.cpp -DNAMESPACE="std" -o back && ./back > back.std
	@if [ "$(shell diff back.ft back.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff back.ft back.std)" > logs/back.log;\
	fi;

CLEAR: LOG
	@echo "Start clear tests!"
	@$(CC) clear.cpp -DNAMESPACE="ft" -o clear && ./clear > clear.ft
	@$(CC) clear.cpp -DNAMESPACE="std" -o clear && ./clear > clear.std
	@if [ "$(shell diff clear.ft clear.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff clear.ft clear.std)" > logs/clear.log;\
	fi;

EQUAL: LOG
	@echo "Start equal tests!"
	@$(CC) equal.cpp -DNAMESPACE="ft" -o equal && ./equal > equal.ft
	@$(CC) equal.cpp -DNAMESPACE="std" -o equal && ./equal > equal.std
	@if [ "$(shell diff equal.ft equal.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff equal.ft equal.std)" > logs/push_back.log;\
	fi;

ERASE_RANGE: LOG
	@echo "Start erase_range tests!"
	@$(CC) erase_range.cpp -DNAMESPACE="ft" -o erase_range && ./erase_range > erase_range.ft
	@$(CC) erase_range.cpp -DNAMESPACE="std" -o erase_range && ./erase_range > erase_range.std
	@if [ "$(shell diff erase_range.ft erase_range.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff erase_range.ft erase_range.std)" > logs/erase_range.log;\
	fi;

ERASE: LOG
	@echo "Start erase tests!"
	@$(CC) erase.cpp -DNAMESPACE="ft" -o erase && ./erase > erase.ft
	@$(CC) erase.cpp -DNAMESPACE="std" -o erase && ./erase > erase.std
	@if [ "$(shell diff erase.ft erase.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff erase.ft erase.std)" > logs/erase.log;\
	fi;

FRONT: LOG
	@echo "Start front tests!"
	@$(CC) front.cpp -DNAMESPACE="ft" -o front && ./front > front.ft
	@$(CC) front.cpp -DNAMESPACE="std" -o front && ./front > front.std
	@if [ "$(shell diff front.ft front.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff front.ft front.std)" > logs/front.log;\
	fi;

INSERT_RANGE: LOG
	@echo "Start insert_range tests!"
	@$(CC) insert_range.cpp -DNAMESPACE="ft" -o insert_range && ./insert_range > insert_range.ft
	@$(CC) insert_range.cpp -DNAMESPACE="std" -o insert_range && ./insert_range > insert_range.std
	@if [ "$(shell diff insert_range.ft insert_range.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff insert_range.ft insert_range.std)" > logs/insert_range.log;\
	fi;

INSERT_SIZE: LOG
	@echo "Start insert_size tests!"
	@$(CC) insert_size.cpp -DNAMESPACE="ft" -o insert_size && ./insert_size > insert_size.ft
	@$(CC) insert_size.cpp -DNAMESPACE="std" -o insert_size && ./insert_size > insert_size.std
	@if [ "$(shell diff insert_size.ft insert_size.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff insert_size.ft insert_size.std)" > logs/insert_size.log;\
	fi;

INSERT: LOG
	@echo "Start insert tests!"
	@$(CC) insert.cpp -DNAMESPACE="ft" -o insert && ./insert > insert.ft
	@$(CC) insert.cpp -DNAMESPACE="std" -o insert && ./insert > insert.std
	@if [ "$(shell diff insert.ft insert.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff insert.ft insert.std)" > logs/insert.log;\
	fi;

ITERATOR: LOG
	@echo "Start iterator tests!"
	@$(CC) iterator.cpp -DNAMESPACE="ft" -o iterator && ./iterator > iterator.ft
	@$(CC) iterator.cpp -DNAMESPACE="std" -o iterator && ./iterator > iterator.std
	@if [ "$(shell diff iterator.ft iterator.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff iterator.ft iterator.std)" > logs/iterator.log;\
	fi;

LEXICOGRAFICAL_COMPARE: LOG
	@echo "Start lexicographical_compare tests!"
	@$(CC) lexicographical_compare.cpp -DNAMESPACE="ft" -o lexicographical_compare && ./lexicographical_compare > lexicographical_compare.ft
	@$(CC) lexicographical_compare.cpp -DNAMESPACE="std" -o lexicographical_compare && ./lexicographical_compare > lexicographical_compare.std
	@if [ "$(shell diff lexicographical_compare.ft lexicographical_compare.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff lexicographical_compare.ft lexicographical_compare.std)" > logs/lexicographical_compare.log;\
	fi;

PAIR: LOG
	@echo "Start pair tests!"
	@$(CC) pair.cpp -DNAMESPACE="ft" -o pair && ./pair > pair.ft
	@$(CC) pair.cpp -DNAMESPACE="std" -o pair && ./pair > pair.std
	@if [ "$(shell diff pair.ft pair.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff pair.ft pair.std)" > logs/pair.log;\
	fi;

POP_BACK: LOG
	@echo "Start pop_back tests!"
	@$(CC) pop_back.cpp -DNAMESPACE="ft" -o pop_back && ./pop_back > pop_back.ft
	@$(CC) pop_back.cpp -DNAMESPACE="std" -o pop_back && ./pop_back > pop_back.std
	@if [ "$(shell diff pop_back.ft pop_back.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff pop_back.ft pop_back.std)" > logs/pop_back.log;\
	fi;

RELATIONAL_OPERATORS: LOG
	@echo "Start relational_operators tests!"
	@$(CC) relational_operators.cpp -DNAMESPACE="ft" -o relational_operators && ./relational_operators > relational_operators.ft
	@$(CC) relational_operators.cpp -DNAMESPACE="std" -o relational_operators && ./relational_operators > relational_operators.std
	@if [ "$(shell diff relational_operators.ft relational_operators.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff relational_operators.ft relational_operators.std)" > logs/relational_operators.log;\
	fi;

RESERVE_RESIZE: LOG
	@echo "Start reserve_resize tests!"
	@$(CC) reserve_resize.cpp -DNAMESPACE="ft" -o reserve_resize && ./reserve_resize > reserve_resize.ft
	@$(CC) reserve_resize.cpp -DNAMESPACE="std" -o reserve_resize && ./reserve_resize > reserve_resize.std
	@if [ "$(shell diff reserve_resize.ft reserve_resize.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff reserve_resize.ft reserve_resize.std)" > logs/reserve_resize.log;\
	fi;

REVERSE_ITERATOR: LOG
	@echo "Start reverse_iterator tests!"
	@$(CC) reverse_iterator.cpp -DNAMESPACE="ft" -o reverse_iterator && ./reverse_iterator > reverse_iterator.ft
	@$(CC) reverse_iterator.cpp -DNAMESPACE="std" -o reverse_iterator && ./reverse_iterator > reverse_iterator.std
	@if [ "$(shell diff reverse_iterator.ft reverse_iterator.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff reverse_iterator.ft reverse_iterator.std)" > logs/reverse_iterator.log;\
	fi;

SWAP_MEMBER: LOG
	@echo "Start swap_member tests!"
	@$(CC) swap_member.cpp -DNAMESPACE="ft" -o swap_member && ./swap_member > swap_member.ft
	@$(CC) swap_member.cpp -DNAMESPACE="std" -o swap_member && ./swap_member > swap_member.std
	@if [ "$(shell diff swap_member.ft swap_member.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff swap_member.ft swap_member.std)" > logs/swap_member.log;\
	fi;

CAPACITY: LOG
	@echo "Start capacity tests!"
	@$(CC) capacity.cpp -DNAMESPACE="ft" -o capacity && ./capacity > capacity.ft
	@$(CC) capacity.cpp -DNAMESPACE="std" -o capacity && ./capacity > capacity.std
	@if [ "$(shell diff capacity.ft capacity.std)" = "" ]; then\
		echo "\033[1;32mPASSED\033[m 😁 🤓";\
	else\
		echo "\033[1;31mFAIL\033[m 😮‍💨" && echo "$(shell diff capacity.ft capacity.std)" > logs/capacity.log;\
	fi;

all: PUSH_BACK ASSING_RANGE ASSING AT BACK CLEAR EQUAL ERASE_RANGE ERASE FRONT \
	INSERT_RANGE INSERT_SIZE INSERT ITERATOR LEXICOGRAFICAL_COMPARE \
	PAIR POP_BACK RELATIONAL_OPERATORS RESERVE_RESIZE SWAP_MEMBER CAPACITY

clean:
	@rm -f push_back assign_range assign at back clear equal erase_range erase front
	@rm -f insert_range insert_size insert iterator lexicographical_compare pair pop_back
	@rm -f relational_operators reserve_resize reverse_iterator swap_member capacity
	@rm -f *.ft *.std
	@echo "\033[1;34mEverything CLEAR"

fclean: clean
	rm -rf logs
