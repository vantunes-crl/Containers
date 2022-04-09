CC = clang++

LOG:
	@[ ! -d "logs" ] && mkdir -p "logs" || [ $$? -eq 1 ]

NAME = push_back
PUSH_BACK: LOG
	@echo "Start $(NAME) tests!"
	@$(CC) $(NAME).cpp -DNAMESPACE="ft" -o $(NAME) && ./$(NAME) > $(NAME).ft
	@$(CC) $(NAME).cpp -DNAMESPACE="std" -o $(NAME) && ./$(NAME) > $(NAME).std
	@(diff $(NAME).ft $(NAME).std; [ $$? -eq 0 ] || [ $$? -eq 1 ]) > ./logs/$(NAME).log
	@rm -f $(NAME).ft $(NAME).std
	@if [ "$(shell wc -l logs/$(NAME).log)" = "0 logs/$(NAME).log" ]; then echo "\033[1;32mSucess 😁 🤓"; else echo "\033[1;31mFail 😮‍💨"; fi;

ASSING_RANGE:
	$(CC) assign_range.cpp -o assign_range

ASSING:
	$(CC) assign.cpp -o assign

AT:
	$(CC) at.cpp -o at

BACK:
	$(CC) back.cpp -o back

CLEAR:
	$(CC) clear.cpp -o clear

EQUAL:
	$(CC) equal.cpp -o equal

ERASE_RANGE:
	$(CC) erase_range.cpp -o erase_range

ERASE:
	$(CC) erase.cpp -o erase

FRONT:
	$(CC) front.cpp -o front

INSERT_RANGE:
	$(CC) insert_range.cpp -o insert_range

INSERT_SIZE:
	$(CC) insert_size.cpp -o insert_size

INSERT:
	$(CC) insert.cpp -o insert

ITERATOR:
	$(CC) iterator.cpp -o iterator

LEXICOGRAFICAL_COMPARE:
	$(CC) lexicographical_compare.cpp -o lexicographical_compare

PAIR:
	$(CC) pair.cpp -o pair

POP_BACK:
	$(CC) pop_back.cpp -o pop_back

RELATIONAL_OPERATORS:
	$(CC) relational_operators.cpp -o relational_operators

RESERVE_RESIZE:
	$(CC) reserve_resize.cpp -o reserve_resize

REVERSE_ITERATOR:
	$(CC) reverse_iterator.cpp -o reverse_iterator

SWAP_MEMBER:
	$(CC) swap_member.cpp -o swap_member

all: PUSH_BACK ASSING_RANGE ASSING AT BACK CLEAR EQUAL ERASE_RANGE ERASE FRONT \
	INSERT_RANGE INSERT_SIZE INSERT ITERATOR LEXICOGRAFICAL_COMPARE \
	PAIR POP_BACK RELATIONAL_OPERATORS RESERVE_RESIZE SWAP_MEMBER

clean:
	@rm -f push_back assign_range assign at back clear equal erase_range erase front
	@rm -f insert_range insert_size insert iterator lexicographical_compare pair pop_back
	@rm -f relational_operators reserve_resize reverse_iterator swap_member
	@echo "\033[1;34mEverything CLEAR"
