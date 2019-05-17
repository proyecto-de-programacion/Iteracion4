#                                             Creator of everything     Alexandra Conache
###############################################################################################################################################################################################################

CC = gcc -g -ansi -pedantic
CFLAGS = -Wall

EXE = JuegoOca
EXE_TEST_COMMAND = test_command
EXE_TEST_DIE = test_die
EXE_TEST_INVENTORY = test_inventory
EXE_TEST_LINK = test_link
EXE_TEST_OBJECT = test_object
EXE_TEST_PLAYER = test_player
EXE_TEST_SET = test_set
EXE_TEST_SPACE = test_space

###############################################################################################################################################################################################################
all : $(EXE) #doxygen
test: $(EXE_TEST_COMMAND) $(EXE_TEST_DIE) $(EXE_TEST_INVENTORY) $(EXE_TEST_LINK) $(EXE_TEST_OBJECT) $(EXE_TEST_PLAYER) $(EXE_TEST_SET) $(EXE_TEST_SPACE)  #doxygen

.PHONY : clean

clean :
	rm -f ./obj/*.o core $(EXE) $(EXE_TEST_COMMAND) $(EXE_TEST_DIE) $(EXE_TEST_GAME) $(EXE_TEST_game_management) $(EXE_TEST_GRAPHIC_ENGINE) $(EXE_TEST_INVENTORY)  $(EXE_TEST_LINK) $(EXE_TEST_OBJECT) $(EXE_TEST_PLAYER) $(EXE_TEST_SET) $(EXE_TEST_SPACE)
	rm -f file.log

runv:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./JuegoOca data.dat

run_with_val:
	valgrind --leak-check=full ./JuegoOca data.dat

run_with_log:
	valgrind --leak-check=full ./JuegoOca data.dat -l file.log

run_with_game1:
	./JuegoOca data.dat < game1.oca

run_with_game2:
	./JuegoOca data.dat < game2.oca

doxygen:
	doxygen Doxyfile

compress:
	tar -xvzf I3_PPROG_G2111_AlonsoAquinoCiro_CatanaSaraErika_ConacheAlexandra.tgz Makefile doc include obj src test actas Doxyfile *.dat *.txt
###############################################################################################################################################################################################################
$(EXE) : % : ./obj/game_loop.o ./obj/command.o ./obj/game.o ./obj/graphic_engine.o ./obj/screen.o ./obj/space.o ./obj/object.o ./obj/player.o ./obj/game_management.o ./obj/die.o ./obj/set.o ./obj/inventory.o ./obj/link.o
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ ./obj/game_loop.o ./obj/command.o ./obj/game.o ./obj/graphic_engine.o ./obj/screen.o ./obj/space.o ./obj/object.o ./obj/player.o ./obj/game_management.o ./obj/die.o ./obj/set.o ./obj/inventory.o ./obj/link.o


$(EXE_TEST_COMMAND) : % : ./obj/test_command.o ./obj/command.o
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ ./obj/test_command.o ./obj/command.o

$(EXE_TEST_DIE) : % : test_die.o die.o
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ ./obj/test_die.o ./obj/die.o

$(EXE_TEST_INVENTORY) : % : ./obj/test_inventory.o ./obj/inventory.o ./obj/set.o
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ ./obj/test_inventory.o ./obj/inventory.o ./obj/set.o

$(EXE_TEST_LINK) : % : ./obj/test_link.o ./obj/link.o
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ ./obj/test_link.o ./obj/link.o

$(EXE_TEST_OBJECT) : % : ./obj/test_object.o ./obj/object.o
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ ./obj/test_object.o ./obj/object.o

$(EXE_TEST_PLAYER) : % : ./obj/test_player.o ./obj/player.o ./obj/inventory.o ./obj/set.o
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ ./obj/test_player.o ./obj/player.o ./obj/inventory.o ./obj/set.o

$(EXE_TEST_SET) : % : ./obj/test_set.o ./obj/set.o
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ ./obj/test_set.o ./obj/set.o

$(EXE_TEST_SPACE) : % : ./obj/test_space.o ./obj/space.o ./obj/set.o
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ ./obj/test_space.o ./obj/space.o ./obj/set.o

###############################################################################################################################################################################################################
./obj/game_loop.o: ./src/game_loop.c ./include/graphic_engine.h ./include/command.h ./include/game.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<



./obj/command.o : ./src/command.c ./include/command.h ./include/types.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/die.o : ./src/die.c ./include/die.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/game.o : ./src/game.c ./include/game.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<


./obj/game_management.o : ./src/game_management.c ./include/game_management.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<


./obj/graphic_engine.o : ./src/graphic_engine.c ./include/graphic_engine.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<


./obj/inventory.o: ./src/inventory.c ./include/inventory.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/link.o: ./src/link.c ./include/link.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/object.o : ./src/object.c ./include/object.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<


./obj/player.o : ./src/player.c ./include/player.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<


./obj/set.o : ./src/set.c ./include/set.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/screen.o : ./src/screen.c ./include/screen.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<


./obj/space.o : ./src/space.c ./include/space.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<



###############################################################################################################################################################################################################
./obj/test_command.o: ./test/test_command.c ./include/command.h ./include/test.h ./include/types.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/test_die.o: ./test/test_die.c ./include/die.h ./include/test.h ./include/types.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/test_inventory.o: ./test/test_inventory.c ./include/inventory.h ./include/test.h ./include/types.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/test_link.o: ./test/test_link.c ./include/test_link.h ./include/link.h ./include/test.h ./include/types.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/test_object.o: ./test/test_object.c ./include/object.h ./include/test.h ./include/types.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/test_player.o: ./test/test_player.c ./include/player.h ./include/test.h ./include/types.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/test_set.o: ./test/test_set.c ./include/set.h ./include/test.h ./include/types.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<

./obj/test_space.o: ./test/test_space.c ./include/space.h ./include/test.h ./include/types.h
	@echo "#################"
	@echo "# Generating: $@ "
	@echo "# Depending: $^"
	@echo "# Changing: $<"
	$(CC) $(CFLAGS) -o $@ -c $<





