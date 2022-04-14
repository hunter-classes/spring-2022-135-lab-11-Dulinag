
OBJECTS = profile.o network.o

main: main.o profile.o network.o
	g++ -o main main.o $(OBJECTS)

tests: tests.o profile.o network.o
	g++ -o tests tests.o $(OBJECTS)


main.o: main.cpp profile.h network.h

network.o: network.cpp network.h profile.h

profile.o: profile.cpp profile.h

tests.o: tests.cpp doctest.h profile.h network.h

clean:
	rm -f main tests main.o tests.o $(OBJECTS)
